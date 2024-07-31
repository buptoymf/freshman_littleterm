#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#define NUMBER 80
//定义结构体 
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
	float ScenicSpot_INCOME;
	
}ScenicSpotList[NUMBER];




void outputinfo()
{
	
	FILE *fp;
	
	
	char buf[1000];
	
	
	int c=0;
	
	fp=fopen("订单信息.txt","rb") ;
	
	printf("您的所有订单信息如下：\n");
	
	for(c=0;fread(&info[c],sizeof(struct info_list),1,fp)!=0;c++)
    {
	
	
		printf("游客ID：%s\n",info[c].order_ID1);
		
		
		printf("景点ID：%s\n",info[c].order_NUMBER);
		
		
		printf("学生人数：%d\n",info[c].order_IDENTITY1);
	
		printf("军人人数：%d\n",info[c].order_IDENTITY2);
		
		
		
		
		printf("普通游客人数：%d\n",info[c].order_IDENTITY3);
		
		printf("游客团人数：%d\n",info[c].order_PEOPLENUM);
		
	
		printf("游客年龄层次：%s\n",info[c].order_AGE);
		

		
		printf("订票时间（年）：%d\n",info[c].order_YEAR);
		
	
		printf("订票时间（月）：%d\n",info[c].order_MONTH);
		
	
		printf("订票时间（日）：%d\n",info[c].order_DAY);
		
		
		printf("订票时间（时）：%d\n",info[c].order_HOUR);
		
		printf("订票时间（分）：%d\n",info[c].order_MINUTE);
		
		
		printf("订单总价格（元）：%.2f\n",info[c].order_PRICE);
		
		
		printf("订单编号：%s\n",info[c].order_ID);
		
	

	}
	
	if(c==0)
	{
		printf("无订单信息！\n");
	}

	fclose(fp);
 }

int main()
{
	outputinfo();
	
	return 0;
}
