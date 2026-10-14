.PHONY: all build test test-verbose debug fmt fmt-check lint check clean \
	compile_commands.json

# clang++ by default: lldb shows its debug info best (`make CXX=g++` overrides)
CXX = clang++
# -Wno-comment: tree diagrams in the problem comments have lines ending in '\'
CXXFLAGS := -std=c++20 -g -Wall -Wextra -Wno-unused-parameter -Wno-comment -I.
SANITIZE := -fsanitize=address,undefined -fno-omit-frame-pointer
LINTFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -Wshadow -Wno-comment \
	-Werror -I.

# each test program takes a second or two to compile, so build them on every
# core at once (`make -j1` builds one at a time)
MAKEFLAGS += --jobs=$(shell nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null \
	|| echo 4)

# P picks the pattern folder to build and test, e.g. `make test P=slidingwindow`
P ?= *
TESTS := $(sort $(wildcard $(P)/*_test.cpp))
BINS := $(patsubst %_test.cpp,build/%_test,$(TESTS))
SOURCES := $(sort $(wildcard */*.cpp */*.hpp))
CPP_FILES := $(sort $(wildcard */*.cpp))

all: check

build: compile_commands.json $(BINS)

# tells clangd (the editor's language server) how every C++ file is compiled;
# refreshed on each build so new files are picked up
compile_commands.json:
	@./scripts/compile_commands.py "$(CXX)" "$(CXXFLAGS)" $(CPP_FILES)

# every test file includes its solution, so each one builds into its own program
build/%_test: %_test.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(SANITIZE) -MMD -MP -o $@ $<

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

fmt:
	@clang-format -i $(SOURCES)

fmt-check:
	@clang-format --dry-run --Werror $(SOURCES)

lint:
	@for f in $(TESTS); do \
		$(CXX) $(LINTFLAGS) -fsyntax-only $$f || exit 1; \
	done
	@long=$$(awk 'length($$0) > 80 { print FILENAME ":" FNR ": " length($$0) " chars" }' $(SOURCES)); \
	if [ -n "$$long" ]; then echo "Lines over 80 characters:"; echo "$$long"; exit 1; fi

check: lint test fmt

clean:
	rm -rf build
