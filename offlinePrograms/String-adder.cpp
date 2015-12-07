#include<stdio.h>
#include<conio.h>
void Adder(char*, char*);
void main(){

	char arr1[50];
	char arr2[50];
	gets_s(arr1);
	gets_s(arr2);
	Adder(arr1, arr2);
	_getch();
}
void Adder(char *a, char *b){

	int i = 0;
	int j = 0;
	int k = 0;
	char added[50];

	while (a[k] != '\0')
	{
		added[k] = ((int)a[i]-48) +((int)b[i]-48);

		if (added[k] == 9){
			i++;
		}
		else if(added[k] < 9){
			i++;
			j = i;
		}
		else{
			added[j]++;
			added[i] = added[k] % 10;

			while (i!=j)
			{
				j++;
				added[j] = 0;				
			}
		}
		k++;
	}
	added[k] = '\0';
	for (int i = 0; added[i] != '\0'; i++) printf("%d", added[i]);

}