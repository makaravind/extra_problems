#include<stdio.h>
#include <malloc.h>
#include<conio.h>
struct node {
	int num;
	struct node *next;
};
void display(struct node *p)
{
	struct node *q;
	q = p;
	while (q != NULL)
	{
		printf("%d \n", q->num);
		q = q->next;
		//count++;
	}
}
void append(struct node **q, int num)
{
	struct  node *temp, *r;

	if (*q == NULL)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->num = num;
		temp->next = NULL;
		*q = temp;

	}
	else
	{
		temp = *q;
		while (temp->next != NULL)
			temp = temp->next;
		r = (struct node *)malloc(sizeof(struct node));
		r->num = num;
		r->next = NULL;
		temp->next = r;


	}
}
void  Reversell(struct node **head_ref);
void main(){
	struct node *head1 = NULL;
	struct node *head2 = NULL;
	// change the code to insert last
	printf("enter the first LL");
	for (int i = 0; i < 3; i++){
		int d;
		scanf_s("%d", &d);
		append(&head1, d);
	}
	
	Reversell(&head1);
	display(head1);
	_getch();
}
void Reversell(struct node **head_ref)
{
	struct node* first;
	struct node* rest;

	if (*head_ref == NULL)
		return;
	
	first = *head_ref;
	rest = first->next;


	if (rest == NULL)
		return;

	Reversell(&rest);
	first->next->next = first;

	
	first->next = NULL;

	*head_ref = rest;
}
/*struct node* Reversell(struct node *l1){
	if (l1 == NULL) return NULL;
	if (l1->next == NULL)
	{
		return NULL;
	}
	else{
		struct node *second = l1->next;
		l1->next = NULL;
		struct node *reverse = Reversell(second);
		second->next = l1;
		return reverse;
	}

}*/

