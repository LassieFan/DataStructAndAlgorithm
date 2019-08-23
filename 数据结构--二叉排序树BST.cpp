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
	void Insert(int value);       //���ӣ��ڲ�����insert����������
	void Insert(PBNode pnode,int value);

	PBNode Search(int key);      //����key��Ӧ�Ľڵ㣬���������search
	PBNode Search(PBNode pnode,int key);  

	void Delete(int key);

	void PreorderRecursively(PBNode pnode);		//ǰ������ݹ�
	void InorderRecursively(PBNode pnode);		//��������ݹ�
	void PostorderRecursively(PBNode pnode);		//��������ݹ�

	void Preorder();       //  ǰ�����,�ǵݹ鷽�������ö�ջ��
	void Inorder();        //  �������,�ǵݹ鷽�������ö�ջ��
	void Postorder();      //  �������,�ǵݹ鷽�������ö�ջ��

	PBNode GetMaxKey();     //  ��ö����������Ԫ��ֵ���Ľڵ�
	PBNode GetMinKey();     //  ��ö����������Ԫ��ֵ��С�Ľڵ�

	void FreeMemory(PBNode p);

public:
	PBNode pRoot;
};

void BSTree::Insert(int value)       //���ӣ��ڲ�����insert����������
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
	else      //���ڵ��ڵĶ����ұ�
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

//ɾ����ؼ�����Ϊ�������
//1��ɾ��Ҷ�ӽڵ�
//2��ɾ��ֻ��һ�����ӵĽڵ�
//3��ɾ�����������ӵģ������������ҽڵ��滻��ȥ����������������ڵ㣬���ǰ������еĴ�ɾ�����������˵������滻����
void BSTree::Delete(int key)
{
	PBNode pParent = pRoot;
	PBNode pFind = pRoot;

	//�ҵ�key��Ӧ��Ԫ�ؽڵ��Լ��丸�ڵ�
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

	if (pFind == NULL)    //δ�ҵ�
		return;

	//ɾ��ֻ��һ�����ӵĻ���Ҷ�ӽڵ��
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
	//ɾ�����������ӵ�
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

void BSTree::PreorderRecursively(PBNode pnode)		//ǰ������ݹ�
{
	if (pnode == NULL)
		return;

		cout << pnode->data << " ";
		PreorderRecursively(pnode->lchild);
		PreorderRecursively(pnode->rchild);

}
void BSTree::InorderRecursively(PBNode pnode)		//��������ݹ�
{
	if (pnode == NULL)
		return;

		InorderRecursively(pnode->lchild);
		cout << pnode->data << " ";	
		InorderRecursively(pnode->rchild);
;
}
void BSTree::PostorderRecursively(PBNode pnode)		//��������ݹ�
{
	if (pnode == NULL)
		return;

		PostorderRecursively(pnode->lchild);
		PostorderRecursively(pnode->rchild);
		cout << pnode->data << " ";

}

void BSTree::Preorder()       //  ǰ�����,�ǵݹ鷽�������ö�ջ��
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

void BSTree::Inorder()        //  �������,�ǵݹ鷽�������ö�ջ��
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

//  �������,�ǵݹ鷽��������������ʾ�Ƿ���ʹ��ø��ڵ�
//  �������������Һ��Ӿ��Ȳ��������ֱ�������ұ����˲������������Ҫ���
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

		if (judge)     //�����ʹ��ˣ�����ֱ�����
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

PBNode BSTree::GetMaxKey()     //  ��ö����������Ԫ��ֵ���Ľڵ�
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

PBNode BSTree::GetMinKey()     //  ��ö����������Ԫ��ֵ��С�Ľڵ�
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

//�����е����ͷ��ڴ�
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


	cout << " ������ݲ���˳��: ";
	for (int i = 0; i < 15; i++)
	{
		int tmp = rand() % 100;
		pTree->Insert(tmp);
		cout << tmp << " ";
	}
	PBNode pRoot = pTree->pRoot;

	cout << endl;
	cout << " �ǵݹ�ǰ�����   ��";
	pTree->Preorder();
	cout << endl;

	cout << " �ݹ�ǰ�����    ��";
	pTree->PreorderRecursively(pRoot);
	cout << endl;

	cout << " �ǵݹ��������   ��";
	pTree->Inorder();
	cout << endl;

	cout << " �ݹ��������    ��";
	pTree->InorderRecursively(pRoot);
	cout << endl;

	cout << " �ǵݹ�������   ��";
	pTree->Postorder();
	cout << endl;

	cout << " �ݹ��������    ��";
	pTree->PostorderRecursively(pRoot);
	cout << endl;

	PBNode pMaxNode = pTree->GetMaxKey();
	PBNode pMinNode = pTree->GetMinKey();
	if (pMaxNode != NULL)
		cout << " �ö�������������Ԫ���ǣ�" << pMaxNode->data << endl;

	if (pMinNode != NULL)
		cout << " �ö������������СԪ���ǣ�" << pMinNode->data << endl;

	int DeleteKey = 15;
	PBNode pSearchNode = pTree->Search(DeleteKey);
	if (pSearchNode != NULL)
		cout << " ��Ҫ��ѯ��Ԫ���ǣ�" << DeleteKey << ", ʵ�ʲ�ѯ����Ԫ���ǣ�" << pSearchNode->data << endl;
	else
		cout << " û�в�ѯ��Ԫ��" << DeleteKey << endl;
	
	pTree->Delete(DeleteKey);
	cout << " ɾ��Ԫ��" << DeleteKey << "֮��ĵݹ�ǰ�������";
	pTree->PreorderRecursively(pRoot);
	cout << endl;

	DeleteKey = 1;
	pTree->Delete(DeleteKey);
	cout << " ɾ��Ԫ��" << DeleteKey << "֮��ĵݹ�ǰ�������";
	pTree->PreorderRecursively(pRoot);
	cout << endl;

	DeleteKey = 8;
	pTree->Delete(DeleteKey);
	cout << " ɾ��Ԫ��" << DeleteKey << "֮��ĵݹ�ǰ�������";
	pTree->PreorderRecursively(pRoot);
	cout << endl;

	DeleteKey = 26;
	pTree->Delete(DeleteKey);
	cout << " ɾ��Ԫ��" << DeleteKey << "֮��ĵݹ�ǰ�������";
	pTree->PreorderRecursively(pRoot);
	cout << endl;
	
	delete pTree;
	pTree = NULL;
	return 1;
}