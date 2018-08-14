#include "common.h"
#include "string.h"
#include <stdlib.h>
int StrToNum(const char *ptstr, int *offset)
{
    int i = 0;
    int num = 0;
    for(i = *offset; ptstr[i] >= '0' && ptstr[i] <= '9'; i++)
    {
        num = num * 10 + ptstr[i] - '0';
    }
    *offset = i + 1;
    return num;
}

int StrToDate(const char *ptStr, T_Date *ptDate)
{
    if(NULL == ptStr || NULL == ptDate)
    {
        return 1;
    }
    int offset = 0;
    ptDate->year = StrToNum(ptStr, &offset);
    ptDate->month = StrToNum(ptStr, &offset);
    ptDate->day = StrToNum(ptStr, &offset);

    if(0 == ptDate->year || 0 == ptDate->month || ptDate->day == 0)
    {
        return 1;
    }
    return 0;
}

int DateToStr(T_Date tDate, char *ptStr)
{
    if(NULL == ptStr)
    {
        return 1;
    }
    char cYear[5];
    char cMonth[3];
    char cDay[3];
    itoa(tDate.year, cYear, 10);
    itoa(tDate.month, cMonth, 10);
    itoa(tDate.day, cDay, 10);

    strcat(ptStr, cYear);
    strcat(ptStr, "-");
    strcat(ptStr, cMonth);
    strcat(ptStr, "-");
    strcat(ptStr, cDay);
    return 0;
}

int printfAccount(T_Account *ptAccount)
{    
    char date[30]={0};
    printf("%s,", ptAccount->accountName);
    printf("%s,", ptAccount->billName);
    printf("%f,", ptAccount->money);
    DateToStr(ptAccount->creatTime, date);
    printf("%s,", date);
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



