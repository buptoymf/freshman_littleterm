  #include<stdio.h>
  #include<process.h>
  #include <stdlib.h>
  #include <string.h>
  
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
	int ScenicSpot_COST[80];//����ά������
	int ScenicSpot_MENPIAO;//������Ʊ 
	int ScenicSpot_VISIT;//����������� 
	int ScenicSpot_YUDING;//����Ԥ���� 
	float ScenicSpot_HAOPING;//��������� 
 }ScenicSpotList[NUMBER],ScenicSpotList[NUMBER]2;
 
 //Ԥ����Ϣ

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
}info[80];

 
 
  void piaojiapaixu()//����������Ʊ����С�������� 
 {
   FILE *fp;
   fp=fopen("������Ϣ.txt","rb");//���ļ���������Ϣ�� 
    int i;
    for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//�����ļ��о�������,���㾰����� ,i�Ǿ������ 
	/*for(n=0;n<i;n++)
    fread(&ScenicSpotList[n],sizeof(struct  ScenicSpot),i,fp);*/
	
	int j,k,n;//n,j,k������������ ScenicSpotList2������������ 
	 for(int n=1;n<i;n++)
   {
      k=ScenicSpotList[n].ScenicSpot_PRICE1;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//���� ScenicSpotList[n]���� 
      j=n-1;//j����������ǰ���������ǰ���ݽ������� 
        while((j>=0)&&(ScenicSpotList[j].ScenicSpot_PRICE1>k))
		// j��Ϊ����ScenicSpotList[n-1]>ScenicSpotList[n],�򽻻� 
      {
         ScenicSpotList[j+1].ScenicSpot_PRICE1=ScenicSpotList[j].ScenicSpot_PRICE1;
         ScenicSpotList[j+1]=ScenicSpotList[j];         
         j--;
      }//j-1�������Ƚ� ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_PRICE1=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];

   }
   printf("   ��������          ����ID          ����Ʊ��         ����Ʊ��\n");
   for(int n=0;n<i;n++)
    {       
       printf("%11s\t%11s\t%11d\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_PRICE1,ScenicSpotList[n].ScenicSpot_PRICE2);
    }//�������󾰵����� 
    fclose(fp);//�ر��ļ� 
 }




 int main()
{   
    piaojiapaixu();
	return 0;
}

  
   
  
   
   
   void yudingliangpaixu() //������Ԥ�����Ӵ�С���� 
 {
   FILE *fp,*fp2;
   fp=fopen("������Ϣ.txt","rb");//���ļ���������Ϣ�� 
    int i;
     for(i=0;fread(&ScenicSpotList2[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);
     //�����������ơ�����Ϣ��ֵ�� ScenicSpotList2
    fp=fopen("������Ϣ.txt","rb");//���ļ�������Ϣ 
    int i2;//i2Ϊ�������� 
     for(i2=0;fread(&info[i2],sizeof(struct info_list),1,fp2)!=0;i2++);
     //���㶩������ 
    int yu[80];\
      for(int n=0;n<i2;n++)
	   yu[n]=0;//ΪԤ������������ 
    //strcmp(dsfsfs,dfdfd)
     for(int n=0;n<i;n++)
      { for(int j=0;j<i2;j++)
         if(strcmp(ScenicSpotList2.ScenicSpot_ID,info)==0)
           yu[n]=yu[n]+info.order_IDENTITY1+info.order_IDENTITY2+info.order_IDENTITY3;
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
     fp=fopen("������Ϣ.txt","w");
     fwrite(&ScenicSpotList2,sizeof(struct  ScenicSpot),i,fp);
     //���޸ĺ���Ϣ���롰������Ϣ��   
	 FILE *fp;
     fp=fopen("������Ϣ.txt","rb");//���ļ����������� 
     int i; 
    for(i=1;fread(&ScenicSpotList[i-1],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//�����ļ��о�������,���㾰����� ,i�Ǿ������    
     	int j,k,n;//n,j,k������������ ScenicSpotList2������������     	
	 for(int n=1;n<i;n++)
   {
      k=ScenicSpotList[n].ScenicSpot_YUDING ;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//���� ScenicSpotList[n]���� 
      j=n-1;//j����������ǰ���������ǰ���ݽ������� 
        while((j>=0)&&(ScenicSpotList[j].ScenicSpot_YUDING <k))
        // j��Ϊ����ScenicSpotList[n-1]>ScenicSpotList[n],�򽻻�
      {
         ScenicSpotList[j+1].ScenicSpot_YUDING =ScenicSpotList[j].ScenicSpot_YUDING ;
         ScenicSpotList2[j+1]=ScenicSpotList[j];         
         j--;
      } //j-1�������Ƚ� ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_PRICE1=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];
     printf("   ��������          ����ID          ����Ԥ����"); 
    for(int n=0;n<i-1;n++)
    {       
       printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_YUDING  );
    }//�������󾰵����� 
     fclose(fp);
}
 
 
 

 
 
 
   void fangwenrenshupaixu()//������������С�������� 
 {   FILE *fp;
     fp=fopen("������Ϣ.txt","rb");//���ļ���������Ϣ 
     int i; 
    for(i=1;fread(&ScenicSpotList[i-1],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//�����ļ��о�������,���㾰����� ,i�Ǿ������ 
	int j,k,n;//n,j,k������������ ScenicSpotList2������������ 
	 for(int n=1;n<i;n++)
   {
      k=ScenicSpotList[n]   ��������;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//���� ScenicSpotList[n]���� 
      j=n-1;//j����������ǰ���������ǰ���ݽ������� 
        while((j>=0)&&(ScenicSpotList[j] �������� >k))
        // j��Ϊ����ScenicSpotList[n-1]>ScenicSpotList[n],�򽻻�
      {
         ScenicSpotList[j+1] �������� =ScenicSpotList[j]  ;
         ScenicSpotList2[j+1]=ScenicSpotList[j];         
         j--;
      } //j-1�������Ƚ� ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_PRICE1=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];
     printf("   ��������          ����ID          �����������");
    for(int n=0;n<i-1;n++)
    {       
       printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n] �������� );
    }//�������󾰵����� 
    fclose(fp);//�ر��ļ� 
   } 
 	
 }
 
 
 
 
 
    void lirunpaixu()//�����ɴ�С���� 
 { 
     FILE *fp��*fp2 ;
     fp=fopen("������Ϣ.txt","rb");//���ļ���������Ϣ 
     int i; 
    for(i=1;fread(&ScenicSpotList[i-1],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//�����ļ��о�������,���㾰����� ,i�Ǿ������ 
	int j,k,n;//n,j,k������������ ScenicSpotList2������������ 
	 for(int n=1;n<i;n++)
   {
      k=ScenicSpotList[n]   ����;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//���� ScenicSpotList[n]���� 
      j=n-1;//j����������ǰ���������ǰ���ݽ������� 
        while((j>=0)&&(ScenicSpotList[j] ���� <k))
        // j��Ϊ����ScenicSpotList[n-1]>ScenicSpotList[n],�򽻻�
      {
         ScenicSpotList[j+1] ���� =ScenicSpotList[j]  ;
         ScenicSpotList2[j+1]=ScenicSpotList[j];         
         j--;
      } //j-1�������Ƚ� ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_PRICE1=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];
      printf("   ��������          ����ID          ����");
    for(int n=0;n<i-1;n++)
    {       
       printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n] ���� );
    }//�������󾰵����� 
      fclose(fp);//�ر��ļ� 	
 }
 
      void age()//����ͳ�� 
 {
 	   FILE *fp;
       fp=fopen("������Ϣ.txt","rb");//���ļ���������Ϣ
       int i; 
       for(i=1;fread(&ScenicSpotList[i-1],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	    //�����ļ��о�������,���㾰����� ,i�Ǿ������
	   printf("   ��������          ����ID          ������"); 
	    for(int n=0;n<i-1;n++)
       {       
          printf("%11s\t%11s\t%11c\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n]������ );
       }
       fclose(fp);//�ر��ļ�
 }
 
 
 
 
 
   void tuijian()//��ͬ���Ⱦ����Ƽ� 
 {
 	FILE *fp;
       fp=fopen("������Ϣ.txt","rb");//���ļ���������Ϣ
       int i; 
       for(i=1;fread(&ScenicSpotList[i-1],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	    //�����ļ��о�������,���㾰����� ,i�Ǿ������
	    printf("���ž����Ƽ�\n\n); 
	   printf("   ��������          ����ID          ������"); 
	   printf("��һ����\n");
	    for(int n=0;n<i-1;n++)
       {       
          printf("%11s\t%11s\t%11c\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n]������һ );
       }
        printf("�ڶ�����\n");
	    for(int n=0;n<i-1;n++)
       {       
          printf("%11s\t%11s\t%11c\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n]�������� );
       }
        printf("��������\n");
	    for(int n=0;n<i-1;n++)
       {       
          printf("%11s\t%11s\t%11c\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n]�������� );
       }
        printf("���ļ���\n");
	    for(int n=0;n<i-1;n++)
       {       
          printf("%11s\t%11s\t%11c\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n]��������);
       }
       fclose(fp);//�ر��ļ�
 }
 
 
 
 
 void piaojiapaixu()//�����Ƽ� 
 {
   FILE *fp;
   fp=fopen("������Ϣ.txt","rb");//���ļ���������Ϣ�� 
    int i;
    for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//�����ļ��о�������,���㾰����� ,i�Ǿ������ 
	/*for(n=0;n<i;n++)
    fread(&ScenicSpotList[n],sizeof(struct  ScenicSpot),i,fp);*/
	
	int j,k,n;//n,j,k������������ ScenicSpotList2������������ 
	 for(int n=1;n<i;n++)
   {
      k=ScenicSpotList[n].ScenicSpot_PRICE1;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//���� ScenicSpotList[n]���� 
      j=n-1;//j����������ǰ���������ǰ���ݽ������� 
        while((j>=0)&&(ScenicSpotList[j].ScenicSpot_HAOPING>k))
		// j��Ϊ����ScenicSpotList[n-1]>ScenicSpotList[n],�򽻻� 
      {
         ScenicSpotList[j+1].ScenicSpot_HAOPING=ScenicSpotList[j].ScenicSpot_HAOPING;
         ScenicSpotList[j+1]=ScenicSpotList[j];         
         j--;
      }//j-1�������Ƚ� ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_HAOPING=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];

   }
   printf("   ��������          ����ID          ����Ʊ��         ����Ʊ��\n");
   for(int n=0;n<i;n++)
    {       
       printf("%11s\t%11s\t%11d\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_HAOPING,);
    }//�������󾰵����� 
    fclose(fp);//�ر��ļ� 
 }

