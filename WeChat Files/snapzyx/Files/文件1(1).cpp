#include<stdio.h>
#include<string.h>
struct tourist
{
	char tourist_ID[20];//�ο�����ID
	char tourist_PASSWORD[20];//�ο��������� 
	char tourist_NUM[20];//�ο��������� 
	char tourist_AGE[20];//�ο����������� 
	char tourist_PHONE[20];//�ο�������ϵ�˵绰 
}touristList[80];
main()
{
	FILE *fp;
	fp=fopen("�ο���Ϣ.txt","w");
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
	fwrite(&touristList,sizeof(tourist),5,fp);
	fclose(fp);
}
 
