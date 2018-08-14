#include "common.h"

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
    T_Account *ptHeadAccount = NULL;
    ptHeadAccount = dbGetptHead();
    if(NULL == ptHeadAccount)
    {
        printf("%s\n", "账本为空！\n");
        return 1;
    }
    printf("======================================\n");
    for(; ptHeadAccount != NULL; )
    {
        printfAccount(ptHeadAccount);
        ptHeadAccount = ptHeadAccount->next;
    }
    printf("======================================\n");
    return 0;
}



