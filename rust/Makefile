.PHONY: all build test test-verbose debug fmt fmt-check lint check clean

all: check

build:
	cargo build

# P picks the pattern to test, e.g. `make test P=slidingwindow`
FILTER := $(if $(P),$(P)::)

test:
	cargo test $(FILTER)

test-verbose:
	cargo test $(FILTER) -- --nocapture

# T picks the test to debug, e.g. `make debug T=slidingwindow/avg`.
# Tests run on one thread here, so stepping stays in the test being debugged.
debug:
	@if [ -z "$(T)" ]; then \
		echo "Usage: make debug T=<folder>/<problem>"; \
		echo "Example: make debug T=slidingwindow/avg"; \
		exit 1; \
	fi
	@bin=$$(cargo test --no-run 2>&1 | grep -o 'target/debug/deps/dsapatterns-[0-9a-f]*'); \
	if [ -z "$$bin" ]; then cargo test --no-run; exit 1; fi; \
	rust-lldb $$bin -- $(subst /,::,$(T))_test:: --test-threads=1

fmt:
	cargo fmt

fmt-check:
	cargo fmt --check

lint:
	cargo clippy --all-targets -- -D warnings
	@long=$$(git ls-files -co --exclude-standard '*.rs' | xargs awk 'length($$0) > 80 { print FILENAME ":" FNR ": " length($$0) " chars" }'); \
	if [ -n "$$long" ]; then echo "Lines over 80 characters:"; echo "$$long"; exit 1; fi

check: lint test fmt

clean:
	cargo clean
