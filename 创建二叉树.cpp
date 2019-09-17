#include<iostream>
#include<cstdio>

using namespace  std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}treeNode;

//插入成功返回1,插入失败返回0 
treeNode *insert(treeNode *tree,int num){
	treeNode *p;
	p = new treeNode;
	p->data = num;
	p->left = NULL;
	p->right = NULL;
	//如果这是棵空树 
	if(!tree){
		return ;
	}
	if(num>tree->data) insert(tree->right,num);
	else if(num<tree->data)insert(tree->left,num);
	else return NULL;
}

void putTree(treeNode *tree){
	if(!tree)return;
	putTree(tree->left);
	putTree(tree->right);
	printf("%d",tree->data);
}
int main(){
	treeNode *tree = NULL;
	int n;
	pair<int,treeNode> ret;
	int num;
	int flag;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> num;
		ret = insert(tree,num);
		if(!ret.first){printf("insert %d error!\n",num);}
		else 
	}
	putTree(tree);	
}
