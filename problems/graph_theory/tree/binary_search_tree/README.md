# Binary Tree V/S Binary Search Tree

A binary search tree (BST) and a binary tree are both types of tree data structures, but they have different characteristics and purposes.

1. **Binary Tree**:

   - A binary tree is a hierarchical data structure where each node has at most two children, usually referred to as the left child and the right child.
   - In a binary tree, there are no specific rules or constraints about the ordering of elements or values in the tree. Each node can have any value and can be placed in any order.
   - Binary trees can be used for a variety of purposes, including representing mathematical expressions, organizing hierarchical data, and serving as the basis for more specialized tree structures like binary search trees.
   - Example of a binary tree:

   ```
        1
       / \
      2   3
     / \
    4   5
   ```

1. **Binary Search Tree (BST)**:

   - A binary search tree is a type of binary tree where each node's value follows a specific ordering rule:
     - All values in the left subtree of a node are less than the node's value.
     - All values in the right subtree of a node are greater than the node's value.
   - Due to this ordering rule, binary search trees are particularly useful for efficient searching, insertion, and deletion operations. They enable fast lookup of elements, making them suitable for implementing data structures like sets and maps.
   - Example of a binary search tree:

   ```
        5
       / \
      2   8
     / \ / \
    1  3 6  9
   ```

In summary, a binary tree is a general tree structure with no specific ordering of elements, while a binary search tree imposes a specific ordering rule on its elements to enable efficient searching and manipulation operations. Binary search trees are a specialized form of binary trees designed for efficient data retrieval based on value ordering.
