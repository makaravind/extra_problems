#include<stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
void Insert(struct node **head, int data){

	struct node *current = *head;
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	
	newnode->num = data;
	while (current->next != *head)
	{
		current = current->next;
	}
	newnode->next = newnode;
	if (*head == NULL){
		*head = newnode;
	}
	else{
		newnode->next = *head;
		current->next = newnode;
	}
}
void main(){
	struct node *head1 = NULL;
	struct node *head2 = NULL;
	// change the code to insert last
	printf("enter the first LL");
	for (int i = 0; i < 5; i++){
		int d;
		scanf_s("%d", &d);
		Insert(&head1, d);
	}
	for (int i = 0; i < 5; i++) {
		head2 = head1;
		printf("%d", head2->num);
		head2 = head2->next;
	}
}