#include "funcCountAccount.h"

#include "dbAccount.h"

int funcCountAllAccount()
{
    int count = 0;
    T_Account *ptAccount = NULL;
    ptAccount = dbGetptHead();
    for(; ptAccount != NULL; )
    {
        count++;
        ptAccount = ptAccount->next;
    }
    return count;
}

int funcCountAccountByDate(int year, int month)
{
    T_Account *ptAccount = NULL;
    ptAccount = dbGetptHead();
    for(; ptAccount != NULL; )
    {
        ptAccount = ptAccount->next;
    }
    return 0;
}
