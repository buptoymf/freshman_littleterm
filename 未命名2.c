#include<stdio.h>
int main()
{
	FILE *fp;
	fp=fopen("xxx.txt","a");
	fclose(fp);
	remove("xxx.txt");
	
	return 1;
}
