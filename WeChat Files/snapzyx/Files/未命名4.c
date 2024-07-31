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
	
	printf("���Ķ�����Ϣ���£�\n");
	printf("%15s%20s%20s%25s\n","����ID","��������","��Ʊ����","����ʱ��");

		fp=fopen("dingdan.txt","a");
		fclose(fp);

	for(i=0;i<n;i++)
	{
		fread(&info[i],sizeof(struct info_list),1,fp);
		printf("%15s%20s%20s%20s/%s/%s %s:00\n",info[i].id,info[i].name,info[i].number,info[i].y,info[i].m,info[i].d,info[i].h);
	}
	fclose(fp);
	printf("���Ķ�����Ϣ�ѱ��棬������ϵͳ����Ч��\n");
	
}

void inputinfo()
{
FILE *fp;
	int i,n;
	fp=fopen("dingdan.txt","a");
	printf("��Ҫ�����ٸ������Ʊ��\n");
	scanf("%d",&n);
	if(n<=0 || n>10)
	{
		printf("����������������������ֵ����!\n"); 
	}
	else 
	{
	printf("��ֱ�����ÿ�������ID,�������ƣ���Ʊ����������ʱ��(��/��/��/ʱ��)��ÿ��������һ��س�����\n");
	
		fp=fopen("dingdan.txt","a");
		
	for(i=0;i<n;i++)
	{
		printf("�������%d������������Ϣ��\n",i+1);
		
		printf("����ID��");
		scanf("%s",info[i].id);
		fputs(info[i].id,fp);
		fputs("\n",fp);
		
		printf("�������ƣ�");
		scanf("%s",info[i].name);
		fputs(info[i].name,fp);
		fputs("\n",fp);
		
		printf("��Ʊ������");
		scanf("%s",info[i].number);
		fputs(info[i].number,fp);
		fputs("\n",fp);
		
		printf("����ʱ�䣨�꣩");
		scanf("%s",info[i].y);
		fputs(info[i].y,fp);
		fputs("\n",fp);
			
		printf("����ʱ�䣨�£�");
		scanf("%s",info[i].m);
		fputs(info[i].m,fp);
		fputs("\n",fp);
		
		printf("����ʱ�䣨�գ�");
		scanf("%s",info[i].d);
		fputs(info[i].d,fp);
		fputs("\n",fp);
		
		printf("����ʱ�䣨ʱ��");
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
	
	printf("������Ϣ���£�������Ϊ�����ID,�������ƣ���Ʊ��������Ʊʱ�䣨�꣬�£��գ�ʱ��\n");
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
//		printf("��%d�������ľ����ID,�������ƣ���Ʊ��������Ʊʱ��\n",i);
		
		
		i++;
		
		
//			printf("��%d�������ľ����ID,�������ƣ���Ʊ��������Ʊʱ��\n",(i/4)+1);
		
		printf("%c",c);
		c=fgetc(fp);
		
//		}
	}
	
	if(i==0)
	{
		printf("�޶�����Ϣ��\n");
	}

	fclose(fp);
 }
  
void PrintMainMenu()
{
	printf("**************************���˵�**************************\n");
	printf("\t\t\t����������ı����ִ�����\n"); 
	printf("\t\t\t1.��Ӷ���\n");
	printf("\t\t\t2.��ѯ����\n");
	printf("\t\t\t3.�˶�\n");
	printf("\t\t\t4.�˳�\n");
	printf("*************************************************************\n");
} 



int main()
{
	char cmd[100];
    
    cmd[0]='9';
    
    printf("\t\t\t��ӭʹ�ñ����ʵ��ѧ�����ζ�Ʊϵͳ\n");
    printf("\n");
    PrintMainMenu(); 

	    while(cmd[0]!='4')
    {
    
	
    gets(cmd);//�������˵���Ӧ���������� 
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
        	printf("��������!\n");
		}
      	if(cmd[0]=='4')
        {
        	printf("�ټ�.");
		}
        
    }
	
	

	

	return 2;
}
