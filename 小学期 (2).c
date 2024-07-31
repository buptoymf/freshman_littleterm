#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define NUMBER 80

//主界面 
void mainmenu()
{
	printf("\n\n\t**************Main Menu**************\n");
	printf("\t*            1.游客登陆             *\n");
	printf("\t*            2.管理员登陆           *\n");
	printf("\t*            3.关闭系统             *\n");
	printf("\t*************************************\n");
}

//游客登陆界面
void touristmenu()
{
	
	
} 

//管理员登陆界面
void adminmenu()
{
	
	
} 

//游客团体

struct tourist
{
	char tourist_ID[20];//游客团体ID
	char tourist_PASSWORD[20];//游客团体密码 
	char tourist_NUM[20];//游客团体人数 
	char tourist_AGE[20];//游客团体年龄层次 
	char tourist_PHONE[20];//游客团体联系人电话 
}touristList[NUMBER];

//系统管理员

struct administrator
{
	char administrator_ID[20];//系统管理员ID 
	char administrator_PASSWORD[20];//系统管理员密码 
	char administrator_PHONE[20];//系统管理员电话 
	char administrator_MAIL[20];//系统管理员邮箱 
}administratorList[NUMBER];

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
}ScenicSpotList[NUMBER];

//预订信息

struct order
{
	char order_ID[20];//订单编号
	char order_DAY[20];//预订日期
	char order_NUMBER[20];//景点编号
	char order_TIME[20];//出行时间
	char order_AGE[20];//年龄段
	char order_PEOPLENUM[20];//人数
	char order_IDENTITY[20];//身份
	float order_PRICE[20];//订单总价格
}orderList[NUMBER];

//---------初始化值函数---------- 

//初始化游客
void touristsystem()
{
	int num1=0; 
	//1号ID 
	strcpy(touristList[num1].tourist_ID,"youke001");//游客ID 
	strcpy(touristList[num1].tourist_PASSWORD,"youke001");//密码 
	strcpy(touristList[num1].tourist_NUM,"30");//人数 
	strcpy(touristList[num1].tourist_AGE,"25岁左右");//年龄层次 
	strcpy(touristList[num1].tourist_PHONE,"11111111111");//联系电话 
	num1++;
	//2号ID 
	strcpy(touristList[num1].tourist_ID,"youke002");//游客ID
	strcpy(touristList[num1].tourist_PASSWORD,"youke002");//密码
	strcpy(touristList[num1].tourist_NUM,"40");//人数
	strcpy(touristList[num1].tourist_AGE,"45岁左右");//年龄层次
	strcpy(touristList[num1].tourist_PHONE,"11111111112");//联系电话 
	num1++;
	//3号ID 
	strcpy(touristList[num1].tourist_ID,"youke003");//游客ID
	strcpy(touristList[num1].tourist_PASSWORD,"youke003");//密码
	strcpy(touristList[num1].tourist_NUM,"35");//人数
	strcpy(touristList[num1].tourist_AGE,"40岁左右");//年龄层次
	strcpy(touristList[num1].tourist_PHONE,"11111111113");//联系电话 
	num1++;
	//4号ID 
	strcpy(touristList[num1].tourist_ID,"youke004");//游客ID
	strcpy(touristList[num1].tourist_PASSWORD,"youke004");//密码
	strcpy(touristList[num1].tourist_NUM,"29");//人数
	strcpy(touristList[num1].tourist_AGE,"30岁左右");//年龄层次
	strcpy(touristList[num1].tourist_PHONE,"11111111114");//联系电话 
	num1++;
	//5号ID 
	strcpy(touristList[num1].tourist_ID,"youke005");//游客ID
	strcpy(touristList[num1].tourist_PASSWORD,"youke005");//密码
	strcpy(touristList[num1].tourist_NUM,"37");//人数
	strcpy(touristList[num1].tourist_AGE,"35岁左右");//年龄层次
	strcpy(touristList[num1].tourist_PHONE,"11111111115");//联系电话 
}
	
//初始化管理员
void adminsystem()
{
	int num2=0;
	//1号管理员
	strcpy(administratorList[num2].administrator_ID,"guanli01");//ID
	strcpy(administratorList[num2].administrator_PASSWORD,"guanli01");//密码 
	strcpy(administratorList[num2].administrator_PHONE,"11111110001");//电话 
	strcpy(administratorList[num2].administrator_MAIL,"01@guanli.com");//邮箱
	num2++; 
	//2号管理员
	strcpy(administratorList[num2].administrator_ID,"guanli02");//ID
	strcpy(administratorList[num2].administrator_PASSWORD,"guanli02");//密码 
	strcpy(administratorList[num2].administrator_PHONE,"11111110002");//电话 
	strcpy(administratorList[num2].administrator_MAIL,"02@guanli.com");//邮箱
	num2++; 
	//3号管理员
	strcpy(administratorList[num2].administrator_ID,"guanli03");//ID
	strcpy(administratorList[num2].administrator_PASSWORD,"guanli03");//密码 
	strcpy(administratorList[num2].administrator_PHONE,"11111110003");//电话 
	strcpy(administratorList[num2].administrator_MAIL,"03@guanli.com");//邮箱
}

//初始化景点信息
void spotsystem()
{
	int num3=0;
	//1号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0001");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"万里长城");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"中国伟大的军事建筑");//景点简介
	ScenicSpotList[num3].ScenicSpot_PRICE1=200;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=140;//景点淡季门票价格 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE,"200");//景点旺季门票价格 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE2,"140");//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"4小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.8;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.7;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息
	//strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT1,"0.8");//学生折扣信息 
	//strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT2,"0.7");//军人折扣信息 
	//strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT3,"0.9");//普通折扣信息
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"无");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"北京");//景点所属区域 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"10万");//景点维护费用 
	num3++; 
	//2号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0002");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"桂林山水");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"桂林山水甲天下");//景点简介 
	ScenicSpotList[num3].ScenicSpot_PRICE1=350;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=300;//景点淡季门票价格 
//	strcpy(ScenicSpotList[num3].ScenicSpot_PRICE1,"350");//景点旺季门票价格 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE2,"300");//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"2.5小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=1.0;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=1.0;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=1.0;//普通折扣信息 
	//strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT1,"1.0");//学生折扣信息 
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT2,"1.0");//军人折扣信息
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT3,"1.0");//普通折扣信息 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"无");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"桂林");//景点所属区域 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"7.8万");//景点维护费用
	num3++;
	//3号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0003");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"故宫");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"明清两代的皇宫");//景点简介
	ScenicSpotList[num3].ScenicSpot_PRICE1=100;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=50;//景点淡季门票价格
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE1,"100");//景点旺季门票价格 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE2,"50");//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"3.5小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.8;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.75;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息 
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT1,"0.8");//学生折扣信息 
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT2,"0.75");//军人折扣信息
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT3,"0.9");//普通折扣信息
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"10万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"北京");//景点所属区域 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"4万");//景点维护费用
	num3++;
	//4号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0004");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"杭州西湖");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"历史悠久、世界著名的风景游览胜地");//景点简介 
	ScenicSpotList[num3].ScenicSpot_PRICE1=230;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=170;//景点淡季门票价格 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE1,"230");//景点旺季门票价格 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE2,"170");//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"3小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.7;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.5;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息 
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT1,"0.7");//学生折扣信息
   // strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT2,"0.5");//军人折扣信息
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT3,"0.9");//普通折扣信息 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"5级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"2万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"杭州");//景点所属区域 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"5.1万");//景点维护费用
	num3++;
	//5号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0005");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"苏州园林");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"悠久历史的私家园林");//景点简介 
	ScenicSpotList[num3].ScenicSpot_PRICE1=200;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=140;//景点淡季门票价格 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE1,"200");//景点旺季门票价格 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE2,"140");//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"2小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.75;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.6;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息 
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT1,"0.75");//学生折扣信息
  //  strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT2,"0.6");//军人折扣信息
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT3,"0.9");//普通折扣信息 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"1.5万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"苏州");//景点所属区域 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"6.3万");//景点维护费用
	num3++;
	//6号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0006");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"安徽黄山");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"天下第一奇山");//景点简介 
	ScenicSpotList[num3].ScenicSpot_PRICE1=225;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=175;//景点淡季门票价格 
//	strcpy(ScenicSpotList[num3].ScenicSpot_PRICE1,"225");//景点旺季门票价格 
//	strcpy(ScenicSpotList[num3].ScenicSpot_PRICE2,"175");//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"3.5小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.8;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.8;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息 
//	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT1,"0.8");//学生折扣信息
  //  strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT2,"0.80");//军人折扣信息 
  //  strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT3,"0.9");//普通折扣信息
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"3.1万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"黄山市");//景点所属区域 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"1.5万");//景点维护费用
	num3++;
	//7号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0007");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"长江三峡");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"长江上最为奇秀壮丽的山水画廊");//景点简介  
	ScenicSpotList[num3].ScenicSpot_PRICE1=240;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=200;//景点淡季门票价格
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE1,"240");//景点旺季门票价格 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE2,"200");//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"2.6小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.75;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.75;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息
	/* 
	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT1,"0.75");//学生折扣信息
    strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT2,"0.75");//军人折扣信息
	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT3,"0.9");//普通折扣信息
	*/ 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"1.5万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"长江");//景点所属区域 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"2万");//景点维护费用
	num3++;
	//8号景点
	strcpy(ScenicSpotList[num3].ScenicSpot_ID,"jd0008");//景点ID
	strcpy(ScenicSpotList[num3].ScenicSpot_NAME,"兵马俑");//景点名称 
	strcpy(ScenicSpotList[num3].ScenicSpot_INTRO,"秦朝的奇迹");//景点简介
	ScenicSpotList[num3].ScenicSpot_PRICE1=200;//景点旺季门票价格
	ScenicSpotList[num3].ScenicSpot_PRICE2=140;//景点淡季门票价格 
	//strcpy(ScenicSpotList[num3].ScenicSpot_PRICE1,"260");//景点旺季门票价格 
//	strcpy(ScenicSpotList[num3].ScenicSpot_PRICE2,"210");//景点淡季门票价格 
	strcpy(ScenicSpotList[num3].ScenicSpot_TIME,"1.5小时");//游览所需时间
	ScenicSpotList[num3].ScenicSpot_DISCOUNT1=0.65;//学生折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT2=0.8;//军人折扣信息
	ScenicSpotList[num3].ScenicSpot_DISCOUNT3=0.9;//普通折扣信息
	/* 
	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT1,"0.65");//学生折扣信息
    strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT2,"0.8");//军人折扣信息
	strcpy(ScenicSpotList[num3].ScenicSpot_DISCOUNT3,"0.9");//普通折扣信息
	*/ 
	strcpy(ScenicSpotList[num3].ScenicSpot_GRADE,"4级");//景点级别 
	strcpy(ScenicSpotList[num3].ScenicSpot_NUMBER,"1万");//景点人数限制 
	strcpy(ScenicSpotList[num3].ScenicSpot_AREA,"西安");//景点所属区域 
	strcpy(ScenicSpotList[num3].ScenicSpot_COST,"5万");//景点维护费用
}

//预订信息
void dingdansystem()
{
    int num4=0;
}
	
	


 
