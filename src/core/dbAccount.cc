#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dbAccount.h"

const char g_ptfile[] = "account.txt";
T_Account *g_ptHeadAccount = NULL;

int dbReadTXT()
{
    FILE *fpRead = fopen(g_ptfile, "r");
    if(NULL == fpRead)
    {
        printf("dbReadTXT::account.txt is not exist\n");
        return 1;
    }
    T_Account *ptAccountMalloc = NULL;
    T_Account *ptAccountTemp = NULL;
    char buff[500] = {0};
    while(!feof(fpRead))
    {
        memset(buff, 0, sizeof(buff));
        fgets(buff, sizeof(buff), fpRead);
        // 做一下数据长度保护，最后一行为换行符之后的空行
        if(strlen(buff) < 10)
        {
            break;
        }
        // 将新的数据作为链表头，写出来的代码比较简洁，但会导致读出来的数据倒序
        ptAccountMalloc = (T_Account *)malloc(sizeof(T_Account));
        memset(ptAccountMalloc, 0, sizeof(ptAccountMalloc));
        ptAccountMalloc->next = ptAccountTemp;
        dbBuffToAccount(buff, ptAccountMalloc);        
        ptAccountTemp = ptAccountMalloc;
    }
    g_ptHeadAccount = ptAccountTemp;
    fclose(fpRead);
    return 0;
}
int dbWriteTXT()
{
    FILE *fpWrite = fopen(g_ptfile, "w");

    T_Account *ptTemp = g_ptHeadAccount;
    for(; ptTemp != NULL; )
    {   
        fprintf(fpWrite, "%s,", ptTemp->accountName);
        fprintf(fpWrite, "%s,", ptTemp->billName);
        fprintf(fpWrite, "%f,", ptTemp->money);
        fprintf(fpWrite, "%s,", ptTemp->creatTime);
        fprintf(fpWrite, "%s,", ptTemp->tag);
        fprintf(fpWrite, "%s\n", ptTemp->comment);
        ptTemp = ptTemp->next;
    }
    return 0;
}

int dbDelAllAccount()
{
    T_Account *ptTemp;
    if(NULL == g_ptHeadAccount)
    {
        return 0;
    }

    for(; NULL != g_ptHeadAccount; )
    {
        ptTemp = g_ptHeadAccount;
        g_ptHeadAccount = g_ptHeadAccount->next;
        free(ptTemp);
    }
    return 0;
}

int dbBuffOffset(char *ptBuff, char cDelimit, char *ptStr, int *ptOffset)
{
    int i = 0;
    for(i = 0; ptBuff[i] != cDelimit; i++)
    {
        ptStr[i] = ptBuff[i];
    }
    ptStr[i] = '\0';
    *ptOffset = (*ptOffset) + i + 1;    
    return 0;
}
int dbBuffToAccount(char *ptBuff, T_Account *ptAcount)
{
    int dwOffset = 0;
    char ucMoney[100] = {0};
    
    dbBuffOffset(&ptBuff[dwOffset], ',', ptAcount->accountName, &dwOffset);
    dbBuffOffset(&ptBuff[dwOffset], ',', ptAcount->billName, &dwOffset);
    dbBuffOffset(&ptBuff[dwOffset], ',', ucMoney, &dwOffset);
    ptAcount->money = atof(ucMoney);
    dbBuffOffset(&ptBuff[dwOffset], ',', ptAcount->creatTime, &dwOffset);
    dbBuffOffset(&ptBuff[dwOffset], ',', ptAcount->tag, &dwOffset);
    dbBuffOffset(&ptBuff[dwOffset], '\n', ptAcount->comment, &dwOffset);
    
    return 0;
}

T_Account* dbGetptHead()
{
    // 其他文件要使用头指针都通过这个函数调用，不必使用extern全局变量
    return g_ptHeadAccount;
}