#include <stdio.h>
#include <stdlib.h>
#define LENGTH 128

int main (int argc, char * argv[] )
{
		FILE *fp1, *fp2;

		char string[LENGTH];

		if((fp1= fopen(argv[1],"r" )) == NULL )
		{
				printf("Can't Open File %s\n",argv[1]);
				exit(1);
		}
		if( (fp2 = fopen("string.txt","w")) == NULL )
		{
				fclose(fp1);
				printf("can't open file\n");
				exit(1);
		}

		while(fgets(string,LENGTH,fp1)!=NULL)
		{
				printf("%s", string);
				fputs(string, fp2);
				fputs("\n",fp2);
		}

		fclose(fp1);
		fclose(fp2);

}
