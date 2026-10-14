"""Helpers shared by the merge intervals problems."""

from dataclasses import dataclass


@dataclass
class Interval:
    start: int
    end: int
