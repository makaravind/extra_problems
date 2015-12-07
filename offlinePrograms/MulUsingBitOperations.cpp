/* Given two integers X, Y, write a function for X*Y without using multiplication or addition operators. Use bit operators*/
#include<stdio.h>
#include<conio.h>
int MUL(int, int);
int validate(int, int);
void main(){
	int x; // first number
	int y; //second number

	// input 2 numbers.
	scanf_s("%d%d", &x, &y); 

	if (validate(x, y)){
		printf("%d", MUL(x, y));
	}
	else
		printf("Invalid :P");
	_getch();
}
//checking whether entered inputs are right or wrong.
int validate(int x, int y){
	if (x < 0 || y < 0)
		return 0;
	return 1;
}
// Multiply using bit operatons
int MUL(int x,int y){

	int result = 0;

	while (y != 0){
		if (y & 01)
			result += x;
		x <<= 1; // left swift 
		
		y >>= 1; // right shift
	}

	return result;
}