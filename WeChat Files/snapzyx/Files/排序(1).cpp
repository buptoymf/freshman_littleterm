  #include<stdio.h>
  #include<process.h>
  #include <stdlib.h>
  #include <string.h>
  
  //景点信息

   struct  ScenicSpot
 {
	char ScenicSpot_ID[80];//景点ID
	char ScenicSpot_NAME[80];//景点名称
	char ScenicSpot_INTRO[80];//景点简介
	int ScenicSpot_PRICE1;//景点旺季门票价格
	int ScenicSpot_PRICE2;//景点淡季门票价格
	char ScenicSpot_TIME[80];//游览该景点所需时间
	float ScenicSpot_DISCOUNT1;//学生折扣信息
	float ScenicSpot_DISCOUNT2;//军人折扣信息
	float ScenicSpot_DISCOUNT3;//普通折扣信息
	char ScenicSpot_GRADE[80];//景点级别
	char ScenicSpot_NUMBER[80];//人数限制
	char ScenicSpot_AREA[80];//景点所属区域
	int ScenicSpot_COST[80];//景点维护费用
	int ScenicSpot_MENPIAO;//景点总票 
	int ScenicSpot_VISIT;//景点访问人数 
	int ScenicSpot_YUDING;//景点预定量 
	float ScenicSpot_HAOPING;//景点好评率 
 }ScenicSpotList[NUMBER],ScenicSpotList[NUMBER]2;
 
 //预订信息

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

 
 
  void piaojiapaixu()//按景点旺季票价有小到大排序 
 {
   FILE *fp;
   fp=fopen("景点信息.txt","rb");//打开文件“景点信息” 
    int i;
    for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//引入文件中景点数据,计算景点个数 ,i是景点个数 
	/*for(n=0;n<i;n++)
    fread(&ScenicSpotList[n],sizeof(struct  ScenicSpot),i,fp);*/
	
	int j,k,n;//n,j,k用来辅助排序， ScenicSpotList2用来辅助排序 
	 for(int n=1;n<i;n++)
   {
      k=ScenicSpotList[n].ScenicSpot_PRICE1;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//存下 ScenicSpotList[n]数据 
      j=n-1;//j用来计数当前数据最多与前数据交换次数 
        while((j>=0)&&(ScenicSpotList[j].ScenicSpot_PRICE1>k))
		// j不为负且ScenicSpotList[n-1]>ScenicSpotList[n],则交换 
      {
         ScenicSpotList[j+1].ScenicSpot_PRICE1=ScenicSpotList[j].ScenicSpot_PRICE1;
         ScenicSpotList[j+1]=ScenicSpotList[j];         
         j--;
      }//j-1，继续比较 ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_PRICE1=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];

   }
   printf("   景点名称          景点ID          旺季票价         淡季票价\n");
   for(int n=0;n<i;n++)
    {       
       printf("%11s\t%11s\t%11d\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_PRICE1,ScenicSpotList[n].ScenicSpot_PRICE2);
    }//输出排序后景点数据 
    fclose(fp);//关闭文件 
 }




 int main()
{   
    piaojiapaixu();
	return 0;
}

  
   
  
   
   
   void yudingliangpaixu() //按景点预售量从大到小排序 
 {
   FILE *fp,*fp2;
   fp=fopen("景点信息.txt","rb");//打开文件“景点信息” 
    int i;
     for(i=0;fread(&ScenicSpotList2[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);
     //将“景点名称”中信息赋值给 ScenicSpotList2
    fp=fopen("订单信息.txt","rb");//打开文件订单信息 
    int i2;//i2为订单个数 
     for(i2=0;fread(&info[i2],sizeof(struct info_list),1,fp2)!=0;i2++);
     //计算订单个数 
    int yu[80];\
      for(int n=0;n<i2;n++)
	   yu[n]=0;//为预定量建立数组 
    //strcmp(dsfsfs,dfdfd)
     for(int n=0;n<i;n++)
      { for(int j=0;j<i2;j++)
         if(strcmp(ScenicSpotList2.ScenicSpot_ID,info)==0)
           yu[n]=yu[n]+info.order_IDENTITY1+info.order_IDENTITY2+info.order_IDENTITY3;
	  }
    //根据景点id，分别计算各景点预定量 
    for(int n=0;n<i;n++)
     {
        //ScenicSpotList2[n]=ScenicSpotList[n];
     	ScenicSpotList2[n].ScenicSpot_YUDING=yu[n];
	 }
	 // 输入修改后预定量 
     fclose(fp);
     fclose(fp2);
     fp=fopen("景点信息.txt","w");
     fwrite(&ScenicSpotList2,sizeof(struct  ScenicSpot),i,fp);
     //将修改后信息输入“景点信息”   
	 FILE *fp;
     fp=fopen("景点信息.txt","rb");//打开文件，景点名称 
     int i; 
    for(i=1;fread(&ScenicSpotList[i-1],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//引入文件中景点数据,计算景点个数 ,i是景点个数    
     	int j,k,n;//n,j,k用来辅助排序， ScenicSpotList2用来辅助排序     	
	 for(int n=1;n<i;n++)
   {
      k=ScenicSpotList[n].ScenicSpot_YUDING ;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//存下 ScenicSpotList[n]数据 
      j=n-1;//j用来计数当前数据最多与前数据交换次数 
        while((j>=0)&&(ScenicSpotList[j].ScenicSpot_YUDING <k))
        // j不为负且ScenicSpotList[n-1]>ScenicSpotList[n],则交换
      {
         ScenicSpotList[j+1].ScenicSpot_YUDING =ScenicSpotList[j].ScenicSpot_YUDING ;
         ScenicSpotList2[j+1]=ScenicSpotList[j];         
         j--;
      } //j-1，继续比较 ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_PRICE1=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];
     printf("   景点名称          景点ID          景点预定量"); 
    for(int n=0;n<i-1;n++)
    {       
       printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_YUDING  );
    }//输出排序后景点数据 
     fclose(fp);
}
 
 
 

 
 
 
   void fangwenrenshupaixu()//按访问人数有小到大排序 
 {   FILE *fp;
     fp=fopen("景点信息.txt","rb");//打开文件，景点信息 
     int i; 
    for(i=1;fread(&ScenicSpotList[i-1],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//引入文件中景点数据,计算景点个数 ,i是景点个数 
	int j,k,n;//n,j,k用来辅助排序， ScenicSpotList2用来辅助排序 
	 for(int n=1;n<i;n++)
   {
      k=ScenicSpotList[n]   访问人数;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//存下 ScenicSpotList[n]数据 
      j=n-1;//j用来计数当前数据最多与前数据交换次数 
        while((j>=0)&&(ScenicSpotList[j] 访问人数 >k))
        // j不为负且ScenicSpotList[n-1]>ScenicSpotList[n],则交换
      {
         ScenicSpotList[j+1] 访问人数 =ScenicSpotList[j]  ;
         ScenicSpotList2[j+1]=ScenicSpotList[j];         
         j--;
      } //j-1，继续比较 ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_PRICE1=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];
     printf("   景点名称          景点ID          景点访问人数");
    for(int n=0;n<i-1;n++)
    {       
       printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n] 访问人数 );
    }//输出排序后景点数据 
    fclose(fp);//关闭文件 
   } 
 	
 }
 
 
 
 
 
    void lirunpaixu()//利润由大到小排序 
 { 
     FILE *fp，*fp2 ;
     fp=fopen("景点信息.txt","rb");//打开文件，景点信息 
     int i; 
    for(i=1;fread(&ScenicSpotList[i-1],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//引入文件中景点数据,计算景点个数 ,i是景点个数 
	int j,k,n;//n,j,k用来辅助排序， ScenicSpotList2用来辅助排序 
	 for(int n=1;n<i;n++)
   {
      k=ScenicSpotList[n]   利润;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//存下 ScenicSpotList[n]数据 
      j=n-1;//j用来计数当前数据最多与前数据交换次数 
        while((j>=0)&&(ScenicSpotList[j] 利润 <k))
        // j不为负且ScenicSpotList[n-1]>ScenicSpotList[n],则交换
      {
         ScenicSpotList[j+1] 利润 =ScenicSpotList[j]  ;
         ScenicSpotList2[j+1]=ScenicSpotList[j];         
         j--;
      } //j-1，继续比较 ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_PRICE1=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];
      printf("   景点名称          景点ID          利润");
    for(int n=0;n<i-1;n++)
    {       
       printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n] 利润 );
    }//输出排序后景点数据 
      fclose(fp);//关闭文件 	
 }
 
      void age()//年龄统计 
 {
 	   FILE *fp;
       fp=fopen("景点信息.txt","rb");//打开文件，景点信息
       int i; 
       for(i=1;fread(&ScenicSpotList[i-1],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	    //引入文件中景点数据,计算景点个数 ,i是景点个数
	   printf("   景点名称          景点ID          年龄层次"); 
	    for(int n=0;n<i-1;n++)
       {       
          printf("%11s\t%11s\t%11c\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n]年龄层次 );
       }
       fclose(fp);//关闭文件
 }
 
 
 
 
 
   void tuijian()//不同季度景点推荐 
 {
 	FILE *fp;
       fp=fopen("景点信息.txt","rb");//打开文件，景点信息
       int i; 
       for(i=1;fread(&ScenicSpotList[i-1],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	    //引入文件中景点数据,计算景点个数 ,i是景点个数
	    printf("热门景点推荐\n\n); 
	   printf("   景点名称          景点ID          访问量"); 
	   printf("第一季度\n");
	    for(int n=0;n<i-1;n++)
       {       
          printf("%11s\t%11s\t%11c\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n]访问量一 );
       }
        printf("第二季度\n");
	    for(int n=0;n<i-1;n++)
       {       
          printf("%11s\t%11s\t%11c\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n]访问量二 );
       }
        printf("第三季度\n");
	    for(int n=0;n<i-1;n++)
       {       
          printf("%11s\t%11s\t%11c\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n]访问量三 );
       }
        printf("第四季度\n");
	    for(int n=0;n<i-1;n++)
       {       
          printf("%11s\t%11s\t%11c\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n]访问量四);
       }
       fclose(fp);//关闭文件
 }
 
 
 
 
 void piaojiapaixu()//景点推荐 
 {
   FILE *fp;
   fp=fopen("景点信息.txt","rb");//打开文件“景点信息” 
    int i;
    for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//引入文件中景点数据,计算景点个数 ,i是景点个数 
	/*for(n=0;n<i;n++)
    fread(&ScenicSpotList[n],sizeof(struct  ScenicSpot),i,fp);*/
	
	int j,k,n;//n,j,k用来辅助排序， ScenicSpotList2用来辅助排序 
	 for(int n=1;n<i;n++)
   {
      k=ScenicSpotList[n].ScenicSpot_PRICE1;
      ScenicSpotList2[n-1]=ScenicSpotList[n];//存下 ScenicSpotList[n]数据 
      j=n-1;//j用来计数当前数据最多与前数据交换次数 
        while((j>=0)&&(ScenicSpotList[j].ScenicSpot_HAOPING>k))
		// j不为负且ScenicSpotList[n-1]>ScenicSpotList[n],则交换 
      {
         ScenicSpotList[j+1].ScenicSpot_HAOPING=ScenicSpotList[j].ScenicSpot_HAOPING;
         ScenicSpotList[j+1]=ScenicSpotList[j];         
         j--;
      }//j-1，继续比较 ScenicSpotList[n-2]>ScenicSpotList[n]
     ScenicSpotList[j+1].ScenicSpot_HAOPING=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];

   }
   printf("   景点名称          景点ID          旺季票价         淡季票价\n");
   for(int n=0;n<i;n++)
    {       
       printf("%11s\t%11s\t%11d\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_HAOPING,);
    }//输出排序后景点数据 
    fclose(fp);//关闭文件 
 }

