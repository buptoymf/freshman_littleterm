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




void outputinfo()
{
	
	FILE *fp;
	
	
	char buf[1000];
	
	
	int c=0;
	
	fp=fopen("������Ϣ.txt","rb") ;
	
	printf("�������ж�����Ϣ���£�\n");
	
	for(c=0;fread(&info[c],sizeof(struct info_list),1,fp)!=0;c++)
    {
	
	
		printf("�ο�ID��%s\n",info[c].order_ID1);
		
		
		printf("����ID��%s\n",info[c].order_NUMBER);
		
		
		printf("ѧ��������%d\n",info[c].order_IDENTITY1);
	
		printf("����������%d\n",info[c].order_IDENTITY2);
		
		
		
		
		printf("��ͨ�ο�������%d\n",info[c].order_IDENTITY3);
		
		printf("�ο���������%d\n",info[c].order_PEOPLENUM);
		
	
		printf("�ο������Σ�%s\n",info[c].order_AGE);
		

		
		printf("��Ʊʱ�䣨�꣩��%d\n",info[c].order_YEAR);
		
	
		printf("��Ʊʱ�䣨�£���%d\n",info[c].order_MONTH);
		
	
		printf("��Ʊʱ�䣨�գ���%d\n",info[c].order_DAY);
		
		
		printf("��Ʊʱ�䣨ʱ����%d\n",info[c].order_HOUR);
		
		printf("��Ʊʱ�䣨�֣���%d\n",info[c].order_MINUTE);
		
		
		printf("�����ܼ۸�Ԫ����%.2f\n",info[c].order_PRICE);
		
		
		printf("������ţ�%s\n",info[c].order_ID);
		
	

	}
	
	if(c==0)
	{
		printf("�޶�����Ϣ��\n");
	}

	fclose(fp);
 }

int main()
{
	outputinfo();
	
	return 0;
}
