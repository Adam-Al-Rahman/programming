# Functional Graph

A **functional graph** is a special type of directed graph where each vertex has exactly one outgoing edge. These graphs are often used in problems where each element can be mapped to exactly one other element (like a function), creating a deterministic and directed structure.

## Properties:

1. **Single Outdegree**: Each node in the graph has exactly one outgoing edge.
2. **Cycles and Chains**: Functional graphs consist of cycles and chains (or paths leading into cycles). Every vertex eventually reaches a cycle.
3. **Deterministic Traversal**: Since each node has one outgoing edge, the graph is deterministic in how you can move from one node to the next.
4. **Graph Components**: The graph may consist of several components, each having exactly one cycle, and the nodes not in the cycle lead into it via a chain.

## Example of Functional Graph

Consider the following function mapping:

[ f(x) = { (1 -> 2), (2 -> 3), (3 -> 1), (4 -> 5), (5 -> 4) } ]

This would look like two separate components:

1. A cycle: 1 → 2 → 3 → 1.
2. Another cycle: 4 → 5 → 4.

## Applications:

- **Cycle Detection**: Functional graphs are often used for problems involving cycle detection or finding the number of steps to reach a cycle.
- **Dynamic Programming**: Functional graphs can be used in DP problems, where transitions between states can be represented as nodes and edges.
- **Modular Arithmetic**: In problems related to modular arithmetic, functional graphs may represent number transitions based on some modular function.

## Key Aspects:

- **Cycle Detection**: The code uses Floyd's Tortoise and Hare algorithm to detect cycles.
- **Cycle Length**: Once a cycle is detected, the length of the cycle is computed and stored for each node.

Functional graphs are quite useful in algorithmic problems, especially in competitive programming, where they can represent various processes like transitions between states, modular arithmetic operations, or other mappings.
