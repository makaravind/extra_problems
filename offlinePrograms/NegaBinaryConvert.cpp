//   a = (-r)c + d = (-r)c + d - r + r = (-r)(c + 1) + (d + r)
#include<stdio.h>
#include<conio.h>
void NegaBinary(int);
void Binary(int);
 /*void toNegaBinary(unsigned int value) // input in standard binary
{
	unsigned int Schroeppel2 = 0xAAAAAAAA; // = 2/3*((2*2)^16-1) = ...1010
	printf("%d", (value + Schroeppel2) ^ Schroeppel2); // eXclusive OR
	// resulting unsigned int to be interpreted as string of elements ε {0,1} (bits)
}*/
void main(){

	int num = 6;
	
	NegaBinary(num);
	//Binary(num);
	//toNegaBinary(1111);
	_getch();
}
void Binary(int num){
	int result = 0;
	int remainder;

	while (num != 0)
	{
		remainder = num % 2;
		num /= 2;
		printf("%d\n", remainder);
	}


}

void NegaBinary(int n){
	int a;
	int arr[50];
	int size = 0;
	if (n == 0) printf("0");
	else{
		while (n != 0){
			a = n % 2;
			arr[size++] = a;
			n = (n - a) / 2;
			
		}
		for (int i = 0; i < size; i++) printf("%d", arr[i]);
	}




	/*int result = 0;
	int remainder;
	
	while (num!=0)
	{
		remainder = num % -2;
		num /= -2;

		if (remainder < 0){
			remainder += 2;
			num + 1;
		}

		result += remainder;
		result *= 10;
		printf("%d\n", remainder);
	}*/
	
}