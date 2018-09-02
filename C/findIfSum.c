
/* Determines if a sorted linked list has two numbers that equal a particular sum */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
linkedList* buildList(int);
void enqueue(linkedList*, int);
void display(linkedList*);
bool hasAddUp(linkedList*, int);



int main() {

	linkedList* ll = buildList(5);

	printf("%s\n", hasAddUp(ll, 10) ? "true" : "false");	

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

linkedList* buildList(int upTo)
{
	linkedList* tmpll = malloc(sizeof(linkedList));
	tmpll->head = NULL;
	tmpll->tail = NULL;
	
	for(int i = upTo; i > 0; i--)
	{
		enqueue(tmpll, i);			
	}

	return tmpll;
}

void enqueue(linkedList* ll, int data)
{
	node* tmpNode = malloc(sizeof(node));
	tmpNode->val = data;
	tmpNode->prev = NULL;
	if(ll->tail == NULL)
	{
		ll->head = ll->tail = tmpNode;
	}
	else
	{
		tmpNode->next = ll->head;
		ll->head->prev = tmpNode;
		ll->head = tmpNode;
	}
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

bool hasAddUp(linkedList* ll, int sumNum)
{
	node* headWindow = ll->head;
	node* tailWindow = ll->tail;

	while (headWindow != tailWindow)
	{
		if(headWindow->val + tailWindow->val == sumNum)
		{
			return true;	
		}
		else if( headWindow->val + tailWindow->val > sumNum)
		{
			tailWindow = tailWindow->prev;
		}
		else{
			headWindow = headWindow->next;
		}

	}
	return false;
}
