#include <gtest/gtest.h>

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(PrjCrtTest, given_nothing_when_crtprj_expect_ok)
{
    printf("Gtest OK\n");
}