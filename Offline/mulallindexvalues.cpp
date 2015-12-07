// WAP to create an array where index is the multiple of all the elements expect that
#include<stdio.h>
#include<conio.h>
void Multiply(int*, int*, int);
void main(){

	int size;
	int a[100];
	int b[100];

	scanf_s("%d", &size);

	for (int i = 0; i < size; i++) scanf_s("%d", &a[i]);
	Multiply(a, b, size);
	for (int i = 0; i < size; i++)
		printf("%d\t", b[i]);
	_getch();
}
void Multiply(int *ap, int *bp, int size){

	ap[-1] = 1;
	bp[size] = 1;
	for (int i = 0; i < size; i++){
		bp[i] = ap[i];
		ap[i] = ap[i] * ap[i - 1];
	}

	for (int i = size-1; i >= 0; i--){
		bp[i] = bp[i] * bp[i + 1];
	}


	int i = -1;
	int j = 1;
	
	while (1){
		if (j > size) break;
		bp[j - 1] = bp[j] * ap[i];
		j++;
		i++;	
	}

	
}