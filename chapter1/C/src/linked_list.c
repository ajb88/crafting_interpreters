#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_list.h"







Node *node_search(List *l, const char *k)
{
    Node *curr = l->head;
    while(curr != NULL && strcmp(curr->string, k))
    {
	curr = curr->next; 
    }
    return curr;     
}
int list_search(List *l, const char *k)
{
    Node *found = node_search(l, k);
    if(found)
    {
	return 1; 
    }
    return 0; 
}

void node_insert(List *l, Node *x)
{
    x->next = l->head;
    if(l->head != NULL)
    {
	l->head->prev = x; 
    }
    l->head = x;
    x->prev = NULL; 
}

void list_insert(List *l, const char *string)
{
    int size = strlen(string);
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->string = (char*)malloc(((size + 1) * sizeof(char)));
    strcpy(new_node->string, string); 
    node_insert(l, new_node);
}
void node_delete(List *l, Node *x)
{
    if(x->prev != NULL)
    {
	x->prev->next = x->next; 
    }
    else
    {
	l->head = x->next; 
    }
    if(x->next != NULL)
    {
	x->next->prev = x->prev; 
    }
    free(x->string); 
    free(x); 
}


int list_delete(List *l, const char *string)
{
    Node *found = node_search(l, string);
    if(found == NULL)
    {
	return 0; 
    }
    node_delete(l, found);
    return 1; 
}
