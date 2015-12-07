#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{	
	int var;
	node *link;
};
void Insert(int x, node **head){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));

	if (*head == NULL){
		newNode->link = NULL;
		newNode->var = x;
		*head = newNode;
	}
	else{
		newNode->link = *head;
		newNode->var = x;
		*head = newNode;
	}
		

}
void Modify (node **head){

	node *p = *head;
	node *nextP = p->link;

	while (nextP != NULL)
	{
		p->link = nextP->link;
		if (p->link == NULL) break;
		p = p->link;
		nextP = p->link;
	}

	node *first = *head;
	while (first->link != NULL){
		printf("%d", first->var);
		first = first->link;
	}

}
void main(){
	node *head = NULL;
	node *p = head;

	/*Insert(1, &head);
	Insert(2, &head);
	Insert(3, &head);
	Insert(4, &head);
	Insert(5, &head);
	Insert(6, &head);
	Insert(7, &head);
	Insert(8, &head);
	Insert(9, &head);
	Insert(10, &head);*/
	int size;
	scanf("%d",&size);
	for(int i=0;i<size;i++)
	{
		int d;
		printf("enter elements");
		scanf("%d",&d);
		Insert(d,&head);
		}

	

	//printf("%d", head->var);

	Modify(&head);
	
	_getch();
}