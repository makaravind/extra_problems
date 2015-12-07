/**/
#include<stdio.h>
#include<conio.h>
void Arrange(int*, int);
void Swap(int*, int, int, int);
void main(){

	int size;
	int a[100];
	scanf_s("%d", &size);

	for (int i = 0; i < size; i++)
	{
		int temp;
		scanf_s("%d", &temp);
			if (temp != 0 && temp != 1) {
				printf("you have to enter 1 or 0 ! just as a remainder");
				i--;
				continue;
			}
			else a[i] = temp;
	}

	Arrange(a, size);
	for (int i = 0; i < size; i++) printf("%d", a[i]);

	_getch();
}
void Swap(int *ap, int size, int i, int j){
	int temp;
	temp = ap[i];
	ap[i] = ap[j];
	ap[j] = temp;
}
void Arrange(int *ap, int size){

	int i = 0;
	int j = size - 1;

	while (i<j){
		if (ap[i] == 0)i++;
		if (ap[j] == 1)j--;
		if (ap[i] != 0 && ap[j] != 1){
			Swap(ap, size, i, j);
			i++;
			j--;
		}
	}

}