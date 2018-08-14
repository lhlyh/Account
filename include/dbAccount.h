#ifndef _DB_ACCOUNT_H_
#define _DB_ACCOUNT_H_
#include "stdio.h"

const int g_charLen = 50;
typedef struct tag_Date
{
    int    year;
    int    month;
    int    day;
}T_Date;
typedef struct tag_Accout
{
    char    accountName[g_charLen];
    char    billName[g_charLen];
    float   money;
    T_Date  creatTime;
    char    tag[g_charLen];
    char    comment[g_charLen];
    struct tag_Accout *next;
}T_Account;

int dbReadTXT();
int dbWriteTXT();
int dbBuffOffset(char *ptBuff, char cDelimit, char *ptStr, int *ptOffset);
int dbBuffToAccount(char *ptString, T_Account *ptAcount);

int dbDelAllAccount();
T_Account* dbGetptHead();

#endif
