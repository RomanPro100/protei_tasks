#include <gtest/gtest.h>

#include <readargs.hpp>

// Проба
TEST(TestGroupName, Subtest_1) { ASSERT_TRUE(1 == 1); }

TEST(TestGroupName, Subtest_2) {
    ASSERT_FALSE('b' == 'b');
    std::cout << "continue test after failure" << std::endl;
}

int main(int argc, char** argv) {
    ArgStore args = ArgStore(argc, argv);
    for (auto& [k, m] : args.getArgMap()) {
        std::cout << "Флаг: " << k << ", значение: " << m << std::endl;
    }
    std::cout << "Одинокие флаги: ";
    for (std::string e : args.getLonelyFlags()) {
        std::cout << e << ", ";
    }
    std::cout << std::endl << "Одинокие значения: ";
    for (std::string e : args.getLonelyValues()) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
