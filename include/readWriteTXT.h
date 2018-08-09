#ifndef _READ_WRITE_TXT_H_
#define _READ_WRITE_TXT_H_
#include "stdio.h"

const int g_charLen = 50;
typedef struct tag_Accout
{
    char    accountName[g_charLen];
    char    billName[g_charLen];
    float   money;
    char    creatTime[g_charLen];
    char    tag[g_charLen];
    char    comment[g_charLen];
    struct tag_Accout *next;
}T_Account;


int dbBuffToAccount(char *ptString, T_Account *ptAcount);
int printfAccount(T_Account *tAccount);
int printfAllAccount();
int dbReadTXT();
int dbWriteTXT();
int delAllAccount();

#endif