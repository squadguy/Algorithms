#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	char val;
	struct Node *next;
	struct Node *prev;

} Node;

Node* initNode(char);


int main()
{

	Node* node = initNode('C');

	printf("%c\n",node->val);

	return 0;
}


Node* initNode(char val)
{
	Node *node = malloc(sizeof(Node));
	node->next = NULL;
	node->prev = NULL;
	node->val = val;
	
	return node;
}
