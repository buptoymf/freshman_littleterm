#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>

struct info_list
{
	char id[10];
	char name[10];
	char number[10];
	char tm[10];
}info[100];
void save()
{
	FILE *fp;
		fp=fopen("dingdan.txt","a");
		fclose(fp);
}

void show(int n)
{
	
	int i;
	FILE *fp;
	
	printf("您的订单信息如下：\n");
	printf("%15s%20s%20s%20s\n","景点ID","景点名称","订票数量","订票时间");

		fp=fopen("dingdan.txt","a");
		fclose(fp);

	for(i=0;i<n;i++)
	{
		fread(&info[i],sizeof(struct info_list),1,fp);
		printf("%15s%20s%20s%20s\n",info[i].id,info[i].name,info[i].number,info[i].tm);
	}
	fclose(fp);
	printf("您的订单信息已保存。\n");
	
}






int main()
{
	FILE *fp;
	int i,n;
	fp=fopen("dingdan.txt","a");
	printf("您要订多少个景点的票？\n");
	scanf("%d",&n);
	if(n<=0 || n>10)
	{
		printf("景点数量输入错误或输入数值过大!\n"); 
	}
	else 
	{
	printf("请分别输入每个景点的ID,景点名称，订票数量，订票时间，每次输入完一项按回车继续\n");
	for(i=0;i<n;i++)
	{
		printf("请输入第%d个景点的相关信息：\n",i+1);
		scanf("%s%s%s%s",info[i].id,info[i].name,info[i].number,info[i].tm);
		fputs(info[i].id,fp);
		fputs("\n",fp);
		fputs(info[i].name,fp);
		fputs("\n",fp);
		fputs(info[i].number,fp);
		fputs("\n",fp);
		fputs(info[i].tm,fp);
		fputs("\n",fp);
		save();
		
		
	}
	show(n);
	}
	

	

	return 2;
}
