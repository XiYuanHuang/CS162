#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct node *head = NULL;
	int i;
	head = malloc(sizeof(struct node));
	struct node* cur = head;
	head->val = 0;
	for(i=1;i<4;i++){
		cur->next = malloc(sizeof(struct node));//new node
		cur = cur->next;
		cur->val = i;
	}		
	cur->next = NULL;
	head = push(head, 4);
	head = append(head, 7);	
	int size = length(head);
	print(head, size);	
	printf("size of list %d\n", size);
	head = remove_node(head, 5);	
	size = length(head);
	head = insert_middle(head, 8, 3);
	head = sort_ascending(head);
	print(head,size);
	size = length(head);
	printf("size of list %d\n", size);
	head = clear(head);
			
return 0;
}
