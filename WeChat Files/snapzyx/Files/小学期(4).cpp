#include<stdio.h>
#include<process.h>
#include<string.h>
#include <stdlib.h>

#define NUMBER 80
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
void yudingjingdianmenpiao();
void outputinfo();
void deleteinfo();
int countline()
{
    FILE *pf = fopen("dingdan.txt", "r");
    char buf[1000];
    int c=0;
    
    if (!pf)
    
    return 0;
        
    while (fgets(buf, 1000, pf))
    c++;
    
    fclose(pf);
    
    return c;
}
struct tourist
{
	char tourist_ID[20];//游客团体ID
	char tourist_PASSWORD[20];//游客团体密码 
	char tourist_NUM[20];//游客团体人数 
	char tourist_AGE[20];//游客团体年龄层次 
	char tourist_PHONE[20];//游客团体联系人电话 
}touristList[NUMBER];
struct administrator
{
	char administrator_ID[20];//系统管理员ID 
	char administrator_PASSWORD[20];//系统管理员密码 
	char administrator_PHONE[20];//系统管理员电话 
	char administrator_MAIL[20];//系统管理员邮箱 
}administratorList[NUMBER];
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
}ScenicSpotList[NUMBER],ScenicSpotList2[NUMBER];
struct info_list
{
	
	char order_NUMBER[20];
	int order_IDENTITY1;
	int order_IDENTITY2;
	int order_IDENTITY3;
	char order_AGE[20];
	int number;
	int order_YEAR;
	int order_MONTH;
	int order_DAY;
	int order_HOUR;
	int order_MINUTE;
	char order_ID[20];
}info[NUMBER];

//主函数 
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
}
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
	jinruyoukegongneng();
}
void Jingdianchaxun()
{
	int choose,panduan=1;
	printf("1.根据景点名称查询。\n2.根据是否有票查询。\n3.根据景点区域查询。\n4.根据是否有折扣查询。\n5.根据价格排序所有景点。\n6.根据与定量排序所有景点。\n");
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
		printf("请问您是否需要订票？\n1.需要\n2.返回功能界面\n");
		int choose,panduan=1;
		scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				
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
			printf("请问您是否需要订票？\n1.需要\n2.返回功能界面\n");
		int choose,panduan=1;
		scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				
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
void Shifouzhekou()
{
			int cal1,cal3,cal5,cal7=1,choose;
	FILE *Jingdian4;
	Jingdian4=fopen("景点信息.txt","r");
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
	        puts(ScenicSpotList[cal1].ScenicSpot_COST);	
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
	        puts(ScenicSpotList[cal3].ScenicSpot_COST);	
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
	        puts(ScenicSpotList[cal5].ScenicSpot_COST);	
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
void piaojiapaixu()
{
   FILE *fp;
   fp=fopen("景点信息.txt","rb");//打开文件“景点信息” 
    int i,j,k,choose,panduan=1;
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
				 for(int n=1;n<i;n++)
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
 				for(int n=0;n<i;n++)
 						 {       
  					         printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_PRICE1);
   						 }
   			  fclose(fp);
			  panduan=0;
			  break;
			case 2:
				for(int n=1;n<i;n++)
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
 				for(int n=0;n<i;n++)
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
void yudingliangpaixu()
{
}
void jinruyoukegongneng()
{
	int choose,panduan=1;
		printf("欢迎进入系统，请选择您要执行的功能： \n");
	printf("\n\n\t**************Main Menu**************\n");
	printf("\t*            1.景点查询                 *\n");
	printf("\t*            2.预定景点门票             *\n");
	printf("\t*            3.信息管理                 *\n");
	printf("\t*            4.取消预定                 *\n");
	printf("\t*            5.查询预定门票             *\n");
	printf("\t*            6.退出                     *\n");
	printf("\t*************************************\n");
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
void yudingjingdianmenpiao()
{
	
	
	FILE *jingdian;
	
	jingdian=fopen("景点信息.txt","rb");
	
	int num3;
	
	for(num3=0;fread(&ScenicSpotList[num3],sizeof(struct  ScenicSpot),1,jingdian)!=0;num3++);
	
FILE *fp;

	int i,n,x,y;//循环结构的计数值 
	
	int a,b,c,d,e,f,g,h,j,k;//判断各项信息输入是否正确的标记值 
	
	char tmp[20];
	
	int total_tourists=100;
	
	 
	fp=fopen("dingdan.txt","a");
	printf("您要订多少个景点的票？\n");
	scanf("%d",&n);
	if(n<=0 || n>10)
	{
		printf("景点数量输入错误或输入数值过大!\n"); 
	}
	else 
	{
	printf("请分别输入每个景点的ID，游客身份,游客年龄层次,订票数量，出行时间(年/月/日/时间)，每次输入完一项按回车继续\n");
	
		fp=fopen("dingdan.txt","a");
		
	
		
	for(i=0;i<n;i++)
	{
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
		if(info[i].order_IDENTITY1<=total_tourists && info[i].order_IDENTITY1>=0)
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
		if(info[i].order_IDENTITY2<=total_tourists && info[i].order_IDENTITY2>=0)
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
		if(info[i].order_IDENTITY3<=total_tourists && info[i].order_IDENTITY3>=0)
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
		
		printf("订票数量：(剩余票数：%d)",ScenicSpotList[a].ScenicSpot_MENPIAO);
		
		
		
		e=-1;
		
		while(e==-1)
		{

		scanf("%d",&info[i].number);
		
		
		
		
		if(ScenicSpotList[a].ScenicSpot_MENPIAO>=info[i].number)
		{
		
		e=0;
		
		}
		
		if(e==-1)
		{
		printf("订票数量超出所剩票数！订票失败！请重新输入！\n");
		}
		
		
		
		}
		
		
		ScenicSpotList[a].ScenicSpot_MENPIAO-=info[i].number;
		
		fprintf(fp,"%d",info[i].number);
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
		fputs("\n",fp);
	}
	
	fclose(fp);
	
	
	fwrite(&ScenicSpotList,1000,num3,jingdian);
	
	
	
	
	
	}
}
void outputinfo()
{
	
	FILE *fp;
	int i;
	char c;
	
	i=0;
	
	fp=fopen("dingdan.txt","r") ;
	
	printf("订单信息如下：（依次为景点的ID,各身份（学生，军人，普通人）游客人数，游客年龄层次,订票数量，订票时间（年，月，日，时，分），订单编号\n");
	c=fgetc(fp);
	
	
	while(c!=EOF)
	{
		
		i++;
		
		
		
		printf("%c",c);
		c=fgetc(fp);
		

	}
	
	if(i==0)
	{
		printf("无订单信息！\n");
	}

	fclose(fp);
 }
 void deleteinfo()
{
	FILE *pf = fopen("dingdan.txt", "r");
	
	
    char buf[1000];
	char s[50];

    int i=0;
	int c=-1;
//	double riqi;
	
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
	
	
//	time_t t;
//	struct tm*lt;
 //   time(&t);
 //   lt=localtime (&t);
	
//	riqi=lt->tm_sec+lt->tm_min*100+lt->tm_hour*10000+lt->tm_mday*1000000+(lt->tm_mon+1)*100000000+(lt->tm_year+1900)*10000000000;
	
	
//	printf("%.lf\n",riqi);
	
	
	if(c==-1 || (c+1)%13!=0) //判断s是否为订单编号与订单编号是否正确 
	{
		printf("此订单不存在！\n");
	}
    else  
    {
    
    fclose(pf);
    
    FILE *pf2 = fopen("dingdan.txt", "r");
    FILE *pt = fopen("tmp.txt", "w");
    	
	i=0;
	
	while (fgets(buf,1000,pf2))
	{
	i++;
	
    if(i<c-12 || i>c)
    {
    printf("%s",buf);
	fputs(buf,pt);
	
	}
    
	
	}
    fclose(pt);
    fclose(pf2);
    
    remove("dingdan.txt");
    rename("tmp.txt","dingdan.txt");
	
	
	printf("订单删除成功！\n");
	
	}
	
	}
	
	
	

	
    

    fclose(pf);
    
    
	
    
    
	
}
