#include <iostream>
#include <stack>
#include <time.h>
using namespace std;

typedef struct BiTNode
{
	int data;
	BiTNode* lchild, *rchild;
	BiTNode(int val)
	{
		data = val;
		lchild = NULL;
		rchild = NULL;
	}

};
typedef BiTNode* PBNode;

class BSTree
{
public:
	BSTree()
	{
		pRoot = NULL;
	}
	~BSTree()
	{
		if (pRoot == NULL)
			return;
		FreeMemory(pRoot);
	}
	void Insert(int value);       //增加，内部调用insert两个参数的
	void Insert(PBNode pnode,int value);

	PBNode Search(int key);      //查找key对应的节点，调用下面的search
	PBNode Search(PBNode pnode,int key);  

	void Delete(int key);

	void PreorderRecursively(PBNode pnode);		//前序遍历递归
	void InorderRecursively(PBNode pnode);		//中序遍历递归
	void PostorderRecursively(PBNode pnode);		//后序遍历递归

	void Preorder();       //  前序遍历,非递归方法（借用堆栈）
	void Inorder();        //  中序遍历,非递归方法（借用堆栈）
	void Postorder();      //  后序遍历,非递归方法（借用堆栈）

	PBNode GetMaxKey();     //  获得二叉查找树中元素值最大的节点
	PBNode GetMinKey();     //  获得二叉查找树中元素值最小的节点

	void FreeMemory(PBNode p);

public:
	PBNode pRoot;
};

void BSTree::Insert(int value)       //增加，内部调用insert两个参数的
{
	if (pRoot == NULL)
	{
		pRoot = new BiTNode(value);
	}
	else
		Insert(pRoot, value);
}

void BSTree::Insert(PBNode pnode, int value)
{
	if (pnode->data > value)
	{
		if (pnode->lchild == NULL)
			pnode->lchild = new BiTNode(value);
		else
			Insert(pnode ->lchild,value);
	}
	else      //大于等于的都在右边
	{
		if (pnode->rchild == NULL)
			pnode->rchild = new BiTNode(value);
		else
			Insert(pnode->rchild, value);
	}
}

PBNode BSTree::Search(int key)
{
		return Search(pRoot,key);
}

PBNode BSTree::Search(PBNode pnode, int key)
{
	if (pnode == NULL)
		return NULL;
	
	if (pnode->data == key)
		return pnode;
	else if (pnode->data > key)
		return Search(pnode->lchild, key);
	else
		return Search(pnode->rchild, key);
}

//删除最关键，分为三种情况
//1：删除叶子节点
//2：删除只有一个孩子的节点
//3：删除有两个孩子的（将左子树最右节点替换上去或者右子树的最左节点，就是按序排列的待删除的左右两端的数据替换它）
void BSTree::Delete(int key)
{
	PBNode pParent = pRoot;
	PBNode pFind = pRoot;

	//找到key对应的元素节点以及其父节点
	while (pFind != NULL)
	{
		if (pFind->data == key)
			break;
		pParent = pFind;
		if (pFind->data > key)
			pFind = pFind->lchild;
		else
			pFind = pFind->rchild;
	}

	if (pFind == NULL)    //未找到
		return;

	//删除只有一个孩子的或者叶子节点的
	if (pFind->lchild == NULL || pFind->rchild == NULL)
	{
		PBNode ptemp = NULL;
		if (pFind->lchild != NULL)
			ptemp = pFind->lchild;
		else if (pFind->rchild != NULL)
			ptemp = pFind->rchild;
		
		if (pParent->lchild == pFind)
			pParent->lchild = ptemp;
		else
			pParent->rchild = ptemp;
		delete pFind;
		pFind = NULL;
	}
	//删除有两个孩子的
	else     
	{
		PBNode ptemp = pFind->lchild;
		PBNode ptempParent = pFind;

		while (ptemp->rchild != NULL)
		{
			ptempParent = ptemp;
			ptemp = ptemp->rchild;
		}

		pFind->data = ptemp->data;
		if (ptempParent != pFind)
			ptempParent->rchild = ptemp->lchild;
		else
			ptempParent->lchild = ptemp->lchild;
		delete ptemp;
		ptemp = NULL;
		
	}

}

void BSTree::PreorderRecursively(PBNode pnode)		//前序遍历递归
{
	if (pnode == NULL)
		return;

		cout << pnode->data << " ";
		PreorderRecursively(pnode->lchild);
		PreorderRecursively(pnode->rchild);

}
void BSTree::InorderRecursively(PBNode pnode)		//中序遍历递归
{
	if (pnode == NULL)
		return;

		InorderRecursively(pnode->lchild);
		cout << pnode->data << " ";	
		InorderRecursively(pnode->rchild);
;
}
void BSTree::PostorderRecursively(PBNode pnode)		//后序遍历递归
{
	if (pnode == NULL)
		return;

		PostorderRecursively(pnode->lchild);
		PostorderRecursively(pnode->rchild);
		cout << pnode->data << " ";

}

void BSTree::Preorder()       //  前序遍历,非递归方法（借用堆栈）
{
	if (pRoot == NULL)
	{
		cout << "BST IS EMPTY" << endl;
		return;
	}

	stack<PBNode> s;
	PBNode pnode = pRoot;
	while (pnode!=NULL||!s.empty())
	{
		while (pnode != NULL)
		{
			cout << pnode->data << " ";
			s.push(pnode);
			pnode = pnode->lchild;
		}
		pnode = s.top()->rchild;
		s.pop();
	}
}

void BSTree::Inorder()        //  中序遍历,非递归方法（借用堆栈）
{
	if (pRoot == NULL)
	{
		cout << "BST IS EMPTY" << endl;
		return;
	}
	stack<PBNode> s;
	PBNode pnode = pRoot;
	while (pnode!=NULL|| !s.empty())
	{
		while (pnode!=NULL)
		{
			s.push(pnode);
			pnode = pnode->lchild;
		}
		pnode = s.top();
		cout << pnode->data << " ";
		pnode = pnode->rchild;
		s.pop();
	}
}

//  后序遍历,非递归方法，借助变量表示是否访问过该根节点
//  如果还有左或者右孩子就先不能输出，直到将左右遍历了才能输出，所以要标记
void BSTree::Postorder()      
{
	if (pRoot == NULL)
	{
		cout << "BST IS EMPTY" << endl;
		return;
	}

	stack<pair<PBNode,bool>> s;
	s.push(make_pair(pRoot, false));
	
	while (!s.empty())
	{
		PBNode pnode = s.top().first;
		bool judge = s.top().second;

		if (pnode == NULL)
		{
			s.pop();
			continue;
		}

		if (judge)     //被访问过了，可以直接输出
		{
			cout << pnode->data << " ";
			s.pop();
		}
		else
		{
			s.top().second = true;
			s.push(make_pair(pnode->rchild, false));
			s.push(make_pair(pnode->lchild, false));
		}
	}
		
}

PBNode BSTree::GetMaxKey()     //  获得二叉查找树中元素值最大的节点
{
	if (pRoot == NULL)
		return NULL;

	PBNode pnode = pRoot;
	while(pnode->rchild != NULL)
	{
		pnode = pnode->rchild;
	}
	return pnode;
}

PBNode BSTree::GetMinKey()     //  获得二叉查找树中元素值最小的节点
{
	if (pRoot == NULL)
		return NULL;

	PBNode pnode = pRoot;
	while (pnode->lchild != NULL)
	{
		pnode = pnode->lchild;
	}
	return pnode;
}

//析构中调用释放内存
void BSTree::FreeMemory(PBNode p)
{
	if (p == NULL)
		return;
	if (p->lchild != NULL)
		FreeMemory(p->lchild);
	if (p->rchild != NULL)
		FreeMemory(p->rchild);
	
	delete p;
	p = NULL;
}

int main()
{
	BSTree* pTree = new BSTree();
	srand(time(NULL));


	cout << " 随机数据插入顺序: ";
	for (int i = 0; i < 15; i++)
	{
		int tmp = rand() % 100;
		pTree->Insert(tmp);
		cout << tmp << " ";
	}
	PBNode pRoot = pTree->pRoot;

	cout << endl;
	cout << " 非递归前序遍历   ：";
	pTree->Preorder();
	cout << endl;

	cout << " 递归前序遍历    ：";
	pTree->PreorderRecursively(pRoot);
	cout << endl;

	cout << " 非递归中序遍历   ：";
	pTree->Inorder();
	cout << endl;

	cout << " 递归中序遍历    ：";
	pTree->InorderRecursively(pRoot);
	cout << endl;

	cout << " 非递归后序遍历   ：";
	pTree->Postorder();
	cout << endl;

	cout << " 递归后续遍历    ：";
	pTree->PostorderRecursively(pRoot);
	cout << endl;

	PBNode pMaxNode = pTree->GetMaxKey();
	PBNode pMinNode = pTree->GetMinKey();
	if (pMaxNode != NULL)
		cout << " 该二叉查找树的最大元素是：" << pMaxNode->data << endl;

	if (pMinNode != NULL)
		cout << " 该二叉查找树的最小元素是：" << pMinNode->data << endl;

	int DeleteKey = 15;
	PBNode pSearchNode = pTree->Search(DeleteKey);
	if (pSearchNode != NULL)
		cout << " 需要查询的元素是：" << DeleteKey << ", 实际查询到的元素是：" << pSearchNode->data << endl;
	else
		cout << " 没有查询到元素" << DeleteKey << endl;
	
	pTree->Delete(DeleteKey);
	cout << " 删除元素" << DeleteKey << "之后的递归前序遍历：";
	pTree->PreorderRecursively(pRoot);
	cout << endl;

	DeleteKey = 1;
	pTree->Delete(DeleteKey);
	cout << " 删除元素" << DeleteKey << "之后的递归前序遍历：";
	pTree->PreorderRecursively(pRoot);
	cout << endl;

	DeleteKey = 8;
	pTree->Delete(DeleteKey);
	cout << " 删除元素" << DeleteKey << "之后的递归前序遍历：";
	pTree->PreorderRecursively(pRoot);
	cout << endl;

	DeleteKey = 26;
	pTree->Delete(DeleteKey);
	cout << " 删除元素" << DeleteKey << "之后的递归前序遍历：";
	pTree->PreorderRecursively(pRoot);
	cout << endl;
	
	delete pTree;
	pTree = NULL;
	return 1;
}