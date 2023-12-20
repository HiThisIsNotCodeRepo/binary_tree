# Binary Tree Level Traversal - Solution

We provide C++ and Java codes for your reference.

Since each node in the tree will be pushed into the queue exactly once, the time complexity for level-order traversal is
O(N), where N is the total number of nodes in the tree.

What about the space complexity? We have to maintain a queue to help us to do the traversal. And the size of the queue
will be at most N because each node will be pushed into the queue exactly once. Therefore, the space complexity of
level-order traversal is also O(N).
