.PHONY: all build test test-verbose fmt fmt-check lint check clean

all: check

build:
	cargo build

# P picks the pattern to test, e.g. `make test P=slidingwindow`
test:
	cargo test $(P)

test-verbose:
	cargo test $(P) -- --nocapture

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
