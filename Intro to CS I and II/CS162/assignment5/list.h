struct node {
 int val;
 struct node *next;
};

int length(struct node *);
void print(struct node *);
void swap(struct node *a, struct node *b);
struct node* push(struct node **, int); //add to front of list
struct node* append(struct node **, int); //add to rear of list
struct node* clear(struct node **);
struct node* sort_ascending(struct node *);
struct node* sort_descending(struct node *);
struct node* insert_middle(struct node **, int, int);
struct node* removeNode(struct node *, int);
