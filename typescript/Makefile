.PHONY: all setup test test-verbose debug fmt fmt-check lint check clean

BIN := node_modules/.bin

# P picks the pattern folder to test, e.g. `make test P=slidingwindow`
P ?=
# CASE runs only the test cases whose name contains it, e.g.
# CASE="window size 1". Vitest reads -t as a regular expression, so the
# characters that mean something there are escaped first.
CASE_OPT = $(if $(CASE),-t "$$(printf '%s' '$(CASE)' | \
	sed 's/[][()*+?.^$$|{}\\]/\\&/g')")

DEBUG_PORT ?= 9229

SOURCES = $(shell find . -path ./node_modules -prune -o \
	\( -name '*.ts' -o -name '*.js' \) -print)

all: check

# the tools live in node_modules, installed on first use and again when
# package-lock.json changes
setup: node_modules/.installed

node_modules/.installed: package-lock.json
	npm ci --no-fund --no-audit
	@touch $@

test: setup
	@$(BIN)/vitest run $(CASE_OPT) $(P)

test-verbose: setup
	@$(BIN)/vitest run --reporter=verbose $(CASE_OPT) $(P)

# T picks the test to debug, e.g. `make debug T=slidingwindow/avg`.
# The tests start paused in the background, and Node's command-line debugger
# attaches to them; add CASE=... to run one test case. A paused test would
# otherwise fail after five seconds, so the timeout is turned off.
debug: setup
	@if [ -z "$(T)" ]; then \
		echo "Usage: make debug T=<folder>/<problem> [CASE=<test case>]"; \
		echo "Example: make debug T=slidingwindow/avg CASE=\"window size 1\""; \
		exit 1; \
	fi
	@$(BIN)/vitest run --inspect-brk=$(DEBUG_PORT) --no-file-parallelism \
		--test-timeout=0 \
		$(CASE_OPT) $(T).test.ts & \
	sleep 1; node inspect 127.0.0.1:$(DEBUG_PORT); wait

fmt: setup
	@$(BIN)/prettier --write --log-level warn .

fmt-check: setup
	@$(BIN)/prettier --check .

lint: setup
	@$(BIN)/tsc -p .
	@$(BIN)/eslint .
	@long=$$(awk 'length($$0) > 80 { print FILENAME ":" FNR ": " length($$0) " chars" }' $(SOURCES)); \
	if [ -n "$$long" ]; then echo "Lines over 80 characters:"; echo "$$long"; exit 1; fi

check: lint test fmt

clean:
	rm -rf node_modules/.vite node_modules/.vitest
