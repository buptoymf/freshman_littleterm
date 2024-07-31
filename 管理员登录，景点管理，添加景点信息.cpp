     void tianjiajingdianxinxi()
{
    FILE  *fpa;
    FILE  *fpb;
    int i=0;
    int c=0;
    int num1=0; 
    int ScenicSpotNum=8;//景点数量 
    int panduan=1;//判断是否输入正确 
    int panduan2;//判断是否继续修改
	int panduan3=0;//判断景点ID是否正确
	int panduan4=0;//判断景点名称是否正确 
	int e;//景点信息是否有误 
    int xuan;//选择要修改的信息
	int tianjia;//添加新的信息
	int queding;//是否发布
	int discount1=1,discount2=1,discount3=1;//判断折扣信息输入是否合格 
	int menpiao;//判断门票信息是否输入合格 
    struct  ScenicSpot a[80];//暂存信息 
    struct  ScenicSpot b[80];//暂存信息
    //打开并读取文件信息 
    fpa=fopen("景点信息.txt","a+");
	fpb=fopen("添加信息预存.txt","a+");        
    for(i=0;i<ScenicSpotNum;i++)
    fread(&ScenicSpotList[i],sizeof(struct  ScenicSpot),1,fpa);
    
		//输入新的景点信息 
        printf("请输入景点ID\n");
		while(panduan3==0)
		{
			getchar(); 
    		scanf("%s",a[num1].ScenicSpot_ID);
    		panduan3=1;
    		for(c=0;c<ScenicSpotNum;c++)
    		if(strcmp(a[num1].ScenicSpot_ID,ScenicSpotList[c].ScenicSpot_ID)==0)//判断是否景点ID重复 
			{ 
    	    	printf("景点ID重复\n");
    	    	panduan3=0; 
    			printf("请重新输入景点ID\n");
    		}
    	}
    	printf("请输入景点名称\n");
    	while(panduan4==0)
		{
    		scanf("%s",a[num1].ScenicSpot_NAME);
    		panduan4=1;
    		for(c=0;c<ScenicSpotNum;c++)
    		if(strcmp(a[num1].ScenicSpot_NAME,ScenicSpotList[c].ScenicSpot_NAME)==0)//判断是否景点名称重复 
			{ 
    			printf("景点名字重复\n");
    			panduan4=0;
    			printf("请重新输入景点名称\n");
			}	
    	}
    	printf("请输入景点简介\n");
    	scanf("%s",a[num1].ScenicSpot_INTRO);
    	printf("请输入景点旺季门票价格\n");
    	scanf("%d",&a[num1].ScenicSpot_PRICE1);
    	printf("请输入景点淡季门票价格\n");
    	scanf("%d",&a[num1].ScenicSpot_PRICE2);
    	getchar();
    	printf("请输入游览该景点所需时间\n");
    	scanf("%s",a[num1].ScenicSpot_TIME);
    	printf("请输入学生折扣信息\n");
    	do
    	{
    		discount1=1;
    		scanf("%f",&a[num1].ScenicSpot_DISCOUNT1);
    		if(a[num1].ScenicSpot_DISCOUNT1>1)//判断折扣信息输入是否合格
    		{
    			discount1=0;
    			printf("折扣信息输入不合格。请重新输入\n");
    		}
    	}
    	while(discount1==0);
    	printf("请输入军人折扣信息\n");
    	do
    	{
    		discount2=1;
    		scanf("%f",&a[num1].ScenicSpot_DISCOUNT1);
    		if(a[num1].ScenicSpot_DISCOUNT1>1)//判断折扣信息输入是否合格
    		{
    			discount2=0;
    			printf("折扣信息输入不合格。请重新输入\n");
    		}
    	}
    	while(discount2==0);
    	printf("请输入普通折扣信息\n");
    	do
    	{
    		discount3=1;
    		scanf("%f",&a[num1].ScenicSpot_DISCOUNT3);
    		if(a[num1].ScenicSpot_DISCOUNT3>1)//判断折扣信息输入是否合格
    		{
    			discount3=0;
    			printf("折扣信息输入不合格。请重新输入\n");
    		}
    	}
    	while(discount3==0);
    	getchar();
    	printf("请输入景点级别\n");
    	scanf("%s",a[num1].ScenicSpot_GRADE);
    	printf("请输入人数限制\n");
    	scanf("%s",a[num1].ScenicSpot_NUMBER);
    	printf("请输入景点所属区域\n");
    	scanf("%s",a[num1].ScenicSpot_AREA);
    	printf("请输入景点维护费用\n");
    	scanf("%d",&a[num1].ScenicSpot_COST);
    	printf("请输入景点总票数\n");
    	do
    	{
    		menpiao=1;
    		scanf("%d",&a[num1].ScenicSpot_MENPIAO);
    		if(a[num1].ScenicSpot_MENPIAO<0)//判断门票信息是否输入合格
    		{
    			menpiao=0;
    			printf("输入不合格。请重新输入\n");
    		}
    	}
    	while(menpiao==0);
    	printf("请输入景点好评率\n");
    	scanf("%f",&a[num1].ScenicSpot_HAOPING);
    	printf("请输入景点是否适宜老人儿童\n");
    	getchar();
    	scanf("%s",a[num1].ScenicSpot_LRET); 
    	printf("请确认景点信息是否有误\n1.修改\n2.取消添加\n3.发布\n");
    	scanf("%d",&e);
    	if(e==1)
		{
			i++;
			do
			{
				printf("请选择要修改的信息\n");
				printf("1.景点ID\n");
				printf("2.景点名称\n");
				printf("3.景点简介\n");
				printf("4.景点旺季门票价格\n");
				printf("5.景点淡季门票价格\n");
				printf("6.游览该景点所需时间\n");
				printf("7.学生折扣信息\n");
				printf("8.军人折扣信息\n");
				printf("9.普通折扣信息\n");
				printf("10.景点级别\n");
				printf("11.人数限制\n");
				printf("12.景点所属区域\n");
				printf("13.景点维护费用\n");
				printf("14.景点总票数\n");
				printf("15.景点好评率\n");
				printf("16.景点是否适宜老人儿童\n");
				panduan=1;
				scanf("%d",&xuan);//选择要修改的选项 
				while(panduan!=0)//判断输入是否合格 
				{
					switch(xuan)//要修改的选项
					{
						case 1:
							getchar();
							printf("请输入新信息\n");
							panduan3=0; 
							while(panduan3==0)
							{ 
    							scanf("%s",b[num1].ScenicSpot_ID);
    							panduan3=1;
    							for(c=0;c<ScenicSpotNum;c++)
    							if(strcmp(b[num1].ScenicSpot_ID,ScenicSpotList[c].ScenicSpot_ID)==0)//判断是否景点ID重复 
								{ 
    	    						printf("景点ID重复\n");
    	    						panduan3=0; 
    								printf("请重新输入景点ID\n");
    							}
    						}
							strncpy(a[num1].ScenicSpot_ID,b[num1].ScenicSpot_ID,100);
							panduan=0;
							break;
						case 2:
							getchar();
							printf("请输入新信息\n");
							panduan4=0;
							while(panduan4==0)
							{ 
    							scanf("%s",b[num1].ScenicSpot_NAME);
    							panduan4=1;
    							for(c=0;c<ScenicSpotNum;c++)
    							if(strcmp(b[num1].ScenicSpot_NAME,ScenicSpotList[c].ScenicSpot_NAME)==0)//判断是否景点名称重复 
								{ 
    								printf("景点名字重复");
    								panduan4=0;
    								printf("请重新输入景点名称\n");
								}	
    						}
							strncpy(a[num1].ScenicSpot_NAME,b[num1].ScenicSpot_NAME,100);
							panduan=0;
							break;
						case 3:
							getchar();
							printf("请输入新信息\n");
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
							printf("请输入新信息\n");
							scanf("%d",&b[num1].ScenicSpot_PRICE2); 
							a[num1].ScenicSpot_PRICE2=b[num1].ScenicSpot_PRICE2;
							panduan=0;
							break;
						case 6:
							getchar();
							printf("请输入新信息\n");
							scanf("%s",b[num1].ScenicSpot_TIME); 
							strncpy(a[num1].ScenicSpot_TIME,b[num1].ScenicSpot_TIME,100);
							panduan=0;
							break;
						case 7:
							printf("请输入新信息\n"); 
							scanf("%f",&b[num1].ScenicSpot_DISCOUNT1);
							a[num1].ScenicSpot_DISCOUNT1=b[num1].ScenicSpot_DISCOUNT1;
							panduan=0;
							break;
						case 8:
							printf("请输入新信息\n");
							scanf("%f",&b[num1].ScenicSpot_DISCOUNT2);
							a[num1].ScenicSpot_DISCOUNT2=b[num1].ScenicSpot_DISCOUNT2;
							panduan=0;
							break; 
						case 9:
							printf("请输入新信息\n");
							scanf("%f",&b[num1].ScenicSpot_DISCOUNT3);
							a[num1].ScenicSpot_DISCOUNT3=b[num1].ScenicSpot_DISCOUNT3;
							panduan=0;
							break; 
						case 10:
							printf("请输入新信息\n");
							getchar();
							scanf("%s",b[num1].ScenicSpot_GRADE); 
							strncpy(a[num1].ScenicSpot_GRADE,b[num1].ScenicSpot_GRADE,100);
							panduan=0;
							break;
						case 11:
							printf("请输入新信息\n");
							scanf("%s",b[num1].ScenicSpot_NUMBER); 
							strncpy(a[num1].ScenicSpot_NUMBER,b[num1].ScenicSpot_NUMBER,100);
							panduan=0;
							break;
						case 12:
							printf("请输入新信息\n");
							getchar();
							scanf("%s",b[num1].ScenicSpot_AREA); 
							strncpy(a[num1].ScenicSpot_AREA,b[num1].ScenicSpot_AREA,100);
							panduan=0;
							break;
						case 13:
							printf("请输入新信息\n");
							scanf("%d",&b[num1].ScenicSpot_COST);
							a[num1].ScenicSpot_COST=b[num1].ScenicSpot_COST;
							panduan=0;
							break;
						case 14:
							printf("请输入新信息\n");
							scanf("%d",&b[num1].ScenicSpot_MENPIAO);
							a[num1].ScenicSpot_MENPIAO=b[num1].ScenicSpot_MENPIAO;
							panduan=0;
							break;
						case 15:
							printf("请输入新信息\n");
							scanf("%f",&b[num1].ScenicSpot_HAOPING);	
							a[num1].ScenicSpot_HAOPING=b[num1].ScenicSpot_HAOPING;
							break;
						case 16:
							printf("请输入新信息\n");
							getchar();
							scanf("%s",b[num1].ScenicSpot_LRET);
							strncpy(a[num1].ScenicSpot_LRET,b[num1].ScenicSpot_LRET,100);
							panduan=0;
							break;
						default:
							printf("您输入的数据有错误，请重新输入：\n");
							scanf("%d",&xuan);
							break;
					}	
				}
				if(panduan==0)
				{
					printf("是否继续修改\n1.是\t2.否\n");//是否继续修改 
					scanf("%d",&panduan2); 
				}
			}
			while(panduan2==1); 
			printf("请确定是否发布\n1.是 2.否\n");//修改完信息后是否发布 
			scanf("%d",&queding);
			if(queding==1)//发布 
			{
				fseek(fpa,0L,2);
				fwrite(&a[num1],sizeof(ScenicSpot),1,fpa);
			}
			else//不发布 
			{
				fwrite(&ScenicSpotList[i],sizeof(ScenicSpot),1,fpb);
				remove("添加信息预存.txt");
			}
		}
    	if(e==2)//取消发布 
		{
			fwrite(&a[num1],sizeof(ScenicSpot),1,fpb);
			remove("添加信息预存.txt");
		}
    	if(e==3)//发布信息 
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
		printf("是否继续添加新的景点信息\n1.是\t2.否\n");
		scanf("%d",&tianjia); 
	
	if(tianjia==1)
	tianjiajingdianxinxi();
	else
	fclose(fpa);
	fclose(fpb);
	
	    		printf("请问您是否需要继续使用系统？\n1.返回功能界面\n2.退出\n");
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
				printf("您输入的数据有错误，请重新输入：\n");
				scanf("%d",&choose1);
				break;
		}
	}
	return;
    }
