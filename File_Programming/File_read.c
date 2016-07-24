#include <stdio.h>
#include <stdlib.h>
#include "student_score.h"

long filesize(FILE * stream);



int main( int argc, char * argv[])
{
		FILE *fp;
		student_score  data = {0,"",' ',0,0};
   //	student_score *data = NULL;  // can't using pointer since you did't
   //	offer enough space for store the data

		int item_num=0;
		if( (fp = fopen(argv[1], "rb")) == NULL){
				printf("Read File Error");exit(1);
		}

		long int total_size,data_size;
		
		//printf("Filesize of %s is %ld bytes\n", argv[1], total_size= filesize(fp));
		
		printf("size of each data %ld \n------------\n\n",data_size= sizeof(student_score) );
		

		while(!feof(fp))
		{
		item_num = fread(&data, data_size, 1, fp);
		
		// printing item remained
		printf("Reading %d  item ......\n", item_num);
		printf("number: %d\nname: %s\ngender: %c\nage: %d\nscore: %f\n ------------\n",data.num,data.name,data.gender,data.age, data.score);
		
		
		
		//This part is for peeking to check the EOF encounter !!!
		char c;
		c = fgetc(fp);
		if(c == EOF) break;
		else ungetc(c, fp);
		}



		fclose(fp);
		return 0;
}


long filesize(FILE * stream)
{
		long curpos, length;

		curpos = ftell(stream);// store the current stream indicator position

		fseek(stream, 0L, SEEK_END); // offset 0L from SEEK_END
		length = ftell(stream);
		fseek(stream, curpos, SEEK_SET);// get back to the start position of the file

		return length;

}



