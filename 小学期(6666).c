#include<stdio.h>
#include<process.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>

#define NUMBER 80
//主菜单 
void mainmenu()
{
	printf("\n\n\t**************Main Menu**************\n");
	printf("\t*            1.游客登陆             *\n");
	printf("\t*            2.管理员登陆           *\n");
	printf("\t*            3.关闭系统             *\n");
	printf("\t*************************************\n");
}
void jinruyoukegongneng();
void Jingdianmingcheng();
void Shifouyoupiao();
void Jingdianquyu();
void Shifouzhekou();
void Youkedenglu();
void Jingdianchaxun();
void piaojiapaixu();
void yudingliangpaixu();
void haopingpaixu();
void yudingjingdianmenpiao();
void outputinfo();
void deleteinfo();
void Guanliyuandenglu();
void guanliyuancaidan();
void jingdianguanli();
void tianjiajingdianxinxi(); 
void dingdanchaxun();
void jingdianxinxichaxun();
void gerenxinxichaxun();
void xiugaigerenxinxi();
void youkexiugaigerenxinxi();
void dingdantongji();
void yudingliangpaixu1();

void lirunpaixu();
void age();
//订单信息结构体 
struct info_list
{
	char order_ID1[20];//游客ID 
	char order_NUMBER[20];//景点ID 
	int order_IDENTITY1;//学生身份
	int order_IDENTITY2;//军人身份
	int order_IDENTITY3;//普通身份
	char order_AGE[20];//年龄段
	int order_PEOPLENUM;//人数
	int order_YEAR;//订单年份 
	int order_MONTH;//订单月份 
	int order_DAY;//订单日 
	int order_HOUR;//订单小时
	int order_MINUTE;//订单分钟
	char order_ID[20];//订单编号（游客ID+订票时间） 
	float order_PRICE;//订单总价格
	char order_jidu[20];//订单所属季度 
	
}info[NUMBER];

//显示订单信息 
void show(int n)
{
	
	int i;
	
	
//	printf("您的订单信息如下：\n");
	
	for(i=0;i<n;i++)
	{

//	printf("景点ID：%s\n",info[i].order_NUMBER);
//	printf("学生人数：%d\n",info[i].order_IDENTITY1);
//	printf("军人人数：%d\n",info[i].order_IDENTITY2);
//	printf("普通游客人数：%d\n",info[i].order_IDENTITY3);
//	printf("游客年龄层次：%s\n",info[i].order_AGE);
//	printf("总人数（订票数量）：%d\n",info[i].order_PEOPLENUM);
//	printf("订票时间（年）：%d\n",info[i].order_YEAR);
//	printf("订票时间（月）：%d\n",info[i].order_MONTH);
//	printf("订票时间（日）：%d\n",info[i].order_DAY);
//	printf("订票时间（时）：%d\n",info[i].order_HOUR);
//	printf("订票时间（分）：%d\n",info[i].order_MINUTE);
	printf("您的订单编号是：%s\n",info[i].order_ID);
	
}
	printf("\n");
	
	printf("订票成功！您的订单信息已保存。系统重启后生效。\n");
	
}


// 计算订单信息的函数 
int countline()
{
    FILE *pf = fopen("订单信息.dat", "rb");
    char buf[1000];
    int c=0;
    
    if (!pf)
    
    return 0;
        
    while (fgets(buf, 1000, pf))
    c++;
    
    fclose(pf);
    
    return c;
}
//游客信息结构体 
struct tourist
{
	char tourist_ID[20];//游客团体ID
	char tourist_PASSWORD[20];//游客团体密码 
	char tourist_NUM[20];//游客团体人数 
	char tourist_AGE[20];//游客团体年龄层次 
	char tourist_PHONE[20];//游客团体联系人电话 
}touristList[NUMBER];
//管理员信息结构体 
struct administrator
{
	char administrator_ID[20];//系统管理员ID 
	char administrator_PASSWORD[20];//系统管理员密码 
	char administrator_PHONE[20];//系统管理员电话 
	char administrator_MAIL[20];//系统管理员邮箱 
}administratorList[NUMBER];
//景点信息结构体 
struct  ScenicSpot
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
	int ScenicSpot_COST;//景点维护费用
	int ScenicSpot_MENPIAO;//景点总票 
	int ScenicSpot_VISIT;//景点访问人数 
	int ScenicSpot_YUDING;//景点预定量 
	float ScenicSpot_HAOPING;//景点好评率 
	char ScenicSpot_LRET[80];//是否适宜老人儿童 
}ScenicSpotList[NUMBER],ScenicSpotList2[NUMBER];

//主函数  主登陆界面 
int main()
{
	int choose,panduan=1;
	mainmenu();
	printf("请选择您要执行的选项:\n");
	scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				Youkedenglu();
				panduan=0;
				break;
			case 2:
				Guanliyuandenglu();
				panduan=0;
				break;
			case 3:
				panduan=0;
				exit(0);
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose);
				break;
		}
	}
	return 0;
}

//游客用户名与密码输入 
void Youkedenglu()
{
	FILE *tourist_ID1,*tourist_PASSWORD1,*tourist_login;
	tourist_ID1=fopen("游客信息.dat","rb");
	tourist_PASSWORD1=fopen("游客信息.dat","rb");
	tourist_login=fopen("游客用户名和密码备份.dat","w");
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
				fputs(tourist_PASSWORD2,tourist_login);
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
				cal1=0;
				cal3=0;
			}
	} 
	fclose(tourist_ID1);
	fclose(tourist_PASSWORD1);
	fclose(tourist_login);
	jinruyoukegongneng();
}
//游客登陆界面 
void jinruyoukegongneng()
{
	int choose,panduan=1;
		printf("欢迎进入系统，请选择您要执行的功能： \n");
	printf("\n\n\t**************Main Menu******************\n");
	printf("\t*            1.景点查询                 *\n");
	printf("\t*            2.预定景点门票             *\n");
	printf("\t*            3.信息管理                 *\n");
	printf("\t*            4.取消预定                 *\n");
	printf("\t*            5.查询预定门票             *\n");
	printf("\t*            6.退出                     *\n");
	printf("\t*****************************************\n");
	scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				Jingdianchaxun();
				panduan=0;
				break;
			case 2:
				yudingjingdianmenpiao();
				panduan=0;
				break;
			case 3:
				//youkexiugaigerenxinxi();
				panduan=0;
				break;
			case 4:
				deleteinfo();
				panduan=0;
				break;
			case 5:
				outputinfo();
				panduan=0;
				break;
			case 6:
				panduan=0;
				exit(0);
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose);
				break;
		}
	}
}
//景点查询界面 
void Jingdianchaxun()
{
	int choose,panduan=1;
	printf("1.根据景点名称查询。\n2.根据是否有票查询。\n3.根据景点区域查询。\n4.根据是否有折扣查询。\n5.根据价格排序所有景点。\n6.根据预定量排序所有景点。\n7.根据好评率排序所有景点。\n");
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
			case 5:
				piaojiapaixu();
				panduan=0;
				break;
			case 6:
				yudingliangpaixu();
				panduan=0;
				break;
			case 7:
				haopingpaixu();
				panduan=0;
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose);
				break;
		}
	}
}


// 根据景点名称查询 
void Jingdianmingcheng()
{
	int cal1=1,cal2,cal3=1,cal4;
	FILE *Jingdian1;
	Jingdian1=fopen("景点信息.dat","rb");
	char jingdianchaxun1[80]={"\0"};
	printf("请输入要查询的景点名称：\n");
	scanf("%s",jingdianchaxun1);
	for(cal4=0;fread(&ScenicSpotList[cal4],sizeof(struct  ScenicSpot),1,Jingdian1)!=0;cal4++);
//	fread(ScenicSpotList,sizeof(struct ScenicSpot),8,Jingdian1);//（暂时定为八个） 
	while(cal3!=0) 
	{
		for(cal2=0;cal2<cal4;cal2++)//（暂时定为八个） 
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
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_COST);	
	        printf("景点剩余票数: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_MENPIAO);
	     //   printf("景点访问人数: ");
	     //   printf("%d\n",ScenicSpotList[cal2].ScenicSpot_VISIT);
	        printf("景点预定量: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_YUDING);
	        printf("景点好评率: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_HAOPING);
	        printf("是否适宜老人儿童: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_LRET);
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
		printf("请问您是否需要订票？\n1.需要\n2.返回功能界面\n");
		int choose,panduan=1;
		scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				yudingjingdianmenpiao();
				panduan=0;
				break;
			case 2:
				jinruyoukegongneng();
				panduan=0;
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose);
				break;
		}
	}
			
		
	return;
}
//根据是否有票查询 
void Shifouyoupiao()
{
	FILE *fp;
	fp=fopen("景点信息.dat","rb");
	int cal1,cal2;
	for(cal1=0;fread(&ScenicSpotList[cal1],sizeof(struct  ScenicSpot),1,fp)!=0;cal1++);
	for(cal2=0;cal2<cal1;cal2++)
	{
		if(ScenicSpotList[cal2].ScenicSpot_MENPIAO > 0)
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
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_COST);	
	        printf("景点剩余票数: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_MENPIAO);
	     //   printf("景点访问人数: ");
	     //   printf("%d\n",ScenicSpotList[cal2].ScenicSpot_VISIT);
	        printf("景点预定量: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_YUDING);
	        printf("景点好评率: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_HAOPING);
	        printf("是否适宜老人儿童: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_LRET);
	        printf("\n");
		}
	}
	
			printf("请问您是否需要订票？\n1.需要\n2.返回功能界面\n");
		int choose,panduan=1;
		scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				yudingjingdianmenpiao();
				panduan=0;
				break;
			case 2:
				jinruyoukegongneng();
				panduan=0;
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose);
				break;
		}
	}
			
		
	return;
}
//根据景点区域查询 
void Jingdianquyu()
{
	int cal1=1,cal2,cal3=1;
	FILE *Jingdian3;
	Jingdian3=fopen("景点信息.dat","rb");
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
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_COST);	
	        printf("景点剩余票数: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_MENPIAO);
	     //   printf("景点访问人数: ");
	     //   printf("%d\n",ScenicSpotList[cal2].ScenicSpot_VISIT);
	        printf("景点预定量: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_YUDING);
	        printf("景点好评率: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_HAOPING);
	        printf("是否适宜老人儿童: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_LRET);
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
			printf("请问您是否需要订票？\n1.需要\n2.返回功能界面\n");
		int choose,panduan=1;
		scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				yudingjingdianmenpiao();
				panduan=0;
				break;
			case 2:
				jinruyoukegongneng();
				panduan=0;
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose);
				break;
		}
	}
	return;
}
//根据是否折扣查询 
void Shifouzhekou()
{
			int cal1,cal3,cal5,cal7=1,choose;
	FILE *Jingdian4;
	Jingdian4=fopen("景点信息.dat","rb");
	fread(ScenicSpotList,sizeof(struct ScenicSpot),8,Jingdian4);//（暂时定为八个） 
	printf("请问您要查询哪类折扣信息：\n1.学生\n2.军人\n3.普通人\n ");
		scanf("%d",&choose);
	while(cal7!=0) 
	{
		switch(choose)
		{
			case 1:
				for(cal1=0;cal1<8;cal1++)//（暂时定为八个） 
			{
			//	fscanf(Jingdian4,"%.1f",&ScenicSpotList[cal1].ScenicSpot_DISCOUNT1);
				if(ScenicSpotList[cal1].ScenicSpot_DISCOUNT1 < 1)
				{
			printf("景点ID: "); 
		    puts(ScenicSpotList[cal1].ScenicSpot_ID);
	   	    printf("景点名称: ");
	        puts(ScenicSpotList[cal1].ScenicSpot_NAME);
		    printf("景点简介: ");
	     	puts(ScenicSpotList[cal1].ScenicSpot_INTRO);
	     	printf("景点旺季门票价格: ");
	        printf("%d\n",ScenicSpotList[cal1].ScenicSpot_PRICE1);
	        printf("景点淡季门票价格: ");
	        printf("%d\n",ScenicSpotList[cal1].ScenicSpot_PRICE2);
	        printf("游览该景点所需时间: ");
	        puts(ScenicSpotList[cal1].ScenicSpot_TIME);
	        printf("学生折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[cal1].ScenicSpot_DISCOUNT1);
	        printf("军人折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[cal1].ScenicSpot_DISCOUNT2);
	        printf("普通折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[cal1].ScenicSpot_DISCOUNT3);
	        printf("景点级别: ");
	        puts(ScenicSpotList[cal1].ScenicSpot_GRADE);
	        printf("人数限制: ");
	        puts(ScenicSpotList[cal1].ScenicSpot_NUMBER);
	        printf("景点所属区域: ");
	        puts(ScenicSpotList[cal1].ScenicSpot_AREA);
	        printf("景点维护费用:");
	        printf("%d\n",ScenicSpotList[cal1].ScenicSpot_COST);	
	        printf("景点剩余票数: ");
	        printf("%d\n",ScenicSpotList[cal1].ScenicSpot_MENPIAO);
	     //   printf("景点访问人数: ");
	     //   printf("%d\n",ScenicSpotList[cal1].ScenicSpot_VISIT);
	        printf("景点预定量: ");
	        printf("%d\n",ScenicSpotList[cal1].ScenicSpot_YUDING);
	        printf("景点好评率: ");
	        printf("%.2f\n",ScenicSpotList[cal1].ScenicSpot_HAOPING);
	        printf("是否适宜老人儿童: ");
	        puts(ScenicSpotList[cal1].ScenicSpot_LRET);
	        printf("\n");
			}
			}
			cal7=0;
			break;
			case 2:
				for(cal3=0;cal3<8;cal3++)//（暂时定为八个） 
			{
			//	fscanf(Jingdian4,"%.1f",&ScenicSpotList[cal3].ScenicSpot_DISCOUNT2);
			if(ScenicSpotList[cal3].ScenicSpot_DISCOUNT2 < 1)
			{
			printf("景点ID: "); 
		    puts(ScenicSpotList[cal3].ScenicSpot_ID);
	        printf("景点名称: ");
	        puts(ScenicSpotList[cal3].ScenicSpot_NAME);
		    printf("景点简介: ");
	        puts(ScenicSpotList[cal3].ScenicSpot_INTRO);
	        printf("景点旺季门票价格: ");
	        printf("%d\n",ScenicSpotList[cal3].ScenicSpot_PRICE1);
	        printf("景点淡季门票价格: ");
	        printf("%d\n",ScenicSpotList[cal3].ScenicSpot_PRICE2);
	        printf("游览该景点所需时间: ");
	        puts(ScenicSpotList[cal3].ScenicSpot_TIME);
	        printf("学生折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[cal3].ScenicSpot_DISCOUNT1);
	        printf("军人折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[cal3].ScenicSpot_DISCOUNT2);
	        printf("普通折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[cal3].ScenicSpot_DISCOUNT3);
	        printf("景点级别: ");
	        puts(ScenicSpotList[cal3].ScenicSpot_GRADE);
	        printf("人数限制: ");
	        puts(ScenicSpotList[cal3].ScenicSpot_NUMBER);
	        printf("景点所属区域: ");
	        puts(ScenicSpotList[cal3].ScenicSpot_AREA);
	        printf("景点维护费用:");
	        printf("%d\n",ScenicSpotList[cal3].ScenicSpot_COST);	
	        printf("景点剩余票数: ");
	        printf("%d\n",ScenicSpotList[cal3].ScenicSpot_MENPIAO);
	     //   printf("景点访问人数: ");
	     //   printf("%d\n",ScenicSpotList[cal3].ScenicSpot_VISIT);
	        printf("景点预定量: ");
	        printf("%d\n",ScenicSpotList[cal3].ScenicSpot_YUDING);
	        printf("景点好评率: ");
	        printf("%.2f\n",ScenicSpotList[cal3].ScenicSpot_HAOPING);
	        printf("是否适宜老人儿童: ");
	        puts(ScenicSpotList[cal3].ScenicSpot_LRET);
	        printf("\n");
			}
			}
			cal7=0;
			break;
			case 3:
					for(cal5=0;cal5<8;cal5++)//（暂时定为八个） 
			{
			//	fscanf(Jingdian4,"%.1f",&ScenicSpotList[cal5].ScenicSpot_DISCOUNT3);
			if(ScenicSpotList[cal5].ScenicSpot_DISCOUNT3 < 1)
			{
			printf("景点ID: "); 
		    puts(ScenicSpotList[cal5].ScenicSpot_ID);
	        printf("景点名称: ");
	        puts(ScenicSpotList[cal5].ScenicSpot_NAME);
		    printf("景点简介: ");
	        puts(ScenicSpotList[cal5].ScenicSpot_INTRO);
	        printf("景点旺季门票价格: ");
	        printf("%d\n",ScenicSpotList[cal5].ScenicSpot_PRICE1);
	        printf("景点淡季门票价格: ");
	        printf("%d\n",ScenicSpotList[cal5].ScenicSpot_PRICE2);
	        printf("游览该景点所需时间: ");
	        puts(ScenicSpotList[cal5].ScenicSpot_TIME);
	        printf("学生折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[cal5].ScenicSpot_DISCOUNT1);
	        printf("军人折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[cal5].ScenicSpot_DISCOUNT2);
	        printf("普通折扣信息: ");
	        printf("%.2f\n",ScenicSpotList[cal5].ScenicSpot_DISCOUNT3);
	        printf("景点级别: ");
	        puts(ScenicSpotList[cal5].ScenicSpot_GRADE);
	        printf("人数限制: ");
	        puts(ScenicSpotList[cal5].ScenicSpot_NUMBER);
	        printf("景点所属区域: ");
	        puts(ScenicSpotList[cal5].ScenicSpot_AREA);
	        printf("景点维护费用:");
	        printf("%d\n",ScenicSpotList[cal5].ScenicSpot_COST);	
	        printf("景点剩余票数: ");
	        printf("%d\n",ScenicSpotList[cal5].ScenicSpot_MENPIAO);
	     //   printf("景点访问人数: ");
	     //   printf("%d\n",ScenicSpotList[cal5].ScenicSpot_VISIT);
	        printf("景点预定量: ");
	        printf("%d\n",ScenicSpotList[cal5].ScenicSpot_YUDING);
	        printf("景点好评率: ");
	        printf("%.2f\n",ScenicSpotList[cal5].ScenicSpot_HAOPING);
	        printf("是否适宜老人儿童: ");
	        puts(ScenicSpotList[cal5].ScenicSpot_LRET);
	        printf("\n");
			}
			}
			cal7=0;
			break;
			default:
				printf("您输入的查询数字有误，请重新输入：\n");
				scanf("%d",&choose); 
			}
		}
					printf("请问您是否需要订票？\n1.需要\n2.返回功能界面\n");
		int choose1,panduan=1;
		scanf("%d",&choose1);
	while(panduan!=0)
	{
		switch(choose1)
		{
			case 1:
				yudingjingdianmenpiao();
				panduan=0;
				break;
			case 2:
				jinruyoukegongneng();
				panduan=0;
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose);
				break;
		}
	}
	return;
}
//根据票价排序 
void piaojiapaixu()
{
   FILE *fp;
   fp=fopen("景点信息.dat","rb");//打开文件“景点信息” 
    int i,j,k,choose,panduan=1;
    int n; 
    for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  

	//引入文件中景点数据,计算景点个数 ,i是景点个数 
	/*for(n=0;n<i;n++)
    fread(&ScenicSpotList[n],sizeof(struct  ScenicSpot),i,fp);*/
	
	printf("请问您是要查看淡季票价排序还是旺季票价排序:\n1.淡季票价排序.\n2.旺季票价排序.\n");
	scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				 for(n=1;n<i;n++)
  					 {
   						  k=ScenicSpotList[n].ScenicSpot_PRICE1;
    					  ScenicSpotList2[n-1]=ScenicSpotList[n];
     					  j=n-1;
      					  while((j>=0)&&(ScenicSpotList[j].ScenicSpot_PRICE1>k))
     						 {
     				  		 	ScenicSpotList[j+1].ScenicSpot_PRICE1=ScenicSpotList[j].ScenicSpot_PRICE1;
     						    ScenicSpotList[j+1]=ScenicSpotList[j];         
  						        j--;
  						   	 }
  						  ScenicSpotList[j+1].ScenicSpot_PRICE1=k;
   						  ScenicSpotList[j+1]=ScenicSpotList2[n-1];

  					 }
 					 printf("   景点名称          景点ID         淡季票价\n");
 				for(n=0;n<i;n++)
 						 {       
  					         printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_PRICE1);
   						 }
   			  fclose(fp);
			  panduan=0;
			  break;
			case 2:
				for(n=1;n<i;n++)
  					 {
   						  k=ScenicSpotList[n].ScenicSpot_PRICE2;
    					  ScenicSpotList2[n-1]=ScenicSpotList[n];
     					  j=n-1;
      					  while((j>=0)&&(ScenicSpotList[j].ScenicSpot_PRICE2>k))
     						 {
     				  		 	ScenicSpotList[j+1].ScenicSpot_PRICE2=ScenicSpotList[j].ScenicSpot_PRICE2;
     						    ScenicSpotList[j+1]=ScenicSpotList[j];         
  						        j--;
  						   	 }
  						  ScenicSpotList[j+1].ScenicSpot_PRICE2=k;
   						  ScenicSpotList[j+1]=ScenicSpotList2[n-1];

  					 }
 					 printf("   景点名称          景点ID          旺季票价\n");
 				for(n=0;n<i;n++)
 						 {       
  					         printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_PRICE2);
   						 }
   			  fclose(fp);
				panduan=0;
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose);
				break;
		}
	}
				printf("请问您是否需要订票？\n1.需要\n2.返回功能界面\n");
		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				yudingjingdianmenpiao();
				panduan1=0;
				break;
			case 2:
				jinruyoukegongneng();
				panduan1=0;
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose);
				break;
		}
	}
	return;
 }
//根据预定量排序 
void yudingliangpaixu()
{

   FILE *fp,*fp2;
   fp=fopen("景点信息.dat","rb");//打开文件“景点信息” 
    int i,j,n;
     for(i=0;fread(&ScenicSpotList2[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);
     //将“景点名称”中信息赋值给 ScenicSpotList2
    fp2=fopen("订单信息.dat","rb");//打开文件订单信息 
    int i2;//i2为订单个数 
     for(i2=0;fread(&info[i2],sizeof(struct info_list),1,fp2)!=0;i2++);
     //计算订单个数 
    int yu[80];
      for(n=0;n<i;n++)
	   yu[n]=0;//为预定量建立数组 
    //strcmp(dsfsfs,dfdfd)
     for(n=0;n<i;n++)
      { for(j=0;j<i2;j++)
         if(strcmp(ScenicSpotList2[n].ScenicSpot_ID,info[j].order_NUMBER)==0)
           yu[n]=yu[n]+info[j].order_IDENTITY1+info[j].order_IDENTITY2+info[j].order_IDENTITY3;
	  }
    //根据景点id，分别计算各景点预定量 
    for(n=0;n<i;n++)
     {
        //ScenicSpotList2[n]=ScenicSpotList[n];
     	ScenicSpotList2[n].ScenicSpot_YUDING=yu[n];
	 }
	 // 输入修改后预定量 
     fclose(fp);
     fclose(fp2);
     fp=fopen("景点信息.dat","wb");
     fwrite(&ScenicSpotList2,sizeof(struct  ScenicSpot),i,fp);
     fclose(fp);
     //将修改后信息输入“景点信息”   
	 FILE *fp3;
     fp3=fopen("景点信息.dat","rb");//打开文件，景点名称 
      
    for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//引入文件中景点数据,计算景点个数 ,i是景点个数    
	
     	int k;//n,j,k用来辅助排序， ScenicSpotList2用来辅助排序     	
	 for(n=1;n<i;n++)
    {
      k=ScenicSpotList[n].ScenicSpot_YUDING ;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//存下 ScenicSpotList[n]数据 
      j=n-1;//j用来计数当前数据最多与前数据交换次数 
        while((j>=0)&&(ScenicSpotList[j].ScenicSpot_YUDING<k))
        // j不为负且ScenicSpotList[n-1]>ScenicSpotList[n],则交换
      {
         ScenicSpotList[j+1].ScenicSpot_YUDING =ScenicSpotList[j].ScenicSpot_YUDING ;
         ScenicSpotList[j+1]=ScenicSpotList[j];         
         j--;
      } //j-1，继续比较 ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_YUDING=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];
   }
     printf("   景点名称          景点ID          景点预定量\n");    
    for(n=0;n<i;n++)
     {       
       printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_YUDING  );
     }//输出排序后景点数据 
     fclose(fp3);
     	printf("请问您是否需要订票？\n1.需要\n2.返回功能界面\n");
     		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				yudingjingdianmenpiao();
				panduan1=0;
				break;
			case 2:
				jinruyoukegongneng();
				panduan1=0;
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
}
//根据好评率排序 
void haopingpaixu()
{
	  FILE *fp;
   fp=fopen("景点信息.dat","rb");//打开文件“景点信息” 
    int i;
    for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//引入文件中景点数据,计算景点个数 ,i是景点个数 
	/*for(n=0;n<i;n++)
    fread(&ScenicSpotList[n],sizeof(struct  ScenicSpot),i,fp);*/
	
	int j,n;//n,j,k用来辅助排序， ScenicSpotList2用来辅助排序 
	float k;
	 for(n=1;n<i;n++)
   {
      k=ScenicSpotList[n].ScenicSpot_HAOPING;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//存下 ScenicSpotList[n]数据 
      j=n-1;//j用来计数当前数据最多与前数据交换次数 
        while((j>=0)&&(ScenicSpotList[j].ScenicSpot_HAOPING<k))
		// j不为负且ScenicSpotList[n-1]>ScenicSpotList[n],则交换 
      {
         ScenicSpotList[j+1].ScenicSpot_HAOPING=ScenicSpotList[j].ScenicSpot_HAOPING;
         ScenicSpotList[j+1]=ScenicSpotList[j];         
         j--;
      }//j-1，继续比较 ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_HAOPING=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];

   }
   printf("   景点名称          景点ID          好评率\n");
   for(n=0;n<i-1;n++)
    {       
       printf("%11s\t%11s\t%11.2f\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_HAOPING);
    }//输出排序后景点数据 
    fclose(fp);//关闭文件 
    	printf("请问您是否需要订票？\n1.需要\n2.返回功能界面\n");
    		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				yudingjingdianmenpiao();
				panduan1=0;
				break;
			case 2:
				jinruyoukegongneng();
				panduan1=0;
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
}
//预定景点门票 
void yudingjingdianmenpiao()
{
	
	FILE *jingdian;
	
	jingdian=fopen("景点名称.dat","w");
	
	int num3=0;
	
	//1号景点
	
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0001");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"万里长城");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"中国伟大的军事建筑");//景点简介
	ScenicSpotList[num3].ScenicSpot_PRICE1=200;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=140;//景点淡季门票价格  
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"4小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.8;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.7;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"无");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"北京");//景点所属区域 
	ScenicSpotList[num3].ScenicSpot_COST=100000;//景点维护费用
	ScenicSpotList[num3].ScenicSpot_MENPIAO=700; //景点总票数
	ScenicSpotList[num3].ScenicSpot_VISIT=150000;//景点访问人数
	ScenicSpotList[num3].ScenicSpot_YUDING=2000;//景点预定量
	ScenicSpotList[num3].ScenicSpot_HAOPING=0.81;//景点好评率
	strcpy(ScenicSpotList[num3].ScenicSpot_LRET,"是");//是否适宜老人儿童 
	num3++; 
	//2号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0002");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"桂林山水");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"桂林山水甲天下");//景点简介 
	ScenicSpotList[num3].ScenicSpot_PRICE1=350;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=300;//景点淡季门票价格  
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"2.5小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=1.0;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=1.0;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=1.0;//普通折扣信息  
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"无");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"桂林");//景点所属区域 
	ScenicSpotList[num3].ScenicSpot_COST=78000;//景点维护费用
	ScenicSpotList[num3].ScenicSpot_MENPIAO=1100;//景点总票数
	ScenicSpotList[num3].ScenicSpot_VISIT=175000;//景点访问人数
	ScenicSpotList[num3].ScenicSpot_YUDING=4500;//景点预定量
	ScenicSpotList[num3].ScenicSpot_HAOPING=0.89;//景点好评率
	strcpy(ScenicSpotList[num3].ScenicSpot_LRET,"是");//是否适宜老人儿童
	num3++;
	//3号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0003");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"故宫");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"明清两代的皇宫");//景点简介
	ScenicSpotList[num3].ScenicSpot_PRICE1=100;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=50;//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"3.5小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.8;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.75;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"10万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"北京");//景点所属区域 
	ScenicSpotList[num3].ScenicSpot_COST=40000;//景点维护费用
	ScenicSpotList[num3].ScenicSpot_MENPIAO=1000;//景点总票数
	ScenicSpotList[num3].ScenicSpot_VISIT=100000;//景点访问人数
	ScenicSpotList[num3].ScenicSpot_YUDING=3462;//景点预定量
	ScenicSpotList[num3].ScenicSpot_HAOPING=0.82;//景点好评率
	strcpy(ScenicSpotList[num3].ScenicSpot_LRET,"是");//是否适宜老人儿童 
	num3++;
	//4号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0004");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"杭州西湖");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"历史悠久、世界著名的风景游览胜地");//景点简介 
	ScenicSpotList[num3].ScenicSpot_PRICE1=230;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=170;//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"3小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.7;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.5;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"2万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"杭州");//景点所属区域 
	ScenicSpotList[num3].ScenicSpot_COST=51000;//景点维护费用
	ScenicSpotList[num3].ScenicSpot_MENPIAO=2000;//景点总票数
	ScenicSpotList[num3].ScenicSpot_VISIT=89000;//景点访问人数
	ScenicSpotList[num3].ScenicSpot_YUDING=4500;//景点预定量
	ScenicSpotList[num3].ScenicSpot_HAOPING=0.89;//景点好评率
	strcpy(ScenicSpotList[num3].ScenicSpot_LRET,"是");//是否适宜老人儿童
	num3++;
	//5号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0005");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"苏州园林");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"悠久历史的私家园林");//景点简介 
	ScenicSpotList[num3].ScenicSpot_PRICE1=200;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=140;//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"2小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.75;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.6;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"1.5万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"苏州");//景点所属区域 
	ScenicSpotList[num3].ScenicSpot_COST=63000;//景点维护费用
	ScenicSpotList[num3].ScenicSpot_MENPIAO=800;//景点总票数
	ScenicSpotList[num3].ScenicSpot_VISIT=65000;//景点访问人数
	ScenicSpotList[num3].ScenicSpot_YUDING=4100;//景点预定量
	ScenicSpotList[num3].ScenicSpot_HAOPING=0.79;//景点好评率
	strcpy(ScenicSpotList[num3].ScenicSpot_LRET,"是");//是否适宜老人儿童
	num3++;
	//6号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0006");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"安徽黄山");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"天下第一奇山");//景点简介 
	ScenicSpotList[num3].ScenicSpot_PRICE1=225;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=175;//景点淡季门票价格  
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"3.5小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.8;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.8;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"3.1万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"黄山市");//景点所属区域 
	ScenicSpotList[num3].ScenicSpot_COST=15000;//景点维护费用
	ScenicSpotList[num3].ScenicSpot_MENPIAO=900;//景点总票数
	ScenicSpotList[num3].ScenicSpot_VISIT=78000;//景点访问人数
	ScenicSpotList[num3].ScenicSpot_YUDING=4120;//景点预定量
	ScenicSpotList[num3].ScenicSpot_HAOPING=0.80;//景点好评率
	strcpy(ScenicSpotList[num3].ScenicSpot_LRET,"否");//是否适宜老人儿童
	num3++;
	//7号景点
		strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0007");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"长江三峡");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"长江上最为奇秀壮丽的山水画廊");//景点简介  
	ScenicSpotList[num3].ScenicSpot_PRICE1=240;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=200;//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"2.6小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.75;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.75;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"1.5万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"长江");//景点所属区域 
	ScenicSpotList[num3].ScenicSpot_COST=20000;//景点维护费用
	ScenicSpotList[num3].ScenicSpot_MENPIAO=600;//景点总票数
	ScenicSpotList[num3].ScenicSpot_VISIT=50000;//景点访问人数
	ScenicSpotList[num3].ScenicSpot_YUDING=3400;//景点预定量
	ScenicSpotList[num3].ScenicSpot_HAOPING=0.83;//景点好评率
	strcpy(ScenicSpotList[num3].ScenicSpot_LRET,"否");//是否适宜老人儿童
	num3++;
	//8号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0008");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"兵马俑");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"秦朝的奇迹");//景点简介
	ScenicSpotList[num3].ScenicSpot_PRICE1=200;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=140;//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"1.5小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.65;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.8;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"1万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"西安");//景点所属区域 
	ScenicSpotList[num3].ScenicSpot_COST=50000;//景点维护费用
	ScenicSpotList[num3].ScenicSpot_MENPIAO=800;//景点总票数 
	ScenicSpotList[num3].ScenicSpot_VISIT=60000;//景点访问人数
	ScenicSpotList[num3].ScenicSpot_YUDING=5010;//景点预定量
	ScenicSpotList[num3].ScenicSpot_HAOPING=0.85;//景点好评率
	strcpy(ScenicSpotList[num3].ScenicSpot_LRET,"是");//是否适宜老人儿童
	num3++;
	
	
	
	
FILE *fp;

	int i,n,x,y;//循环结构的计数值 
	
	int a,b,c,d,f,g,h,j,k;//判断各项信息输入是否正确的标记值 
	
	char tmp[20];
	
	
	
	
	 
	 
	 
	fp=fopen("dingdan.dat","a");
	printf("您要订多少个景点的票？\n");
	scanf("%d",&n);
	if(n<=0 || n>10)
	{
		printf("景点数量输入错误或输入数值过大!\n"); 
	}
	else 
	{
	printf("请分别输入每个景点的ID，游客身份,游客年龄层次,订票数量，出行时间(年/月/日/时间)，每次输入完一项按回车继续\n");
	
		fp=fopen("订单信息.dat.dat","a");
		
	
		
	for(i=0;i<n;i++)
	{
		
		
		//门票总价格（数据待读取，暂定10000） 
	
		info[i]. order_PRICE=10000;
	
	
		printf("请输入第%d个景点的相关信息：\n",i+1);
		
		
		
		
		 
		printf("景点ID：");
	
		
		x=num3-1;
		a=-1;
		
		while(a==-1)
		{

		scanf("%s",info[i].order_NUMBER);
		
		for(y=0;y<=x;y++)
		{ 
		if(strcmp(info[i].order_NUMBER,ScenicSpotList[y].ScenicSpot_ID)==0)
		{
	
		a=y;
		
		}
		
		
		
		} 
		
		if(a==-1) 
		{
	
		printf("景点ID输入错误！请重新输入！\n");
		
		}
	
		} 
		
		
		
		fputs(info[i].order_NUMBER,fp);
		fputs("\n",fp);
		
		
		printf("游客身份（学生人数）：");
		
		
		b=-1;
		while(b==-1)
		{
		scanf("%d",&info[i].order_IDENTITY1);
		if(info[i].order_IDENTITY1>=0)
		{
		
		b=0;
		
		}
		
		if(b==-1)
		{
		printf("输入错误！请重新输入！\n");
		}
		
		}
		
		fprintf(fp,"%d",info[i].order_IDENTITY1);
		fputs("\n",fp);
		
		
		
		
		printf("游客身份（军人人数）：");
		
		
		c=-1;
		while(c==-1)
		{
		scanf("%d",&info[i].order_IDENTITY2);
		if(info[i].order_IDENTITY2>=0)
		{
		
		c=0;
		
		}
		
		if(c==-1)
		{
		printf("输入错误！请重新输入！\n");
		}
		
		}
		
		fprintf(fp,"%d",info[i].order_IDENTITY2);
		fputs("\n",fp);
		
		
		
		printf("游客身份（普通人人数）：");
		
		
		d=-1;
		while(d==-1)
		{
		scanf("%d",&info[i].order_IDENTITY3);
		if(info[i].order_IDENTITY3>=0)
		{
		
		d=0;
		
		}
		
		if(d==-1)
		{
		printf("输入错误！请重新输入！\n");
		}
		
		}
		
		fprintf(fp,"%d",info[i].order_IDENTITY3);
		fputs("\n",fp);
		
		
		
		printf("游客年龄层次：");
		scanf("%s",info[i].order_AGE);
		fputs(info[i].order_AGE,fp);
		fputs("\n",fp);
		

		info[i].order_PEOPLENUM=info[i].order_IDENTITY1+info[i].order_IDENTITY2+info[i].order_IDENTITY3;
		
		ScenicSpotList[a].ScenicSpot_MENPIAO-=info[i].order_PEOPLENUM;
		
		
		fprintf(fp,"%d",info[i].order_PEOPLENUM);
		fputs("\n",fp);
		
		
		printf("出行时间（年）");
		
		f=-1;
		 
		while(f==-1)
		{
		scanf("%d",&info[i].order_YEAR);
		
		if(info[i].order_YEAR>=1000 && info[i].order_YEAR<=9999)
		{
		
		f=0;
		
		}
		
		if(f==-1)
		{
		printf("年份输入错误！\n");
		}
		
		}
		
		fprintf(fp,"%d",info[i].order_YEAR);
		fputs("\n",fp);
		
		
		printf("出行时间（月）");
		
		
		g=-1;
		
		while(g==-1)
		{
		scanf("%d",&info[i].order_MONTH);
		
		if(info[i].order_MONTH>=1 && info[i].order_MONTH<=12)
		{
		
		g=0;
		
		}
		
		if(g==-1)
		{
		printf("月份输入错误！\n");
		}
		
		}
		
		
		fprintf(fp,"%d",info[i].order_MONTH);
		fputs("\n",fp);
		
		printf("出行时间（日）");
		
		h=-1;
		
		while(h==-1)
		{
		scanf("%d",&info[i].order_DAY);
		
		if(info[i].order_DAY>=1 && info[i].order_DAY<=31)
		{
		
		h=0;
		
		}
		
		if(h==-1)
		{
		printf("日期输入错误！\n");
		}
		
		}
		
		
		fprintf(fp,"%d",info[i].order_DAY);
		fputs("\n",fp);
		
		
		printf("出行时间（时）");
		
		j=-1;
		
		while(j==-1)
		{
		scanf("%d",&info[i].order_HOUR);
		
		if(info[i].order_HOUR>=0 && info[i].order_HOUR<=23)
		{
		
		j=0;
		
		}
		
		if(j==-1)
		{
		printf("时间输入错误！\n");
		}
		
		}
		
		fprintf(fp,"%d",info[i].order_HOUR);
		fputs("\n",fp);
		
		
		printf("出行时间（分）");
		
		k=-1;
		
		while(k==-1)
		{
		scanf("%d",&info[i].order_MINUTE);
		
		if(info[i].order_MINUTE>=0 && info[i].order_MINUTE<=59)
		{
		
		k=0;
		
		}
		
		if(k==-1)
		{
		printf("时间输入错误！\n");
		}
		
		}
		
		fprintf(fp,"%d",info[i].order_MINUTE);
		fputs("\n",fp);
		
		
		
		
		
		
		
		
		
		
		//根据订单日期生成订单编号 

		sprintf(info[i].order_ID,"%d",info[i].order_YEAR);
		
		
		
		if(info[i].order_MONTH<10)
		{
		sprintf(tmp,"0%d",info[i].order_MONTH);
		
		strcat(info[i].order_ID,tmp);
		
		}
		else
		{
		sprintf(tmp,"%d",info[i].order_MONTH);
		
		strcat(info[i].order_ID,tmp);
		}
		
		
		
		if(info[i].order_DAY<10)
		{
		sprintf(tmp,"0%d",info[i].order_DAY);
		
		strcat(info[i].order_ID,tmp);
		
		}
		else
		{	
		sprintf(tmp,"%d",info[i].order_DAY);
		
		strcat(info[i].order_ID,tmp);
		}
		
		
		if(info[i].order_HOUR<10)
		{
		sprintf(tmp,"0%d",info[i].order_HOUR);
		
		strcat(info[i].order_ID,tmp);
		
		}
		else
		{
		sprintf(tmp,"%d",info[i].order_HOUR);
		
		strcat(info[i].order_ID,tmp);
		}
		
		
		if(info[i].order_MINUTE<10)
		{
		sprintf(tmp,"0%d",info[i].order_MINUTE);
		
		strcat(info[i].order_ID,tmp);
		
		}
		else
		{
		sprintf(tmp,"%d",info[i].order_MINUTE);
		
		strcat(info[i].order_ID,tmp);
		}
		
		fputs(info[i].order_ID,fp);
	
		
		fputs("\n",fp);
		
	}
	
	fclose(fp);
	
	
	fwrite(&ScenicSpotList,1000,num3,jingdian);
	
	
	
	
	show(n);
	
	
	}
}
//输出信息的函数 
void outputinfo()
{
	
	FILE *fp;
	int i;
	
	char buf[1000];
	
	i=0;
	
	fp=fopen("订单信息.dat","rb") ;
	
	printf("您的所有订单信息如下：\n");
	
	while (fgets(buf,1000,fp))
	{
	
		
		i++;
		
		if(i%12==1) 
		printf("景点ID：%s",buf);
		
		if(i%12==2) 
		printf("学生人数：%s",buf);
		
		
		if(i%12==3) 
		printf("军人人数：%s",buf);
		
		
		if(i%12==4) 
		printf("普通游客人数：%s",buf);
		
		if(i%12==5) 
		printf("游客年龄层次：%s",buf);
		
		if(i%12==6) 
		printf("总人数（订票数量）：%s",buf);
		
		if(i%12==7) 
		printf("订票时间（年）：%s",buf);
		
		if(i%12==8) 
		printf("订票时间（月）：%s",buf);
		
		if(i%12==9) 
		printf("订票时间（日）：%s",buf);
		
		if(i%12==10) 
		printf("订票时间（时）：%s",buf);
		
		if(i%12==11) 
		printf("订票时间（分）：%s",buf);
		
		if(i%12==0) 
		printf("订单编号：%s",buf);

	}
	
	if(i==0)
	{
		printf("无订单信息！\n");
	}

	fclose(fp);
	
		printf("请问您是否需要继续使用系统？\n1.返回功能界面\n2.退出\n");
	    		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				jinruyoukegongneng();
				panduan1=0;
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
 }
//退订的函数 
void deleteinfo()
{
	FILE *pf = fopen("订单信息.dat", "rb");
	
	
    char buf[1000];
	char s[50];

    int i=0;
	int c=-1;
	
	int riqi_year,riqi_month,riqi_day,riqi_hour,riqi_minute;
	int riqi2_year,riqi2_month,riqi2_day,riqi2_hour,riqi2_minute;
	double gap_between_date1,gap_between_date2;
	int d[12]={0,31,59,90,120,151,181,212,243,273,304,334};
	

	
	if(countline()==0) 
	{
	printf("无订单信息！\n");
	}
	else
	{

	printf("输入要删除的订单编号：\n");
	
	scanf("%s",s);
	
	//judgetime(x);
	
	
	
	strcat(s,"\n");
	
	while (fgets(buf,1000,pf) && c!=i)
	{
	

		
	i++;
	

		
	if(strcmp(buf,s)==0)
	{
		c=i;
		
	}
	
	
	}
	
	
	
	
	
	
	
	
	if(c==-1 || c%12!=0) //判断s是否为订单编号与订单编号是否正确 
	{
		printf("此订单不存在！\n");
	}
    else  
    {
    
    
    
    
    fclose(pf);
    
    
    time_t t;
	struct tm*lt;
    time(&t);
    lt=localtime (&t);
    
    
	
	riqi2_year=lt->tm_year+1900;
	riqi2_month=lt->tm_mon+1; 
	riqi2_day=lt->tm_mday;
	riqi2_hour=lt->tm_hour;
	riqi2_minute=lt->tm_min;
	
	
   
   
    
    
    FILE *pf2 = fopen("订单信息.dat", "rb");
    FILE *pt = fopen("tmp.dat", "w");//创建临时文件tmp.dat，存储删除后的数据，然后用其替换源文件 
    	
	i=0;
	
	while (fgets(buf,1000,pf2))
	{
	i++;
	
    if(i<c-11 || i>c)
    {
    
	fputs(buf,pt);
	
	}
    
    if(i==c-6)
    {
    	
	}
    if(i==c-5)
    {
    	
	riqi_year=atof(buf);
	
	

	
	
	}
	
	
	if(i==c-4)
    {
    	
	riqi_month=atof(buf);
	
	
	

	
	}
	
	if(i==c-3)
    {
    	
	riqi_day=atof(buf);
	
	
	

	
	}
	
	
	if(i==c-2)
    {
    	
	riqi_hour=atof(buf);
	
	

	
	}
	
	
	if(i==c-1)
    {
    	
	riqi_minute=atof(buf);
	
	

	
	}
	
	
	}
	
	
	
	
	if(riqi_year%4==0 && riqi_year%100!=0)
	{
		
	if(riqi_month==1 || riqi_month==2)
	gap_between_date1=(riqi_year-1)*525600+(riqi_year-1)/4*1440-(riqi_year-1)/100*1440+d[riqi_month-1]*1440+(riqi_day-1)*1440+(riqi_hour)*60+riqi_minute;
	else
	gap_between_date1=(riqi_year-1)*525600+(riqi_year-1)/4*1440-(riqi_year-1)/100*1440+d[riqi_month-1]*1440+1440+(riqi_day-1)*1440+(riqi_hour)*60+riqi_minute;
	
	}
	else
	{
		gap_between_date1=(riqi_year-1)*525600+(riqi_year-1)/4*1440-(riqi_year-1)/100*1440+d[riqi_month-1]*1440+(riqi_day-1)*1440+(riqi_hour)*60+riqi_minute;
	}
	
	
	
	if(riqi2_year%4==0 && riqi2_year%100!=0)
	{
		
	if(riqi2_month==1 || riqi2_month==2)
	gap_between_date2=(riqi2_year-1)*525600+(riqi2_year-1)/4*1440-(riqi2_year-1)/100*1440+d[riqi2_month-1]*1440+(riqi2_day-1)*1440+(riqi2_hour)*60+riqi2_minute;
	else
	gap_between_date2=(riqi2_year-1)*525600+(riqi2_year-1)/4*1440-(riqi2_year-1)/100*1440+d[riqi2_month-1]*1440+1440+(riqi2_day-1)*1440+(riqi2_hour)*60+riqi2_minute;
	
	}
	else
	{
		gap_between_date2=(riqi2_year-1)*525600+(riqi2_year-1)/4*1440-(riqi2_year-1)/100*1440+d[riqi2_month-1]*1440+(riqi2_day-1)*1440+(riqi2_hour)*60+riqi2_minute;
	}
	
	printf("温馨提示：现在是时间是%d年%d月%d日 %d时%d分\n",riqi2_year,riqi2_month,riqi2_day,riqi2_hour,riqi2_minute);
	
	
	
	if(gap_between_date1-gap_between_date2<=1440 && gap_between_date1-gap_between_date2>0)
	{
	
    fclose(pt);
    fclose(pf2);
    
    remove("订单信息.dat");
    rename("tmp.dat","订单信息.dat");
	
	
	printf("订单删除成功！\n");
	
	}
	
	if(gap_between_date1-gap_between_date2>1440)
	{
		fclose(pt);
    	fclose(pf2);
		printf("退订失败，请在出行前24小时内再退订。\n");
		remove("tmp.dat");	
	}
	
	
	if(gap_between_date1-gap_between_date2<=0)
	{
		fclose(pt);
    	fclose(pf2);
		printf("时间已经过了。退订失败！\n");
		remove("tmp.dat");	
	}
	
	
	}
	

	}
	
	
	

	
    

    fclose(pf);
    
    		printf("请问您是否需要继续使用系统？\n1.返回功能界面\n2.退出\n");
	    		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				jinruyoukegongneng();
				panduan1=0;
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
	
    
    
	
}

//管理员登陆 
void Guanliyuandenglu()
{
	FILE *administrator_ID1,*administrator_PASSWORD1,*administrator_login;
	administrator_ID1=fopen("管理员信息.dat","rb");
	administrator_PASSWORD1=fopen("管理员信息.dat","rb");
	administrator_login=fopen("管理员用户名和密码备份.dat","w");
	int cal1=1,cal2,cal3=1,cal4,cal5=0;
	char administrator_ID2[20]={"\0"},administrator_PASSWORD2[20]={"\0"};
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
				fputs(administrator_ID2,administrator_login);
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
	fputs(administrator_ID2,administrator_login);
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
				fputs(administrator_PASSWORD2,administrator_login);
			}
		}
		   if(cal1!=0)
		  {
		  	printf("密码输入不正确，请重新输入：\n"); 
		  	scanf("%s",administrator_PASSWORD2);
		  	cal2=0;
		  	cal5++;
			}
			if(cal5 == 2)
			{
				printf("密码输入错误次数超过3次，请返回主界面重新登陆\n");
				mainmenu();
				cal1=0;
				cal3=0;
			}
	} 
	fclose(administrator_ID1);
	fclose(administrator_PASSWORD1);
	fclose(administrator_login);
	guanliyuancaidan();
}   
//管理员菜单 
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
			    gerenxinxichaxun();
				panduan=0;
				break;
			case 5:
				exit(0);
				panduan=0;
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose);
				break;
		}
	}
}    

// 景点管理界面 
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
//添加景点信息及修改发布
void tianjiajingdianxinxi()
{
    FILE  *fpa;
    FILE  *fpb;
    int i=0;
    int c=0;
    int num1=0; 
    int ScenicSpotNum=8;//景点数量 
    int panduan=1;//判断是否输入正确 
    int panduan2;//判断是否继续修改
	int panduan3=0;//判断景点ID是否正确
	int panduan4=0;//判断景点名称是否正确 
	int e;//景点信息是否有误 
    int xuan;//选择要修改的信息
	int tianjia;//添加新的信息
	int queding;//是否发布
	int discount1=1,discount2=1,discount3=1;//判断折扣信息输入是否合格 
	int menpiao;//判断门票信息是否输入合格 
    struct  ScenicSpot a[80];//暂存信息 
    struct  ScenicSpot b[80];//暂存信息
    //打开并读取文件信息 
    fpa=fopen("景点信息.dat","a+");
	fpb=fopen("添加信息预存.dat","a+");        
    for(i=0;i<ScenicSpotNum;i++)
    fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fpa);
    do
	{
		//输入新的景点信息 
        printf("请输入景点ID\n");
		while(panduan3==0)
		{
			getchar(); 
    		gets(a[num1].ScenicSpot_ID);
    		panduan3=1;
    		for(c=0;c<ScenicSpotNum;c++)
    		if(strcmp(a[num1].ScenicSpot_ID,ScenicSpotList[c].ScenicSpot_ID)==0)//判断是否景点ID重复 
			{ 
    	    	printf("景点ID重复\n");
    	    	panduan3=0; 
    			printf("请重新输入景点ID\n");
    		}
    	}
    	printf("请输入景点名称\n");
    	while(panduan4==0)
		{
    		gets(a[num1].ScenicSpot_NAME);
    		panduan4=1;
    		for(c=0;c<ScenicSpotNum;c++)
    		if(strcmp(a[num1].ScenicSpot_NAME,ScenicSpotList[c].ScenicSpot_NAME)==0)//判断是否景点名称重复 
			{ 
    			printf("景点名字重复\n");
    			panduan4=0;
    			printf("请重新输入景点名称\n");
			}	
    	}
    	printf("请输入景点简介\n");
    	gets(a[num1].ScenicSpot_INTRO);
    	printf("请输入景点旺季门票价格\n");
    	scanf("%d",&a[num1].ScenicSpot_PRICE1);
    	printf("请输入景点淡季门票价格\n");
    	scanf("%d",&a[num1].ScenicSpot_PRICE2);
    	getchar();
    	printf("请输入游览该景点所需时间\n");
    	gets(a[num1].ScenicSpot_TIME);
    	printf("请输入学生折扣信息\n");
    	do
    	{
    		discount1=1;
    		scanf("%f",&a[num1].ScenicSpot_DISCOUNT1);
    		if(a[num1].ScenicSpot_DISCOUNT1>1)//判断折扣信息输入是否合格
    		{
    			discount1=0;
    			printf("折扣信息输入不合格。请重新输入\n");
    		}
    	}
    	while(discount1==0);
    	printf("请输入军人折扣信息\n");
    	do
    	{
    		discount2=1;
    		scanf("%f",&a[num1].ScenicSpot_DISCOUNT1);
    		if(a[num1].ScenicSpot_DISCOUNT1>1)//判断折扣信息输入是否合格
    		{
    			discount2=0;
    			printf("折扣信息输入不合格。请重新输入\n");
    		}
    	}
    	while(discount2==0);
    	printf("请输入普通折扣信息\n");
    	do
    	{
    		discount3=1;
    		scanf("%f",&a[num1].ScenicSpot_DISCOUNT3);
    		if(a[num1].ScenicSpot_DISCOUNT3>1)//判断折扣信息输入是否合格
    		{
    			discount3=0;
    			printf("折扣信息输入不合格。请重新输入\n");
    		}
    	}
    	while(discount3==0);
    	getchar();
    	printf("请输入景点级别\n");
    	gets(a[num1].ScenicSpot_GRADE);
    	printf("请输入人数限制\n");
    	gets(a[num1].ScenicSpot_NUMBER);
    	printf("请输入景点所属区域\n");
    	gets(a[num1].ScenicSpot_AREA);
    	printf("请输入景点维护费用\n");
    	scanf("%d",&a[num1].ScenicSpot_COST);
    	printf("请输入景点总票数\n");
    	do
    	{
    		menpiao=1;
    		scanf("%d",&a[num1].ScenicSpot_MENPIAO);
    		if(a[num1].ScenicSpot_MENPIAO<0)//判断门票信息是否输入合格
    		{
    			menpiao=0;
    			printf("输入不合格。请重新输入\n");
    		}
    	}
    	while(menpiao==0);
    	printf("请输入景点好评率\n");
    	scanf("%f",&a[num1].ScenicSpot_HAOPING);
    	printf("请输入景点是否适宜老人儿童\n");
    	getchar();
    	gets(a[num1].ScenicSpot_LRET); 
    	printf("请确认景点信息是否有误\n1.修改\n2.取消添加\n3.发布\n");
    	scanf("%d",&e);
    	if(e==1)
		{
			i++;
			do
			{
				printf("请选择要修改的信息\n");
				printf("1.景点ID\n");
				printf("2.景点名称\n");
				printf("3.景点简介\n");
				printf("4.景点旺季门票价格\n");
				printf("5.景点淡季门票价格\n");
				printf("6.游览该景点所需时间\n");
				printf("7.学生折扣信息\n");
				printf("8.军人折扣信息\n");
				printf("9.普通折扣信息\n");
				printf("10.景点级别\n");
				printf("11.人数限制\n");
				printf("12.景点所属区域\n");
				printf("13.景点维护费用\n");
				printf("14.景点总票数\n");
				printf("15.景点好评率\n");
				printf("16.景点是否适宜老人儿童\n");
				panduan=1;
				scanf("%d",&xuan);//选择要修改的选项 
				while(panduan!=0)//判断输入是否合格 
				{
					switch(xuan)//要修改的选项
					{
						case 1:
							getchar();
							printf("请输入新信息\n");
							panduan3=0; 
							while(panduan3==0)
							{ 
    							gets(b[num1].ScenicSpot_ID);
    							panduan3=1;
    							for(c=0;c<ScenicSpotNum;c++)
    							if(strcmp(b[num1].ScenicSpot_ID,ScenicSpotList[c].ScenicSpot_ID)==0)//判断是否景点ID重复 
								{ 
    	    						printf("景点ID重复\n");
    	    						panduan3=0; 
    								printf("请重新输入景点ID\n");
    							}
    						}
							strncpy(a[num1].ScenicSpot_ID,b[num1].ScenicSpot_ID,100);
							panduan=0;
							break;
						case 2:
							getchar();
							printf("请输入新信息\n");
							panduan4=0;
							while(panduan4==0)
							{ 
    							gets(b[num1].ScenicSpot_NAME);
    							panduan4=1;
    							for(c=0;c<ScenicSpotNum;c++)
    							if(strcmp(b[num1].ScenicSpot_NAME,ScenicSpotList[c].ScenicSpot_NAME)==0)//判断是否景点名称重复 
								{ 
    								printf("景点名字重复");
    								panduan4=0;
    								printf("请重新输入景点名称\n");
								}	
    						}
							strncpy(a[num1].ScenicSpot_NAME,b[num1].ScenicSpot_NAME,100);
							panduan=0;
							break;
						case 3:
							getchar();
							printf("请输入新信息\n");
							gets(b[num1].ScenicSpot_INTRO);
							strncpy(a[num1].ScenicSpot_INTRO,b[num1].ScenicSpot_INTRO,100);
							panduan=0;
							break;
						case 4:
							scanf("%d",&b[num1].ScenicSpot_PRICE1);
							a[num1].ScenicSpot_PRICE1=b[num1].ScenicSpot_PRICE1;
							panduan=0;
							break;
						case 5:
							printf("请输入新信息\n");
							scanf("%d",&b[num1].ScenicSpot_PRICE2); 
							a[num1].ScenicSpot_PRICE2=b[num1].ScenicSpot_PRICE2;
							panduan=0;
							break;
						case 6:
							getchar();
							printf("请输入新信息\n");
							gets(b[num1].ScenicSpot_TIME); 
							strncpy(a[num1].ScenicSpot_TIME,b[num1].ScenicSpot_TIME,100);
							panduan=0;
							break;
						case 7:
							printf("请输入新信息\n"); 
							scanf("%f",&b[num1].ScenicSpot_DISCOUNT1);
							a[num1].ScenicSpot_DISCOUNT1=b[num1].ScenicSpot_DISCOUNT1;
							panduan=0;
							break;
						case 8:
							printf("请输入新信息\n");
							scanf("%f",&b[num1].ScenicSpot_DISCOUNT2);
							a[num1].ScenicSpot_DISCOUNT2=b[num1].ScenicSpot_DISCOUNT2;
							panduan=0;
							break; 
						case 9:
							printf("请输入新信息\n");
							scanf("%f",&b[num1].ScenicSpot_DISCOUNT3);
							a[num1].ScenicSpot_DISCOUNT3=b[num1].ScenicSpot_DISCOUNT3;
							panduan=0;
							break; 
						case 10:
							printf("请输入新信息\n");
							getchar();
							gets(b[num1].ScenicSpot_GRADE); 
							strncpy(a[num1].ScenicSpot_GRADE,b[num1].ScenicSpot_GRADE,100);
							panduan=0;
							break;
						case 11:
							printf("请输入新信息\n");
							gets(b[num1].ScenicSpot_NUMBER); 
							strncpy(a[num1].ScenicSpot_NUMBER,b[num1].ScenicSpot_NUMBER,100);
							panduan=0;
							break;
						case 12:
							printf("请输入新信息\n");
							getchar();
							gets(b[num1].ScenicSpot_AREA); 
							strncpy(a[num1].ScenicSpot_AREA,b[num1].ScenicSpot_AREA,100);
							panduan=0;
							break;
						case 13:
							printf("请输入新信息\n");
							scanf("%d",&b[num1].ScenicSpot_COST);
							a[num1].ScenicSpot_COST=b[num1].ScenicSpot_COST;
							panduan=0;
							break;
						case 14:
							printf("请输入新信息\n");
							scanf("%d",&b[num1].ScenicSpot_MENPIAO);
							a[num1].ScenicSpot_MENPIAO=b[num1].ScenicSpot_MENPIAO;
							panduan=0;
							break;
						case 15:
							printf("请输入新信息\n");
							scanf("%f",&b[num1].ScenicSpot_HAOPING);	
							a[num1].ScenicSpot_HAOPING=b[num1].ScenicSpot_HAOPING;
							break;
						case 16:
							printf("请输入新信息\n");
							getchar();
							gets(b[num1].ScenicSpot_LRET);
							strncpy(a[num1].ScenicSpot_LRET,b[num1].ScenicSpot_LRET,100);
							panduan=0;
							break;
						default:
							printf("您输入的数据有错误，请重新输入：\n");
							scanf("%d",&xuan);
							break;
					}	
				}
				if(panduan==0)
				{
					printf("是否继续修改\n1.是\t2.否\n");//是否继续修改 
					scanf("%d",&panduan2); 
				}
			}
			while(panduan2==1); 
			printf("请确定是否发布\n1.是 2.否\n");//修改完信息后是否发布 
			scanf("%d",&queding);
			if(queding==1)//发布 
			{
				fseek(fpa,0L,2);
				fwrite(&a[num1],10000,1,fpa);
			}
			else//不发布 
			{
				fwrite(&ScenicSpotList[i],10000,1,fpb);
				remove("添加信息预存.dat");
			}
		}
    	if(e==2)//取消发布 
		{
			fwrite(&a[num1],10000,1,fpb);
			remove("添加信息预存.dat");
		}
    	if(e==3)//发布信息 
		{
			fseek(fpa,0L,2);
			fwrite(&a[num1],10000,1,fpa);
    	}
    	num1++;
    	ScenicSpotNum++;
		printf("是否继续添加新的景点信息\n1.是\t2.否\n");
		scanf("%d",&tianjia); 
	}
	while(tianjia==1);
	fclose(fpa);
	fclose(fpb);
	
	    		printf("请问您是否需要继续使用系统？\n1.返回功能界面\n2.退出\n");
	    		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				guanliyuancaidan();
				panduan1=0;
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
		    
}	
//订单查询 
void dingdanchaxun()
{
FILE  *fp;
        int  i,t,m=1,n=1;
        fp=fopen("订单信息.dat","rb");
        char dingdanchaxun1[80]={"\0"};
	    printf("请输入要查询的订单编号：\n");
		scanf("%s",dingdanchaxun1);
      for(i=0;fread(&info[i],sizeof(struct info_list),1,fp)==1;i++)
        t=i;
		
		while(m!=0) 
	{
		for(i=0;i<t;i++)
		{
		if(strcmp(dingdanchaxun1,info[i].order_ID)==0)//若文件中有输入的订单编号，则进入if条件 
			{
			printf("订单编号: "); 
		    puts(info[i].order_ID);
	        printf("订单年份: ");
	        printf("%d\n",info[i].order_YEAR);
		    printf("订单月份: ");
	        printf("%d\n",info[i].order_MONTH);
	        printf("订单日: ");
	        printf("%d\n",info[i].order_DAY);
	        printf("订单小时: ");
	        printf("%d\n",info[i].order_HOUR);
	        printf("订单分钟: ");
	      //  printf("%d\n",info[i].order_MINNTE);
	        printf("景点编号: ");
	        puts(info[i].order_NUMBER);
	        printf("出行时间: ");
	       // puts(info[i].order_TIME);
	        printf("年龄段: ");
	      	puts(info[i].order_AGE);
	        printf("人数: ");
	       // puts(info[i].order_PEOPLENUM);
	        printf("学生身份: ");
	      //  puts(info[i].order_IDENTITY1);
	        printf("军人身份: ");
	       // puts(info[i].order_IDENTITY2);
	        printf("普通身份:");
	      //  puts(info[i].order_IDENTITY3);
			printf("订单总价格:");
	       // printf("%f",info[i].order_PRICE);	
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
//景点信息查询 
void  jingdianxinxichaxun()
{
	FILE  *fp;
        int  i,t,m=1,n=1;
        fp=fopen("景点信息.dat","rb");
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
	        printf("%d\n",ScenicSpotList[i].ScenicSpot_COST);
			printf("景点总票: ");
			printf("%d\n",ScenicSpotList[i].ScenicSpot_MENPIAO);
			printf("景点访问人数: ");
			printf("%d\n",ScenicSpotList[i].ScenicSpot_VISIT);
			printf("景点预定量: ");
			printf("%d\n",ScenicSpotList[i].ScenicSpot_YUDING);
			printf("景点好评率: ");
			printf("%.2f\n",ScenicSpotList[i].ScenicSpot_HAOPING);
			printf("否适宜老人儿童: ");
			puts(ScenicSpotList[i].ScenicSpot_LRET);
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
		
			    		printf("请问您是否需要继续使用系统？\n1.返回功能界面\n2.退出\n");
	    		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				guanliyuancaidan();
				panduan1=0;
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
}
//管理员个人信息查询 
void  gerenxinxichaxun()
{
		FILE  *fp,*fp2;
        int i;
        char administrator_ID2[80];
        fp=fopen("管理员信息.dat","rb");        
        fp2=fopen("管理员用户名和密码备份.dat","rb");
        fgets(administrator_ID2,sizeof(administrator_ID2),fp2);
        printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
        printf("                         查询结果\n");
        printf("------------------------------------------------------------------\n");
        printf("管理员ID\t管理员密码\t管理员电话\t管理员邮箱\n");
		printf("------------------------------------------------------------------\n"); 
		for(i=0;fread(&administratorList[i],sizeof(struct  administrator),1,fp)==1;i++)
        	if(strcmp(administratorList[i].administrator_ID,administrator_ID2)==0)
        	{
				printf("%s\t%s\t",administratorList[i].administrator_ID,administratorList[i].administrator_PASSWORD);
			    printf("%s\t%s\n",administratorList[i].administrator_PHONE,administratorList[i].administrator_MAIL);
			}
		printf("------------------------------------------------------------------\n\n");
        printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n\n\n");
        fclose(fp);
        
        	    		printf("请问您是否需要修改信息？\n1.是\n2.返回功能界面\n");
	    		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				xiugaigerenxinxi();
				panduan1=0;
				break;
			case 2:
				guanliyuancaidan();
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
}	
//管理员个人信息修改 
void xiugaigerenxinxi()
{	
FILE  *fp,*fp2;
	fp=fopen("管理员信息.dat","rb"); 
	char administrator_ID2[80];
	        fp2=fopen("管理员用户名和密码备份.dat","rb");
        fgets(administrator_ID2,sizeof(administrator_ID2),fp2);
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
	fp=fopen("管理员信息.dat","rb+");
	//strcpy(a->administrator_ID,administratorList[n].administrator_ID);
	//strcpy(a->administrator_PHONE,administratorList[n].administrator_PHONE);
	//administratorList[n].administrator_PASSWORD=NULL;
	//administratorList[n].administrator_MAIL=NULL;
    fseek(fp,n*sizeof(struct  administrator),0);
    printf("请输入新的密码及邮箱\n"); 
	scanf("%s%s",a,b);
	strncpy(administratorList[n].administrator_PASSWORD,a,20);
	strncpy(administratorList[n].administrator_MAIL,b,20);
	for(i=0;i<80;i++)
	{
		fwrite(&administratorList[i],10000,1,fp);
	}
    fclose(fp); 
    guanliyuancaidan();
}
//订单统计界面 
void dingdantongji()
{
		int choose,panduan=1;
   	printf("请选择你要统计信息的方式：\n");
	printf("1.按预定量对景点进行排序。\n2.按访问人数对景点进行排序。\n3.按各景点的利润排序。\n4.统计不同景点的用户年龄层次分布\n5.按季度对不同景点的售票情况排序。\n6.退出程序。\n");
	scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				yudingliangpaixu1();
				panduan=0; 
				break;
			case 2:
				
				panduan=0;
				break;
			case 3:
				lirunpaixu();
				panduan=0;
				break;
			case 4:
			    age();
				panduan=0;
				break;
			case 5:
				
				panduan=0;
				break;
			case 6:
				exit(0);
				panduan=0;
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose);
				break;
		}
	}
}
//按景点预售量从大到小排序
void yudingliangpaixu1() 
 {
 
   FILE *fp,*fp2;
   fp=fopen("景点信息.dat","rb");//打开文件“景点信息” 
    int i,n,j;
     for(i=0;fread(&ScenicSpotList2[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);
     //将“景点名称”中信息赋值给 ScenicSpotList2
    fp2=fopen("订单信息.dat","rb");//打开文件订单信息 
    int i2;//i2为订单个数 
     for(i2=0;fread(&info[i2],sizeof(struct info_list),1,fp2)!=0;i2++);
     //计算订单个数 
    int yu[80];
      for(n=0;n<i;n++)
	   yu[n]=0;//为预定量建立数组 
    //strcmp(dsfsfs,dfdfd)
     for(n=0;n<i;n++)
      { for(j=0;j<i2;j++)
         if(strcmp(ScenicSpotList2[n].ScenicSpot_ID,info[j].order_NUMBER)==0)
           yu[n]=yu[n]+info[j].order_IDENTITY1+info[j].order_IDENTITY2+info[j].order_IDENTITY3;
	  }
    //根据景点id，分别计算各景点预定量 
    for(n=0;n<i;n++)
     {
        //ScenicSpotList2[n]=ScenicSpotList[n];
     	ScenicSpotList2[n].ScenicSpot_YUDING=yu[n];
	 }
	 // 输入修改后预定量 
     fclose(fp);
     fclose(fp2);
     fp=fopen("景点信息.dat","wb");
     fwrite(&ScenicSpotList2,sizeof(struct  ScenicSpot),i,fp);
     fclose(fp);
     //将修改后信息输入“景点信息”   
	 FILE *fp3;
     fp3=fopen("景点信息.dat","rb");//打开文件，景点名称 
      
    for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//引入文件中景点数据,计算景点个数 ,i是景点个数    
	
     	int k;//n,j,k用来辅助排序， ScenicSpotList2用来辅助排序     	
	 for(n=1;n<i;n++)
    {
      k=ScenicSpotList[n].ScenicSpot_YUDING ;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//存下 ScenicSpotList[n]数据 
      j=n-1;//j用来计数当前数据最多与前数据交换次数 
        while((j>=0)&&(ScenicSpotList[j].ScenicSpot_YUDING<k))
        // j不为负且ScenicSpotList[n-1]>ScenicSpotList[n],则交换
      {
         ScenicSpotList[j+1].ScenicSpot_YUDING =ScenicSpotList[j].ScenicSpot_YUDING ;
         ScenicSpotList[j+1]=ScenicSpotList[j];         
         j--;
      } //j-1，继续比较 ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_YUDING=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];
   }
     printf("   景点名称          景点ID          景点预定量\n");    
    for(n=0;n<i;n++)
     {       
       printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_YUDING  );
     }//输出排序后景点数据 
     fclose(fp3);
     
     			    		printf("请问您是否需要继续使用系统？\n1.返回功能界面\n2.退出\n");
	    		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				guanliyuancaidan();
				panduan1=0;
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
  }
//按访问人数有小到大排序 
void fangwenrenshupaixu() 
{
}
//利润由大到小排序 
void lirunpaixu() 
 { 
 }
//年龄统计 
void age() 
 {
 }




