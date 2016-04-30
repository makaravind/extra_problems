#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stack>
#include <iostream>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
// Functions declarations
void PostFix(char * , char postfix[][20]);
int PostFixEval(char[][20]);
int isOperator(char *var, int current_index);
char getOperatorCheck(char *infix, int* current_index);
char getOperator(char *infix, int* current_index);
int isGreaterPrecedence(char current_operator);

//Funtions definitions
char getOperatorCheck(char *infix, int* current_index){
	char current_operator;
	if (infix[*current_index] == '*' && infix[*current_index + 1] == '*') {
		current_operator = '^';
	}
	else current_operator = infix[*current_index];

	return current_operator;
}
char getOperator(char *infix, int* current_index){
	char current_operator;
	if (infix[*current_index] == '*' && infix[*current_index + 1] == '*') {
		current_operator = '^';
		*current_index = *current_index + 1;
	}
	else current_operator = infix[*current_index];

	return current_operator;
}
int isGreaterPrecedence(char current_operator){
	
	/*
	precedence :
		** , * , / , + , -
	*/	
	if (current_operator == '^') return 3;
	else if (current_operator == '*' || current_operator == '/') return 2;
	else if (current_operator == '+' || current_operator == '-') return 1;
	return -1;
}
int CheckPriority(char *infixCheck,int *i,char top){
	char temp = getOperatorCheck(infixCheck, i);
	char str1[2] = { temp, '\0' };
	char oper[5] = "";
	strcpy_s(oper, str1);
	if (strcmp(oper, "^") == 0){
		if (isGreaterPrecedence(temp) < isGreaterPrecedence(top)) return 1;
		return 0;
	}
	else{
		if (isGreaterPrecedence(temp) <= isGreaterPrecedence(top)) return 1;
		return 0;
	}
}
int isOperator(char *var, int current_index){
	/*
	precedence :
	** , * , / , + , -
	*/
	if (current_index == -1){

		if (strcmp(var, "^") == 0 || strcmp(var, "+") == 0 || strcmp(var, "-") == 0
			|| strcmp(var, "*") == 0 || strcmp(var, "/") == 0)
			return 1;
		return 0;
	}
	else{

		if (var[current_index] == '*' && var[current_index + 1] == '*') return 1;
		else if (var[current_index] == '*' || var[current_index] == '/'
			|| var[current_index] == '+' || var[current_index] == '-')
			return 1;

		return 0;
	}
}
void PostFix(char *infix, char postfix[][20]){

	/*converts infix expression into post fix, saves in postfix[][] finally*/

	int tptr = 0;
	char temp[20][20];
	//temp = (char*)malloc(sizeof(char)*strlen(infix));
	std::stack<char> postfix_stack;

	for (int i = 0; i < strlen(infix); i++){

		if (isdigit(infix[i])){
			char buff[10];
			int bptr = 0;
			while (isdigit(infix[i])){
				buff[bptr++] = infix[i];
				i++;
			}
			i--;
			buff[bptr] = '\0';
			bptr = 0;
			strcpy_s(temp[tptr++], buff);
		}

		else if (isOperator(infix, i)) {


			while ((!postfix_stack.empty())
				&& CheckPriority(infix, &i, postfix_stack.top())){

				char top = postfix_stack.top();
				char str1[2] = { top, '\0' };
				char str2[5] = "";
				strcpy_s(str2, str1);
				strcpy_s(temp[tptr++], str2);
				postfix_stack.pop();
			}
			postfix_stack.push(getOperator(infix, &i));
		}

	}
	while (!postfix_stack.empty())
	{

		char top = postfix_stack.top();
		char str1[2] = { top, '\0' };
		char str2[5] = "";
		strcpy_s(str2, str1);
		strcpy_s(temp[tptr++], str2);
		postfix_stack.pop();
	}
	strcpy_s(temp[tptr], "DONE");

	//copying temp into postfix param
	for (int i = 0; strcmp(temp[i], "DONE") != 0; i++)
		strcpy_s(postfix[i], temp[i]);
	strcpy_s(postfix[tptr], "DONE");
}
int PostFixEval(char postfix[][20]){

	/*takes postfix expression and evaluttes and returns the final value*/

	std::stack<int> eval_stack;
	int op1, op2;
	for (int i = 0; strcmp(postfix[i], "DONE") != 0; i++){
		//	printf("%d", atoi("*"));
		if (!eval_stack.empty() && eval_stack.size() >= 2 && isOperator(postfix[i], -1)){
			op1 = eval_stack.top();
			eval_stack.pop();
			op2 = eval_stack.top();
			eval_stack.pop();

			//printf("%s- operator , %d %d\n", postfix[i], op1, op2);
			if (strcmp("^", postfix[i]) == 0)
				eval_stack.push(pow(op2, op1));
			else if (strcmp("*", postfix[i]) == 0)
				eval_stack.push(op1*op2);
			else if (strcmp("/", postfix[i]) == 0){
				if (op1 == 0) eval_stack.push(0);
				else eval_stack.push(op2 / op1);
			}
			else if (strcmp("+", postfix[i]) == 0)
				eval_stack.push(op1 + op2);
			else if (strcmp("-", postfix[i]) == 0)
				eval_stack.push(op2 - op1);
		}
		else {
			eval_stack.push(atoi(postfix[i]));
		}
	}
	return eval_stack.top();
}
void main(){
	
	
	//opeing required files
	FILE *src, *dest;
	char filename[] = "F:\\sample3.txt";
	char dest_filename[] = "F:\\eval-results1.txt";
	src = fopen(filename, "r");
	dest = fopen(dest_filename, "w");
	if (src == NULL || dest == NULL) printf("error");

	char infix[20];
	char postfix[20][20];
	while (!feof(src))
	{	
		fscanf(src, "%s", infix);
		PostFix(infix, postfix);
		int value = PostFixEval(postfix);

		// print into the destination file
		fprintf(dest, "%s", infix);
		fprintf(dest, " = %d\n", value);
	}
	
	_getch();
}




/*std::stack<int> first;
first.push(1);
printf("%d", first.top());
first.pop();*/