#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#define NUMBER 80

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
	int ScenicSpot_MENPIAO;//������Ʊ����
	int ScenicSpot_VISIT;//����������� 
	int ScenicSpot_YUDING;//����Ԥ���� 
	float ScenicSpot_HAOPING;//��������� 
	char ScenicSpot_LRET[80];//�Ƿ��������˶�ͯ 
	float ScenicSpot_INCOME;//������������ 
}ScenicSpotList[NUMBER];
void jingdianxinxi()//��ʼ��������Ϣ 
{
	FILE *jingdian;
	
	jingdian=fopen("��������.txt","wb");
	
	char tmp[20];
	int num3=0;
	
	//1�ž���
	
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0001");//����ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"���ﳤ��");//�������� 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"�й�ΰ��ľ��½���");//������
	ScenicSpotList[num3].ScenicSpot_PRICE1=200;//����������Ʊ�۸�
	ScenicSpotList[num3].ScenicSpot_PRICE2=140;//���㵭����Ʊ�۸�  
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"4Сʱ");//��������ʱ��
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.8;//ѧ���ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.7;//�����ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//��ͨ�ۿ���Ϣ
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5��");//���㼶�� 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"��");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"����");//������������ 
	ScenicSpotList[num3].ScenicSpot_COST=100000;//����ά������
	ScenicSpotList[num3].ScenicSpot_MENPIAO=700; //������Ʊ��
	ScenicSpotList[num3].ScenicSpot_VISIT=150000;//�����������
	ScenicSpotList[num3].ScenicSpot_YUDING=2000;//����Ԥ����
	ScenicSpotList[num3].ScenicSpot_HAOPING=0.81;//���������
	strcpy(ScenicSpotList[num3].ScenicSpot_LRET,"��");//�Ƿ��������˶�ͯ 
	ScenicSpotList[num3].ScenicSpot_INCOME=0.0;
	
	fputs(ScenicSpotList[num3].ScenicSpot_ID,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_NAME,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_INTRO,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_PRICE1);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_PRICE2);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	fputs(ScenicSpotList[num3].ScenicSpot_TIME,jingdian);
	fputs("\n",jingdian);
	
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT1);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT2);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT3);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	fputs(ScenicSpotList[num3].ScenicSpot_GRADE,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_NUMBER,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_AREA,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_COST);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_MENPIAO);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_VISIT);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_YUDING);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%lf",ScenicSpotList[num3].ScenicSpot_HAOPING);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_LRET,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_INCOME);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	num3++; 
	//2�ž���
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0002");//����ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"����ɽˮ");//�������� 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"����ɽˮ������");//������ 
	ScenicSpotList[num3].ScenicSpot_PRICE1=350;//����������Ʊ�۸�
	ScenicSpotList[num3].ScenicSpot_PRICE2=300;//���㵭����Ʊ�۸�  
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"2.5Сʱ");//��������ʱ��
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=1.0;//ѧ���ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=1.0;//�����ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=1.0;//��ͨ�ۿ���Ϣ  
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5��");//���㼶�� 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"��");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"����");//������������ 
	ScenicSpotList[num3].ScenicSpot_COST=78000;//����ά������
	ScenicSpotList[num3].ScenicSpot_MENPIAO=1100;//������Ʊ��
	ScenicSpotList[num3].ScenicSpot_VISIT=175000;//�����������
	ScenicSpotList[num3].ScenicSpot_YUDING=4500;//����Ԥ����
	ScenicSpotList[num3].ScenicSpot_HAOPING=0.89;//���������
	strcpy(ScenicSpotList[num3].ScenicSpot_LRET,"��");//�Ƿ��������˶�ͯ
	ScenicSpotList[num3].ScenicSpot_INCOME=0.0;
	
	fputs(ScenicSpotList[num3].ScenicSpot_ID,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_NAME,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_INTRO,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_PRICE1);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_PRICE2);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	fputs(ScenicSpotList[num3].ScenicSpot_TIME,jingdian);
	fputs("\n",jingdian);
	
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT1);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT2);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT3);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	fputs(ScenicSpotList[num3].ScenicSpot_GRADE,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_NUMBER,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_AREA,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_COST);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_MENPIAO);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_VISIT);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_YUDING);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%lf",ScenicSpotList[num3].ScenicSpot_HAOPING);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_LRET,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_INCOME);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	
	num3++;
	//3�ž���
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0003");//����ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"�ʹ�");//�������� 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"���������Ļʹ�");//������
	ScenicSpotList[num3].ScenicSpot_PRICE1=100;//����������Ʊ�۸�
	ScenicSpotList[num3].ScenicSpot_PRICE2=50;//���㵭����Ʊ�۸� 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"3.5Сʱ");//��������ʱ��
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.8;//ѧ���ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.75;//�����ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//��ͨ�ۿ���Ϣ 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5��");//���㼶�� 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"10��");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"����");//������������ 
	ScenicSpotList[num3].ScenicSpot_COST=40000;//����ά������
	ScenicSpotList[num3].ScenicSpot_MENPIAO=1000;//������Ʊ��
	ScenicSpotList[num3].ScenicSpot_VISIT=100000;//�����������
	ScenicSpotList[num3].ScenicSpot_YUDING=3462;//����Ԥ����
	ScenicSpotList[num3].ScenicSpot_HAOPING=0.82;//���������
	strcpy(ScenicSpotList[num3].ScenicSpot_LRET,"��");//�Ƿ��������˶�ͯ 
	ScenicSpotList[num3].ScenicSpot_INCOME=0.0;
	
	fputs(ScenicSpotList[num3].ScenicSpot_ID,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_NAME,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_INTRO,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_PRICE1);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_PRICE2);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	fputs(ScenicSpotList[num3].ScenicSpot_TIME,jingdian);
	fputs("\n",jingdian);
	
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT1);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT2);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT3);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	fputs(ScenicSpotList[num3].ScenicSpot_GRADE,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_NUMBER,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_AREA,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_COST);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_MENPIAO);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_VISIT);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_YUDING);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%lf",ScenicSpotList[num3].ScenicSpot_HAOPING);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_LRET,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_INCOME);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	
	num3++;
	//4�ž���
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0004");//����ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"��������");//�������� 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"��ʷ�ƾá����������ķ羰����ʤ��");//������ 
	ScenicSpotList[num3].ScenicSpot_PRICE1=230;//����������Ʊ�۸�
	ScenicSpotList[num3].ScenicSpot_PRICE2=170;//���㵭����Ʊ�۸� 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"3Сʱ");//��������ʱ��
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.7;//ѧ���ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.5;//�����ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//��ͨ�ۿ���Ϣ 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5��");//���㼶�� 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"2��");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"����");//������������ 
	ScenicSpotList[num3].ScenicSpot_COST=51000;//����ά������
	ScenicSpotList[num3].ScenicSpot_MENPIAO=2000;//������Ʊ��
	ScenicSpotList[num3].ScenicSpot_VISIT=89000;//�����������
	ScenicSpotList[num3].ScenicSpot_YUDING=4500;//����Ԥ����
	ScenicSpotList[num3].ScenicSpot_HAOPING=0.89;//���������
	strcpy(ScenicSpotList[num3].ScenicSpot_LRET,"��");//�Ƿ��������˶�ͯ
	ScenicSpotList[num3].ScenicSpot_INCOME=0.0;
	
	fputs(ScenicSpotList[num3].ScenicSpot_ID,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_NAME,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_INTRO,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_PRICE1);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_PRICE2);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	fputs(ScenicSpotList[num3].ScenicSpot_TIME,jingdian);
	fputs("\n",jingdian);
	
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT1);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT2);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT3);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	fputs(ScenicSpotList[num3].ScenicSpot_GRADE,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_NUMBER,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_AREA,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_COST);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_MENPIAO);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_VISIT);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_YUDING);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%lf",ScenicSpotList[num3].ScenicSpot_HAOPING);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_LRET,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_INCOME);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	
	num3++;
	//5�ž���
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0005");//����ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"����԰��");//�������� 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"�ƾ���ʷ��˽��԰��");//������ 
	ScenicSpotList[num3].ScenicSpot_PRICE1=200;//����������Ʊ�۸�
	ScenicSpotList[num3].ScenicSpot_PRICE2=140;//���㵭����Ʊ�۸� 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"2Сʱ");//��������ʱ��
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.75;//ѧ���ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.6;//�����ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//��ͨ�ۿ���Ϣ 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4��");//���㼶�� 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"1.5��");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"����");//������������ 
	ScenicSpotList[num3].ScenicSpot_COST=63000;//����ά������
	ScenicSpotList[num3].ScenicSpot_MENPIAO=800;//������Ʊ��
	ScenicSpotList[num3].ScenicSpot_VISIT=65000;//�����������
	ScenicSpotList[num3].ScenicSpot_YUDING=4100;//����Ԥ����
	ScenicSpotList[num3].ScenicSpot_HAOPING=0.79;//���������
	strcpy(ScenicSpotList[num3].ScenicSpot_LRET,"��");//�Ƿ��������˶�ͯ
	ScenicSpotList[num3].ScenicSpot_INCOME=0.0;
	
	fputs(ScenicSpotList[num3].ScenicSpot_ID,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_NAME,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_INTRO,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_PRICE1);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_PRICE2);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	fputs(ScenicSpotList[num3].ScenicSpot_TIME,jingdian);
	fputs("\n",jingdian);
	
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT1);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT2);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT3);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	fputs(ScenicSpotList[num3].ScenicSpot_GRADE,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_NUMBER,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_AREA,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_COST);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_MENPIAO);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_VISIT);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_YUDING);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%lf",ScenicSpotList[num3].ScenicSpot_HAOPING);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_LRET,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_INCOME);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	
	num3++;
	//6�ž���
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0006");//����ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"���ջ�ɽ");//�������� 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"���µ�һ��ɽ");//������ 
	ScenicSpotList[num3].ScenicSpot_PRICE1=225;//����������Ʊ�۸�
	ScenicSpotList[num3].ScenicSpot_PRICE2=175;//���㵭����Ʊ�۸�  
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"3.5Сʱ");//��������ʱ��
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.8;//ѧ���ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.8;//�����ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//��ͨ�ۿ���Ϣ 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4��");//���㼶�� 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"3.1��");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"��ɽ��");//������������ 
	ScenicSpotList[num3].ScenicSpot_COST=15000;//����ά������
	ScenicSpotList[num3].ScenicSpot_MENPIAO=900;//������Ʊ��
	ScenicSpotList[num3].ScenicSpot_VISIT=78000;//�����������
	ScenicSpotList[num3].ScenicSpot_YUDING=4120;//����Ԥ����
	ScenicSpotList[num3].ScenicSpot_HAOPING=0.80;//���������
	strcpy(ScenicSpotList[num3].ScenicSpot_LRET,"��");//�Ƿ��������˶�ͯ
	ScenicSpotList[num3].ScenicSpot_INCOME=0.0;
	
	fputs(ScenicSpotList[num3].ScenicSpot_ID,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_NAME,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_INTRO,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_PRICE1);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_PRICE2);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	fputs(ScenicSpotList[num3].ScenicSpot_TIME,jingdian);
	fputs("\n",jingdian);
	
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT1);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT2);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT3);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	fputs(ScenicSpotList[num3].ScenicSpot_GRADE,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_NUMBER,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_AREA,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_COST);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_MENPIAO);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_VISIT);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_YUDING);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%lf",ScenicSpotList[num3].ScenicSpot_HAOPING);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_LRET,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_INCOME);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	
	num3++;
	//7�ž���
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0007");//����ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"������Ͽ");//�������� 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"��������Ϊ����׳����ɽˮ����");//������  
	ScenicSpotList[num3].ScenicSpot_PRICE1=240;//����������Ʊ�۸�
	ScenicSpotList[num3].ScenicSpot_PRICE2=200;//���㵭����Ʊ�۸� 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"2.6Сʱ");//��������ʱ��
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.75;//ѧ���ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.75;//�����ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//��ͨ�ۿ���Ϣ
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4��");//���㼶�� 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"1.5��");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"����");//������������ 
	ScenicSpotList[num3].ScenicSpot_COST=20000;//����ά������
	ScenicSpotList[num3].ScenicSpot_MENPIAO=600;//������Ʊ��
	ScenicSpotList[num3].ScenicSpot_VISIT=50000;//�����������
	ScenicSpotList[num3].ScenicSpot_YUDING=3400;//����Ԥ����
	ScenicSpotList[num3].ScenicSpot_HAOPING=0.83;//���������
	strcpy(ScenicSpotList[num3].ScenicSpot_LRET,"��");//�Ƿ��������˶�ͯ
	ScenicSpotList[num3].ScenicSpot_INCOME=0.0;
	
	fputs(ScenicSpotList[num3].ScenicSpot_ID,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_NAME,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_INTRO,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_PRICE1);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_PRICE2);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	fputs(ScenicSpotList[num3].ScenicSpot_TIME,jingdian);
	fputs("\n",jingdian);
	
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT1);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT2);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT3);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	fputs(ScenicSpotList[num3].ScenicSpot_GRADE,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_NUMBER,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_AREA,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_COST);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_MENPIAO);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_VISIT);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_YUDING);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%lf",ScenicSpotList[num3].ScenicSpot_HAOPING);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_LRET,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_INCOME);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	
	num3++;
	//8�ž���
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0008");//����ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"����ٸ");//�������� 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"�س����漣");//������
	ScenicSpotList[num3].ScenicSpot_PRICE1=200;//����������Ʊ�۸�
	ScenicSpotList[num3].ScenicSpot_PRICE2=140;//���㵭����Ʊ�۸� 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"1.5Сʱ");//��������ʱ��
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.65;//ѧ���ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.8;//�����ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//��ͨ�ۿ���Ϣ
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4��");//���㼶�� 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"1��");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"����");//������������ 
	ScenicSpotList[num3].ScenicSpot_COST=50000;//����ά������
	ScenicSpotList[num3].ScenicSpot_MENPIAO=800;//������Ʊ�� 
	ScenicSpotList[num3].ScenicSpot_VISIT=60000;//�����������
	ScenicSpotList[num3].ScenicSpot_YUDING=5010;//����Ԥ����
	ScenicSpotList[num3].ScenicSpot_HAOPING=0.85;//���������
	strcpy(ScenicSpotList[num3].ScenicSpot_LRET,"��");//�Ƿ��������˶�ͯ
	ScenicSpotList[num3].ScenicSpot_INCOME=0.0;
	
	fputs(ScenicSpotList[num3].ScenicSpot_ID,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_NAME,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_INTRO,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_PRICE1);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_PRICE2);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	fputs(ScenicSpotList[num3].ScenicSpot_TIME,jingdian);
	fputs("\n",jingdian);
	
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT1);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT2);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_DISCOUNT3);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	fputs(ScenicSpotList[num3].ScenicSpot_GRADE,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_NUMBER,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_AREA,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_COST);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_MENPIAO);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_VISIT);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%d",ScenicSpotList[num3].ScenicSpot_YUDING);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%lf",ScenicSpotList[num3].ScenicSpot_HAOPING);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	fputs(ScenicSpotList[num3].ScenicSpot_LRET,jingdian);
	fputs("\n",jingdian);
	sprintf(tmp,"%.2f",ScenicSpotList[num3].ScenicSpot_INCOME);
	fputs(tmp,jingdian);
	fputs("\n",jingdian);
	
	num3++;
	
	fclose(jingdian);
	
}	

int main()
{
jingdianxinxi();
return 0;
}
