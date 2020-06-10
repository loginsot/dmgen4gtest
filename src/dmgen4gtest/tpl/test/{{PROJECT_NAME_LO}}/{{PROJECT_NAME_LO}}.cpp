
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

void {{PROJECT_NAME_LO}}_DeathTest()
{
    ::testing::internal::Random oRand(time(0));

    for (size_t i = 0; i < 1000000; i++)
    {
        if (9999 == oRand.Generate(10000))
        {
            std::cerr << "DeathTest" << std::endl;
            exit(1);
        }
    }
}

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

TEST({{PROJECT_NAME_LO}}_DeathTest, DeathTest)
{
    EXPECT_EXIT({{PROJECT_NAME_LO}}_DeathTest(), ::testing::ExitedWithCode(1), "DeathTest");
}
