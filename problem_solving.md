# Problem Solving

## 1. **Observation** ( Understand the problem )

- Carefully read the problem and identify key aspects such as constraints, special cases, and any visible patterns.
- Break down the problem to understand how the input behaves and what output is expected for different cases.
- Explore small examples and test cases to get a feel for the problem.
- Come up with some fact through **chain-of-reasoning**.

## 2. **Hypothesis** ( Forming a solution )

- Based on your observations, form a **hypothesis** about how to solve the problem.
- This is where you think of a potential solution approach, algorithm, or data structure that might work.
- The hypothesis is essentially your educated guess about how to tackle the problem. For instance, you may hypothesize that a greedy approach, dynamic programming, or a specific algorithm (e.g., binary search, graph traversal) will work.

## 3. **Proof** ( Verifying hypothesis correctness & efficiency)

- Once you have a hypothesis, you need to **prove** that it's correct. This involves:
- Validating the correctness of the solution by ensuring it handles all edge cases.
- Proving that the approach works for all inputs, perhaps by induction or by formalizing the logic behind it.
- Checking if the time and space complexity meet the problem's constraints.

## Hypothesis Techniques

- Modify an algorithm to fit the data structure
- Modify the data structure to fit an algorithm.

### General Patterns

- Induction
- Greedy
- Backtracking
- Dynamic Programming
- Square-Root Decomposition
- Bit Mask
- Two Pointers

### Concrete Algorithms

- Kruskal's Algorithm
- Fast Fourier Transform
- Li-Chao Tree
- DFS
- BFS
- Sieve of Eratosthenes
- Dijkstra
- Floyd Warshall
- Topology sort
- Trie
- Knuth-Morris-Prath
- $A^{*}$ Algorithm
- Kadane's Algorithm
- Stable Internships
- Moore's Algorithm

## Proof Techniques

- **Greedy Algorithms**: For greedy algorithms, the proof usually involves showing that locally optimal choices lead to a global optimum. Think about:

  - **Exchange Arguments**: Can you swap elements of a solution to prove that one choice is always better than the other?
  - **Counterexamples**: Try to come up with cases where the greedy choice might fail. If you can't, it’s a good sign your algorithm works.

- **Dynamic Programming**: In DP problems, the proof usually involves showing that:

  - **Optimal Substructure**: The problem can be broken into subproblems whose solutions can combine to form an overall solution.
  - **State Transition**: Prove that the transition from one state to another is correct and covers all cases.

- **Induction**: For some problems, especially recursive ones, mathematical induction is useful. The process involves:
  - **Base Case**: Show that the solution works for the smallest possible input.
  - **Inductive Step**: Assume it works for `n`, and prove it works for `n + 1`.

## References

- [How to read problem statements](https://codeforces.com/blog/entry/62730)
- [On "is this greedy or DP", forcing and rubber bands](https://codeforces.com/blog/entry/106346)
- [How to come up with the solutions: techniques](https://codeforces.com/blog/entry/20548)
