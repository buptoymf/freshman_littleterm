#include<stdio.h>
main()
{
	FILE *fp;
	fp=fopen("mima.txt","a");
	fputs("123456",fp);
	fclose(fp);
}
 
