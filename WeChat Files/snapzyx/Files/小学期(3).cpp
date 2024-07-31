#include<stdio.h>
#include<process.h>
#include<string.h>
void Jingdianmingcheng();
void Shifouyoupiao();
void Jingdianquyu();
void Shifouzhekou();
struct tourist
{
	char tourist_ID[20];//游客团体ID
	char tourist_PASSWORD[20];//游客团体密码 
	char tourist_NUM[20];//游客团体人数 
	char tourist_AGE[20];//游客团体年龄层次 
	char tourist_PHONE[20];//游客团体联系人电话 
}touristList[80];
struct ScenicSpot
{
	char ScenicSpot_ID[80];//景点ID
	char ScenicSpot_NAME[80];//景点名称
	char ScenicSpot_INTRO[80];//景点简介
	int ScenicSpot_PRICE1;//景点旺季门票价格
	int ScenicSpot_PRICE2;//景点淡季门票价格
	char ScenicSpot_TIME[80];//游览该景点所需时间
	float ScenicSpot_DISCOUNT1;//学生折扣信息
	float ScenicSpot_DISCOUNT2;//军人折扣信息
	float ScenicSpot_DISCOUNT3;//普通折扣信息
	char ScenicSpot_GRADE[80];//景点级别
	char ScenicSpot_NUMBER[80];//人数限制
	char ScenicSpot_AREA[80];//景点所属区域
	char ScenicSpot_COST[80];//景点维护费用
	int ScenicSpot_MENPIAO;//景点总票 
}ScenicSpotList[80];
int main()
	{
	FILE *tourist_ID1,*tourist_PASSWORD1,*tourist_login;
	tourist_ID1=fopen("游客信息.txt","r");
	tourist_PASSWORD1=fopen("游客信息.txt","r");
	tourist_login=fopen("游客用户名.txt","w");
	int cal1=1,cal2,cal3=1,cal4,choose,panduan=1;
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
			}
	} 
	fclose(tourist_ID1);
	fclose(tourist_PASSWORD1);
	fclose(tourist_login);
	printf("欢迎进入系统：\n");
	printf("1.根据景点名称查询。\n2.根据是否有票查询。\n3.根据景点区域查询。\n4.根据是否有折扣查询.\n");
	scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				Jingdianmingcheng();
				panduan=0;
				break;
			case 2:
				Shifouyoupiao();
				panduan=0;
				break;
			case 3:
				Jingdianquyu();
				panduan=0;
				break;
			case 4:
				Shifouzhekou();
				panduan=0;
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose);
				break;
		}
	}
}
void Jingdianmingcheng()
{
	int cal1=1,cal2,cal3=1;
	FILE *Jingdian1;
	Jingdian1=fopen("景点信息.txt","r");
	char jingdianchaxun1[80]={"\0"};
	printf("请输入要查询的景点名称：\n");
	scanf("%s",jingdianchaxun1);
	fread(ScenicSpotList,sizeof(struct ScenicSpot),8,Jingdian1);//（暂时定为八个） 
	while(cal3!=0) 
	{
		for(cal2=0;cal2<8;cal2++)//（暂时定为八个） 
		{
		if(strcmp(jingdianchaxun1,ScenicSpotList[cal2].ScenicSpot_NAME)==0)//若文件中有输入的景点名称，则进入if条件 
			{
			printf("景点ID: "); 
		    puts(ScenicSpotList[cal2].ScenicSpot_ID);
	        printf("景点名称: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_NAME);
		    printf("景点简介: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_INTRO);
	        printf("景点旺季门票价格: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_PRICE1);
	        printf("景点淡季门票价格: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_PRICE2);
	        printf("游览该景点所需时间: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_TIME);
	        printf("学生折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_DISCOUNT1);
	        printf("军人折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_DISCOUNT2);
	        printf("普通折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_DISCOUNT3);
	        printf("景点级别: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_GRADE);
	        printf("人数限制: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_NUMBER);
	        printf("景点所属区域: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_AREA);
	        printf("景点维护费用:");
	        puts(ScenicSpotList[cal2].ScenicSpot_COST);	
			cal1=0;
			cal3=0;
			}
		}
			if(cal1!=0)
			{
			printf("您输入的景点名称有误，请重新输入：\n");
			scanf("%s",jingdianchaxun1);
			}
		}
	return;
}
void Shifouyoupiao()
{

}
void Jingdianquyu()
{
	int cal1=1,cal2,cal3=1;
	FILE *Jingdian3;
	Jingdian3=fopen("景点信息.txt","r");
	char jingdianchaxun3[80]={"\0"};
	printf("请输入要查询的景点区域：\n");
	scanf("%s",jingdianchaxun3);
	fread(ScenicSpotList,sizeof(struct ScenicSpot),8,Jingdian3);//（暂时定为八个） 
	while(cal3!=0) 
	{
		for(cal2=0;cal2<8;cal2++)//（暂时定为八个） 
		{
		if(strcmp(jingdianchaxun3,ScenicSpotList[cal2].ScenicSpot_AREA)==0)
			{
			printf("景点ID: "); 
		    puts(ScenicSpotList[cal2].ScenicSpot_ID);
	        printf("景点名称: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_NAME);
		    printf("景点简介: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_INTRO);
	        printf("景点旺季门票价格: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_PRICE1);
	        printf("景点淡季门票价格: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_PRICE2);
	        printf("游览该景点所需时间: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_TIME);
	        printf("学生折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_DISCOUNT1);
	        printf("军人折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_DISCOUNT2);
	        printf("普通折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_DISCOUNT3);
	        printf("景点级别: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_GRADE);
	        printf("人数限制: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_NUMBER);
	        printf("景点所属区域: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_AREA);
	        printf("景点维护费用:");
	        puts(ScenicSpotList[cal2].ScenicSpot_COST);	
			cal1=0;
			cal3=0;
			}
		}
			if(cal1!=0)
			{
			printf("您输入的景点区域有误，请重新输入：\n");
			scanf("%s",jingdianchaxun3);
			cal2=0;
			}
		}
	return;
}
void Shifouzhekou()
{
	
}
