#include "gtest/gtest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "dbAccount.h"
#include "funcCountAccount.h"
#include "common.h"

TEST(funcCountAccount, funcCountAllCount)
{
    dbReadTXT();
    ASSERT_EQ(2, funcCountAllAccount());
    dbDelAllAccount();
    ASSERT_EQ(0, funcCountAllAccount());
}

