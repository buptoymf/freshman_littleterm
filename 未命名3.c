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
	
	printf("���Ķ�����Ϣ���£�\n");
	printf("%15s%20s%20s%20s\n","����ID","��������","��Ʊ����","��Ʊʱ��");

		fp=fopen("dingdan.txt","a");
		fclose(fp);

	for(i=0;i<n;i++)
	{
		fread(&info[i],sizeof(struct info_list),1,fp);
		printf("%15s%20s%20s%20s\n",info[i].id,info[i].name,info[i].number,info[i].tm);
	}
	fclose(fp);
	printf("���Ķ�����Ϣ�ѱ��档\n");
	
}






int main()
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
	printf("��ֱ�����ÿ�������ID,�������ƣ���Ʊ��������Ʊʱ�䣬ÿ��������һ��س�����\n");
	for(i=0;i<n;i++)
	{
		printf("�������%d������������Ϣ��\n",i+1);
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
