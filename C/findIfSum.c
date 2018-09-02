
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


	linkedList *ll = initList(9);

	enqueue(ll, 8);
	enqueue(ll, 7);
	enqueue(ll, 6);
	display(ll);
	

	return 0;
}

linkedList* initList(int data)
{

	linkedList* tmpll = malloc(sizeof(linkedList));
	tmpll->head = NULL;
	tmpll->head = NULL;

	node* tmpNode = malloc(sizeof(node));
	tmpNode->next = NULL;
	tmpNode->prev = NULL;
	tmpNode->val = data;

	tmpll->head = tmpNode;
	tmpll->tail = tmpNode;

	return tmpll;

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

	while (current != NULL)
	{
		printf("%d->",current->val);
		current = current->next;
	}
	printf("NULL\n");
}
