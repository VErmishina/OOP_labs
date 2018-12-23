#include <iostream>
#include <cmath>
#include <math.h>
#include <gtest/gtest.h>

constexpr double polynom(double x) {
	return 3*x*x + 17*x - 5;
}

TEST(check_polynom, check_polynom) {
	EXPECT_EQ(15, polynom(1));
}

constexpr double Integrate (double bottom, double top, int32_t points_number, double (*function)(double x)){
	double sum = 0;
	double step = (top - bottom) / (points_number - 1);
	double current_point = bottom;
	for (int i = 0; i < points_number; ++i){
		double next_point = current_point + step;
		sum += (function(current_point) + function(next_point));
		current_point = next_point;
	}
	sum = sum * step / 2;

	return sum;
}

TEST(Integration, Integration) {
	EXPECT_LT(4, Integrate(0, 1, 100, polynom));
	EXPECT_GT(5, Integrate(0, 1, 100, polynom));
}

int main(int argc, char** argv) {
	constexpr auto integral = Integrate(0, 10, 300, polynom);
	std::cout << "integral = " << integral << std::endl;
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
