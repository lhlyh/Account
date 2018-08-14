#include "gtest/gtest.h"

#include "common.h"
#include "dbAccount.h"

TEST(common, StrToDate_right)
{
    const char *ptStr = "2018-12-12";
    T_Date tDate;
    StrToDate(ptStr, &tDate);
    
    ASSERT_EQ(2018, tDate.year);
    ASSERT_EQ(12, tDate.month);
    ASSERT_EQ(12, tDate.day);
}

TEST(common, StrToDate_NULL)
{
    const char *ptStr = "2018-1-2";
    T_Date *tDate = NULL;
    ASSERT_EQ(1, StrToDate(ptStr, tDate));
}

TEST(common, StrToDate_Wrong)
{
    const char *ptStr = "2018-12-";
    T_Date tDate;
    
    ASSERT_EQ(1, StrToDate(ptStr, &tDate));
}

TEST(common, DateToStr)
{
    char ptStr[10];
    T_Date tDate;
    tDate.year = 2018;
    tDate.month = 1;
    tDate.day = 21;
    DateToStr(tDate, ptStr);
    printf("%s\n", ptStr);
//    ASSERT_EQ("2018-1-21", DateToStr(tDate, ptStr));
}

