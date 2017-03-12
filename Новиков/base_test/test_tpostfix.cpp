//---
#include "postfix.h"
#include <gtest.h>


TEST(TPostfix, cant_div_null)
{
	string expression = "9/0";
	TPostfix postfix(expression);
	ASSERT_ANY_THROW(postfix.ToPostfix());
}


TEST(TPostfix, can_create_postfix)
{
	string expression = "2+2";
	ASSERT_NO_THROW(TPostfix postfix(expression));
}

TEST(TPostfix, simple_mul_test)
{
	string expression = "2*2";
	string result = "22*";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, simple_add_test)
{
	string expression = "2+2";
	string result = "22+";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, simple_div_test)
{
	string expression = "2/2";
	string result = "22/";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, simple_sub_test)
{
	string expression = "2-2";
	string result = "22-";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, mix_test_one)
{
	string expression = "a*b+c";
	string result = "ab*c+";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, mix_test_two)
{
	string expression = "a+b-c*d";
	string result = "ab+cd*-";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, mix_test_three)
{
	string expression = "a+b*c-d";
	string result = "abc*+d-";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, mix_test_four)
{
	string expression = "(a+b)*c";
	string result = "ab+c*";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, mix_test_five)
{
	string expression = "(a+b*c)/2";
	string result = "abc*+2/";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, mix_test_six)
{
	string expression = "(a*(b+c)+d)/2";
	string result = "abc+*d+2/";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, mix_test_seven)
{
	string expression = "a+b*c/d-d";
	string result = "abc*d/+d-";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, mix_test_eight)
{
	string expression = "a+(b*b-(a+c)-b)/a";
	string result = "abb*ac+-b-a/+";
	TPostfix postfix(expression);
	EXPECT_EQ(result, postfix.ToPostfix());
}

TEST(TPostfix, calc_simple_mul_test)
{
	string expression = "6*6";
	double result = 36;
	TPostfix postfix(expression);
	postfix.ToPostfix();
	EXPECT_EQ(result, postfix.Calculate());
}

TEST(TPostfix, calc_simple_add_test)
{
	string expression = "6+6";
	double result = 12;
	TPostfix postfix(expression);
	postfix.ToPostfix();
	EXPECT_EQ(result, postfix.Calculate());
}

TEST(TPostfix, calc_simple_div_test)
{
	string expression = "6/6";
	double result = 1;
	TPostfix postfix(expression);
	postfix.ToPostfix();
	EXPECT_EQ(result, postfix.Calculate());
}

TEST(TPostfix, calc_simple_nul_test)
{
	string expression = "6-6";
	double result = 0;
	TPostfix postfix(expression);
	postfix.ToPostfix();
	EXPECT_EQ(result, postfix.Calculate());
}

TEST(TPostfix, calc_negative_numbert)
{
	string expression = "9-6-6";
	double result = -3;
	TPostfix postfix(expression);
	postfix.ToPostfix();
	EXPECT_EQ(result, postfix.Calculate());
}