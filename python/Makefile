.PHONY: all setup test test-verbose debug fmt fmt-check lint check clean

PYTHON ?= python3
VENV := .venv
BIN := $(VENV)/bin

# P picks the pattern folder to test, e.g. `make test P=slidingwindow`
P ?= .
# CASE runs only the test cases with that name, e.g. CASE="window size 1"
CASE_OPT = $(if $(CASE),--case "$(CASE)")

all: check

# the tools live in .venv, made on first use and again when
# requirements-dev.txt changes
setup: $(VENV)/.installed

$(VENV)/.installed: requirements-dev.txt
	$(PYTHON) -m venv $(VENV)
	$(BIN)/pip install --quiet --disable-pip-version-check -r requirements-dev.txt
	@touch $@

test: setup
	@$(BIN)/pytest $(CASE_OPT) $(P)

test-verbose: setup
	@$(BIN)/pytest -v $(CASE_OPT) $(P)

# T picks the test to debug, e.g. `make debug T=slidingwindow/avg`.
# pdb stops at the start of each test case; add CASE=... to pick one.
# -s shows print() output as it happens; quitting pdb isn't a make error.
debug: setup
	@if [ -z "$(T)" ]; then \
		echo "Usage: make debug T=<folder>/<problem> [CASE=<test case>]"; \
		echo "Example: make debug T=slidingwindow/avg CASE=\"window size 1\""; \
		exit 1; \
	fi
	@$(BIN)/pytest -s --trace $(CASE_OPT) $(T)_test.py || true

fmt: setup
	@$(BIN)/ruff format --quiet .
	@$(BIN)/ruff check --quiet --select I --fix .

fmt-check: setup
	@$(BIN)/ruff format --check .

lint: setup
	@$(BIN)/ruff check .
	@$(BIN)/mypy .

check: lint test fmt

clean:
	rm -rf .pytest_cache .mypy_cache .ruff_cache
	find . -name __pycache__ -not -path './$(VENV)/*' -prune -exec rm -rf {} +
