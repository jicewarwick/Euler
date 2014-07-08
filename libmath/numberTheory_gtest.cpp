#include "numberTheory.h"
#include <gtest/gtest.h>

TEST(PrimeTest, PositiveTest){
	ASSERT_EQ(0, isPrime(1));
	ASSERT_EQ(1, isPrime(2));
	ASSERT_EQ(1, isPrime(3));
	ASSERT_EQ(0, isPrime(45));
	ASSERT_EQ(0, isPrime(0));
}

TEST(OddEvenTest, OddTest){
	ASSERT_EQ(0, isOdd(0));
	ASSERT_EQ(0, isOdd(2));
	ASSERT_EQ(0, isOdd(8));
	ASSERT_EQ(1, isOdd(3));


}

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
