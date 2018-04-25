"Top-down" Solution

 the "top-down" solution can be considered as kind of ""preorder"" traversal.
 To be specific, the recursion function top_down(root, params) works like this:


1. return specific value for null node
2. update the answer if needed                      // anwer <-- params
3. left_ans = top_down(root.left, left_params)      // left_params <-- root.val, params
4. right_ans = top_down(root.right, right_params)   // right_params <-- root.val, params
5. return the answer if needed                      // answer <-- left_ans, right_ans



"Bottom-up" Solution

This process can be regarded as kind of postorder traversal. Typically, a "bottom-up" recursion function bottom_up(root) will be like this:
1. return specific value for null node
2. left_ans = bottom_up(root.left)          // call function recursively for left child
3. right_ans = bottom_up(root.right)        // call function recursively for right child
4. return answers                           // answer <-- left_ans, right_ans, root.val
