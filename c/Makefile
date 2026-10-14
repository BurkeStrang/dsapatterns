.PHONY: all build test test-verbose debug fmt fmt-check lint check clean \
	compile_commands.json

CC ?= cc
# -Wno-comment: tree diagrams in the problem comments have lines ending in '\'
CFLAGS := -std=c17 -g -Wall -Wextra -Wno-unused-parameter -Wno-comment -I.
SANITIZE := -fsanitize=address,undefined -fno-omit-frame-pointer
LINTFLAGS := -std=c17 -Wall -Wextra -Wpedantic -Wshadow -Wno-comment -Werror -I.

# P picks the pattern folder to build and test, e.g. `make test P=slidingwindow`
P ?= *
TESTS := $(sort $(wildcard $(P)/*_test.c))
BINS := $(patsubst %_test.c,build/%_test,$(TESTS))
SOURCES := $(sort $(wildcard */*.c */*.h))
C_FILES := $(sort $(wildcard */*.c))

# clang-format is pinned, because each release formats a little differently.
# The first fmt or fmt-check installs this version from PyPI into .tools/;
# changing the version here installs the new one.
CLANG_FORMAT_VERSION := 18.1.3
CLANG_FORMAT := .tools/bin/clang-format
CLANG_FORMAT_STAMP := .tools/clang-format-$(CLANG_FORMAT_VERSION)

all: check

build: compile_commands.json $(BINS)

# tells clangd (the editor's language server) how every C file is compiled;
# refreshed on each build so new files are picked up
compile_commands.json:
	@./scripts/compile_commands.py "$(CC)" "$(CFLAGS)" $(C_FILES)

# every test file includes its solution, so each one builds into its own program
build/%_test: %_test.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(SANITIZE) -MMD -MP -o $@ $< -lm

-include $(BINS:=.d)

test: build
	@./scripts/run_tests.sh $(BINS)

test-verbose: build
	@./scripts/run_tests.sh -v $(BINS)

# T picks the test to debug, e.g. `make debug T=slidingwindow/avg`.
# Leak detection can't run under a debugger, so it is switched off here.
debug:
	@if [ -z "$(T)" ]; then \
		echo "Usage: make debug T=<folder>/<problem>"; \
		echo "Example: make debug T=slidingwindow/avg"; \
		exit 1; \
	fi
	@$(MAKE) -s build/$(T)_test
	ASAN_OPTIONS=detect_leaks=0 lldb build/$(T)_test

$(CLANG_FORMAT_STAMP):
	python3 -m venv .tools
	.tools/bin/pip install --quiet --disable-pip-version-check \
		clang-format==$(CLANG_FORMAT_VERSION)
	@touch $@

fmt: $(CLANG_FORMAT_STAMP)
	@CLANG_FORMAT=$(CLANG_FORMAT) ./scripts/format.py $(SOURCES)

fmt-check: $(CLANG_FORMAT_STAMP)
	@CLANG_FORMAT=$(CLANG_FORMAT) ./scripts/format.py --check $(SOURCES)

lint:
	@for f in $(TESTS); do \
		$(CC) $(LINTFLAGS) -fsyntax-only $$f || exit 1; \
	done
	@long=$$(awk 'length($$0) > 80 { print FILENAME ":" FNR ": " length($$0) " chars" }' $(SOURCES)); \
	if [ -n "$$long" ]; then echo "Lines over 80 characters:"; echo "$$long"; exit 1; fi

check: lint test fmt

clean:
	rm -rf build
