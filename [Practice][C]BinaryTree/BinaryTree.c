#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode{
	int data;
	struct treeNode* lc;
	struct treeNode* rc;
}Node;

// create a left-skew binary tree
Node* addNode(Node* tree, int input) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = input;
	newNode->lc = NULL;
	newNode->rc = NULL;

	if(!tree) tree = newNode;
	else if(tree->lc) {
		if(!tree->rc) tree->rc = addNode(tree->rc, input);
		else tree->lc = addNode(tree->lc, input);
	} else tree->lc = addNode(tree->lc, input);
	return tree;
}

// pre-order traversal : NLR
void preorder(Node* tree) {
	if(!tree) printf("The binary tree is empty.\n");
	else {
		printf("%-5d", tree->data);
		if(tree->lc) preorder(tree->lc);
		if(tree->rc) preorder(tree->rc);
	}
}

// in-order traversal : NLR
void inorder(Node* tree) {
	if(!tree) printf("The binary tree is empty.\n");
	else {
		if(tree->lc) preorder(tree->lc);
		printf("%-5d", tree->data);
		if(tree->rc) preorder(tree->rc);
	}
}

// post-order traversal : NLR
void postorder(Node* tree) {
	if(!tree) printf("The binary tree is empty.\n");
	else {
		if(tree->lc) preorder(tree->lc);
		if(tree->rc) preorder(tree->rc);
		printf("%-5d", tree->data);
	}
}

int main() {
	int inputs[12] = {10, 587, 311, 62, 9, 21, 33, 794, 55, 46, 274, 32};
	Node *tree = NULL;

	int i;
	int len = sizeof(inputs) / sizeof(int);

	for(i = 0; i < len ; i++) tree = addNode(tree, inputs[i]);

	printf("preorder traversal : ");
	preorder(tree);
	printf("\n");

	printf("inorder traversal : ");
	inorder(tree);
	printf("\n");

	printf("postorder traversal : ");
	postorder(tree);
	printf("\n");

}
