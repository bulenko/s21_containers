#include "../array/s21_array.h"

#include <gtest/gtest.h>

TEST(array_constructor, constructor_int) {
  s21::Array<int, 1> a;
  std::array<int, 1> b;
  EXPECT_EQ(a.Size(), b.size());
}

TEST(array_constructor, constructor_int_2) {
  // throw of initializer_list
  ASSERT_ANY_THROW((s21::Array<int, 1>({0, 0})));
}

TEST(array_constructor, constructor_double) {
  s21::Array<double, 10> a{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  std::array<double, 10> b{1, 299, 9};
  EXPECT_EQ(a.Size(), b.size());
  EXPECT_EQ(a.MaxSize(), b.max_size());
}

TEST(array_constructor, constructor_string) {
  s21::Array<std::string, 3> a{"kubik", "rubik", "ussr"};
  std::array<std::string, 3> b{"kubik", "rubik", "ussr"};
  EXPECT_EQ(a[0], b[0]);
  EXPECT_EQ(a[1], b[1]);
  EXPECT_EQ(a[2], b[2]);
}

TEST(array_constructor, copy_constructor) {
  s21::Array<int, 10> a{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  s21::Array<int, 10> a_copy(a);
  std::array<int, 10> b{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  std::array<int, 10> b_copied(b);
  int i = 0;
  for (auto it = a.Begin(); it != a.End(); ++it) {
    EXPECT_EQ(a[i], b[i]);
    EXPECT_EQ(a_copy[i], b_copied[i]);
    ++i;
  }
}

TEST(array_constructor, copy_constructor_string) {
  s21::Array<std::string, 10> a{"a", "b", "c"};
  s21::Array<std::string, 10> a_copy(a);
  std::array<std::string, 10> b{"a", "b", "c"};
  std::array<std::string, 10> b_copied(b);
  int i = 0;
  for (auto it = a.Begin(); it != a.End(); ++it) {
    EXPECT_EQ(a[i], b[i]);
    EXPECT_EQ(a_copy[i], b_copied[i]);
    ++i;
  }
}

TEST(array_constructor, operator_string) {
  s21::Array<std::string, 10> a{"a", "b", "c"};
  s21::Array<std::string, 10> a_copy;
  a_copy = a;
  std::array<std::string, 10> b{"a", "b", "c"};
  std::array<std::string, 10> b_copied;
  b_copied = b;
  int i = 0;
  for (auto it = a.Begin(); it != a.End(); ++it) {
    EXPECT_EQ(a[i], b[i]);
    EXPECT_EQ(a_copy[i], b_copied[i]);
    ++i;
  }
}

TEST(array_constructor, move_constructor_string) {
  s21::Array<std::string, 10> a{"a", "b", "c"};
  s21::Array<std::string, 10> a_moved(std::move(a));
  std::array<std::string, 10> b{"a", "b", "c"};
  std::array<std::string, 10> b_moved(std::move(b));
  for (size_t i = 0; i < a_moved.Size(); ++i) {
    EXPECT_EQ(a_moved[i], b_moved[i]);
  }
}

TEST(array_constructor, move_constructor_1) {
  s21::Array<int, 10> a{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  s21::Array<int, 10> a_moved(std::move(a));
  std::array<int, 10> b{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  std::array<int, 10> b_moved(std::move(b));
  for (size_t i = 0; i < a_moved.Size(); ++i) {
    EXPECT_EQ(a_moved[i], b_moved[i]);
  }
}

TEST(array_constructor, move_operator_string) {
  s21::Array<std::string, 10> a{"a", "b", "c"};
  s21::Array<std::string, 10> a_moved;
  a_moved = std::move(a);
  std::array<std::string, 10> b{"a", "b", "c"};
  std::array<std::string, 10> b_moved;
  b_moved = std::move(b);
  for (size_t i = 0; i < a_moved.Size(); ++i) {
    EXPECT_EQ(a_moved[i], b_moved[i]);
  }
}

TEST(reference_at, at) {
  s21::Array<int, 10> a{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  std::array<int, 10> b{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  ASSERT_EQ(a.At(1), a.At(1));
  ASSERT_EQ(a.At(0), b.at(0));
  EXPECT_THROW(a.At(11), std::exception);
}

TEST(const_reference_front, front) {
  s21::Array<int, 10> a{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  std::array<int, 10> b{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  EXPECT_EQ(a.Front(), b.front());
  a[0] = 8;
  b[0] = 8;
  EXPECT_EQ(a.Front(), b.front());
}

TEST(const_reference_back, back) {
  s21::Array<int, 10> a{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  std::array<int, 10> b{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  EXPECT_EQ(a.Back(), b.back());
}

TEST(bool_empty, empty) {
  s21::Array<int, 10> a{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  std::array<int, 10> b{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  ASSERT_EQ(a.Empty(), b.empty());
}

TEST(bool_empty, empty2) {
  s21::Array<int, 0> a;
  std::array<int, 0> b;
  ASSERT_EQ(a.Empty(), b.empty());
}

TEST(iterator, plus_minus) {
  s21::Array<int, 10> a{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  s21::Array<int, 10>::iterator my_it = a.Begin();
  std::array<int, 10> b{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  std::array<int, 10>::iterator org_it = b.begin();
  while (my_it != a.End()) {
    ASSERT_EQ(*my_it++, *org_it++);
  }
  while (my_it != a.Begin()) {
    ASSERT_EQ(*--my_it, *--org_it);
  }
}

TEST(iterator, begin_end) {
  s21::Array<int, 0> a;
  s21::Array<int, 0>::iterator my_it = a.Begin();
  ASSERT_EQ(my_it, a.End());
}

TEST(iterator, data) {
  s21::Array<int, 1> a{6};
  s21::Array<int, 1>::iterator my_it = a.Data();
  ASSERT_EQ(*my_it, 6);
  ASSERT_EQ(my_it, a.Begin());
}

TEST(void_fill, fill) {
  s21::Array<int, 10> a;
  a.Fill(99);
  std::array<int, 10> b;
  b.fill(99);
  for (size_t i = 0; i < b.size(); ++i) {
    EXPECT_EQ(a[i], b[i]);
  }
}

TEST(void_swap, swap) {
  s21::Array<int, 10> a{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  s21::Array<int, 10> a2{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  a.Swap(a2);

  std::array<int, 10> c{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  std::array<int, 10> c2{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  c.swap(c2);

  for (size_t i = 0; i < c.size(); ++i) {
    EXPECT_EQ(a[i], c[i]);
  }
}

TEST(array_constructor, operator_move) {
  s21::Array<int, 10> a{12, 1, 6, 3, 100, 0, -1, -33, -89, 20};
  s21::Array<int, 10> b{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  a = b;
  for (size_t i = 0; i < b.Size(); ++i) {
    EXPECT_EQ(a[i], b[i]);
  }
}
TEST(array_constructor, operator_move_exp) {
  s21::Array<std::string, 1> a{"q"};
  s21::Array<std::string, 1> b{"v"};
  a = b;
  EXPECT_EQ(a[0], b[0]);
}