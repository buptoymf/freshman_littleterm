void  addScenicSpot()
{
        FILE  *fp;
        fp=fopen("景点信息.txt","ab+");        
        for(int i=0;fread(&ScenicSpotList[NUMBER],sizeof(struct  ScenicSpot),1,fp)==1;i++);
        int N;
        printf("请输入要添加的景点信息数目：");
        scanf("%d", &N); 
        for(int i = 0; i < N; i++)
		{	printf("请输入要增加的景点ID、景点名称、景点简介、景点旺季门票价格、景点淡季门票价格、游览该景点所需时间、学生折扣信息、军人折扣信息、普通折扣信息、景点级别、人数限制、景点所属区域、景点维护费用:\n");
            scanf("%s%s%s%d%d%s%f%f%f%s%s%s%s",ScenicSpot_ID[i],ScenicSpot_NAME[80],ScenicSpot_INTRO[80],&ScenicSpot_PRICE1,&ScenicSpot_PRICE2,ScenicSpot_TIME[80],&ScenicSpot_DISCOUNT1,&ScenicSpot_DISCOUNT2,&ScenicSpot_DISCOUNT3,ScenicSpot_GRADE[80],ScenicSpot_NUMBER[80],ScenicSpot_AREA[80],ScenicSpot_COST[80]);
            fwrite(&ScenicSpotList[NUMBER],sizeof(struct  ScenicSpot),1,fp);
            }
        fclose(fp);
        return;
    }
