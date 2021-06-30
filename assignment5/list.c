/*********************************************************************
 * ** Program Filename:list.c
 * ** Author:XiYuan Huang
 * ** Date:11/30/2018
 * ** Description:This file contains the function definitions for
 * 	the linked list.
 * ** Input:It depends on the user.
 * ** Output:It depends on the user's option.
 * *********************************************************************/
#include "list.h"

#include <stdio.h>
#include <stdlib.h>

/*********************************************************************
 * ** Function:int length(struct node *)
 * ** Description:This function gets the length of the list
 * ** Parameters:struct node *head
 * ** Pre-Conditions:struct node *head(the head of the list) 
 * ** Post-Conditions:int count(the number of element of the list)
 * *********************************************************************/ 
int length(struct node *head)
{
	int count = 0;
	while(head != NULL){
		count++;
		head = head->next;
	}
	return count;
}
/*********************************************************************
 * ** Function:void print(struct node*, int)
 * ** Description:This function prints a certain number of elements 
 * 	from the list starting with the first node 
 * ** Parameters:struct node *head, int num
 * ** Pre-Conditions:struct node *head, int num(the number of element
 * 	the user want)
 * ** Post-Conditions:N/A
 * *********************************************************************/ 
void print(struct node *head, int num)
{
	int i = 0;
	if(length(head) >= num){
	for(i = 0; i < num; i++){
		 printf("%d\n",head->val);
		 head = head->next;
		}
	}
}
/*********************************************************************
 * ** Function:struct node *push(struct node*, int)
 * ** Description:This function puts a node at the front
 * ** Parameters:struct node* head, int num
 * ** Pre-Conditions:struct node* head, int num(the value of new node)
 * ** Post-Conditions:struct node* head
 * *********************************************************************/ 
struct node * push(struct node *head, int num)
{
	struct node* new_node = malloc(sizeof(struct node));
	new_node->next = head;
	head = new_node;
	new_node->val = num;
	return head;
}
/*********************************************************************
 * ** Function:struct node *append(struct node *, int)
 * ** Description:This function puts a node at the back
 * ** Parameters:struct node* head, int num
 * ** Pre-Conditions:struct node* head, int num(the value of new node)
 * ** Post-Conditions:struct node* head
 * *********************************************************************/ 
struct node * append(struct node *head, int num)
{
	struct node* new_cur = head;
	while(new_cur->next != NULL){
		new_cur = new_cur->next;
	}
	new_cur->next = malloc(sizeof(struct node));
	new_cur->next->val = num;
	new_cur->next->next = NULL;
	return head;
}
/*********************************************************************
 * ** Function:struct node * clear(struct node*)
 * ** Description:This function deletes the entire list
 * ** Parameters:struct node *head
 * ** Pre-Conditions:struct node *head
 * ** Post-Conditions:NULL
 * *********************************************************************/ 
struct node * clear(struct node *head) 
{
	struct node* new_cur = head->next;
	free(head);
	while(new_cur != NULL){
		head = new_cur;
		new_cur = new_cur->next;
		free(head);
	}
	return NULL;
}
/*********************************************************************
 * ** Function:struct node *remove_node(struct node *, int)
 * ** Description:This function deletes a particular node
 * ** Parameters:struct node *head, int position
 * ** Pre-Conditions:struct node *head, int position(the node which 
 * 	will be removed)
 * ** Post-Conditions:struct node *head
 * *********************************************************************/ 
struct node * remove_node(struct node *head, int position)
{
	struct node *new_cur, *temp;
	int i = 0;
	if(head == NULL){
		return head;
	}else{
		temp = head->next;
		new_cur = head;
		if(position == 0){
			free(new_cur);
			return temp;
		}else{
			for(i = 1; i < position; i++){
				new_cur = temp;
				temp = new_cur->next;
			}
			new_cur->next = temp->next;
			free(temp);
			return head;
		}
	}	
}
/*********************************************************************
 * ** Function:struct node *sort_ascending(struct node*)
 * ** Description:This function sorts the nodes in ascending order
 * ** Parameters:struct node *head
 * ** Pre-Conditions:struct node *head
 * ** Post-Conditions:struct node *head
 * *********************************************************************/ 
struct node * sort_ascending(struct node * head)
{
	struct node *cur, *temp, *new_cur;
	int i, j;
	for( i = 0; i < length(head); i++){
		cur = head;
		temp = cur->next;
		new_cur = NULL;
		while(temp != NULL){
			if(cur->val > temp->val){
				if(cur == head){
					head = temp;
				}else{
					new_cur->next = temp;
				}
				cur->next = temp->next;
				temp->next = cur;
				new_cur = temp;
				temp = cur->next;
			}else{
				new_cur = cur;
				cur = cur->next;
				temp = cur->next;}
		}
	}	
	return head; 
}
/*********************************************************************
 * ** Function:struct node *sort_descending(struct node *head)
 * ** Description:This function sorts the nodes in descending order
 * ** Parameters:struct node *head
 * ** Pre-Conditions:struct node *head
 * ** Post-Conditions:struct node *head
 * *********************************************************************/ 
struct node * sort_descending(struct node * head)
{
	struct node *cur, *temp, *new_cur;
	int i, j;
	for( i = 0; i < length(head); i++){
		cur = head;
		temp = cur->next;
		new_cur = NULL;
		while(temp != NULL){
			if(cur->val < temp->val){
				if(cur == head){
					head = temp;
				}else{
					new_cur->next = temp;
				}
				cur->next = temp->next;
				temp->next = cur;
				new_cur = temp;
				temp = cur->next;
			}else{
				new_cur = cur;
				cur = cur->next;
				temp = cur->next;}
		}
	}	
	return head; 
}
/*********************************************************************
 * ** Function:struct node *insert_middle(struct node*, int, int)
 * ** Description:This function inserts a node into a specific location
 * 	in the list
 * ** Parameters:struct node *head, int num, int position
 * ** Pre-Conditions:struct node *head, int num(the value of new node),
 * 	 int position
 * ** Post-Conditions:strutct node *head
 * *********************************************************************/ 
struct node * insert_middle(struct node * head, int num, int position)
{
	struct node *new_cur, *temp;
	struct node *cur = malloc(sizeof(struct node));
	int i = 0;
	new_cur = head;
	temp = head->next;
	cur->val = num;
	for(i = 1; i < position; i++){
		new_cur = temp;
		temp = new_cur->next;
	}
	new_cur->next = cur;;
	cur->next = temp;
	return head;
}
