#!/usr/bin/env bash
set -euo pipefail

FOLDER="${1:-}"

if [[ -z "$FOLDER" ]]; then
    echo "Usage: $0 <folder>"
    echo "Example: $0 stack"
    exit 1
fi

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

python3 "$SCRIPT_DIR/stub_functions.py" "$FOLDER"
