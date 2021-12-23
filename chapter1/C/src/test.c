#include <stdio.h>
#include <assert.h>
#include "linked_list.h"
int main(int argc, const char** argv)
{
    List l;
    l.head = NULL;
    list_insert(&l, "Allen");
    list_insert(&l, "Mary");
    assert(list_search(&l, "Allen"));
    assert(list_search(&l, "Mary"));
    assert(!list_search(&l, "Joey"));
    list_delete(&l, "Allen");
    list_delete(&l, "Mary");
    assert(!list_search(&l, "Allen"));
    assert(!list_search(&l, "Mary"));    
    return 0; 
}
