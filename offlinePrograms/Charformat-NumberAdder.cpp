/*Given two strings which are unsigned integer numbers (in string format)
write an adder to add the numbers. Lenghts of both can be different.*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void Adder(char*, char*);
int Length(char*);
void Reverse(char*);
int Validate(char*);
void main(){

	char num1[50];
	char num2[50];

	gets_s(num1);
	gets_s(num2);
	Adder(num1, num2);

	_getch();

}
int Validate(char *num){
	for (int i = 0; num[i] != '\0'; i++)
		if ((int)num < 48 || (int)num > 57) return 0;
	return 1;
}
void Reverse(char *num){

	char *temp;
	int tempi = Length(num)-1;
	temp = (char*)malloc(sizeof(char)*Length(num));

	for (int i = 0; num[i] != 0; i++,tempi--){
		temp[tempi] = num[i];
	}
	temp[Length(num)] = '\0';

	puts(temp);
}
int Length(char *num){
	int count;
	for (count = 0; num[count] != '\0'; count++);
	return count;
}
void Adder(char *num1, char *num2){

	char Sum[50];
	int carry = 0;
	int i = Length(num1)-1;
	int j = Length(num2)-1;
	int end=i;
	char x, y;
	int d=0;
	i > j ? end = i : end = j;
	
	int z = 0;
	while (z <= end){

		if (i < 0) x = '0';
		else x = num1[i];

		if (j < 0) y = '0';
		else y = num2[j];

		d += carry+((int)x - 48) + ((int)y - 48);
		Sum[z] = (char)((d % 10)+48);
		d /= 10;
		carry = d;
		i--;
		j--;
		z++;
		d = 0;
	}
	Sum[z] = '\0';
	Reverse(Sum);
}