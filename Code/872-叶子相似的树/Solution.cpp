#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/**
    分别找出两个树的叶值序列，进行比较
    深搜，如果结点是叶子，写入该值
**/

//   官方题解
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;
        dfs(root1, leaves1);
        dfs(root2, leaves2);

        return leaves1 == leaves2;
    }

    void dfs(TreeNode* node, vector<int>& leaves) {
        if (node == NULL) return;
        if (node->left == NULL && node->right == NULL)
            leaves.push_back(node->val);
        dfs(node->left, leaves);
        dfs(node->right, leaves);
    }
};


// 渣码
class Solution1{
public:
    vector<int> dfs( TreeNode* root, vector<int>& v) {
        if (root->left == NULL && root->right == NULL) {
            v.push_back(root->val);
        }
        if (root->left != NULL) {
            dfs( root->left,v);
        }
        if (root->right != NULL) {
            dfs( root->right,v);
        }
        return v;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        v1 = dfs(root1, v1);
        v2 = dfs(root2, v2);
        return v1==v2;
    }
}