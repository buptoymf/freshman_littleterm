//#include "stdafx.h"//If the vc++6.0, with this line.
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    int x;
    if((fp=fopen("123.txt","r"))==NULL)
	{
        printf("Open the file failure...\n");
        exit(0);
    }
    while(fscanf(fp,"%d%*[^0-9]",&x)>0)
        printf("%d",x);
    fclose(fp);
    printf("\n");
    return 0;
}
