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
void print(LinkedList*);
void reversePrint(LinkedList*);

void reverse(LinkedList*);

int main()
{
	LinkedList *ll = initList();

	enqueue(ll, 'd');
	enqueue(ll, 'e');
	enqueue(ll, 'a');
	enqueue(ll, 'r');


	print(ll);

	reverse(ll);
	print(ll);
	

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
	
	if (list->tail == NULL)
	{
		list->head = tmpNode;
		list->tail = tmpNode;
	}
	else
	{
		list->tail->next = tmpNode;
		tmpNode->prev = list->tail;
		list->tail = tmpNode;
	}
	

}

void print(LinkedList* list)
{
	Node *current = list->head;

	while ( current->next != NULL )
	{
		printf("%c->", current->val);
		current = current->next;
	}

	printf("%c\n", current->val);

}

void reversePrint(LinkedList* list)
{
	Node *current = list->tail;
	while( current->prev != NULL)
	{
		printf("%c->", current->val);
		current = current->prev;
	}

	printf("%c\n", current->val);
}

void reverse(LinkedList* list)
{
	Node *current;

	//Flip tail&head pointers
	current = list->tail;

	while ( current->prev != NULL )
	{
		current->next = current->prev;
		current = current->next;
	}

	current->next = NULL;
	list->head = list->tail;
	list->tail = current;	
}
