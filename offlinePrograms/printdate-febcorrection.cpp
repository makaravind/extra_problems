/* given a date print the date as text, example: 10/1/1992 shoudl be printed as tenth january of nineteen ninety two.*/
#include<stdio.h>
#include<conio.h>
void PrintDate(char*);
int  Validate(char*);
void PrintMonth(char*);
void PrintYear(char*);
void PrintbyPlace2(char);
void PrintbyPlace1(char);
void PrintTeens(char);
void Printsingles(char);
void main(){

	char expression[50];
	printf("enter date in the form dd/mm/yyyy\n");

	gets_s(expression);
	if (Validate(expression)){
		PrintDate(expression);
		printf(" ");
		PrintMonth(expression);
		printf(" of ");
		printf(" ");
		PrintYear(expression);
	}
	_getch();
}
int Validate(char *exp){
	//validation of length of the string
	int i;
	for (i = 0; exp[i] != '\0'; i++);
	if (i <= 0 || i > 10){
		printf("AI is not used, you used enter in the specified order/format");
		return 0;
	}
	// validation for date
	char date[3];
	for (int i = 0; exp[i] != '\0'; i++){
		if (exp[i] != '/')
			date[i] = exp[i];
		else
			break;
	}
	 i = 0;
	int daten = 0;
	while (i<2){
		daten *= 10;
		daten = daten + date[i] - '0';
		i++;
	}
	if (daten <= 0 || daten >31) {
		printf("enter date between 1 and 31");
		return 0;
	}
	// validation for month
	char month[3];
	for (int i = 3, j = 0; i<5; i++, j++){
		month[j] = exp[i];
	}
	 i = 0;
	int monthn = 0;
	while (i<2){
		monthn *= 10;
		monthn = monthn + month[i] - '0';
		i++;
	}
	if (monthn <= 0 || monthn>12){
		printf("enter month between 1 and 12");
		return 0;
	}
	//validation for feb month
	if (monthn == 2){
		if (daten >= 30)
		{
			printf("enter valid february date");
			return 0;
		}
	}
	//validation for year
	char year[5];

	for (int i = 6, j = 0; exp[i] != '\0'; i++, j++)
		year[j] = exp[i];
	if (year[0] == '0'){
		printf("no records");
		return 0;
	}
	return 1;
}
void Printsingles(char number){
	switch (number)
	{
	case '1':
		printf("first");
		break;
	case '2':
		printf("second");
		break;
	case '3':
		printf("third");
		break;
	case '4':
		printf("forth");
		break;
	case '5':
		printf("fiveth");
		break;
	case '6':
		printf("sixth");
		break;
	case '7':
		printf("seventh");
		break;
	case '8':
		printf("eighth");
		break;
	case '9':
		printf("nighth");
		break;
	default:
		break;
	}
}
void PrintTeens(char number){
	switch (number)
	{
	case '0':
		printf("ten");
		break;
	case '1' : 
		printf("eleven");
		break;
	case '2':
		printf("twelve");
		break;
	case '3':
		printf("thirteen");
		break;
	case '4':
		printf("forteen");
		break;
	case '5':
		printf("fiveteen");
		break;
	case '6':
		printf("sixteen");
		break;
	case '7':
		printf("seventeen");
		break;
	case '8':
		printf("eighteen");
		break;
	case '9':
		printf("nineteen");
		break;
	default:
		break;
	}
}
void PrintYear(char *exp){
	char year[5];

	for (int i = 6,j=0; exp[i] != '\0'; i++,j++)
		year[j] = exp[i];
	
	int i = 0;
	while (year[i] != '\0')
	{
		if (year[i] == '1') {
			i++;
			PrintTeens(year[i]);
		}
		else{
			PrintbyPlace2(year[i]);
			i++;
			PrintbyPlace1(year[i]);
		}
		i++;
		if (year[i] == '1'){
			i++;
			PrintTeens(year[i]);
			break;
		}
		else{
			PrintbyPlace2(year[i]);
			i++;
			PrintbyPlace1(year[i]);
			break;
		}
	}
}
void PrintMonth(char *exp){

	char month[3];
	for (int i = 3,j=0;i<5; i++,j++){
		month[j] = exp[i];
	}
	int i = 0;
	int monthn=0;
	while (i<2){
		monthn *= 10;
		monthn = monthn+month[i] - '0';	
		i++;
	}
	switch (monthn)
	{
	case 1 :
		printf("january");
		break;
	case 2:
		printf("febuary");
		break;
	case 3:
		printf("march");
		break;
	case 4:
		printf("april");
		break;
	case 5:
		printf("may");
		break;
	case 6:
		printf("june");
		break;
	case 7:
		printf("july");
		break;
	case 8:
		printf("august");
		break;
	case 9:
		printf("september");
		break;
	case 10:
		printf("october");
		break;
	case 11:
		printf("november");
		break;
	case 12:
		printf("december");
		break;
	default:
		break;
	}
}
void PrintDate(char *exp){

	char date[3];
	for (int i = 0; exp[i] != '\0'; i++){
		if (exp[i] != '/')
			date[i] = exp[i];
		else
		break;
	}
	int i = 0;
	while(date[i] != '\0'){
		if (date[i] != '1' && date[i] != '0'){
			PrintbyPlace2(date[i]);
			i++;
		}
		else if (date[i] == '1') {
			i++;
			PrintTeens(date[i]);
			break;
		}
		else if (date[i] == '0')
		{
			i++;
			Printsingles(date[i]);
			break;
		}
	}

}
void PrintbyPlace1(char number){
	switch (number)
	{
	case 48 :
		printf(" ");
		break;
	case 49 :
		printf("one");
		break;
	case 50:
		printf("two");
		break;
	case 51:
		printf("three");
		break;
	case 52:
		printf("four");
		break;
	case 53:
		printf("five");
		break;
	case 54:
		printf("six");
		break;
	case 55:
		printf("seven");
		break;
	case 56:
		printf("eight");
		break;
	case 57:
		printf("nine");
		break;
	default:
		break;
	}
}
void PrintbyPlace2(char number){

	switch (number)
	{
	case 48:
		printf(" ");
		break;
		case 50 : 
		printf("twenty");
		break;
		case 51:
			printf("thirthy");
			break;
		case 52:
			printf("forty");
			break;
		case 53:
			printf("fivety");
			break;
		case 54:
			printf("sixty");
			break;
		case 55:
			printf("seventy");
			break;
		case 56:
			printf("eighty");
			break;
		case 57:
			printf("nighty");
			break;
	default:
		break;
	}
}