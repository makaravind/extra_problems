#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void swap(char* a, char* b)
{
	char t = *a;
	*a = *b;
	*b = t;
}
int compare(const void *a, const void * b)
{
	return (*(char *)a - *(char *)b);
}
void Permutate(char*);
int findCeil(char str[], char first, int l, int h);
int Length(char *cp){
	int count;
	for (count = 0; cp[count] != '\0'; count++);
	return count;
}
void main(){

	char str[50] ;
	printf("Enter a string of length 8");
	for (int i = 0; i < 8; i++)
		scanf_s("%c", str[i]);
	Permutate(str);
	_getch();
}
void Permutate(char *str){

	int count = 0;
	int size = Length(str);
	int IsFinished = 0;
	qsort(str, size, sizeof(char), compare);
	while (!IsFinished){
		printf("%s\n", str);
		count++;
		//finding first char
		int i;
		for (i = size - 2; i >= 0; i--){
			if (str[i] < str[i + 1])
				break;
		}

		if (i == -1)
			IsFinished = 1;
		else{
			// find ceiling index
			int ceilIndex = findCeil(str, str[i], i + 1, size - 1);
			swap(&str[i], &str[ceilIndex]);

			qsort(str + i + 1, size - 1 - i, sizeof(char), compare);
		}
	}
	printf("Total number of permutations %d", count);
}
int findCeil(char str[], char first, int l, int h){
	int ceilIndex = l;

	for (int i = l + 1; i <= h; i++){
		if (str[i] > first && str[i] < str[ceilIndex])
			ceilIndex = i;
	}
	return ceilIndex;
}

