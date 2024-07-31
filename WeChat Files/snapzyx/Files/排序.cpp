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
	char ScenicSpot_COST[80];//景点维护费用 
  }ScenicSpotList[80],ScenicSpotList2[80];
  
  void piaojiapaixu()
 {
   FILE *fp;
   fp=fopen("景点信息.txt","rb");//打开文件“景点信息” 
    int i,n;
    for(i=0;fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//引入文件中景点数据,计算景点个数 ,i是景点个数 
	/*for(n=0;n<i;n++)
    fread(&ScenicSpotList[n],sizeof(struct  ScenicSpot),i,fp);*/
	
	int j,k;
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
   printf("   景点名称          景点ID          旺季票价         淡季票价\n");
   for(int n=0;n<i;n++)
    {       
       printf("%11s\t%11s\t%11d\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n].ScenicSpot_PRICE1,ScenicSpotList[n].ScenicSpot_PRICE2);
    }
    fclose(fp);
 }

 int main()
{   
    piaojiapaixu();
	return 0;
}

  /*void yudingliang()//按景点预售量从小到大排序 
   { 
     FILE *fp;
     fp=fopen("景点信息.txt","rb");//打开文件，景点信息 
     int i,n; //
    for(i=1;fread(&ScenicSpotList[i-1],sizeof(struct  ScenicSpot),1,fp)!=0;i++);  
	//引入文件中景点数据,计算景点个数 ,i是景点个数 
	int j,k;
	 for(int n=1;n<i;n++)
   {
      k=ScenicSpotList[n]  ;
      ScenicSpotList2[n-1]=ScenicSpotList[n];
      j=n-1;
        while((j>=0)&&(ScenicSpotList[j]  >k))
      {
         ScenicSpotList[j+1]  =ScenicSpotList[j]  ;
         ScenicSpotList2[j+1]=ScenicSpotList[j];         
         j--;
      }
     ScenicSpotList[j+1].ScenicSpot_PRICE1=k;
     ScenicSpotList[j+1]=ScenicSpotList2[n-1];
    for(int n=0;n<i-1;n++)
    {       
       printf("%11s\t%11s\t%11d\n",ScenicSpotList[n].ScenicSpot_NAME,ScenicSpotList[n].ScenicSpot_ID,ScenicSpotList[n]  );
    }
    fclose(fp);
   }
   }*/
