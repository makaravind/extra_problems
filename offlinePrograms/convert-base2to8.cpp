#include<stdio.h>
#include<conio.h>
#include<math.h>
void Convert_8(char*, char*);
void Set(char*,char*);
int binary_decimal(char *binary,int ,int);
int Length(char *bp){
	int count;
	for (count = 0; bp[count] != '\0'; count++);
	return count;
}
void main(){

	char temp[50];
	char Binary[50];
	char Octal[50];
	gets_s(Binary);
	if (Length(Binary) % 3 > 0)
	Set(Binary,temp);
	Convert_8(Binary,Octal);
	_getch();
}
void Set(char *Binary,char *temp){

	int j;

	if (Length(Binary) % 3 == 1){
		temp[0] = '0';
		temp[1] = '0';
		j = 2;
		for (int i = 0; Binary[i] != '\0'; i++, j++)
			temp[j] = Binary[i];
	}
	else if (Length(Binary) % 3 == 2){
		temp[0] = '0';
		j = 1;
		for (int i = 0; Binary[i] != '\0'; i++, j++)
			temp[j] = Binary[i];
	}
	temp[j] = '\0';
	
}
int binary_decimal(char *binary,int start,int end){
	int power = 0;
	int decimal = 0;
	int inter;
	for (int i = start, j = 0; i >= end; i--, j++){
		if (binary[i] == '1'){
			inter = pow(2.0, j);
			decimal += inter;
		}

	}
	return decimal;
}
void Convert_8(char *binary, char *octal){


	printf("%d", binary_decimal(binary, Length(binary) - 1, 2));
}