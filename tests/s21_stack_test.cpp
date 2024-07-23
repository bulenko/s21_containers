#include "../stack/s21_stack.h"

#include <gtest/gtest.h>

TEST(stack_constructor, default_constructor) {
  s21::Stack<int> a;
  std::stack<int> b;
  ASSERT_EQ(a.Empty(), b.empty());
}

TEST(stack_constructor, init_constructor) {
  s21::Stack<int> a{1, 2, 3};
  ASSERT_FALSE(a.Empty());
}

TEST(stack_constructor, init_string_constructor) {
  s21::Stack<std::string> a{"kubik", "rubik"};
  ASSERT_EQ(a.Top(), "rubik");
}

TEST(stack_constructor, copy_constructor) {
  s21::Stack<int> a{1};
  s21::Stack<int> b(a);
  ASSERT_EQ(a.Top(), b.Top());
}

TEST(stack_constructor, move_constructor) {
  s21::Stack<int> a{15, 22, 36};
  s21::Stack<int> b(std::move(a));
  ASSERT_TRUE(a.Empty());
  ASSERT_FALSE(b.Empty());
}

TEST(stack_constructor, move_operator_constructor) {
  s21::Stack<int> a{10, 22, 37};
  s21::Stack<int> b;
  b = std::move(a);
  ASSERT_TRUE(a.Empty());
  ASSERT_FALSE(b.Empty());
}

TEST(stack_push, push_int) {
  s21::Stack<int> a;
  a.Push(7);
  std::stack<int> b;
  b.push(7);
  ASSERT_EQ(a.Top(), b.top());
}

TEST(stack_push, push_int2) {
  s21::Stack<int> a;
  a.Push(3);
  a.Push(4);
  a.Pop();
  std::stack<int> b;
  b.push(3);
  ASSERT_EQ(a.Top(), b.top());
}

TEST(stack_pop, pop_int) {
  s21::Stack<int> a{896, 2};
  std::stack<int> b;
  b.push(896);
  b.push(2);
  ASSERT_EQ(a.Top(), b.top());
  a.Pop();
  b.pop();
  ASSERT_EQ(a.Top(), b.top());
}

TEST(stack_pop, pop_string) {
  s21::Stack<std::string> a{"kubik", "rubik"};
  std::stack<std::string> b;
  b.push("kubik");
  b.push("rubik");
  a.Pop();
  b.pop();
  ASSERT_EQ(a.Top(), b.top());
}

TEST(stack_size, size) {
  s21::Stack<int> a{9, 7, 3, 7, 88, 146453};
  s21::Stack<int> a2{543, 2346};
  ASSERT_EQ(a.Size(), 6);
  ASSERT_EQ(a2.Size(), 2);
}

TEST(stack_swap, swap) {
  s21::Stack<int> a{9, 7, 3, 7, 88, 146453};
  s21::Stack<int> a2{543, 2346};
  a.Swap(a2);
  ASSERT_EQ(a.Size(), 2);
  ASSERT_EQ(a2.Size(), 6);
}

TEST(stack_emplace, emplace_front) {
  s21::Stack<int> a{58, 53, 51};
  a.EmplaceFront(456, 345);
  ASSERT_EQ(a.Size(), 5);
  ASSERT_EQ(a.Top(), 345);
  a.Pop();
  ASSERT_EQ(a.Top(), 456);
  a.Pop();
  ASSERT_EQ(a.Top(), 51);
}

TEST(stack_emplace, emplace_front_1) {
  s21::Stack<std::string> a{"a", "b", "c"};
  a.EmplaceFront("rubik", "kubik", "rubik");
  ASSERT_EQ(a.Top(), "rubik");
  a.Pop();
  ASSERT_EQ(a.Top(), "kubik");
  a.Pop();
  ASSERT_EQ(a.Top(), "rubik");
  a.Pop();
  ASSERT_EQ(a.Top(), "c");
}

TEST(stack_emplace, emplace_front_empty) {
  s21::Stack<std::string> a{"a", "b", "c"};
  a.EmplaceFront();
  ASSERT_EQ(a.Top(), "\0");
  a.Pop();
  ASSERT_EQ(a.Top(), "c");
  a.Pop();
  ASSERT_EQ(a.Top(), "b");
}

TEST(stack_emplace, emplace_front_5) {
  s21::Stack<int> a{1};
  a.EmplaceFront(1, 2, 3, 4, 5);
  ASSERT_EQ(a.Top(), 5);
  a.Pop();
  ASSERT_EQ(a.Top(), 4);
  a.Pop();
  ASSERT_EQ(a.Top(), 3);
}