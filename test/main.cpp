#include <gtest/gtest.h>

#include <readargs.hpp>

// Проба
TEST(TestArguments, Reading) {
    char* a[11] = {"",   "-qwerty", "123", "-zxcvbnm", "-photo", "yeeees",
                   "no", "-one",    "two", "hello",    "-aboba"};
    ArgStore args = ArgStore(11, a);

    ArgMap ref_map = {
        {"-qwerty", "123"}, {"-photo", "yeeees"}, {"-one", "two"}};
    for (auto& [k, m] : args.arg_map()) {
        ASSERT_EQ(ref_map[k], m);
    }

    LonelyVec ref_lonely_flags = {"-zxcvbnm", "-aboba"};
    ASSERT_EQ(ref_lonely_flags.size(), args.lonely_flags().size());
    for (size_t i = 0; i < ref_lonely_flags.size(); i++) {
        ASSERT_EQ(ref_lonely_flags[i], args.lonely_flags()[i]);
    }

    LonelyVec ref_lonely_values = {"no", "hello"};
    ASSERT_EQ(ref_lonely_values.size(), args.lonely_values().size());
    for (size_t i = 0; i < ref_lonely_values.size(); i++) {
        ASSERT_EQ(ref_lonely_values[i], args.lonely_values()[i]);
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
