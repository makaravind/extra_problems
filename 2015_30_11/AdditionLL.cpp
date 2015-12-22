#include <stdio.h>
#include <malloc.h>
#include<conio.h>

struct node {
	int num;
	struct node *next;
};
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
void Sum(struct node*, struct node*);
void main(){
	struct node *head1 = NULL;
	struct node *head2 = NULL;
	int n1, n2;
	// change the code to insert last
	printf("enter number of elements for first LL");
	scanf_s("%d", &n1);
	for (int i = 0; i < n1; i++){
		int d;
		scanf_s("%d", &d);
		append(&head1, d);
	}
	printf("enter number of elements for second LL");
	scanf_s("%d", &n2);
	for (int i = 0; i < n2; i++){
		int d;
		scanf_s("%d", &d);
		append(&head2, d);
	}
	Sum(head1, head2);
	_getch();
}
void Sum(struct node *l1, struct node *l2){
	struct node *tmp1 = NULL;
	struct node *tmp2 = NULL;
	struct node *tmp3 = NULL;
	struct node *head3 = NULL;
	int carry = 0;
	int d=0;
	tmp1 = l1;
	tmp2 = l2;

	Reversell(&tmp1);
	Reversell(&tmp2);

	while (1)/*Revere the LL and then perform addition*/
	{
		int sum = tmp1->num + tmp2->num + carry;
		if (sum > 9){
			d = sum % 10;
			sum /= 10;
			carry = sum;
		}
		else {
			d = sum;
			carry = 0;
		}
		append(&head3, d);
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
		if (tmp1 == NULL || tmp2 == NULL) break;
	}
		// copy all of tmp1 into head3
		while (tmp1 != NULL)
		{
			append(&head3, tmp1->num);
			tmp1 = tmp1->next;
		}

		while (tmp2 != NULL)
		{
			append(&head3, tmp2->num);
			tmp2 = tmp2->next;
		}

	tmp3 = head3;
	Reversell(&tmp3);
	while (tmp3 != NULL)
	{
		printf("%d", tmp3->num);
		tmp3 = tmp3->next;
	}
}