#include<stdio.h>
#include<process.h>
#include<string.h>
char administrator_ID2[20]={"\0"},administrator_PASSWORD2[20]={"\0"};
void guanliyuancaidan(); 
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
struct order
{
	char order_ID[20];//�������
	int order_YEAR;//������� 
	int order_MONTH;//�����·� 
	int order_DAY;//������ 
	int order_HOUR;//����Сʱ 
	int order_MINNTE;//�������� 
	char order_NUMBER[20];//������
	char order_TIME[20];//����ʱ��
	char order_AGE[20];//�����
	char order_PEOPLENUM[20];//����
	char order_IDENTITY1[20];//ѧ�����
	char order_IDENTITY2[20];//�������
	char order_IDENTITY3[20];//��ͨ���
	float order_PRICE[20];//�����ܼ۸�
}orderList[80];
int main()
{
	FILE *administrator_ID1,*administrator_PASSWORD1;
	administrator_ID1=fopen("����Ա��Ϣ.txt","r");
	administrator_PASSWORD1=fopen("����Ա��Ϣ.txt","r");
	int cal1=1,cal2,cal3=1,cal4;
	
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
	guanliyuancaidan();
}
void guanliyuancaidan()
{
	int choose,panduan=1;
   	printf("��ӭ�������Աϵͳ��\n");
	printf("1.������ѯ��\n2.����ͳ�ơ�\n3.�������\n4.������Ϣ����\n5.�˳�����\n");
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
			case 5:
				panduan=0;
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose);
				break;
		}
	}
}
void dingdanchaxun()
{
FILE  *fp;
        int  i,t,m=1,n=1;
        fp=fopen("������Ϣ.txt","rb");
        char dingdanchaxun1[80]={"\0"};
	    printf("������Ҫ��ѯ�Ķ�����ţ�\n");
		scanf("%s",dingdanchaxun1);
      for(i=0;fread(&orderList[i],sizeof(struct  order),1,fp)==1;i++)
        t=i;
		
		while(m!=0) 
	{
		for(i=0;i<t;i++)
		{
		if(strcmp(dingdanchaxun1,orderList[i].order_ID)==0)//���ļ���������Ķ�����ţ������if���� 
			{
			printf("�������: "); 
		    puts(orderList[i].order_ID);
	        printf("�������: ");
	        printf("%d\n",orderList[i].order_YEAR);
		    printf("�����·�: ");
	        printf("%d\n",orderList[i].order_MONTH);
	        printf("������: ");
	        printf("%d\n",orderList[i].order_DAY);
	        printf("����Сʱ: ");
	        printf("%d\n",orderList[i].order_HOUR);
	        printf("��������: ");
	        printf("%d\n",orderList[i].order_MINNTE);
	        printf("������: ");
	        puts(orderList[i].order_NUMBER);
	        printf("����ʱ��: ");
	        puts(orderList[i].order_TIME);
	        printf("�����: ");
	      	puts(orderList[i].order_AGE);
	        printf("����: ");
	        puts(orderList[i].order_PEOPLENUM);
	        printf("ѧ�����: ");
	        puts(orderList[i].order_IDENTITY1);
	        printf("�������: ");
	        puts(orderList[i].order_IDENTITY2);
	        printf("��ͨ���:");
	        puts(orderList[i].order_IDENTITY3);
			printf("�����ܼ۸�:");
	        printf("%f",orderList[i].order_PRICE);	
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
		void guanliyuancaidan();
}
void dingdantongji()
{
}
void jingdianguanli()
{
	int choose,panduan=1; 
	printf("1.������Ϣ��ѯ��\n2.��Ӿ�����Ϣ��\n3.�����ϼ��˵���\n");
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
			printf("\n");	
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
		jingdianguanli();
}
void  tianjiajingdianxinxi()
{
FILE  *fp;
        fp=fopen("������Ϣ.txt","ab+"); 
		int i,a=1,cal1=1,cal2,cal3=1;      
        for(int i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)==1;i++);
        i=i+1;
        for(a==1;a==1;i++){
        printf("�����뾰��ID\n"); 
        scanf("%s",ScenicSpotList[i].ScenicSpot_ID);
        printf("�����뾰������\n");
        scanf("%s",ScenicSpotList[i].ScenicSpot_NAME);
        printf("�����뾰����\n");
        scanf("%s",ScenicSpotList[i].ScenicSpot_INTRO);
        printf("�����뾰��������Ʊ�۸�\n");
        scanf("%d",&ScenicSpotList[i].ScenicSpot_PRICE1);
        printf("�����뾰�㵭����Ʊ�۸�\n");
        scanf("%d",&ScenicSpotList[i].ScenicSpot_PRICE2);
        printf("�����������þ�������ʱ��\n");
        scanf("%s",ScenicSpotList[i].ScenicSpot_TIME);
        printf("������ѧ���ۿ���Ϣ\n");
        scanf("%f",&ScenicSpotList[i].ScenicSpot_DISCOUNT1);
        printf("����������ۿ���Ϣ\n");
        scanf("%f",&ScenicSpotList[i].ScenicSpot_DISCOUNT2);
        printf("��������ͨ�ۿ���Ϣ\n");
        scanf("%f",&ScenicSpotList[i].ScenicSpot_DISCOUNT3);
        printf("�����뾰�㼶��\n");
        scanf("%s",ScenicSpotList[i].ScenicSpot_GRADE);
        printf("��������������\n");
        scanf("%s",ScenicSpotList[i].ScenicSpot_NUMBER);
        printf("�����뾰����������\n");
        scanf("%s",ScenicSpotList[i].ScenicSpot_AREA);
        printf("�����뾰��ά������\n");
        scanf("%s",ScenicSpotList[i].ScenicSpot_COST);
        printf("��������Ʊ��Ʊ��\n");
        scanf("%d",&ScenicSpotList[i].ScenicSpot_MENPIAO);
		fwrite(&ScenicSpotList[i],sizeof(ScenicSpot),1,fp);
        printf("�Ƿ������ӣ�\n1.��\n2.��\n");
        scanf("%d",&a);}
                fclose(fp);
        jingdianguanli();
        
        // int e;
        //printf("��ȷ�Ͼ�����Ϣ�Ƿ�����\n1.�޸�\n2.ȡ�����\n3.����\n");
        //scanf("%d",&e);
        //if(e==1){}
        //if(e==2){}
        //if(e==3)		
        }
void gerenxinxiguanli()
{
	int choose,panduan=1; 
	printf("1.������Ϣ��ѯ��\n2.�޸ĸ�����Ϣ��\n3.�����ϼ��˵���\n");
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
        guanliyuancaidan();
}	
void xiugaigerenxinxi()
{	
FILE  *fp;
	fp=fopen("����Ա��Ϣ.txt","rb"); 
    int  i,n;
    int  flag=0;
	char a[20],b[20];        
    for(i=0;fread(&administratorList[i],sizeof(struct  administrator),1,fp)==1;i++)
    if(strcmp(administratorList[i].administrator_ID,administrator_ID2)==0)
	{
        n=i;
        flag=1;          
	}
	fclose(fp); 
    if(flag==0)
	{
        printf("�������!\n");
        printf("�뷵��!\n");
        return;
    }   
	printf("\n\n\n");  
	fp=fopen("����Ա��Ϣ.txt","rb+");
	//strcpy(a->administrator_ID,administratorList[n].administrator_ID);
	//strcpy(a->administrator_PHONE,administratorList[n].administrator_PHONE);
	//administratorList[n].administrator_PASSWORD=NULL;
	//administratorList[n].administrator_MAIL=NULL;
    fseek(fp,n*sizeof(struct  administrator),0);
    printf("�������µ����뼰����\n"); 
	scanf("%s%s",&a,&b);
	strncpy(administratorList[n].administrator_PASSWORD,a,20);
	strncpy(administratorList[n].administrator_MAIL,b,20);
	for(i=0;i<80;i++)
	{
		fwrite(&administratorList[i],sizeof(administrator),1,fp);
	}
    fclose(fp); 
    guanliyuancaidan();
}
