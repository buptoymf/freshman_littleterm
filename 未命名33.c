#include <stdio.h>
 
int main()
{
    FILE *pf = fopen("dingdan.txt", "r"); // ���ļ�
    char buf[1000];
    int lineCnt = 0;
    if (!pf) // �ж��Ƿ�򿪳ɹ�
        return -1;
    while (fgets(buf, 1000, pf)) // fgetsѭ����ȡ��ֱ���ļ���󣬲Ż᷵��NULL
        lineCnt++; // �ۼ�����
    fclose(pf);
    printf("file line count = %d\n", lineCnt);
    return 0;
}
