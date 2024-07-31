#include<stdio.h>
#include<process.h>
#include<string.h>
char administrator_ID2[20]={"\0"},administrator_PASSWORD2[20]={"\0"};
void guanliyuancaidan(); 
	void dingdanchaxun();
	void dingdantongji();
	void jingdianguanli();
		void  jingdianxinxichaxun();
		void  tianjiajingdianxinxi();
	void gerenxinxiguanli();
    	void  gerenxinxichaxun();
    	void  xiugaigerenxinxi();
struct administrator
{
	char administrator_ID[20];//系统管理员ID 
	char administrator_PASSWORD[20];//系统管理员密码 
	char administrator_PHONE[20];//系统管理员电话 
	char administrator_MAIL[20];//系统管理员邮箱 
}administratorList[80];
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
struct order
{
	char order_ID[20];//订单编号
	int order_YEAR;//订单年份 
	int order_MONTH;//订单月份 
	int order_DAY;//订单日 
	int order_HOUR;//订单小时 
	int order_MINNTE;//订单分钟 
	char order_NUMBER[20];//景点编号
	char order_TIME[20];//出行时间
	char order_AGE[20];//年龄段
	char order_PEOPLENUM[20];//人数
	char order_IDENTITY1[20];//学生身份
	char order_IDENTITY2[20];//军人身份
	char order_IDENTITY3[20];//普通身份
	float order_PRICE[20];//订单总价格
}orderList[80];
int main()
{
	FILE *administrator_ID1,*administrator_PASSWORD1;
	administrator_ID1=fopen("管理员信息.txt","r");
	administrator_PASSWORD1=fopen("管理员信息.txt","r");
	int cal1=1,cal2,cal3=1,cal4;
	
	printf("请输入管理员ID：\n");
	scanf("%s",administrator_ID2);
	fread(administratorList,sizeof(struct administrator),3,administrator_ID1);
	//验证用户的用户名输入是否正确 
	while(cal3!=0)
	{
	for(cal2=0;cal2<3;cal2++)
		{
			if(strcmp(administrator_ID2,administratorList[cal2].administrator_ID)==0)
			{
				cal1=0;
				cal3=0;
				cal4=cal2;
			}
		}
		   if(cal1!=0)
		  {
		  	printf("管理员ID输入不正确，请重新输入：\n"); 
		  	scanf("%s",administrator_ID2);
		  	cal2=0;
			}
	}
	cal1=1;
	cal3=1;
	printf("请输入密码：\n");
	scanf("%s",administrator_PASSWORD2);
	while(cal3!=0)	//验证该用户的密码输入是否正确 
	{
	for(cal2=0;cal2<3;cal2++)
		{
			if(strcmp(administrator_PASSWORD2,administratorList[cal4].administrator_PASSWORD)==0)
			{
				cal1=0;
				cal3=0;
			}
		}
		   if(cal1!=0)
		  {
		  	printf("密码输入不正确，请重新输入：\n"); 
		  	scanf("%s",administrator_PASSWORD2);
		  	cal2=0;
			}
	} 
	fclose(administrator_ID1);
	fclose(administrator_PASSWORD1);
	guanliyuancaidan();
}
void guanliyuancaidan()
{
	int choose,panduan=1;
   	printf("欢迎进入管理员系统：\n");
	printf("1.订单查询。\n2.订单统计。\n3.景点管理。\n4.个人信息管理。\n5.退出程序。\n");
	scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				dingdanchaxun();
				panduan=0; 
				break;
			case 2:
				dingdantongji();
				panduan=0;
				break;
			case 3:
				jingdianguanli();
				panduan=0;
				break;
			case 4:
			    gerenxinxiguanli();
				panduan=0;
				break;
			case 5:
				panduan=0;
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose);
				break;
		}
	}
}
void dingdanchaxun()
{
FILE  *fp;
        int  i,t,m=1,n=1;
        fp=fopen("订单信息.txt","rb");
        char dingdanchaxun1[80]={"\0"};
	    printf("请输入要查询的订单编号：\n");
		scanf("%s",dingdanchaxun1);
      for(i=0;fread(&orderList[i],sizeof(struct  order),1,fp)==1;i++)
        t=i;
		
		while(m!=0) 
	{
		for(i=0;i<t;i++)
		{
		if(strcmp(dingdanchaxun1,orderList[i].order_ID)==0)//若文件中有输入的订单编号，则进入if条件 
			{
			printf("订单编号: "); 
		    puts(orderList[i].order_ID);
	        printf("订单年份: ");
	        printf("%d\n",orderList[i].order_YEAR);
		    printf("订单月份: ");
	        printf("%d\n",orderList[i].order_MONTH);
	        printf("订单日: ");
	        printf("%d\n",orderList[i].order_DAY);
	        printf("订单小时: ");
	        printf("%d\n",orderList[i].order_HOUR);
	        printf("订单分钟: ");
	        printf("%d\n",orderList[i].order_MINNTE);
	        printf("景点编号: ");
	        puts(orderList[i].order_NUMBER);
	        printf("出行时间: ");
	        puts(orderList[i].order_TIME);
	        printf("年龄段: ");
	      	puts(orderList[i].order_AGE);
	        printf("人数: ");
	        puts(orderList[i].order_PEOPLENUM);
	        printf("学生身份: ");
	        puts(orderList[i].order_IDENTITY1);
	        printf("军人身份: ");
	        puts(orderList[i].order_IDENTITY2);
	        printf("普通身份:");
	        puts(orderList[i].order_IDENTITY3);
			printf("订单总价格:");
	        printf("%f",orderList[i].order_PRICE);	
			m=0;
			n=0;
			}
		}
			if(n!=0)
			{
			printf("您输入的订单编号有误，请重新输入：\n");
			scanf("%s",dingdanchaxun1);
			}
		}
		fclose(fp);
		void guanliyuancaidan();
}
void dingdantongji()
{
}
void jingdianguanli()
{
	int choose,panduan=1; 
	printf("1.景点信息查询。\n2.添加景点信息。\n3.返回上级菜单。\n");
	scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				jingdianxinxichaxun();
				panduan=0; 
				break;
			case 2:
				tianjiajingdianxinxi(); 
				panduan=0; 
				break;
			case 3:
				guanliyuancaidan(); 
				panduan=0; 
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose);
				break;
		}
	}
}
void  jingdianxinxichaxun()
{
	FILE  *fp;
        int  i,t,m=1,n=1;
        fp=fopen("景点信息.txt","rb");
        char jingdianchaxun1[80]={"\0"};
	    printf("请输入要查询的景点名称：\n");
		scanf("%s",jingdianchaxun1);
      for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)==1;i++)
        t=i;
		
		while(m!=0) 
	{
		for(i=0;i<t;i++)
		{
		if(strcmp(jingdianchaxun1,ScenicSpotList[i].ScenicSpot_NAME)==0)//若文件中有输入的景点名称，则进入if条件 
			{
			printf("景点ID: "); 
		    puts(ScenicSpotList[i].ScenicSpot_ID);
	        printf("景点名称: ");
	        puts(ScenicSpotList[i].ScenicSpot_NAME);
		    printf("景点简介: ");
	        puts(ScenicSpotList[i].ScenicSpot_INTRO);
	        printf("景点旺季门票价格: ");
	        printf("%d\n",ScenicSpotList[i].ScenicSpot_PRICE1);
	        printf("景点淡季门票价格: ");
	        printf("%d\n",ScenicSpotList[i].ScenicSpot_PRICE2);
	        printf("游览该景点所需时间: ");
	        puts(ScenicSpotList[i].ScenicSpot_TIME);
	        printf("学生折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[i].ScenicSpot_DISCOUNT1);
	        printf("军人折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[i].ScenicSpot_DISCOUNT2);
	        printf("普通折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[i].ScenicSpot_DISCOUNT3);
	        printf("景点级别: ");
	        puts(ScenicSpotList[i].ScenicSpot_GRADE);
	        printf("人数限制: ");
	        puts(ScenicSpotList[i].ScenicSpot_NUMBER);
	        printf("景点所属区域: ");
	        puts(ScenicSpotList[i].ScenicSpot_AREA);
	        printf("景点维护费用:");
	        puts(ScenicSpotList[i].ScenicSpot_COST);
			printf("\n");	
			m=0;
			n=0;
			}
		}
			if(n!=0)
			{
			printf("您输入的景点名称有误，请重新输入：\n");
			scanf("%s",jingdianchaxun1);
			}
		}
		fclose(fp);
		jingdianguanli();
}
void  tianjiajingdianxinxi()
{
FILE  *fp;
        fp=fopen("景点信息.txt","ab+"); 
		int i,a=1,cal1=1,cal2,cal3=1;      
        for(int i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)==1;i++);
        i=i+1;
        for(a==1;a==1;i++){
        printf("请输入景点ID\n"); 
        scanf("%s",ScenicSpotList[i].ScenicSpot_ID);
        printf("请输入景点名称\n");
        scanf("%s",ScenicSpotList[i].ScenicSpot_NAME);
        printf("请输入景点简介\n");
        scanf("%s",ScenicSpotList[i].ScenicSpot_INTRO);
        printf("请输入景点旺季门票价格\n");
        scanf("%d",&ScenicSpotList[i].ScenicSpot_PRICE1);
        printf("请输入景点淡季门票价格\n");
        scanf("%d",&ScenicSpotList[i].ScenicSpot_PRICE2);
        printf("请输入游览该景点所需时间\n");
        scanf("%s",ScenicSpotList[i].ScenicSpot_TIME);
        printf("请输入学生折扣信息\n");
        scanf("%f",&ScenicSpotList[i].ScenicSpot_DISCOUNT1);
        printf("请输入军人折扣信息\n");
        scanf("%f",&ScenicSpotList[i].ScenicSpot_DISCOUNT2);
        printf("请输入普通折扣信息\n");
        scanf("%f",&ScenicSpotList[i].ScenicSpot_DISCOUNT3);
        printf("请输入景点级别\n");
        scanf("%s",ScenicSpotList[i].ScenicSpot_GRADE);
        printf("请输入人数限制\n");
        scanf("%s",ScenicSpotList[i].ScenicSpot_NUMBER);
        printf("请输入景点所属区域\n");
        scanf("%s",ScenicSpotList[i].ScenicSpot_AREA);
        printf("请输入景点维护费用\n");
        scanf("%s",ScenicSpotList[i].ScenicSpot_COST);
        printf("请输入门票总票数\n");
        scanf("%d",&ScenicSpotList[i].ScenicSpot_MENPIAO);
		fwrite(&ScenicSpotList[i],sizeof(ScenicSpot),1,fp);
        printf("是否继续添加？\n1.是\n2.否\n");
        scanf("%d",&a);}
                fclose(fp);
        jingdianguanli();
        
        // int e;
        //printf("请确认景点信息是否有误\n1.修改\n2.取消添加\n3.发布\n");
        //scanf("%d",&e);
        //if(e==1){}
        //if(e==2){}
        //if(e==3)		
        }
void gerenxinxiguanli()
{
	int choose,panduan=1; 
	printf("1.个人信息查询。\n2.修改个人信息。\n3.返回上级菜单。\n");
	scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				gerenxinxichaxun();
				panduan=0; 
				break;
			case 2:
				xiugaigerenxinxi(); 
				panduan=0; 
				break;
			case 3:
				guanliyuancaidan();
				panduan=0; 
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose);
				break;
		}
	}
}
void  gerenxinxichaxun()
{
		FILE  *fp;
        
        fp=fopen("管理员信息.txt","rb");        
       
        printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
        printf("                         查询结果\n");
        printf("------------------------------------------------------------------\n");
        printf("管理员ID\t管理员密码\t管理员电话\t管理员邮箱\n");
		printf("------------------------------------------------------------------\n"); 
		for(int i=0;fread(&administratorList[i],sizeof(struct  administrator),1,fp)==1;i++)
        	if(strcmp(administratorList[i].administrator_ID,administrator_ID2)==0)
        	{
				printf("%s\t%s\t",administratorList[i].administrator_ID,administratorList[i].administrator_PASSWORD);
			    printf("%s\t%s\n",administratorList[i].administrator_PHONE,administratorList[i].administrator_MAIL);
			}
		printf("------------------------------------------------------------------\n\n");
        printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n\n\n");
        fclose(fp);
        guanliyuancaidan();
}	
void xiugaigerenxinxi()
{	
FILE  *fp;
	fp=fopen("管理员信息.txt","rb"); 
    int  i,n;
    int  flag=0;
	char a[20],b[20];        
    for(i=0;fread(&administratorList[i],sizeof(struct  administrator),1,fp)==1;i++)
    if(strcmp(administratorList[i].administrator_ID,administrator_ID2)==0)
	{
        n=i;
        flag=1;          
	}
	fclose(fp); 
    if(flag==0)
	{
        printf("输入错误!\n");
        printf("请返回!\n");
        return;
    }   
	printf("\n\n\n");  
	fp=fopen("管理员信息.txt","rb+");
	//strcpy(a->administrator_ID,administratorList[n].administrator_ID);
	//strcpy(a->administrator_PHONE,administratorList[n].administrator_PHONE);
	//administratorList[n].administrator_PASSWORD=NULL;
	//administratorList[n].administrator_MAIL=NULL;
    fseek(fp,n*sizeof(struct  administrator),0);
    printf("请输入新的密码及邮箱\n"); 
	scanf("%s%s",&a,&b);
	strncpy(administratorList[n].administrator_PASSWORD,a,20);
	strncpy(administratorList[n].administrator_MAIL,b,20);
	for(i=0;i<80;i++)
	{
		fwrite(&administratorList[i],sizeof(administrator),1,fp);
	}
    fclose(fp); 
    guanliyuancaidan();
}
