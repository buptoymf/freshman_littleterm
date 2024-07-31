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



//输入信息的函数
void inputinfo()
{
	
	
	
	
	
	FILE *fp;

	int i,n,x,y;//循环结构的计数值 
	
	int jingdianshuliang;
	int a,b,c,d,f,g,h,j,k,l;//判断各项信息输入是否正确的标记值 
	
	int price;
	
	char buf[1000];
	char buf2[1000];
	char tmp[20];
	
	FILE *jingdian;
	
	jingdian=fopen("景点信息.txt","rb");
	 
	 
	 
	fp=fopen("订单信息.txt","ab");
	printf("您要订多少个景点的票？\n");
	scanf("%d",&n);
	if(n<=0 || n>10)
	
	{
		printf("景点数量输入错误或输入数值过大!\n"); 
	}
	else 
	{
	printf("请分别输入每个景点的ID，各身份游客人数,游客年龄层次,出行时间(年，月，日，时，分)，每次输入完一项按回车继续\n");
	
		fp=fopen("订单信息.txt","ab");
		
	
//		m=0;
		
	for(i=0;i<n;i++)
	{
		
	
	
	
	
	
		printf("请输入第%d个景点的相关信息：\n",i+1);
		
//		x=0;
		
//		fseek(jingdian,0L,0);
		
/*		while (fgets(buf,1000,jingdian))
		{
			m++;
			if(m%19==1)
			{
			x++;
			strcpy(ScenicSpotList[x].ScenicSpot_ID,buf);
			
			
			}
		}*/
	for(jingdianshuliang=0;fread(&ScenicSpotList[jingdianshuliang],sizeof(struct ScenicSpot),1,jingdian)!=0;jingdianshuliang++)
	
    {
		 
	}
//	printf("景点数量：%d\n",jingdianshuliang);
	
		printf("景点ID：");
	
		
		
		a=-1;
		
		while(a==-1)
		{

		scanf("%s",info[i].order_NUMBER);
		
		for(y=0;y<jingdianshuliang;y++)
		{
		
		strcpy(buf,info[i].order_NUMBER);
		
		
		
		
		if(strcmp(buf,ScenicSpotList[y].ScenicSpot_ID)==0)
		{
		
		a=y;
		
		}
		
		//printf("a是%d\n",a);
		
		} 
		
		if(a==-1) 
		{
	
		printf("景点ID输入错误！请重新输入！\n");
		
		}
	
		} 
		
		
		
		
		
		
		
		//输入景点ID后，从景点信息文件中读取该景点的全部数据 
		
		
//		y=0;
		
//		fseek(jingdian,0L,0);
		
	
			
/*		while(fgets(buf,1000,jingdian))
		{
			y++;
			if(y==19*(a-1)+1)
			{
			strcpy(ScenicSpotList[i].ScenicSpot_ID,buf);
			
			}
			if(y==19*(a-1)+2)
			{
			strcpy(ScenicSpotList[i].ScenicSpot_NAME,buf);
			
			}
			if(y==19*(a-1)+3)
			{
			strcpy(ScenicSpotList[i].ScenicSpot_INTRO,buf);
			
			}
			if(y==19*(a-1)+4)
			{
			ScenicSpotList[i].ScenicSpot_PRICE1=atoi(buf);
			
			}
			if(y==19*(a-1)+5)
			{
			ScenicSpotList[i].ScenicSpot_PRICE2=atoi(buf);
			
			}
			if(y==19*(a-1)+6)
			{
			strcpy(ScenicSpotList[i].ScenicSpot_TIME,buf);
			
			}
			if(y==19*(a-1)+7)
			{
			ScenicSpotList[i].ScenicSpot_DISCOUNT1=atof(buf);
			
			}
			if(y==19*(a-1)+8)
			{
			ScenicSpotList[i].ScenicSpot_DISCOUNT2=atof(buf);
			
			}
			if(y==19*(a-1)+9)
			{
			ScenicSpotList[i].ScenicSpot_DISCOUNT3=atof(buf);
			
			}
			if(y==19*(a-1)+10)
			{
			strcpy(ScenicSpotList[i].ScenicSpot_GRADE,buf);
			
			}
			if(y==19*(a-1)+11)
			{
			strcpy(ScenicSpotList[i].ScenicSpot_NUMBER,buf);
			
			}
			if(y==19*(a-1)+12)
			{
			strcpy(ScenicSpotList[i].ScenicSpot_AREA,buf);
			
			}
			if(y==19*(a-1)+13)
			{
			ScenicSpotList[i].ScenicSpot_COST=atoi(buf);
			
			}
			if(y==19*(a-1)+14)
			{
			ScenicSpotList[i].ScenicSpot_MENPIAO=atoi(buf);
			
			}
			if(y==19*(a-1)+15)
			{
			ScenicSpotList[i].ScenicSpot_VISIT=atoi(buf);
			
			}
			if(y==19*(a-1)+16)
			{
			ScenicSpotList[i].ScenicSpot_YUDING=atoi(buf);
			
			}
			if(y==19*(a-1)+17)
			{
			ScenicSpotList[i].ScenicSpot_HAOPING=atof(buf);
			
			}
			if(y==19*(a-1)+18)
			{
			strcpy(ScenicSpotList[i].ScenicSpot_LRET,buf);
			
			}
			if(y==19*(a-1)+19)
			{
			ScenicSpotList[i].ScenicSpot_INCOME=atof(buf);
			
			}
			
		}*/
		
		
		if(ScenicSpotList[a].ScenicSpot_MENPIAO==0)
		{
		printf("抱歉，此景点票已售完。预订失败。\n");
		exit(0);
		}
		else
		{
		
		
		} 
		l=-1;
		
		while(l==-1)
		
		{

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
		
		
		
		
		
		printf("游客年龄层次：");
		scanf("%s",info[i].order_AGE);
		
		

		info[i].order_PEOPLENUM=info[i].order_IDENTITY1+info[i].order_IDENTITY2+info[i].order_IDENTITY3;//算出游客团总人数 
		
		
		
		
		if(ScenicSpotList[a].ScenicSpot_MENPIAO-info[i].order_PEOPLENUM>=0)
		{
		
			l=0;
			
	
		
		}
			else
			printf("游客团人数超出景点容量！请重新输入！\n");
			
		
		}
	
		

		
		
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
		
		
		
		
		//根据订单日期与订票数量计算总价格 
//		y=0;
		
//		fseek(jingdian,0L,0);
		
		if(info[i].order_MONTH<=6)
		
		{
			
//		while(fgets(buf,1000,jingdian))
//		{
//			y++;
//			if(y==19*(a-1)+4)
//			{
			strcpy(info[i].order_jidu,"旺季");
			price=ScenicSpotList[a].ScenicSpot_PRICE1;
			
//			}
			
		}
	
	
//		}
		
//		y=0;
//		
//		fseek(jingdian,0L,0);
		
		if(info[i].order_MONTH>6)
		
		{
			
//		while(fgets(buf,1000,jingdian))
//		{
//			y++;
//			if(y==19*(a-1)+5)
//			{
			strcpy(info[i].order_jidu,"淡季");
			price=ScenicSpotList[a].ScenicSpot_PRICE2;
			
//			}
			
		}
	
	
//		}
		
		
		
		
		
		//数据计算 
		ScenicSpotList[a].ScenicSpot_MENPIAO-=info[i].order_PEOPLENUM;//扣减票数 
		
		info[i].order_PRICE=info[i].order_IDENTITY1*price*ScenicSpotList[a].ScenicSpot_DISCOUNT1+info[i].order_IDENTITY2*price*ScenicSpotList[a].ScenicSpot_DISCOUNT2+info[i].order_IDENTITY3*price*ScenicSpotList[a].ScenicSpot_DISCOUNT3;
		
		ScenicSpotList[a].ScenicSpot_VISIT-=info[i].order_PEOPLENUM;
		
		ScenicSpotList[a].ScenicSpot_YUDING+=info[i].order_PEOPLENUM;
		
		ScenicSpotList[a].ScenicSpot_INCOME+=info[i].order_PRICE;
		
		printf("订单总价格（元）:%.2f\n",info[i].order_PRICE);
		
		
		
		
		
		
		//根据订单日期生成订单编号 
		strcpy(info[i].order_ID1,"游客ID");//游客ID待读取 
		
		strcpy(info[i].order_ID,info[i].order_ID1); 
		
		
		
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
		
		
	
		
		
		
		//一切信息输入完之后，创建新文件以存储景点信息变化； 
		FILE *jingdian2;
	
		jingdian2=fopen("temp.txt","wb");//创建临时文件tmp.txt，存储删除后的数据，然后用其替换源文件 
	
//		y=0;
		
//		fseek(jingdian,0L,0);
		
	
/*		while(fgets(buf2,1000,jingdian))
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
				
			sprintf(buf2,"%d\n",ScenicSpotList[i].ScenicSpot_VISIT);
			
			fputs(buf2,jingdian2);
			
			printf("此景点剩余容量：%s",buf2);
			}
			if(y==19*(a-1)+16)
			{
			
			sprintf(buf2,"%d\n",ScenicSpotList[i].ScenicSpot_YUDING);
			
			fputs(buf2,jingdian2);
			
			printf("此景点预订量：%s",buf2);
			
			}
			if(y==19*(a-1)+19)
			{
			
			
			sprintf(buf2,"%.2f\n",ScenicSpotList[i].ScenicSpot_INCOME);
			
			fputs(buf2,jingdian2);
			
			printf("此景点总收入：%s",buf2);
			
			}
		}*/
		
		fwrite(&ScenicSpotList,sizeof(ScenicSpot),jingdianshuliang,jingdian2);
		fwrite(&info,sizeof(info_list),jingdianshuliang,fp);
		
		fclose(jingdian2);
		
		
		
		
		
		
		
	}
	
		fclose(jingdian);
		
		remove("景点信息.txt");
		rename("temp.txt","景点信息.txt");
	fclose(fp);
	
	
//	fwrite(&ScenicSpotList,1000,num3,jingdian);
	
	
	
	
//	show(n);
	
	
	}
}

int main()
{
	inputinfo();

	return 0;
}
