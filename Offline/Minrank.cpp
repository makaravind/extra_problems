//find the min rank of the number 
// index of the number in the sorted array where all the permutation of the number in the array
#include<stdio.h>
#include<conio.h>
int Index(int*, int);
int Fact(int);
void main(){

	int size;
	int a[100];

	scanf_s("%d", &size);

	for (int i = 0; i < size; i++)
		scanf_s("%d", &a[i]);

	//Index(a, size);

	printf("\t%d", Index(a, size));

	/*for (int i = 0; i < size; i++)
	printf("%d\t", a[i]);*/
	_getch();
}
int Fact(int n){
	int fact=1;
	if (n == 0) return 1;
	for (int i = 1; i <= n; i++) fact = fact*i;
	return fact;
	

}
int Index(int *ap, int size){

	int index = 0;

	for (int i = 0; i < size; i++){
		/*if (ap[i] > ap[j])  {
			index = Fact(size + 1 - i);
		j++;
		}
		else j++;*/
		for (int j = i + 1; j < size; j++){
			if (ap[i] > ap[j])  {
				index = index + Fact(size -1 - i);
			}
		}
	}
	/*int i = 0;
	for (int j = i + 1; j < size; j++){
		/*if (ap[i] > ap[j])  {
		index = Fact(size + 1 - i);
		j++;
		}
		else j++;
		if (ap[i] > ap[j])  {
			index = Fact(size + 1 - i);			
		}
		if (j == size-1)i++;
	}*/
	//if (size % 2 != 0) index = index+1 ;

	return index;

}