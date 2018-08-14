#include "gtest/gtest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "dbAccount.h"
#include "common.h"

TEST(dbAccount, read_print_write_del_print)
{
    dbReadTXT();
    printfAllAccount();
    dbWriteTXT();
    dbDelAllAccount();
    printfAllAccount();
    
}
