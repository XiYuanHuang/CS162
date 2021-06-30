
struct node {
	int val;
	struct node *next;
};

int length(struct node*);//get the length of the list
void print(struct node*, int); 
struct node * push(struct node *, int);
struct node * append(struct node *, int);
struct node * clear(struct node*);
struct node * remove_node(struct node *, int);
struct node * sort_ascending(struct node*);
struct node * sort_descending(struct node *);
struct node * insert_middle(struct node *, int val, int idx);	
