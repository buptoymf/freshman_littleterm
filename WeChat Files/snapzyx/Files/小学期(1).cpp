#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define NUMBER 80

//������ 
void mainmenu()
{
	printf("\n\n\t**************Main Menu**************\n");
	printf("\t*            1.�ο͵�½             *\n");
	printf("\t*            2.����Ա��½           *\n");
	printf("\t*            3.�ر�ϵͳ             *\n");
	printf("\t*************************************\n");
}

//�ο͵�½����
void touristmenu()
{
	
	
} 

//����Ա��½����
void adminmenu()
{
	
	
} 

//�ο�����

struct tourist
{
	char tourist_ID[20];//�ο�����ID
	char tourist_PASSWORD[20];//�ο��������� 
	char tourist_NUM[20];//�ο��������� 
	char tourist_AGE[20];//�ο����������� 
	char tourist_PHONE[20];//�ο�������ϵ�˵绰 
}touristList[NUMBER];

//ϵͳ����Ա

struct administrator
{
	char administrator_ID[20];//ϵͳ����ԱID 
	char administrator_PASSWORD[20];//ϵͳ����Ա���� 
	char administrator_PHONE[20];//ϵͳ����Ա�绰 
	char administrator_MAIL[20];//ϵͳ����Ա���� 
}administratorList[NUMBER];

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
	char ScenicSpot_COST[80];//����ά������
}ScenicSpotList[NUMBER];

//Ԥ����Ϣ

struct order
{
	char order_ID[20];//�������
	char order_DAY[20];//Ԥ������
	char order_NUMBER[20];//������
	char order_TIME[20];//����ʱ��
	char order_AGE[20];//�����
	char order_PEOPLENUM[20];//����
	char order_IDENTITY[20];//���
	float order_PRICE[20];//�����ܼ۸�
}orderList[NUMBER];

//---------��ʼ��ֵ����---------- 

//��ʼ���ο�
void touristsystem()
{
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
}
	
//��ʼ������Ա
void adminsystem()
{
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
}

//��ʼ��������Ϣ
void spotsystem()
{
	int num3=0;
	//1�ž���
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0001");//����ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"���ﳤ��");//�������� 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"�й�ΰ��ľ��½���");//������
	ScenicSpotList[num3].ScenicSpot_PRICE1=200;//����������Ʊ�۸�
	ScenicSpotList[num3].ScenicSpot_PRICE2=140;//���㵭����Ʊ�۸� 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE,"200");//����������Ʊ�۸� 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE2,"140");//���㵭����Ʊ�۸� 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"4Сʱ");//��������ʱ��
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.8;//ѧ���ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.7;//�����ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//��ͨ�ۿ���Ϣ
	//strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT1,"0.8");//ѧ���ۿ���Ϣ 
	//strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT2,"0.7");//�����ۿ���Ϣ 
	//strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT3,"0.9");//��ͨ�ۿ���Ϣ
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5��");//���㼶�� 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"��");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"����");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"10��");//����ά������ 
	num3++; 
	//2�ž���
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0002");//����ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"����ɽˮ");//�������� 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"����ɽˮ������");//������ 
	ScenicSpotList[num3].ScenicSpot_PRICE1=350;//����������Ʊ�۸�
	ScenicSpotList[num3].ScenicSpot_PRICE2=300;//���㵭����Ʊ�۸� 
//	strcpy(ScenicSpotList[num3].ScenicSpot_PRICE1,"350");//����������Ʊ�۸� 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE2,"300");//���㵭����Ʊ�۸� 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"2.5Сʱ");//��������ʱ��
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=1.0;//ѧ���ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=1.0;//�����ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=1.0;//��ͨ�ۿ���Ϣ 
	//strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT1,"1.0");//ѧ���ۿ���Ϣ 
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT2,"1.0");//�����ۿ���Ϣ
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT3,"1.0");//��ͨ�ۿ���Ϣ 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5��");//���㼶�� 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"��");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"����");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"7.8��");//����ά������
	num3++;
	//3�ž���
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0003");//����ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"�ʹ�");//�������� 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"���������Ļʹ�");//������
	ScenicSpotList[num3].ScenicSpot_PRICE1=100;//����������Ʊ�۸�
	ScenicSpotList[num3].ScenicSpot_PRICE2=50;//���㵭����Ʊ�۸�
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE1,"100");//����������Ʊ�۸� 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE2,"50");//���㵭����Ʊ�۸� 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"3.5Сʱ");//��������ʱ��
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.8;//ѧ���ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.75;//�����ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//��ͨ�ۿ���Ϣ 
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT1,"0.8");//ѧ���ۿ���Ϣ 
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT2,"0.75");//�����ۿ���Ϣ
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT3,"0.9");//��ͨ�ۿ���Ϣ
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5��");//���㼶�� 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"10��");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"����");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"4��");//����ά������
	num3++;
	//4�ž���
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0004");//����ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"��������");//�������� 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"��ʷ�ƾá����������ķ羰����ʤ��");//������ 
	ScenicSpotList[num3].ScenicSpot_PRICE1=230;//����������Ʊ�۸�
	ScenicSpotList[num3].ScenicSpot_PRICE2=170;//���㵭����Ʊ�۸� 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE1,"230");//����������Ʊ�۸� 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE2,"170");//���㵭����Ʊ�۸� 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"3Сʱ");//��������ʱ��
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.7;//ѧ���ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.5;//�����ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//��ͨ�ۿ���Ϣ 
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT1,"0.7");//ѧ���ۿ���Ϣ
   // strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT2,"0.5");//�����ۿ���Ϣ
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT3,"0.9");//��ͨ�ۿ���Ϣ 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5��");//���㼶�� 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"2��");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"����");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"5.1��");//����ά������
	num3++;
	//5�ž���
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0005");//����ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"����԰��");//�������� 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"�ƾ���ʷ��˽��԰��");//������ 
	ScenicSpotList[num3].ScenicSpot_PRICE1=200;//����������Ʊ�۸�
	ScenicSpotList[num3].ScenicSpot_PRICE2=140;//���㵭����Ʊ�۸� 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE1,"200");//����������Ʊ�۸� 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE2,"140");//���㵭����Ʊ�۸� 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"2Сʱ");//��������ʱ��
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.75;//ѧ���ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.6;//�����ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//��ͨ�ۿ���Ϣ 
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT1,"0.75");//ѧ���ۿ���Ϣ
  //  strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT2,"0.6");//�����ۿ���Ϣ
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT3,"0.9");//��ͨ�ۿ���Ϣ 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4��");//���㼶�� 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"1.5��");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"����");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"6.3��");//����ά������
	num3++;
	//6�ž���
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0006");//����ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"���ջ�ɽ");//�������� 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"���µ�һ��ɽ");//������ 
	ScenicSpotList[num3].ScenicSpot_PRICE1=225;//����������Ʊ�۸�
	ScenicSpotList[num3].ScenicSpot_PRICE2=175;//���㵭����Ʊ�۸� 
//	strcpy(ScenicSpotList[num3].ScenicSpot_PRICE1,"225");//����������Ʊ�۸� 
//	strcpy(ScenicSpotList[num3].ScenicSpot_PRICE2,"175");//���㵭����Ʊ�۸� 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"3.5Сʱ");//��������ʱ��
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.8;//ѧ���ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.8;//�����ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//��ͨ�ۿ���Ϣ 
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT1,"0.8");//ѧ���ۿ���Ϣ
  //  strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT2,"0.80");//�����ۿ���Ϣ 
  //  strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT3,"0.9");//��ͨ�ۿ���Ϣ
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4��");//���㼶�� 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"3.1��");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"��ɽ��");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"1.5��");//����ά������
	num3++;
	//7�ž���
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0007");//����ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"������Ͽ");//�������� 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"��������Ϊ����׳����ɽˮ����");//������  
	ScenicSpotList[num3].ScenicSpot_PRICE1=240;//����������Ʊ�۸�
	ScenicSpotList[num3].ScenicSpot_PRICE2=200;//���㵭����Ʊ�۸�
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE1,"240");//����������Ʊ�۸� 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE2,"200");//���㵭����Ʊ�۸� 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"2.6Сʱ");//��������ʱ��
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.75;//ѧ���ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.75;//�����ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//��ͨ�ۿ���Ϣ
	/* 
	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT1,"0.75");//ѧ���ۿ���Ϣ
    strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT2,"0.75");//�����ۿ���Ϣ
	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT3,"0.9");//��ͨ�ۿ���Ϣ
	*/ 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4��");//���㼶�� 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"1.5��");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"����");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"2��");//����ά������
	num3++;
	//8�ž���
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0008");//����ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"����ٸ");//�������� 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"�س����漣");//������
	ScenicSpotList[num3].ScenicSpot_PRICE1=200;//����������Ʊ�۸�
	ScenicSpotList[num3].ScenicSpot_PRICE2=140;//���㵭����Ʊ�۸� 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE1,"260");//����������Ʊ�۸� 
//	strcpy(ScenicSpotList[num3].ScenicSpot_PRICE2,"210");//���㵭����Ʊ�۸� 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"1.5Сʱ");//��������ʱ��
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.65;//ѧ���ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.8;//�����ۿ���Ϣ
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//��ͨ�ۿ���Ϣ
	/* 
	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT1,"0.65");//ѧ���ۿ���Ϣ
    strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT2,"0.8");//�����ۿ���Ϣ
	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT3,"0.9");//��ͨ�ۿ���Ϣ
	*/ 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4��");//���㼶�� 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"1��");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"����");//������������ 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"5��");//����ά������
}

//Ԥ����Ϣ
void dingdansystem()
{
    int num4=0;
}
	
	


 
