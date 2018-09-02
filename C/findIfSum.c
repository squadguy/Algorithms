
/* Determines if a sorted linked list has two numbers that equal a particular sum */

#include<stdio.h>
#include<stdlib.h>

typedef struct linkedList
{
	struct node* head;
	struct node* tail;

} linkedList;

typedef struct node
{
	int val;
	struct node* next;
	struct node* prev;

} node;

linkedList* initList(int);
void enqueue(linkedList*, int);
void display(linkedList*);

int main() {


	linkedList *ll = initList(5);

	enqueue(ll, 4);
	enqueue(ll, 3);
	enqueue(ll, 2);


	display(ll);
	

	return 0;
}

linkedList* initList(int data)
{

	linkedList* ll = malloc(sizeof(linkedList));
	ll->head = NULL;
	ll->head = NULL;

	node* tmpNode = malloc(sizeof(node));
	tmpNode->next = NULL;
	tmpNode->prev = NULL;
	tmpNode->val = data;

	ll->head = tmpNode;
	ll->tail = tmpNode;

	return ll;

}

void enqueue(linkedList* ll, int data)
{
	node* tmpNode = malloc(sizeof(node));
	tmpNode->val = data;
	tmpNode->prev = NULL;
	tmpNode->next = ll->head;
	ll->head->prev = tmpNode;
	ll->head = tmpNode;
}

void display(linkedList* ll)
{
	node* current = ll->head;

	while (current->next != NULL)
	{
		printf("%d->",current->val);
		current = current->next;
	}
	printf("NULL\n");
}
