#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#define NUMBER 80

struct tourist
{
	char tourist_ID[20];//�ο�����ID
	char tourist_PASSWORD[20];//�ο��������� 
	char tourist_NUM[20];//�ο��������� 
	char tourist_AGE[20];//�ο����������� 
	char tourist_PHONE[20];//�ο�������ϵ�˵绰 
}touristList[NUMBER];



struct  ScenicSpot//������Ϣ�ṹ�� 
{
	char ScenicSpot_ID[80];//����ID
	char ScenicSpot_NAME[80];//������Ϣ
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
	int ScenicSpot_MENPIAO;//������Ʊ����
	int ScenicSpot_VISIT;//����������� 
	int ScenicSpot_YUDING;//����Ԥ���� 
	float ScenicSpot_HAOPING;//��������� 
	char ScenicSpot_LRET[80];//�Ƿ��������˶�ͯ 
	float ScenicSpot_INCOME;//������������
}ScenicSpotList[NUMBER];





//����ṹ�� 
struct info_list//������Ϣ�ṹ�� 
{
	
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
	char order_jidu[20];//�������� 
	 
}info[NUMBER];



//�����ĵ������ĺ���
int countline()
{
    FILE *pf = fopen("������Ϣ.txt", "rb");
    char buf[1000];
    int c=0;
    
    if (!pf)
    
    return 0;
        
    while (fgets(buf,1000,pf))
    c++;
    
    fclose(pf);
    
    return c;
}



//������ɺ���ʾ������Ϣ�ĺ��� 
void show(int n)
{
	
	int i;
	
	
//	printf("���Ķ�����Ϣ���£�\n");
	
	for(i=0;i<n;i++)
	{


	printf("���Ķ����۸��ǣ�%.2fԪ\n",info[i].order_PRICE);
	printf("���Ķ�������ǣ�%s\n",info[i].order_ID);
	
}
	printf("\n");
	
	printf("��Ʊ�ɹ������Ķ�����Ϣ�ѱ��档ϵͳ��������Ч��\n");
	
}


//������Ϣ�ĺ���
void inputinfo()
{
	
	
	
	
	
	FILE *fp;

	int i,n,x,y,m;//ѭ���ṹ�ļ���ֵ 
	
	int a,b,c,d,f,g,h,j,k,l;//�жϸ�����Ϣ�����Ƿ���ȷ�ı��ֵ 
	
	int price;
	
	char buf[1000];
	char buf2[1000];
	char tmp[20];
	
	FILE *jingdian;
	
	jingdian=fopen("������Ϣ.txt","rb");
	 
	 
	 
	fp=fopen("������Ϣ.txt","a");
	printf("��Ҫ�����ٸ������Ʊ��\n");
	scanf("%d",&n);
	if(n<=0 || n>10)
	
	{
		printf("����������������������ֵ����!\n"); 
	}
	else 
	{
	printf("��ֱ�����ÿ�������ID��������ο�����,�ο�������,����ʱ��(�꣬�£��գ�ʱ����)��ÿ��������һ��س�����\n");
	
		fp=fopen("������Ϣ.txt","ab");
		
	
		m=0;
		
	for(i=0;i<n;i++)
	{
		
	
	
	
	
	
		printf("�������%d������������Ϣ��\n",i+1);
		
		x=0;
		
		fseek(jingdian,0L,0);
		
		while (fgets(buf,1000,jingdian))
		{
			m++;
			if(m%19==1)
			{
			x++;
			strcpy(ScenicSpotList[x].ScenicSpot_ID,buf);
			
			
			}
		}
	
		 
		 
		printf("����ID��");
	
		
		
		a=-1;
		
		while(a==-1)
		{

		scanf("%s",info[i].order_NUMBER);
		
		for(y=1;y<=x;y++)
		{
		
		strcpy(buf,info[i].order_NUMBER);
		strcat(buf,"\n");
		
		
		
		if(strcmp(buf,ScenicSpotList[y].ScenicSpot_ID)==0)
		{
	
		a=y;
		
		}
		
		
		
		} 
		
		if(a==-1) 
		{
	
		printf("����ID����������������룡\n");
		
		}
	
		} 
		
		
		
		
		
		
		
		//���뾰��ID�󣬴Ӿ�����Ϣ�ļ��ж�ȡ�þ����ȫ������ 
		
		
		y=0;
		
		fseek(jingdian,0L,0);
		
	
			
		while(fgets(buf,1000,jingdian))
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
			
		}
		
		
		if(ScenicSpotList[i].ScenicSpot_MENPIAO==0)
		{
		printf("��Ǹ���˾���Ʊ�����ꡣԤ��ʧ�ܡ�\n");
		exit(0);
		}
		else
		{
		
		fputs(info[i].order_NUMBER,fp);
		fputs("\n",fp);
		} 
		l=-1;
		
		while(l==-1)
		
		{

		printf("�ο���ݣ�ѧ����������");
		
		
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
		printf("����������������룡\n");
		}
		
		}
		
		
		
		
		
		
		printf("�ο���ݣ�������������");
		
		
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
		printf("����������������룡\n");
		}
		
		}
		
		
		
		
		
		printf("�ο���ݣ���ͨ����������");
		
		
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
		printf("����������������룡\n");
		}
		
		}
		
		
		
		
		
		printf("�ο������Σ�");
		scanf("%s",info[i].order_AGE);
		
		

		info[i].order_PEOPLENUM=info[i].order_IDENTITY1+info[i].order_IDENTITY2+info[i].order_IDENTITY3;//����ο��������� 
		
		
		
		
		if(ScenicSpotList[i].ScenicSpot_MENPIAO-info[i].order_PEOPLENUM>=0)
		{
		
			l=0;
			
			fprintf(fp,"%d",info[i].order_IDENTITY1);
			fputs("\n",fp);
			fprintf(fp,"%d",info[i].order_IDENTITY2);
			fputs("\n",fp);
			fprintf(fp,"%d",info[i].order_IDENTITY3);		
			fputs("\n",fp);
			fputs(info[i].order_AGE,fp);
			fputs("\n",fp);
		
		}
			else
			printf("�ο������������������������������룡\n");
			
		
		}
	
		
		fprintf(fp,"%d",info[i].order_PEOPLENUM);
		fputs("\n",fp);
		
		
		printf("����ʱ�䣨�꣩");
		
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
		printf("����������\n");
		}
		
		}
		
		fprintf(fp,"%d",info[i].order_YEAR);
		fputs("\n",fp);
		
		
		printf("����ʱ�䣨�£�");
		
		
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
		printf("�·��������\n");
		}
		
		}
		
		
		fprintf(fp,"%d",info[i].order_MONTH);
		fputs("\n",fp);
		
		printf("����ʱ�䣨�գ�");
		
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
		printf("�����������\n");
		}
		
		}
		
		
		fprintf(fp,"%d",info[i].order_DAY);
		fputs("\n",fp);
		
		
		printf("����ʱ�䣨ʱ��");
		
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
		printf("ʱ���������\n");
		}
		
		}
		
		fprintf(fp,"%d",info[i].order_HOUR);
		fputs("\n",fp);
		
		
		printf("����ʱ�䣨�֣�");
		
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
		printf("ʱ���������\n");
		}
		
		}
		
		fprintf(fp,"%d",info[i].order_MINUTE);
		fputs("\n",fp);
		
		
		//���ݶ��������붩Ʊ���������ܼ۸� 
		y=0;
		
		fseek(jingdian,0L,0);
		
		if(info[i].order_MONTH<=6)
		
		{
			
		while(fgets(buf,1000,jingdian))
		{
			y++;
			if(y==19*(a-1)+4)
			{
			price=atoi(buf);
			
			}
			
		}
	
	
		}
		
		y=0;
		
		fseek(jingdian,0L,0);
		
		if(info[i].order_MONTH>6)
		
		{
			
		while(fgets(buf,1000,jingdian))
		{
			y++;
			if(y==19*(a-1)+5)
			{
			
			price=atoi(buf);
			
			}
			
		}
	
	
		}
		
		
		
		
		
		//���ݼ��� 
		ScenicSpotList[i].ScenicSpot_MENPIAO-=info[i].order_PEOPLENUM;//�ۼ�Ʊ�� 
		
		info[i].order_PRICE=info[i].order_IDENTITY1*price*ScenicSpotList[i].ScenicSpot_DISCOUNT1+info[i].order_IDENTITY2*price*ScenicSpotList[i].ScenicSpot_DISCOUNT2+info[i].order_IDENTITY3*price*ScenicSpotList[i].ScenicSpot_DISCOUNT3;
		
		printf("�����ܼ۸�Ԫ��:%.2f\n",info[i].order_PRICE);
		
		fprintf(fp,"%.2f",info[i].order_PRICE);
		fputs("\n",fp);
		
		
		
		
		//���ݶ����������ɶ������ 
		strcpy(touristList[i].tourist_ID,"�ο�ID");//�ο�ID����ȡ 
		
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
		
		fputs(info[i].order_ID,fp);
	
		
		fputs("\n",fp);
		
		//һ����Ϣ������֮�󣬴������ļ��Դ洢������Ϣ�仯�� 
		FILE *jingdian2;
	
		jingdian2=fopen("temp.txt","wb");//������ʱ�ļ�tmp.txt���洢ɾ��������ݣ�Ȼ�������滻Դ�ļ� 
	
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
			printf("�˾���ʣ��Ʊ����%s",buf2);
			}
			if(y==19*(a-1)+15)
			{
				ScenicSpotList[i].ScenicSpot_VISIT-=info[i].order_PEOPLENUM;
			sprintf(buf2,"%d\n",ScenicSpotList[i].ScenicSpot_VISIT);
			
			fputs(buf2,jingdian2);
			
			printf("�˾���ʣ��������%s",buf2);
			}
			if(y==19*(a-1)+16)
			{
			ScenicSpotList[i].ScenicSpot_YUDING+=info[i].order_PEOPLENUM;
			sprintf(buf2,"%d\n",ScenicSpotList[i].ScenicSpot_YUDING);
			
			fputs(buf2,jingdian2);
			
			printf("�˾���Ԥ������%s",buf2);
			
			}
			if(y==19*(a-1)+19)
			{
			
			ScenicSpotList[i].ScenicSpot_INCOME+=info[i].order_PRICE;
			sprintf(buf2,"%.2f\n",ScenicSpotList[i].ScenicSpot_INCOME);
			
			fputs(buf2,jingdian2);
			
			printf("�˾��������룺%s",buf2);
			
			}
		}
		
		
		fclose(jingdian2);
		
		
		
		
		
		
		
	}
	
		fclose(jingdian);
		
		remove("������Ϣ.txt");
		rename("temp.txt","������Ϣ.txt");
	fclose(fp);
	
	
//	fwrite(&ScenicSpotList,1000,num3,jingdian);
	
	
	
	
	show(n);
	
	
	}
}



//�����Ϣ�ĺ��� 
void outputinfo()
{
	
	FILE *fp;
	int i;
	
	char buf[1000];
	
	i=0;
	
	fp=fopen("������Ϣ.txt","rb") ;
	
	printf("�������ж�����Ϣ���£�\n");
	
	while (fgets(buf,1000,fp))
	{
	
		
		i++;
		
		if(i%13==1) 
		printf("����ID��%s",buf);
		
		if(i%13==2) 
		printf("ѧ��������%s",buf);
		
		
		if(i%13==3) 
		printf("����������%s",buf);
		
		
		if(i%13==4) 
		printf("��ͨ�ο�������%s",buf);
		
		if(i%13==5) 
		printf("�ο������Σ�%s",buf);
		
		if(i%13==6) 
		printf("����������Ʊ��������%s",buf);
		
		if(i%13==7) 
		printf("��Ʊʱ�䣨�꣩��%s",buf);
		
		if(i%13==8) 
		printf("��Ʊʱ�䣨�£���%s",buf);
		
		if(i%13==9) 
		printf("��Ʊʱ�䣨�գ���%s",buf);
		
		if(i%13==10) 
		printf("��Ʊʱ�䣨ʱ����%s",buf);
		
		if(i%13==11) 
		printf("��Ʊʱ�䣨�֣���%s",buf);
		
		if(i%13==12) 
		printf("�����ܼ۸�Ԫ����%s",buf);
		
		if(i%13==0) 
		printf("������ţ�%s",buf);

	}
	
	if(i==0)
	{
		printf("�޶�����Ϣ��\n");
	}

	fclose(fp);
 }
  
  


//�˶��ĺ��� 
void deleteinfo()
{
	FILE *pf = fopen("������Ϣ.txt", "rb");
	
	
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
	

	
	if(countline()==0) 
	{
	printf("�޶�����Ϣ��\n");
	}
	else
	{

	printf("����Ҫɾ���Ķ�����ţ�\n");
	
	scanf("%s",s);
	
	//judgetime(x);
	
	
	
	strcat(s,"\n");
	
	m=0;
	
	while (fgets(buf,1000,pf) && c!=m)
	{
	

		
	m++;
	

		
	if(strcmp(buf,s)==0)
	{
		c=m;
		
	}
	
	
	}
	
	
	
	
	
	
	
	
	if(c==-1 || c%13!=0) //�ж�s�Ƿ�Ϊ��������붩������Ƿ���ȷ 
	{
		printf("�˶��������ڣ�\n");
	}
    else  
    {
    	FILE *jingdian;
    
    	
		jingdian=fopen("������Ϣ.txt","rb");
		
		
		
    	
		
		fseek(pf,0L,0);
		
		
		i=0;
		
		while (fgets(buf,1000,pf))
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
		
	
		}
		
		
		x=0;
		m=0;
		
//		fseek(jingdian,0L,0);
		
		fseek(jingdian,0L,0);
		
		while (fgets(buf,1000,jingdian))
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
    
    
    FILE *pf2 = fopen("������Ϣ.txt", "rb");
    FILE *pt = fopen("tmp.txt", "wb");//������ʱ�ļ�tmp.txt���洢ɾ��������ݣ�Ȼ�������滻Դ�ļ� 
    	
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
	
	
	}
	
	
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
			
			
		}
		
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

//��ʾ���˵� 
void PrintMainMenu()
{
	printf("**************************���˵�**************************\n");
	printf("\t\t\t����������ı����ִ�����\n"); 
	printf("\t\t\t1.��Ӷ���\n");
	printf("\t\t\t2.��ѯ����\n");
	printf("\t\t\t3.�˶�\n");
	printf("\t\t\t4.��ѯȫ��������Ϣ���ѷϳ���\n");
	printf("\t\t\t5.�˳�\n");
	printf("*************************************************************\n");
} 



int main()
{
	char cmd[100];
    
    cmd[0]='9';
    
    
    
    
    
    printf("\t\t��ӭʹ�ñ����ʵ��ѧ�����ζ�Ʊϵͳ\n");
    printf("\n");
    PrintMainMenu(); 

	    while(cmd[0]!='5')
    {
    
	
    gets(cmd);//�������˵���Ӧ���������� 
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
        	printf("��������!\n");
		}
      	if(cmd[0]=='5')
        {
        	printf("�ټ�.");
		}
        
    }
	
	

	

	return 2;
}
