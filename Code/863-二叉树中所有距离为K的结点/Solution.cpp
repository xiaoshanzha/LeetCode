class Solution {
    private:
        stack<TreeNode*> st;
        vector<int> ret;
    public:
        vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {

            //获得从target子树的距离为K的节点
            findByDistance(target, K);

            //先序遍历的方式，记录从root到target的路径，并压入栈中
            preOrder(root, target);

            //对栈中对象进行处理
            int deep = 1;
            TreeNode* tmp = target;
            while (!st.empty() && deep <= K) {
                TreeNode* parent = st.top();
                st.pop();

                if (K == deep)
                    ret.push_back(parent->val);
                else if (parent->left == tmp)
                    findByDistance(parent->right, K - deep - 1);
                else
                    findByDistance(parent->left, K - deep - 1);
                tmp = parent;
                ++deep;
            }


            return ret;
        }

        //记录从根节点到target的路径，压入栈中
        bool preOrder(TreeNode* root, TreeNode* target) {
            if (root == NULL)
                return false;

            if (root == target)
                return true;

            st.push(root);

            if (preOrder(root->left, target) || preOrder(root->right, target)) {
                return true;
            }

            st.pop();
            return false;
        }


        //获得从root子树，距离为k的节点
        void findByDistance(TreeNode* root, int k) {
            if (root == NULL)
                return;

            if (k == 0) {
                ret.push_back(root->val);
                return;
            }

            findByDistance(root->left, k-1);
            findByDistance(root->right, k-1);

        }

};