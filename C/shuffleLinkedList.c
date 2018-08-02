#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} node_t;

typedef struct linkedList
{
	struct node *head;
} linkedList;

void initialize (linkedList *ll, int value)
{
	ll->head=NULL;		
	ll->head=malloc(sizeof(node_t));

	ll->head->data=value;
	ll->head->next=NULL;

}

void insert_at_end (linkedList *ll, int value)
{
	node_t * tmp;
	node_t * current;
	tmp = malloc(sizeof(node_t));
	tmp->data=value;
	tmp->next=NULL;
	
	current = ll->head;

	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = tmp;
}

void insert_at_front(linkedList *ll, int value)
{
	node_t *tmp;
	tmp=malloc(sizeof(node_t));
	tmp->data=value;
	tmp->next=ll->head;
	ll->head=tmp;

}

void print(linkedList *ll)
{
	node_t * current;
	current = ll->head;

	while (current->next != NULL)
	{
		printf("%d->", current->data);
		current = current->next;
	}
		printf("%d\n", current->data);
	
}

node_t* splitAtHalf(linkedList *ll)
{
	size_t numElements = 0;
	node_t *first = ll->head;
	for(node_t *first = ll->head; first!=NULL; first = first->next)
	{
		numElements++;
	}
	printf("%ld\n", numElements);

	for(size_t i = 0; i < numElements / 2 - 1; i++)
	{
		first = first->next;
	}

	node_t *result = first->next;
	first->next = NULL;
	
	printf("%d\n", result->data);

	return result;

}

int main()
{
	linkedList * ll = NULL;
	ll = malloc(sizeof(linkedList));

	initialize(ll,0);
	insert_at_end(ll,1);
	insert_at_end(ll,2);
	insert_at_end(ll,3);
	print(ll);
//Test inserting at front
	insert_at_end(ll, 4);	
	print(ll);
	insert_at_end(ll, 5);	
	insert_at_end(ll,6);
	insert_at_end(ll,7);
	insert_at_end(ll,8);
	insert_at_end(ll,9);

	print(ll);
	splitAtHalf(ll);

	return 0;
}
