#include <stdio.h>
#include<conio.h>
int main()
{
	
	FILE *fptr,*fptr1;
	int k = 5; //input

	fopen_s(&fptr1, "VSprojectsLastnFileRef1.txt", "r");
	int c=NULL;
	int lines = 1;
	while (c != EOF){
		c = fgetc(fptr1);
		if (c == (int)'\n') lines++;
	}
	fclose(fptr1);
	// printing last n lines
	int toread = lines - k;
	if (toread < 0) {
		printf("Wrong input");
		fclose(fptr1);
	}
	else{
		//Text file is located in VS/ProjectName
		fopen_s(&fptr1, "VSprojectsLastnFileRef1.txt", "r"); 
		int line = 1;
		int c = NULL;
		while (line <= toread){
			c = fgetc(fptr1);
			if (c == (int)'\n') line++;
			if (c == EOF) {
				printf("wrong input");
			}

		}

		c = NULL;
		while (c != EOF)
		{
			c = fgetc(fptr1);
			printf("%c", c); // printing on the screen
		}
		fclose(fptr1);

	}

	_getch();
}


/*fopen_s(&fptr,"VSprojectsLastnFileRef1.txt", "w+");
if (fptr == NULL){
printf("Error!");
return 0;
}
fputc(65, fptr);
fclose(fptr);*/