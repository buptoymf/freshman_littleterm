#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUMBER 80
//景点信息

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
}ScenicSpotList[NUMBER];


//添加景点信息及修改发布
main() 
//void  addScenicSpot()
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
    struct  ScenicSpot a[80];
    fpa=fopen("景点信息.txt","a+");
	fpb=fopen("添加信息预存.txt","a+");        
    for(i=0;i<ScenicSpotNum;i++)
    fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fpa);
    do
	{
        printf("请输入景点ID\n");
		while(panduan3==0)
		{ 
    		gets(a[num1].ScenicSpot_ID);
    		panduan3=1;
    		for(c=0;c<ScenicSpotNum;c++)
    		if(strcmp(a[num1].ScenicSpot_ID,ScenicSpotList[c].ScenicSpot_ID)==0)
			{ 
    	    	printf("景点ID重复\n");
    	    	panduan3=0; 
    			printf("请重新输入景点名称\n");
    		}
    	}
    	printf("请输入景点名称\n");
    	while(panduan4==0)
		{ 
    		gets(a[num1].ScenicSpot_NAME);
    		panduan4=1;
    		for(c=0;c<ScenicSpotNum;c++)
    		if(strcmp(a[num1].ScenicSpot_NAME,ScenicSpotList[c].ScenicSpot_NAME)==0)
			{ 
    			printf("景点名字重复");
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
    	scanf("%f",&a[num1].ScenicSpot_DISCOUNT1);
    	printf("请输入军人折扣信息\n");
    	scanf("%f",&a[num1].ScenicSpot_DISCOUNT2);
    	printf("请输入普通折扣信息\n");
    	scanf("%f",&a[num1].ScenicSpot_DISCOUNT3);
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
    	scanf("%d",&a[num1].ScenicSpot_MENPIAO);
    	printf("请输入景点是否适宜老人儿童\n");
    	getchar();
    	gets(a[num1].ScenicSpot_LRET); 
    	printf("请确认景点信息是否有误\n1.修改\n2.取消添加\n3.发布\n");
    	scanf("%d",&e);
    	if(e==1)
		{
			fwrite(&ScenicSpotList[ScenicSpotNum],sizeof(ScenicSpot),1,fpb);
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
			printf("15.景点是否适宜老人儿童\n");
			i++;
			scanf("%d",&xuan);
			do
			{
				while(panduan!=0)
				{
					switch(xuan)
					{
						case 1:
							strncpy(ScenicSpotList[i].ScenicSpot_ID,a[num1].ScenicSpot_ID,100);
							panduan=0;
							break;
						case 2:
							strncpy(ScenicSpotList[i].ScenicSpot_NAME,a[num1].ScenicSpot_NAME,100);
							panduan=0;
							break;
						case 3:
							strncpy(ScenicSpotList[i].ScenicSpot_INTRO,a[num1].ScenicSpot_INTRO,100);
							panduan=0;
							break;
						case 4:
							ScenicSpotList[i].ScenicSpot_PRICE1=a[num1].ScenicSpot_PRICE1;
							panduan=0;
							break;
						case 5: 
							ScenicSpotList[i].ScenicSpot_PRICE2=a[num1].ScenicSpot_PRICE2;
							panduan=0;
							break;
						case 6: 
							strncpy(ScenicSpotList[i].ScenicSpot_TIME,a[num1].ScenicSpot_TIME,100);
							panduan=0;
							break;
						case 7: 
							ScenicSpotList[i].ScenicSpot_DISCOUNT1=a[num1].ScenicSpot_DISCOUNT1;
							panduan=0;
							break;
						case 8:
							ScenicSpotList[i].ScenicSpot_DISCOUNT2=a[num1].ScenicSpot_DISCOUNT2;
							panduan=0;
							break; 
						case 9:
							ScenicSpotList[i].ScenicSpot_DISCOUNT3=a[num1].ScenicSpot_DISCOUNT3;
							panduan=0;
							break; 
						case 10: 
							strncpy(ScenicSpotList[i].ScenicSpot_GRADE,a[num1].ScenicSpot_GRADE,100);
							panduan=0;
							break;
						case 11: 
							strncpy(ScenicSpotList[i].ScenicSpot_NUMBER,a[num1].ScenicSpot_NUMBER,100);
							panduan=0;
							break;
						case 12:
							strncpy(ScenicSpotList[i].ScenicSpot_AREA,a[num1].ScenicSpot_AREA,100);
							panduan=0;
							break;
						case 13:
							ScenicSpotList[i].ScenicSpot_COST=a[num1].ScenicSpot_COST;
							panduan=0;
							break;
						case 14:
							ScenicSpotList[i].ScenicSpot_MENPIAO=a[num1].ScenicSpot_MENPIAO;
							panduan=0;
							break;
						case 15:
							strncpy(ScenicSpotList[i].ScenicSpot_LRET,a[num1].ScenicSpot_LRET,100);
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
					printf("是否继续修改\n1.是\t2.否");
					scanf("%d",&panduan2); 
				}
			}
			while(panduan2==1);	
			printf("请确定是否发布\n1.是 2.否");
			scanf("%d",&queding);
			if(queding==1)
			{
				fseek(fpa,0L,2);
				fwrite(&ScenicSpotList[i],sizeof(ScenicSpot),1,fpa);
			}
			else
			{
				fwrite(&ScenicSpotList[i],sizeof(ScenicSpot),1,fpb);
				remove("添加信息预存.txt");
			}
		}
    	if(e==2)
		{
			fwrite(&ScenicSpotList[i],sizeof(ScenicSpot),1,fpb);
			remove("添加信息预存.txt");
		}
    	if(e==3)
		{
			fseek(fpa,0L,2);
			fwrite(&a[num1],sizeof(ScenicSpot),1,fpa);
    	}
    	num1++;
    	ScenicSpotNum++;
		printf("是否继续添加新的景点信息\n1.是\t2.否");
		scanf("%d",&tianjia); 
	}
	while(tianjia==1);
	fclose(fpa);
	fclose(fpb);	    
}
