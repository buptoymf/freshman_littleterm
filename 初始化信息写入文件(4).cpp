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
	int ScenicSpot_COST;//����ά������
	int ScenicSpot_MENPIAO;//������Ʊ 
	int ScenicSpot_VISIT;//����������� 
	int ScenicSpot_YUDING;//����Ԥ���� 
	float ScenicSpot_HAOPING;//��������� 
	char ScenicSpot_LRET[80];//�Ƿ��������˶�ͯ 
}ScenicSpotList[NUMBER];

//Ԥ����Ϣ

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

//---------����ʼ����Ϣд���ļ�---------
main()
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
	num3++;
	fwrite(&ScenicSpotList,sizeof(ScenicSpot),num3,fp3);
	fclose(fp3);
}	

