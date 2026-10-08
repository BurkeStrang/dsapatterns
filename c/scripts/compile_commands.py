#!/usr/bin/env python3
"""
Writes compile_commands.json, the file clangd reads to learn how each C
file is compiled. Without it the editor can't find the project's headers.

The file is only rewritten when its contents change, so clangd is not
made to reload on every build.

Usage: compile_commands.py <compiler> <flags> <file>...
"""

import json
import os
import sys

OUTPUT = 'compile_commands.json'


def main():
    if len(sys.argv) < 3:
        print("Usage: compile_commands.py <compiler> <flags> <file>...")
        sys.exit(1)

    compiler = sys.argv[1]
    flags = sys.argv[2].split()
    files = sys.argv[3:]
    directory = os.getcwd()

    commands = [
        {
            'directory': directory,
            'file': path,
            'arguments': [compiler, *flags, '-c', path],
        }
        for path in sorted(files)
    ]
    content = json.dumps(commands, indent=2) + '\n'

    if os.path.exists(OUTPUT):
        with open(OUTPUT, 'r') as f:
            if f.read() == content:
                return

    with open(OUTPUT, 'w') as f:
        f.write(content)
    print(f"Updated {OUTPUT} ({len(commands)} files)")


if __name__ == '__main__':
    main()
