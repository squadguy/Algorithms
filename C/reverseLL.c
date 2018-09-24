#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	char val;
	struct Node *next;
	struct Node *prev;

} Node;

typedef struct LinkedList
{
	Node *head;
	Node *tail;

} LinkedList;

Node* initNode(char);

LinkedList* initList()
{
	LinkedList* list = malloc(sizeof(list));
	list->head = NULL;
	list->tail = NULL;
	return list;	
}

int main()
{
	Node *node = initNode('D');

	LinkedList *ll = initList();


	ll->head=node;
	ll->tail=node;

	printf("%c\n", ll->head->val);
	printf("%c\n", ll->tail->val);


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

