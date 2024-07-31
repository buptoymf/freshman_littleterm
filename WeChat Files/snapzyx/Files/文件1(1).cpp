#include<stdio.h>
#include<string.h>
struct tourist
{
	char tourist_ID[20];//游客团体ID
	char tourist_PASSWORD[20];//游客团体密码 
	char tourist_NUM[20];//游客团体人数 
	char tourist_AGE[20];//游客团体年龄层次 
	char tourist_PHONE[20];//游客团体联系人电话 
}touristList[80];
main()
{
	FILE *fp;
	fp=fopen("游客信息.txt","w");
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
	fwrite(&touristList,sizeof(tourist),5,fp);
	fclose(fp);
}
 
