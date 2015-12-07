// Find x power y mod a
#include<stdio.h>
#include<conio.h>
int Find(int, int, int);
int Find2(int, int, int);
int Power(int, int);
void main(){

	int x, y, a;
	printf("Find x power y mod a");
	scanf_s("%d%d%d", &x, &y, &a);
	printf("%d", Find(x, y, a));
	printf("\t%d", Find2(x, y, a));
	_getch();
}
// Finding power function
int Power(int x, int y){
	int temp = x;
	for (int i = 1; i <= y; i++) temp = temp*x;
	return temp;
}
// Main logic function ( x^y ) % z
int Find(int x, int y, int z){
	int ans = 1;
	int square = x;

	while (y != 0){
		if (y % 2) ans = ans * square;
		square = (square*square) % z;
		y = y / 2;
		if (ans > z) ans = ans % z;
	}
	return ans;
}
