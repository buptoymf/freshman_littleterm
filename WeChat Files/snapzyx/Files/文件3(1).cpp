#include<stdio.h>
#include<string.h>
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
	int ScenicSpot_MENPIAO;//������Ʊ 
}ScenicSpotList[80];
main()
{
	FILE *fp;
	fp=fopen("������Ϣ.txt","w");
//��ʼ��������Ϣ
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
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"10��");//����ά������
	ScenicSpotList[num3].ScenicSpot_MENPIAO=70; //������Ʊ��
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
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"7.8��");//����ά������
	ScenicSpotList[num3].ScenicSpot_MENPIAO=110;//������Ʊ��
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
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"4��");//����ά������
	ScenicSpotList[num3].ScenicSpot_MENPIAO=100;//������Ʊ��
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
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"5.1��");//����ά������
	ScenicSpotList[num3].ScenicSpot_MENPIAO=200;//������Ʊ��
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
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"6.3��");//����ά������
	ScenicSpotList[num3].ScenicSpot_MENPIAO=80;//������Ʊ��
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
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"1.5��");//����ά������
	ScenicSpotList[num3].ScenicSpot_MENPIAO=90;//������Ʊ��
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
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"2��");//����ά������
	ScenicSpotList[num3].ScenicSpot_MENPIAO=60;//������Ʊ��
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
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"5��");//����ά������
	ScenicSpotList[num3].ScenicSpot_MENPIAO=80;//������Ʊ�� 
	fwrite(&ScenicSpotList,sizeof(ScenicSpot),8,fp);
	fclose(fp);
}
 
