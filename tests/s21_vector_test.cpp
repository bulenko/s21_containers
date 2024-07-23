#include "../vector/s21_vector.h"

TEST(VectorElementAccess, ReferenceAt) {
  s21::Vector<int> a{100, 4, 3, 5, 8, 11, 0};
  std::vector<int> b{100, 4, 3, 5, 8, 11, 0};
  EXPECT_EQ(a.At(3), b.at(3));
  EXPECT_EQ(a.At(0), b.at(0));
  EXPECT_EQ(a.At(6), b.at(6));
  EXPECT_THROW(a.At(7), std::exception);
}

TEST(VectorElementAccess, ReferenceOperatorBrakets) {
  s21::Vector<int> a{100, 4, 3, 5, 8, 11, 0};
  std::vector<int> b{100, 4, 3, 5, 8, 11, 0};
  EXPECT_EQ(a[4], b[4]);
  EXPECT_EQ(a[0], b[0]);
  EXPECT_EQ(a[6], b[6]);
}

TEST(VectorElementAccess, ReferenceFront) {
  s21::Vector<int> a{100, 4, 3, 5, 8, 11, 0};
  std::vector<int> b{100, 4, 3, 5, 8, 11, 0};
  EXPECT_EQ(a.Front(), b.front());
}

TEST(VectorElementAccess, ReferenceBack) {
  s21::Vector<int> a{100, 4, 3, 5, 8, 11, 0};
  std::vector<int> b{100, 4, 3, 5, 8, 11, 0};
  EXPECT_EQ(a.Back(), b.back());
}

TEST(VectorElementAccess, IteratorData) {
  s21::Vector<int> a{100, 4, 3, 5, 8, 11, 0};
  std::vector<int> b{100, 4, 3, 5, 8, 11, 0};
  EXPECT_EQ(*a.Data(), *b.data());
}

TEST(VectorIterator, IteratorBegin) {
  s21::Vector<int> a{100, 4, 3, 5, 8, 11, 0};
  std::vector<int> b{100, 4, 3, 5, 8, 11, 0};
  EXPECT_EQ(*a.Begin(), *b.begin());
}

TEST(VectorIterator, IteratorEnd) {
  s21::Vector<double> a{100.1, 4.5, 3.1, 5.8, 8.4, 11.9, 0.9};
  std::vector<double> b{100.1, 4.5, 3.1, 5.8, 8.4, 11.9, 0.9};
  s21::Vector<double>::iterator my_it = a.End();
  std::vector<double>::iterator org_it = b.end();
  EXPECT_DOUBLE_EQ(*(--my_it), *(--org_it));
}

TEST(VectorIterator, IteratorPlus) {
  s21::Vector<double> a{100.1, 4.5, 3.1, 5.8, 8.4, 11.9, 0.9};
  std::vector<double> b{100.1, 4.5, 3.1, 5.8, 8.4, 11.9, 0.9};
  s21::Vector<double>::iterator my_it = a.Begin();
  std::vector<double>::iterator org_it = b.begin();
  EXPECT_DOUBLE_EQ(*(++my_it), *(++org_it));
}

TEST(VectorIterator, IteratorMinus) {
  s21::Vector<double> a{100.1, 4.5, 3.1, 5.8, 8.4, 11.9, 0.9};
  std::vector<double> b{100.1, 4.5, 3.1, 5.8, 8.4, 11.9, 0.9};
  s21::Vector<double>::iterator my_it = a.End();
  std::vector<double>::iterator org_it = b.end();
  EXPECT_EQ(*--my_it, *--org_it);
}

TEST(VectorIterator, IteratorEqual) {
  s21::Vector<std::string> a{"hi",        "ha",   "hb",  "ht",
                             "highvideo", "houl", "hppp"};
  std::vector<std::string> b{"hi",        "ha",   "hb",  "ht",
                             "highvideo", "houl", "hppp"};
  s21::Vector<std::string>::iterator my_it = a.Begin();
  std::vector<std::string>::iterator org_it = b.begin();
  EXPECT_TRUE(*my_it == *org_it);
}

TEST(VectorIterator, IteratorNotEqual) {
  s21::Vector<std::string> a{"hi",        "ha",   "hb",  "ht",
                             "highvideo", "houl", "hppp"};
  std::vector<std::string> b{"hi",        "ha",   "hb",  "ht",
                             "highvideo", "houl", "hppp"};
  s21::Vector<std::string>::iterator my_it = a.Begin();
  std::vector<std::string>::iterator org_it = b.begin();
  EXPECT_TRUE(*my_it != *++org_it);
}

TEST(VectorCapacity, empty) {
  s21::Vector<std::string> a{"hi",        "ha",   "hb",  "ht",
                             "highvideo", "houl", "hppp"};
  std::vector<std::string> b{"hi",        "ha",   "hb",  "ht",
                             "highvideo", "houl", "hppp"};
  EXPECT_EQ(a.Empty(), b.empty());
}

TEST(VectorCapacity, Size) {
  s21::Vector<std::string> a{"hi",        "ha",   "hb",  "ht",
                             "highvideo", "houl", "hppp"};
  std::vector<std::string> b{"hi",        "ha",   "hb",  "ht",
                             "highvideo", "houl", "hppp"};
  EXPECT_EQ(a.Size(), b.size());
  s21::Vector<int> aTemp;
  std::vector<int> bTemp;
  EXPECT_EQ(aTemp.Size(), bTemp.size());
}

TEST(VectorCapacity, MaxSize) {
  s21::Vector<int> a{100, 4, 3, 5, 8, 11, 0};
  std::vector<int> b{100, 4, 3, 5, 8, 11, 0};
  EXPECT_EQ(a.MaxSize(), b.max_size());
}

TEST(VectorCapacity, MaxSize_1) {
  s21::Vector<double> a{100, 4, 3, 5, 8, 11, 0};
  std::vector<double> b{100, 4, 3, 5, 8, 11, 0};
  EXPECT_EQ(a.MaxSize(), b.max_size());
}

TEST(VectorCapacity, MaxSize_2) {
  s21::Vector<std::string> a;
  std::vector<std::string> b;
  EXPECT_EQ(a.MaxSize(), b.max_size());
}

TEST(VectorCapacity, Reserve) {
  s21::Vector<int> a{100, 4, 3, 5, 8, 11, 0};
  std::vector<int> b{100, 4, 3, 5, 8, 11, 0};
  a.Reserve(14);
  b.reserve(14);
  EXPECT_EQ(a.Capacity(), b.capacity());
  EXPECT_THROW(a.Reserve(a.MaxSize() + 1), std::exception);
}

TEST(VectorCapacity, Reserve_2) {
  s21::Vector<int> a{100, 4, 3, 5, 8, 11, 0};
  std::vector<int> b{100, 4, 3, 5, 8, 11, 0};
  a.Clear();
  b.clear();
  a.ShrinkToFit();
  b.shrink_to_fit();
  a.Reserve(14);
  b.reserve(14);
  EXPECT_EQ(a.Capacity(), b.capacity());
}

TEST(VectorCapacity, Capacity) {
  s21::Vector<int> a{100, 4, 3, 5, 8, 11, 0};
  EXPECT_EQ(a.Capacity(), 7);
}

TEST(VectorCapacity, ShrinkToFit) {
  s21::Vector<int> a{100, 4, 3, 5, 8, 11, 0};
  std::vector<int> b{100, 4, 3, 5, 8, 11, 0};
  a.Reserve(14);
  b.reserve(14);
  a.ShrinkToFit();
  b.shrink_to_fit();
  EXPECT_EQ(a.Capacity(), b.capacity());
}

TEST(VectorModifiers, Clear) {
  s21::Vector<int> a{1, 4, 5, 2, 7, 12, 14};
  std::vector<int> b{1, 4, 5, 2, 7, 12, 14};
  a.Clear();
  b.clear();
  EXPECT_EQ(a.Capacity(), 7);
  EXPECT_EQ(a.Size(), b.size());
}

TEST(VectorModifiers, Insert_1) {
  s21::Vector<int> a;
  std::vector<int> b;
  a.PushBack(12);
  a.PushBack(45);
  a.PushBack(31);
  a.PushBack(30);

  b.push_back(12);
  b.push_back(45);
  b.push_back(31);
  b.push_back(30);

  s21::Vector<int>::iterator my_it = a.Begin();
  std::vector<int>::iterator org_it = b.begin();

  my_it = a.Insert(my_it, 1);
  org_it = b.insert(org_it, 1);
  EXPECT_EQ(*my_it, *org_it);
}

TEST(VectorModifiers, Insert_2) {
  s21::Vector<int> a;
  std::vector<int> b;
  a.PushBack(12);
  a.PushBack(45);
  a.PushBack(31);
  a.PushBack(30);

  b.push_back(12);
  b.push_back(45);
  b.push_back(31);
  b.push_back(30);

  s21::Vector<int>::iterator my_it = a.Begin();
  std::vector<int>::iterator org_it = b.begin();

  my_it = a.Insert(my_it + 3, 1);
  org_it = b.insert(org_it + 3, 1);
  EXPECT_EQ(*my_it, *org_it);
}

TEST(VectorModifiers, Reserve_3) {
  s21::Vector<int> a;
  std::vector<int> b;
  a.Clear();
  b.clear();
  a.ShrinkToFit();
  b.shrink_to_fit();
  s21::Vector<int>::iterator my_it = a.Begin();
  std::vector<int>::iterator org_it = b.begin();
  a.Insert(my_it, 1);
  b.insert(org_it, 1);
  EXPECT_EQ(a[0], b[0]);
}

TEST(VectorModifiers, Erase_1) {
  s21::Vector<std::string> a;
  std::vector<std::string> b;
  a.PushBack("a");
  a.PushBack("b");

  b.push_back("a");
  b.push_back("b");

  s21::Vector<std::string>::iterator my_it = a.Begin();
  std::vector<std::string>::iterator org_it = b.begin();
  ++my_it;
  ++org_it;
  a.Erase(my_it);
  b.erase(org_it);
  EXPECT_EQ(a[0], b[0]);
}

TEST(VectorModifiers, Erase_2) {
  s21::Vector<int> a;
  std::vector<int> b;
  a.PushBack(12);
  a.PushBack(45);
  a.PushBack(31);
  a.PushBack(30);

  b.push_back(12);
  b.push_back(45);
  b.push_back(31);
  b.push_back(30);

  s21::Vector<int>::iterator my_it = a.Begin();
  std::vector<int>::iterator org_it = b.begin();

  a.Erase(my_it + 3);
  b.erase(org_it + 3);
  EXPECT_EQ(a[2], b[2]);
}

TEST(VectorModifiers, push_back) {
  s21::Vector<int> a;
  std::vector<int> b;
  a.PushBack(12);
  a.PushBack(45);
  a.PushBack(31);
  a.PushBack(30);

  b.push_back(12);
  b.push_back(45);
  b.push_back(31);
  b.push_back(30);

  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(a[i], b[i]);
  }
}

TEST(VectorModifiers, pop_back) {
  s21::Vector<int> a;
  std::vector<int> b;
  a.PushBack(12);
  a.PushBack(45);
  a.PushBack(31);
  a.PushBack(30);
  a.PopBack();
  a.PopBack();

  b.push_back(12);
  b.push_back(45);
  b.push_back(31);
  b.push_back(30);
  b.pop_back();
  b.pop_back();

  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(a[i], b[i]);
  }
}

TEST(VectorModifiers, Swap) {
  s21::Vector<int> a{4, 4, 4};
  s21::Vector<int> aTemp{1, 1, 1};
  std::vector<int> b{4, 4, 4};
  std::vector<int> bTemp{1, 1, 1};
  a.Swap(aTemp);
  b.swap(bTemp);
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(a[i], b[i]);
    EXPECT_EQ(aTemp[i], bTemp[i]);
  }
}

TEST(VectorConstructor, SizeN) {
  s21::Vector<int> a(5);
  EXPECT_EQ(a.Capacity(), 5);
  EXPECT_THROW(s21::Vector<int> a(-2), std::exception);
}

TEST(VectorConstructor, CopyConstruction) {
  s21::Vector<int> a{4, 4, 4};
  s21::Vector<int> aTemp(a);
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(a[i], aTemp[i]);
  }
}

TEST(VectorConstructor, OperatorEqual) {
  s21::Vector<int> a{4, 4, 4};
  s21::Vector<int> aTemp = a;
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(a[i], aTemp[i]);
  }
}

TEST(VectorConstructor, MoveConstructor) {
  s21::Vector<int> a{4, 4, 4};
  s21::Vector<int> aTemp(std::move(a));
  for (size_t i = 0; i < aTemp.Size(); i++) {
    EXPECT_EQ(aTemp[i], 4);
  }
}

TEST(VectorConstructor, MoveEqualConstructor) {
  s21::Vector<int> a{4, 4, 4};
  s21::Vector<int> aTemp;
  aTemp = std::move(a);
  for (size_t i = 0; i < aTemp.Size(); i++) {
    EXPECT_EQ(aTemp[i], 4);
  }
}

TEST(VectorInitiat, SecondTime) {
  s21::Vector<std::string> a{"hi",        "ha",   "hb",  "ht",
                             "highvideo", "houl", "hppp"};
  std::vector<std::string> b{"hi",        "ha",   "hb",  "ht",
                             "highvideo", "houl", "hppp"};
  a = s21::Vector<std::string>{"jjjj"};
  b = {"jjjj"};
  EXPECT_EQ(a[0], b[0]);
  EXPECT_EQ(a.Size(), b.size());
  s21::Vector<int> a_int{4, 4, 4};
  a_int = s21::Vector<int>{1};
  EXPECT_EQ(a_int.Size(), 1);
}

TEST(VectorEmplace, EmplaceBack_3) {
  s21::Vector<int> a;
  a.EmplaceBack(7, 7, 7);
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(a[i], 7);
  }
}

TEST(VectorEmplace, EmplaceBack_0) {
  s21::Vector<int> a;
  a.EmplaceBack();
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(a[i], 0);
  }
}

TEST(VectorEmplace, EmplaceBack) {
  s21::Vector<int> a;
  s21::Vector<int> b{1, 2, 5, 3, 4, 6, 8};
  a.EmplaceBack(1, 2, 5, 3, 4, 6, 8);
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(a[i], b[i]);
  }
}

TEST(VectorEmplace, EmplaceBack_7) {
  s21::Vector<std::string> a{"3", "jksd"};
  s21::Vector<std::string> b{"3",   "jksd", "3hk",  "dssff", "sdf",
                             "ert", "etv",  "dsfs", "dg b"};
  a.EmplaceBack("3hk", "dssff", "sdf", "ert", "etv", "dsfs", "dg b");
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(a[i], b[i]);
  }
}

TEST(VectorEmplace, Emplace_1) {
  s21::Vector<int> a;
  a.Emplace(a.Begin(), 39, 39, 39);
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(a[i], 39);
  }
}

TEST(VectorEmplace, Emplace_0) {
  s21::Vector<int> a;
  a.Emplace(a.Begin());
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(a[i], 0);
  }
}

TEST(VectorEmplace, Emplace_string) {
  s21::Vector<std::string> a;
  a.Emplace(a.Begin());
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(a[i], "\0");
  }
}

TEST(VectorEmplace, Emplace_3) {
  s21::Vector<int> a{1, 2};
  s21::Vector<int> b{1, 39, 39, 39, 2};
  a.Emplace(a.Begin() + 1, 39, 39, 39);
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(a[i], b[i]);
  }
}

TEST(VectorEmplace, Emplace_7) {
  s21::Vector<std::string> a{"c", "c"};
  s21::Vector<std::string> b{"c",   "dg b",  "dsfs", "etv", "ert",
                             "sdf", "dssff", "3hk",  "c"};
  a.Emplace(a.Begin() + 1, "3hk", "dssff", "sdf", "ert", "etv", "dsfs", "dg b");
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(a[i], b[i]);
  }
}
