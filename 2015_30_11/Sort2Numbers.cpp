#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	int data;
	struct node *link;
};
void append(struct node **q, int num)
{
	struct  node *temp, *r;

	if (*q == NULL)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data = num;
		temp->link = NULL;
		*q = temp;

	}
	else
	{
		temp = *q;
		while (temp->link != NULL)
			temp = temp->link;
		r = (struct node *)malloc(sizeof(struct node));
		r->data = num;
		r->link = NULL;
		temp->link = r;


	}
}
void display(struct node *p)
{
	struct node *q;
	q = p;
	while (q != NULL)
	{
		printf("%d \n", q->data);
		q = q->link;
		//count++;
	}
}
void Reversell(struct node **head_ref)
{
	struct node* first;
	struct node* rest;

	if (*head_ref == NULL)
		return;

	first = *head_ref;
	rest = first->link;


	if (rest == NULL)
		return;

	Reversell(&rest);
	first->link->link = first;


	first->link = NULL;

	*head_ref = rest;
}
void Arrange2Numbers(struct node **p1);
void main(){
	struct node *head = NULL;
	

	int k, n1;

	printf("enter no of elements you want to enter \n");
	//Insert in LL1
	scanf_s("%d", &n1);
	for (int i = 0; i<n1; i++){
		scanf_s("%d", &k);
		append(&head, k);
	}

	Arrange2Numbers(&head);
	display(head);
	_getch();
}

void Arrange2Numbers(struct node **p1){

	struct node *ref = NULL;
	struct node *tmp1 = *p1;
	struct node *tmp2 = tmp1->link;

	int num1, num2;

	//Search from start
	while (1)
	{
		if (tmp1->data < tmp2->data){
			tmp1 = tmp1->link;
			tmp2 = tmp2->link;
			if (tmp1 == NULL || tmp2 == NULL) break;
			continue;
		}

		num1 = tmp1->data;
		ref = tmp1;
		break;
	}

	struct node *revhead = *p1;
	Reversell(&revhead);
	tmp1 = revhead;
	tmp2 = tmp1->link;
	//Searching from back
	while (1)
	{
		if (tmp1->data > tmp2->data){
			tmp1 = tmp1->link;
			tmp2 = tmp2->link;
			if (tmp1 == NULL || tmp2 == NULL) break;
			continue;
		}

		//Arranging in correct order
		num2 = tmp1->data;
		tmp1->data = num1;
		ref->data = num2;
		break;
	}
	//Reversing the LL again to point in correct order
	Reversell(&revhead);
	*p1 = revhead;
}