#define _CRT_SECURE_NO_WARNINGS
#define BLOCK_SIZE 8192
#define BIT_VECTOR_SIZE 2000
#define IN_BIT_VECTOR_SIZE 140
#define BIT_VECTIOR_END 500
#define USERS 20
#define NUMBER_MESSAGE 3
#define MESSAGE_IN_BLOCK 16
#define INDIRECT1_MESSAGES 5
#define INDIRECT2 3
#define USER_OFFSET 2500
#define IN_BLOCK_BIT_VECTOR 160
#define CATEGORY_BIT_VECTOR 100
#define MESSAGE_ID_OFFSET 3000
#define BITVECTOR_OFFSET 0
#define CATEGORY_OFFSET 8192
#define DIRECT_OFFSET 16384
#define DIRECT_BITVECTOR_SIZE 1000
#define CONTENT_OFFSET 24576
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
// structs
struct vector{
	char free;
};
struct invector{
	char free;
};
struct user{
	int user_id;
};
struct message_count{
	int id;
};
struct messageId{
	int id;
};
struct user_count{
	int count;
};
struct message{
	int id;
	char text[128];
	int uid;
	int indirect;
};
struct category{
	int cid;
	int uid;
	int id;
	int messages[3];
	int indirect; //offset for the indirect one struct where it points to 5 more message_inodes
};
struct category_count{
	int count;
};
struct reply{
	char text[128];
	int uid;
	char dummy[8];
};
struct indirect1{
	int messages[INDIRECT1_MESSAGES];
};
void Error(char *msg){
	printf("worng %s..exting", msg);
	exit(1);
}
// declarations
void Init();
void Display_Main_Menu(int user_id);
void Enter_Category(int user_id);
void UpdateUserMeta(int uid);
void Display_Users();
void Display_Categories(int user_id);
int New_Message(struct category category, int category_offset, char *msg,int curr_user_id);
int PlaceMsgInCategory(struct category category, int msg_created_at);
int GetFreeIndirect();
void ReadMessages(struct category category);
int GetMessageId(int message_offset);
void PrintMessage(int offset);
void New_Reply(struct category category, int msg_id);
//
int GetMessageId(int message_offset){

	FILE *fp;
	struct message message;
	fp = fopen("data.bin", "r+b");
	fseek(fp, message_offset, SEEK_SET);
	fread(&message, sizeof(message), 1, fp);
	fclose(fp);
	return message.id;
}
void New_Reply(struct category category, int msg_id){

	FILE *fp;
	fp = fopen("data.bin", "r+b");
	int message_id;
	struct indirect1 indirect;
	int flag = 0;
	// go through the messages
	for (int i = 0; i < 3; i++){
		message_id = GetMessageId(category.messages[i]);
		if (message_id == msg_id){
			flag = 1;
			// enter the reply here
			break;
		}
	}
	if (category.indirect > 0 && flag == 0){
		// fseek to the indirect
		fread(&indirect, sizeof(indirect), 1, fp);
		for (int i = 0; i < INDIRECT1_MESSAGES; i++){
			if (indirect.messages[i] > 0){
				message_id = GetMessageId(indirect.messages[i]);
				if(message_id == msg_id){
					flag = 1;
					// enter the reply here
					break;
				}
			}
		}
	}
	else{
		Error("choice");
	}
	fclose(fp);
}
void PrintMessage(int offset){

	FILE *fp;
	fp = fopen("data.bin", "r+b");
	fseek(fp, offset, SEEK_SET);
	struct message message;
	fread(&message, sizeof(message), 1, fp);

	printf("%d. ", message.id);
	printf("%d  ", message.uid);
	printf("%s\n", message.text);

	fclose(fp);

}

void ReadMessages(struct category category){

	FILE *fp;
	struct category_count category_count;
	struct message message;
	struct indirect1 indirect;
	int category_offset;
	fp = fopen("data.bin", "r+b");	
	for (int j = 0; j < 3; j++){
		if (category.messages[j] > 0){
			PrintMessage(category.messages[j]);
		}
	}
	if (category.indirect > 0){
		// seek to the indirect offset and print the messages
		fseek(fp, category.indirect, SEEK_SET);
		fread(&indirect, sizeof(indirect), 1, fp);
		for (int i = 0; i < INDIRECT1_MESSAGES; i++){
			if (indirect.messages[i] > 0){
				PrintMessage(indirect.messages[i]);
			}
			
		}
	}
	
	int selection;
	int msg_selection;
	printf("do you wanna to add reply? press 1\n");
	scanf("%d", &selection);
	switch (selection)
	{
	case 1:
		// reply process starts
		printf("enter the message id\n");
		scanf("%d", &msg_selection);
		printf("replies come here");
		New_Reply(category, msg_selection);
		break;
	case 2:
		// should actually go back the menu
		// now exit
		break;
	default:
		Error("choice");
		break;
	}
	fclose(fp);
}
void read(){
	FILE *fp;
	struct category category;
	struct message message;
	int category_offset;
	fp = fopen("data.bin", "r+b");
	category_offset = CATEGORY_OFFSET + sizeof(struct category)*(2) + 4;
	fseek(fp, category_offset, SEEK_SET);
	fread(&category, sizeof(category), 1, fp);

	fseek(fp, category.messages[0], SEEK_SET);
	fread(&message, sizeof(message), 1, fp);
	fclose(fp);
}
int GetFreeIndirect(){

	//go to indirect offset search bit vector and find the free space and return the offset
	FILE *fp;
	struct vector vector;
	int indirect_offset;
	fp = fopen("data.bin", "r+b");
	fseek(fp, DIRECT_OFFSET, SEEK_SET);
	for (int i = 0; i < DIRECT_BITVECTOR_SIZE; i++){
		fread(&vector, sizeof(struct vector), 1, fp);
		if (vector.free == 0){
			indirect_offset = sizeof(indirect1)*i + DIRECT_OFFSET + DIRECT_BITVECTOR_SIZE;
			break;
		}
	}
	fclose(fp);
	return indirect_offset;
}
int New_Message(struct category category, int category_offset, char *msg, int curr_user_id){
	// returns the offset where the message is created
	struct vector vector;
	struct message new_message;
	struct message_count messageid;
	int main_block_message_creation_offset;
	int vector_offset;
	int in_block_message_creation_offset;
	FILE *fp;
	fp = fopen("data.bin", "r+b");
	// serach in main bit vector
	fseek(fp, BITVECTOR_OFFSET, SEEK_SET);
	for (int i = 0; i < BIT_VECTOR_SIZE; i++){
		fread(&vector, sizeof(struct vector), 1, fp);
		if (vector.free == 0){
			main_block_message_creation_offset = BLOCK_SIZE*i+(BLOCK_SIZE*3);
			break;
		}
	}
	//move the file to the blocl
	fseek(fp, main_block_message_creation_offset, SEEK_SET);
	// find free in the block using in_block_vector
	for (int i = 0; i < IN_BLOCK_BIT_VECTOR; i++){
		vector_offset = ftell(fp);
		fread(&vector, sizeof(struct vector), 1, fp);	
		if (vector.free == 0){
			in_block_message_creation_offset = main_block_message_creation_offset
				+IN_BLOCK_BIT_VECTOR+sizeof(struct message) * i;
			vector.free = 1;
			break;
		}
	}
	//update the in block bit vector
	fseek(fp, vector_offset, SEEK_SET);
	fwrite(&vector, sizeof(struct vector), 1, fp);
	// move the file in the block
	fseek(fp, in_block_message_creation_offset, SEEK_SET);
	// create the message here
	strcpy(new_message.text, msg);
	new_message.uid = curr_user_id;
	int anchor = ftell(fp);
	// fseek to the msg meta
	fseek(fp, MESSAGE_ID_OFFSET, SEEK_SET);
	fread(&messageid, sizeof(struct message_count), 1, fp);
	new_message.id = messageid.id;
	// update the message id
	fseek(fp, MESSAGE_ID_OFFSET, SEEK_SET);
	messageid.id += 1;
	fwrite(&messageid, sizeof(struct message_count), 1, fp);

	//write the actual message
	fseek(fp, anchor, SEEK_SET);
	fwrite(&new_message, sizeof(struct message), 1, fp);
	return in_block_message_creation_offset;

}
int PlaceMsgInCategory(struct category category, int msg_created_at){

	FILE *fp;
	struct indirect1 indirect;
	int in_categories_messages[5];
	int message_created_at;
	fp = fopen("data.bin", "r+b");
	int flag = 0;

	// find free in the category
	for (int i = 0; i < 3; i++){
		if (category.messages[i] < -1){
			// place the message offset here
			flag = 1;
			category.messages[i] = msg_created_at;
			break;
		}
	}
	
	// finding rthe indirect addressing 
	if (flag==0){
		int indirect_offset;
		// if indirect is <0 create a indirect and get the offset
		if (category.indirect < 0){
			indirect_offset = GetFreeIndirect();
			category.indirect = indirect_offset;
		}	
		//else go to the offset and place the message
		fseek(fp, category.indirect, SEEK_SET);
		fread(&indirect, sizeof(indirect1), 1, fp);
		// read the indirect and find the free place
		for (int i = 0; i < INDIRECT1_MESSAGES; i++){
			if (indirect.messages[i] == 0){
				indirect.messages[i] = msg_created_at;
				break;
			}
		}
	}
	//update indirect 
	fseek(fp, category.indirect, SEEK_SET);
	fwrite(&indirect, sizeof(indirect1), 1, fp);
	//update the category , go to offset my category.id
	int category_offset = CATEGORY_OFFSET + sizeof(struct category)*(category.id) + 4;
	fseek(fp, category_offset, SEEK_SET);
	fwrite(&category, sizeof(category), 1, fp);
	return 1;
}
void Display_Categories(int user_id){

	struct category_count category_count;
	struct category category;
	FILE *fp;
	int category_offset = BLOCK_SIZE;
	fp = fopen("data.bin", "r+b");
	fseek(fp, category_offset, SEEK_SET);
	fread(&category_count, sizeof(struct category_count), 1, fp);
	printf("userid\tcategory\n");
	for (int i = 0; i < category_count.count; i++){
		fread(&category, sizeof(struct category), 1, fp);
		printf("%d\t", category.uid);
		printf("%d\n", category.cid);
	}

	// display options.
	int selection;
	int msg_created_at;
	int sucess;
	printf("\nchoose a category for options:");
	scanf("%d", &selection);
	fseek(fp, category_offset, 0);
	fread(&category_count, sizeof(category_count), 1, fp);
	for (int i = 0; i < category_count.count; i++){
		int category_prev = ftell(fp);
		fread(&category, sizeof(struct category), 1, fp);
		if (category.cid == selection){
			// display options
			printf("1. enter new message\n");
			printf("2. view messages\n");
			int msg_selection;
			scanf("%d", &msg_selection);
			switch (msg_selection)
			{
			case 1:
				printf("enter the messgae");
				char msg[128];
				// check the count of character if more than 128 , call new message
				scanf("%s", &msg);
				 msg_created_at = New_Message(category, category_prev, msg,user_id);
				 sucess = PlaceMsgInCategory(category, msg_created_at);
				if (sucess == 1){
					
				}
				else Error("message creation");
				break;
			case 2:
				ReadMessages(category);
				break;
			default:
				break;
			}
		}
	}
	fclose(fp);
}
void Display_Users(){

	FILE *fp;
	fp = fopen("data.bin", "r+b");
	int user_offset = USER_OFFSET;
	fseek(fp, user_offset, SEEK_SET);
	struct user user;
	struct user_count user_count;
	fread(&user_count, sizeof(struct user_count), 1, fp);
	for (int i = 0; i < user_count.count; i++){
		fread(&user, sizeof(struct user), 1, fp);
		printf("%d.%d\n", i + 1, user.user_id);
	}
	fclose(fp);
}
void UpdateUserMeta(int uid){

	FILE *fp;
	fp = fopen("data.bin", "r+b");
	int user_offset = USER_OFFSET;
	struct user user;
	struct user_count user_count;
	fseek(fp, user_offset, SEEK_SET);
	fread(&user_count, sizeof(struct user_count), 1, fp);
	for (int i = 0; i < user_count.count; i++){
		fread(&user, sizeof(struct user), 1, fp);
		if (user.user_id == uid) return;
	}
	fseek(fp, user_offset, SEEK_SET);
	fread(&user_count, sizeof(struct user_count), 1, fp);
	fseek(fp, sizeof(user_count)*user_count.count, SEEK_CUR);
	user.user_id = uid;
	fwrite(&user, sizeof(struct user), 1, fp);

	// update count
	fseek(fp, user_offset, SEEK_SET);
	user_count.count += 1;
	fwrite(&user_count, sizeof(struct user_count), 1, fp);
	fclose(fp);
}
void Enter_Category(int user_id){

	printf("enter your category id\n");
	int new_id;
	scanf("%d", &new_id);

	int category_offset = CATEGORY_OFFSET;
	struct category category;
	struct category_count category_count;
	FILE *fp;
	fp = fopen("data.bin", "r+b");
	// read category count and offset to the last category

	fseek(fp, category_offset, SEEK_SET);
	fread(&category_count, sizeof(struct category_count), 1, fp);
	int in_category_offset = category_count.count*sizeof(struct category);
	fseek(fp, in_category_offset, SEEK_CUR);
	category.cid = new_id;
	category.uid = user_id;
	category.id = category_count.count;
	
	fwrite(&category, sizeof(struct category), 1, fp);

	//update category count
	fseek(fp, category_offset, SEEK_SET);
	category_count.count += 1;
	fwrite(&category_count, sizeof(struct category_count), 1, fp);
	fclose(fp);
}
void Display_Main_Main(int user_id){

	// main menu for users
	printf("1. enter category\n");
	printf("2. display categories\n");
	printf("3. display users\n");

	int selection;
	scanf("\n%d", &selection);
	switch (selection)
	{
	case 1:
		Enter_Category(user_id);
		break;
	case 2:
		Display_Categories(user_id);
		break;
	case 3:
		Display_Users();
	default:
		Error("choice");
	}
}
void main(){

	printf("enter the user id (< %d)", USERS);
	int uid;

	scanf("%d", &uid);
	UpdateUserMeta(uid);
	Display_Main_Main(uid);
	
	//read();
	_getch();
}