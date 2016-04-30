#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int Java;
	int id;
	struct node* link;

};
int Convert(char *cp){

	int val = 0;
	for (int i = 0; cp[i] != '\0'; i++)
	{
		val *= 10;
		val += cp[i] - '0';

	}
	return val;
}
void append(struct node **q, int java,int id)
{
	struct  node *temp=NULL , *r;

	if (*q == NULL)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->Java = java;
		temp->id = id;
		temp->link = NULL;
		*q = temp;

	}
	else
	{
		temp = *q;
		while (temp->link != NULL)
			temp = temp->link;
		r = (struct node *)malloc(sizeof(struct node));
		temp->Java = java;
		temp->id = id;
		r->link = NULL;
		temp->link = r;


	}
	/*struct  node *temp=NULL, *r;

	if (*q == NULL)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->Java = java;
		temp->id = id;
		temp->link = NULL;
		*q = temp;

	}
	else
	{

		r = (struct node *)malloc(sizeof(struct node));
		r->Java = java;
		r->id = id;
		r->link = *q;
		*q = r;
	}*/
}
void display(struct node *p)
{
	struct node *q;
	q = p;
	while (q != NULL)
	{
		printf("marks - >  %d  id --> %d \n", q->Java,q->id);
		q = q->link;
		//count++;
	}
}
struct node*  Merge(struct node **l1, struct node **l2);
void GoToInsert(struct node**);
void GoToDelete(struct node**);
void Terminate(struct node**);
void Init(struct node**, char *filename);
void GoToMerge();
void main(){
	struct node *head = NULL;
	int response;
	char filename[] = "F:\\db2.txt";
	Init(&head,filename);
	display(head);
	printf("LL Program\n");
	printf("Menu\n");
	printf("1.Insert a record\n");
	printf("2. Delete a record\n");
	printf("3. Merge\n");
	printf("4. Merge Java and Py\n");
	printf("5. Exit\n");
	scanf_s("%d", &response);
	switch (response)
	{
	case 1 :
		GoToInsert(&head);
		break;
	case 2 :
		GoToDelete(&head);
		break;
	case 3:
		GoToMerge();
	case 4:
		GoToMerge();
	case 5 :
		//printf("Program has terminated");
		Terminate(&head);
	default:
		break;
	}


}
void GoToMerge(){
	printf("Select the mergeable files :");
	printf("1:db1\n2:db2\n");
	int responce=0;

	struct node *head1=NULL, *head2=NULL,*head3=NULL;
	scanf_s("%d", &responce);
	if (responce == 1){
		Init(&head1, "F:\\db.txt");
		Init(&head2, "F:\\db2.txt");
		head3 = Merge(&head1, &head2);
	}

	//Terminate(&head3);
	FILE *fp;
	//fopen_s(&fp, "db.txt", "a");
	fp = fopen("F:\\db3.txt", "w");
	struct node *q;
	q = head3;

	while (q != NULL)
	{
		//printf("marks - >  %d  id --> %d \n", q->Java,q->id);
		fprintf(fp, "%d", q->id);
		fprintf(fp, "%c", '\n');
		fprintf(fp, "%d", q->Java);
		fprintf(fp, "%c", '\n');
		q = q->link;

	}

	fclose(fp);
	
}
void Init(struct node **head,char *filename){

	struct node * tmp;
	tmp = *head;

	FILE *fp;
	fp = fopen(filename, "r");

	int marks, id;
	char buff[100];
	fread(buff, sizeof(buff), 1, fp);
	//printf("in the file %s", buff);
	int t = 0;
	int flag = 0;
	append(head, 0, 0);
	for (int i = 0; buff[i] != '-'; i++){
		char temp[30];

		temp[t++] = buff[i];
		if (buff[i] == '\n'){
			temp[t - 1] = '\0';
			t = 0;
			//printf("%d", Convert(temp));
			if (flag == 0){
				id = Convert(temp);
				flag++;
			}
			else if (flag == 1){
				marks = Convert(temp);
				append(head, marks, id);
				flag = 0;
			}

				
			//append(head);
		}
	}
	fclose(fp);
}
void GoToDelete(struct node **head){

	struct node * tmp;
	struct node * tmp2 = NULL;
	tmp = *head;
	int resposnce;

	while (1)
	{
		printf("enter the id you want to delete !");
		scanf_s("%d", &resposnce);

		while (tmp->id != resposnce)
		{
			tmp2 = tmp;
			tmp = tmp->link;
		}
		tmp2->link = tmp->link;
		printf("\ndo you want to delete more ? 1 or 0");
		scanf_s("%d", &resposnce);
		if (resposnce == 0)break;
	}
	
	Terminate(head);

}
void Terminate(struct node **head){
	//Sort LL

	//Insert into files
	FILE *fp;
	//fopen_s(&fp, "db.txt", "a");
	fp = fopen("F:\\db2.txt", "w");
	struct node *q;
	q = *head;

	while (q != NULL)
	{
	//printf("marks - >  %d  id --> %d \n", q->Java,q->id);
		fprintf(fp, "%d", q->id);
		fprintf(fp, "%c", '\n');
		fprintf(fp,"%d" ,q->Java);
		fprintf(fp, "%c",'\n');
		q = q->link;
	
	}
	fprintf(fp, "%c", '\0');
	fclose(fp);
	printf("Program has terminated");
	exit(1);
}
void GoToInsert(struct node **head){

	int id, marks;
	int response;

	do
	{
		printf("Enter id = ");
		scanf_s("%d", &id);
		printf("Enter marks = ");
		scanf_s("%d", &marks);

		append(head, marks, id);
		printf("Do you want to insert another record or delete? 1 or 2 or 3");

		scanf("%d", &response);
		/*if (response[0] == 'n')
			Terminate(head);
			//break;*/
		switch (response)
		{
		case 1:
			continue;
		case 2:
			GoToDelete(head);
		case 3:
			Terminate(head);

		default:
			printf("worng option..Program terminated!");
			
			break;
		}
			

	} while (1);
	
}

struct node* Merge(struct node **l1, struct node **l2){
	struct node *p1, *p2, *finish, *headfinsh;

	finish = NULL;
	p1 = *l1;
	p2 = *l2;
	int flag = 0;

	//Init pointing to lowest value 
	if (p1->id < p2->id){
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
		if (p1->id > p2->id){
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

	//display(headfinsh);
	return headfinsh;
}

