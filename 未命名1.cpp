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
						fputs(a[i].order_NUMBER,fp1);
						fputs("\n",fp1);
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
				if(a[i].order_IDENTITY2>=0)
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
				if(a[i].order_IDENTITY3>=0)
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
			else
			{
				fprintf(fp1,"%d",a[i].order_IDENTITY1);
			fputs("\n",fp1);
			fprintf(fp1,"%d",a[i].order_IDENTITY2);
			fputs("\n",fp1);
			fprintf(fp1,"%d",a[i].order_IDENTITY3);		
			fputs("\n",fp1);
			}
			//��д������ 
			printf("�ο������Σ�");
			gets(a[i].order_AGE);
			fputs(a[i].order_AGE,fp1);
			fputs("\n",fp1);
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
					printf("�����������\n���������룺");
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
			char *tmp;
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
