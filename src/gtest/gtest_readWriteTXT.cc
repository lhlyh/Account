#include "gtest/gtest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "readWriteTXT.h"
#include "common.h"

TEST(writeAccountTest, test1)
{
//    char ptString[] = "总账单,饭卡充值,100,2016-11-06,,\n";
//    T_Account *ptAcount;
//    ptAcount = (T_Account *)malloc(sizeof(T_Account));
//    memset(ptAcount, 0, sizeof(ptAcount));
//
//    dbBuffToAccount(ptString, ptAcount);
//    
//    printf("======================================\n");
//    printfAccount(ptAcount);
//    printf("======================================\n");
}

TEST(readTXTTest, test2)
{
//    dbReadTXT();
//    printfAllAccount();
}
TEST(writeTXTTest, test2)
{
    dbReadTXT();
    printfAllAccount();
    dbWriteTXT();
    dbDelAllAccount();
    printfAllAccount();
    
}
