# Binary Tree Traversal - Solution

In this article, we will provide the recursive solution for the three traversal methods we have mentioned. And talk
about the implementation of the iterative solution. Finally, we will discuss the difference between them.

*Iterative Solution*

There are several iterative solutions for tree traversal. One of the solutions is to use a stack to simulate the
recursion process.

Taking pre-order traversal as an example, in each iteration, we pop one node from the stack and visit this node. Then if
this node has a right child, push its right child into the stack. If this node has a left child, push its left child
into the stack. It is noteworthy that we push the right child first so that we can visit the left child first since the
nature of the stack is LIFO(last in first out). After that, we can continue to the next iteration until the stack is
empty.

Here are java and c++ codes for your reference.
