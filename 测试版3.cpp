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



//������Ϣ�ĺ���
void inputinfo()
{
	
	
	
	
	
	FILE *fp;

	int i,n,x,y;//ѭ���ṹ�ļ���ֵ 
	
	int jingdianshuliang;
	int a,b,c,d,f,g,h,j,k,l;//�жϸ�����Ϣ�����Ƿ���ȷ�ı��ֵ 
	
	int price;
	
	char buf[1000];
	char buf2[1000];
	char tmp[20];
	
	FILE *jingdian;
	
	jingdian=fopen("������Ϣ.txt","rb");
	 
	 
	 
	fp=fopen("������Ϣ.txt","ab");
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
		
	
//		m=0;
		
	for(i=0;i<n;i++)
	{
		
	
	
	
	
	
		printf("�������%d������������Ϣ��\n",i+1);
		
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
//	printf("����������%d\n",jingdianshuliang);
	
		printf("����ID��");
	
		
		
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
		
		//printf("a��%d\n",a);
		
		} 
		
		if(a==-1) 
		{
	
		printf("����ID����������������룡\n");
		
		}
	
		} 
		
		
		
		
		
		
		
		//���뾰��ID�󣬴Ӿ�����Ϣ�ļ��ж�ȡ�þ����ȫ������ 
		
		
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
		printf("��Ǹ���˾���Ʊ�����ꡣԤ��ʧ�ܡ�\n");
		exit(0);
		}
		else
		{
		
		
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
		
		
		
		
		if(ScenicSpotList[a].ScenicSpot_MENPIAO-info[i].order_PEOPLENUM>=0)
		{
		
			l=0;
			
	
		
		}
			else
			printf("�ο������������������������������룡\n");
			
		
		}
	
		

		
		
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
		
		
		
		
		//���ݶ��������붩Ʊ���������ܼ۸� 
//		y=0;
		
//		fseek(jingdian,0L,0);
		
		if(info[i].order_MONTH<=6)
		
		{
			
//		while(fgets(buf,1000,jingdian))
//		{
//			y++;
//			if(y==19*(a-1)+4)
//			{
			strcpy(info[i].order_jidu,"����");
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
			strcpy(info[i].order_jidu,"����");
			price=ScenicSpotList[a].ScenicSpot_PRICE2;
			
//			}
			
		}
	
	
//		}
		
		
		
		
		
		//���ݼ��� 
		ScenicSpotList[a].ScenicSpot_MENPIAO-=info[i].order_PEOPLENUM;//�ۼ�Ʊ�� 
		
		info[i].order_PRICE=info[i].order_IDENTITY1*price*ScenicSpotList[a].ScenicSpot_DISCOUNT1+info[i].order_IDENTITY2*price*ScenicSpotList[a].ScenicSpot_DISCOUNT2+info[i].order_IDENTITY3*price*ScenicSpotList[a].ScenicSpot_DISCOUNT3;
		
		ScenicSpotList[a].ScenicSpot_VISIT-=info[i].order_PEOPLENUM;
		
		ScenicSpotList[a].ScenicSpot_YUDING+=info[i].order_PEOPLENUM;
		
		ScenicSpotList[a].ScenicSpot_INCOME+=info[i].order_PRICE;
		
		printf("�����ܼ۸�Ԫ��:%.2f\n",info[i].order_PRICE);
		
		
		
		
		
		
		//���ݶ����������ɶ������ 
		strcpy(info[i].order_ID1,"�ο�ID");//�ο�ID����ȡ 
		
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
		
		
	
		
		
		
		//һ����Ϣ������֮�󣬴������ļ��Դ洢������Ϣ�仯�� 
		FILE *jingdian2;
	
		jingdian2=fopen("temp.txt","wb");//������ʱ�ļ�tmp.txt���洢ɾ��������ݣ�Ȼ�������滻Դ�ļ� 
	
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
			printf("�˾���ʣ��Ʊ����%s",buf2);
			}
			if(y==19*(a-1)+15)
			{
				
			sprintf(buf2,"%d\n",ScenicSpotList[i].ScenicSpot_VISIT);
			
			fputs(buf2,jingdian2);
			
			printf("�˾���ʣ��������%s",buf2);
			}
			if(y==19*(a-1)+16)
			{
			
			sprintf(buf2,"%d\n",ScenicSpotList[i].ScenicSpot_YUDING);
			
			fputs(buf2,jingdian2);
			
			printf("�˾���Ԥ������%s",buf2);
			
			}
			if(y==19*(a-1)+19)
			{
			
			
			sprintf(buf2,"%.2f\n",ScenicSpotList[i].ScenicSpot_INCOME);
			
			fputs(buf2,jingdian2);
			
			printf("�˾��������룺%s",buf2);
			
			}
		}*/
		
		fwrite(&ScenicSpotList,sizeof(ScenicSpot),jingdianshuliang,jingdian2);
		fwrite(&info,sizeof(info_list),jingdianshuliang,fp);
		
		fclose(jingdian2);
		
		
		
		
		
		
		
	}
	
		fclose(jingdian);
		
		remove("������Ϣ.txt");
		rename("temp.txt","������Ϣ.txt");
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
