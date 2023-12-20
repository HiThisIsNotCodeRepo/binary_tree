# Solve Tree Problems Recursively

In previous sections, we have introduced how to solve tree traversal problems recursively. Recursion is one of the most
powerful and frequently used techniques for solving tree problems.

As we know, a tree can be defined recursively as a node(the root node) that includes a value and a list of references to
children nodes. Recursion is one of the natural features of a tree. Therefore, many tree problems can be solved
recursively. For each recursive function call, we only focus on the problem for the current node and call the function
recursively to solve its children.

Typically, we can solve a tree problem recursively using a top-down approach or using a bottom-up approach.

*"Top-down" Solution*

"Top-down" means that in each recursive call, we will visit the node first to come up with some values, and pass these
values to its children when calling the function recursively. So the "top-down" solution can be considered as a kind of
preorder traversal. To be specific, the recursive function top_down(root, params) works like this:

```
1. return specific value for null node
2. update the answer if needed                      // answer <-- params
3. left_ans = top_down(root.left, left_params)      // left_params <-- root.val, params
4. right_ans = top_down(root.right, right_params)   // right_params <-- root.val, params
5. return the answer if needed                      // answer <-- left_ans, right_ans
```

For instance, consider this problem: given a binary tree, find its maximum depth.

Here we will define the depth of the root node as 1 (although often, the depth of the root node is defined as 0). For
each node, if we know its depth, we will know the depth of its children. Therefore, if we pass the depth of the node as
a parameter when calling the function recursively, all the nodes will know their depth. For leaf nodes, we can use the
depth to update the final answer. Here is the pseudocode for the recursive function maximum_depth(root, depth):

```
1. return if root is null
2. if root is a leaf node:
3.     answer = max(answer, depth)         // update the answer if needed
4. maximum_depth(root.left, depth + 1)     // call the function recursively for left child
5. maximum_depth(root.right, depth + 1)    // call the function recursively for right child
```

Here is an example to help you understand how it works:

We also provide C++ and Java codes for reference.

```
int answer; // don't forget to initialize the answer before calling maximum_depth
void maximum_depth(TreeNode* root, int depth) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        answer = max(answer, depth);
    }
    maximum_depth(root->left, depth + 1);
    maximum_depth(root->right, depth + 1);
}
```

*"Bottom-up" Solution*

"Bottom-up" is another recursive solution. In each recursive call, we will first call the function recursively for all
the children nodes and then come up with the answer according to the returned values and the value of the current node
itself. This process can be regarded as a kind of postorder traversal. Typically, a "bottom-up" recursive function
bottom_up(root) will be something like this:

```
1. return specific value for null node
2. left_ans = bottom_up(root.left)      // call function recursively for left child
3. right_ans = bottom_up(root.right)    // call function recursively for right child
4. return answers                       // answer <-- left_ans, right_ans, root.val
```

Let's go on discussing the question about maximum depth but using a different way of thinking: for a single node of the
tree, what will be the maximum depth x of the subtree rooted at itself?

If we know the maximum depth l of the subtree rooted at its left child and the maximum depth r of the subtree rooted at
its right child, can we answer the previous question? Of course yes, we can choose the maximum between them and add 1 to
get the maximum depth of the subtree rooted at the current node. That is x = max(l, r) + 1.