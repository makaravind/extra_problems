#include<stdio.h>
#include<conio.h>
struct stack
{
	int top;
	int stackarr[100];
	int size;
};
void StackInit(stack*);
void stackPush(stack*,int);
int stackPop(stack*);
int Eval(char*, stack*);
void main(){
	stack s;
	StackInit(&s);

	char expression[100] = "462+*";
	int size = 5;

	/*printf("enter the size of the expression\n");
	scanf_s("%d", &size);

	printf("enter the expression\n");
	gets_s(expression);
	//fgets(expression, 100, stdin);
	*/
	//printf("%d",Eval(expression, &s));

	_getch();

}
//Post fix eval
int Eval(char *exp, stack *sp){
	
	for (int i = 0; exp[i] != '\0'; i++){

		if ( (int)exp[i] >= 48 && (int)exp[i] <= 57 ){

			stackPush(sp,(int)exp[i]);

		}
		else if ((int)exp[i] >= 42 && (int)exp[i] <= 47)
		{
			switch ((int)exp[i])
			{
				case '+':
					stackPush(sp,stackPop(sp) + stackPop(sp));
					break;
				case '*':
					stackPush(sp, stackPop(sp) * stackPop(sp));
					break;
				case '/':
					stackPush(sp, stackPop(sp) / stackPop(sp));
					break;
				case '-':
					stackPush(sp, stackPop(sp) - stackPop(sp));
					break;
			default:
				printf("wrong operator");
				return -1;
			}
		}
		
	}
	return sp->top;
}
//stack functions and stack declaration
void stackPush(stack *sp,int ele){
	if (sp->top >= sp->size) {
		printf("stack full");
		return;
	}
	else{
		sp->stackarr[++sp->top] = ele;
	}
}
int stackPop(stack *sp){
	if (sp->top == -1) {
		printf("stack is empty");
		return -1;
	}
	else{
		return sp->stackarr[sp->top--];
	}
}
void StackInit(stack *sp){
	sp->top = -1;
	sp->size = 50;
}