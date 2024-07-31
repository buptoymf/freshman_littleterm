#include<stdio.h>

int main()
{


struct beixuanzhe
{
   char name[20];
   int  xuanpiao;
}sb1={"sb1",0},sb2={"sb2",0},sb3={"sb3",0};

printf("name=%s,xuanpiao=%d\n",sb1.name,sb1.xuanpiao);
printf("name=%s,xuanpiao=%d\n",sb2.name,sb2.xuanpiao);
printf("name=%s,xuanpiao=%d\n",sb3.name,sb3.xuanpiao);


return 0;
}
