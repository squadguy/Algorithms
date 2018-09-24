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
LinkedList* initList();
void enqueue(LinkedList*, char);


int main()
{
	//Node *node = initNode('D');

	LinkedList *ll = initList();

/*
	ll->head=node;
	ll->tail=node;
*/

	enqueue(ll, 'f');
	printf("%c\n", ll->head->val);
	printf("%c\n", ll->tail->val);

	enqueue(ll, 'o');
	printf("%c\n", ll->head->val);
	printf("%c\n", ll->tail->val);

	enqueue(ll, 'c');
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

LinkedList* initList()
{
	LinkedList* list = malloc(sizeof(list));
	list->tail = NULL;
	list->head = list->tail;

	return list;	
}

void enqueue(LinkedList* list, char val)
{
	Node* tmpNode = initNode(val);
	
	if (list->head == NULL)
	{
		list->head = tmpNode;
		list->tail = tmpNode;
	}
	else
	{
		list->head->prev = tmpNode;
		tmpNode->next = list->head;
		list->head = tmpNode;
	}
	

}


