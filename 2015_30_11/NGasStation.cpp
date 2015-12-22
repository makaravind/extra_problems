#include<stdio.h>
#include<conio.h>
struct result{
	int first;
	int second;
};
struct result NGasStation(int*, int);
void main(){
	//int a[50] = { 1, 2, 3, 4, 5, - 2, - 3, - 4, - 20, 10, 2 };
	int a[50] = { 1, 2, 3, 5, -10, 20, 40 };
	int n = sizeof(a) / sizeof(a[0]);
	/*scanf_s("%d", &n);
	for (int i = 0; i < n; i++) scanf_s("%d", &a[i]);*/
	struct result temp = NGasStation(a, n);
	printf("%d %d", a[temp.first], a[temp.second]);
	_getch();
}
struct result NGasStation(int *ap, int size){
	int first, second;
	int Sum = 0;
	first = 0;
	second = 1;
	int flag1;
	int flag = 0;
	
	while(second != size){
		
		if (flag == 0){
			if (ap[first] > 0){
				Sum += ap[first];
				flag = 1;
			}
			else{
				first++;
				second = first + 1;
			}
		}
		
		if (ap[second] < 0){
			
			int temp = Sum + ap[second];
			if (temp <= 0){
				first = second+1;
				second = second+2 ;
				Sum = 0;
				flag = 0;
				continue;
			}
			else /*greater than 0*/{
				int temp2 = ap[second] + ap[second + 1];
				if (temp2 > 0){
					Sum += ap[second];
					second++;
				}
				else if (temp2 < 0) break;
			}
		}
		else {
			Sum += ap[second++];
		}
	}

	struct result temp;
	temp.first = first;
	temp.second = second - 1;

	return temp;
}