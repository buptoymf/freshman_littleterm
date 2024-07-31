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
	char tmp[20];
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
		
		strcpy(info[i].order_ID,touristList[i].tourist_ID); 
		
		
		
		sprintf(tmp,"%d",info[i].order_YEAR);
		
		strcat(info[i].order_ID,tmp);
		
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
		
		fputs(info[i].order_ID,fp1);
	
		
		fputs("\n",fp1);
		
		//一切信息输入完之后，创建新文件以存储景点信息变化； 
		FILE *jingdian2;
	
		jingdian2=fopen("temp.txt","wb");//创建临时文件tmp.txt，存储删除后的数据，然后用其替换源文件 
	
		y=0;
		
		fseek(jingdian,0L,0);
		
	
		while(fgets(buf2,1000,jingdian))
		{
			y++;
			if(y!=19*(a-1)+14 && y!=19*(a-1)+15 && y!=19*(a-1)+16 && y!=19*(a-1)+19)
			{
				
				fputs(buf2,jingdian2);
			}
			if(y==19*(a-1)+14)
			{
			sprintf(buf2,"%d\n",ScenicSpotList[i].ScenicSpot_MENPIAO);
			fputs(buf2,jingdian2);
			printf("此景点剩余票数：%s",buf2);
			}
			if(y==19*(a-1)+15)
			{
				ScenicSpotList[i].ScenicSpot_VISIT-=info[i].order_PEOPLENUM;
			sprintf(buf2,"%d\n",ScenicSpotList[i].ScenicSpot_VISIT);
			
			fputs(buf2,jingdian2);
			
			printf("此景点剩余容量：%s",buf2);
			}
			if(y==19*(a-1)+16)
			{
			ScenicSpotList[i].ScenicSpot_YUDING+=info[i].order_PEOPLENUM;
			sprintf(buf2,"%d\n",ScenicSpotList[i].ScenicSpot_YUDING);
			
			fputs(buf2,jingdian2);
			
			printf("此景点预订量：%s",buf2);
			
			}
			if(y==19*(a-1)+19)
			{
			
			ScenicSpotList[i].ScenicSpot_INCOME+=info[i].order_PRICE;
			sprintf(buf2,"%.2f\n",ScenicSpotList[i].ScenicSpot_INCOME);
			
			fputs(buf2,jingdian2);
			
			printf("此景点总收入：%s",buf2);
			
			
			}
		}
		
		
		fclose(jingdian2);
		
		
		
		
		
		
		
	}
	
		fclose(jingdian);
		
		
		
		
		remove("景点信息.txt");
		rename("temp.txt","景点信息.txt");
	fclose(fp1);
	
	
//	fwrite(&ScenicSpotList,1000,num3,jingdian);
	
	
	
	
	show(shuliang);
	
	
	}
}

//输出信息的函数
void outputinfo()
{
	FILE *fp;
	int i=0;
	fp=fopen("订单信息.txt","r");
	fread(&info,sizeof(struct info_list),1,fp);
	printf("您的所有订单信息如下：\n");
	if(info[i].order_ID!=NULL)
	{
		do
		{
			printf("景点ID：%s",info[i].order_ID);
			printf("学生人数：%d",info[i].order_IDENTITY1);
			printf("军人人数：%d",info[i].order_IDENTITY2);
			printf("普通人人数：%d",info[i].order_IDENTITY3);
			printf("游客年龄层次：%s",info[i].order_AGE);
			printf("总人数（订票数量）：%d",info[i].order_PEOPLENUM);
			printf("订票时间（年）：%d",info[i].order_YEAR);
			printf("订票时间（月）：%d",info[i].order_MONTH);
			printf("订票时间（日）：%d",info[i].order_DAY);
			printf("订票时间（时）：%d",info[i].order_HOUR);
			printf("订票时间（分）：%d",info[i].order_MINUTE);
			printf("订单总价格（元）：%d",info[i].order_PRICE);
			printf("订单编号：%s",info[i].order_ID);
			i++;
		} 
		while(info[i].order_ID==NULL);
    }
    else
    printf("无订单信息！\n");

} 
//退订的函数 
void deleteinfo()
{
	FILE *pf = fopen("订单信息.txt", "rb");
	
	
    char buf[1000];
    char buf2[1000];
	char s[50];

    int i=0;
	int c=-1;
	int a,x,y,m,n;
	
	int riqi_year,riqi_month,riqi_day,riqi_hour,riqi_minute;
	int riqi2_year,riqi2_month,riqi2_day,riqi2_hour,riqi2_minute;
	double gap_between_date1,gap_between_date2;
	int d[12]={0,31,59,90,120,151,181,212,243,273,304,334};
	

	
	if(fread(&info,sizeof(struct info_list),1,pf)==NULL) 
	{
	printf("无订单信息！\n");
	}
	else
	{

	printf("输入要删除的订单编号：\n");
	
	scanf("%s",s);
	
	//judgetime(x);
	
	
	
	strcat(s,"\n");
	
	m=0;
	
	while (fread(&info,sizeof(struct info_list),1,pf) && c!=m)
	{
	

		
	m++;
	

		
	if(strcmp(buf,s)==0)
	{
		c=m;
		
	}
	
	
	}
	
	
	
	
	
	
	
	
	if(c==-1 || c%13!=0) //判断s是否为订单编号与订单编号是否正确 
	{
		printf("此订单不存在！\n");
	}
    else  
    {
    	FILE *jingdian;
    
    	
		jingdian=fopen("景点信息.txt","rb");
		
		
		
    	
		
		fseek(pf,0L,0);
		
		
		i=0;
		
		while (fread(&info,sizeof(struct info_list),1,pf))
		{
		i++;
		
		if(i==c-12)
		{
		strcpy(info[i].order_NUMBER,buf);
		printf("此景点ID：%s",info[i].order_NUMBER);
		}
		
		if(i==c-1)
		{
		info[i].order_PRICE=atof(buf);	
		n=i;
		printf("此订单总价格（元）：%.2f\n",info[n].order_PRICE);
		}
		
	
		}
		
		
		x=0;
		m=0;
		
//		fseek(jingdian,0L,0);
		
		fseek(jingdian,0L,0);
		
		while (fread(&info,sizeof(struct info_list),1,jingdian))
		{
			m++;
			if((m+19)%19==1)
			{
			x++;
			strcpy(ScenicSpotList[x].ScenicSpot_ID,buf);
			
			
			}
		}
		
	
	
		
		for(y=1;y<=x;y++)
		{
		
		
	//	strcat(buf,"\n");
		
		
		
		
		if(strcmp(info[c-12].order_NUMBER,ScenicSpotList[y].ScenicSpot_ID)==0)
		{
		
		a=y;
		
		}
		
		
		
		}
		
		
    	y=0;
		
		fseek(jingdian,0L,0);
		
	
		//fread(ScenicSpotList,sizeof(ScenicSpotList),8,jingdian);	
		while(fgets(buf,1000,jingdian))
		{
			y++;
			if(y==19*(a-1)+1)
			{
			strcpy(ScenicSpotList[a].ScenicSpot_ID,buf);
			
			}
			if(y==19*(a-1)+2)
			{
			strcpy(ScenicSpotList[a].ScenicSpot_NAME,buf);
			
			}
			if(y==19*(a-1)+3)
			{
			strcpy(ScenicSpotList[a].ScenicSpot_INTRO,buf);
			
			}
			if(y==19*(a-1)+4)
			{
			ScenicSpotList[a].ScenicSpot_PRICE1=atoi(buf);
			
			}
			if(y==19*(a-1)+5)
			{
			ScenicSpotList[a].ScenicSpot_PRICE2=atoi(buf);
			
			}
			if(y==19*(a-1)+6)
			{
			strcpy(ScenicSpotList[a].ScenicSpot_TIME,buf);
			
			}
			if(y==19*(a-1)+7)
			{
			ScenicSpotList[a].ScenicSpot_DISCOUNT1=atof(buf);
			
			}
			if(y==19*(a-1)+8)
			{
			ScenicSpotList[a].ScenicSpot_DISCOUNT2=atof(buf);
			
			}
			if(y==19*(a-1)+9)
			{
			ScenicSpotList[a].ScenicSpot_DISCOUNT3=atof(buf);
			
			}
			if(y==19*(a-1)+10)
			{
			strcpy(ScenicSpotList[a].ScenicSpot_GRADE,buf);
			
			}
			if(y==19*(a-1)+11)
			{
			strcpy(ScenicSpotList[a].ScenicSpot_NUMBER,buf);
			
			}
			if(y==19*(a-1)+12)
			{
			strcpy(ScenicSpotList[a].ScenicSpot_AREA,buf);
			
			}
			if(y==19*(a-1)+13)
			{
			ScenicSpotList[a].ScenicSpot_COST=atoi(buf);
			
			}
			if(y==19*(a-1)+14)
			{
			ScenicSpotList[a].ScenicSpot_MENPIAO=atoi(buf);
			
			}
			if(y==19*(a-1)+15)
			{
			ScenicSpotList[a].ScenicSpot_VISIT=atoi(buf);
			
			}
			if(y==19*(a-1)+16)
			{
			ScenicSpotList[a].ScenicSpot_YUDING=atoi(buf);
			
			}
			if(y==19*(a-1)+17)
			{
			ScenicSpotList[a].ScenicSpot_HAOPING=atof(buf);
			
			}
			if(y==19*(a-1)+18)
			{
			strcpy(ScenicSpotList[a].ScenicSpot_LRET,buf);
			
			}
			if(y==19*(a-1)+19)
			{
			ScenicSpotList[a].ScenicSpot_INCOME=atof(buf);
			
			}
			
			
			
			
			
		}
		
    
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
	
	
   
   int piaoshu;
    
    
    FILE *pf2 = fopen("订单信息.txt", "rb");
    FILE *pt = fopen("tmp.txt", "wb");//创建临时文件tmp.txt，存储删除后的数据，然后用其替换源文件 
    	
	i=0;
	
	
	while(fgets(buf,1000,pf2))
	{
	i++;
	
    if(i<c-12 || i>c)
    {
    
	fputs(buf,pt);
	
	}
    
    if(i==c-7)
    {
    	piaoshu=atoi(buf);
    	printf("退订票数：%d\n",piaoshu);
	}
    if(i==c-6)
    {
    	
	riqi_year=atof(buf);
	
	

	
	
	}
	
	
	if(i==c-5)
    {
    	
	riqi_month=atof(buf);
	
	
	

	
	}
	
	if(i==c-4)
    {
    	
	riqi_day=atof(buf);
	
	
	

	
	}
	
	
	if(i==c-3)
    {
    	
	riqi_hour=atof(buf);
	
	

	
	}
	
	
	if(i==c-2)
    {
    	
	riqi_minute=atof(buf);
	
	

	
	}
	
	
	}
	
	
	//判断是否为出行前24小时内 
	
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
	
	FILE *jingdian2;
	
	jingdian2=fopen("temp.txt","wb");//创建临时文件tmp.txt，存储删除后的数据，然后用其替换源文件
	
	y=0;
		
		fseek(jingdian,0L,0);
		
	
		while(fgets(buf2,1000,jingdian))
		{
			y++;
			if(y!=19*(a-1)+14 && y!=19*(a-1)+15 && y!=19*(a-1)+19)
			{
				
				fputs(buf2,jingdian2);
			}
			if(y==19*(a-1)+14)
			{
			ScenicSpotList[a].ScenicSpot_MENPIAO+=piaoshu;
			sprintf(buf2,"%d\n",ScenicSpotList[a].ScenicSpot_MENPIAO);
			fputs(buf2,jingdian2);
			printf("此景点剩余票数：%s",buf2);
			}
			if(y==19*(a-1)+15)
			{
			ScenicSpotList[a].ScenicSpot_VISIT+=piaoshu;
			sprintf(buf2,"%d\n",ScenicSpotList[a].ScenicSpot_VISIT);
			
			fputs(buf2,jingdian2);
			
			printf("此景点剩余容量：%s",buf2);
			}
			
			if(y==19*(a-1)+19)
			{
			ScenicSpotList[a].ScenicSpot_INCOME-=info[n].order_PRICE;
			sprintf(buf2,"%.2f\n",ScenicSpotList[a].ScenicSpot_INCOME);
			
			fputs(buf2,jingdian2);
			
			printf("此景点总收入(元)：%s",buf2);
			
			}
			
			
		}
		
		fclose(jingdian2);
		fclose(jingdian);
		
    fclose(pt);
    fclose(pf2);
    
    remove("景点信息.txt");
    	rename("temp.txt","景点信息.txt");
    	
    	
    
    remove("订单信息.txt");
    rename("tmp.txt","订单信息.txt");
	
	
	printf("订单删除成功！\n");
	
	}
	
	if(gap_between_date1-gap_between_date2>1440)
	{
		fclose(pt);
    	fclose(pf2);
    	fclose(jingdian);
		printf("退订失败，请在出行前24小时内再退订。\n");
		remove("tmp.txt");	
		
	}
	
	
	if(gap_between_date1-gap_between_date2<=0)
	{
		fclose(pt);
    	fclose(pf2);
    	fclose(jingdian);
		printf("时间已经过了。退订失败！\n");
		remove("tmp.txt");	
	}
	
	
	}
	

	}
	
	
	

	
    

    fclose(pf);
    
    
	
    
    
	
}
	
	
	
	

	
    

    
//显示主菜单 
void PrintMainMenu()
{
	printf("**************************主菜单**************************\n");
	printf("\t\t\t请输入命令的编号以执行命令：\n"); 
	printf("\t\t\t1.添加订单\n");
	printf("\t\t\t2.查询订单\n");
	printf("\t\t\t3.退订\n");
	printf("\t\t\t4.查询全部景点信息（已废除）\n");
	printf("\t\t\t5.退出\n");
	printf("*************************************************************\n");
} 



int main()
{
	char cmd[100];
    
    cmd[0]='9';
    
    
    
    
    
    printf("\t\t欢迎使用北京邮电大学团体游订票系统\n");
    printf("\n");
    PrintMainMenu(); 

	    while(cmd[0]!='5')
    {
    
	
    gets(cmd);//输入主菜单对应的命令数字 
        switch(cmd[0])
        {
            case '1':
                inputinfo();
                exit(0); 
                break;
            case '2':
                outputinfo();
                PrintMainMenu();
                break;
            case '3':
            	deleteinfo();
                PrintMainMenu();
                break;
            case '4':
                
                PrintMainMenu();
                break;
            
			
        }
        if(cmd[0]!='1' && cmd[0]!='2' && cmd[0]!='3' && cmd[0]!='4' && cmd[0]!='5' && cmd[0]!='\0')
        {
        	printf("输入有误!\n");
		}
      	if(cmd[0]=='5')
        {
        	printf("再见.");
		}
        
    }
	
	

	

	return 2;
}
