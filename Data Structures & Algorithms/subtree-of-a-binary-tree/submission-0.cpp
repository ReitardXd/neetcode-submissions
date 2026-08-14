
class Solution {
public:
    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot)
            return true;

        if (!root || !subRoot)
            return false;

        if (root->val != subRoot->val)
            return false;

        return sameTree(root->left, subRoot->left) &&
               sameTree(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot)
            return true;

        if (!root)
            return false;

        if (sameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};