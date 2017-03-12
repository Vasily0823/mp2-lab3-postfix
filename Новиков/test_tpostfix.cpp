//---
#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
	string expression = "2+2";
	ASSERT_NO_THROW(TPostfix postfix(expression));
}

TEST(TPostfix, simple_multiplication_test)
{
	string expression = "2*2";
	string result = "22*";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, simple_addition_test)
{
	string expression = "2+2";
	string result = "22+";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, simple_division_test)
{
	string expression = "2/2";
	string result = "22/";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, simple_subtraction_test)
{
	string expression = "2-2";
	string result = "22-";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, mixed_test_number_one)
{
	string expression = "a+b*c";
	string result = "abc*+";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, mixed_test_number_two)
{
	string expression = "a+b-c*d";
	string result = "ab+cd*-";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, mixed_test_number_three)
{
	string expression = "a+b*c-d";
	string result = "abc*+d-";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, mixed_test_number_four)
{
	string expression = "(a+b)*c";
	string result = "ab+c*";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, mixed_test_number_five)
{
	string expression = "(a+b*c)/2";
	string result = "abc*+2/";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, mixed_test_number_six)
{
	string expression = "(a*(b+c)+d)/2";
	string result = "abc+*d+2/";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, mixed_test_number_seven)
{
	string expression = "a+b*c/d-d";
	string result = "abc*d/+d-";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, calc_simple_multiplication_test)
{
	string expression = "5*5";
	double result = 25;
	TPostfix postfix(expression);
	postfix.ToPostfix();
	EXPECT_EQ(result, postfix.Calculate());
}

TEST(TPostfix, calc_simple_addition_test)
{
	string expression = "5+5";
	double result = 10;
	TPostfix postfix(expression);
	postfix.ToPostfix();
	EXPECT_EQ(result, postfix.Calculate());
}

TEST(TPostfix, calc_simple_division_test)
{
	string expression = "5/5";
	double result = 1;
	TPostfix postfix(expression);
	postfix.ToPostfix();
	EXPECT_EQ(result, postfix.Calculate());
}

TEST(TPostfix, calc_simple_subtraction_test)
{
	string expression = "5-5";
	double result = 0;
	TPostfix postfix(expression);
	postfix.ToPostfix();
	EXPECT_EQ(result, postfix.Calculate());
}