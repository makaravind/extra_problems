#include<stdio.h>
#include<conio.h>
#include<malloc.h>
bool isKthBitSet(unsigned int x, unsigned int k)
{
	return (x & (1 << (k - 1))) ? true : false;
}
void Multiplier(int*, int*,int);
void LeftShift(int*, int);
void RightShift(int*, int);
void Add(int*, int*,int,int);
int AddSimple(int*, int*);
int CheckB(int*,int);
int CheckOddrEven(int*,int);
void main(){

	int a[60];
	int b[30];
	int size;
	scanf_s("%d", &size);
	for (int i = 0; i < size; i++) scanf_s("%d", &a[i]);
	for (int i = 0; i < size; i++) scanf_s("%d", &b[i]);
	Multiplier(a, b, size);
	_getch();

}
int CheckOddrEven(int *bp,int size){
	
	if (bp[size - 1] & 1)return 1; //odd
	else return 0;//even
}
int CheckB(int *bp,int size){

	for (int i = 0; i < size; i++){
		if (bp[i] > 0) return 1;
	}
	return 0;
}
void Add(int *ap, int *result,int size,int car){

	int res;
	int carry = car ;

	for (int i = size-1; i>=0; i--){
		result[i] += ap[i];
	}
	/*	res = (a ^ b) ^ carry;
		carry = (a & b) & carry;
		//printf("%d%d", res,carry);
		result[i] = res;*/
}
void RightShift(int *ap, int size){
	int carry;
	int prevcarry = 0;
	for (int i = 0; i < size; i++){

		if (!(ap[i] & 1))
			carry = 0;
		else
			carry = 1;

		ap[i] >>= 1;
		if (prevcarry)
		{
			ap[i] |= 1 << 32;
		}
		prevcarry = carry;

	}

}
void LeftShift(int *ap, int size){
	int carry;
	int i = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		if (i == size - 1 || !isKthBitSet(ap[i], 32)) carry = 0;
		else if (isKthBitSet(ap[i], 32))
			carry = 1;
		int temp = ap[i];
		temp <<= 1;
		ap[i] = temp;
		if (carry) ap[i]++;
	}

}
void Multiplier(int *ap, int *bp,int size){

	int result[50];
	for (int i = 0; i < size; i++)result[i] = 0;
	int carry = 0;
	//printf("%d",Add(ap, bp, result, 1, 0));
	while (CheckB(bp,size))
	{
		if (CheckOddrEven(bp, size)){
			Add(ap,result,size,carry);
		}
		LeftShift(ap, size);
		RightShift(bp, size);
	}
	for (int i = 0; i < size; i++) printf("%d", result[i]);
	//Normal Bit multiplication
	/*
	while(b != 0)               
   {
      if (b&01)                
        {
          result=result+a;     
        }
      a<<=1;                 
                               
      b>>=1;                 
   }*/

}