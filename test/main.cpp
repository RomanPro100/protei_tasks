#include <gtest/gtest.h>

#include <readargs.hpp>

// Проба
TEST(TestArguments, Reading) {
    char* a[11] = {"",   "-qwerty", "123", "-zxcvbnm", "-photo", "yeeees",
                   "no", "-one",    "two", "hello",    "-aboba"};
    ArgStore args = ArgStore(11, a);

    ArgMap refMap = {{"-qwerty", "123"}, {"-photo", "yeeees"}, {"-one", "two"}};
    for (auto& [k, m] : args.getArgMap()) {
        ASSERT_EQ(refMap[k], m);
    }

    LonelyVec refLonelyFlags = {"-zxcvbnm", "-aboba"};
    ASSERT_EQ(refLonelyFlags.size(), args.getLonelyFlags().size());
    for (size_t i = 0; i < refLonelyFlags.size(); i++) {
        ASSERT_EQ(refLonelyFlags[i], args.getLonelyFlags()[i]);
    }

    LonelyVec refLonelyValues = {"no", "hello"};
    ASSERT_EQ(refLonelyValues.size(), args.getLonelyValues().size());
    for (size_t i = 0; i < refLonelyValues.size(); i++) {
        ASSERT_EQ(refLonelyValues[i], args.getLonelyValues()[i]);
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
