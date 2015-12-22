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
int Slipt(struct node **l, struct node **l1);
void Merge(struct node **l1, struct node **l2);
void Reversell(struct node **head_ref);
void main(){
	struct node *head = NULL;
	struct node *head2 = NULL;
	int k, n;

	printf("enter no of elements you want to enter \n");
	scanf_s("%d", &n);
	for (int i = 0; i<n; i++){
		scanf_s("%d", &k);
		append(&head, k);
	}
	int x = Slipt(&head, &head2); 
	if (x != 1){
		Reversell(&head2);
		Merge(&head, &head2);
	}
	else printf("not in required format");
	_getch();
}
void Merge(struct node **l1, struct node **l2){
	struct node *p1, *p2, *finish, *headfinsh;

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
int Slipt(struct node **l, struct node **l1){
	struct node *t1, *t2, *t3;
	//Init
	t1 = *l;
	t2 = t1->link;
	t3 = NULL;

	while (1)
	{
		if (t1->data < t2->data) {
			t3 = t1;
			t1 = t1->link;
			t2 = t2->link;
			if (t2 == NULL){
				return 1;
			}
		}
		else{
			t3->link = NULL;
			*l1 = t1;
			break;
		}
	}

}