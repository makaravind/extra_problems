#include<stdio.h>
#include<conio.h>
void PrintN(int*);
void main(){

	int arr[100] ;
	for (int i = 0; i < 12; i++) scanf_s("%d", &arr[i]);
	PrintN(arr);
	_getch();
}
void PrintN(int *ap){

	int i = 0;
	while (1){

		if (ap[i] < ap[i + 1] && ap[i+1] >  ap[i+2])
		{
			printf("%d", i + 1);
		}
		else if (ap[i] > ap[i + 1])
		{
			printf("%d", i - 1);
			break;
		}
		else if (ap[i] == 0){
			i = (i / 2) + (i/4);
		}
		i = (i+1) * 2;

	}

}