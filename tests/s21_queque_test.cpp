#include "../queue/s21_queue.h"

TEST(queue_constructor, default_constructor) {
  s21::Queue<int> a;
  std::queue<int> std_a;
  ASSERT_EQ(a.Empty(), std_a.empty());
}

TEST(queue_constructor, init_constructor) {
  s21::Queue<int> a{1, 2};
  ASSERT_FALSE(a.Empty());
}

TEST(queue_constructor, init_string_constructor) {
  s21::Queue<std::string> a{"dfDfd", "world"};
  ASSERT_EQ(a.Back(), "world");
  ASSERT_EQ(a.Front(), "dfDfd");
}

TEST(queue_constructor, copy_constructor) {
  s21::Queue<int> a{1};
  s21::Queue<int> b(a);
  ASSERT_EQ(a.Front(), b.Front());
}

TEST(queue_constructor, FrontEmpty_BackEmpty) {
  s21::Queue<int> a;
  ASSERT_ANY_THROW(a.Front());
  ASSERT_ANY_THROW(a.Back());
}

TEST(queue_constructor, move_constructor) {
  s21::Queue<int> a{1, 2, 3};
  s21::Queue<int> b(std::move(a));
  ASSERT_TRUE(a.Empty());
  ASSERT_FALSE(b.Empty());
}

TEST(queue_constructor, move_operator_constructor) {
  s21::Queue<int> a{1, 2, 3};
  s21::Queue<int> b;
  b = std::move(a);
  ASSERT_TRUE(a.Empty());
  ASSERT_FALSE(b.Empty());
}

TEST(queue_push, push_int) {
  s21::Queue<int> a;
  a.Push(566);
  std::queue<int> std_a;
  std_a.push(566);
  ASSERT_EQ(a.Front(), std_a.front());
  ASSERT_EQ(a.Back(), std_a.back());
}

TEST(queue_push, push_int2) {
  s21::Queue<int> a;
  a.Push(3);
  a.Push(4);
  a.Pop();
  std::queue<int> std_a;
  std_a.push(4);
  ASSERT_EQ(a.Front(), std_a.front());
}

TEST(queue_pop, pop_int) {
  s21::Queue<int> a{566, 123};
  std::queue<int> std_a;
  std_a.push(566);
  std_a.push(123);
  ASSERT_EQ(a.Front(), std_a.front());
  ASSERT_EQ(a.Back(), std_a.back());
  a.Pop();
  std_a.pop();
  ASSERT_EQ(a.Front(), std_a.front());
  ASSERT_EQ(a.Back(), std_a.back());
}

TEST(queue_pop, pop_string) {
  s21::Queue<std::string> a{"kubik", "rubik"};
  std::queue<std::string> std_a;
  std_a.push("kubik");
  std_a.push("rubik");
  ASSERT_EQ(a.Front(), std_a.front());
  ASSERT_EQ(a.Back(), std_a.back());
  a.Pop();
  std_a.pop();
  ASSERT_EQ(a.Front(), std_a.front());
  ASSERT_EQ(a.Back(), std_a.back());
}

TEST(queue_size, size) {
  s21::Queue<int> a{546, 432, 54546, 23, 123, 1231};
  s21::Queue<int> a2{342, 5234};
  ASSERT_EQ(a.Size(), 6);
  ASSERT_EQ(a2.Size(), 2);
}

TEST(queue_swap, swap) {
  s21::Queue<int> a{546, 432, 54546, 23, 123, 1231};
  s21::Queue<int> a2{342, 5234};
  a.Swap(a2);
  ASSERT_EQ(a.Size(), 2);
  ASSERT_EQ(a2.Size(), 6);
}

TEST(queue_emplace, emplace_back) {
  s21::Queue<int> a{5, 5};
  a.EmplaceBack(3, 3);
  ASSERT_EQ(a.Size(), 4);
  ASSERT_EQ(a.Front(), 5);
  ASSERT_EQ(a.Back(), 3);
  a.Pop();
  ASSERT_EQ(a.Front(), 5);
  a.Pop();
  ASSERT_EQ(a.Front(), 3);
}

TEST(queue_emplace, emplace_back_1) {
  s21::Queue<std::string> a{"a", "a"};
  a.EmplaceBack("a", "a");
  ASSERT_EQ(a.Size(), 4);
  ASSERT_EQ(a.Front(), "a");
  ASSERT_EQ(a.Back(), "a");
  a.Pop();
  ASSERT_EQ(a.Front(), "a");
  a.Pop();
  ASSERT_EQ(a.Front(), "a");
}

TEST(queue_emplace, emplace_back_0) {
  s21::Queue<std::string> a{"a", "a"};
  a.EmplaceBack();
  ASSERT_EQ(a.Size(), 3);
  ASSERT_EQ(a.Front(), "a");
  ASSERT_EQ(a.Back(), "\0");
}

TEST(queue_emplace, emplace_back_5) {
  s21::Queue<std::string> a{"a", "a"};
  a.EmplaceBack("h", "a", "c", "v", "s");
  ASSERT_EQ(a.Size(), 7);
  ASSERT_EQ(a.Front(), "a");
  ASSERT_EQ(a.Back(), "s");
  a.Pop();
  ASSERT_EQ(a.Front(), "a");
}