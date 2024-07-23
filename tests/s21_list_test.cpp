#include "../list/s21_list.h"

TEST(list_constructor, default_constructor) {
  s21::List<int> s21_a;
  std::list<int> std_a;
  ASSERT_EQ(s21_a.Empty(), std_a.empty());
  ASSERT_EQ(std_a.max_size(), s21_a.MaxSize());
}

TEST(list_constructor, size_constructor) {
  s21::List<int> s21_a(5);
  ASSERT_EQ(s21_a.Size(), 5);
}

TEST(list_constructor, init_constructor) {
  s21::List<int> s21_a{1, 2, 3};
  ASSERT_FALSE(s21_a.Empty());
  ASSERT_EQ(s21_a.Front(), 1);
  s21_a.Clear();
  ASSERT_TRUE(s21_a.Empty());
}

TEST(list_constructor, init_string_constructor) {
  s21::List<std::string> s21_a{"kubik", "rubik"};
  ASSERT_EQ(s21_a.Front(), "kubik");
  ASSERT_EQ(s21_a.Back(), "rubik");
}

TEST(list_constructor, copy_constructor) {
  s21::List<int> s21_a{3, 2, 1};
  s21::List<int> s21_b(s21_a);
  ASSERT_EQ(s21_a.Front(), s21_b.Front());
}

TEST(list_constructor, move_constructor) {
  s21::List<int> s21_a{1, 2, 3};
  s21::List<int> s21_b(std::move(s21_a));
  ASSERT_TRUE(s21_a.Empty());
  ASSERT_FALSE(s21_b.Empty());
}

TEST(list_iterator_back, minus_minus) {
  s21::List<int> s21_a{1, 2, 3};
  std::list<int> s21_b{1, 2, 3};
  s21::List<int>::Iterator s21_it = s21_a.End();
  std::list<int>::iterator std_it = s21_b.end();
  for (size_t i = 0; i < s21_a.Size(); ++i) {
    --s21_it;
    --std_it;
    ASSERT_EQ(*s21_it, *std_it);
  }
}

TEST(list_constructor, move_operator_constructor) {
  s21::List<int> s21_a{1, 2, 3};
  s21::List<int> s21_b;
  s21_b = std::move(s21_a);
  ASSERT_TRUE(s21_a.Empty());
  ASSERT_FALSE(s21_b.Empty());
}

TEST(list_push, push_int) {
  s21::List<int> s21_a;
  s21_a.PushFront(4254);
  s21_a.PushBack(23);
  std::list<int> std_a;
  std_a.push_front(4254);
  std_a.push_back(23);
  ASSERT_EQ(s21_a.Front(), std_a.front());
  ASSERT_EQ(s21_a.Back(), std_a.back());
}

TEST(list_size, size_swap) {
  s21::List<int> s21_a{45324, 123, 31223, 5463, 2342, 1123};
  s21::List<int> s21_a2{55346, 165723};
  ASSERT_EQ(s21_a.Size(), 6);
  ASSERT_EQ(s21_a2.Size(), 2);
  s21_a.Swap(s21_a2);
  ASSERT_EQ(s21_a.Size(), 2);
  ASSERT_EQ(s21_a2.Size(), 6);
}

TEST(list_sort, sort) {
  s21::List<int> s21_a{3, 5, 1, 4, 6, 2};
  std::list<int> std_a{3, 5, 1, 4, 6, 2};
  std::list<int> sorted_a{1, 2, 3, 4, 5, 6};
  s21_a.Sort();
  std_a.sort();
  s21::List<int>::Iterator s21_it = s21_a.Begin();
  std::list<int>::iterator std_it = std_a.begin();
  std::list<int>::iterator sort_it = sorted_a.begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*s21_it, *std_it);
    ASSERT_EQ(*s21_it, *sort_it);
    ++s21_it;
    ++std_it;
    ++sort_it;
  }
}

TEST(list_iter, iter_eq) {
  s21::List<int> s21_a{3, 5, 1, 4, 6, 2};
  s21::List<int>::Iterator begin = s21_a.Begin();
  ASSERT_TRUE(*begin == 3);
}

TEST(list_change, reverse) {
  s21::List<int> s21_a{6, 5, 4, 3, 2, 1};
  std::list<int> std_a{1, 2, 3, 4, 5, 6};
  s21_a.Reverse();
  s21::List<int>::Iterator s21_it;
  s21_it = s21_a.Begin();
  std::list<int>::iterator std_it = std_a.begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(list_change, unique) {
  s21::List<int> s21_a{1, 1, 1, 1, 2, 2, 3, 3};
  std::list<int> std_a{1, 2, 3};
  s21_a.Unique();
  s21::List<int>::Iterator s21_it = s21_a.Begin();
  std::list<int>::iterator std_it = std_a.begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(list_change, unique_1) {
  s21::List<int> s21_a{1};
  std::list<int> std_a{1};
  s21_a.Unique();
  s21::List<int>::Iterator s21_it = s21_a.Begin();
  std::list<int>::iterator std_it = std_a.begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(list_erase, erase_1) {
  s21::List<int> s21_a{1};
  std::list<int> std_a{1};
  s21::List<int>::Iterator s21_it = s21_a.Begin();
  std::list<int>::iterator std_it = std_a.begin();
  s21_a.Erase(s21_it);
  std_a.erase(std_it);
  ASSERT_EQ(s21_a.Empty(), std_a.empty());
}

TEST(list_erase, erase_2) {
  s21::List<int> s21_a{1, 2};
  std::list<int> std_a{1, 2};
  s21::List<int>::Iterator s21_it = s21_a.Begin();
  std::list<int>::iterator std_it = std_a.begin();
  s21_a.Erase(s21_it);
  std_a.erase(std_it);
  ASSERT_EQ(s21_a.Size(), std_a.size());
}

TEST(list_erase, erase_3) {
  s21::List<int> s21_a{1, 2};
  s21::List<int>::Iterator s21_it = s21_a.End();
  EXPECT_ANY_THROW(s21_a.Erase(s21_it));
}

TEST(list_pop_front, pop_front) {
  s21::List<int> s21_a{1, 2};
  s21_a.PopFront();
  ASSERT_EQ(s21_a.Size(), 1);
  s21_a.PopFront();
  ASSERT_TRUE(s21_a.Empty());
}

TEST(list_insert, insert) {
  s21::List<int> s21_a;
  EXPECT_ANY_THROW(s21_a.Front());
  EXPECT_ANY_THROW(s21_a.Back());
  s21::List<int>::Iterator s21_it = s21_a.Begin();
  std::list<int> std_a;
  std::list<int>::iterator std_it = std_a.begin();
  s21_a.Insert(s21_it, 2);
  std_a.insert(std_it, 2);
  ASSERT_EQ(s21_a.Size(), std_a.size());
}

TEST(list_merge, merge) {
  s21::List<int> s21_a{1, 2, 3, 4, 5};
  s21::List<int> s21_b{-56, 12, 22, 31, 49};
  std::list<int> std_a{1, 2, 3, 4, 5};
  std::list<int> std_a_b{-56, 12, 22, 31, 49};
  s21_a.Merge(s21_b);
  std_a.merge(std_a_b);
  s21::List<int>::Iterator s21_it = s21_a.Begin();
  std::list<int>::iterator std_it = std_a.begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(list_merge, MergeFirstEmpty) {
  // str 302
  s21::List<int> s21_a;
  s21::List<int> s21_b{-56, 12, 22, 31, 49};
  std::list<int> std_a;
  std::list<int> std_a_b{-56, 12, 22, 31, 49};
  s21_a.Merge(s21_b);
  std_a.merge(std_a_b);
  s21::List<int>::Iterator s21_it = s21_a.Begin();
  std::list<int>::iterator std_it = std_a.begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(list_splice, splice) {
  s21::List<int> s21_a{1, 2, 3, 4, 5};
  s21::List<int> s21_b{-56, 12, 22, 31, 49};
  std::list<int> std_a{1, 2, 3, 4, 5};
  std::list<int> std_a_b{-56, 12, 22, 31, 49};
  s21::List<int>::Iterator s21_it = s21_a.Begin();
  std::list<int>::iterator std_it = std_a.begin();
  ++s21_it;
  ++std_it;
  s21_a.Splice(s21_it, s21_b);
  std_a.splice(std_it, std_a_b);
  s21_it = s21_a.Begin();
  std_it = std_a.begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(list_splice, splice_1) {
  s21::List<int> s21_a{1, 2, 3, 4, 5};
  s21::List<int> s21_b{-56, 12, 22, 31, 49};
  std::list<int> std_a{1, 2, 3, 4, 5};
  std::list<int> std_a_b{-56, 12, 22, 31, 49};
  s21::List<int>::Iterator s21_it = s21_a.Begin();
  std::list<int>::iterator std_it = std_a.begin();
  s21_a.Splice(s21_it, s21_b);
  std_a.splice(std_it, std_a_b);
  s21_it = s21_a.Begin();
  std_it = std_a.begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(list_splice, splice_2) {
  s21::List<int> s21_a{1, 2};
  s21::List<int> s21_b{-56, 12};
  std::list<int> std_a{1, 2};
  std::list<int> std_a_b{-56, 12};
  s21::List<int>::Iterator s21_it = s21_a.End();
  std::list<int>::iterator std_it = std_a.end();
  s21_a.Splice(s21_it, s21_b);
  std_a.splice(std_it, std_a_b);
  s21_it = s21_a.Begin();
  std_it = std_a.begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(list_splice, splice_3) {
  s21::List<int> s21_a;
  s21::List<int> s21_b{-56, 12};
  std::list<int> std_a;
  std::list<int> std_a_b{-56, 12};
  s21::List<int>::Iterator s21_it = s21_a.End();
  std::list<int>::iterator std_it = std_a.end();
  s21_a.Splice(s21_it, s21_b);
  std_a.splice(std_it, std_a_b);
  s21_it = s21_a.Begin();
  std_it = std_a.begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(operator_equal, Increment) {
  s21::List<int> s21_a;
  s21::List<int> s21_b{-56, 12};
  std::list<int> std_a;
  std::list<int> std_a_b{-56, 12};
  s21_a = s21_b;
  std_a = std_a_b;
  s21::List<int>::Iterator s21_it = s21_a.Begin();
  std::list<int>::iterator std_it = std_a.begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(bonus, emplace) {
  s21::List<int> s21_a{1, 2, 3};
  s21::List<int> check{1, 7, 8, 9, 2, 3};
  s21::List<int>::Iterator s21_it = s21_a.Begin();
  ++s21_it;
  s21_a.Emplace(s21_it, 7, 8, 9);
  s21::List<int>::Iterator ch1 = s21_a.Begin();
  s21::List<int>::Iterator std_it = check.Begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*ch1, *std_it);
    ++ch1;
    ++std_it;
  }
}

TEST(bonus, emplace_with_0) {
  s21::List<int> s21_a{};
  s21::List<int> check{0};
  s21::List<int>::Iterator s21_it = s21_a.Begin();
  s21_a.Emplace(s21_it);
  s21::List<int>::Iterator ch1 = s21_a.Begin();
  s21::List<int>::Iterator std_it = check.Begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*ch1, *std_it);
    ++ch1;
    ++std_it;
  }
}

TEST(bonus, emplace_with_5) {
  s21::List<int> s21_a{1, 2};
  s21::List<int> check{3, 4, 5, 8, 456, 1, 2};
  s21::List<int>::Iterator s21_it = s21_a.Begin();
  s21_a.Emplace(s21_it, 3, 4, 5, 8, 456);
  s21::List<int>::Iterator ch1 = s21_a.Begin();
  s21::List<int>::Iterator std_it = check.Begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*ch1, *std_it);
    ++ch1;
    ++std_it;
  }
}

TEST(bonus, emplace_back) {
  s21::List<int> s21_a{1, 2, 3};
  s21::List<int> check{1, 2, 3, 7, 8, 8};
  s21_a.EmplaceBack(7, 8, 8);
  s21::List<int>::Iterator ch1 = s21_a.Begin();
  s21::List<int>::Iterator std_it = check.Begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*ch1, *std_it);
    ++ch1;
    ++std_it;
  }
}

TEST(bonus, emplace_back_0) {
  s21::List<int> s21_a{1, 2, 3};
  s21::List<int> check{1, 2, 3, 0};
  s21_a.EmplaceBack();
  s21::List<int>::Iterator ch1 = s21_a.Begin();
  s21::List<int>::Iterator std_it = check.Begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*ch1, *std_it);
    ++ch1;
    ++std_it;
  }
}

TEST(bonus, emplace_back_5) {
  s21::List<std::string> s21_a{"a", "dfg", "dgst"};
  s21::List<std::string> check{"a",    "dfg", "dgst",  "hello",
                               "sdfs", "sdg", "sdffg", "wetfs"};
  s21_a.EmplaceBack("hello", "sdfs", "sdg", "sdffg", "wetfs");
  s21::List<std::string>::Iterator ch1 = s21_a.Begin();
  s21::List<std::string>::Iterator std_it = check.Begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*ch1, *std_it);
    ++ch1;
    ++std_it;
  }
}

TEST(bonus, emplace_front) {
  s21::List<int> s21_a{1, 2, 3};
  s21::List<int> check{5675, 34, 3453, 1, 2, 3};
  s21_a.EmplaceFront(5675, 34, 3453);
  s21::List<int>::Iterator ch1 = s21_a.Begin();
  s21::List<int>::Iterator std_it = check.Begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*ch1, *std_it);
    ++ch1;
    ++std_it;
  }
}

TEST(bonus, emplace_front_0) {
  s21::List<std::string> s21_a{"a", "dfg", "dgst"};
  s21::List<std::string> check{"\0", "a", "dfg", "dgst"};
  s21_a.EmplaceFront();
  s21::List<std::string>::Iterator ch1 = s21_a.Begin();
  s21::List<std::string>::Iterator std_it = check.Begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*ch1, *std_it);
    ++ch1;
    ++std_it;
  }
}

TEST(bonus, emplace_front_5) {
  s21::List<std::string> s21_a{"a", "dfg", "dgst"};
  s21::List<std::string> check{"hello", "sdfs", "sdg", "sdffg",
                               "wetfs", "a",    "dfg", "dgst"};
  s21_a.EmplaceFront("hello", "sdfs", "sdg", "sdffg", "wetfs");
  s21::List<std::string>::Iterator ch1 = s21_a.Begin();
  s21::List<std::string>::Iterator std_it = check.Begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*ch1, *std_it);
    ++ch1;
    ++std_it;
  }
}

TEST(bonus, emplace_front_bool) {
  s21::List<bool> s21_a{true, false, true};
  s21::List<bool> check{true, false, true, true, false, true};
  s21_a.EmplaceFront(true, false, true);
  s21::List<bool>::Iterator ch1 = s21_a.Begin();
  s21::List<bool>::Iterator std_it = check.Begin();
  for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {
    ASSERT_EQ(*ch1, *std_it);
    ++ch1;
    ++std_it;
  }
}

TEST(ListElementAccess, Access1) {
  s21::List<int> s21_a;
  ASSERT_ANY_THROW(*s21_a.Begin());
}

TEST(ListElementAccess, Access2) {
  s21::List<int> s21_a{1, 2, 3};
  s21::List<int>::Iterator it1 = s21_a.Begin();
  s21::List<int>::Iterator it2 = s21_a.End();
  ++it1;
  --it2;
  --it2;
  EXPECT_TRUE(it1 == it2);
}