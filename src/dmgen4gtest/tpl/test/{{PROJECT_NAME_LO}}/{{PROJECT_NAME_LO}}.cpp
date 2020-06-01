
#include "gtest.h"

class env_{{PROJECT_NAME}}
{
public:
    void init(){}
    void uninit(){}
};

class frame_{{PROJECT_NAME}} : public testing::Test
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
    env_{{PROJECT_NAME}} env;
};

TEST_F(frame_{{PROJECT_NAME}}, init)
{
    ASSERT_TRUE(1);
    ASSERT_EQ(1, 1);
    ASSERT_FALSE(0);
}

TEST_F(frame_{{PROJECT_NAME}}, create)
{

}

TEST_F(frame_{{PROJECT_NAME}}, do_action)
{

}