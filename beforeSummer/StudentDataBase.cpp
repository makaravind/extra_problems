#define _CRT_SECURE_NO_WARNINGS
#define SUBJECT_LENGTH 20
#define MAX_ENTRIES 50
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>
#include<string.h>
struct node{
	char name[50];
	int id;
	int *marks;
	node* left;
	node* right;
};
struct MarksNode{
	char name[50];
	int id;
	int total;
	MarksNode *left;
	MarksNode *right;
};
//  function declaration
void MenuSelect(struct node*, char subjects[50][50], int no_subjects, int *ID);
void MenuDisplay();
struct node* init(char[20], int *no_subjects, char subjects[][50], struct node *head, int *ID); // inserts the entries into a tree structure
void Split(char *dirty, char clean[][50],char dirt);
void SplitInt(char *dirty, int *clean, char dirt);
struct node* Insert(struct node* r, char *name, int *marks, int id);
struct MarksNode* InsertTotal(struct MarksNode* r, char *name, int marks, int id);
struct MarksNode* LeaderBoard_TotalMarksEntries(struct MarksNode *root1, struct node* root2,char subjects[50][50], int no_subjects);
struct node* DeleteById(struct node* root, int id,char *name);
struct node * minValueNode(struct node* node);
int isValidName(char *ip_name);
int isValidMarks(char *marks);
int isValidMarksInt(int marks);
char* lowerCaseWord(char* a);
int Sum(int *marks,int no_subjects);
float Average(int *marks, int no_subjects);
char Grade(int total,int max);
int FindSubjectIndex(char all_subjects[50][50],int no_subjects,char *subject);
char* SelectSubject(char all_subjects[50][50], int no_subjects);
int SelectSubjectId(char all_subjects[50][50], int no_subjects);
int SelectByNameId(struct node *root, char *sName);
void SelectByIdName(struct node *root, int id,char *del_name);
void SearchByName(struct node *root, char *sName, int *id_array, int *id_ptr);
void Feature_StudentPortalMenu(struct node* root, char subjects[50][50], int no_subjects);
void Feature_DisplayDb(struct node* root, char *subjects, int no_subjects);
void Feature_DisplayTotalDb(struct MarksNode* root2, char subjects[50][50], int no_subjects,int K);
void Feature_DisplayTopper(struct MarksNode* root2, char subjects[50][50], int no_subjects);
void Feature_DisplayPromoted(struct MarksNode* root2, char subjects[50][50], int no_subjects);
void Feature_DisplayFailed(struct MarksNode* root2, char subjects[50][50], int no_subjects);
void Feature_DisplaySubject(struct node* root, char subject[50][50], int no_subjects, char *xSubject);
void Feature_DisplayStudentSubject(struct node* root, char subject[50][50], int no_subjects,int id,int isubject);
void Feature_DiplayStudentMarks(struct node* root, char subject[50][50], int no_subjects, int id);
void Feature_DisplayMaximumMarks(struct node* root, char subject[50][50], int no_subjects, int id);
void Feature_DisplayAverage(struct node* root, char subject[50][50], int no_subjects, int id);
void Feature_DisplayIsPassOrFail(struct node* root, char subject[50][50], int no_subjects, int id);
void Feature_NewEntry(struct node* root, char subject[50][50], int no_subjects, int *ID);
void Feature_EditEntry(struct node* root, char subjects[50][50], int no_subjects, int *ID);
void Feature_EditEntry_Edit(struct node* root, char subjects[50][50], int no_subjects, int *ID,
	int newId, int subjectId, int newMarks);
void Feature_DeleteEntry(struct node* root, char subjects[50][50], int no_subjects, int *ID);
void Feature_LeaderBoard(struct node* root, char subjects[50][50], int no_subjects, int *ID);
void Feature_LeaderBoard_Total(struct node* root, char subjects[50][50], int no_subjects, int *ID);
void Feature_LeaderBoard_GreaterThan(struct node* root, char subjects[50][50], int no_subjects, int *ID);
void Feature_LeaderBoard_Topper(struct node* root, char subjects[50][50], int no_subjects, int *ID);
void Feature_LeaderBoard_Promoted(struct node* root, char subjects[50][50], int no_subjects, int *ID);
void Feature_LeaderBoard_Failed(struct node* root, char subjects[50][50], int no_subjects, int *ID);
// function definitions
void Feature_LeaderBoard_Failed(struct node* root, char subjects[50][50], int no_subjects, int *ID){

	struct MarksNode *root2 = NULL;
	root2 = LeaderBoard_TotalMarksEntries(root2, root, subjects, no_subjects);
	printf("Failed students\n");
	Feature_DisplayFailed(root2, subjects, no_subjects);
}
void Feature_LeaderBoard_Promoted(struct node* root, char subjects[50][50], int no_subjects, int *ID){

	struct MarksNode *root2 = NULL;
	root2 = LeaderBoard_TotalMarksEntries(root2, root, subjects, no_subjects);
	printf("Promoted students\n");
	Feature_DisplayPromoted(root2, subjects, no_subjects);
}
void Feature_LeaderBoard_Topper(struct node* root, char subjects[50][50], int no_subjects, int *ID){

	struct MarksNode *root2 = NULL;
	root2 = LeaderBoard_TotalMarksEntries(root2, root, subjects, no_subjects);
	Feature_DisplayTopper(root2, subjects, no_subjects);
}
void Feature_LeaderBoard_GreaterThan(struct node* root, char subjects[50][50], int no_subjects, int *ID){
	struct MarksNode *root2 = NULL;
	int K = -1;
	root2 = LeaderBoard_TotalMarksEntries(root2, root, subjects, no_subjects);
	printf("enter marks greater than: (max is %d)", 100 * no_subjects);
	scanf("%d", &K);
	Feature_DisplayTotalDb(root2, subjects, no_subjects, K);
}
void Feature_LeaderBoard_Total(struct node* root, char subjects[50][50], int no_subjects, int *ID){

	struct MarksNode *root2 = NULL;
	root2 = LeaderBoard_TotalMarksEntries(root2, root, subjects, no_subjects);
	Feature_DisplayTotalDb(root2, subjects, no_subjects,-1);
}
void Feature_LeaderBoard(struct node* root, char subjects[50][50], int no_subjects, int *ID){

	printf("You are in leaderboard portal! \n");
	printf("1. All entries total wise\n");
	printf("2. Entries greater than K, enter K\n");
	printf("3. Topper in a subject\n");
	printf("4. Promoted candidates\n");
	printf("5. Failed canditates\n");
	printf("100. Main menu\n");

	int leader_option = -1;
	int leader_again = 1;

	while (leader_again)
	{
		printf("choose an option:");
		scanf("%d", &leader_option);
		switch (leader_option)
		{
		case 1:
			Feature_LeaderBoard_Total(root, subjects, no_subjects, ID);
			break;
		case 2:
			Feature_LeaderBoard_GreaterThan(root, subjects, no_subjects, ID);
			break;
		case 3:
			Feature_LeaderBoard_Topper(root, subjects, no_subjects, ID);
			break;
		case 4:
			Feature_LeaderBoard_Promoted(root, subjects, no_subjects, ID);
			break;
		case 5:
			Feature_LeaderBoard_Failed(root, subjects, no_subjects, ID);
			break;
		case 100:
			MenuDisplay();
			MenuSelect(root, subjects, no_subjects, ID);
			break;
		default:
			printf("wrong option- choose again\n");
			Feature_LeaderBoard(root, subjects, no_subjects, ID);
			break;
		}
		printf("LeaderBoard agian? Press 1 else 0");
		scanf("%d", &leader_again);
	}
	
}
void Feature_DeleteEntry(struct node* root, char subjects[50][50], int no_subjects, int *ID){

	printf("you can delete an entry now:\n");
	printf("1. Delete by name\n");
	printf("2. Delete by Id\n");
	printf("press 100 for main menu\n");
	int delete_option = -1;
	char del_name[20];
	int del_id = -1;
	int iptr = 0;
	int del_again = 1;
	
	while (del_again)
	{
		printf("\ndeleting option?");
		scanf("%d", &delete_option);
		switch (delete_option)
		{
		case 1:
			printf("enter the name (case insensitive) : ");
			scanf("%s", &del_name);
			// display all entries with that name
			int hit_id[MAX_ENTRIES];
			SearchByName(root, del_name, hit_id, &iptr);
			for (int i = 0; i < iptr; i++) printf("%d. %s\n", hit_id[i], del_name);
			printf("Select an Id:");
			scanf("%d", &del_id);
			printf("Deleting %s record Id %d..\n", del_name, del_id);
			root = DeleteById(root, del_id, del_name);
			break;
		case 2:
			printf("Enter an Id (total entries %d)", *ID);
			// find the name with that ID
			scanf("%d", &del_id);
			SelectByIdName(root, del_id, del_name);
			printf("deleting %s record Id %d", del_name, del_id);
			root = DeleteById(root, del_id, del_name);
			break;
		case 100:
			MenuDisplay();
			MenuSelect(root, subjects, no_subjects, ID);
			break;
		default:
			printf("wrong option-choose again\n");
			Feature_DeleteEntry(root, subjects, no_subjects, ID);
		}

		printf("\nDelete again? press 1 else 0");
		scanf("%d", &del_again);
	}
	
}
void Feature_EditEntry_Edit(struct node* root, char subjects[50][50], int no_subjects, int *ID,
	int newId, int subjectId, int newMarks){

	if (root != NULL){
		if (root->id == newId){
			printf("updating %s's %s marks...\n", root->name,subjects[subjectId]);
			root->marks[subjectId] = newMarks;
			return;
		}
		Feature_EditEntry_Edit(root->left, subjects, no_subjects, ID, newId, subjectId,newMarks);
		Feature_EditEntry_Edit(root->right, subjects, no_subjects, ID, newId, subjectId, newMarks);
	}
}
void Feature_EditEntry(struct node* root, char subjects[50][50], int no_subjects, int *ID){
	printf("you can now edit an entry.\n");
	printf("search name : press 1\n");
	printf("Got ID !Lets edit : press 2\n");
	printf("To go back : press 100\n");
	int edit_option = -1;
	char edit_Name[20];
	int id;
	scanf("%d", &edit_option);
	switch (edit_option)
	{
	case 1:
		printf("Enter name :\n");
		scanf("%s", &edit_Name);
		id = SelectByNameId(root, edit_Name);
		break;
	case 2:
		printf("Enter ID:\n");
		scanf("%d", &id);
		break;
	case 100:
		MenuDisplay();
		MenuSelect(root,subjects,no_subjects,ID);
	default:
		printf("wrong option - choose again!");
		Feature_EditEntry(root, subjects, no_subjects, ID);
	}
	// final "id" in id
	int subjectId = SelectSubjectId(subjects, no_subjects);
	int newMarks;
	do{
		printf("Enter new marks of %s", subjects[subjectId]);
		scanf("%d", &newMarks);
	} while (!isValidMarksInt(newMarks)); // check this!
	
	// serach the id -> change the subject index to new one
	Feature_EditEntry_Edit(root, subjects, no_subjects, ID, id, subjectId,newMarks);

	// displaying menu
	MenuDisplay();
	MenuSelect(root, subjects, no_subjects, ID);
}
void Feature_NewEntry(struct node* root, char subject[50][50], int no_subjects, int *ID){
	printf("you can now make a new entry.\n");
	char newName[20];
	int *marks;
	int curr_marks;
	scanf("%s", &newName);
	while (!isValidName(newName)){
		printf("enter valid name(no punctuations) : ");
		scanf("%s", &newName);
	}
	marks = (int*)malloc(sizeof(int)*no_subjects);
	for (int i = 0; i < no_subjects; i++){
		printf("enter marks %s , to skip enter -1 : ", subject[i]);
		scanf_s("%d", &curr_marks);
		if (!isValidMarksInt(curr_marks)){ 
			printf("Invalid marks!");
			i--; 
			continue;
		}
		if (curr_marks >= 0) marks[i] = curr_marks;
		else marks[i] = -1;
	}
	printf("assigned ID %d...updating...", *ID);
	root = Insert(root,newName,marks,(*ID)++);
	printf("Updated!\n");
	MenuDisplay();
	MenuSelect(root, subject, no_subjects, ID);
}
void Feature_StudentPortalMenu(struct node* root, char subjects[50][50], int no_subjects){
	printf("Welcome to student portal\n");
	printf("1. student's subject marks\n");
	printf("2. student's all marks\n");
	printf("3. student maximum marks\n");
	printf("4. student average marks\n");
	printf("5. student is promoted or not?\n");
	int student_option;
	int id;
	int id_subject;
	int choose_again = 1;
	
	while (choose_again)
	{
		printf("choose an option:");
		scanf_s("%d", &student_option);
		switch (student_option)
		{
		case 1:
			printf("enter the id of the student:");
			scanf_s("%d", &id);
			id_subject = SelectSubjectId(subjects, no_subjects);
			Feature_DisplayStudentSubject(root, subjects, no_subjects, id, id_subject);
			break;
		case 2:
			printf("enter the id of the student:");
			scanf_s("%d", &id);
			Feature_DiplayStudentMarks(root, subjects, no_subjects, id);
			break;
		case 3:
			printf("enter the id of the student:");
			scanf_s("%d", &id);
			Feature_DisplayMaximumMarks(root, subjects, no_subjects, id);
			break;
		case 4:
			printf("enter the id of the student:");
			scanf_s("%d", &id);
			Feature_DisplayAverage(root, subjects, no_subjects, id);
			break;
		case 5:
			printf("enter the id of the student:");
			scanf_s("%d", &id);
			Feature_DisplayIsPassOrFail(root, subjects, no_subjects, id);
			break;
		case 100:
			MenuDisplay();
			break;
		default:
			printf("wrong option-select agian...");
			Feature_StudentPortalMenu(root, subjects, no_subjects);
		}

		printf("\nStudent info again? press 1 else 0");
		scanf("%d", &choose_again);
	}
	
}
void Feature_DisplayIsPassOrFail(struct node* root, char subject[50][50], int no_subjects, int id){
	if (root != NULL){
		if (root->id == id){
			printf("Grade of %s :", root->name);
			printf("%c", Grade(Sum(root->marks, no_subjects), no_subjects * 100));
		}
		Feature_DisplayAverage(root->left, subject, no_subjects, id);
		Feature_DisplayAverage(root->right, subject, no_subjects, id);
	}
}
void Feature_DisplayAverage(struct node* root, char subject[50][50], int no_subjects, int id){
	if (root != NULL){
		if (root->id == id){
			printf("Marks of %s :", root->name);
			printf("%0.3f", Average(root->marks,no_subjects));
		}
		Feature_DisplayAverage(root->left, subject, no_subjects, id);
		Feature_DisplayAverage(root->right, subject, no_subjects, id);
	}
}
void Feature_DisplayMaximumMarks(struct node* root, char subject[50][50], int no_subjects, int id){
	if (root != NULL){
		if (root->id == id){
			printf("Marks of %s :", root->name);
			printf("%d", Sum(root->marks,no_subjects));
		}
		Feature_DiplayStudentMarks(root->left, subject, no_subjects, id);
		Feature_DiplayStudentMarks(root->right, subject, no_subjects, id);
	}
}
void Feature_DiplayStudentMarks(struct node* root, char subject[50][50], int no_subjects, int id){
	if (root != NULL){
		if (root->id == id){
			printf("Marks of %s :", root->name);
			for (int i = 0; i < no_subjects; i++) printf("%s - %d\n", subject[i], root->marks[i]);
		}
		Feature_DiplayStudentMarks(root->left, subject, no_subjects, id);
		Feature_DiplayStudentMarks(root->right, subject, no_subjects, id);
	}
}
void Feature_DisplayStudentSubject(struct node* root, char subject[50][50], int no_subjects, int id,int isubject){
	if (root != NULL){
		if (root->id == id) printf("Marks of %s in %s is %d",root->name,subject[isubject],root->marks[isubject]);

		Feature_DisplayStudentSubject(root->left, subject,no_subjects,id,isubject);
		Feature_DisplayStudentSubject(root->right, subject, no_subjects, id, isubject);
	}
}
void Feature_DisplaySubject(struct node* root, char subjects[50][50], int no_subjects, char *xSubject){
	if (root){
		int index = FindSubjectIndex(subjects,no_subjects,xSubject);
		printf("%d. %s -> ", root->id, root->name);
		printf("%d\n",root->marks[index]);
		printf("\n");
		Feature_DisplaySubject(root->left, subjects, no_subjects, xSubject);
		Feature_DisplaySubject(root->right, subjects, no_subjects, xSubject);
	}
}
void Feature_DisplayFailed(struct MarksNode* root2, char subjects[50][50], int no_subjects){

	if (root2){
		Feature_DisplayFailed(root2->right, subjects, no_subjects);
		if (Grade(root2->total, 100 * no_subjects) == 'F'){
			printf("%d. %s - %d\n", root2->id, root2->name, root2->total);
			printf("\n");
		}
		Feature_DisplayFailed(root2->left, subjects, no_subjects);
	}
}
void Feature_DisplayPromoted(struct MarksNode* root2, char subjects[50][50], int no_subjects){

	if (root2){
		Feature_DisplayPromoted(root2->right, subjects, no_subjects);
		if (Grade(root2->total,100*no_subjects) != 'F'){
			printf("%d. %s - %d\n", root2->id, root2->name, root2->total);
			printf("\n");
		}
		Feature_DisplayPromoted(root2->left, subjects, no_subjects);
	}
}
void Feature_DisplayTopper(struct MarksNode* root2, char subjects[50][50], int no_subjects){

	if(root2){
		Feature_DisplayTopper(root2->right, subjects, no_subjects);
			printf("%d. %s - %d\n", root2->id, root2->name, root2->total);
			printf("\n");
			return;
		Feature_DisplayTopper(root2->left, subjects, no_subjects);
	}
}
void Feature_DisplayTotalDb(struct MarksNode* root2, char subjects[50][50], int no_subjects,int K){

	if (root2){
		Feature_DisplayTotalDb(root2->right, subjects, no_subjects,K);
		if (K == -1 || root2->total > K){
			printf("%d. %s - %d\n", root2->id, root2->name, root2->total);
			printf("\n");
		}
		Feature_DisplayTotalDb(root2->left, subjects, no_subjects,K);
	}
}
void Feature_DisplayDb(struct node* root,char subjects[50][50],int no_subjects){
	if (root){
		printf("%d. %s\n", root->id, root->name);
		for (int i = 0; i < no_subjects; i++) printf("%s - %d\n", subjects[i], root->marks[i]);
		printf("\n");
		Feature_DisplayDb(root->left, subjects, no_subjects);
		Feature_DisplayDb(root->right,  subjects,  no_subjects);
	}
}
void SearchByName(struct node *root, char *sName, int *id_array, int *id_ptr){
	if (root != NULL){
		if (strcmp(lowerCaseWord(root->name), lowerCaseWord(sName)) == 0){
			id_array[*id_ptr] = root->id;
			*id_ptr = *id_ptr + 1;
		}
		SearchByName(root->left, sName,id_array,id_ptr);
		SearchByName(root->right, sName, id_array, id_ptr);
	}
}
void SelectByIdName(struct node *root, int id, char *del_name){

	if (root != NULL){
		if (root->id  == id){
			strcpy(del_name, root->name);
			return;
		}
		SelectByIdName(root->left, id,del_name);
		SelectByIdName(root->right, id,del_name);
	}
}
int SelectByNameId(struct node *root, char *sName){
	int Ids[MAX_ENTRIES];
	int iptr = 0;
	SearchByName(root, sName, Ids, &iptr);

	// display all hit Ids
	printf("found matches...\n");
	for (int i = 0; i < iptr; i++){
		printf("%d. %s\n", Ids[i], sName);
	}

	int id_option = -1;
	printf("choose an id:");
	scanf("%d", &id_option);
	return id_option;
}
int SelectSubjectId(char all_subjects[50][50], int no_subjects){
	for (int i = 0; i < no_subjects; i++)
		printf("%d . %s\n", i + 1, all_subjects[i]);

	int subject_option;
	printf("select a subject: ");
	scanf_s("%d", &subject_option);
	return subject_option - 1;
}
char* SelectSubject(char all_subjects[50][50], int no_subjects){
	for (int i = 0; i < no_subjects; i++)
		printf("%d . %s\n", i+1, all_subjects[i]);

	int subject_option;
	printf("select a subject: ");
	scanf_s("%d", &subject_option);
	return all_subjects[subject_option-1];
}
int FindSubjectIndex(char all_subjects[50][50], int no_subjects, char *subject){
	for (int i = 0; i < no_subjects; i++)
		if (strcmp(all_subjects[i], subject) == 0) return i;
	return -1;
}
char Grade(int total, int max){
	
	float test = ((float)total / (float)max) * 100;
	if (test > 80) return 'A';
	else if (test > 70 && test <= 80) return 'B';
	else if (test > 60 && test <= 70) return 'C';
	else return 'F';
}
float Average(int *marks, int no_subjects){
	float total = 0;
	for (int i = 0; i < no_subjects; i++){
		total += marks[i];
	}
	return total/(float)no_subjects;
}
int Sum(int *marks,int no_subjects){
	int total = 0;
	for (int i = 0; i < no_subjects; i++){
		total += marks[i];
	}
	return total;
}
char* lowerCaseWord(char* a)
{
	char *b = new char[strlen(a)];
	for (int i = 0; i < strlen(a); i++)
	{
		b[i] = tolower(a[i]);
	}
	return b;
}
int isValidName(char *ip_name){

	if (!isalpha(ip_name[0])) return 0;
	for (int i = 0; ip_name[i] != '\0'; i++)
		if (ispunct(ip_name[i])) return 0;
	return 1;
}
int isValidMarksInt(int marks){
	if (marks >= 0 && marks <= 100) return 1;
	else 0;
}
int isValidMarks(char *marks){
	for (int i = 0; marks[i] != '\0'; i++)
		if (isalpha(marks[i])) return 0;
	return 1;
}
struct node * minValueNode(struct node* node){
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;
	return current;
}
struct MarksNode* LeaderBoard_TotalMarksEntries(struct MarksNode *root1, struct node* root2,char subjects[50][50], int no_subjects){

	// preorder travel root2;
	// find sum and insert into root1
	
	if (root2){
		root1 = InsertTotal(root1, root2->name, Sum(root2->marks, no_subjects), root2->id);
		LeaderBoard_TotalMarksEntries(root1,root2->left,subjects,no_subjects);
		LeaderBoard_TotalMarksEntries(root1, root2->right, subjects, no_subjects);
	}

	return root1;
}
struct node* DeleteById(struct node* root, int id, char *name){
	
	if (root == NULL) return root;

	if (strcmp(lowerCaseWord(root->name), lowerCaseWord(name)) == 0) {

		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		struct node* temp = minValueNode(root->right);

		root->id = temp->id;
		strcpy(root->name, temp->name);
		root->marks = temp->marks;

		root->right = DeleteById(root, temp->id, temp->name);
	}
	else if (strcmp(root->name, name))
		root->left = DeleteById(root->left, id, name);
	else 
		root->right = DeleteById(root->right, id, name);

	return root;
}
struct MarksNode* InsertTotal(struct MarksNode* r, char *name, int marks, int id){

	if (r == NULL)
	{
		r = (struct MarksNode*) malloc(sizeof(struct MarksNode));
		r->id = id;
		strcpy(r->name, name);
		r->total = marks;
		r->left = NULL;
		r->right = NULL;
	}
	else if (id == r->id){
		// if same id found
	}
	else if (r->total > marks){
		r->left = InsertTotal(r->left, name, marks, id);
	}
	else {
		r->right = InsertTotal(r->right, name, marks, id);
	}
	return r;
}
struct node* Insert(struct node* r, char *name, int *marks, int id)
{
	if (r == NULL)
	{
		r = (struct node*) malloc(sizeof(struct node));
		r->id = id;
		strcpy(r->name, name);
		r->marks = marks;
		r->left = NULL;
		r->right = NULL;
	}
	else if (id == r->id){
		// if same id found
	}
	else if (strcmp(r->name,name)<0){
		r->left = Insert(r->left, name,marks,id);
	}
	else {
		r->right = Insert(r->right, name, marks, id);
	}
	return r;
}
void Split(char *dirty, char clean[][50], char dirt){
	
	char *each_subject = (char*)malloc(sizeof(char) * SUBJECT_LENGTH);
	char sptr = 0;
	char cptr = 0;
	for (int i = 0; dirty[i] != '\0'; i++){
		if (dirty[i] != dirt)
			each_subject[sptr++] = dirty[i];
		else{
			each_subject[sptr] = '\0';
			strcpy(clean[cptr++], each_subject);
			each_subject = (char*)malloc(sizeof(char) * SUBJECT_LENGTH);
			sptr = 0;
		}
	}
	each_subject[sptr] = '\0';
	strcpy(clean[cptr++], each_subject);
}
void SplitInt(char *dirty, int *clean, char dirt){

	char cleantemp[50][50];
	int count = 0;
	char *each_Marks = (char*)malloc(sizeof(char) * SUBJECT_LENGTH);
	char sptr = 0;
	char cptr = 0;
	int i;
	for (i = 0; dirty[i] != '\0'; i++){
		if (dirty[i] != dirt)
			each_Marks[sptr++] = dirty[i];
		else if(dirty[i] == dirt){
			each_Marks[sptr] = '\0';
			strcpy(cleantemp[cptr++], each_Marks);
			count++;
			each_Marks = (char*)malloc(sizeof(char) * SUBJECT_LENGTH);
			sptr = 0;
		}
	}
	each_Marks[sptr] = '\0';
	strcpy(cleantemp[cptr++], each_Marks);

	// converting into int to clean array
	for (int i = 0; i <= count; i++) 
		clean[i] = atoi(cleantemp[i]);
}
struct node* init(char filename[20], int *no_subjects, char subjects[][50], struct node *root
						,int *ID){
	
	FILE *input;
	char nsubjects[5] = "";
	char temp[100] = "";
	char ip_name[50];
	char sMarks[100];
	int *marks;
	input = fopen(filename, "r");
	fscanf(input, "%s", nsubjects);
	*no_subjects = atoi(nsubjects);

	// init the sujects array
	fscanf(input, "%s", temp);
	Split(temp,subjects, ',');
	
	// Insert into tree
	while (!feof(input)){
		marks = (int*)malloc(sizeof(int)*(*no_subjects));
		fscanf(input, "%s", ip_name);
		if (!isValidName(ip_name))
			continue;
		fscanf(input, "%s", sMarks);
		if (!isValidMarks(sMarks))
			continue;
		SplitInt(sMarks, marks, ',');
		root = Insert(root, ip_name, marks, (*ID)++);
	}
	return root;
}
void MenuDisplay(){

	printf("1. Display the db\n");
	printf("2. Student's Info\n"); // ask is it all or particular or max or avg
	printf("3. subject wise display\n"); // ask all or particular | order name wise or subject wise
	printf("4. Enter new entry\n");
	printf("5. Delete an entry\n");
	printf("6. Edit Student's details\n");// ask name or subject
	printf("7. LeaderBoard\n"); // ask subject >K 
	printf("8. exit\n");
}
void MenuSelect(struct node* root, char subjects[50][50], int no_subjects,int *ID){

	int option_selected;
	printf("\n----------choose an option--------------\n");
	scanf_s("%d", &option_selected);
	printf("\nselect 100 for menu options\n");
	switch (option_selected)
	{
	case 1:
		Feature_DisplayDb(root, subjects,no_subjects);
		break;
	case 2:
		Feature_StudentPortalMenu(root, subjects, no_subjects);
		break;
	case 3:
		Feature_DisplaySubject(root, subjects, no_subjects, SelectSubject(subjects, no_subjects));
		break;
	case 4:
		Feature_NewEntry(root, subjects,no_subjects,ID);
		break;
	case 5:
		Feature_DeleteEntry(root, subjects,no_subjects,ID);
		break;
	case 6:
		Feature_EditEntry(root, subjects, no_subjects, ID);
		break;
	case 7:
		Feature_LeaderBoard(root, subjects, no_subjects, ID);
		break;
	case 8:
		// save the changes into a file and then exit
		printf("exiting");
		break;
	case 100:
		MenuDisplay();
	default:
		printf("worng option- choose again");
		MenuSelect(root,subjects,no_subjects,ID);
	}
}
void main(){
	
	printf("Student Data Base Program\n");
	MenuDisplay();
	int no_sujects;
	char subjects[50][50];
	struct node *root;
	root = NULL;
	int ID = 1;
	char filename[] = "F:\\student.txt";
	root = init(filename, &no_sujects, subjects, root,&ID);
	MenuSelect(root,subjects,no_sujects,&ID);
	_getch();
}
