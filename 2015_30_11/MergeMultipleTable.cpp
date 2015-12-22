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
int MultipleTableMerge(int, int, int);
struct node* Merge(struct node **l1, struct node **l2);
void main(){


	int n1, n2, k;

	printf("Enter n1 n2 k");
	scanf_s("%d%d%d", &n1, &n2, &k);
	if (n1 == n2) {
		printf("empty");
	}
	else{

		int result = MultipleTableMerge(n1, n2, k);
		printf("%d", result);
	}
	
	_getch();

}
int MultipleTableMerge(int n1, int n2, int k){
	struct node *head1 = NULL;
	struct node *head2 = NULL;

	int i = 1,x,y;
	while (1){
		x = n1*i;
		y = n2*i;
		if (x != y) {
			append(&head1, x);
			append(&head2, y);
			i++;
			if (i == (2*k)) break;
		}
	}

	struct node *head3 = Merge(&head1,&head2);
	struct node *tmp = head3;
	i = 1;
	while (i<k){
		tmp = tmp->link;
		i++;
	}
	return tmp->data;
}
struct node* Merge(struct node **l1, struct node **l2){
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
		else if (p1->data == p2->data)
		{
			p1 = p1->link;
			p2 = p2->link;
			if (p1 == NULL || p2 == NULL) break;
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

	return(headfinsh);
}