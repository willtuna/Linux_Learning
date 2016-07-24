#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[] ){

		FILE *fp_in, *fp_out;
		
		if((fp_in = fopen( argv[1],"r"))== NULL)
		{
				printf("Can't open file: %s ! \n ", argv[1]);
				exit(1);
		}
		if( (fp_out=fopen("outputfile.txt","w"))== NULL)
		{
				fclose(fp_in);
				printf("can't open file : outputfile.txt");
				exit(1);
		}

		while( !feof(fp_in) )// feof() support both textfile and binary file
		{
				fputc(fgetc(fp_in),fp_out );


		}
		fclose(fp_in);
		fclose(fp_out);


return 0;






}

