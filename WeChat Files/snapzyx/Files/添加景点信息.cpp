void  addScenicSpot()
{
        FILE  *fp;
        fp=fopen("������Ϣ.txt","ab+");        
        for(int i=0;fread(&ScenicSpotList[NUMBER],sizeof(struct  ScenicSpot),1,fp)==1;i++);
        int N;
        printf("������Ҫ��ӵľ�����Ϣ��Ŀ��");
        scanf("%d", &N); 
        for(int i = 0; i < N; i++)
		{	printf("������Ҫ���ӵľ���ID���������ơ������顢����������Ʊ�۸񡢾��㵭����Ʊ�۸������þ�������ʱ�䡢ѧ���ۿ���Ϣ�������ۿ���Ϣ����ͨ�ۿ���Ϣ�����㼶���������ơ������������򡢾���ά������:\n");
            scanf("%s%s%s%d%d%s%f%f%f%s%s%s%s",ScenicSpot_ID[i],ScenicSpot_NAME[80],ScenicSpot_INTRO[80],&ScenicSpot_PRICE1,&ScenicSpot_PRICE2,ScenicSpot_TIME[80],&ScenicSpot_DISCOUNT1,&ScenicSpot_DISCOUNT2,&ScenicSpot_DISCOUNT3,ScenicSpot_GRADE[80],ScenicSpot_NUMBER[80],ScenicSpot_AREA[80],ScenicSpot_COST[80]);
            fwrite(&ScenicSpotList[NUMBER],sizeof(struct  ScenicSpot),1,fp);
            }
        fclose(fp);
        return;
    }
