
#include "gtest.h"

class env_{{PROJECT_NAME_LO}}
{
public:
    void init(){}
    void uninit(){}
};

class frame_{{PROJECT_NAME_LO}} : public testing::Test
{
public:
    virtual void SetUp()
    {
        env.init();
    }
    virtual void TearDown()
    {
        env.uninit();
    }
protected:
    env_{{PROJECT_NAME_LO}} env;
};

TEST_F(frame_{{PROJECT_NAME_LO}}, init)
{
    ASSERT_TRUE(1);
    ASSERT_EQ(1, 1);
    ASSERT_FALSE(0);
}

TEST_F(frame_{{PROJECT_NAME_LO}}, create)
{

}

TEST_F(frame_{{PROJECT_NAME_LO}}, do_action)
{

}