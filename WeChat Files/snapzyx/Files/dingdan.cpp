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

//������Ϣ�ĺ���
void inputinfo()
{
	FILE *fp1;//������Ϣ 
	FILE *fp2;//������Ϣ
	FILE *fp3;//Ԥ�澰����Ϣ
	struct info_list a[80];
	int c=0,i;//idѭ������������ 
	int ord;//��¼�ڼ������� 
	int shuliang;//����ľ�������
	int panduan=1,panduan1=1;//�ж�ѭ��  
	fp1=fopen("������Ϣ.txt","r"); 
	fp2=fopen("������Ϣ.txt","a");
	fp3=fopen("Ԥ�澰����Ϣ1.txt","w");
    fread(&ScenicSpotList,sizeof(struct  ScenicSpot),1,fp1);
	printf("��Ҫ�����ٸ������Ʊ��\n");
	scanf("%d",&shuliang);
	if(shuliang<=0 || shuliang>10)
	{
		printf("����������������������ֵ����!\n"); 
	}
	else 
	{
		printf("��ֱ�����ÿ�������ID��������ο�����,�ο�������,����ʱ��(�꣬�£��գ�ʱ����)��ÿ��������һ��س�����\n");
		for(i=0;i<shuliang;i++)
		{
			printf("�������%d������������Ϣ��\n",i+1);
			printf("����ID��");
			while(panduan==1) 
			{
				gets(a[i].order_NUMBER);
				for(c=0;c<8;c++)//���������� 
    			{
					if(strcmp(a[i].order_NUMBER,ScenicSpotList[c].ScenicSpot_ID)==0)//�ж����뾰��ID�Ƿ�ϸ� 
					{
						ord=c;
						panduan=0;
					}
				}
				if(panduan==1)
				printf("����ID���벻��ȷ\n����������:");
			}
			//ѧ������ 
			printf("�ο���ݣ�ѧ����������");
			while(panduan==0)
			{
				scanf("%d",&a[i].order_IDENTITY1);
				if(a[i].order_IDENTITY1>=0)
				panduan=1;
				else
				{
					printf("�������벻��ȷ\n���������룺"); 
					panduan=0;
				} 
			}
			//��������
			panduan=0; 
			printf("�ο���ݣ�������������");
			while(panduan==0)
			{
				scanf("%d",&a[i].order_IDENTITY2);
				if(a[i].order_IDENTITY1>=0)
				panduan=1;
				else
				{
					printf("�������벻��ȷ\n���������룺"); 
					panduan=0;
				} 
			}
			//��ͨ�ο�����
			panduan=0; 
			printf("�ο���ݣ���ͨ�ο���������");
			while(panduan==0)
			{
				scanf("%d",&a[i].order_IDENTITY3);
				if(a[i].order_IDENTITY1>=0)
				panduan=1;
				else
				{
					printf("�������벻��ȷ\n���������룺"); 
					panduan=0;
				} 
			}
			a[i].order_PEOPLENUM=a[i].order_IDENTITY1+a[i].order_IDENTITY2+a[i].order_IDENTITY3;
			if(a[i].order_PEOPLENUM>ScenicSpotList[ord].ScenicSpot_MENPIAO)//�ж��Ƿ���Ʊ 
			{
				printf("�þ���ʣ��Ʊ��Ϊ%d\n",ScenicSpotList[ord].ScenicSpot_MENPIAO);
				printf("Ԥ��ʧ�ܡ�"); 
			}
			//��д������ 
			printf("�ο������Σ�");
			gets(a[i].order_AGE);
			//��д��������
			printf("����ʱ�䣨�꣩��");
			while(panduan1==1)
			{
				scanf("%d",a[i].order_YEAR);
				if(a[i].order_YEAR>=1000&&a[i].order_YEAR<=9999)
				panduan1=0;
				else
				{
					printf("����������\n���������룺");
					panduan1=1; 
				}
			}
			panduan1=1; 
			printf("����ʱ�䣨�£���");
			while(panduan1==1)
			{
				scanf("%d",a[i].order_MONTH);
				if(a[i].order_MONTH>=1&&a[i].order_MONTH<=12)
				panduan1=0;
				else
				{
					printf("�·��������\n���������룺");
					panduan1=1; 
				}
			} 
			panduan1=1; 
			printf("����ʱ�䣨�գ���");
			while(panduan1==1)
			{
				scanf("%d",a[i].order_DAY);
				if(a[i].order_DAY>=1&&a[i].order_DAY<=31)
				panduan1=0;
				else
				{
					printf("�շ��������\n���������룺");
					panduan1=1; 
				}
			} 
			panduan1=1; 
			printf("����ʱ�䣨ʱ����");
			while(panduan1==1)
			{
				scanf("%d",a[i].order_HOUR);
				if(a[i].order_HOUR>=0&&a[i].order_HOUR<=23)
				panduan1=0;
				else
				{
					printf("Сʱ�������\n���������룺");
					panduan1=1; 
				}
			} 
			panduan1=1; 
			printf("����ʱ�䣨�֣���");
			while(panduan1==1)
			{
				scanf("%d",a[i].order_MINUTE);
				if(a[i].order_MINUTE>=0&&a[i].order_MINUTE<=59)
				panduan1=0;
				else
				{
					printf("�����������\n���������룺");
					panduan1=1; 
				}
			}
			//�����ܼ۸�
			if(a[i].order_MONTH>=5&&a[i].order_MONTH<=10)//�����۸� 
			a[i].order_PRICE=ScenicSpotList[ord].ScenicSpot_DISCOUNT1*a[i].order_IDENTITY1*ScenicSpotList[ord].ScenicSpot_PRICE1+
			                 ScenicSpotList[ord].ScenicSpot_DISCOUNT2*a[i].order_IDENTITY2*ScenicSpotList[ord].ScenicSpot_PRICE1+
			                 ScenicSpotList[ord].ScenicSpot_DISCOUNT3*a[i].order_IDENTITY3*ScenicSpotList[ord].ScenicSpot_PRICE1;
			else//�����۸� 
			a[i].order_PRICE=ScenicSpotList[ord].ScenicSpot_DISCOUNT1*a[i].order_IDENTITY1*ScenicSpotList[ord].ScenicSpot_PRICE2+
			                 ScenicSpotList[ord].ScenicSpot_DISCOUNT2*a[i].order_IDENTITY2*ScenicSpotList[ord].ScenicSpot_PRICE2+
			                 ScenicSpotList[ord].ScenicSpot_DISCOUNT3*a[i].order_IDENTITY3*ScenicSpotList[ord].ScenicSpot_PRICE2;
			                 
			//���ݼ��� 
			ScenicSpotList[ord].ScenicSpot_MENPIAO-=a[i].order_PEOPLENUM;//�ۼ�Ʊ�� 
			printf("�����ܼ۸�Ԫ��:%.2f\n",a[i].order_PRICE);
			
			//���ݶ����������ɶ������ 
			strcpy(touristList[i].tourist_ID,"�ο�ID");//�ο�ID����ȡ 		
			strcpy(a[i].order_ID,touristList[i].tourist_ID); 
			int tmp;
			sprintf(tmp,"%d",a[i].order_YEAR);
			strcat(a[i].order_ID,tmp);
			//��		
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
			//�� 
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
			//ʱ 
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
			//�� 	
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
		
			fputs(a[i].order_ID,fp);
			
			
			
			
			
			
		}
		show(n);		
	}
	
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}

//�����Ϣ�ĺ���
void outputinfo()
{
	FILE *fp;
	int i=0;
	fp=fopen("������Ϣ.txt","r");
	fread(&info,sizeof(struct info_list),1,fp);
	printf("�������ж�����Ϣ���£�\n");
	if(info[i].order_ID!=NULL)
	{
		do
		{
			printf("����ID��%s",info[i].order_ID);
			printf("ѧ��������%d",info[i].order_IDENTITY1);
			printf("����������%d",info[i].order_IDENTITY2);
			printf("��ͨ��������%d",info[i].order_IDENTITY3);
			printf("�ο������Σ�%s",info[i].order_AGE);
			printf("����������Ʊ��������%d",info[i].order_PEOPLENUM);
			printf("��Ʊʱ�䣨�꣩��%d",info[i].order_YEAR);
			printf("��Ʊʱ�䣨�£���%d",info[i].order_MONTH);
			printf("��Ʊʱ�䣨�գ���%d",info[i].order_DAY);
			printf("��Ʊʱ�䣨ʱ����%d",info[i].order_HOUR);
			printf("��Ʊʱ�䣨�֣���%d",info[i].order_MINUTE);
			printf("�����ܼ۸�Ԫ����%d",info[i].order_PRICE);
			printf("������ţ�%s",info[i].order_ID);
			i++;
		} 
		while(info[i].order_ID==NULL);
    }
    else
    printf("�޶�����Ϣ��\n");

} 
//�˶�����
void deleteinfo()
{
	FILE *fp1=fopen("������Ϣ.txt", "r");
	FILE *fp2=fopen("�ݴ���Ϣ.txt", "r");
	struct info_list b[80];
	int i=0,v,w=0;//���
	int code=-1;//��¼�ڼ������� 
	fread(&info,sizeof(struct info_list),1,fp1);
	if(info.order_ID==NULL) 
	printf("�޶�����Ϣ��\n");
	else
	{
		printf("����Ҫɾ���Ķ�����ţ�\n");
		gets(b[i].order_ID);
		for(v=0;v<1000;v++)
		{
			if(strcmp(b[i].order_ID,info[v].order_ID)==0)
			code=v;
		}
		if(v<0)
		printf("���޴˵���");
		else
		{
			v=0;
			while(fread(&info,sizeof(struct info_list),1,fp1))//ɾ����Ϣ֮���޸��ļ����ƣ���Ϊ�µĶ����ļ� 
			{
				if(strcmp(b[i].order_ID,info[v].order_ID)==0)
				v--;
				if(strcmp(b[i].order_ID,info[v].order_ID)!=0) 
				fwrite(&info[v],sizeof(struct info_list),1,fp2);
				v++;
			} 
				
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
