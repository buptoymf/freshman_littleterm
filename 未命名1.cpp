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



struct  ScenicSpot//景点信息结构体 
{
	char ScenicSpot_ID[80];//景点ID
	char ScenicSpot_NAME[80];//景点信息
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
	int ScenicSpot_MENPIAO;//景点门票总量
	int ScenicSpot_VISIT;//景点访问人数 
	int ScenicSpot_YUDING;//景点预定量 
	float ScenicSpot_HAOPING;//景点好评率 
	char ScenicSpot_LRET[80];//是否适宜老人儿童 
	float ScenicSpot_INCOME;//景点总收入量
}ScenicSpotList[NUMBER];





//定义结构体 
struct info_list//订单信息结构体 
{
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
	char order_jidu[20];//订单季度 	 
}info[NUMBER];

//输入完成后，显示订单信息的函数 
void show(int n)
{
	
	int i;
	
	
//	printf("您的订单信息如下：\n");
	
	for(i=0;i<n;i++)
	{


	printf("您的订单价格是：%.2f元\n",info[i].order_PRICE);
	printf("您的订单编号是：%s\n",info[i].order_ID);
	
}
	printf("\n");
	
	printf("订票成功！您的订单信息已保存。系统重启后生效。\n");
	
}


//输入信息的函数
void inputinfo()
{
	FILE *fp1;//景点信息 
	FILE *fp2;//订单信息
	FILE *fp3;//预存景点信息
	struct info_list a[80];
	int c=0,i;//id循环及订单次数 
	int ord;//记录第几个景点 
	int shuliang;//输入的景点数量
	int panduan=1,panduan1=1;//判断循环  
	fp1=fopen("景点信息.txt","r"); 
	fp2=fopen("订单信息.txt","a");
	fp3=fopen("预存景点信息1.txt","w");
    fread(&ScenicSpotList,sizeof(struct  ScenicSpot),1,fp1);
	printf("您要订多少个景点的票？\n");
	scanf("%d",&shuliang);
	if(shuliang<=0 || shuliang>10)
	{
		printf("景点数量输入错误或输入数值过大!\n"); 
	}
	else 
	{
		printf("请分别输入每个景点的ID，各身份游客人数,游客年龄层次,出行时间(年，月，日，时，分)，每次输入完一项按回车继续\n");
		for(i=0;i<shuliang;i++)
		{
			printf("请输入第%d个景点的相关信息：\n",i+1);
			printf("景点ID：");
			while(panduan==1) 
			{
				gets(a[i].order_NUMBER);
				for(c=0;c<8;c++)//景点总数量 
    			{
					if(strcmp(a[i].order_NUMBER,ScenicSpotList[c].ScenicSpot_ID)==0)//判断输入景点ID是否合格 
					{
						ord=c;
						panduan=0;
						fputs(a[i].order_NUMBER,fp1);
						fputs("\n",fp1);
					}
				}
				if(panduan==1)
				printf("景点ID输入不正确\n请重新输入:");
			}
			//学生人数 
			printf("游客身份（学生人数）：");
			while(panduan==0)
			{
				scanf("%d",&a[i].order_IDENTITY1);
				if(a[i].order_IDENTITY1>=0)
				panduan=1;
				
				else
				{
					printf("人数输入不正确\n请重新输入："); 
					panduan=0;
				} 
			}
			//军人人数
			panduan=0; 
			printf("游客身份（军人人数）：");
			while(panduan==0)
			{
				scanf("%d",&a[i].order_IDENTITY2);
				if(a[i].order_IDENTITY2>=0)
				panduan=1;
				
				else
				{
					printf("人数输入不正确\n请重新输入："); 
					panduan=0;
				} 
			}
			//普通游客人数
			panduan=0; 
			printf("游客身份（普通游客人数）：");
			while(panduan==0)
			{
				scanf("%d",&a[i].order_IDENTITY3);
				if(a[i].order_IDENTITY3>=0)
				panduan=1;
				
				else
				{
					printf("人数输入不正确\n请重新输入："); 
					panduan=0;
				} 
			}
			a[i].order_PEOPLENUM=a[i].order_IDENTITY1+a[i].order_IDENTITY2+a[i].order_IDENTITY3;
			if(a[i].order_PEOPLENUM>ScenicSpotList[ord].ScenicSpot_MENPIAO)//判断是否有票 
			{
				printf("该景点剩余票数为%d\n",ScenicSpotList[ord].ScenicSpot_MENPIAO);
				printf("预订失败。"); 
			}
			else
			{
				fprintf(fp1,"%d",a[i].order_IDENTITY1);
			fputs("\n",fp1);
			fprintf(fp1,"%d",a[i].order_IDENTITY2);
			fputs("\n",fp1);
			fprintf(fp1,"%d",a[i].order_IDENTITY3);		
			fputs("\n",fp1);
			}
			//填写年龄层次 
			printf("游客年龄层次：");
			gets(a[i].order_AGE);
			fputs(a[i].order_AGE,fp1);
			fputs("\n",fp1);
			//填写出行日期
			printf("出行时间（年）：");
			while(panduan1==1)
			{
				scanf("%d",a[i].order_YEAR);
				if(a[i].order_YEAR>=1000&&a[i].order_YEAR<=9999)
				panduan1=0;
				else
				{
					printf("年份输入错误\n请重新输入：");
					panduan1=1; 
				}
			}
			panduan1=1; 
			printf("出行时间（月）：");
			while(panduan1==1)
			{
				scanf("%d",a[i].order_MONTH);
				if(a[i].order_MONTH>=1&&a[i].order_MONTH<=12)
				panduan1=0;
				else
				{
					printf("月份输入错误\n请重新输入：");
					panduan1=1; 
				}
			} 
			panduan1=1; 
			printf("出行时间（日）：");
			while(panduan1==1)
			{
				scanf("%d",a[i].order_DAY);
				if(a[i].order_DAY>=1&&a[i].order_DAY<=31)
				panduan1=0;
				else
				{
					printf("日期输入错误\n请重新输入：");
					panduan1=1; 
				}
			} 
			panduan1=1; 
			printf("出行时间（时）：");
			while(panduan1==1)
			{
				scanf("%d",a[i].order_HOUR);
				if(a[i].order_HOUR>=0&&a[i].order_HOUR<=23)
				panduan1=0;
				else
				{
					printf("小时输入错误\n请重新输入：");
					panduan1=1; 
				}
			} 
			panduan1=1; 
			printf("出行时间（分）：");
			while(panduan1==1)
			{
				scanf("%d",a[i].order_MINUTE);
				if(a[i].order_MINUTE>=0&&a[i].order_MINUTE<=59)
				panduan1=0;
				else
				{
					printf("分钟输入错误\n请重新输入：");
					panduan1=1; 
				}
			}
			//计算总价格
			if(a[i].order_MONTH>=5&&a[i].order_MONTH<=10)//旺季价格 
			a[i].order_PRICE=ScenicSpotList[ord].ScenicSpot_DISCOUNT1*a[i].order_IDENTITY1*ScenicSpotList[ord].ScenicSpot_PRICE1+
			                 ScenicSpotList[ord].ScenicSpot_DISCOUNT2*a[i].order_IDENTITY2*ScenicSpotList[ord].ScenicSpot_PRICE1+
			                 ScenicSpotList[ord].ScenicSpot_DISCOUNT3*a[i].order_IDENTITY3*ScenicSpotList[ord].ScenicSpot_PRICE1;
			else//淡季价格 
			a[i].order_PRICE=ScenicSpotList[ord].ScenicSpot_DISCOUNT1*a[i].order_IDENTITY1*ScenicSpotList[ord].ScenicSpot_PRICE2+
			                 ScenicSpotList[ord].ScenicSpot_DISCOUNT2*a[i].order_IDENTITY2*ScenicSpotList[ord].ScenicSpot_PRICE2+
			                 ScenicSpotList[ord].ScenicSpot_DISCOUNT3*a[i].order_IDENTITY3*ScenicSpotList[ord].ScenicSpot_PRICE2;
			                 
			//数据计算 
			ScenicSpotList[ord].ScenicSpot_MENPIAO-=a[i].order_PEOPLENUM;//扣减票数 
			printf("订单总价格（元）:%.2f\n",a[i].order_PRICE);
			
			//根据订单日期生成订单编号 
			strcpy(touristList[i].tourist_ID,"游客ID");//游客ID待读取 		
			strcpy(a[i].order_ID,touristList[i].tourist_ID); 
			char *tmp;
			sprintf(tmp,"%d",a[i].order_YEAR);
			strcat(a[i].order_ID,tmp);
			//月		
			if(info[i].order_MONTH<10)
			{
				sprintf(tmp,"0%d",a[i].order_MONTH);		
				strcat(a[i].order_ID,tmp);
			}
			else
			{
				sprintf(tmp,"%d",a[i].order_MONTH);
				strcat(a[i].order_ID,tmp);
			}
			//日 
			if(a[i].order_DAY<10)
			{
				sprintf(tmp,"0%d",a[i].order_DAY);		
				strcat(a[i].order_ID,tmp);		
			}
			else
			{	
				sprintf(tmp,"%d",a[i].order_DAY);		
				strcat(a[i].order_ID,tmp);
			}
			//时 
			if(a[i].order_HOUR<10)
			{
				sprintf(tmp,"0%d",a[i].order_HOUR);		
				strcat(a[i].order_ID,tmp);		
			}
			else
			{
				sprintf(tmp,"%d",a[i].order_HOUR);		
				strcat(a[i].order_ID,tmp);
			}
			//分 	
			if(a[i].order_MINUTE<10)
			{
				sprintf(tmp,"0%d",a[i].order_MINUTE);
				strcat(a[i].order_ID,tmp);
			}
			else
			{
				sprintf(tmp,"%d",a[i].order_MINUTE);
				strcat(a[i].order_ID,tmp);
			}
		
			
			fprintf(fp1,"%d",a[i].order_YEAR);
			fputs("\n",fp1);
			fprintf(fp1,"%d",a[i].order_MONTH);
			fputs("\n",fp1);
			fprintf(fp1,"%d",a[i].order_DAY);
			fputs("\n",fp1);
			
			fprintf(fp1,"%d",a[i].order_HOUR);
			fputs("\n",fp1);
			fprintf(fp1,"%d",a[i].order_MINUTE);
			fputs("\n",fp1);
		
			
			fprintf(fp1,"%.2f",a[i].order_PRICE);
			fputs("\n",fp1);
			fputs(a[i].order_ID,fp1);
			fputs("\n",fp1);
			
			
			
			
			
			
		}
		show(shuliang);		
	}
	
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}

int main()
{
	inputinfo();
	return 0;
}
