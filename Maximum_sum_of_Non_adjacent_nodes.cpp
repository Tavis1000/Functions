pair<int, int> fun(Node* root){
        if(root == NULL){
            return {0, 0};
        }
        auto left = fun(root->left);
        auto right = fun(root->right);
        int one = root->data + left.second + right.second;
        int two = max(left.first, left.second) + max(right.first, right.second);
        return {one, two};
    }
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        // code here
        auto ans = fun(root);
        return max(ans.first, ans.second);
    }