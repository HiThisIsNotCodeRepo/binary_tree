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

*Complexity Analysis*

As we mentioned before, we can traverse a tree recursively to retrieve all the data in pre-order, in-order or
post-order. The time complexity is O(N) because we visit each node exactly once. And the depth of the tree might be N in
the worst case. That is to say, the level of recursion might be at most N in the worst case. Therefore, taking system
stack into consideration, the space complexity is O(N) as well.

To be cautious, the complexity might be different due to a different implementation. It is comparatively easy to do
traversal recursively but when the depth of the tree is too large, we might suffer from stack overflow problem. That's
one of the main reasons why we want to solve this problem iteratively sometimes.

For the iterative solution, the time complexity is apparently the same with recursion solution which is O(N). The space
complexity is also O(N) since in the worst case, we will have all the nodes in the stack. There are some other solutions
for iterative traversal which can reduce the space complexity to O(1).
