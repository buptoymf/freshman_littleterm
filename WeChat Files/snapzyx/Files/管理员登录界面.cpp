#include<stdio.h>
#include<process.h>
#include<string.h>
char administrator_ID2[20]={"\0"},administrator_PASSWORD2[20]={"\0"};
void dingdanchaxun();
void dingdantongji();
void jingdianguanli();
	void  jingdianxinxichaxun();
	void  tianjiajingdianxinxi();
void gerenxinxiguanli();
    void  gerenxinxichaxun();
    void  xiugaigerenxinxi();
struct administrator
{
	char administrator_ID[20];//ϵͳ����ԱID 
	char administrator_PASSWORD[20];//ϵͳ����Ա���� 
	char administrator_PHONE[20];//ϵͳ����Ա�绰 
	char administrator_MAIL[20];//ϵͳ����Ա���� 
}administratorList[80];
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
	FILE *administrator_ID1,*administrator_PASSWORD1;
	administrator_ID1=fopen("����Ա��Ϣ.txt","r");
	administrator_PASSWORD1=fopen("����Ա��Ϣ.txt","r");
	int cal1=1,cal2,cal3=1,cal4,choose,panduan=1;
	
	printf("���������ԱID��\n");
	scanf("%s",administrator_ID2);
	fread(administratorList,sizeof(struct administrator),3,administrator_ID1);
	//��֤�û����û��������Ƿ���ȷ 
	while(cal3!=0)
	{
	for(cal2=0;cal2<3;cal2++)
		{
			if(strcmp(administrator_ID2,administratorList[cal2].administrator_ID)==0)
			{
				cal1=0;
				cal3=0;
				cal4=cal2;
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
			if(strcmp(administrator_PASSWORD2,administratorList[cal4].administrator_PASSWORD)==0)
			{
				cal1=0;
				cal3=0;
			}
		}
		   if(cal1!=0)
		  {
		  	printf("�������벻��ȷ�����������룺\n"); 
		  	scanf("%s",administrator_PASSWORD2);
		  	cal2=0;
			}
	} 
	fclose(administrator_ID1);
	fclose(administrator_PASSWORD1);
	printf("��ӭ�������Աϵͳ��\n");
	printf("1.������ѯ��\n2.����ͳ�ơ�\n3.�������\n4.������Ϣ����\n");
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
			    gerenxinxiguanli();
				panduan=0;
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
}
void dingdanchaxun(){
}
void dingdantongji(){
}
void jingdianguanli(){
	int choose,panduan=1; 
	printf("1.������Ϣ��ѯ��\n2.��Ӿ�����Ϣ��\n");
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
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
}
void  jingdianxinxichaxun()
{
	FILE  *fp;
        int  i,t,m=1,n=1;
        fp=fopen("������Ϣ.txt","rb");
        char jingdianchaxun1[80]={"\0"};
	    printf("������Ҫ��ѯ�ľ������ƣ�\n");
		scanf("%s",jingdianchaxun1);
      for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)==1;i++)
        t=i;
		
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
	        puts(ScenicSpotList[i].ScenicSpot_COST);	
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
}
void  tianjiajingdianxinxi()
{
        }
void gerenxinxiguanli(){
	int choose,panduan=1; 
	printf("1.������Ϣ��ѯ��\n2.�޸ĸ�����Ϣ��\n");
	scanf("%d",&choose);
	while(panduan!=0)
	{
		switch(choose)
		{
			case 1:
				gerenxinxichaxun();
				panduan=0; 
				break;
			case 2:
				xiugaigerenxinxi(); 
				panduan=0; 
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
}
void  gerenxinxichaxun()
{
		FILE  *fp;
        
        fp=fopen("����Ա��Ϣ.txt","rb");        
       
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
}	
void xiugaigerenxinxi()
{	FILE  *fp;
	fp=fopen("����Ա��Ϣ.txt","rb"); 
        int  i,n;
        int  flag=0;        
          for(i=0;fread(&administratorList[i],sizeof(struct  administrator),1,fp)==1;i++)
        if(strcmp(administratorList[i].administrator_ID,administrator_ID2)==0)
	{
                n=i;
                flag=1;
              
	}fclose(fp); 
        if(flag==0)
	{
                printf("�������!\n");
                printf("�뷵��!\n");
                return;
        }
		printf("\n\n\n");  
		fp=fopen("����Ա��Ϣ.txt","rb+");
        fseek(fp,n*sizeof(struct  administrator),SEEK_SET);
        printf("�������µ����뼰����\n"); 
		scanf("%s%s",&administratorList[i].administrator_PASSWORD,&administratorList[i].administrator_MAIL); 
		fwrite(&administratorList[i],sizeof(struct  administrator),1,fp);
		printf("%s",administratorList[2].administrator_ID);
        fclose(fp); 
}
