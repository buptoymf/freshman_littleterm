#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#define NUMBER 80
struct tourist
{
	char tourist_ID[20];//游客团体ID
	char tourist_PASSWORD[20];//游客团体密码 
	char tourist_NUM[20];//游客团体人数 
	char tourist_AGE[20];//游客团体年龄层次 
	char tourist_PHONE[20];//游客团体联系人电话 
}touristList[NUMBER];

void Youkedenglu()
{
	FILE *tourist_ID1,*tourist_PASSWORD1,*tourist_login;
	tourist_ID1=fopen("游客信息.txt","r");
	tourist_PASSWORD1=fopen("游客信息.txt","r");
	tourist_login=fopen("游客用户名.txt","w");
	int cal1=1,cal2,cal3=1,cal4,cal5=0;
	char tourist_ID2[20]={"\0"},tourist_PASSWORD2[20]={"\0"};
	printf("请输入用户名：\n");
	scanf("%s",tourist_ID2);
	fread(touristList,sizeof(struct tourist),5,tourist_ID1);
	//验证用户的用户名输入是否正确 
	while(cal3!=0)
	{
	for(cal2=0;cal2<5;cal2++)
		{
			if(strcmp(tourist_ID2,touristList[cal2].tourist_ID)==0)
			{
				cal1=0;
				cal3=0;
				cal4=cal2;
			}
		}
		   if(cal1!=0)
		  {
		  	printf("用户名输入不正确，请重新输入：\n"); 
		  	scanf("%s",tourist_ID2);
		  	cal2=0;
			}
	}
	cal1=1;
	cal3=1;
	fputs(tourist_ID2,tourist_login);
	printf("请输入密码：\n");
	scanf("%s",tourist_PASSWORD2);
	while(cal3!=0)	//验证该用户的密码输入是否正确 
	{
	for(cal2=0;cal2<5;cal2++)
		{
			if(strcmp(tourist_PASSWORD2,touristList[cal4].tourist_PASSWORD)==0)
			{
				cal1=0;
				cal3=0;
			}
		}
		   if(cal1!=0)
		  {
		  	printf("密码输入不正确，请重新输入：\n"); 
		  	scanf("%s",tourist_PASSWORD2);
		  	cal2=0;
		  	cal5++;
			}
			if(cal5 == 2)
			{
				printf("密码输入错误次数超过3次，请返回主界面重新登陆\n");
				mainmenu();
			}
	} 
	fclose(tourist_ID1);
	fclose(tourist_PASSWORD1);
	fclose(tourist_login);
//	jinruyoukegongneng();
}
