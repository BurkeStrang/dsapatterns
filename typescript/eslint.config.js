// ESLint with typescript-eslint's strict, type-aware rules.
import js from "@eslint/js";
import tseslint from "typescript-eslint";

export default tseslint.config(
  { ignores: ["node_modules/"] },
  js.configs.recommended,
  tseslint.configs.strictTypeChecked,
  tseslint.configs.stylisticTypeChecked,
  {
    languageOptions: {
      parserOptions: {
        projectService: true,
        tsconfigRootDir: import.meta.dirname,
      },
    },
    rules: {
      // the linked list code checks each pointer for null in turn
      // (fast !== null && fast.next !== null), which shows the algorithm
      // more plainly than fast?.next != null
      "@typescript-eslint/prefer-optional-chain": "off",
    },
  },
  {
    // the config files themselves are plain JavaScript
    files: ["**/*.js"],
    extends: [tseslint.configs.disableTypeChecked],
  },
);
