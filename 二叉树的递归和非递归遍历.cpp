//***************************************************************
//           二叉树的递归遍历BT（二元树Binary tree）的遍历（包括递归和非递归）
//****************************************************************

typedef struct BTNode
{
	char data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;

//二叉树的递归遍历
void preorder(BTNode *p)
{
	if(p != NULL)
	{
		//visit(p);先序
		preorder(p->lchild);
		//visit(p);中序
		preorder(p->rchild);
		//visit(p);后序
	}
}

/* 二叉树的非递归遍历 --> 都是用人工栈解决的 */

//二叉树先序非递归遍历
void preorder_Nonrecursion(BTNode *root)
{
	if(root != NULL){
		BTNode *Stack[MAXSIZE];
		int top = -1;
		BTNode *p = NULL;//初始化一个游标，实质是用一个p去采集，并且借助visit访问出栈元素
		Stack[++top] = root;//先把树根放进栈顶
		while(top != -1)//栈空退出循环，也就是完成了bt的遍历
		{
			p = Stack[top--];//用p采集出栈元素
			visit(p);//（采集并）访问
			if(p->rchild != NULL)//这么做的目的是让为了先访问左子树，故让右子树先入栈
				Stack[++top] = p->rchild;
			if(p->lchild != NULL)
				Stack[++top] = p->lchild;
		}
	}
	
}

//二叉树的后序遍历 --> 后序（左右根）先把先序（根左右）变为逆后序（根右左） 然后用一个栈逆序成后序（左右根）
void postorderNoncursion(BTNode *root)
{
	if(root != NULL)
	{
		BTNode *Stack_store_temp[MAXSIZE];int top1 = -1;//类似于先序遍历里栈的功能
		BTNode *Stack_reverse_elem[MAXSIZE];int top2 = -1;//用来反转序列的栈
		BTNode * p = NULL;
		Stack_store_temp[++top1] = root;
		while(top1 != -1)
		{
			p = Stack_store_temp[top1--];//采集出栈元素
			Stack_reverse_elem[++top2] = p;//栈顶出栈后入到反转栈
			if(p->lchild != NULL)
				Stack_store_temp[top1--] = Stack_reverse_elem[++top2];
			if(p->rchild != NULL)
				Stack_store_temp[top1--] = Stack_reverse_elem[++top2];
		}
		while(top2 != -1)//现在已经得到了存储在反转栈的反转好的元素序列，然后出栈即得到了目标序列
			p = Stack_reverse_elem[top2--];
		visit(p);
	}
}

//二叉树的中序遍历  --> 先左后根再右，如果根存在左孩子，一直把左孩子入进去，不存在左孩子则把该node输出

//（输出的作为根找右孩子-->找到了继续上边的过程），只要不存在左孩子或者右孩子就出栈栈顶元素，出栈的就判断右孩子
//存在右孩子的就入栈，新入栈的元素就找左孩子


/*总而言之，新入栈的找左孩子，新出栈的找右孩子*/
void inorderNoncursion(BTNode *p)
{
	if(p != NULL)
	{
		BTNode *Stack[MAXSIZE];int top = -1;
		BTNode *p = NULL;
		while(top != -1 || p != NULL)//会有现状为栈空但是下一次会入栈的情况
		{
			while(p != NULL)//一直到左子树一路入栈，新入栈的要找其左子树
			{
				Stack[++top] = p;
				p = p->lchild;
			}
			if(top != -1)//找不到左子树的要先出栈然后寻找刚刚出栈这个node的右子树
			{
				p = Stack[top--];//p为上边的无左子树的node，出栈
				visit(p);//出栈并且访问
				p = p->rchild;//访问右子树，如果有的话进入到上边的while循环一路找左子树，如果没有的话，进入现在的循环体，先出栈顶，然后寻找右子树
			}
		}
	}
}


