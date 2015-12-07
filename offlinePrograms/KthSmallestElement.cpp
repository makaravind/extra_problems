#include<stdio.h>
#include<conio.h>
int KthSmallest(int*, int*, int);
void main(){

	int arr1[50];
	int size1;
	int arr2[50];
	int size2;
	int k;
	scanf_s("%d%d%d", &size1, &size2,&k);

	if (k <= (size1 + size2)) {
		for (int i = 0; i < size1; i++)
			scanf_s("%d", &arr1[i]);

		for (int i = 0; i < size2; i++)
			scanf_s("%d", &arr2[i]);

		printf("%d",KthSmallest(arr1, arr2, k));


	}
	else
	{
		printf("Invalid :P");
	}
	

	_getch();
}
int KthSmallest(int *a1, int *a2, int k){

	int i = 0;//for first array
	int j = 0;//for second array
	int prev;
	while (k>0)
	{
		if (a1[i] < a2[j]){
			prev = a1[i];
			i++;
		}
		else if (a1[i] > a2[j]){
			prev = a2[j];
			j++;
		}
		k--;
	}
	return prev;
}