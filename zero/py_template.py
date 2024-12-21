import sys
from collections import defaultdict, deque
from itertools import permutations, combinations
from heapq import heappop, heappush
from math import gcd, sqrt, factorial
from functools import lru_cache
from bisect import bisect_left, bisect_right
from typing import List, Tuple, Dict, Any

# Fast input/output
input = sys.stdin.read


def get_ints():
    return map(int, input().split())


def get_list():
    return list(map(int, input().split()))


def solve():
    n = int(input().strip())
    arr = get_list()


def main():
    """
    Main entry point.
    Handles multiple test cases and invokes the solve function.
    """
    # Uncomment for single test case
    # solve()

    # Uncomment for multiple test cases
    data = input().strip().split("\n")
    T = int(data[0])
    idx = 1
    for _ in range(T):
        sys.stdin = iter(data[idx:])
        solve()
        idx += 1


if __name__ == "__main__":
    # Disable recursion limit for problems with deep recursion
    sys.setrecursionlimit(10**6)

    # Call the main function
    main()
