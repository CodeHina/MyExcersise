/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    void Mirror(TreeNode* pRoot)
    {
       
                if(pRoot == NULL)
                    return;
        //考察树的遍历 - 这里采用层次遍历 - 当前节点不空则交换左右指针
                queue<TreeNode*> q;
                q.push(pRoot);
                while (!q.empty())
                {
                    TreeNode* p = q.front();
                    q.pop();
                    //交换指针
                    TreeNode* temp = p->left;
                    p->left = p->right;
                    p->right = temp;

                    if (p->left)
                        q.push(p->left);
                    if (p->right)
                        q.push(p->right);
                }//O(9n) - 需要将所有节点遍历一遍 - O(n)
       
 /*
        //递归方法 - 将当前树看作一个二叉树 - 只需交换左右指针即可
        if (pRoot == NULL)
            return;        //递归基

        std::swap(pRoot->left, pRoot->right);//交换当前二叉树的左右指针

        Mirror(pRoot->left);
        Mirror(pRoot->right);                //递归即可

 */

    }
};