#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void FindSum(int,int*,int);
int Ismul3(int n){
	int odd_count = 0;
	int even_count = 0;
	if (n < 0)n *= -1;
	if (n == 0)return 1;
	if (n == 1) return 0;
	while (n)
	{
		/* If odd bit is set then
		increment odd counter */
		if (n & 1)
			odd_count++;
		n = n >> 1;

		/* If even bit is set then
		increment even counter */
		if (n & 1)
			even_count++;
		n = n >> 1;
	}
	return Ismul3(odd_count - even_count);

}
int Ismul5(int n){
	int d = n % 10;
	if (d == 0 || d == 5) return 1;
	else return 0;
}
void main(){

	int t;
	int input[50];
	int *output;
	scanf_s("%d", &t);
	if (t <= 0){
		printf("invalid");
		return;
	}
		//input = (int*)malloc(sizeof(int)*t);
		output = (int*)malloc(sizeof(int)*t);

		for (int i = 0; i < t; i++){
			scanf_s("%d", input[i]); //input the values
		}

		for (int i = 0; i < t; i++){
			printf("%d", input[i]);
		}

		for (int i = 0; i < t; i++){
			FindSum(input[i],output,i);
		}

		for (int i = 0; i < t; i++){
			printf("%d", output[i]);
		}
		_getch();

}
void FindSum(int n,int *op,int optr){
	int sum = 0;
	for (int i = 0; i < n; i++){
		if (Ismul3(i) && Ismul5(i)) sum += i;
	}
	op[optr] = sum;
}