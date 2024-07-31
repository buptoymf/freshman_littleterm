#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>

struct info_list
{
	char id[10];
	char name[10];
	char number[10];
	char y[10];
	char m[10];
	char d[10];
	char h[10];
}info[100];



void show(int n)
{
	
	int i;
	FILE *fp;
	
	printf("您的订单信息如下：\n");
	printf("%15s%20s%20s%25s\n","景点ID","景点名称","订票数量","出行时间");

		fp=fopen("dingdan.txt","a");
		fclose(fp);

	for(i=0;i<n;i++)
	{
		fread(&info[i],sizeof(struct info_list),1,fp);
		printf("%15s%20s%20s%20s/%s/%s %s:00\n",info[i].id,info[i].name,info[i].number,info[i].y,info[i].m,info[i].d,info[i].h);
	}
	fclose(fp);
	printf("您的订单信息已保存，重启本系统后生效。\n");
	
}

void inputinfo()
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
	printf("请分别输入每个景点的ID,景点名称，订票数量，出行时间(年/月/日/时间)，每次输入完一项按回车继续\n");
	
		fp=fopen("dingdan.txt","a");
		
	for(i=0;i<n;i++)
	{
		printf("请输入第%d个景点的相关信息：\n",i+1);
		
		printf("景点ID：");
		scanf("%s",info[i].id);
		fputs(info[i].id,fp);
		fputs("\n",fp);
		
		printf("景点名称：");
		scanf("%s",info[i].name);
		fputs(info[i].name,fp);
		fputs("\n",fp);
		
		printf("订票数量：");
		scanf("%s",info[i].number);
		fputs(info[i].number,fp);
		fputs("\n",fp);
		
		printf("出行时间（年）");
		scanf("%s",info[i].y);
		fputs(info[i].y,fp);
		fputs("\n",fp);
			
		printf("出行时间（月）");
		scanf("%s",info[i].m);
		fputs(info[i].m,fp);
		fputs("\n",fp);
		
		printf("出行时间（日）");
		scanf("%s",info[i].d);
		fputs(info[i].d,fp);
		fputs("\n",fp);
		
		printf("出行时间（时）");
		scanf("%s",info[i].h);
		fputs(info[i].h,fp);
		fputs("\n",fp);
		fputs("\n",fp);
		
		
		
		
	}
	
	fclose(fp);
	
	show(n);
	}
}

void outputinfo()
{
	
	FILE *fp;
	int i;
	char c;
	
	i=0;
	
	fp=fopen("dingdan.txt","r") ;
	
	printf("订单信息如下：（依次为景点的ID,景点名称，订票数量，订票时间（年，月，日，时）\n");
	c=fgetc(fp);
	
//	n=0;
//	while(c!=EOF)
//	{
//		n++;
//	}
//		n=n/4;
		
	while(c!=EOF)
	{
//		for(i=1;i<n+1;i++)
//		{
//		printf("第%d个订单的景点的ID,景点名称，订票数量，订票时间\n",i);
		
		
		i++;
		
		
//			printf("第%d个订单的景点的ID,景点名称，订票数量，订票时间\n",(i/4)+1);
		
		printf("%c",c);
		c=fgetc(fp);
		
//		}
	}
	
	if(i==0)
	{
		printf("无订单信息！\n");
	}

	fclose(fp);
 }
  
void PrintMainMenu()
{
	printf("**************************主菜单**************************\n");
	printf("\t\t\t请输入命令的编号以执行命令：\n"); 
	printf("\t\t\t1.添加订单\n");
	printf("\t\t\t2.查询订单\n");
	printf("\t\t\t3.退订\n");
	printf("\t\t\t4.退出\n");
	printf("*************************************************************\n");
} 



int main()
{
	char cmd[100];
    
    cmd[0]='9';
    
    printf("\t\t\t欢迎使用北京邮电大学团体游订票系统\n");
    printf("\n");
    PrintMainMenu(); 

	    while(cmd[0]!='4')
    {
    
	
    gets(cmd);//输入主菜单对应的命令数字 
        switch(cmd[0])
        {
            case '1':
                inputinfo();
                PrintMainMenu();
                break;
            case '2':
                outputinfo();
                PrintMainMenu();
                break;
            case '3':
            	inputinfo();
                PrintMainMenu();
                break;
            
			
        }
        if(cmd[0]!='1' && cmd[0]!='2' && cmd[0]!='3' && cmd[0]!='4' && cmd[0]!='\0')
        {
        	printf("输入有误!\n");
		}
      	if(cmd[0]=='4')
        {
        	printf("再见.");
		}
        
    }
	
	

	

	return 2;
}
