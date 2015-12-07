/*Same string as Q 2, write a function for divisibility by 3*/
#include<stdio.h>
#include<conio.h>
int IsDivisible_3(char*,int);
int Validate(char*);
void main(){

	char num[50];
	int repeat;

	gets_s(num);
	scanf_s("%d", &repeat);
	if (Validate(num)){
		if (IsDivisible_3(num, repeat)) printf("Divisible by 3");
		else printf("not Divisible by 3");
	}
	else printf("Invalid");
	
	

}
int Validate(char *num){
	for (int i = 0; num[i] != '\0'; i++)
		if ((int)num < 48 || (int)num > 57) return 0;
	return 1;
}
int IsDivisible_3(char *num,int repeat){

	int sum = 0;

	for (int i = 0; num[i] != 0; i++){
		sum += ((int)num[i] - 48);
	}
	sum *= repeat;
	if (sum % 3 == 0) return 1;
	return  0;

}