#include "readWriteTXT.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char g_ptfile[] = "account.txt";
T_Account *g_ptHeadAccount = NULL;

int dbReadTXT()
{
    FILE *fpRead = fopen(g_ptfile, "r");
    if(NULL == fpRead)
    {
        printf("account.txt is not exist\n");
        return 1;
    }    
    T_Account *ptAccountMalloc = NULL;
    T_Account *ptAccountTemp = NULL;
    char buff[500] = {0};
    while(!feof(fpRead))
    {
        memset(buff, 0, sizeof(buff));
        fgets(buff, sizeof(buff), fpRead);
        if(strlen(buff) < 10)
        {
            break;
        }
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

int delAllAccount()
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
    // printf("%d, %s", *ptOffset, ptBuff);
    int i = 0;
    for(i = 0; ptBuff[i] != cDelimit; i++)
    {
        ptStr[i] = ptBuff[i];
    }
    *ptOffset = (*ptOffset) + i + 1;    
    return 0;
}
int dbBuffToAccount(char *ptBuff, T_Account *ptAcount)
{
    int dwOffset = 0;
    char ucMoney[50] = {0};
    
    dbBuffOffset(&ptBuff[dwOffset], ',', ptAcount->accountName, &dwOffset);
    dbBuffOffset(&ptBuff[dwOffset], ',', ptAcount->billName, &dwOffset);
    dbBuffOffset(&ptBuff[dwOffset], ',', ucMoney, &dwOffset);
    ptAcount->money = atof(ucMoney);
    dbBuffOffset(&ptBuff[dwOffset], ',', ptAcount->creatTime, &dwOffset);
    dbBuffOffset(&ptBuff[dwOffset], ',', ptAcount->tag, &dwOffset);
    dbBuffOffset(&ptBuff[dwOffset], '\n', ptAcount->comment, &dwOffset);
    
    return 0;
}

int printfAccount(T_Account *ptAccount)
{    
    printf("%s,", ptAccount->accountName);
    printf("%s,", ptAccount->billName);
    printf("%f,", ptAccount->money);
    printf("%s,", ptAccount->creatTime);
    printf("%s,", ptAccount->tag);
    printf("%s\n", ptAccount->comment);
    return 0;
}
int printfAllAccount()
{
    if(NULL == g_ptHeadAccount)
    {
        printf("%s\n", "账本为空！\n");
        return 1;
    }
    T_Account *ptTemp = g_ptHeadAccount;
    printf("======================================\n");
    for(; ptTemp != NULL; )
    {
        printfAccount(ptTemp);
        ptTemp = ptTemp->next;
    }
    printf("======================================\n");
    return 0;
}

