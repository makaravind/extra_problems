#include<stdio.h>
#include<conio.h>
#include<malloc.h>

int max(int a, int b){
	if (a > b) return a;
	return b;
}
int maxSubArraySum(int a[], int size)
{
	int max_so_far = a[0];
	int curr_max = a[0];

	for (int i = 1; i < size; i++)
	{
		curr_max = max(a[i], curr_max + a[i]);
		max_so_far = max(max_so_far, curr_max);
	}
	return max_so_far;
}

int main()
{
	int a[] = {1, 2, 3, 4 ,5, - 2, - 3, - 4, - 20, 10, 2};
	int n = sizeof(a) / sizeof(a[0]);
	int max_sum = maxSubArraySum(a, n);
	printf("Max sum = %d", max_sum);
	_getch();
