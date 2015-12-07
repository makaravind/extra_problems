/*Given a unsigned number as a string input(it can be of length, max 10000 chars) write a function to 
find whether the number is divisible by 11 or not*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int IsDivisible_11(char*);
int Validate(char*);
void main(){

	char number[50];
	gets_s(number);
	if (Validate(number)){
		if (IsDivisible_11(number)) printf("divisible by 11");
		else printf("not divisible by 11");
	}
	else printf("Invalid");
	_getch();
}
int Validate(char *num){
	for (int i = 0; num[i] != '\0'; i++)
		if ((int)num < 48 || (int)num > 57) return 0;
	return 1;
}
int IsDivisible_11(char *num){

	int even = 0;
	int odd = 0;
	
	for (int i = 0; num[i] != '\0'; i++){

		if ( (i+1) % 2 != 0)
			odd += ((int)num[i] - 48);
		else
			even += ((int)num[i] - 48);
	}
	
	if ((odd - even) % 11 == 0) return 1;
	return 0;

}