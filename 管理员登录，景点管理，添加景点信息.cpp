     void tianjiajingdianxinxi()
{
    FILE  *fpa;
    FILE  *fpb;
    int i=0;
    int c=0;
    int num1=0; 
    int ScenicSpotNum=8;//�������� 
    int panduan=1;//�ж��Ƿ�������ȷ 
    int panduan2;//�ж��Ƿ�����޸�
	int panduan3=0;//�жϾ���ID�Ƿ���ȷ
	int panduan4=0;//�жϾ��������Ƿ���ȷ 
	int e;//������Ϣ�Ƿ����� 
    int xuan;//ѡ��Ҫ�޸ĵ���Ϣ
	int tianjia;//����µ���Ϣ
	int queding;//�Ƿ񷢲�
	int discount1=1,discount2=1,discount3=1;//�ж��ۿ���Ϣ�����Ƿ�ϸ� 
	int menpiao;//�ж���Ʊ��Ϣ�Ƿ�����ϸ� 
    struct  ScenicSpot a[80];//�ݴ���Ϣ 
    struct  ScenicSpot b[80];//�ݴ���Ϣ
    //�򿪲���ȡ�ļ���Ϣ 
    fpa=fopen("������Ϣ.txt","a+");
	fpb=fopen("�����ϢԤ��.txt","a+");        
    for(i=0;i<ScenicSpotNum;i++)
    fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fpa);
    
		//�����µľ�����Ϣ 
        printf("�����뾰��ID\n");
		while(panduan3==0)
		{
			getchar(); 
    		scanf("%s",a[num1].ScenicSpot_ID);
    		panduan3=1;
    		for(c=0;c<ScenicSpotNum;c++)
    		if(strcmp(a[num1].ScenicSpot_ID,ScenicSpotList[c].ScenicSpot_ID)==0)//�ж��Ƿ񾰵�ID�ظ� 
			{ 
    	    	printf("����ID�ظ�\n");
    	    	panduan3=0; 
    			printf("���������뾰��ID\n");
    		}
    	}
    	printf("�����뾰������\n");
    	while(panduan4==0)
		{
    		scanf("%s",a[num1].ScenicSpot_NAME);
    		panduan4=1;
    		for(c=0;c<ScenicSpotNum;c++)
    		if(strcmp(a[num1].ScenicSpot_NAME,ScenicSpotList[c].ScenicSpot_NAME)==0)//�ж��Ƿ񾰵������ظ� 
			{ 
    			printf("���������ظ�\n");
    			panduan4=0;
    			printf("���������뾰������\n");
			}	
    	}
    	printf("�����뾰����\n");
    	scanf("%s",a[num1].ScenicSpot_INTRO);
    	printf("�����뾰��������Ʊ�۸�\n");
    	scanf("%d",&a[num1].ScenicSpot_PRICE1);
    	printf("�����뾰�㵭����Ʊ�۸�\n");
    	scanf("%d",&a[num1].ScenicSpot_PRICE2);
    	getchar();
    	printf("�����������þ�������ʱ��\n");
    	scanf("%s",a[num1].ScenicSpot_TIME);
    	printf("������ѧ���ۿ���Ϣ\n");
    	do
    	{
    		discount1=1;
    		scanf("%f",&a[num1].ScenicSpot_DISCOUNT1);
    		if(a[num1].ScenicSpot_DISCOUNT1>1)//�ж��ۿ���Ϣ�����Ƿ�ϸ�
    		{
    			discount1=0;
    			printf("�ۿ���Ϣ���벻�ϸ�����������\n");
    		}
    	}
    	while(discount1==0);
    	printf("����������ۿ���Ϣ\n");
    	do
    	{
    		discount2=1;
    		scanf("%f",&a[num1].ScenicSpot_DISCOUNT1);
    		if(a[num1].ScenicSpot_DISCOUNT1>1)//�ж��ۿ���Ϣ�����Ƿ�ϸ�
    		{
    			discount2=0;
    			printf("�ۿ���Ϣ���벻�ϸ�����������\n");
    		}
    	}
    	while(discount2==0);
    	printf("��������ͨ�ۿ���Ϣ\n");
    	do
    	{
    		discount3=1;
    		scanf("%f",&a[num1].ScenicSpot_DISCOUNT3);
    		if(a[num1].ScenicSpot_DISCOUNT3>1)//�ж��ۿ���Ϣ�����Ƿ�ϸ�
    		{
    			discount3=0;
    			printf("�ۿ���Ϣ���벻�ϸ�����������\n");
    		}
    	}
    	while(discount3==0);
    	getchar();
    	printf("�����뾰�㼶��\n");
    	scanf("%s",a[num1].ScenicSpot_GRADE);
    	printf("��������������\n");
    	scanf("%s",a[num1].ScenicSpot_NUMBER);
    	printf("�����뾰����������\n");
    	scanf("%s",a[num1].ScenicSpot_AREA);
    	printf("�����뾰��ά������\n");
    	scanf("%d",&a[num1].ScenicSpot_COST);
    	printf("�����뾰����Ʊ��\n");
    	do
    	{
    		menpiao=1;
    		scanf("%d",&a[num1].ScenicSpot_MENPIAO);
    		if(a[num1].ScenicSpot_MENPIAO<0)//�ж���Ʊ��Ϣ�Ƿ�����ϸ�
    		{
    			menpiao=0;
    			printf("���벻�ϸ�����������\n");
    		}
    	}
    	while(menpiao==0);
    	printf("�����뾰�������\n");
    	scanf("%f",&a[num1].ScenicSpot_HAOPING);
    	printf("�����뾰���Ƿ��������˶�ͯ\n");
    	getchar();
    	scanf("%s",a[num1].ScenicSpot_LRET); 
    	printf("��ȷ�Ͼ�����Ϣ�Ƿ�����\n1.�޸�\n2.ȡ�����\n3.����\n");
    	scanf("%d",&e);
    	if(e==1)
		{
			i++;
			do
			{
				printf("��ѡ��Ҫ�޸ĵ���Ϣ\n");
				printf("1.����ID\n");
				printf("2.��������\n");
				printf("3.������\n");
				printf("4.����������Ʊ�۸�\n");
				printf("5.���㵭����Ʊ�۸�\n");
				printf("6.�����þ�������ʱ��\n");
				printf("7.ѧ���ۿ���Ϣ\n");
				printf("8.�����ۿ���Ϣ\n");
				printf("9.��ͨ�ۿ���Ϣ\n");
				printf("10.���㼶��\n");
				printf("11.��������\n");
				printf("12.������������\n");
				printf("13.����ά������\n");
				printf("14.������Ʊ��\n");
				printf("15.���������\n");
				printf("16.�����Ƿ��������˶�ͯ\n");
				panduan=1;
				scanf("%d",&xuan);//ѡ��Ҫ�޸ĵ�ѡ�� 
				while(panduan!=0)//�ж������Ƿ�ϸ� 
				{
					switch(xuan)//Ҫ�޸ĵ�ѡ��
					{
						case 1:
							getchar();
							printf("����������Ϣ\n");
							panduan3=0; 
							while(panduan3==0)
							{ 
    							scanf("%s",b[num1].ScenicSpot_ID);
    							panduan3=1;
    							for(c=0;c<ScenicSpotNum;c++)
    							if(strcmp(b[num1].ScenicSpot_ID,ScenicSpotList[c].ScenicSpot_ID)==0)//�ж��Ƿ񾰵�ID�ظ� 
								{ 
    	    						printf("����ID�ظ�\n");
    	    						panduan3=0; 
    								printf("���������뾰��ID\n");
    							}
    						}
							strncpy(a[num1].ScenicSpot_ID,b[num1].ScenicSpot_ID,100);
							panduan=0;
							break;
						case 2:
							getchar();
							printf("����������Ϣ\n");
							panduan4=0;
							while(panduan4==0)
							{ 
    							scanf("%s",b[num1].ScenicSpot_NAME);
    							panduan4=1;
    							for(c=0;c<ScenicSpotNum;c++)
    							if(strcmp(b[num1].ScenicSpot_NAME,ScenicSpotList[c].ScenicSpot_NAME)==0)//�ж��Ƿ񾰵������ظ� 
								{ 
    								printf("���������ظ�");
    								panduan4=0;
    								printf("���������뾰������\n");
								}	
    						}
							strncpy(a[num1].ScenicSpot_NAME,b[num1].ScenicSpot_NAME,100);
							panduan=0;
							break;
						case 3:
							getchar();
							printf("����������Ϣ\n");
							scanf("%s",b[num1].ScenicSpot_INTRO);
							strncpy(a[num1].ScenicSpot_INTRO,b[num1].ScenicSpot_INTRO,100);
							panduan=0;
							break;
						case 4:
							scanf("%d",&b[num1].ScenicSpot_PRICE1);
							a[num1].ScenicSpot_PRICE1=b[num1].ScenicSpot_PRICE1;
							panduan=0;
							break;
						case 5:
							printf("����������Ϣ\n");
							scanf("%d",&b[num1].ScenicSpot_PRICE2); 
							a[num1].ScenicSpot_PRICE2=b[num1].ScenicSpot_PRICE2;
							panduan=0;
							break;
						case 6:
							getchar();
							printf("����������Ϣ\n");
							scanf("%s",b[num1].ScenicSpot_TIME); 
							strncpy(a[num1].ScenicSpot_TIME,b[num1].ScenicSpot_TIME,100);
							panduan=0;
							break;
						case 7:
							printf("����������Ϣ\n"); 
							scanf("%f",&b[num1].ScenicSpot_DISCOUNT1);
							a[num1].ScenicSpot_DISCOUNT1=b[num1].ScenicSpot_DISCOUNT1;
							panduan=0;
							break;
						case 8:
							printf("����������Ϣ\n");
							scanf("%f",&b[num1].ScenicSpot_DISCOUNT2);
							a[num1].ScenicSpot_DISCOUNT2=b[num1].ScenicSpot_DISCOUNT2;
							panduan=0;
							break; 
						case 9:
							printf("����������Ϣ\n");
							scanf("%f",&b[num1].ScenicSpot_DISCOUNT3);
							a[num1].ScenicSpot_DISCOUNT3=b[num1].ScenicSpot_DISCOUNT3;
							panduan=0;
							break; 
						case 10:
							printf("����������Ϣ\n");
							getchar();
							scanf("%s",b[num1].ScenicSpot_GRADE); 
							strncpy(a[num1].ScenicSpot_GRADE,b[num1].ScenicSpot_GRADE,100);
							panduan=0;
							break;
						case 11:
							printf("����������Ϣ\n");
							scanf("%s",b[num1].ScenicSpot_NUMBER); 
							strncpy(a[num1].ScenicSpot_NUMBER,b[num1].ScenicSpot_NUMBER,100);
							panduan=0;
							break;
						case 12:
							printf("����������Ϣ\n");
							getchar();
							scanf("%s",b[num1].ScenicSpot_AREA); 
							strncpy(a[num1].ScenicSpot_AREA,b[num1].ScenicSpot_AREA,100);
							panduan=0;
							break;
						case 13:
							printf("����������Ϣ\n");
							scanf("%d",&b[num1].ScenicSpot_COST);
							a[num1].ScenicSpot_COST=b[num1].ScenicSpot_COST;
							panduan=0;
							break;
						case 14:
							printf("����������Ϣ\n");
							scanf("%d",&b[num1].ScenicSpot_MENPIAO);
							a[num1].ScenicSpot_MENPIAO=b[num1].ScenicSpot_MENPIAO;
							panduan=0;
							break;
						case 15:
							printf("����������Ϣ\n");
							scanf("%f",&b[num1].ScenicSpot_HAOPING);	
							a[num1].ScenicSpot_HAOPING=b[num1].ScenicSpot_HAOPING;
							break;
						case 16:
							printf("����������Ϣ\n");
							getchar();
							scanf("%s",b[num1].ScenicSpot_LRET);
							strncpy(a[num1].ScenicSpot_LRET,b[num1].ScenicSpot_LRET,100);
							panduan=0;
							break;
						default:
							printf("������������д������������룺\n");
							scanf("%d",&xuan);
							break;
					}	
				}
				if(panduan==0)
				{
					printf("�Ƿ�����޸�\n1.��\t2.��\n");//�Ƿ�����޸� 
					scanf("%d",&panduan2); 
				}
			}
			while(panduan2==1); 
			printf("��ȷ���Ƿ񷢲�\n1.�� 2.��\n");//�޸�����Ϣ���Ƿ񷢲� 
			scanf("%d",&queding);
			if(queding==1)//���� 
			{
				fseek(fpa,0L,2);
				fwrite(&a[num1],sizeof(ScenicSpot),1,fpa);
			}
			else//������ 
			{
				fwrite(&ScenicSpotList[i],sizeof(ScenicSpot),1,fpb);
				remove("�����ϢԤ��.txt");
			}
		}
    	if(e==2)//ȡ������ 
		{
			fwrite(&a[num1],sizeof(ScenicSpot),1,fpb);
			remove("�����ϢԤ��.txt");
		}
    	if(e==3)//������Ϣ 
		{
			strncpy(ScenicSpotList[i].ScenicSpot_ID,a[num1].ScenicSpot_ID,100);
			strncpy(ScenicSpotList[i].ScenicSpot_NAME,a[num1].ScenicSpot_NAME,100);
			strncpy(ScenicSpotList[i].ScenicSpot_INTRO,a[num1].ScenicSpot_INTRO,100);
			ScenicSpotList[i].ScenicSpot_PRICE1=a[num1].ScenicSpot_PRICE1;
			ScenicSpotList[i].ScenicSpot_PRICE2=a[num1].ScenicSpot_PRICE2;
			strncpy(ScenicSpotList[i].ScenicSpot_TIME,a[num1].ScenicSpot_TIME,100);
			ScenicSpotList[i].ScenicSpot_DISCOUNT1=a[num1].ScenicSpot_DISCOUNT1;
			ScenicSpotList[i].ScenicSpot_DISCOUNT2=a[num1].ScenicSpot_DISCOUNT2;
			ScenicSpotList[i].ScenicSpot_DISCOUNT3=a[num1].ScenicSpot_DISCOUNT3;
			strncpy(ScenicSpotList[i].ScenicSpot_GRADE,a[num1].ScenicSpot_GRADE,100);
			strncpy(ScenicSpotList[i].ScenicSpot_NUMBER,a[num1].ScenicSpot_NUMBER,100);
			strncpy(ScenicSpotList[i].ScenicSpot_AREA,a[num1].ScenicSpot_AREA,100);
			ScenicSpotList[i].ScenicSpot_COST=a[num1].ScenicSpot_COST;
			ScenicSpotList[i].ScenicSpot_MENPIAO=a[num1].ScenicSpot_MENPIAO;
			ScenicSpotList[i].ScenicSpot_HAOPING=a[num1].ScenicSpot_HAOPING;
			strncpy(ScenicSpotList[i].ScenicSpot_LRET,a[num1].ScenicSpot_LRET,100);
			fseek(fpa,0L,2);
			fwrite(&ScenicSpotList[i],sizeof(ScenicSpot),1,fpa);
    	}
    	num1++;
    	ScenicSpotNum++;
		printf("�Ƿ��������µľ�����Ϣ\n1.��\t2.��\n");
		scanf("%d",&tianjia); 
	
	if(tianjia==1)
	tianjiajingdianxinxi();
	else
	fclose(fpa);
	fclose(fpb);
	
	    		printf("�������Ƿ���Ҫ����ʹ��ϵͳ��\n1.���ع��ܽ���\n2.�˳�\n");
	    		int choose1,panduan1=1;
		scanf("%d",&choose1);
	while(panduan1!=0)
	{
		switch(choose1)
		{
			case 1:
				guanliyuancaidan();
				panduan1=0;
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("������������д������������룺\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
    }
