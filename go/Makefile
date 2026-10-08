.PHONY: all build test test-verbose vet fmt lint check clean

all: check

build:
	go build ./...

test:
	go test -race ./...

test-verbose:
	go test -v -race ./...

vet:
	go vet ./...

fmt:
	gofmt -s -w .

lint:
	golangci-lint run ./...

check: vet lint test fmt

clean:
	go clean ./...
