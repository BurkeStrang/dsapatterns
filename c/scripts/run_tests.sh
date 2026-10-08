#!/usr/bin/env bash
# Runs each test program and prints one line per test file, like `go test`.
set -uo pipefail

VERBOSE=0
if [[ "${1:-}" == "-v" ]]; then
    VERBOSE=1
    shift
fi

if [[ $# -eq 0 ]]; then
    echo "no tests to run"
    exit 0
fi

failed=0
for bin in "$@"; do
    name="${bin#build/}"
    name="${name%_test}"
    output="$("$bin" 2>&1)"
    status=$?
    if [[ $status -eq 0 ]]; then
        echo "ok    $name"
        if [[ $VERBOSE -eq 1 ]]; then
            echo "$output" | sed 's/^/    /'
        fi
    else
        echo "FAIL  $name"
        echo "$output" | sed 's/^/    /'
        failed=$((failed + 1))
    fi
done

if [[ $failed -gt 0 ]]; then
    echo
    echo "FAIL: $failed of $# test files failed"
    exit 1
fi
