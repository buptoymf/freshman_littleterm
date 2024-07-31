#include<stdio.h>
#include<string.h>
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
	int ScenicSpot_MENPIAO;//景点总票 
}ScenicSpotList[80];
main()
{
	FILE *fp;
	fp=fopen("景点信息.txt","w");
//初始化景点信息
	int num3=0;
	//1号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0001");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"万里长城");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"中国伟大的军事建筑");//景点简介
	ScenicSpotList[num3].ScenicSpot_PRICE1=200;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=140;//景点淡季门票价格  
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"4小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.8;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.7;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"无");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"北京");//景点所属区域 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"10万");//景点维护费用
	ScenicSpotList[num3].ScenicSpot_MENPIAO=70; //景点总票数
	num3++; 
	//2号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0002");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"桂林山水");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"桂林山水甲天下");//景点简介 
	ScenicSpotList[num3].ScenicSpot_PRICE1=350;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=300;//景点淡季门票价格  
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"2.5小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=1.0;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=1.0;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=1.0;//普通折扣信息  
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"无");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"桂林");//景点所属区域 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"7.8万");//景点维护费用
	ScenicSpotList[num3].ScenicSpot_MENPIAO=110;//景点总票数
	num3++;
	//3号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0003");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"故宫");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"明清两代的皇宫");//景点简介
	ScenicSpotList[num3].ScenicSpot_PRICE1=100;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=50;//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"3.5小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.8;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.75;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"10万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"北京");//景点所属区域 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"4万");//景点维护费用
	ScenicSpotList[num3].ScenicSpot_MENPIAO=100;//景点总票数
	num3++;
	//4号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0004");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"杭州西湖");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"历史悠久、世界著名的风景游览胜地");//景点简介 
	ScenicSpotList[num3].ScenicSpot_PRICE1=230;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=170;//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"3小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.7;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.5;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"2万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"杭州");//景点所属区域 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"5.1万");//景点维护费用
	ScenicSpotList[num3].ScenicSpot_MENPIAO=200;//景点总票数
	num3++;
	//5号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0005");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"苏州园林");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"悠久历史的私家园林");//景点简介 
	ScenicSpotList[num3].ScenicSpot_PRICE1=200;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=140;//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"2小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.75;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.6;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"1.5万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"苏州");//景点所属区域 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"6.3万");//景点维护费用
	ScenicSpotList[num3].ScenicSpot_MENPIAO=80;//景点总票数
	num3++;
	//6号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0006");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"安徽黄山");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"天下第一奇山");//景点简介 
	ScenicSpotList[num3].ScenicSpot_PRICE1=225;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=175;//景点淡季门票价格  
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"3.5小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.8;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.8;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"3.1万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"黄山市");//景点所属区域 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"1.5万");//景点维护费用
	ScenicSpotList[num3].ScenicSpot_MENPIAO=90;//景点总票数
	num3++;
	//7号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0007");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"长江三峡");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"长江上最为奇秀壮丽的山水画廊");//景点简介  
	ScenicSpotList[num3].ScenicSpot_PRICE1=240;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=200;//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"2.6小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.75;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.75;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"1.5万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"长江");//景点所属区域 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"2万");//景点维护费用
	ScenicSpotList[num3].ScenicSpot_MENPIAO=60;//景点总票数
	num3++;
	//8号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0008");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"兵马俑");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"秦朝的奇迹");//景点简介
	ScenicSpotList[num3].ScenicSpot_PRICE1=200;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=140;//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"1.5小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.65;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.8;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"1万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"西安");//景点所属区域 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"5万");//景点维护费用
	ScenicSpotList[num3].ScenicSpot_MENPIAO=80;//景点总票数 
	fwrite(&ScenicSpotList,sizeof(ScenicSpot),8,fp);
	fclose(fp);
}
 
