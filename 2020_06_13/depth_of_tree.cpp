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
    int TreeDepth(TreeNode* pRoot)
    {
//递归法 
        if(pRoot == NULL)    //递归基 - 即根节点为空节点
            return 0;

        //递归深度为树的深度 - 不过O(depth(tree))
        //return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));//其最长路径必为 1 + max(左子树的最长路径，右子树的最长路径)
        
//迭代法 - 层次遍历 - 每有一层即深度+1

        queue<TreeNode*> Q;
        Q.push(pRoot); //根节点入队
        int depth = 0;
        
        while( !Q.empty() )    //队不空
        {
            //可访问本层数据 - 则深度+1
            ++depth;
            for(int i = 0; i < Q.size(); ++i) //需要将计数层的所有节点出队 - 其对应的下层节点入队 - 保证只计入层数 - 而非节点数
            {    
                //取出队首节点
                TreeNode* r = Q.front();
                Q.pop();
            
                if(r->left !=  NULL)//左孩子不空则先入队
                    Q.push(r->left);
                if(r->right != NULL)//右孩子后入队
                    Q.push(r->right);
            }//O(Q.size())
        }//O(depth)
    
        return depth;
    }//即节点总数 - O(n)
};
