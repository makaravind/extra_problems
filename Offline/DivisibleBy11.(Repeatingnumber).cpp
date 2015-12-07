/*An unsigned number Q is formed by taking input P which is an unsigned integer in string format, K: number of times P repeated to form Q. write a function to find whether the number Q is divisible by 11 or not
ex: Q: 123123123 P: 123 K:3*/
#include<stdio.h>
#include<conio.h>
int IsDivisible_11(char*);
int Validate(char*,int);
int Length(char*);
void main(){

	char number[50];
	int repeat;
	gets_s(number);
	scanf_s("%d", &repeat);

	if (Validate(number, repeat)) {

		if (Length(number) % 2 == 0){

			if (IsDivisible_11(number)) printf("Divisible by 11");
			else printf(" not Divisible by 11");

		}

		else{
			if (!IsDivisible_11(number))
				if (repeat % 2 == 0) printf("divisible by 11");
				else printf("not divisible by 11");

			else
				printf("divisible by 11");
		}
	}
	 
	else printf("Invalid");

		
	_getch();
}
int Length(char *num){
	int count;
	for (count = 0; num[count] != '\0'; count++);
	return count;
}
int Validate(char *num,int repeat){
	if (repeat <= 0) return 0;
	for (int i = 0; num[i] != '\0'; i++)
		if ((int)num[i] < 48 || (int)num[i] > 57) 
			return 0;
	return 1;
}
int IsDivisible_11(char *num){

	int even = 0;
	int odd = 0;

	for (int i = 0; num[i] != '\0'; i++){

		if ((i + 1) % 2 != 0)
			odd += ((int)num[i] - 48);
		else
			even += ((int)num[i] - 48);
	}

	if ((odd - even) % 11 == 0) return 1;
	return 0;

}
