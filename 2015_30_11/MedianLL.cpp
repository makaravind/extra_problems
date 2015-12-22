/*Median of a SLL*/
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
void insertfirst(struct node **q, int num)
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

		r = (struct node *)malloc(sizeof(struct node));
		r->data = num;
		r->link = *q;
		*q = r;
	}
}
void Median2(struct node **p);
void main(){
struct node *head = NULL;
int k,n;

printf("enter no of elements you want to enter \n");
scanf_s("%d", &n);
for (int i = 0; i<n; i++){
	scanf_s("%d", &k);
	append(&head, k);
}
Median2(&head);
_getch();
}
void Median2(struct node **p){
	struct node *p1, *p2;
	p1 = p2 = *p;
	int i = 0;
	while (p1->link != NULL){
		if (i == 0){
			p1 = p1->link;
			i = 1;
		}
		else if (i == 1){
			p1 = p1->link;
			p2 = p2->link;
			i = 0;
		}
	}

	printf("%d", p2->data);

}