#include "TestFramework.h"
#include "Assertions.h"
#include "String.h"

TEST(String_Default)
{
    String s;
    EXPECT_EQ(s.size(), 0);
}

TEST(String_Find)
{
    String s = "hello";
    EXPECT_EQ(s.find('e'), 1);
}

int main()
{
    TestRegistry::instance().run();
}