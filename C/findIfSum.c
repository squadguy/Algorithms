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

int main() {


	linkedList *ll = initList(5);

	printf("%d\n", ll->head->val);

	enqueue(ll, 4);

	printf("%d\n", ll->head->val);
	printf("%d\n", ll->head->next->val);
	printf("%d\n", ll->head->next->prev->val);
	printf("%d\n", ll->tail->prev->val);
	printf("%d\n", ll->tail->val);

	

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
