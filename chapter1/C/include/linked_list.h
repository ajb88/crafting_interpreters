typedef struct node Node;
typedef struct list List;
struct node
{
    char *string;
    Node *next;
    Node *prev; 
};

struct list
{
    Node *head;
};
int list_search(List *l, const char *k);

void list_insert(List *l, const char *string); 

int list_delete(List *l, const char *string);
