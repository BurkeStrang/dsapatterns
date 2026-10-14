"""Adds the --case option, which runs only the test cases with that name."""

import pytest


def pytest_addoption(parser: pytest.Parser) -> None:
    parser.addoption(
        "--case",
        help='run only the test cases named CASE, e.g. --case "window size 1"',
    )


def pytest_collection_modifyitems(
    config: pytest.Config, items: list[pytest.Item]
) -> None:
    case = config.getoption("--case")
    if case is None:
        return
    keep: list[pytest.Item] = []
    skip: list[pytest.Item] = []
    for item in items:
        callspec = getattr(item, "callspec", None)
        if callspec is not None and callspec.id == case:
            keep.append(item)
        else:
            skip.append(item)
    config.hook.pytest_deselected(items=skip)
    items[:] = keep
