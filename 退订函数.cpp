#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#define NUMBER 80
//����ṹ�� 
struct info_list
{
	char order_ID1[20];//�ο�ID 
	char order_NUMBER[20];//����ID 
	int order_IDENTITY1;//ѧ�����
	int order_IDENTITY2;//�������
	int order_IDENTITY3;//��ͨ���
	char order_AGE[20];//�����
	int order_PEOPLENUM;//����
	int order_YEAR;//������� 
	int order_MONTH;//�����·� 
	int order_DAY;//������ 
	int order_HOUR;//����Сʱ
	int order_MINUTE;//��������
	char order_ID[20];//������ţ��ο�ID+��Ʊʱ�䣩 
	float order_PRICE;//�����ܼ۸�
	char order_jidu[20];//������������ 
	
}info[NUMBER];
struct  ScenicSpot
{
	char ScenicSpot_ID[80];//����ID
	char ScenicSpot_NAME[80];//��������
	char ScenicSpot_INTRO[80];//������
	int ScenicSpot_PRICE1;//����������Ʊ�۸�
	int ScenicSpot_PRICE2;//���㵭����Ʊ�۸�
	char ScenicSpot_TIME[80];//�����þ�������ʱ��
	float ScenicSpot_DISCOUNT1;//ѧ���ۿ���Ϣ
	float ScenicSpot_DISCOUNT2;//�����ۿ���Ϣ
	float ScenicSpot_DISCOUNT3;//��ͨ�ۿ���Ϣ
	char ScenicSpot_GRADE[80];//���㼶��
	char ScenicSpot_NUMBER[80];//��������
	char ScenicSpot_AREA[80];//������������
	int ScenicSpot_COST;//����ά������
	int ScenicSpot_MENPIAO;//������Ʊ 
	int ScenicSpot_VISIT;//����������� 
	int ScenicSpot_YUDING;//����Ԥ���� 
	float ScenicSpot_HAOPING;//��������� 
	char ScenicSpot_LRET[80];//�Ƿ��������˶�ͯ 
	float ScenicSpot_INCOME;
	
}ScenicSpotList[NUMBER];





void deleteinfo()
{
	FILE *pf = fopen("������Ϣ.txt", "rb");
	
	
    char buf[1000];
    char buf2[1000];
	char s[50];

	int jingdianshuliang;
    int i=0;
	int c=0;
	int a,x,y,m,n;
	
	int riqi_year,riqi_month,riqi_day,riqi_hour,riqi_minute;
	int riqi2_year,riqi2_month,riqi2_day,riqi2_hour,riqi2_minute;
	double gap_between_date1,gap_between_date2;
	int d[12]={0,31,59,90,120,151,181,212,243,273,304,334};
	

	
	if(1==0) 
	{
	printf("�޶�����Ϣ��\n");
	}
	else
	{

	printf("����Ҫɾ���Ķ�����ţ�\n");
	
	scanf("%s",s);
	
	//judgetime(x);
	
	
	a=-1;
	
	strcat(s,"\n");
	
	
/*	while (fgets(buf,1000,pf) && c!=m)
	{
	

		
	m++;
	

		
	if(strcmp(buf,s)==0)
	{
		c=m;
		
	}
	
	
	}*/
	for(c=0;fread(&info[c],sizeof(struct info_list),1,pf)!=0;c++)
    {
    	strcpy(buf,info[c].order_ID) ;
    	strcat(buf,"\n") ;
    	if(strcmp(buf,s)==0)
	{
		a=c;
	}
	
	}
	
	
	
	
	
	
	if(a==-1) //�ж�s�Ƿ�Ϊ��������붩������Ƿ���ȷ 
	{
		printf("�˶��������ڣ�\n");
	}
    else  
    {
    	FILE *jingdian;
    
    	
		jingdian=fopen("������Ϣ.txt","rb");
		
		
		
    	printf("�˾���ID��%s\n",info[a].order_NUMBER);
		printf("�˶����ܼ۸�Ԫ����%.2f\n",info[a].order_PRICE);
		
//		fseek(pf,0L,0);
		
		
//		i=0;
		
/*		while (fgets(buf,1000,pf))
		{
		i++;
		
		if(i==c-12)
		{
		strcpy(info[i].order_NUMBER,buf);
		printf("�˾���ID��%s",info[i].order_NUMBER);
		}
		
		if(i==c-1)
		{
		info[i].order_PRICE=atof(buf);	
		n=i;
		printf("�˶����ܼ۸�Ԫ����%.2f\n",info[n].order_PRICE);
		}
		
	
		}*/
		
	
		
//		fseek(jingdian,0L,0);
		
//		fseek(jingdian,0L,0);
		
/*		while (fgets(buf,1000,jingdian))
		{
			m++;
			if((m+19)%19==1)
			{
			x++;
			strcpy(ScenicSpotList[x].ScenicSpot_ID,buf);
			
			
			}
		}*/
		for(jingdianshuliang=0;fread(&ScenicSpotList[jingdianshuliang],sizeof(struct ScenicSpot),1,jingdian)!=0;jingdianshuliang++)
    {
    
	
	}
	
	
		
/*		for(y=0;y<jingdianshuliang;y++)
		{
		
		
	//	strcat(buf,"\n");
		
		
		
		
		if(strcmp(info[c-12].order_NUMBER,ScenicSpotList[y].ScenicSpot_ID)==0)
		{
		
		a=y;
		
		}
		
		
		
		}*/
		
		
   // 	y=0;
		
//		fseek(jingdian,0L,0);
		
	
		//fread(ScenicSpotList,sizeof(ScenicSpotList),8,jingdian);	
	
/*			if(y==19*(a-1)+1)
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
			
			
			
			
			
		}*/
		
    
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
    
    
    FILE *pf2 = fopen("������Ϣ.txt", "rb");
    FILE *pt = fopen("tmp.txt", "wb");//������ʱ�ļ�tmp.txt���洢ɾ��������ݣ�Ȼ�������滻Դ�ļ� 
    	
	i=0;
	
	piaoshu=info[a].order_PEOPLENUM;
    printf("�˶�Ʊ����%d\n",piaoshu);
	riqi_year=info[a].order_YEAR;
	riqi_month=info[a].order_MONTH;
	riqi_day=info[a].order_DAY;
	riqi_hour=info[a].order_HOUR;
	riqi_minute=info[a].order_MINUTE;
	
/*	while(fgets(buf,1000,pf2))
	{
	i++;
	
    if(i<c-12 || i>c)
    {
    
	fputs(buf,pt);
	
	}
    
    if(i==c-7)
    {
    	piaoshu=atoi(buf);
    	printf("�˶�Ʊ����%d\n",piaoshu);
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
	
	
	}*/
	
	
	//�ж��Ƿ�Ϊ����ǰ24Сʱ�� 
	
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
	
	printf("��ܰ��ʾ��������ʱ����%d��%d��%d�� %dʱ%d��\n",riqi2_year,riqi2_month,riqi2_day,riqi2_hour,riqi2_minute);
	
	
	
	if(gap_between_date1-gap_between_date2<=1440 && gap_between_date1-gap_between_date2>0)
	{
	
	FILE *jingdian2;
	
	jingdian2=fopen("temp.txt","wb");//������ʱ�ļ�tmp.txt���洢ɾ��������ݣ�Ȼ�������滻Դ�ļ�
	
//	y=0;
		
//		fseek(jingdian,0L,0);
		
	
/*		while(fgets(buf2,1000,jingdian))
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
			printf("�˾���ʣ��Ʊ����%s",buf2);
			}
			if(y==19*(a-1)+15)
			{
			ScenicSpotList[a].ScenicSpot_VISIT+=piaoshu;
			sprintf(buf2,"%d\n",ScenicSpotList[a].ScenicSpot_VISIT);
			
			fputs(buf2,jingdian2);
			
			printf("�˾���ʣ��������%s",buf2);
			}
			
			if(y==19*(a-1)+19)
			{
			ScenicSpotList[a].ScenicSpot_INCOME-=info[n].order_PRICE;
			sprintf(buf2,"%.2f\n",ScenicSpotList[a].ScenicSpot_INCOME);
			
			fputs(buf2,jingdian2);
			
			printf("�˾���������(Ԫ)��%s",buf2);
			
			}
			
			
		}*/
		
		fwrite(&ScenicSpotList,sizeof(ScenicSpot),jingdianshuliang,jingdian2);
	
		x=0;
		
		for(x=0;x<a;x++)
		fwrite(&info[x],sizeof(info_list),1,pt);
	
		for(x=a+1;x<c;x++)
		fwrite(&info[x],sizeof(info_list),1,pt);
		
		fclose(jingdian2);
		fclose(jingdian);
		
    fclose(pt);
    fclose(pf2);
    
    remove("������Ϣ.txt");
   	rename("temp.txt","������Ϣ.txt");
    	
    	
    
    remove("������Ϣ.txt");
    rename("tmp.txt","������Ϣ.txt");
	
	
	printf("����ɾ���ɹ���\n");
	
	}
	
	if(gap_between_date1-gap_between_date2>1440)
	{
		fclose(pt);
    	fclose(pf2);
    	fclose(jingdian);
		printf("�˶�ʧ�ܣ����ڳ���ǰ24Сʱ�����˶���\n");
		remove("tmp.txt");	
		
	}
	
	
	if(gap_between_date1-gap_between_date2<=0)
	{
		fclose(pt);
    	fclose(pf2);
    	fclose(jingdian);
		printf("ʱ���Ѿ����ˡ��˶�ʧ�ܣ�\n");
		remove("tmp.txt");	
	}
	
	
	}
	

	}
	
	
	

	
    

    fclose(pf);
    
    
	
    
    
	
}

int main()
{
	deleteinfo();
	return 0;
 } 
