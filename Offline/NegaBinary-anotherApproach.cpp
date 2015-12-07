#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<malloc.h>
int binary_decimal(char*);
int Length(char*);
void sets(int,int*);
void PrintSet(char*);
void main(){

	
	char binaryNum[50];
	printf("Enter number in binary");
	gets_s(binaryNum);
	PrintSet(binaryNum);
	_getch();
}
void PrintSet(char* binary){

	int decimal = binary_decimal(binary);
	switch (decimal)
	{
	case 0 :
		printf("0");
		return;
	case 1:
		printf("1");
		return;
	case 2:
		printf("110");
		return;
	case 3:
		printf("111");
		return;
	case 4:
		printf("100");
		return;
	case 5:
		printf("101");
		return;
	case 6:
		printf("110");
		return;
	}
	int a[] = { -1, -1, -1, -1, -1, -1, -1, -1 };
	char set1[5] = "10";
	char set2[5] = "11";
	char set3[5] = "00";
	char set4[5] = "01";

	sets(decimal, a);
	printf("1");
	for (int i = 0; a[i] > 0; i++){
		switch (a[i])
		{
		case 1: printf("10");
			break;
		case 2:printf("11");
			break;
		case 3:printf("00");
			break;
		case 4:printf("11");
			break;
		}
	}
	printf("%c%c", binary[Length(binary) - 2], binary[Length(binary) - 1]);
}

void sets(int num,int *arr){
	
	int flag = 1;
	int j = 0;
	for (int i = 6; i <= num; i++,flag++){
		if (flag == 5){
			flag = 1;
			if (arr[0] == -1)
			arr[0]=1;
			arr[0]++;
			if (arr[0] == 5)
			{
				arr[0] = 1;
				if (arr[1] == -1)
				arr[1] = 0;
				arr[1]++;
					if (arr[1] == 5){
						arr[1] = 1;
						if (arr[2] == -1)
							arr[2] = 0;
						arr[2]++;
						if (arr[2] == 5){
							arr[2] = 1;
							if (arr[3] == -1)
								arr[3] = 0;
							arr[3]++;
							if (arr[3] == 5){
								arr[3] = 1;
								if (arr[4] == -1)
									arr[4] = 0;
								arr[4]++;
								if (arr[4] == 5){
									arr[4] = 1;
									if (arr[5] == -1)
										arr[5] = 0;
									arr[5]++;
									if (arr[5] == 5){
										arr[5] = 1;
										if (arr[6] == -1)
											arr[6] = 0;
										arr[6]++;
										if (arr[6] == 5){
											arr[6] = 1;
											if (arr[7] == -1)
												arr[7] = 0;
											arr[7]++;
											if (arr[8] == 5){
												arr[8] = 1;
												if (arr[9] == -1)
													arr[9] = 0;
												arr[9]++;
											}
										}
									}
								}
							}
						}
					}
			}
		}
	}
//	for (int i = 0; arr[i] > 0; i++) printf("%d\n", arr[i]);
		//return NULL;
}
int binary_decimal(char *binary){
	int power = 0;
	int decimal = 0;
	int inter;
	for (int i = Length(binary) - 1, j = 0; i >= 0; i--, j++){
		if (binary[i] == '1'){
			inter = pow(2.0, j);
			decimal += inter;
		}

	}
	return decimal;
}
int Length(char *cp){
	int count;
	for (count = 0; cp[count] != '\0'; count++);
	return count;
}