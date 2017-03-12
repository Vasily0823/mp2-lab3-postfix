//---
#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)//тест
{
	ASSERT_NO_THROW(TStack<int> v(5));
}

TEST(TStack, cant_create_stack_with_negative_length)//тест
{
	ASSERT_ANY_THROW(TStack<int> v(-5));
}


TEST(TStack, cant_create_large_stack) //тест
{
	ASSERT_ANY_THROW(TStack<int> v(MaxSize + 1));
}

TEST(TStack, cant_del_stack) //тест
{
	TStack<int> v(2);
	ASSERT_NO_THROW(v.~TStack());
}

TEST(TStack, cant_push_to_full_stack) //тест 
{
	TStack<int> v(2);
	v.Push(1);
	v.Push(2);
	ASSERT_ANY_THROW(v.Push(4));
}

TEST(TStack, cant_pop_of_clear_stack) //тест
{
	TStack<int> v(2);
	ASSERT_ANY_THROW(v.Pop());
}

TEST(TStack, cant_top_of_clear_stack) //тест
{
	TStack<int> v(2);
	ASSERT_ANY_THROW(v.Top());
}


TEST(TStack, can_top_of_stack_about_one)//тест
{
	TStack<int> v(5);
	v.Push(4);
	EXPECT_EQ(4, v.Top());
}

TEST(TStack, can_top_of_stack_about_two)//тест
{
	TStack<int> v(5);
	v.Push(4);
	v.Push(7);
	EXPECT_EQ(7, v.Top());
}

TEST(TStack, can_top_of_stack_about_three)//тест
{
	TStack<int> v(5);
	v.Push(4);
	v.Push(1);
	v.Push(77);
	EXPECT_EQ(77, v.Top());
}

TEST(TStack, can_pop_of_stack_about_one)//тест
{
	TStack<int> v(5);
	v.Push(4);
	EXPECT_EQ(4, v.Pop());
}

TEST(TStack, can_pop_of_stack_about_two)//тест
{
	TStack<int> v(5);
	v.Push(4);
	v.Push(7);
	EXPECT_EQ(7, v.Pop());
}

TEST(TStack, can_pop_of_stack_about_three)//тест
{
	TStack<int> v(5);
	v.Push(4);
	v.Push(1);
	v.Push(77);
	EXPECT_EQ(77, v.Pop());
}

TEST(TStack, can_push_and_pop) //тест
{
	TStack<int> v(5);
	v.Push(4);
	v.Push(5);
	EXPECT_EQ(5, v.Pop());
	EXPECT_EQ(4, v.Top());
}

TEST(TStack, can_push_and_pop_two) //тест
{
	TStack<int> v(5);
	v.Push(4);
	v.Push(5);
	EXPECT_NE(4, v.Pop());
	EXPECT_NE(5, v.Top());
}

TEST(TStack, can_push_and_pop_three) //тест
{
	TStack<int> v(5);
	v.Push(4);
	v.Pop();
	v.Push(5);
	EXPECT_EQ(5, v.Pop());

}


TEST(TStack, IsEmpty_false_of_full_stack) //тест
{
	TStack<int> v(2);
	v.Push(4);
	v.Push(4);
	ASSERT_FALSE(v.IsEmpty());
}

TEST(TStack, IsEmpty_true_of_clear_stack) //тест
{
	TStack<int> v(2);
	ASSERT_TRUE(v.IsEmpty());
}

TEST(TStack, IsEmpty_false_of_any_stack) //тест
{
	TStack<int> v(2);
	v.Push(4);
	ASSERT_FALSE(v.IsEmpty());
}

TEST(TStack, IsFull_true_of_full_stack) //тест
{
	TStack<int> v(2);
	v.Push(4);
	v.Push(4);
	ASSERT_TRUE(v.IsFull());
}

TEST(TStack, IsFull_false_of_clear_stack)  //тест
{
	TStack<int> v(2);
	ASSERT_FALSE(v.IsFull());
}

TEST(TStack, IsFull_false_of_any_stack)  //тест
{
	TStack<int> v(2);
	v.Push(4);
	ASSERT_FALSE(v.IsFull());
}