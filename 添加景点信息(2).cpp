#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUMBER 80
//������Ϣ

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
}ScenicSpotList[NUMBER];


//��Ӿ�����Ϣ���޸ķ���
main() 
//void  addScenicSpot()
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
    struct  ScenicSpot a[80];
    fpa=fopen("������Ϣ.txt","a+");
	fpb=fopen("�����ϢԤ��.txt","a+");        
    for(i=0;i<ScenicSpotNum;i++)
    fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fpa);
    do
	{
        printf("�����뾰��ID\n");
		while(panduan3==0)
		{ 
    		gets(a[num1].ScenicSpot_ID);
    		panduan3=1;
    		for(c=0;c<ScenicSpotNum;c++)
    		if(strcmp(a[num1].ScenicSpot_ID,ScenicSpotList[c].ScenicSpot_ID)==0)
			{ 
    	    	printf("����ID�ظ�\n");
    	    	panduan3=0; 
    			printf("���������뾰������\n");
    		}
    	}
    	printf("�����뾰������\n");
    	while(panduan4==0)
		{ 
    		gets(a[num1].ScenicSpot_NAME);
    		panduan4=1;
    		for(c=0;c<ScenicSpotNum;c++)
    		if(strcmp(a[num1].ScenicSpot_NAME,ScenicSpotList[c].ScenicSpot_NAME)==0)
			{ 
    			printf("���������ظ�");
    			panduan4=0;
    			printf("���������뾰������\n");
			}	
    	}
    	printf("�����뾰����\n");
    	gets(a[num1].ScenicSpot_INTRO);
    	printf("�����뾰��������Ʊ�۸�\n");
    	scanf("%d",&a[num1].ScenicSpot_PRICE1);
    	printf("�����뾰�㵭����Ʊ�۸�\n");
    	scanf("%d",&a[num1].ScenicSpot_PRICE2);
    	getchar();
    	printf("�����������þ�������ʱ��\n");
    	gets(a[num1].ScenicSpot_TIME);
    	printf("������ѧ���ۿ���Ϣ\n");
    	scanf("%f",&a[num1].ScenicSpot_DISCOUNT1);
    	printf("����������ۿ���Ϣ\n");
    	scanf("%f",&a[num1].ScenicSpot_DISCOUNT2);
    	printf("��������ͨ�ۿ���Ϣ\n");
    	scanf("%f",&a[num1].ScenicSpot_DISCOUNT3);
    	getchar();
    	printf("�����뾰�㼶��\n");
    	gets(a[num1].ScenicSpot_GRADE);
    	printf("��������������\n");
    	gets(a[num1].ScenicSpot_NUMBER);
    	printf("�����뾰����������\n");
    	gets(a[num1].ScenicSpot_AREA);
    	printf("�����뾰��ά������\n");
    	scanf("%d",&a[num1].ScenicSpot_COST);
    	printf("�����뾰����Ʊ��\n");
    	scanf("%d",&a[num1].ScenicSpot_MENPIAO);
    	printf("�����뾰���Ƿ��������˶�ͯ\n");
    	getchar();
    	gets(a[num1].ScenicSpot_LRET); 
    	printf("��ȷ�Ͼ�����Ϣ�Ƿ�����\n1.�޸�\n2.ȡ�����\n3.����\n");
    	scanf("%d",&e);
    	if(e==1)
		{
			fwrite(&ScenicSpotList[ScenicSpotNum],sizeof(ScenicSpot),1,fpb);
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
			printf("15.�����Ƿ��������˶�ͯ\n");
			i++;
			scanf("%d",&xuan);
			do
			{
				while(panduan!=0)
				{
					switch(xuan)
					{
						case 1:
							strncpy(ScenicSpotList[i].ScenicSpot_ID,a[num1].ScenicSpot_ID,100);
							panduan=0;
							break;
						case 2:
							strncpy(ScenicSpotList[i].ScenicSpot_NAME,a[num1].ScenicSpot_NAME,100);
							panduan=0;
							break;
						case 3:
							strncpy(ScenicSpotList[i].ScenicSpot_INTRO,a[num1].ScenicSpot_INTRO,100);
							panduan=0;
							break;
						case 4:
							ScenicSpotList[i].ScenicSpot_PRICE1=a[num1].ScenicSpot_PRICE1;
							panduan=0;
							break;
						case 5: 
							ScenicSpotList[i].ScenicSpot_PRICE2=a[num1].ScenicSpot_PRICE2;
							panduan=0;
							break;
						case 6: 
							strncpy(ScenicSpotList[i].ScenicSpot_TIME,a[num1].ScenicSpot_TIME,100);
							panduan=0;
							break;
						case 7: 
							ScenicSpotList[i].ScenicSpot_DISCOUNT1=a[num1].ScenicSpot_DISCOUNT1;
							panduan=0;
							break;
						case 8:
							ScenicSpotList[i].ScenicSpot_DISCOUNT2=a[num1].ScenicSpot_DISCOUNT2;
							panduan=0;
							break; 
						case 9:
							ScenicSpotList[i].ScenicSpot_DISCOUNT3=a[num1].ScenicSpot_DISCOUNT3;
							panduan=0;
							break; 
						case 10: 
							strncpy(ScenicSpotList[i].ScenicSpot_GRADE,a[num1].ScenicSpot_GRADE,100);
							panduan=0;
							break;
						case 11: 
							strncpy(ScenicSpotList[i].ScenicSpot_NUMBER,a[num1].ScenicSpot_NUMBER,100);
							panduan=0;
							break;
						case 12:
							strncpy(ScenicSpotList[i].ScenicSpot_AREA,a[num1].ScenicSpot_AREA,100);
							panduan=0;
							break;
						case 13:
							ScenicSpotList[i].ScenicSpot_COST=a[num1].ScenicSpot_COST;
							panduan=0;
							break;
						case 14:
							ScenicSpotList[i].ScenicSpot_MENPIAO=a[num1].ScenicSpot_MENPIAO;
							panduan=0;
							break;
						case 15:
							strncpy(ScenicSpotList[i].ScenicSpot_LRET,a[num1].ScenicSpot_LRET,100);
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
					printf("�Ƿ�����޸�\n1.��\t2.��");
					scanf("%d",&panduan2); 
				}
			}
			while(panduan2==1);	
			printf("��ȷ���Ƿ񷢲�\n1.�� 2.��");
			scanf("%d",&queding);
			if(queding==1)
			{
				fseek(fpa,0L,2);
				fwrite(&ScenicSpotList[i],sizeof(ScenicSpot),1,fpa);
			}
			else
			{
				fwrite(&ScenicSpotList[i],sizeof(ScenicSpot),1,fpb);
				remove("�����ϢԤ��.txt");
			}
		}
    	if(e==2)
		{
			fwrite(&ScenicSpotList[i],sizeof(ScenicSpot),1,fpb);
			remove("�����ϢԤ��.txt");
		}
    	if(e==3)
		{
			fseek(fpa,0L,2);
			fwrite(&a[num1],sizeof(ScenicSpot),1,fpa);
    	}
    	num1++;
    	ScenicSpotNum++;
		printf("�Ƿ��������µľ�����Ϣ\n1.��\t2.��");
		scanf("%d",&tianjia); 
	}
	while(tianjia==1);
	fclose(fpa);
	fclose(fpb);	    
}
