// Replaces every function body in a pattern folder with a TODO stub.
//
// Usage: node scripts/stub-functions.ts <folder>
//
// Function declarations, functions assigned to a variable, and the methods
// and constructors of classes are stubbed. shared.ts and *.test.ts files are
// left alone. Running it again on stubbed files changes nothing.

import { existsSync, readdirSync, readFileSync, writeFileSync } from "node:fs";
import { join } from "node:path";
import ts from "typescript";

const STUB = ["// TODO:", 'throw new Error("not implemented");'];

// Returns the bodies to replace: functions at any depth outside other
// functions, since a nested function goes away with its parent's body.
function bodies(source: ts.SourceFile): ts.Block[] {
  const found: ts.Block[] = [];
  const visit = (node: ts.Node): void => {
    if (
      (ts.isFunctionDeclaration(node) ||
        ts.isFunctionExpression(node) ||
        ts.isArrowFunction(node) ||
        ts.isMethodDeclaration(node) ||
        ts.isConstructorDeclaration(node) ||
        ts.isGetAccessorDeclaration(node) ||
        ts.isSetAccessorDeclaration(node)) &&
      node.body !== undefined &&
      ts.isBlock(node.body)
    ) {
      found.push(node.body);
      return;
    }
    ts.forEachChild(node, visit);
  };
  visit(source);
  return found;
}

// A body that is already a stub holds just the throw statement.
function isStub(body: ts.Block): boolean {
  return (
    body.statements.length === 1 && body.statements[0].getText() === STUB[1]
  );
}

// The indentation of the line that 'pos' is on.
function lineIndent(text: string, pos: number): string {
  const lineStart = text.lastIndexOf("\n", pos - 1) + 1;
  return /^[ \t]*/.exec(text.slice(lineStart))?.[0] ?? "";
}

function stubFile(path: string): boolean {
  const text = readFileSync(path, "utf8");
  const source = ts.createSourceFile(path, text, ts.ScriptTarget.Latest, true);
  const edits = bodies(source).filter((body) => !isStub(body));
  if (edits.length === 0) {
    return false;
  }

  let result = text;
  // work from the end so earlier positions stay valid
  for (const body of edits.reverse()) {
    const indent = lineIndent(text, body.getStart());
    const inner = STUB.map((line) => `${indent}  ${line}\n`).join("");
    const replacement = `{\n${inner}${indent}}`;
    result =
      result.slice(0, body.getStart()) + replacement + result.slice(body.end);
  }
  writeFileSync(path, result);
  return true;
}

const folder = process.argv.at(2);
if (folder === undefined || !existsSync(folder)) {
  console.error("Usage: node scripts/stub-functions.ts <folder>");
  process.exit(1);
}

let changed = 0;
for (const name of readdirSync(folder).sort()) {
  if (
    !name.endsWith(".ts") ||
    name.endsWith(".test.ts") ||
    name === "shared.ts"
  ) {
    continue;
  }
  const path = join(folder, name);
  if (stubFile(path)) {
    console.log(`Stubbed: ${path}`);
    changed++;
  }
}
console.log(`Done. ${String(changed)} file(s) stubbed.`);
