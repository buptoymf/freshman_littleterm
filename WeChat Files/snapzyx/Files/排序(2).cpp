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
	float ScenicSpot_COST;//����ά������    ���޸� 
	int ScenicSpot_MENPIAO;//������Ʊ 
	int ScenicSpot_VISIT;//����������� 
	int ScenicSpot_YUDING;//����Ԥ���� 
	float ScenicSpot_HAOPING;//��������� 
 }ScenicSpotList[80],ScenicSpotList2[80];
 
 //Ԥ����Ϣ

//����ṹ�� 
struct info_list
{
	
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
	char order_jidu[20];//�������� 
	 
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
     printf("   ��������          ����ID          ����Ԥ����\n");    
    for(int n=0;n<i;n++)
     {       
       printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_YUDING  );
     }//�������󾰵����� 
     fclose(fp3);
  }

 
 
 

 
 
 
   void fangwenrenshupaixu()//������������С�������� 
 {  FILE *fp,*fp2;
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
  }
 
 
 
 
 
    void lirunpaixu()//�����ɴ�С���� 
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
}
 
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
 
 
 
 
 
   void tuijian()//��ͬ���Ⱦ����Ƽ� 
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
 }  
 
 
 
 
 void haoping()//�����Ƽ� 
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
   printf("   ��������          ����ID          ������\n");
   for(int n=0;n<i;n++)
    {       
       printf("%11s\t%11s\t%11.2f\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_HAOPING);
    }//�������󾰵����� 
    fclose(fp);//�ر��ļ� 
 }

