#!/usr/bin/env bash
set -euo pipefail

FOLDER="${1:-}"

if [[ -z "$FOLDER" ]]; then
    echo "Usage: $0 <folder>"
    echo "Example: $0 slidingwindow"
    exit 1
fi

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

node --disable-warning=ExperimentalWarning "$SCRIPT_DIR/stub-functions.ts" "$FOLDER"
