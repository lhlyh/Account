#ifndef _COMMON_H_
#define _COMMON_H_

#include "dbAccount.h"

int printfAccount(T_Account *tAccount);
int printfAllAccount();
int StrToDate(const char *ptStr, T_Date *ptDate);
int DateToStr(T_Date tDate, char *ptStr);



#endif
