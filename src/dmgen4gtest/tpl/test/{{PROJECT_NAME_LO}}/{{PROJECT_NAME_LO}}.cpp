
#include "gtest.h"

class env_{{PROJECT_NAME}} : public testing::Test
{
public:
    virtual void SetUp()
    {

    }
    virtual void TearDown()
    {

    }
protected:

}

TEST_F(env_{{PROJECT_NAME}}, init)
{
    ASSERT_TRUE(1);
    ASSERT_EQ(1, 1);
    ASSERT_FALSE(0);
}

TEST_F(env_{{PROJECT_NAME}}, create)
{

}

TEST_F(env_{{PROJECT_NAME}}, do_action)
{

}