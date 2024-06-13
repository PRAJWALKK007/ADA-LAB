
bool binSearch(struct TreeNode* root, int target)
{
    if (root == NULL) {
        return false;
    }
    
    if (root->val == target) {
        return true;
    }
    else if (root->val > target) {
        return binSearch(root->left, target);
    }
    else {
        return binSearch(root->right, target);
    }
}
 
bool dfs(struct TreeNode *root, struct TreeNode *curr, int target)
{
    if (curr==NULL) {
        return false;
    }
    
    if (target - curr->val != curr->val) {
        if (binSearch(root, target - curr->val) == true) {
            return true;
        }
    }
    
    return (dfs(root, curr->left, target) || dfs(root, curr->right, target));
}

bool findTarget(struct TreeNode* root, int k){     
    return dfs(root, root, k);
}
