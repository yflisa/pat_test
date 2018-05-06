#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
	int value, height;
	Node* lchild;
	Node* rchild;
}*root;


Node* newNode(int v)
{
	Node* node = new Node;
	node->value = v;
	node->height = 1;
	node->lchild = node->rchild = NULL;
	return node;
}

int getHeight(Node* root)
{
	if(root == NULL)
		return 0;
	else
		return root->height;
}

void updateHeight(Node* root)
{
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBalanceFactor(Node* root)
{
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void R(Node* &root)
{
	Node* tmp = root->lchild;
	root->lchild = tmp->rchild;
	tmp->rchild = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}

void L(Node* &root)
{
	Node* tmp = root->rchild;
	root->rchild = tmp->lchild;
	tmp->lchild = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}

void insert(Node* &root, int v)
{
	if(root == NULL)
	{
		root = newNode(v);
		return;
	}
	int nRet;
	if(v < root->value)
	{

		insert(root->lchild, v);
		updateHeight(root);
		if(nRet = getBalanceFactor(root) == 2)
		{
			if(nRet = getBalanceFactor(root->lchild) == 1)
			{
				R(root);
			}
			else if(getBalanceFactor(root->lchild) == -1)
			{
				L(root->lchild);
				R(root);
			}
		}
	}
	else
	{
		insert(root->rchild, v);
		updateHeight(root);
		if(nRet = getBalanceFactor(root) == -2)
		{
			if(nRet = getBalanceFactor(root->rchild) == -1)
			{
				L(root);
			}
			else if(nRet = getBalanceFactor(root->rchild) == 1)
			{
				R(root->rchild);
				L(root);
			}
		}
	}
}
int main()
{
	//FILE* fin, fout;
	//fin = fopen("data.in", "r");
	int n, v;
	//fscanf(fin, "%d", &n);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		//fscanf(fin, "%d", &v);
		scanf("%d", &v);
		insert(root, v);
	}
	printf("%d\n", root->value);
	//fclose(fin);
	return 0;
}