#include<stdio.h>
#include<process.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>

#define NUMBER 80
//���˵� 
void mainmenu()
{
	printf("\n\n\t**************Main Menu**************\n");
	printf("\t*            1.�ο͵�½             *\n");
	printf("\t*            2.����Ա��½           *\n");
	printf("\t*            3.�ر�ϵͳ             *\n");
	printf("\t*****************************************\n");
}
void jinruyoukegongneng();
void Jingdianmingcheng();
void Shifouyoupiao();
void Jingdianquyu();
void Shifouzhekou();
void Youkedenglu();
void Jingdianchaxun();
void piaojiapaixu();
void yudingliangpaixu();
void haopingpaixu();
void yudingjingdianmenpiao();
void outputinfo();
void deleteinfo();
void Guanliyuandenglu();
void guanliyuancaidan();
void jingdianguanli();
void tianjiajingdianxinxi(); 
void dingdanchaxun();
void dingdanchaxun1();
void dingdanchaxun2();
void jingdianxinxichaxun();
void gerenxinxichaxun();
void xiugaigerenxinxi();
void youkexiugaigerenxinxi();
void dingdantongji();
void yudingliangpaixu1();
void youketuanxiugai();
void lirunpaixu();
void age();
void guanliyuanxiugai();
void fangwenrenshupaixu();
void lirunpaixu();
void tuijian();
void chushihuaxinxi();
//������Ϣ�ṹ�� 
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


//�ο���Ϣ�ṹ�� 
struct tourist
{
	char tourist_ID[20];//�ο�����ID
	char tourist_PASSWORD[20];//�ο��������� 
	char tourist_NUM[20];//�ο��������� 
	char tourist_AGE[20];//�ο����������� 
	char tourist_PHONE[20];//�ο�������ϵ�˵绰 
}touristList[NUMBER],touristList2[NUMBER];
//�ο��û������뱸��
struct  touristList1
{
	char tourist_ID1[20];//�ο�����ID
	char tourist_PASSWORD1[20];//�ο��������� 
}touristList1[80]; 
//����Ա��Ϣ�ṹ�� 
struct administrator
{
	char administrator_ID[20];//ϵͳ����ԱID 
	char administrator_PASSWORD[20];//ϵͳ����Ա���� 
	char administrator_PHONE[20];//ϵͳ����Ա�绰 
	char administrator_MAIL[20];//ϵͳ����Ա���� 
}administratorList[NUMBER];
//������Ϣ�ṹ�� 
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
	float ScenicSpot_INCOME;//������������
}ScenicSpotList[NUMBER],ScenicSpotList2[NUMBER];
//����Ա�û������뱸��
struct  administrator1
{
	char administrator1_ID[20];//ϵͳ����ԱID 
	char administrator1_PASSWORD[20];//ϵͳ����Ա���� 
}administratorList1[NUMBER];
//������  ����½���� 
int main()
{
//	chushihuaxinxi();
	int choose,panduan=1;
	mainmenu();
	printf("��ѡ����Ҫִ�е�ѡ��:\n");
	scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				Youkedenglu();//n=1ʱ�����ο͵�½���� 
				panduan=0;
				break;
			case 2:
				Guanliyuandenglu();//n=2ʱ�������Ա��½���� 
				panduan=0;
				break;
			case 3:
				panduan=0;
				printf("��л����ʹ�ã��ټ�!\n");//n=3ʱ�˳����� 
				exit(0);
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
}

//�ο��û������������� 
void Youkedenglu() 
{
	
	FILE *tourist_ID1,*tourist_PASSWORD1,*tourist_login;
	tourist_ID1=fopen("�ο���Ϣ.txt","rb");
	tourist_PASSWORD1=fopen("�ο���Ϣ.txt","rb");
	tourist_login=fopen("�ο��û��������뱸��.txt","wb");//���ļ��ж���������Ϣ����׼��������Ϣ 
	int cal1=1,cal2,cal3=1,cal4,cal5=0;
	
	char tourist_ID2[20]={"\0"},tourist_PASSWORD2[20]={"\0"};
	printf("�������û�����\n");
	scanf("%s",tourist_ID2);
	fread(touristList,sizeof(struct tourist),5,tourist_ID1);//�����ļ��е��ο���Ϣ 
	//��֤�û����û��������Ƿ���ȷ 
	while(cal3!=0)
	{
	for(cal2=0;cal2<5;cal2++)
		{
			if(strcmp(tourist_ID2,touristList[cal2].tourist_ID)==0)//���������Ϣ���ļ��д��ڣ��������ѭ�� 
			{
				cal1=0;
				cal3=0;
				cal4=cal2;
				strcpy(touristList1[cal2].tourist_ID1,tourist_ID2);//��������û������뱸���� 
			//	youkeid=cal2;
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
	printf("���������룺\n");
	scanf("%s",tourist_PASSWORD2);
	while(cal3!=0)	//��֤���û������������Ƿ���ȷ 
	{
	for(cal2=0;cal2<5;cal2++)
		{
			if(strcmp(tourist_PASSWORD2,touristList[cal4].tourist_PASSWORD)==0)//���������Ϣ���ļ��д��ڣ��������ѭ��
			{
				cal1=0;
				cal3=0;
				strcpy(touristList1[cal2].tourist_PASSWORD1,tourist_PASSWORD2);//�������������뱸���� 
			}
		}
		   if(cal1!=0)
		  {
		  	printf("�������벻��ȷ�����������룺\n"); 
		  	scanf("%s",tourist_PASSWORD2);
		  	cal2=0;
		  	cal5++;
			}
			if(cal5 == 2)
			{
				printf("������������������3�Σ��뷵�����������µ�½\n");
				mainmenu();
				cal1=0;
				cal3=0;
			}
	} 
	fwrite(&touristList1,sizeof(struct touristList1),1,tourist_login);//������ı�����Ϣ�����ļ��� 
	fclose(tourist_ID1);
	fclose(tourist_PASSWORD1);
	fclose(tourist_login);
	jinruyoukegongneng();
	

	
	
}
//�ο͵�½���� 
void jinruyoukegongneng()
{
	int choose,panduan=1;
	printf("��ӭ����ϵͳ����ѡ����Ҫִ�еĹ��ܣ� \n");
	printf("\n\n\t**************Main Menu******************\n");
	printf("\t*            1.�����ѯ                 *\n");
	printf("\t*            2.Ԥ��������Ʊ             *\n");
	printf("\t*            3.��Ϣ����                 *\n");
	printf("\t*            4.ȡ��Ԥ��                 *\n");
	printf("\t*            5.��ѯԤ����Ʊ             *\n");
	printf("\t*            6.�˳�                     *\n");
	printf("\t*****************************************\n");
	
	
	
	scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				Jingdianchaxun();
				panduan=0;
				break;
			case 2:
				yudingjingdianmenpiao();
				panduan=0;
				break;
			case 3:
				youketuanxiugai();
				panduan=0;
				break;
			case 4:
				deleteinfo();
				panduan=0;
				break;
			case 5:
				outputinfo();
				panduan=0;
				break;
			case 6:
				panduan=0;
				exit(0);
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
}
//�����ѯ���� 
void Jingdianchaxun()
{
	int choose,panduan=1;
	printf("\t**************Tourist Menu***************\n");
	printf("\t*       1.���ݾ������Ʋ�ѯ              *\n");
	printf("\t*       2.�����Ƿ���Ʊ��ѯ              *\n");
	printf("\t*       3.���ݾ��������ѯ              *\n");
	printf("\t*       4.�����Ƿ����ۿ۲�ѯ            *\n");
	printf("\t*       5.���ݼ۸��������о���          *\n");
	printf("\t*       6.����Ԥ�����������о���        *\n");
	printf("\t*       7.���ݺ������������о���        *\n");
	printf("\t*****************************************\n");
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
			case 5:
				piaojiapaixu();
				panduan=0;
				break;
			case 6:
				yudingliangpaixu();
				panduan=0;
				break;
			case 7:
				haopingpaixu();
				panduan=0;
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
}
// ���ݾ������Ʋ�ѯ 
void Jingdianmingcheng()
{
	int cal1=1,cal2,cal3=1,cal4;
	FILE *Jingdian1;
	Jingdian1=fopen("������Ϣ.txt","r");
	char jingdianchaxun1[80]={"\0"};
	printf("������Ҫ��ѯ�ľ������ƣ�\n");
	scanf("%s",jingdianchaxun1);
	for(cal4=0;fread(&ScenicSpotList[cal4],sizeof(struct  ScenicSpot),1,Jingdian1)!=0;cal4++);//��ȡ�����е�������Ϣ 
	while(cal3!=0) 
	{
		for(cal2=0;cal2<cal4;cal2++)
		{
		if(strcmp(jingdianchaxun1,ScenicSpotList[cal2].ScenicSpot_NAME)==0)//���ļ���������ľ������ƣ����ȡ��Ӧ�ľ�����Ϣ 
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
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_COST);	
	        printf("����ʣ��Ʊ��: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_MENPIAO);
	        printf("����Ԥ����: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_YUDING);
	        printf("���������: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_HAOPING);
	        printf("�Ƿ��������˶�ͯ: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_LRET);
			cal1=0;
			cal3=0;//����ѭ�������� 
			}
		}
			if(cal1!=0)
			{
			printf("������ľ��������������������룺\n");
			scanf("%s",jingdianchaxun1);
			}
		}
		fclose(Jingdian1);	
		printf("\t**************Tourist Menu***************\n");
		printf("\t*          �������Ƿ���Ҫ��Ʊ��         *\n");
		printf("\t*          1.��Ҫ                       *\n");
		printf("\t*          2.���ع��ܽ���               *\n");
		printf("\t**************Tourist Menu***************\n");
		int choose,panduan=1;
		scanf("%d",&choose);
	while(panduan!=0)//�ж�������������ȷ�����ȷ�������Ӧ�ĳ��򣬷���Ҫ���������� 
	{
		switch(choose)
		{
			case 1:
				yudingjingdianmenpiao();
				panduan=0;
				break;
			case 2:
				jinruyoukegongneng();
				panduan=0;
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
			
	
	return;
}
//�����Ƿ���Ʊ��ѯ 
void Shifouyoupiao()
{
	FILE *fp;
	fp=fopen("������Ϣ.txt","rb");
	int cal1,cal2;
	for(cal1=0;fread(&ScenicSpotList[cal1],sizeof(struct  ScenicSpot),1,fp)!=0;cal1++);
	for(cal2=0;cal2<cal1;cal2++)
	{
		if(ScenicSpotList[cal2].ScenicSpot_MENPIAO > 0)
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
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_COST);	
	        printf("����ʣ��Ʊ��: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_MENPIAO);
	        printf("����Ԥ����: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_YUDING);
	        printf("���������: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_HAOPING);
	        printf("�Ƿ��������˶�ͯ: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_LRET);
	        printf("\n");
		}
	}
	fclose(fp);
	
		printf("\t**************Tourist Menu***************\n");
		printf("\t*          �������Ƿ���Ҫ��Ʊ��         *\n");
		printf("\t*          1.��Ҫ                       *\n");
		printf("\t*          2.���ع��ܽ���               *\n");
		printf("\t**************Tourist Menu***************\n");
		int choose,panduan=1;
		scanf("%d",&choose);
	while(panduan!=0)//�ж�������������ȷ�����ȷ�������Ӧ�ĳ��򣬷���Ҫ���������� 
	{
		switch(choose)
		{
			case 1:
				yudingjingdianmenpiao();
				panduan=0;
				break;
			case 2:
				jinruyoukegongneng();
				panduan=0;
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
			
	
	return;
}
//���ݾ��������ѯ 
void Jingdianquyu()
{
	int cal1=1,cal2,cal3=1,cal4;
	FILE *Jingdian3;
	Jingdian3=fopen("������Ϣ.txt","r");
	char jingdianchaxun3[80]={"\0"};
	printf("������Ҫ��ѯ�ľ�������\n");
	scanf("%s",jingdianchaxun3);
	for(cal4=0;fread(&ScenicSpotList[cal4],sizeof(struct  ScenicSpot),1,Jingdian3)!=0;cal4++);//��ȡ�����е�������Ϣ 
	while(cal3!=0) 
	{
		for(cal2=0;cal2<cal4;cal2++)//����ʱ��Ϊ�˸��� 
		{
		if(strcmp(jingdianchaxun3,ScenicSpotList[cal2].ScenicSpot_AREA)==0)//���ļ���������ľ����������ȡ��Ӧ�ľ�����Ϣ 
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
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_COST);	
	        printf("����ʣ��Ʊ��: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_MENPIAO);
	        printf("����Ԥ����: ");
	        printf("%d\n",ScenicSpotList[cal2].ScenicSpot_YUDING);
	        printf("���������: ");
	        printf("%.2f\n",ScenicSpotList[cal2].ScenicSpot_HAOPING);
	        printf("�Ƿ��������˶�ͯ: ");
	        puts(ScenicSpotList[cal2].ScenicSpot_LRET);
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
		fclose(Jingdian3);
		printf("\t**************Tourist Menu***************\n");
		printf("\t*          �������Ƿ���Ҫ��Ʊ��         *\n");
		printf("\t*          1.��Ҫ                       *\n");
		printf("\t*          2.���ع��ܽ���               *\n");
		printf("\t**************Tourist Menu***************\n");
		int choose,panduan=1;
		scanf("%d",&choose);
	while(panduan!=0)//�ж�������������ȷ�����ȷ�������Ӧ�ĳ��򣬷���Ҫ���������� 
	{
		switch(choose)
		{
			case 1:
				yudingjingdianmenpiao();
				panduan=0;
				break;
			case 2:
				jinruyoukegongneng();
				panduan=0;
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
	
	return;
}
//�����Ƿ��ۿ۲�ѯ 
void Shifouzhekou()
{
	int cal1,cal3,cal4,cal5,cal7=1,choose;
	FILE *Jingdian4;
	Jingdian4=fopen("������Ϣ.txt","r");
	for(cal4=0;fread(&ScenicSpotList[cal4],sizeof(struct  ScenicSpot),1,Jingdian4)!=0;cal4++);//��ȡ�����е�������Ϣ 
	printf("\t**************Tourist Menu***************\n");
	printf("\t*     ������Ҫ��ѯ�����ۿ���Ϣ��        *\n");
	printf("\t*     1.ѧ��                            *\n");
	printf("\t*     2.����                            *\n");
	printf("\t*     3.��ͨ��                          *\n");
	printf("\t*****************************************\n");
	scanf("%d",&choose);
	while(cal7!=0) 
	{
		switch(choose)
		{
			case 1:
				for(cal1=0;cal1<cal4;cal1++)
			{
				if(ScenicSpotList[cal1].ScenicSpot_DISCOUNT1 < 1)//�����ۿۣ��������Ӧ����Ϣ 
				{
			printf("����ID: "); 
		    puts(ScenicSpotList[cal1].ScenicSpot_ID);
	   	    printf("��������: ");
	        puts(ScenicSpotList[cal1].ScenicSpot_NAME);
		    printf("������: ");
	     	puts(ScenicSpotList[cal1].ScenicSpot_INTRO);
	     	printf("����������Ʊ�۸�: ");
	        printf("%d\n",ScenicSpotList[cal1].ScenicSpot_PRICE1);
	        printf("���㵭����Ʊ�۸�: ");
	        printf("%d\n",ScenicSpotList[cal1].ScenicSpot_PRICE2);
	        printf("�����þ�������ʱ��: ");
	        puts(ScenicSpotList[cal1].ScenicSpot_TIME);
	        printf("ѧ���ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[cal1].ScenicSpot_DISCOUNT1);
	        printf("�����ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[cal1].ScenicSpot_DISCOUNT2);
	        printf("��ͨ�ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[cal1].ScenicSpot_DISCOUNT3);
	        printf("���㼶��: ");
	        puts(ScenicSpotList[cal1].ScenicSpot_GRADE);
	        printf("��������: ");
	        puts(ScenicSpotList[cal1].ScenicSpot_NUMBER);
	        printf("������������: ");
	        puts(ScenicSpotList[cal1].ScenicSpot_AREA);
	        printf("����ά������:");
	        printf("%d\n",ScenicSpotList[cal1].ScenicSpot_COST);	
	        printf("����ʣ��Ʊ��: ");
	        printf("%d\n",ScenicSpotList[cal1].ScenicSpot_MENPIAO);
	        printf("����Ԥ����: ");
	        printf("%d\n",ScenicSpotList[cal1].ScenicSpot_YUDING);
	        printf("���������: ");
	        printf("%.2f\n",ScenicSpotList[cal1].ScenicSpot_HAOPING);
	        printf("�Ƿ��������˶�ͯ: ");
	        puts(ScenicSpotList[cal1].ScenicSpot_LRET);
	        printf("\n");
			}
			}
			cal7=0;
			break;
			case 2:
				for(cal3=0;cal3<cal4;cal3++)
			{
			if(ScenicSpotList[cal3].ScenicSpot_DISCOUNT2 < 1)//�����ۿۣ��������Ӧ����Ϣ 
			{
			printf("����ID: "); 
		    puts(ScenicSpotList[cal3].ScenicSpot_ID);
	        printf("��������: ");
	        puts(ScenicSpotList[cal3].ScenicSpot_NAME);
		    printf("������: ");
	        puts(ScenicSpotList[cal3].ScenicSpot_INTRO);
	        printf("����������Ʊ�۸�: ");
	        printf("%d\n",ScenicSpotList[cal3].ScenicSpot_PRICE1);
	        printf("���㵭����Ʊ�۸�: ");
	        printf("%d\n",ScenicSpotList[cal3].ScenicSpot_PRICE2);
	        printf("�����þ�������ʱ��: ");
	        puts(ScenicSpotList[cal3].ScenicSpot_TIME);
	        printf("ѧ���ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[cal3].ScenicSpot_DISCOUNT1);
	        printf("�����ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[cal3].ScenicSpot_DISCOUNT2);
	        printf("��ͨ�ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[cal3].ScenicSpot_DISCOUNT3);
	        printf("���㼶��: ");
	        puts(ScenicSpotList[cal3].ScenicSpot_GRADE);
	        printf("��������: ");
	        puts(ScenicSpotList[cal3].ScenicSpot_NUMBER);
	        printf("������������: ");
	        puts(ScenicSpotList[cal3].ScenicSpot_AREA);
	        printf("����ά������:");
	        printf("%d\n",ScenicSpotList[cal3].ScenicSpot_COST);	
	        printf("����ʣ��Ʊ��: ");
	        printf("%d\n",ScenicSpotList[cal3].ScenicSpot_MENPIAO);
	        printf("����Ԥ����: ");
	        printf("%d\n",ScenicSpotList[cal3].ScenicSpot_YUDING);
	        printf("���������: ");
	        printf("%.2f\n",ScenicSpotList[cal3].ScenicSpot_HAOPING);
	        printf("�Ƿ��������˶�ͯ: ");
	        puts(ScenicSpotList[cal3].ScenicSpot_LRET);
	        printf("\n");
			}
			}
			cal7=0;
			break;
			case 3:
			for(cal5=0;cal5<cal4;cal5++) 
			{
			if(ScenicSpotList[cal5].ScenicSpot_DISCOUNT3 < 1)//�����ۿۣ��������Ӧ����Ϣ 
			{
			printf("����ID: "); 
		    puts(ScenicSpotList[cal5].ScenicSpot_ID);
	        printf("��������: ");
	        puts(ScenicSpotList[cal5].ScenicSpot_NAME);
		    printf("������: ");
	        puts(ScenicSpotList[cal5].ScenicSpot_INTRO);
	        printf("����������Ʊ�۸�: ");
	        printf("%d\n",ScenicSpotList[cal5].ScenicSpot_PRICE1);
	        printf("���㵭����Ʊ�۸�: ");
	        printf("%d\n",ScenicSpotList[cal5].ScenicSpot_PRICE2);
	        printf("�����þ�������ʱ��: ");
	        puts(ScenicSpotList[cal5].ScenicSpot_TIME);
	        printf("ѧ���ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[cal5].ScenicSpot_DISCOUNT1);
	        printf("�����ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[cal5].ScenicSpot_DISCOUNT2);
	        printf("��ͨ�ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[cal5].ScenicSpot_DISCOUNT3);
	        printf("���㼶��: ");
	        puts(ScenicSpotList[cal5].ScenicSpot_GRADE);
	        printf("��������: ");
	        puts(ScenicSpotList[cal5].ScenicSpot_NUMBER);
	        printf("������������: ");
	        puts(ScenicSpotList[cal5].ScenicSpot_AREA);
	        printf("����ά������:");
	        printf("%d\n",ScenicSpotList[cal5].ScenicSpot_COST);	
	        printf("����ʣ��Ʊ��: ");
	        printf("%d\n",ScenicSpotList[cal5].ScenicSpot_MENPIAO);
	        printf("����Ԥ����: ");
	        printf("%d\n",ScenicSpotList[cal5].ScenicSpot_YUDING);
	        printf("���������: ");
	        printf("%.2f\n",ScenicSpotList[cal5].ScenicSpot_HAOPING);
	        printf("�Ƿ��������˶�ͯ: ");
	        puts(ScenicSpotList[cal5].ScenicSpot_LRET);
	        printf("\n");
			}
			}
			cal7=0;
			break;
			default:
				printf("������Ĳ�ѯ�����������������룺\n");
				scanf("%d",&choose); 
			}
		}
		fclose(Jingdian4);
		printf("\t**************Tourist Menu***************\n");
		printf("\t*          �������Ƿ���Ҫ��Ʊ��         *\n");
		printf("\t*          1.��Ҫ                       *\n");
		printf("\t*          2.���ع��ܽ���               *\n");
		printf("\t**************Tourist Menu***************\n");
		int choose1,panduan=1;
		scanf("%d",&choose1);
	while(panduan!=0)//�ж�������������ȷ�����ȷ�������Ӧ�ĳ��򣬷���Ҫ���������� 
	{
		switch(choose1)
		{
			case 1:
				yudingjingdianmenpiao();
				panduan=0;
				break;
			case 2:
				jinruyoukegongneng();
				panduan=0;
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
	return;
	
}
//����Ʊ������ 
void piaojiapaixu()
{
   FILE *fp;
   fp=fopen("������Ϣ.txt","rb");//���ļ���������Ϣ�� 
    int i,j,k,choose,panduan=1;
    for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  

	//�����ļ��о�������,���㾰����� ,i�Ǿ������ 
	/*for(n=0;n<i;n++)
    fread(&ScenicSpotList[n],sizeof(struct  ScenicSpot),i,fp);*/
	
	printf("��������Ҫ�鿴����Ʊ������������Ʊ������:\n1.����Ʊ������.\n2.����Ʊ������.\n");
	scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				 for(int n=1;n<i;n++)
  					 {
   						  k=ScenicSpotList[n].ScenicSpot_PRICE1;
    					  ScenicSpotList2[n-1]=ScenicSpotList[n];
     					  j=n-1;
      					  while((j>=0)&&(ScenicSpotList[j].ScenicSpot_PRICE1>k))
     						 {
     				  		 	ScenicSpotList[j+1].ScenicSpot_PRICE1=ScenicSpotList[j].ScenicSpot_PRICE1;
     						    ScenicSpotList[j+1]=ScenicSpotList[j];         
  						        j--;
  						   	 }
  						  ScenicSpotList[j+1].ScenicSpot_PRICE1=k;
   						  ScenicSpotList[j+1]=ScenicSpotList2[n-1];

  					 }
 					 printf("   ��������          ����ID         ����Ʊ��\n");
 				for(int n=0;n<i;n++)
 						 {       
  					         printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_PRICE1);
   						 }
   			  fclose(fp);
			  panduan=0;
			  break;
			case 2:
				for(int n=1;n<i;n++)
  					 {
   						  k=ScenicSpotList[n].ScenicSpot_PRICE2;
    					  ScenicSpotList2[n-1]=ScenicSpotList[n];
     					  j=n-1;
      					  while((j>=0)&&(ScenicSpotList[j].ScenicSpot_PRICE2>k))
     						 {
     				  		 	ScenicSpotList[j+1].ScenicSpot_PRICE2=ScenicSpotList[j].ScenicSpot_PRICE2;
     						    ScenicSpotList[j+1]=ScenicSpotList[j];         
  						        j--;
  						   	 }
  						  ScenicSpotList[j+1].ScenicSpot_PRICE2=k;
   						  ScenicSpotList[j+1]=ScenicSpotList2[n-1];

  					 }
 					 printf("   ��������          ����ID          ����Ʊ��\n");
 				for(int n=0;n<i;n++)
 						 {       
  					         printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_PRICE2);
   						 }
   			  fclose(fp);
				panduan=0;
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
		printf("\t**************Tourist Menu***************\n");
		printf("\t*          �������Ƿ���Ҫ��Ʊ��         *\n");
		printf("\t*          1.��Ҫ                       *\n");
		printf("\t*          2.���ع��ܽ���               *\n");
		printf("\t**************Tourist Menu***************\n");
		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)//�ж�������������ȷ�����ȷ�������Ӧ�ĳ��򣬷���Ҫ���������� 
	{
		switch(choose1)
		{
			case 1:
				yudingjingdianmenpiao();
				panduan1=0;
				break;
			case 2:
				jinruyoukegongneng();
				panduan1=0;
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
	return;
 }
//����Ԥ�������� 
void yudingliangpaixu()
{

   FILE *fp,*fp2;
   fp=fopen("������Ϣ.txt","rb");//���ļ���������Ϣ�� 
    int i;
     for(i=0;fread(&ScenicSpotList2[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);
     //�����������ơ�����Ϣ��ֵ�� ScenicSpotList2
    fp2=fopen("������Ϣ.txt","rb");//���ļ�������Ϣ 
    int i2;//i2Ϊ�������� 
     for(i2=0;fread(&info[i2],sizeof(struct info_list),1,fp2)!=0;i2++);
     //���㶩������ 
    int yu[80];
      for(int n=0;n<i;n++)
	   yu[n]=0;//ΪԤ������������ 
    //strcmp(dsfsfs,dfdfd)
     for(int n=0;n<i;n++)
      { for(int j=0;j<i2;j++)
         if(strcmp(ScenicSpotList2[n].ScenicSpot_ID,info[j].order_NUMBER)==0)
           yu[n]=yu[n]+info[j].order_IDENTITY1+info[j].order_IDENTITY2+info[j].order_IDENTITY3;
	  }
    //���ݾ���id���ֱ���������Ԥ���� 
    for(int n=0;n<i;n++)
     {
        //ScenicSpotList2[n]=ScenicSpotList[n];
     	ScenicSpotList2[n].ScenicSpot_YUDING=yu[n];
	 }
	 // �����޸ĺ�Ԥ���� 
     fclose(fp);
     fclose(fp2);
     fp=fopen("������Ϣ.dat","wb");
     fwrite(&ScenicSpotList2,sizeof(struct  ScenicSpot),i,fp);
     fclose(fp);
     //���޸ĺ���Ϣ���롰������Ϣ��   
	 FILE *fp3;
     fp3=fopen("������Ϣ.dat","rb");//���ļ����������� 
      
    for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//�����ļ��о�������,���㾰����� ,i�Ǿ������    
	
     	int j,k;//n,j,k������������ ScenicSpotList2������������     	
	 for(int n=1;n<i;n++)
    {
      k=ScenicSpotList[n].ScenicSpot_YUDING ;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//���� ScenicSpotList[n]���� 
      j=n-1;//j����������ǰ���������ǰ���ݽ������� 
        while((j>=0)&&(ScenicSpotList[j].ScenicSpot_YUDING<k))
        // j��Ϊ����ScenicSpotList[n-1]>ScenicSpotList[n],�򽻻�
      {
         ScenicSpotList[j+1].ScenicSpot_YUDING =ScenicSpotList[j].ScenicSpot_YUDING ;
         ScenicSpotList[j+1]=ScenicSpotList[j];         
         j--;
      } //j-1�������Ƚ� ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_YUDING=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];
   }
     printf("   ��������          ����ID          ����Ԥ����\n");    
    for(int n=0;n<i;n++)
     {       
       printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_YUDING  );
     }//�������󾰵����� 
     fclose(fp3);
  		printf("\t**************Tourist Menu***************\n");
		printf("\t*          �������Ƿ���Ҫ��Ʊ��         *\n");
		printf("\t*          1.��Ҫ                       *\n");
		printf("\t*          2.���ع��ܽ���               *\n");
		printf("\t**************Tourist Menu***************\n");
		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)//�ж�������������ȷ�����ȷ�������Ӧ�ĳ��򣬷���Ҫ���������� 
	{
		switch(choose1)
		{
			case 1:
				yudingjingdianmenpiao();
				panduan1=0;
				break;
			case 2:
				jinruyoukegongneng();
				panduan1=0;
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
}
//���ݺ��������� 
void haopingpaixu()
{
	  FILE *fp;
   fp=fopen("������Ϣ.txt","rb");//���ļ���������Ϣ�� 
    int i;
    for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//�����ļ��о�������,���㾰����� ,i�Ǿ������ 
	/*for(n=0;n<i;n++)
    fread(&ScenicSpotList[n],sizeof(struct  ScenicSpot),i,fp);*/
	
	int j,n;//n,j,k������������ ScenicSpotList2������������ 
	float k;
	 for(n=1;n<i;n++)
   {
      k=ScenicSpotList[n].ScenicSpot_HAOPING;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//���� ScenicSpotList[n]���� 
      j=n-1;//j����������ǰ���������ǰ���ݽ������� 
        while((j>=0)&&(ScenicSpotList[j].ScenicSpot_HAOPING<k))
		// j��Ϊ����ScenicSpotList[n-1]>ScenicSpotList[n],�򽻻� 
      {
         ScenicSpotList[j+1].ScenicSpot_HAOPING=ScenicSpotList[j].ScenicSpot_HAOPING;
         ScenicSpotList[j+1]=ScenicSpotList[j];         
         j--;
      }//j-1�������Ƚ� ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_HAOPING=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];

   }
   printf("   ��������          ����ID          ������\n");
   for(int n=0;n<i;n++)
    {       
       printf("%11s\t%11s\t%11.2f\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_HAOPING);
    }//�������󾰵����� 
    fclose(fp);//�ر��ļ� 
 		printf("\t**************Tourist Menu***************\n");
		printf("\t*          �������Ƿ���Ҫ��Ʊ��         *\n");
		printf("\t*          1.��Ҫ                       *\n");
		printf("\t*          2.���ع��ܽ���               *\n");
		printf("\t**************Tourist Menu***************\n");
		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)//�ж�������������ȷ�����ȷ�������Ӧ�ĳ��򣬷���Ҫ���������� 
	{
		switch(choose1)
		{
			case 1:
				yudingjingdianmenpiao();
				panduan1=0;
				break;
			case 2:
				jinruyoukegongneng();
				panduan1=0;
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
}


//Ԥ��������Ʊ 
void yudingjingdianmenpiao()
{
	char tourist_ID2[50];
/*	int cal2;
	int youkeid=Youkedenglu();
	FILE *tourist_ID1=fopen("�ο���Ϣ.txt","rb");
	FILE *fp=
	fread(touristList,sizeof(struct tourist),5,tourist_ID1);
	for(cal2=0;cal2<=youkeid;cal2++)
		{
			
		}
		
		strcpy(tourist_ID2,touristList1[cal2].tourist_ID1);
		
	
	*/ 
	
	
	FILE *fp;

	int n,y;//ѭ���ṹ�ļ���ֵ 
	int i;//�жϵڼ������� 
	int jingdianshuliang;
	int a;//�ж϶��˵ڼ��������Ʊ 
	int b,c,d,f,g,h,j,k,l;//�жϸ�����Ϣ�����Ƿ���ȷ�ı��ֵ 
	
	int price;
	
	char buf[1000];
//	char buf2[1000];
	char tmp[20];
	
	printf("�������û�����\n");
	scanf("%s",tourist_ID2);
	
	FILE *jingdian;
	
	jingdian=fopen("������Ϣ.txt","rb");//�򿪾�����Ϣ�ļ����жϾ���id�����Լ���ȡ����Ʊ�� 
	 
	 
	 
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
	
	for(jingdianshuliang=0;fread(&ScenicSpotList[jingdianshuliang],sizeof(struct ScenicSpot),1,jingdian)!=0;jingdianshuliang++)
	
    {
		 
	}
		
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
	
//	printf("����������%d\n",jingdianshuliang);
	
		printf("����ID��");
	
		
		
		a=-1;
		
		while(a==-1)
		{

		scanf("%s",info[i].order_NUMBER);
		
		for(y=0;y<jingdianshuliang;y++)//�����������������id��һ�Ƚ� 
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
		
		
		
		
		
		
		
		//���ݶ����������ɶ������ 
		strcpy(info[i].order_ID1,tourist_ID2);//�ο�ID����ȡ 
		
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
		
		
	
		printf("�����ܼ۸�Ԫ��:%.2f\n",info[i].order_PRICE);
	
		printf("���Ķ�������ǣ�%s\n",info[i].order_ID);
		
		
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
	//	fputs("\n",jingdian2);
		fclose(jingdian2);
		
	}
	
	
		
		fwrite(&info,sizeof(info_list),n,fp);
	//	fputs("\n",fp);
		
		
		
		
		fclose(jingdian);
		
		remove("������Ϣ.txt");
		rename("temp.txt","������Ϣ.txt");
		fclose(fp);
	
	
//	fwrite(&ScenicSpotList,1000,num3,jingdian);
	
	
	
	
//	show(n);
	
	
	}
	

	
	
	
		printf("�������Ƿ���Ҫ����ʹ��ϵͳ��\n1.���ع��ܽ���\n2.�˳�\n");
	    		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				jinruyoukegongneng();
				panduan1=0;
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
 }
//��ѯ������Ʊ 
 void outputinfo()
{
	
	FILE *fp;
	
	
//	char buf[1000];
	
	
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
	fclose(fp);
	
		
	
	
	if(c==0)
	{
		printf("�޶�����Ϣ��\n");
	}
	
			printf("�������Ƿ���Ҫ����ʹ��ϵͳ��\n1.���ع��ܽ���\n2.�˳�\n");
	    		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				jinruyoukegongneng();
				panduan1=0;
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose1);
				break;
		}
	}
		
		
	
	
 
	
 } 
//�˶��ĺ��� 
void deleteinfo()
{
	FILE *pf = fopen("������Ϣ.txt", "rb");
	
	
    char buf[1000];
   // char buf2[1000];
	char s[50];

	int jingdianshuliang;
 //   int i=0;
	int c=0;
	int a,x;
	
	int riqi_year,riqi_month,riqi_day,riqi_hour,riqi_minute;
	int riqi2_year,riqi2_month,riqi2_day,riqi2_hour,riqi2_minute;
	double gap_between_date1,gap_between_date2;
	int d[12]={0,31,59,90,120,151,181,212,243,273,304,334};
	

	
	


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
    	
	//i=0;
	
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
	
	
	//�ж�ʱ���Ƿ���ʣ��б𷽷�Ϊ�ֱ��������ʱ����빫Ԫ0��1��1��0���ʱ��Ȼ������� 
	
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
	
	
	
	if(gap_between_date1-gap_between_date2>=1440)
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
	
	if(gap_between_date1-gap_between_date2<1440 && gap_between_date1-gap_between_date2>0)
	{
		fclose(pt);
    	fclose(pf2);
    	fclose(jingdian);
		printf("�˶�ʧ�ܣ��������ʱ�䲻��24Сʱ��\n"); 
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
	

	
	
	
	

	
    

    fclose(pf);
    
    
    		printf("�������Ƿ���Ҫ����ʹ��ϵͳ��\n1.���ع��ܽ���\n2.�˳�\n");
	    		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				jinruyoukegongneng();
				panduan1=0;
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
	
    
    
	}


//�޸��ο������������ 
void youketuanxiugai()
 {  
    printf("\t**************Tourist Menu***************\n");
    printf("\t*            1.�����޸�                  *\n");
    printf("\t*            2.�����޸�                  *\n");
    printf("\t*            3.�绰�޸�                  *\n");
    printf("\t*            4.ȡ���޸�                  *\n");
    printf("\t*****************************************\n");
    int panduan;
    scanf("%d",&panduan);//ѡ���޸���������� 
    		
     FILE *fp,*fp2;
     fp=fopen("�ο���Ϣ.txt","rb");
       fread(&touristList,sizeof(struct tourist),5,fp);//��ȡ�ο���Ϣ ������
     fp2=fopen("�ο��û��������뱸��.txt","rb");
      
       fread(&touristList1[0],sizeof(struct tourist),1,fp2);//��ȡ����������
    int i,n;       
    for(n=0;n<3;n++)
        {
        	if(strcmp(touristList[n].tourist_ID,touristList1[0].tourist_ID1)==0)
			   i=n;
	    }//�ж����޸ĵ���Ϣ�ǵڼ����ο��ŵģ�iΪ�ù���Ա��� 
    
   switch (panduan)       
  {      
      case 1:  //1Ϊ��������޸�
  	{	 
	   printf("%s\n",touristList1[0].tourist_PASSWORD1);
     char mima[20];     
     for(n=0;n<3;n++)
	 {	  
        printf("������ԭ����\n");
         scanf("%s",&mima);
      
     
       if(strcmp(mima,touristList1[0].tourist_PASSWORD1)==0)
       {
       	 printf("������������\n"); 
       	  scanf("%s",&touristList[i].tourist_PASSWORD);
       	  break;  
		    
	   }
     else
       {
	     printf("���������������������\n");       
       } 
     }    
    
      if(n==3)
      {
	  printf("��������������Σ��������˵�\n");
      jinruyoukegongneng();
			  exit(1);
	  }		       
      fclose(fp);
      fclose(fp2);
      fp=fopen("�ο���Ϣ.txt","wb");
      fwrite(&touristList,sizeof(struct tourist),3,fp);
      printf("�����޸ĳɹ��������������Ч\n");
			  	 exit(0);
	  break;      
    }
    case 2:
     {
     	char mail[20];
     	int n;
		 printf("������������\n");
		 for(n=0;n<3;n++)
		{
		 scanf("%s",&mail);
		   int a,d;
		     for(a=1;a<20;a++)
		      {
		   	    if(mail[a]==64)
		   	    break;
		      }		     
		     for(d=1;d<20;d++)
		      {
		      	if(mail[d]=='.')
		      	break;
			  }
			  if(a==20||a>d||d==20)
			  {
		      printf("��ʽ�����������������\n");
		      break;
		      }
		      if(mail[d+1]<0||mail[d+1]>'z')
		      {
		      	printf("��ʽ�����������������\n");
		      	break;
			  }
		}
		
		     if(n==3)
			  {			  
                printf("�����ʽ����������Σ��������˵�\n");
              jinruyoukegongneng();
                exit(2);
               } 
			//strcpy(touristList[i]//mail,mail);
			FILE *fp3;
			 fp3=fopen("�ο���Ϣ.txt","wb");
			 fwrite(&touristList,sizeof(struct tourist),3,fp3);
			 fclose(fp3);
			printf("�����޸ĳɹ��������������Ч\n");
			  break;
      }
	 
	 
	 case 4:
	  jinruyoukegongneng(); 
	  break;
	  
	case 3:
	
	  char phone[20];
	  int num,n;	   
	    for(n=0;n<3;n++)
	 {
	      	printf("�������µ绰\n");
            scanf("%s",&phone);                  
       	    num=strlen(phone);
       	    if(num==11)
       	      {
				strcpy(touristList[i].tourist_PHONE,phone);
			  FILE *fp3;
			  fp3=fopen("�ο���Ϣ.txt","wb");
			  fwrite(&touristList,sizeof(struct tourist),5,fp3);
			  fclose(fp3);
			  printf("�绰�޸ĳɹ��������������Ч\n");
			  mainmenu();
			  exit(4);
				  
			  }	 			    	  
	        else
	         {
	         	printf("�绰��ʽ��������������\n");	            							  
			 }
     
     }    
    
      if(n==3)
      {	  
       printf("��������������Σ��������˵�\n");
       jinruyoukegongneng();
       exit(5);
      }
      fclose(fp);
      fclose(fp2);
      fp=fopen("�ο���Ϣ.txt","wb");
      fwrite(&touristList,sizeof(struct tourist),5,fp);
	  break;      
    			  		  	
	default:
				printf("����������ݴ������������룺\n\n");				
				youketuanxiugai();
				break;
  }
}	
//����Ա��½ 
void Guanliyuandenglu()
{
	FILE *administrator_ID1,*administrator_PASSWORD1,*administrator_login;
	administrator_ID1=fopen("����Ա��Ϣ.txt","rb");
	administrator_PASSWORD1=fopen("����Ա��Ϣ.txt","rb");
	administrator_login=fopen("����Ա�û��������뱸��.txt","wb");//���ļ��ж���������Ϣ����׼��������Ϣ 
	int cal1=1,cal2,cal3=1,cal4,cal5=0;
	char administrator_ID2[20]={"\0"},administrator_PASSWORD2[20]={"\0"};
	printf("���������ԱID��\n");
	scanf("%s",administrator_ID2);
	fread(administratorList,sizeof(struct administrator),3,administrator_ID1);//�����ļ��еĹ���Ա��Ϣ 
	//��֤�û����û��������Ƿ���ȷ 
	while(cal3!=0)
	{
	for(cal2=0;cal2<3;cal2++)
		{
			if(strcmp(administrator_ID2,administratorList[cal2].administrator_ID)==0)//���������Ϣ���ļ��д��ڣ��������ѭ�� 
			{
				cal1=0;
				cal3=0;
				cal4=cal2;
				strcpy(administratorList1[cal2].administrator1_ID,administrator_ID2);//��������û������뱸���� 
			}
		}
		   if(cal1!=0)
		  {
		  	printf("����ԱID���벻��ȷ�����������룺\n"); 
		  	scanf("%s",administrator_ID2);
		  	cal2=0;
			}
	}
	cal1=1;
	cal3=1;

	printf("���������룺\n");
	scanf("%s",administrator_PASSWORD2);
	while(cal3!=0)	//��֤���û������������Ƿ���ȷ 
	{
	for(cal2=0;cal2<3;cal2++)
		{
			if(strcmp(administrator_PASSWORD2,administratorList[cal4].administrator_PASSWORD)==0)//���������Ϣ���ļ��д��ڣ��������ѭ��
			{
				cal1=0;
				cal3=0;
				strcpy(administratorList1[cal2].administrator1_PASSWORD,administrator_PASSWORD2);//�������������뱸���� 
			}
		}
		   if(cal1!=0)
		  {
		  	printf("�������벻��ȷ�����������룺\n"); 
		  	scanf("%s",administrator_PASSWORD2);
		  	cal2=0;
		  	cal5++;
			}
			if(cal5 == 2)
			{
				printf("������������������3�Σ��뷵�����������µ�½\n");
				mainmenu();
				cal1=0;
				cal3=0;
			}
	} 
	fwrite(administratorList1,sizeof(administratorList1),1,administrator_login);//������ı�����Ϣ�����ļ��� 
	fclose(administrator_ID1);
	fclose(administrator_PASSWORD1);
	fclose(administrator_login);
	guanliyuancaidan();
}   
//����Ա�˵� 
void guanliyuancaidan()
{
	int choose,panduan=1;
   	printf("��ӭ�������Աϵͳ��\n");
   	printf("\n\n\t***************Main Menu*******************\n");
	printf("\t*               1.������ѯ                *\n");
	printf("\t*               2.����ͳ��                *\n");
	printf("\t*               3.�������                *\n");
	printf("\t*               4.������Ϣ����            *\n");
	printf("\t*               5.�˳�����                *\n");
	printf("\t*******************************************\n");
	scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				dingdanchaxun();
				panduan=0; 
				break;
			case 2:
				dingdantongji();
				panduan=0;
				break;
			case 3:
				jingdianguanli();
				panduan=0;
				break;
			case 4:
			    gerenxinxichaxun();
				panduan=0;
				break;
			case 5:
				exit(0);
				panduan=0;
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
}    
// ���������� 
void jingdianguanli()
{
	int choose,panduan=1; 
	printf("\n\n\t**************Tourist Menu*****************\n");
	printf("\t*            1.������Ϣ��ѯ               *\n");
	printf("\t*            2.��Ӿ�����Ϣ               *\n");
	printf("\t*            3.�����ϼ��˵�               *\n");
	printf("\t*******************************************\n");
	scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				jingdianxinxichaxun();
				panduan=0; 
				break;
			case 2:
				tianjiajingdianxinxi(); 
				panduan=0; 
				break;
			case 3:
				guanliyuancaidan(); 
				panduan=0; 
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
}   
//��Ӿ�����Ϣ���޸ķ���
void tianjiajingdianxinxi()
{
    FILE  *fpa;
    FILE  *fpb;
    int i=0;
    int c=0;
    int num1=0; 
    int ScenicSpotNum=8;//�������� 
    int panduan=1;//�ж��Ƿ�������ȷ 
    int panduan2;//�ж��Ƿ�����޸�
	int panduan3=0;//�жϾ���ID�Ƿ���ȷ
	int panduan4=0;//�жϾ��������Ƿ���ȷ 
	int e;//������Ϣ�Ƿ����� 
    int xuan;//ѡ��Ҫ�޸ĵ���Ϣ
	int tianjia;//����µ���Ϣ
	int queding;//�Ƿ񷢲�
	int discount1=1,discount2=1,discount3=1;//�ж��ۿ���Ϣ�����Ƿ�ϸ� 
	int menpiao;//�ж���Ʊ��Ϣ�Ƿ�����ϸ� 
    struct  ScenicSpot a[80];//�ݴ���Ϣ 
    struct  ScenicSpot b[80];//�ݴ���Ϣ
    //�򿪲���ȡ�ļ���Ϣ 
    fpa=fopen("������Ϣ.txt","a+");
	fpb=fopen("�����ϢԤ��.txt","a+");        
    for(i=0;i<ScenicSpotNum;i++)
    fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fpa);
    
		//�����µľ�����Ϣ 
        printf("�����뾰��ID\n");
		while(panduan3==0)
		{
			getchar(); 
    		scanf("%s",a[num1].ScenicSpot_ID);
    		panduan3=1;
    		for(c=0;c<ScenicSpotNum;c++)
    		if(strcmp(a[num1].ScenicSpot_ID,ScenicSpotList[c].ScenicSpot_ID)==0)//�ж��Ƿ񾰵�ID�ظ� 
			{ 
    	    	printf("����ID�ظ�\n");
    	    	panduan3=0; 
    			printf("���������뾰��ID\n");
    		}
    	}
    	printf("�����뾰������\n");
    	while(panduan4==0)
		{
    		scanf("%s",a[num1].ScenicSpot_NAME);
    		panduan4=1;
    		for(c=0;c<ScenicSpotNum;c++)
    		if(strcmp(a[num1].ScenicSpot_NAME,ScenicSpotList[c].ScenicSpot_NAME)==0)//�ж��Ƿ񾰵������ظ� 
			{ 
    			printf("���������ظ�\n");
    			panduan4=0;
    			printf("���������뾰������\n");
			}	
    	}
    	printf("�����뾰����\n");
    	scanf("%s",a[num1].ScenicSpot_INTRO);
    	printf("�����뾰��������Ʊ�۸�\n");
    	scanf("%d",&a[num1].ScenicSpot_PRICE1);
    	printf("�����뾰�㵭����Ʊ�۸�\n");
    	scanf("%d",&a[num1].ScenicSpot_PRICE2);
    	getchar();
    	printf("�����������þ�������ʱ��\n");
    	scanf("%s",a[num1].ScenicSpot_TIME);
    	printf("������ѧ���ۿ���Ϣ\n");
    	do
    	{
    		discount1=1;
    		scanf("%f",&a[num1].ScenicSpot_DISCOUNT1);
    		if(a[num1].ScenicSpot_DISCOUNT1>1)//�ж��ۿ���Ϣ�����Ƿ�ϸ�
    		{
    			discount1=0;
    			printf("�ۿ���Ϣ���벻�ϸ�����������\n");
    		}
    	}
    	while(discount1==0);
    	printf("����������ۿ���Ϣ\n");
    	do
    	{
    		discount2=1;
    		scanf("%f",&a[num1].ScenicSpot_DISCOUNT1);
    		if(a[num1].ScenicSpot_DISCOUNT1>1)//�ж��ۿ���Ϣ�����Ƿ�ϸ�
    		{
    			discount2=0;
    			printf("�ۿ���Ϣ���벻�ϸ�����������\n");
    		}
    	}
    	while(discount2==0);
    	printf("��������ͨ�ۿ���Ϣ\n");
    	do
    	{
    		discount3=1;
    		scanf("%f",&a[num1].ScenicSpot_DISCOUNT3);
    		if(a[num1].ScenicSpot_DISCOUNT3>1)//�ж��ۿ���Ϣ�����Ƿ�ϸ�
    		{
    			discount3=0;
    			printf("�ۿ���Ϣ���벻�ϸ�����������\n");
    		}
    	}
    	while(discount3==0);
    	getchar();
    	printf("�����뾰�㼶��\n");
    	scanf("%s",a[num1].ScenicSpot_GRADE);
    	printf("��������������\n");
    	scanf("%s",a[num1].ScenicSpot_NUMBER);
    	printf("�����뾰����������\n");
    	scanf("%s",a[num1].ScenicSpot_AREA);
    	printf("�����뾰��ά������\n");
    	scanf("%d",&a[num1].ScenicSpot_COST);
    	printf("�����뾰����Ʊ��\n");
    	do
    	{
    		menpiao=1;
    		scanf("%d",&a[num1].ScenicSpot_MENPIAO);
    		if(a[num1].ScenicSpot_MENPIAO<0)//�ж���Ʊ��Ϣ�Ƿ�����ϸ�
    		{
    			menpiao=0;
    			printf("���벻�ϸ�����������\n");
    		}
    	}
    	while(menpiao==0);
    	printf("�����뾰�������\n");
    	scanf("%f",&a[num1].ScenicSpot_HAOPING);
    	printf("�����뾰���Ƿ��������˶�ͯ\n");
    	getchar();
    	scanf("%s",a[num1].ScenicSpot_LRET); 
    	printf("��ȷ�Ͼ�����Ϣ�Ƿ�����\n1.�޸�\n2.ȡ�����\n3.����\n");
    	scanf("%d",&e);
    	if(e==1)
		{
			i++;
			do
			{
				printf("��ѡ��Ҫ�޸ĵ���Ϣ\n");
				printf("1.����ID\n");
				printf("2.��������\n");
				printf("3.������\n");
				printf("4.����������Ʊ�۸�\n");
				printf("5.���㵭����Ʊ�۸�\n");
				printf("6.�����þ�������ʱ��\n");
				printf("7.ѧ���ۿ���Ϣ\n");
				printf("8.�����ۿ���Ϣ\n");
				printf("9.��ͨ�ۿ���Ϣ\n");
				printf("10.���㼶��\n");
				printf("11.��������\n");
				printf("12.������������\n");
				printf("13.����ά������\n");
				printf("14.������Ʊ��\n");
				printf("15.���������\n");
				printf("16.�����Ƿ��������˶�ͯ\n");
				panduan=1;
				scanf("%d",&xuan);//ѡ��Ҫ�޸ĵ�ѡ�� 
				while(panduan!=0)//�ж������Ƿ�ϸ� 
				{
					switch(xuan)//Ҫ�޸ĵ�ѡ��
					{
						case 1:
							getchar();
							printf("����������Ϣ\n");
							panduan3=0; 
							while(panduan3==0)
							{ 
    							scanf("%s",b[num1].ScenicSpot_ID);
    							panduan3=1;
    							for(c=0;c<ScenicSpotNum;c++)
    							if(strcmp(b[num1].ScenicSpot_ID,ScenicSpotList[c].ScenicSpot_ID)==0)//�ж��Ƿ񾰵�ID�ظ� 
								{ 
    	    						printf("����ID�ظ�\n");
    	    						panduan3=0; 
    								printf("���������뾰��ID\n");
    							}
    						}
							strncpy(a[num1].ScenicSpot_ID,b[num1].ScenicSpot_ID,100);
							panduan=0;
							break;
						case 2:
							getchar();
							printf("����������Ϣ\n");
							panduan4=0;
							while(panduan4==0)
							{ 
    							scanf("%s",b[num1].ScenicSpot_NAME);
    							panduan4=1;
    							for(c=0;c<ScenicSpotNum;c++)
    							if(strcmp(b[num1].ScenicSpot_NAME,ScenicSpotList[c].ScenicSpot_NAME)==0)//�ж��Ƿ񾰵������ظ� 
								{ 
    								printf("���������ظ�");
    								panduan4=0;
    								printf("���������뾰������\n");
								}	
    						}
							strncpy(a[num1].ScenicSpot_NAME,b[num1].ScenicSpot_NAME,100);
							panduan=0;
							break;
						case 3:
							getchar();
							printf("����������Ϣ\n");
							scanf("%s",b[num1].ScenicSpot_INTRO);
							strncpy(a[num1].ScenicSpot_INTRO,b[num1].ScenicSpot_INTRO,100);
							panduan=0;
							break;
						case 4:
							scanf("%d",&b[num1].ScenicSpot_PRICE1);
							a[num1].ScenicSpot_PRICE1=b[num1].ScenicSpot_PRICE1;
							panduan=0;
							break;
						case 5:
							printf("����������Ϣ\n");
							scanf("%d",&b[num1].ScenicSpot_PRICE2); 
							a[num1].ScenicSpot_PRICE2=b[num1].ScenicSpot_PRICE2;
							panduan=0;
							break;
						case 6:
							getchar();
							printf("����������Ϣ\n");
							scanf("%s",b[num1].ScenicSpot_TIME); 
							strncpy(a[num1].ScenicSpot_TIME,b[num1].ScenicSpot_TIME,100);
							panduan=0;
							break;
						case 7:
							printf("����������Ϣ\n"); 
							scanf("%f",&b[num1].ScenicSpot_DISCOUNT1);
							a[num1].ScenicSpot_DISCOUNT1=b[num1].ScenicSpot_DISCOUNT1;
							panduan=0;
							break;
						case 8:
							printf("����������Ϣ\n");
							scanf("%f",&b[num1].ScenicSpot_DISCOUNT2);
							a[num1].ScenicSpot_DISCOUNT2=b[num1].ScenicSpot_DISCOUNT2;
							panduan=0;
							break; 
						case 9:
							printf("����������Ϣ\n");
							scanf("%f",&b[num1].ScenicSpot_DISCOUNT3);
							a[num1].ScenicSpot_DISCOUNT3=b[num1].ScenicSpot_DISCOUNT3;
							panduan=0;
							break; 
						case 10:
							printf("����������Ϣ\n");
							getchar();
							scanf("%s",b[num1].ScenicSpot_GRADE); 
							strncpy(a[num1].ScenicSpot_GRADE,b[num1].ScenicSpot_GRADE,100);
							panduan=0;
							break;
						case 11:
							printf("����������Ϣ\n");
							scanf("%s",b[num1].ScenicSpot_NUMBER); 
							strncpy(a[num1].ScenicSpot_NUMBER,b[num1].ScenicSpot_NUMBER,100);
							panduan=0;
							break;
						case 12:
							printf("����������Ϣ\n");
							getchar();
							scanf("%s",b[num1].ScenicSpot_AREA); 
							strncpy(a[num1].ScenicSpot_AREA,b[num1].ScenicSpot_AREA,100);
							panduan=0;
							break;
						case 13:
							printf("����������Ϣ\n");
							scanf("%d",&b[num1].ScenicSpot_COST);
							a[num1].ScenicSpot_COST=b[num1].ScenicSpot_COST;
							panduan=0;
							break;
						case 14:
							printf("����������Ϣ\n");
							scanf("%d",&b[num1].ScenicSpot_MENPIAO);
							a[num1].ScenicSpot_MENPIAO=b[num1].ScenicSpot_MENPIAO;
							panduan=0;
							break;
						case 15:
							printf("����������Ϣ\n");
							scanf("%f",&b[num1].ScenicSpot_HAOPING);	
							a[num1].ScenicSpot_HAOPING=b[num1].ScenicSpot_HAOPING;
							break;
						case 16:
							printf("����������Ϣ\n");
							getchar();
							scanf("%s",b[num1].ScenicSpot_LRET);
							strncpy(a[num1].ScenicSpot_LRET,b[num1].ScenicSpot_LRET,100);
							panduan=0;
							break;
						default:
							printf("������������д������������룺\n");
							scanf("%d",&xuan);
							break;
					}	
				}
				if(panduan==0)
				{
					printf("�Ƿ�����޸�\n1.��\t2.��\n");//�Ƿ�����޸� 
					scanf("%d",&panduan2); 
				}
			}
			while(panduan2==1); 
			printf("��ȷ���Ƿ񷢲�\n1.�� 2.��\n");//�޸�����Ϣ���Ƿ񷢲� 
			scanf("%d",&queding);
			if(queding==1)//���� 
			{
				fseek(fpa,0L,2);
				fwrite(&a[num1],sizeof(ScenicSpot),1,fpa);
			}
			else//������ 
			{
				fwrite(&ScenicSpotList[i],sizeof(ScenicSpot),1,fpb);
				remove("�����ϢԤ��.txt");
			}
		}
    	if(e==2)//ȡ������ 
		{
			fwrite(&a[num1],sizeof(ScenicSpot),1,fpb);
			remove("�����ϢԤ��.txt");
		}
    	if(e==3)//������Ϣ 
		{
			strncpy(ScenicSpotList[i].ScenicSpot_ID,a[num1].ScenicSpot_ID,100);
			strncpy(ScenicSpotList[i].ScenicSpot_NAME,a[num1].ScenicSpot_NAME,100);
			strncpy(ScenicSpotList[i].ScenicSpot_INTRO,a[num1].ScenicSpot_INTRO,100);
			ScenicSpotList[i].ScenicSpot_PRICE1=a[num1].ScenicSpot_PRICE1;
			ScenicSpotList[i].ScenicSpot_PRICE2=a[num1].ScenicSpot_PRICE2;
			strncpy(ScenicSpotList[i].ScenicSpot_TIME,a[num1].ScenicSpot_TIME,100);
			ScenicSpotList[i].ScenicSpot_DISCOUNT1=a[num1].ScenicSpot_DISCOUNT1;
			ScenicSpotList[i].ScenicSpot_DISCOUNT2=a[num1].ScenicSpot_DISCOUNT2;
			ScenicSpotList[i].ScenicSpot_DISCOUNT3=a[num1].ScenicSpot_DISCOUNT3;
			strncpy(ScenicSpotList[i].ScenicSpot_GRADE,a[num1].ScenicSpot_GRADE,100);
			strncpy(ScenicSpotList[i].ScenicSpot_NUMBER,a[num1].ScenicSpot_NUMBER,100);
			strncpy(ScenicSpotList[i].ScenicSpot_AREA,a[num1].ScenicSpot_AREA,100);
			ScenicSpotList[i].ScenicSpot_COST=a[num1].ScenicSpot_COST;
			ScenicSpotList[i].ScenicSpot_MENPIAO=a[num1].ScenicSpot_MENPIAO;
			ScenicSpotList[i].ScenicSpot_HAOPING=a[num1].ScenicSpot_HAOPING;
			strncpy(ScenicSpotList[i].ScenicSpot_LRET,a[num1].ScenicSpot_LRET,100);
			fseek(fpa,0L,2);
			fwrite(&ScenicSpotList[i],sizeof(ScenicSpot),1,fpa);
    	}
    	num1++;
    	ScenicSpotNum++;
		printf("�Ƿ��������µľ�����Ϣ\n1.��\t2.��\n");
		scanf("%d",&tianjia); 
	
	if(tianjia==1)
	tianjiajingdianxinxi();
	else
	fclose(fpa);
	fclose(fpb);
	
	    		printf("�������Ƿ���Ҫ����ʹ��ϵͳ��\n1.���ع��ܽ���\n2.�˳�\n");
	    		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				guanliyuancaidan();
				panduan1=0;
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
		    
}	
//������ѯ
void dingdanchaxun()
{
	printf("\n\n\t**************Tourist Menu*****************\n");
	printf("\t*           1.�οͶ���                    *\n");
	printf("\t*           2.�������Ʊ�������          *\n");
	printf("\t*******************************************\n");
	   	int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				dingdanchaxun1();
				panduan1=0;
				break;
			case 2:
				dingdanchaxun2();
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
} 
//������ѯ -�û����� 
void dingdanchaxun1()
{
		FILE  *fp;
        int  i,t,m=1,n=1;
        fp=fopen("������Ϣ.txt","rb");
        char dingdanchaxun1[80]={"\0"};
	    printf("������Ҫ��ѯ�Ķ�����ţ�\n");
		scanf("%s",dingdanchaxun1);
      for(i=0;fread(&info[i],sizeof(struct  info_list),1,fp)==1;i++);
        t=i+1;
		
		while(m!=0) 
	{
		for(i=0;i<t;i++)
		{
		if(strcmp(dingdanchaxun1,info[i].order_ID)==0)//���ļ���������Ķ�����ţ������if���� 
			{
			printf("�������: "); 
		    puts(info[i].order_ID);
		    printf("�ο�ID��"); 
		    printf("%s\n",info[i].order_ID1); 
		    printf("������: ");
	        puts(info[i].order_NUMBER);
		    printf("ѧ�����: ");
	       	printf("%d\n",info[i].order_IDENTITY1);
	        printf("�������: ");
	        printf("%d\n",info[i].order_IDENTITY2);
	        printf("��ͨ���:");
	        printf("%d\n",info[i].order_IDENTITY3);
	        printf("�����: ");
	      	puts(info[i].order_AGE);
	      	printf("����: ");
	        printf("%d\n",info[i].order_PEOPLENUM);
	        printf("�������: ");
	        printf("%d\n",info[i].order_YEAR);
		    printf("�����·�: ");
	        printf("%d\n",info[i].order_MONTH);
	        printf("������: ");
	        printf("%d\n",info[i].order_DAY);
	        printf("����Сʱ: ");
	        printf("%d\n",info[i].order_HOUR);
	        printf("��������: ");
	        printf("%d\n",info[i].order_MINUTE);
	        printf("�����ܼ۸�: ");
	        printf("%.2f\n",info[i].order_PRICE);
	        printf("������������: ");
	        puts(info[i].order_jidu);
			m=0;
			n=0;
			}
		}
			if(n!=0)
			{
			printf("������Ķ�������������������룺\n");
			scanf("%s",dingdanchaxun1);
			}
		}
		fclose(fp);
		printf("\n\n\t**************Tourist Menu*****************\n");
		printf("\t*              1.���ع��ܽ���             *\n");
		printf("\t*              2.�˳�                     *\n");
		printf("\t*******************************************\n");
	    		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				guanliyuancaidan();
				panduan1=0;
				break;
			case 2:
				printf("��л����ʹ�ã��ټ���\n"); 
				exit(0);
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
}
//������ѯ-����Ʊ�� 
void dingdanchaxun2()
{
	FILE  *fp;
        int  i,t,m=1,n=1;
        fp=fopen("������Ϣ.txt","rb");
        char jingdianbianhaochaxun1[80]={"\0"};
	    printf("������Ҫ��ѯ�ľ����ţ�\n");
		scanf("%s",jingdianbianhaochaxun1);
      for(i=0;fread(&info[i],sizeof(struct  info_list),1,fp)==1;i++);
        t=i+1;
		
		while(m!=0) 
	{
		for(i=0;i<t;i++)
		{
		if(strcmp(jingdianbianhaochaxun1,info[i].order_NUMBER)==0)//���ļ���������Ķ�����ţ������if���� 
			{
			printf("�������: "); 
		    puts(info[i].order_ID);
		    printf("�ο�ID��"); 
		    printf("%s\n",info[i].order_ID1); 
		    printf("������: ");
	        puts(info[i].order_NUMBER);
		    printf("ѧ�����: ");
	       	printf("%d\n",info[i].order_IDENTITY1);
	        printf("�������: ");
	        printf("%d\n",info[i].order_IDENTITY2);
	        printf("��ͨ���:");
	        printf("%d\n",info[i].order_IDENTITY3);
	        printf("�����: ");
	      	puts(info[i].order_AGE);
	      	printf("����: ");
	        printf("%d\n",info[i].order_PEOPLENUM);
	        printf("�������: ");
	        printf("%d\n",info[i].order_YEAR);
		    printf("�����·�: ");
	        printf("%d\n",info[i].order_MONTH);
	        printf("������: ");
	        printf("%d\n",info[i].order_DAY);
	        printf("����Сʱ: ");
	        printf("%d\n",info[i].order_HOUR);
	        printf("��������: ");
	        printf("%d\n",info[i].order_MINUTE);
	        printf("�����ܼ۸�: ");
	        printf("%.2f\n",info[i].order_PRICE);
	        printf("������������: ");
	        puts(info[i].order_jidu);
			m=0;
			n=0;
			}
		}
			if(n!=0)
			{
			printf("������ľ������������������룺\n");
			scanf("%s",jingdianbianhaochaxun1);
			}
		}
		fclose(fp);
	
		printf("\n\n\t**************Tourist Menu*****************\n");
		printf("\t*              1.���ع��ܽ���             *\n");
		printf("\t*              2.�˳�                     *\n");
		printf("\t*******************************************\n");
	    	int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				guanliyuancaidan();
				panduan1=0;
				break;
			case 2:
				printf("��л����ʹ�ã��ټ���\n");
				exit(0);
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
}
//������Ϣ��ѯ 
void  jingdianxinxichaxun()
{
	FILE  *fp;
        int  i,t,m=1,n=1;
        fp=fopen("������Ϣ.txt","rb");
        char jingdianchaxun1[80]={"\0"};
	    printf("������Ҫ��ѯ�ľ������ƣ�\n");
		scanf("%s",jingdianchaxun1);
      for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)==1;i++)
        t=i+1;
		
		while(m!=0) 
	{
		for(i=0;i<t;i++)
		{
		if(strcmp(jingdianchaxun1,ScenicSpotList[i].ScenicSpot_NAME)==0)//���ļ���������ľ������ƣ������if���� 
			{
			printf("����ID: "); 
		    puts(ScenicSpotList[i].ScenicSpot_ID);
	        printf("��������: ");
	        puts(ScenicSpotList[i].ScenicSpot_NAME);
		    printf("������: ");
	        puts(ScenicSpotList[i].ScenicSpot_INTRO);
	        printf("����������Ʊ�۸�: ");
	        printf("%d\n",ScenicSpotList[i].ScenicSpot_PRICE1);
	        printf("���㵭����Ʊ�۸�: ");
	        printf("%d\n",ScenicSpotList[i].ScenicSpot_PRICE2);
	        printf("�����þ�������ʱ��: ");
	        puts(ScenicSpotList[i].ScenicSpot_TIME);
	        printf("ѧ���ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[i].ScenicSpot_DISCOUNT1);
	        printf("�����ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[i].ScenicSpot_DISCOUNT2);
	        printf("��ͨ�ۿ���Ϣ: ");
	        printf("%.2f\n",ScenicSpotList[i].ScenicSpot_DISCOUNT3);
	        printf("���㼶��: ");
	        puts(ScenicSpotList[i].ScenicSpot_GRADE);
	        printf("��������: ");
	        puts(ScenicSpotList[i].ScenicSpot_NUMBER);
	        printf("������������: ");
	        puts(ScenicSpotList[i].ScenicSpot_AREA);
	        printf("����ά������:");
	        printf("%d\n",ScenicSpotList[i].ScenicSpot_COST);
			printf("������Ʊ: ");
			printf("%d\n",ScenicSpotList[i].ScenicSpot_MENPIAO);
			printf("�����������: ");
			printf("%d\n",ScenicSpotList[i].ScenicSpot_VISIT);
			printf("����Ԥ����: ");
			printf("%d\n",ScenicSpotList[i].ScenicSpot_YUDING);
			printf("���������: ");
			printf("%.2f\n",ScenicSpotList[i].ScenicSpot_HAOPING);
			printf("���������˶�ͯ: ");
			puts(ScenicSpotList[i].ScenicSpot_LRET);
			m=0;
			n=0;
			}
		}
			if(n!=0)
			{
			printf("������ľ��������������������룺\n");
			scanf("%s",jingdianchaxun1);
			}
		}
		fclose(fp);
		
		printf("\n\n\t**************Tourist Menu*****************\n");
		printf("\t*              1.���ع��ܽ���             *\n");
		printf("\t*              2.�˳�                     *\n");
		printf("\t*******************************************\n");
	    		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				guanliyuancaidan();
				panduan1=0;
				break;
			case 2:
				printf("��л����ʹ�ã��ټ�!\n");
				exit(0);
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
}
//����Ա������Ϣ��ѯ 
void  gerenxinxichaxun()
{
		FILE  *fp,*fp2;
        int n;
        char administrator_ID2[80];
        fp=fopen("����Ա��Ϣ.txt","rb");        
        fp2=fopen("����Ա�û��������뱸��.txt","r");
        for(n=0;fread(&administratorList[n],sizeof(struct administrator),1,fp2)!=0;n++)
        {
        	
		}
        printf("������������������������������������������������������������������\n");
        printf("                         ��ѯ���\n");
        printf("------------------------------------------------------------------\n");
        printf("����ԱID\t����Ա����\t����Ա�绰\t����Ա����\n");
		printf("------------------------------------------------------------------\n"); 
		for(int i=0;fread(&administratorList[i],sizeof(struct  administrator),1,fp)==1;i++)
        	if(strcmp(administratorList[i].administrator_ID,administrator_ID2)==0)
        	{
				printf("%s\t%s\t",administratorList[i].administrator_ID,administratorList[i].administrator_PASSWORD);
			    printf("%s\t%s\n",administratorList[i].administrator_PHONE,administratorList[i].administrator_MAIL);
			}
		printf("------------------------------------------------------------------\n\n");
        printf("������������������������������������������������������������������\n\n\n");
        fclose(fp);
        printf("\n\n\t**************Tourist Menu*****************\n");
        printf("\t*          �������Ƿ���Ҫ�޸���Ϣ��       *\n");
		printf("\t*              1.��                       *\n");
		printf("\t*              2.���ع��ܽ���             *\n");
		printf("\t*******************************************\n");
	    		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				guanliyuanxiugai();
				panduan1=0;
				break;
			case 2:
				guanliyuancaidan();
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
}	
//����ͳ�ƽ��� 
void dingdantongji()
{
	int choose,panduan=1;
	printf("\n\n\t**************Tourist Menu*****************\n");
	printf("\t*      1.��Ԥ�����Ծ����������           *\n");
	printf("\t*      2.�����������Ծ����������         *\n");
	printf("\t*      3.�����������������               *\n");
	printf("\t*      4.ͳ�Ʋ�ͬ������û������ηֲ�   *\n");
	printf("\t*      5.�����ȶԲ�ͬ�������Ʊ�������   *\n");
	printf("\t*      6.�˳�����                         *\n");
	printf("\t*******************************************\n");
	scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				yudingliangpaixu1();
				panduan=0; 
				break;
			case 2:
				fangwenrenshupaixu();
				panduan=0;
				break;
			case 3:
				lirunpaixu();
				panduan=0;
				break;
			case 4:
			    age();
				panduan=0;
				break;
			case 5:
				tuijian();
				panduan=0;
				break;
			case 6:
				exit(0);
				panduan=0;
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
}
//������Ԥ�����Ӵ�С����
void yudingliangpaixu1() 
{
 
   FILE *fp,*fp2;
   fp=fopen("������Ϣ.txt","rb");//���ļ���������Ϣ�� 
    int i;
     for(i=0;fread(&ScenicSpotList2[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);
     //�����������ơ�����Ϣ��ֵ�� ScenicSpotList2
    fp2=fopen("������Ϣ.txt","rb");//���ļ�������Ϣ 
    int i2;//i2Ϊ�������� 
     for(i2=0;fread(&info[i2],sizeof(struct info_list),1,fp2)!=0;i2++);
     //���㶩������ 
    int yu[80];
      for(int n=0;n<i;n++)
	   yu[n]=0;//ΪԤ������������ 
    //strcmp(dsfsfs,dfdfd)
     for(int n=0;n<i;n++)
      { for(int j=0;j<i2;j++)
         if(strcmp(ScenicSpotList2[n].ScenicSpot_ID,info[j].order_NUMBER)==0)
           yu[n]=yu[n]+info[j].order_IDENTITY1+info[j].order_IDENTITY2+info[j].order_IDENTITY3;
	  }
    //���ݾ���id���ֱ���������Ԥ���� 
    for(int n=0;n<i;n++)
     {
        //ScenicSpotList2[n]=ScenicSpotList[n];
     	ScenicSpotList2[n].ScenicSpot_YUDING=yu[n];
	 }
	 // �����޸ĺ�Ԥ���� 
     fclose(fp);
     fclose(fp2);
     fp=fopen("������Ϣ.dat","wb");
     fwrite(&ScenicSpotList2,sizeof(struct  ScenicSpot),i,fp);
     fclose(fp);
     //���޸ĺ���Ϣ���롰������Ϣ��   
	 FILE *fp3;
     fp3=fopen("������Ϣ.dat","rb");//���ļ����������� 
      
    for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//�����ļ��о�������,���㾰����� ,i�Ǿ������    
	
     	int j,k;//n,j,k������������ ScenicSpotList2������������     	
	 for(int n=1;n<i;n++)
    {
      k=ScenicSpotList[n].ScenicSpot_YUDING ;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//���� ScenicSpotList[n]���� 
      j=n-1;//j����������ǰ���������ǰ���ݽ������� 
        while((j>=0)&&(ScenicSpotList[j].ScenicSpot_YUDING<k))
        // j��Ϊ����ScenicSpotList[n-1]>ScenicSpotList[n],�򽻻�
      {
         ScenicSpotList[j+1].ScenicSpot_YUDING =ScenicSpotList[j].ScenicSpot_YUDING ;
         ScenicSpotList[j+1]=ScenicSpotList[j];         
         j--;
      } //j-1�������Ƚ� ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_YUDING=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];
   }
     printf("   ��������          ����ID          ����Ԥ����\n");    
    for(int n=0;n<i;n++)
     {       
       printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_YUDING  );
     }//�������󾰵����� 
     fclose(fp3);
     
   		printf("\n\n\t**************Tourist Menu*****************\n");
		printf("\t*              1.���ع��ܽ���             *\n");
		printf("\t*              2.�˳�                     *\n");
		printf("\t*******************************************\n");
	    	int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				guanliyuancaidan();
				panduan1=0;
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
  }
 //�޸Ĺ���Ա��������� 
void guanliyuanxiugai()
{  
    void guanliyuancaidan();
    printf("\t**************Tourist Menu***************\n");
    printf("\t*            1.�����޸�                  *\n");
    printf("\t*            2.�����޸�                  *\n");
    printf("\t*            3.ȡ���޸�                  *\n");
    printf("\t*****************************************\n");
    int panduan;
    scanf("%d",&panduan);//ѡ���޸���������� 
    		
     FILE *fp,*fp2;
     fp=fopen("����Ա��Ϣ.txt","rb");
       fread(&administratorList,sizeof(struct administrator),3,fp);//��ȡ����Ա��Ϣ������
     fp2=fopen("����Ա�û��������뱸��.txt","rb");
       //fread(&administratorList2[0],sizeof(struct administrator),1,fp2);
       //fgets(m,20,fp2);
       fread(&administratorList1,sizeof(struct administrator1),1,fp2);//��ȡ����������
    int i,n;       
    for(n=0;n<3;n++)
        {
        	if(strcmp(administratorList[n].administrator_ID,administratorList1[n].administrator1_ID)==0)
			   i=n;
	    }//�ж����޸ĵ���Ϣ�ǵڼ�������Ա�ģ�iΪ�ù���Ա��� 
    printf("%s\n",administratorList1[n].administrator1_PASSWORD);
   switch (panduan)       
  {      
      case 1:  //1Ϊ��������޸�
  	{	 
	  //switch  
     char mima[20];     
    
        printf("������ԭ����\n");
         scanf("%s",&mima);
       for(n=0;n<3;n++)
	 {	  
       if(strcmp(mima,administratorList1[i].administrator1_PASSWORD)==0)
       {
       	 printf("������������\n"); 
       	  scanf("%s",&administratorList[i].administrator_PASSWORD);
       	  break;
	   }
     else
      {
	     printf("���������������������\n");  
		      
       } 
     }    
    
      if(n==3)
      {	  
       printf("��������������Σ��������˵�\n");
       guanliyuancaidan();
       exit(0);
      }
      fclose(fp);
      fclose(fp2);
      fp=fopen("����Ա��Ϣ.txt","wb");
      fwrite(&administratorList,sizeof(struct administrator),3,fp);
	 printf("�����޸ĳɹ��������������Ч\n");
			exit(0);  	        
    }
    case 2:
     {
     	char mail[20];
     	for(n=0;n<3;n++)
		{
		 printf("������������\n");
		 scanf("%s",&mail);
		  //for()
		   int a,d;
		     for(a=1;a<20;a++)
		      {
		   	    if(mail[a]==64)
		   	    break;
		      }		     
		     for(d=1;d<20;d++)
		      {
		      	if(mail[d]=='.')
		      	break;
			  }
			  if(a==20||a>d||d==20)
			  {
		      printf("��ʽ�����������������\n");
		      break;
		      }
		      if(mail[d+1]<0||mail[d+1]>'z')
		      {
		      	printf("��ʽ�����������������\n");
		      	break;
			  }
		}	  
			  if(n==3)
			  {			  
                printf("�����ʽ����������Σ��������˵�\n");
                guanliyuancaidan();
                exit(1);
               } 
			strcpy(administratorList[i].administrator_MAIL,mail);
			FILE *fp3;
			fp3=fopen("����Ա��Ϣ.txt","wb");
			fwrite(&administratorList,sizeof(struct administrator),3,fp3);
			fclose(fp3);
			printf("�����޸ĳɹ��������������Ч\n");
			
			exit(2);
    	
	 }
	 
	 case 3:
	  guanliyuancaidan();
	  break;
	
	default:
				printf("����������ݴ������������룺\n\n");				
				guanliyuanxiugai();
				break;
   }	
  
    		printf("\n\n\t**************Tourist Menu*****************\n");
		printf("\t*              1.���ع��ܽ���             *\n");
		printf("\t*              2.�˳�                     *\n");
		printf("\t*******************************************\n");
	    	int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				guanliyuancaidan();
				panduan1=0;
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
 } 
//������������С��������
void fangwenrenshupaixu() 
{ 
 FILE *fp,*fp2;
   fp=fopen("������Ϣ.txt","rb");//���ļ���������Ϣ�� 
    int i;
     for(i=0;fread(&ScenicSpotList2[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);
     //�����������ơ�����Ϣ��ֵ�� ScenicSpotList2
    fp2=fopen("������Ϣ.txt","rb");//���ļ�������Ϣ 
    int i2;//i2Ϊ�������� 
     for(i2=0;fread(&info[i2],sizeof(struct info_list),1,fp2)!=0;i2++);
     //���㶩������ 
    int fang[80];
      for(int n=0;n<i;n++)
	   fang[n]=0;//Ϊ���������������� 
    //strcmp(dsfsfs,dfdfd)
     for(int n=0;n<i;n++)
      { for(int j=0;j<i2;j++)
         if(strcmp(ScenicSpotList2[n].ScenicSpot_ID,info[j].order_NUMBER)==0)
           fang[n]=fang[n]+info[j].order_IDENTITY1+info[j].order_IDENTITY2+info[j].order_IDENTITY3;
	  }
    //���ݾ���id���ֱ���������������� 
    for(int n=0;n<i;n++)
     {
        //ScenicSpotList2[n]=ScenicSpotList[n];
     	ScenicSpotList2[n].ScenicSpot_YUDING=fang[n];
	 }
	 // �����޸ĺ��������
     fclose(fp);
     fclose(fp2);
     fp=fopen("������Ϣ.dat","wb");
     fwrite(&ScenicSpotList2,sizeof(struct  ScenicSpot),i,fp);
     fclose(fp);
     //���޸ĺ���Ϣ���롰������Ϣ��   
	 FILE *fp3;
     fp3=fopen("������Ϣ.dat","rb");//���ļ����������� 
      
    for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//�����ļ��о�������,���㾰����� ,i�Ǿ������    
	
     	int j,k,n;//n,j,k������������ ScenicSpotList2������������     	
	 for(int n=1;n<i;n++)
    {
      k=ScenicSpotList[n].ScenicSpot_YUDING ;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//���� ScenicSpotList[n]���� 
      j=n-1;//j����������ǰ���������ǰ���ݽ������� 
        while((j>=0)&&(ScenicSpotList[j].ScenicSpot_YUDING<k))
        // j��Ϊ����ScenicSpotList[n-1]>ScenicSpotList[n],�򽻻�
      {
         ScenicSpotList[j+1].ScenicSpot_YUDING =ScenicSpotList[j].ScenicSpot_YUDING ;
         ScenicSpotList[j+1]=ScenicSpotList[j];         
         j--;
      } //j-1�������Ƚ� ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_YUDING=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];
   }
     printf("   ��������          ����ID          �����������\n");    
    for(int n=0;n<i;n++)
     {       
       printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_YUDING  );
     }//�������󾰵����� 
     fclose(fp3);
     
       		printf("\n\n\t**************Tourist Menu*****************\n");
		printf("\t*              1.���ع��ܽ���             *\n");
		printf("\t*              2.�˳�                     *\n");
		printf("\t*******************************************\n");
	    	int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				guanliyuancaidan();
				panduan1=0;
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
}
//�����ɴ�С����   
void lirunpaixu()
{ 
     FILE *fp,*fp2;
     fp=fopen("������Ϣ.txt","rb");//���ļ���������Ϣ 
     int i,d; 
      
    for(i=1;fread(&ScenicSpotList[i-1],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//�����ļ��о�������,���㾰����� ,i�Ǿ������ 
	  fp2=fopen("������Ϣ.txt","rb");
	for(d=0;fread(&info[d],sizeof(struct info_list),1,fp2)!=0;d++);
	//dΪ�������� 
	  for(int k=0;k<i;k++)
	  {	  
	    for(int n=0;n<d;d++)
	      {
	    	if(strcmp(ScenicSpotList[k].ScenicSpot_ID,info[n].order_ID)==0)
	    	 ScenicSpotList[k].ScenicSpot_COST=ScenicSpotList[k].ScenicSpot_COST-info[n].order_PRICE;
	      }
	  }    //���ݾ���ID�ֱ�������������� 
	int j,k,n;//n,j,k������������ ScenicSpotList2������������ 
	 for(int n=1;n<i;n++)
   {
      k=ScenicSpotList[n].ScenicSpot_COST;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//���� ScenicSpotList[n]���� 
      j=n-1;//j����������ǰ���������ǰ���ݽ������� 
        while((j>=0)&&(ScenicSpotList[n].ScenicSpot_COST<k))
        // j��Ϊ����ScenicSpotList[n-1]>ScenicSpotList[n],�򽻻�
      {
         ScenicSpotList[j+1].ScenicSpot_COST=ScenicSpotList[j].ScenicSpot_COST;
         ScenicSpotList2[j+1]=ScenicSpotList[j];         
         j--;
      } //j-1�������Ƚ� ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_COST=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];
      printf("   ��������          ����ID          ����");
    for(int n=0;n<i-1;n++)
    {       
       printf("%11s\t%11s\t%11.2f\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_COST );
    }//�������󾰵����� 
      fclose(fp);//�ر��ļ� 	
  }
    		printf("\n\n\t**************Tourist Menu*****************\n");
		printf("\t*              1.���ع��ܽ���             *\n");
		printf("\t*              2.�˳�                     *\n");
		printf("\t*******************************************\n");
	    	int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				guanliyuancaidan();
				panduan1=0;
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
}
 //����ֲ� 
void age()
{
     	FILE *fp,*fp2;
        fp=fopen("������Ϣ.txt","rb");//���ļ���������Ϣ�� 
         int i;
          for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);
        //�����������ơ�����Ϣ��ֵ�� ScenicSpotList2
        fp2=fopen("������Ϣ.txt","rb");//���ļ�������Ϣ 
         int i2;//i2Ϊ�������� 
          for(i2=0;fread(&info[i2],sizeof(struct info_list),1,fp2)!=0;i2++);
        //���㶩������ 
        printf("   ��������          ����ID          ������") ;
       for(int n=0;n<i;n++)
         {
         	printf("%11s\t%11s\t",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID);
         	for(int k=0;k<i2;k++)
         	  {
         	  	if(strcmp(ScenicSpotList[n].ScenicSpot_ID,info[k].order_ID)==0)
         	  	 printf("%d\t",info[k].order_AGE);
			   }
		 }
		 fclose(fp);
		 fclose(fp2);
	 }
//��ͬ���Ⱦ����Ƽ�
void tuijian()
{
  FILE *fp,*fp2;
   fp=fopen("������Ϣ.txt","rb");//���ļ���������Ϣ�� 
    int i;
     for(i=0;fread(&ScenicSpotList2[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);
     //�����������ơ�����Ϣ��ֵ�� ScenicSpotList2
    fp2=fopen("������Ϣ.txt","rb");//���ļ�������Ϣ 
    int i2;//i2Ϊ�������� 
     for(i2=0;fread(&info[i2],sizeof(struct info_list),1,fp2)!=0;i2++);
     //���㶩������ 
    int yu[3][80];
    for(int n=0;n<4;n++)
     for(int j=0;j<i2;j++)
      yu[n][j]=0;
      
     for(int n=0;n<i;n++)
      { 
	    for(int j=0;j<i2;j++)
         if(strcmp(ScenicSpotList2[n].ScenicSpot_ID,info[j].order_NUMBER)==0&&info[j].order_MONTH>0&&info[j].order_MONTH<4)
           yu[0][n]=yu[0][n]+info[j].order_IDENTITY1+info[j].order_IDENTITY2+info[j].order_IDENTITY3;
	  }
	  
    //���ݾ���id���ֱ���������Ԥ���� 
    for(int n=0;n<i;n++)
     {
        
     	ScenicSpotList2[n].ScenicSpot_YUDING=yu[0][n];
	 }
	 // �����޸ĺ�Ԥ���� 
     fclose(fp);
     fclose(fp2);
     fp=fopen("������Ϣ.dat","wb");
     fwrite(&ScenicSpotList2,sizeof(struct  ScenicSpot),i,fp);
     fclose(fp);
     //���޸ĺ���Ϣ���롰������Ϣ��   
	 FILE *fp3;
	 
	 	int j,k,n;//n,j,k������������ ScenicSpotList2������������     	
	 for(int n=1;n<i;n++)
    {
      k=ScenicSpotList[n].ScenicSpot_YUDING ;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//���� ScenicSpotList[n]���� 
      j=n-1;//j����������ǰ���������ǰ���ݽ������� 
        while((j>=0)&&(ScenicSpotList[j].ScenicSpot_YUDING<k))
        // j��Ϊ����ScenicSpotList[n-1]>ScenicSpotList[n],�򽻻�
      {
         ScenicSpotList[j+1].ScenicSpot_YUDING =ScenicSpotList[j].ScenicSpot_YUDING ;
         ScenicSpotList[j+1]=ScenicSpotList[j];         
         j--;
      } //j-1�������Ƚ� ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_YUDING=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];
   }
	 
     fp3=fopen("������Ϣ.dat","rb");//���ļ����������� 
      
	    printf("���ž����Ƽ�\n\n"); 
	   printf("   ��������          ����ID          ������"); 
	   printf("��һ����\n");
	   for(int n=0;n<i-1;n++)
       {       
          printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_YUDING );
       }
       
       
     for(int n=0;n<i;n++)
      { 
	    for(int j=0;j<i2;j++)
         if(strcmp(ScenicSpotList2[n].ScenicSpot_ID,info[j].order_NUMBER)==0&&info[j].order_MONTH>3&&info[j].order_MONTH<7)
           yu[1][n]=yu[1][n]+info[j].order_IDENTITY1+info[j].order_IDENTITY2+info[j].order_IDENTITY3;
	  } 
    //���ݾ���id���ֱ���������Ԥ���� 
    for(int n=0;n<i;n++)
     {
        
     	ScenicSpotList2[n].ScenicSpot_YUDING=yu[1][n];
	 }
	 // �����޸ĺ�Ԥ���� 
     fclose(fp);
     fclose(fp2);
     fp=fopen("������Ϣ.dat","wb");
     fwrite(&ScenicSpotList2,sizeof(struct  ScenicSpot),i,fp);
     fclose(fp);
     //���޸ĺ���Ϣ���롰������Ϣ��   
	 
     fp3=fopen("������Ϣ.dat","rb");//���ļ�����������  
	 
	 	     	
	 for(int n=1;n<i;n++)
    {
      k=ScenicSpotList[n].ScenicSpot_YUDING ;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//���� ScenicSpotList[n]���� 
      j=n-1;//j����������ǰ���������ǰ���ݽ������� 
        while((j>=0)&&(ScenicSpotList[j].ScenicSpot_YUDING<k))
        // j��Ϊ����ScenicSpotList[n-1]>ScenicSpotList[n],�򽻻�
      {
         ScenicSpotList[j+1].ScenicSpot_YUDING =ScenicSpotList[j].ScenicSpot_YUDING ;
         ScenicSpotList[j+1]=ScenicSpotList[j];         
         j--;
      } //j-1�������Ƚ� ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_YUDING=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];
   }     
        printf("�ڶ�����\n");
	    for(int n=0;n<i-1;n++)
       {       
          printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_YUDING );
       }
       
       for(int n=0;n<i;n++)
      { 
	    for(int j=0;j<i2;j++)
         if(strcmp(ScenicSpotList2[n].ScenicSpot_ID,info[j].order_NUMBER)==0&&info[j].order_MONTH>6&&info[j].order_MONTH<10)
           yu[2][n]=yu[2][n]+info[j].order_IDENTITY1+info[j].order_IDENTITY2+info[j].order_IDENTITY3;
	  } 
    //���ݾ���id���ֱ���������Ԥ���� 
    for(int n=0;n<i;n++)
     {
        
     	ScenicSpotList2[n].ScenicSpot_YUDING=yu[2][n];
	 }
	 // �����޸ĺ�Ԥ���� 
     fclose(fp);
     fclose(fp2);
     fp=fopen("������Ϣ.dat","wb");
     fwrite(&ScenicSpotList2,sizeof(struct  ScenicSpot),i,fp);
     fclose(fp);
     //���޸ĺ���Ϣ���롰������Ϣ��   
	 
     fp3=fopen("������Ϣ.dat","rb");//���ļ����������� 
       //n,j,k������������ ScenicSpotList2������������     	
	 for(int n=1;n<i;n++)
    {
      k=ScenicSpotList[n].ScenicSpot_YUDING ;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//���� ScenicSpotList[n]���� 
      j=n-1;//j����������ǰ���������ǰ���ݽ������� 
        while((j>=0)&&(ScenicSpotList[j].ScenicSpot_YUDING<k))
        // j��Ϊ����ScenicSpotList[n-1]>ScenicSpotList[n],�򽻻�
      {
         ScenicSpotList[j+1].ScenicSpot_YUDING =ScenicSpotList[j].ScenicSpot_YUDING ;
         ScenicSpotList[j+1]=ScenicSpotList[j];         
         j--;
      } //j-1�������Ƚ� ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_YUDING=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];
   }
        printf("��������\n");
	    for(int n=0;n<i-1;n++)
       {       
          printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_YUDING );
       }
       
       for(int n=0;n<i;n++)
      { 
	    for(int j=0;j<i2;j++)
         if(strcmp(ScenicSpotList2[n].ScenicSpot_ID,info[j].order_NUMBER)==0&&info[j].order_MONTH>9&&info[j].order_MONTH<13)
           yu[3][n]=yu[3][n]+info[j].order_IDENTITY1+info[j].order_IDENTITY2+info[j].order_IDENTITY3;
	  } 
    //���ݾ���id���ֱ���������Ԥ���� 
    for(int n=0;n<i;n++)
     {
        
     	ScenicSpotList2[n].ScenicSpot_YUDING=yu[3][n];
	 }
	 // �����޸ĺ�Ԥ���� 
     fclose(fp);
     fclose(fp2);
     fp=fopen("������Ϣ.dat","wb");
     fwrite(&ScenicSpotList2,sizeof(struct  ScenicSpot),i,fp);
     fclose(fp);
     //���޸ĺ���Ϣ���롰������Ϣ��   
	
     fp3=fopen("������Ϣ.dat","rb");//���ļ����������� 
       	//n,j,k������������ ScenicSpotList2������������     	
	 for(int n=1;n<i;n++)
    {
      k=ScenicSpotList[n].ScenicSpot_YUDING ;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//���� ScenicSpotList[n]���� 
      j=n-1;//j����������ǰ���������ǰ���ݽ������� 
        while((j>=0)&&(ScenicSpotList[j].ScenicSpot_YUDING<k))
        // j��Ϊ����ScenicSpotList[n-1]>ScenicSpotList[n],�򽻻�
      {
         ScenicSpotList[j+1].ScenicSpot_YUDING =ScenicSpotList[j].ScenicSpot_YUDING ;
         ScenicSpotList[j+1]=ScenicSpotList[j];         
         j--;
      } //j-1�������Ƚ� ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_YUDING=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];
   }
        printf("���ļ���\n");
	    for(int n=0;n<i-1;n++)
       {       
          printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_YUDING);
       }
       fclose(fp);//�ر��ļ�
         		printf("\n\n\t**************Tourist Menu*****************\n");
		printf("\t*              1.���ع��ܽ���             *\n");
		printf("\t*              2.�˳�                     *\n");
		printf("\t*******************************************\n");
	    	int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				guanliyuancaidan();
				panduan1=0;
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
 }  
 
 //�����ʼ��Ϣ 
 void chushihuaxinxi()
{
	//д���ο���Ϣ 
	FILE *fp1;
	fp1=fopen("�ο���Ϣ.txt","wb");
	int num1=0; 
	//1��ID 
	strcpy(touristList[num1].tourist_ID,"youke001");//�ο�ID 
	strcpy(touristList[num1].tourist_PASSWORD,"youke001");//���� 
	strcpy(touristList[num1].tourist_NUM,"30");//���� 
	strcpy(touristList[num1].tourist_AGE,"25������");//������ 
	strcpy(touristList[num1].tourist_PHONE,"11111111111");//��ϵ�绰 
	num1++;
	//2��ID 
	strcpy(touristList[num1].tourist_ID,"youke002");//�ο�ID
	strcpy(touristList[num1].tourist_PASSWORD,"youke002");//����
	strcpy(touristList[num1].tourist_NUM,"40");//����
	strcpy(touristList[num1].tourist_AGE,"45������");//������
	strcpy(touristList[num1].tourist_PHONE,"11111111112");//��ϵ�绰 
	num1++;
	//3��ID 
	strcpy(touristList[num1].tourist_ID,"youke003");//�ο�ID
	strcpy(touristList[num1].tourist_PASSWORD,"youke003");//����
	strcpy(touristList[num1].tourist_NUM,"35");//����
	strcpy(touristList[num1].tourist_AGE,"40������");//������
	strcpy(touristList[num1].tourist_PHONE,"11111111113");//��ϵ�绰 
	num1++;
	//4��ID 
	strcpy(touristList[num1].tourist_ID,"youke004");//�ο�ID
	strcpy(touristList[num1].tourist_PASSWORD,"youke004");//����
	strcpy(touristList[num1].tourist_NUM,"29");//����
	strcpy(touristList[num1].tourist_AGE,"30������");//������
	strcpy(touristList[num1].tourist_PHONE,"11111111114");//��ϵ�绰 
	num1++;
	//5��ID 
	strcpy(touristList[num1].tourist_ID,"youke005");//�ο�ID
	strcpy(touristList[num1].tourist_PASSWORD,"youke005");//����
	strcpy(touristList[num1].tourist_NUM,"37");//����
	strcpy(touristList[num1].tourist_AGE,"35������");//������
	strcpy(touristList[num1].tourist_PHONE,"11111111115");//��ϵ�绰 
	num1++;
	fwrite(&touristList,sizeof(tourist),num1,fp1);
	fclose(fp1);


	//д�����Ա��Ϣ 
	FILE *fp2;
	fp2=fopen("����Ա��Ϣ.txt","wb");
	int num2=0;
	//1�Ź���Ա
	strcpy(administratorList[num2].administrator_ID,"guanli01");//ID
	strcpy(administratorList[num2].administrator_PASSWORD,"guanli01");//���� 
	strcpy(administratorList[num2].administrator_PHONE,"11111110001");//�绰 
	strcpy(administratorList[num2].administrator_MAIL,"01@guanli.com");//����
	num2++; 
	//2�Ź���Ա
	strcpy(administratorList[num2].administrator_ID,"guanli02");//ID
	strcpy(administratorList[num2].administrator_PASSWORD,"guanli02");//���� 
	strcpy(administratorList[num2].administrator_PHONE,"11111110002");//�绰 
	strcpy(administratorList[num2].administrator_MAIL,"02@guanli.com");//����
	num2++; 
	//3�Ź���Ա
	strcpy(administratorList[num2].administrator_ID,"guanli03");//ID
	strcpy(administratorList[num2].administrator_PASSWORD,"guanli03");//���� 
	strcpy(administratorList[num2].administrator_PHONE,"11111110003");//�绰 
	strcpy(administratorList[num2].administrator_MAIL,"03@guanli.com");//����
	num2++; 
	fwrite(&administratorList,sizeof(administrator),num2,fp2);
	fclose(fp2);

	//д�뾰����Ϣ
	FILE *fp3;
	fp3=fopen("������Ϣ.txt","wb");
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
	num3++;
	fwrite(&ScenicSpotList,sizeof(ScenicSpot),num3,fp3);
	fclose(fp3);
}
