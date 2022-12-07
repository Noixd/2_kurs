#include "gtest/gtest.h"
#include "../../Project10/Project10/class.cpp"

TEST(Admin, tets_self) {
	Admin ad1("Bll", 4, 56);
	EXPECT_NE(ad1.Get_self(), 0);
}

TEST(Admin, test_div) {
	Admin ad1;
	EXPECT_NE(ad1.Div(), 0);
}

TEST(Junior, tets_self) {
	Junior Jr1("Smm", 15, 67, 2);
	EXPECT_NE(Jr1.Get_self(), 0);
}

TEST(Junior, test_div) {
	Junior Jr1;
	EXPECT_NE(Jr1.Div(), 0);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	if (!RUN_ALL_TESTS())
		std::cout << "All Tests are Passed." << std::endl;
	else
		std::cerr << "One or more tests FAILED!" << std::endl;
	std::cin.get();

	try {
		Admin a2("Smith", 7, 6);
	}
	catch (ZDivExcept exception) {
		cout << "Zero divide error on: " << exception.ex_name << '\n';
	}

	try {
		Admin a_ex("Smith", 0, 6);
	}
	catch (ZDivExcept exception) {
		cout << "Zero divide error on: " << exception.ex_name << '\n';
	}

	try {
		Junior j1("Black", 10, 10, 9);
	}
	catch (ZDivExcept exception) {
		cout << "Zero divide error on: " << exception.ex_name << '\n';
	}

	try {
		Junior j_ex("Black", 0, 10, 9);
	}
	catch (ZDivExcept exception) {
		cout << "Zero divide error on: " << exception.ex_name << '\n';
	}

	Admin Ad1;
	Junior Jr1;

	Ad1.Set();

	Ad1.Get();

	cout << Ad1.Div() << endl;

	Jr1.Set();

	Jr1.Get();

	cout << Jr1.Div() << endl;

	return 0;
}