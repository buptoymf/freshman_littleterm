#include<stdio.h>
#include<process.h>
#include<string.h>
#include <stdlib.h>

#define NUMBER 80
void mainmenu()
{
	printf("\n\n\t**************Main Menu**************\n");
	printf("\t*            1.�ο͵�½             *\n");
	printf("\t*            2.����Ա��½           *\n");
	printf("\t*            3.�ر�ϵͳ             *\n");
	printf("\t*************************************\n");
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
void yudingjingdianmenpiao();
void outputinfo();
void deleteinfo();
int countline()
{
    FILE *pf = fopen("dingdan.txt", "r");
    char buf[1000];
    int c=0;
    
    if (!pf)
    
    return 0;
        
    while (fgets(buf, 1000, pf))
    c++;
    
    fclose(pf);
    
    return c;
}
struct tourist
{
	char tourist_ID[20];//�ο�����ID
	char tourist_PASSWORD[20];//�ο��������� 
	char tourist_NUM[20];//�ο��������� 
	char tourist_AGE[20];//�ο����������� 
	char tourist_PHONE[20];//�ο�������ϵ�˵绰 
}touristList[NUMBER];
struct administrator
{
	char administrator_ID[20];//ϵͳ����ԱID 
	char administrator_PASSWORD[20];//ϵͳ����Ա���� 
	char administrator_PHONE[20];//ϵͳ����Ա�绰 
	char administrator_MAIL[20];//ϵͳ����Ա���� 
}administratorList[NUMBER];
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
}ScenicSpotList[NUMBER],ScenicSpotList2[NUMBER];
struct info_list
{
	
	char order_NUMBER[20];
	int order_IDENTITY1;
	int order_IDENTITY2;
	int order_IDENTITY3;
	char order_AGE[20];
	int number;
	int order_YEAR;
	int order_MONTH;
	int order_DAY;
	int order_HOUR;
	int order_MINUTE;
	char order_ID[20];
}info[NUMBER];

//������ 
int main()
{
	int choose,panduan=1;
	mainmenu();
	printf("��ѡ����Ҫִ�е�ѡ��:\n");
	scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				Youkedenglu();
				panduan=0;
				break;
			case 2:
				
				panduan=0;
				break;
			case 3:
				panduan=0;
				exit(0);
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
}
void Youkedenglu()
{
	FILE *tourist_ID1,*tourist_PASSWORD1,*tourist_login;
	tourist_ID1=fopen("�ο���Ϣ.txt","r");
	tourist_PASSWORD1=fopen("�ο���Ϣ.txt","r");
	tourist_login=fopen("�ο��û���.txt","w");
	int cal1=1,cal2,cal3=1,cal4,cal5=0;
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
		  	cal5++;
			}
			if(cal5 == 2)
			{
				printf("������������������3�Σ��뷵�����������µ�½\n");
				mainmenu();
			}
	} 
	fclose(tourist_ID1);
	fclose(tourist_PASSWORD1);
	fclose(tourist_login);
	jinruyoukegongneng();
}
void Jingdianchaxun()
{
	int choose,panduan=1;
	printf("1.���ݾ������Ʋ�ѯ��\n2.�����Ƿ���Ʊ��ѯ��\n3.���ݾ��������ѯ��\n4.�����Ƿ����ۿ۲�ѯ��\n5.���ݼ۸��������о��㡣\n6.�����붨���������о��㡣\n");
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
		printf("�������Ƿ���Ҫ��Ʊ��\n1.��Ҫ\n2.���ع��ܽ���\n");
		int choose,panduan=1;
		scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				
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
			printf("�������Ƿ���Ҫ��Ʊ��\n1.��Ҫ\n2.���ع��ܽ���\n");
		int choose,panduan=1;
		scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				
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
void Shifouzhekou()
{
			int cal1,cal3,cal5,cal7=1,choose;
	FILE *Jingdian4;
	Jingdian4=fopen("������Ϣ.txt","r");
	fread(ScenicSpotList,sizeof(struct ScenicSpot),8,Jingdian4);//����ʱ��Ϊ�˸��� 
	printf("������Ҫ��ѯ�����ۿ���Ϣ��\n1.ѧ��\n2.����\n3.��ͨ��\n ");
		scanf("%d",&choose);
	while(cal7!=0) 
	{
		switch(choose)
		{
			case 1:
				for(cal1=0;cal1<8;cal1++)//����ʱ��Ϊ�˸��� 
			{
			//	fscanf(Jingdian4,"%.1f",&ScenicSpotList[cal1].ScenicSpot_DISCOUNT1);
				if(ScenicSpotList[cal1].ScenicSpot_DISCOUNT1 < 1)
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
	        puts(ScenicSpotList[cal1].ScenicSpot_COST);	
	        printf("\n");
			}
			}
			cal7=0;
			break;
			case 2:
				for(cal3=0;cal3<8;cal3++)//����ʱ��Ϊ�˸��� 
			{
			//	fscanf(Jingdian4,"%.1f",&ScenicSpotList[cal3].ScenicSpot_DISCOUNT2);
			if(ScenicSpotList[cal3].ScenicSpot_DISCOUNT2 < 1)
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
	        puts(ScenicSpotList[cal3].ScenicSpot_COST);	
	        printf("\n");
			}
			}
			cal7=0;
			break;
			case 3:
					for(cal5=0;cal5<8;cal5++)//����ʱ��Ϊ�˸��� 
			{
			//	fscanf(Jingdian4,"%.1f",&ScenicSpotList[cal5].ScenicSpot_DISCOUNT3);
			if(ScenicSpotList[cal5].ScenicSpot_DISCOUNT3 < 1)
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
	        puts(ScenicSpotList[cal5].ScenicSpot_COST);	
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
					printf("�������Ƿ���Ҫ��Ʊ��\n1.��Ҫ\n2.���ع��ܽ���\n");
		int choose1,panduan=1;
		scanf("%d",&choose1);
	while(panduan!=0)
	{
		switch(choose1)
		{
			case 1:
				
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
				printf("�������Ƿ���Ҫ��Ʊ��\n1.��Ҫ\n2.���ع��ܽ���\n");
		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				
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
void yudingliangpaixu()
{
}
void jinruyoukegongneng()
{
	int choose,panduan=1;
		printf("��ӭ����ϵͳ����ѡ����Ҫִ�еĹ��ܣ� \n");
	printf("\n\n\t**************Main Menu**************\n");
	printf("\t*            1.�����ѯ                 *\n");
	printf("\t*            2.Ԥ��������Ʊ             *\n");
	printf("\t*            3.��Ϣ����                 *\n");
	printf("\t*            4.ȡ��Ԥ��                 *\n");
	printf("\t*            5.��ѯԤ����Ʊ             *\n");
	printf("\t*            6.�˳�                     *\n");
	printf("\t*************************************\n");
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
void yudingjingdianmenpiao()
{
	
	
	FILE *jingdian;
	
	jingdian=fopen("������Ϣ.txt","rb");
	
	int num3;
	
	for(num3=0;fread(&ScenicSpotList[num3],sizeof(struct  ScenicSpot),1,jingdian)!=0;num3++);
	
FILE *fp;

	int i,n,x,y;//ѭ���ṹ�ļ���ֵ 
	
	int a,b,c,d,e,f,g,h,j,k;//�жϸ�����Ϣ�����Ƿ���ȷ�ı��ֵ 
	
	char tmp[20];
	
	int total_tourists=100;
	
	 
	fp=fopen("dingdan.txt","a");
	printf("��Ҫ�����ٸ������Ʊ��\n");
	scanf("%d",&n);
	if(n<=0 || n>10)
	{
		printf("����������������������ֵ����!\n"); 
	}
	else 
	{
	printf("��ֱ�����ÿ�������ID���ο����,�ο�������,��Ʊ����������ʱ��(��/��/��/ʱ��)��ÿ��������һ��س�����\n");
	
		fp=fopen("dingdan.txt","a");
		
	
		
	for(i=0;i<n;i++)
	{
		printf("�������%d������������Ϣ��\n",i+1);
		
		
		
		
		 
		printf("����ID��");
	
		
		x=num3-1;
		a=-1;
		
		while(a==-1)
		{

		scanf("%s",info[i].order_NUMBER);
		
		for(y=0;y<=x;y++)
		{ 
		if(strcmp(info[i].order_NUMBER,ScenicSpotList[y].ScenicSpot_ID)==0)
		{
	
		a=y;
		
		}
		
		
		
		} 
		
		if(a==-1) 
		{
	
		printf("����ID����������������룡\n");
		
		}
	
		} 
		
		
		
		fputs(info[i].order_NUMBER,fp);
		fputs("\n",fp);
		
		
		printf("�ο���ݣ�ѧ����������");
		
		
		b=-1;
		while(b==-1)
		{
		scanf("%d",&info[i].order_IDENTITY1);
		if(info[i].order_IDENTITY1<=total_tourists && info[i].order_IDENTITY1>=0)
		{
		
		b=0;
		
		}
		
		if(b==-1)
		{
		printf("����������������룡\n");
		}
		
		}
		
		fprintf(fp,"%d",info[i].order_IDENTITY1);
		fputs("\n",fp);
		
		
		
		
		printf("�ο���ݣ�������������");
		
		
		c=-1;
		while(c==-1)
		{
		scanf("%d",&info[i].order_IDENTITY2);
		if(info[i].order_IDENTITY2<=total_tourists && info[i].order_IDENTITY2>=0)
		{
		
		c=0;
		
		}
		
		if(c==-1)
		{
		printf("����������������룡\n");
		}
		
		}
		
		fprintf(fp,"%d",info[i].order_IDENTITY2);
		fputs("\n",fp);
		
		
		
		printf("�ο���ݣ���ͨ����������");
		
		
		d=-1;
		while(d==-1)
		{
		scanf("%d",&info[i].order_IDENTITY3);
		if(info[i].order_IDENTITY3<=total_tourists && info[i].order_IDENTITY3>=0)
		{
		
		d=0;
		
		}
		
		if(d==-1)
		{
		printf("����������������룡\n");
		}
		
		}
		
		fprintf(fp,"%d",info[i].order_IDENTITY3);
		fputs("\n",fp);
		
		
		
		printf("�ο������Σ�");
		scanf("%s",info[i].order_AGE);
		fputs(info[i].order_AGE,fp);
		fputs("\n",fp);
		
		printf("��Ʊ������(ʣ��Ʊ����%d)",ScenicSpotList[a].ScenicSpot_MENPIAO);
		
		
		
		e=-1;
		
		while(e==-1)
		{

		scanf("%d",&info[i].number);
		
		
		
		
		if(ScenicSpotList[a].ScenicSpot_MENPIAO>=info[i].number)
		{
		
		e=0;
		
		}
		
		if(e==-1)
		{
		printf("��Ʊ����������ʣƱ������Ʊʧ�ܣ����������룡\n");
		}
		
		
		
		}
		
		
		ScenicSpotList[a].ScenicSpot_MENPIAO-=info[i].number;
		
		fprintf(fp,"%d",info[i].number);
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
		
		
		
		
		
		
		
		
		
		//���ݶ����������ɶ������ 

		sprintf(info[i].order_ID,"%d",info[i].order_YEAR);
		
		
		
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
		fputs("\n",fp);
	}
	
	fclose(fp);
	
	
	fwrite(&ScenicSpotList,1000,num3,jingdian);
	
	
	
	
	
	}
}
void outputinfo()
{
	
	FILE *fp;
	int i;
	char c;
	
	i=0;
	
	fp=fopen("dingdan.txt","r") ;
	
	printf("������Ϣ���£�������Ϊ�����ID,����ݣ�ѧ�������ˣ���ͨ�ˣ��ο��������ο�������,��Ʊ��������Ʊʱ�䣨�꣬�£��գ�ʱ���֣����������\n");
	c=fgetc(fp);
	
	
	while(c!=EOF)
	{
		
		i++;
		
		
		
		printf("%c",c);
		c=fgetc(fp);
		

	}
	
	if(i==0)
	{
		printf("�޶�����Ϣ��\n");
	}

	fclose(fp);
 }
 void deleteinfo()
{
	FILE *pf = fopen("dingdan.txt", "r");
	
	
    char buf[1000];
	char s[50];

    int i=0;
	int c=-1;
//	double riqi;
	
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
	
	while (fgets(buf,1000,pf) && c!=i)
	{
	

		
	i++;
	

		
	if(strcmp(buf,s)==0)
	{
		c=i;
		
	}
	
	
	}
	
	
//	time_t t;
//	struct tm*lt;
 //   time(&t);
 //   lt=localtime (&t);
	
//	riqi=lt->tm_sec+lt->tm_min*100+lt->tm_hour*10000+lt->tm_mday*1000000+(lt->tm_mon+1)*100000000+(lt->tm_year+1900)*10000000000;
	
	
//	printf("%.lf\n",riqi);
	
	
	if(c==-1 || (c+1)%13!=0) //�ж�s�Ƿ�Ϊ��������붩������Ƿ���ȷ 
	{
		printf("�˶��������ڣ�\n");
	}
    else  
    {
    
    fclose(pf);
    
    FILE *pf2 = fopen("dingdan.txt", "r");
    FILE *pt = fopen("tmp.txt", "w");
    	
	i=0;
	
	while (fgets(buf,1000,pf2))
	{
	i++;
	
    if(i<c-12 || i>c)
    {
    printf("%s",buf);
	fputs(buf,pt);
	
	}
    
	
	}
    fclose(pt);
    fclose(pf2);
    
    remove("dingdan.txt");
    rename("tmp.txt","dingdan.txt");
	
	
	printf("����ɾ���ɹ���\n");
	
	}
	
	}
	
	
	

	
    

    fclose(pf);
    
    
	
    
    
	
}
