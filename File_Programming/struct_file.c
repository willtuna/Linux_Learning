

#include <stdio.h>
#include <stdlib.h>
#define NAME_LENGTH 32

typedef struct stu
{
		int num;
		char name[NAME_LENGTH];
		char gender;
		int age;
		float score;

}  student_score;




int main(int argc , char *argv[])
{
		struct stu student;
		char numstr[NAME_LENGTH], ch;// for temporary usage
		
		FILE *fp;

		if((fp = fopen("score_book.txt","wb"))==NULL)
		{
				printf("can't open score_book.txt\n");
				exit(1);
		}


		do{
				printf("Enter student number :");
				gets(numstr); 
				student.num = atoi(numstr);

				printf("Enter student name :");
				gets(student.name );

				printf("Enter gender:  ");
				student.gender = getchar();
				getchar(); // process the carriage return

				printf("enter age :");
				gets(numstr);
				student.age = atoi(numstr);

				printf("enter score ：");
				gets(numstr);
				student.score = atof(numstr);



				fwrite( &student, sizeof(struct stu), 1 ,fp);
				//      buffer    size               count file
				
				printf("Do you have other student record (y/n) ?");
				ch =getchar();
				getchar();// process carriage return


		}while(toupper(ch)=='Y');

		fclose(fp);


		return 0;
}


