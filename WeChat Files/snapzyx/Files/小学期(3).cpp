#include<stdio.h>
#include<process.h>
#include<string.h>
void Jingdianmingcheng();
void Shifouyoupiao();
void Jingdianquyu();
void Shifouzhekou();
struct tourist
{
	char tourist_ID[20];//�ο�����ID
	char tourist_PASSWORD[20];//�ο��������� 
	char tourist_NUM[20];//�ο��������� 
	char tourist_AGE[20];//�ο����������� 
	char tourist_PHONE[20];//�ο�������ϵ�˵绰 
}touristList[80];
struct ScenicSpot
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
	char ScenicSpot_COST[80];//����ά������
	int ScenicSpot_MENPIAO;//������Ʊ 
}ScenicSpotList[80];
int main()
	{
	FILE *tourist_ID1,*tourist_PASSWORD1,*tourist_login;
	tourist_ID1=fopen("�ο���Ϣ.txt","r");
	tourist_PASSWORD1=fopen("�ο���Ϣ.txt","r");
	tourist_login=fopen("�ο��û���.txt","w");
	int cal1=1,cal2,cal3=1,cal4,choose,panduan=1;
	char tourist_ID2[20]={"\0"},tourist_PASSWORD2[20]={"\0"};
	printf("�������û�����\n");
	scanf("%s",tourist_ID2);
	fread(touristList,sizeof(struct tourist),5,tourist_ID1);
	//��֤�û����û��������Ƿ���ȷ 
	while(cal3!=0)
	{
	for(cal2=0;cal2<5;cal2++)
		{
			if(strcmp(tourist_ID2,touristList[cal2].tourist_ID)==0)
			{
				cal1=0;
				cal3=0;
				cal4=cal2;
			}
		}
		   if(cal1!=0)
		  {
		  	printf("�û������벻��ȷ�����������룺\n"); 
		  	scanf("%s",tourist_ID2);
		  	cal2=0;
			}
	}
	cal1=1;
	cal3=1;
	fputs(tourist_ID2,tourist_login);
	printf("���������룺\n");
	scanf("%s",tourist_PASSWORD2);
	while(cal3!=0)	//��֤���û������������Ƿ���ȷ 
	{
	for(cal2=0;cal2<5;cal2++)
		{
			if(strcmp(tourist_PASSWORD2,touristList[cal4].tourist_PASSWORD)==0)
			{
				cal1=0;
				cal3=0;
			}
		}
		   if(cal1!=0)
		  {
		  	printf("�������벻��ȷ�����������룺\n"); 
		  	scanf("%s",tourist_PASSWORD2);
		  	cal2=0;
			}
	} 
	fclose(tourist_ID1);
	fclose(tourist_PASSWORD1);
	fclose(tourist_login);
	printf("��ӭ����ϵͳ��\n");
	printf("1.���ݾ������Ʋ�ѯ��\n2.�����Ƿ���Ʊ��ѯ��\n3.���ݾ��������ѯ��\n4.�����Ƿ����ۿ۲�ѯ.\n");
	scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				Jingdianmingcheng();
				panduan=0;
				break;
			case 2:
				Shifouyoupiao();
				panduan=0;
				break;
			case 3:
				Jingdianquyu();
				panduan=0;
				break;
			case 4:
				Shifouzhekou();
				panduan=0;
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
}
void Jingdianmingcheng()
{
	int cal1=1,cal2,cal3=1;
	FILE *Jingdian1;
	Jingdian1=fopen("������Ϣ.txt","r");
	char jingdianchaxun1[80]={"\0"};
	printf("������Ҫ��ѯ�ľ������ƣ�\n");
	scanf("%s",jingdianchaxun1);
	fread(ScenicSpotList,sizeof(struct ScenicSpot),8,Jingdian1);//����ʱ��Ϊ�˸��� 
	while(cal3!=0) 
	{
		for(cal2=0;cal2<8;cal2++)//����ʱ��Ϊ�˸��� 
		{
		if(strcmp(jingdianchaxun1,ScenicSpotList[cal2].ScenicSpot_NAME)==0)//���ļ���������ľ������ƣ������if���� 
			{
			printf("����ID: "); 
		    puts(ScenicSpotList[cal2].ScenicSpot_ID);
	        printf("��������: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_NAME);
		    printf("������: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_INTRO);
	        printf("����������Ʊ�۸�: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_PRICE1);
	        printf("���㵭����Ʊ�۸�: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_PRICE2);
	        printf("�����þ�������ʱ��: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_TIME);
	        printf("ѧ���ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_DISCOUNT1);
	        printf("�����ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_DISCOUNT2);
	        printf("��ͨ�ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_DISCOUNT3);
	        printf("���㼶��: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_GRADE);
	        printf("��������: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_NUMBER);
	        printf("������������: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_AREA);
	        printf("����ά������:");
	        puts(ScenicSpotList[cal2].ScenicSpot_COST);	
			cal1=0;
			cal3=0;
			}
		}
			if(cal1!=0)
			{
			printf("������ľ��������������������룺\n");
			scanf("%s",jingdianchaxun1);
			}
		}
	return;
}
void Shifouyoupiao()
{

}
void Jingdianquyu()
{
	int cal1=1,cal2,cal3=1;
	FILE *Jingdian3;
	Jingdian3=fopen("������Ϣ.txt","r");
	char jingdianchaxun3[80]={"\0"};
	printf("������Ҫ��ѯ�ľ�������\n");
	scanf("%s",jingdianchaxun3);
	fread(ScenicSpotList,sizeof(struct ScenicSpot),8,Jingdian3);//����ʱ��Ϊ�˸��� 
	while(cal3!=0) 
	{
		for(cal2=0;cal2<8;cal2++)//����ʱ��Ϊ�˸��� 
		{
		if(strcmp(jingdianchaxun3,ScenicSpotList[cal2].ScenicSpot_AREA)==0)
			{
			printf("����ID: "); 
		    puts(ScenicSpotList[cal2].ScenicSpot_ID);
	        printf("��������: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_NAME);
		    printf("������: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_INTRO);
	        printf("����������Ʊ�۸�: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_PRICE1);
	        printf("���㵭����Ʊ�۸�: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_PRICE2);
	        printf("�����þ�������ʱ��: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_TIME);
	        printf("ѧ���ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_DISCOUNT1);
	        printf("�����ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_DISCOUNT2);
	        printf("��ͨ�ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_DISCOUNT3);
	        printf("���㼶��: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_GRADE);
	        printf("��������: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_NUMBER);
	        printf("������������: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_AREA);
	        printf("����ά������:");
	        puts(ScenicSpotList[cal2].ScenicSpot_COST);	
			cal1=0;
			cal3=0;
			}
		}
			if(cal1!=0)
			{
			printf("������ľ��������������������룺\n");
			scanf("%s",jingdianchaxun3);
			cal2=0;
			}
		}
	return;
}
void Shifouzhekou()
{
	
}
