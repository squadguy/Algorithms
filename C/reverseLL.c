#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	char val;
	struct Node *next;
	struct Node *prev;

} Node;

int main()
{

	Node *ll = malloc(sizeof(Node));
	ll->next = NULL;
	ll->prev = NULL;
	ll->val = 'd';

	printf("%c\n",ll->val);

	return 0;
}
