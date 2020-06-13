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
        //�������ı��� - ������ò�α��� - ��ǰ�ڵ㲻���򽻻�����ָ��
                queue<TreeNode*> q;
                q.push(pRoot);
                while (!q.empty())
                {
                    TreeNode* p = q.front();
                    q.pop();
                    //����ָ��
                    TreeNode* temp = p->left;
                    p->left = p->right;
                    p->right = temp;

                    if (p->left)
                        q.push(p->left);
                    if (p->right)
                        q.push(p->right);
                }//O(9n) - ��Ҫ�����нڵ����һ�� - O(n)
       
 /*
        //�ݹ鷽�� - ����ǰ������һ�������� - ֻ�轻������ָ�뼴��
        if (pRoot == NULL)
            return;        //�ݹ��

        std::swap(pRoot->left, pRoot->right);//������ǰ������������ָ��

        Mirror(pRoot->left);
        Mirror(pRoot->right);                //�ݹ鼴��

 */

    }
};