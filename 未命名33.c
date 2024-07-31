#include <stdio.h>
 
int main()
{
    FILE *pf = fopen("dingdan.txt", "r"); // 打开文件
    char buf[1000];
    int lineCnt = 0;
    if (!pf) // 判断是否打开成功
        return -1;
    while (fgets(buf, 1000, pf)) // fgets循环读取，直到文件最后，才会返回NULL
        lineCnt++; // 累计行数
    fclose(pf);
    printf("file line count = %d\n", lineCnt);
    return 0;
}
