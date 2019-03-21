#include "btree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct treeNode {
	char * payload;
	int count;
	struct treeNode * left;
	struct treeNode * right;
};
node newNode(char * word){
	node n = (node) malloc (sizeof (struct treeNode));
	n->payload=strdup(word);
	n->count = 1;
	n->left= NULL;
	n->right = NULL;
	return n;
}
void addTree(node root,char * word){
	assert(root!=NULL);
	int ret = strcmp(word,root->payload);
	if(ret == 0) {
		root->count++;
		return ;
	}
  if(ret < 0) {
		if (root->left == NULL ){
			root->left = newNode(word);
			return;
		}
			addTree(root->left,word);

  }
	if (ret > 0) {
		if (root->right == NULL ){
			root->right=newNode(word);
			return;
		}
			addTree(root->right,word);


}
}
void printTree(node root){
	if (root == NULL){
			return ;
	}
		printTree(root->left);
		printf("%4d : %s\n",root->count,root->payload);
		printTree(root->right);
	}
void freeTree(node root){
	if (root == NULL){
			return ;
	}else{
		freeTree(root->left);
		freeTree(root->right);
		free(root->payload);
		free(root);

	}
}

/* Insert your code for the btree methods here */
