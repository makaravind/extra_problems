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
void Merge(struct node **l1, struct node **l2);
void main(){
	struct node *head1 = NULL;
	struct node *head2 = NULL;

	int k, n1,n2;

	printf("enter no of elements you want to enter \n");
	//Insert in LL1
	scanf_s("%d", &n1);
	for (int i = 0; i<n1; i++){
		scanf_s("%d", &k);
		append(&head1, k);
	}
	//insert in LL2
	scanf_s("%d", &n2);
	for (int i = 0; i<n2; i++){
		scanf_s("%d", &k);
		append(&head2, k);
	}

	Merge(&head1, &head2);
	_getch();
}

void Merge(struct node **l1, struct node **l2){
	struct node *p1, *p2, *finish,*headfinsh;

	finish = NULL;
	p1 = *l1;
	p2 = *l2;
	int flag = 0;

	//Init pointing to lowest value 
	if (p1->data < p2->data){
		finish = p1;
		headfinsh = finish;
		p1 = p1->link;
	}
	else {
		finish = p2;
		headfinsh = finish;
		p2 = p2->link;
	}

	while (1){
		if (p1->data > p2->data){
			finish->link = p2;
			finish = finish->link;
			p2 = p2->link;
			if (p2 == NULL) break;
		}
		else{
			finish->link = p1;
			finish = finish->link;
			p1 = p1->link;
			if (p1 == NULL) break;
		}
	}

	if (p1 == NULL){
		finish->link = p2;
	}
	else finish->link = p1;

	display(headfinsh);
}