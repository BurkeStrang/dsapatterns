.PHONY: all build test test-verbose fmt lint check clean

all: check

build:
	dotnet build

test:
	dotnet test

test-verbose:
	dotnet test --logger "console;verbosity=detailed"

fmt:
	dotnet tool restore
	dotnet csharpier format .

lint:
	dotnet build -warnaserror --no-incremental
	@long=$$(git ls-files -co --exclude-standard '*.cs' | xargs awk 'length($$0) > 80 { print FILENAME ":" FNR ": " length($$0) " chars" }'); \
	if [ -n "$$long" ]; then echo "Lines over 80 characters:"; echo "$$long"; exit 1; fi

check: lint test fmt

clean:
	dotnet clean
