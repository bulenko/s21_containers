#include "../map/s21_map.h"

TEST(MapElementAccess, At1) {
  s21::Map<int, std::string> m1 = s21::Map<int, std::string>{{0, "pear"}};
  std::map<int, std::string> m2 = {{0, "pear"}};
  ASSERT_EQ(m1.At(0), m2.at(0));
}

TEST(MapElementAccess, At2) {
  s21::Map<int, std::string> m1 = s21::Map<int, std::string>{{1, "pear"}};
  EXPECT_THROW(m1.At(24), std::exception);
}

TEST(MapElementAccess, SquareBrackets1) {
  s21::Map<int, std::string> m1 =
      s21::Map<int, std::string>{{1, "pear"}, {4, "apple"}};
  std::map<int, std::string> m2 = {{1, "pear"}, {4, "apple"}};
  ASSERT_EQ(m1[4], m2[4]);
  ASSERT_EQ(m1[1], m2[1]);
}

TEST(MapElementAccess, SquareBrackets2) {
  s21::Map<int, std::string> m1 =
      s21::Map<int, std::string>{{1, "pear"}, {4, "apple"}};
  std::map<int, std::string> m2 = {{1, "pear"}, {4, "apple"}};
  m1[2] = "cherry";
  m2[2] = "cherry";
  ASSERT_EQ(m1[2], m2[2]);
}

TEST(MapElementAccess, SquareBrackets3) {
  s21::Map<int, std::string> m1 =
      s21::Map<int, std::string>{{1, "pear"}, {4, "apple"}};
  std::map<int, std::string> m2 = {{1, "pear"}, {4, "apple"}};
  m1[1] = "cherry";
  m2[1] = "cherry";
  ASSERT_EQ(m1[1], m2[1]);
}

TEST(MapCapacity, Empty) {
  s21::Map<int, std::string> m1 = s21::Map<int, std::string>{{4, "apple"}};
  std::map<int, std::string> m2 = {{4, "apple"}};
  EXPECT_EQ(m1.Empty(), m2.empty());

  s21::Map<int, std::string> ma;
  std::map<int, std::string> mb;
  ASSERT_EQ(ma.Empty(), mb.empty());
}

TEST(MapCapacity, Size) {
  s21::Map<int, std::string> m1 = s21::Map<int, std::string>{{4, "apple"}};
  std::map<int, std::string> m2 = {{4, "apple"}};
  ASSERT_EQ(m1.Size(), m2.size());

  s21::Map<int, std::string> ma;
  std::map<int, std::string> mb;
  ASSERT_EQ(ma.Size(), mb.size());
}

TEST(MapCapacity, MaxSize) {
  s21::Map<int, std::string> a;
  EXPECT_TRUE(a.MaxSize());
}

TEST(MapModifiers, Clear) {
  s21::Map<int, std::string> m1 = s21::Map<int, std::string>{{4, "apple"}};
  std::map<int, std::string> m2 = {{4, "apple"}};
  m1.Clear();
  m2.clear();
  ASSERT_EQ(m1.Size(), m2.size());
}

TEST(MapModifiers, Insert1) {
  s21::Map<int, std::string> m1;
  std::map<int, std::string> m2;
  std::pair<int, std::string> k = {152, "apple"};
  auto it_m1 = m1.Insert(k);
  auto it_m2 = m2.insert(k);

  EXPECT_EQ(it_m1.second, it_m2.second);                 // bool
  EXPECT_EQ(it_m1.first.First(), it_m2.first->first);    // key
  EXPECT_EQ(it_m1.first.Second(), it_m2.first->second);  // value
}

TEST(MapModifiers, Insert2) {
  s21::Map<int, std::string> m1 = s21::Map<int, std::string>{{4, "apple"}};
  std::map<int, std::string> m2 = {{4, "apple"}};
  std::pair<int, std::string> k = {10, "cherry"};
  auto it_m1 = m1.Insert(k);
  auto it_m2 = m2.insert(k);
  EXPECT_EQ((*(it_m1.first)).first, (*(it_m2.first)).first);    // key
  EXPECT_EQ((*(it_m1.first)).second, (*(it_m2.first)).second);  // value
  s21::Map<int, std::string>::iterator it1 = m1.Begin();
  std::map<int, std::string>::iterator it2 = m2.begin();
  for (size_t i = 0; i < m1.Size(); i++) {
    EXPECT_EQ((*it1).first, (*it2).first);
    EXPECT_EQ((*it1).second, (*it2).second);
    ++it1;
    ++it2;
  }
}

TEST(MapModifiers, Insert3) {
  s21::Map<char, double> m1 = s21::Map<char, double>{{'s', 125.365}};
  std::map<char, double> m2 = {{'s', 125.365}};
  std::pair<char, double> k = {'a', 488.02255};
  auto it_m1 = m1.Insert(k);
  auto it_m2 = m2.insert(k);
  EXPECT_EQ((*(it_m1.first)).first, (*(it_m2.first)).first);    // key
  EXPECT_EQ((*(it_m1.first)).second, (*(it_m2.first)).second);  // value
  s21::Map<char, double>::iterator it1 = m1.Begin();
  std::map<char, double>::iterator it2 = m2.begin();
  for (size_t i = 0; i < m1.Size(); i++) {
    EXPECT_EQ((*it1).first, (*it2).first);
    EXPECT_EQ((*it1).second, (*it2).second);
    ++it1;
    ++it2;
  }
}

TEST(MapModifiers, Insert4) {
  s21::Map<char, double> m1;
  std::map<char, double> m2;
  auto it_m1 = m1.Insert(std::pair<char, double>('n', 0.20251));
  auto it_m2 = m2.insert(std::pair<char, double>('n', 0.20251));
  EXPECT_EQ((*(it_m1.first)).first, (*(it_m2.first)).first);    // key
  EXPECT_EQ((*(it_m1.first)).second, (*(it_m2.first)).second);  // value
  s21::Map<char, double>::iterator it1 = m1.Begin();
  std::map<char, double>::iterator it2 = m2.begin();
  for (size_t i = 0; i < m1.Size(); i++) {
    EXPECT_EQ((*it1).first, (*it2).first);
    EXPECT_EQ((*it1).second, (*it2).second);
    ++it1;
    ++it2;
  }
}

TEST(MapModifiers, Insert5) {
  s21::Map<int, int> m1{{10, 3}, {15, 1}, {16, 2}, {0, 1}, {5, 3}, {3, 2}};
  std::map<int, int> m2{{10, 3}, {15, 1}, {16, 2}, {0, 1}, {5, 3}, {3, 2}};
  m1.Insert(std::pair<int, int>(12, 1));
  m2.insert(std::pair<int, int>(12, 1));

  s21::Map<int, int>::iterator it1 = m1.Begin();
  std::map<int, int>::iterator it2 = m2.begin();
  for (; it1 != m1.End(); ++it1) {
    EXPECT_EQ((*it1).first, (*it2).first);
    EXPECT_EQ((*it1).second, (*it2).second);
    ++it2;
  }
}

TEST(MapModifiers, Insert2Parameters1) {
  s21::Map<int, std::string> m1 = s21::Map<int, std::string>{{4, "apple"}};
  std::map<int, std::string> m2 = {{4, "apple"}};
  auto it_m1 = m1.Insert(10, "cherry");
  auto it_m2 = m2.insert({10, "cherry"});
  EXPECT_EQ(it_m1.first.First(), it_m2.first->first);    // key
  EXPECT_EQ(it_m1.first.Second(), it_m2.first->second);  // value
  s21::Map<int, std::string>::iterator it1 = m1.Begin();
  std::map<int, std::string>::iterator it2 = m2.begin();
  for (size_t i = 0; i < m1.Size(); i++) {
    EXPECT_EQ(it1.First(), it2->first);    // key
    EXPECT_EQ(it1.Second(), it2->second);  // value
    ++it1;
    ++it2;
  }
}

TEST(MapModifiers, InsertOrAssign) {
  s21::Map<int, char> m1 = s21::Map<int, char>{{1, 'n'}, {2, 'a'}};
  std::map<int, char> m2{{1, 'n'}, {2, 'a'}};
  auto it_m1 = m1.InsertOrAssign(1, 'v');
  auto it_m2 = m2.insert_or_assign(1, 'v');

  EXPECT_EQ(it_m1.first.First(), it_m2.first->first);    // key
  EXPECT_EQ(it_m1.first.Second(), it_m2.first->second);  // value

  m1.InsertOrAssign(10, 'v');
  m2.insert_or_assign(10, 'v');
  s21::Map<int, char>::iterator it1 = m1.Begin();
  std::map<int, char>::iterator it2 = m2.begin();
  for (size_t i = 0; i < m1.Size(); i++) {
    EXPECT_EQ(it1.First(), it2->first);    // key
    EXPECT_EQ(it1.Second(), it2->second);  // value
    ++it1;
    ++it2;
  }
}

TEST(MapModifiers, Erase1) {
  s21::Map<int, std::string> m1 = s21::Map<int, std::string>{{4, "apple"}};
  std::map<int, std::string> m2 = {{4, "apple"}};
  s21::Map<int, std::string>::iterator it_m1 = m1.Begin();
  std::map<int, std::string>::iterator it_m2 = m2.begin();

  m1.Erase(it_m1);
  m2.erase(it_m2);
  EXPECT_EQ(m1.Empty(), m2.empty());
}

TEST(MapModifiers, Erase2_1) {
  s21::Map<int, char> m1 =
      s21::Map<int, char>{{10, 'n'}, {8, 'a'}, {5, 'n'}, {6, 't'}};
  std::map<int, char> m2{{10, 'n'}, {8, 'a'}, {5, 'n'}, {6, 't'}};
  m1.Erase(m1.Begin());
  m2.erase(m2.begin());
  s21::Map<int, char>::iterator it1 = m1.Begin();
  std::map<int, char>::iterator it2 = m2.begin();
  for (size_t i = 0; i < m1.Size(); i++) {
    EXPECT_EQ(it1.First(), it2->first);    // key
    EXPECT_EQ(it1.Second(), it2->second);  // value
    ++it1;
    ++it2;
  }
}

TEST(MapModifiers, Erase2_2) {
  // tree_.h str 272,273
  s21::Map<int, char> m1 = s21::Map<int, char>{
      {15, 'n'}, {8, 'a'}, {5, 'n'}, {6, 't'}, {10, 'j'}, {12, 'd'}, {13, 'e'}};
  std::map<int, char> m2{{15, 'n'}, {8, 'a'},  {5, 'n'}, {6, 't'},
                         {10, 'j'}, {12, 'd'}, {13, 'e'}};
  s21::Map<int, char>::iterator it1 = m1.End();
  std::map<int, char>::iterator it2 = m2.end();
  --it1;
  --it1;
  --it1;
  m1.Erase(it1);
  --it2;
  --it2;
  --it2;
  m2.erase(it2);
  it1 = m1.Begin();
  it2 = m2.begin();
  for (size_t i = 0; i < m1.Size(); i++) {
    EXPECT_EQ(it1.First(), it2->first);    // key
    EXPECT_EQ(it1.Second(), it2->second);  // value
    ++it1;
    ++it2;
  }
}

TEST(MapModifiers, Erase3_1) {
  s21::Map<int, char> m1 =
      s21::Map<int, char>{{10, 'n'}, {8, 'a'}, {5, 'n'}, {6, 't'}, {3, 'y'}};
  std::map<int, char> m2{{10, 'n'}, {8, 'a'}, {5, 'n'}, {6, 't'}, {3, 'y'}};
  s21::Map<int, char>::iterator it1 = m1.Begin();
  ++it1;
  std::map<int, char>::iterator it2 = m2.begin();
  ++it2;
  m1.Erase(it1);  // удаляем key = 5
  m2.erase(it2);
  it1 = m1.Begin();
  it2 = m2.begin();
  for (size_t i = 0; i < m1.Size(); i++) {
    EXPECT_EQ(it1.First(), it2->first);    // key
    EXPECT_EQ(it1.Second(), it2->second);  // value
    ++it1;
    ++it2;
  }
}

TEST(MapModifiers, Erase3_2) {
  // tree_.h str 288
  s21::Map<int, char> m1 =
      s21::Map<int, char>{{10, 'n'}, {8, 'a'}, {5, 'n'}, {1, 't'}, {3, 'y'}};
  std::map<int, char> m2{{10, 'n'}, {8, 'a'}, {5, 'n'}, {1, 't'}, {3, 'y'}};
  s21::Map<int, char>::iterator it1 = m1.Begin();
  ++it1;
  ++it1;
  ++it1;
  std::map<int, char>::iterator it2 = m2.begin();
  ++it2;
  ++it2;
  ++it2;
  m1.Erase(it1);  // удаляем key = 5
  m2.erase(it2);
  it1 = m1.Begin();
  it2 = m2.begin();
  for (size_t i = 0; i < m1.Size(); i++) {
    EXPECT_EQ(it1.First(), it2->first);    // key
    EXPECT_EQ(it1.Second(), it2->second);  // value
    ++it1;
    ++it2;
  }
}

TEST(MapModifiers, EraseEmpty) {
  s21::Map<int, std::string> m1;
  m1.Erase(m1.Begin());
  EXPECT_EQ(m1.Empty(), 1);
}

TEST(MapModifiers, EraseRoot1) {
  s21::Map<int, int> m1{{10, 3}, {15, 1}, {16, 2}, {0, 1}, {5, 3}, {3, 2}};
  s21::Map<int, int> res{{0, 1}, {3, 2}, {5, 3}, {15, 1}, {16, 2}};
  s21::Map<int, int>::iterator it1 = m1.Begin();
  s21::Map<int, int>::iterator it2 = res.Begin();
  ++it1;
  ++it1;
  ++it1;
  m1.Erase(it1);

  it1 = m1.Begin();
  for (; it1 != m1.End(); ++it1) {
    EXPECT_EQ((*it1).first, (*it2).first);
    EXPECT_EQ((*it1).second, (*it2).second);
    ++it2;
  }
}

TEST(MapModifiers, EraseRoot3) {
  // удаляем корень, если есть правый потомок и нет левого потомка
  s21::Map<int, int> m1{{10, 3}, {11, 4}};
  s21::Map<int, int> res{{11, 4}};
  m1.Erase(m1.Begin());  // удалили 10

  s21::Map<int, int>::iterator it1 = m1.Begin();
  s21::Map<int, int>::iterator it2 = res.Begin();
  EXPECT_EQ(m1.Size(), 1);
  EXPECT_EQ((*it1).first, (*it2).first);
}

TEST(MapModifiers, Swap) {
  s21::Map<int, char> m1 = s21::Map<int, char>{{1, 'n'}, {2, 'a'}};
  s21::Map<int, char> mt{{3, 'j'}, {4, 'i'}};
  m1.Swap(mt);
  s21::Map<int, char> new_m1{{3, 'j'}, {4, 'i'}};
  s21::Map<int, char>::iterator it1 = m1.Begin();
  s21::Map<int, char>::iterator it2 = new_m1.Begin();
  for (size_t i = 0; i < m1.Size(); i++) {
    EXPECT_EQ(it1.First(), it2.First());    // key
    EXPECT_EQ(it1.Second(), it2.Second());  // value;
    ++it1;
    ++it2;
  }
}

TEST(MapModifiers, Merge) {
  s21::Map<int, char> m1_1 = s21::Map<int, char>{{1, 'n'}, {2, 'a'}};
  s21::Map<int, char> m1_2{{1, 'l'}, {3, 'k'}};
  std::map<int, char> m2_1 = {{1, 'n'}, {2, 'a'}};
  std::map<int, char> m2_2{{1, 'l'}, {3, 'k'}};
  m1_1.Merge(m1_2);
  m2_1.merge(m2_2);
  s21::Map<int, char>::iterator it1 = m1_1.Begin();
  std::map<int, char>::iterator it2 = m2_1.begin();
  for (size_t i = 0; i < m1_1.Size(); i++) {
    EXPECT_EQ(it1.First(), it2->first);    // key
    EXPECT_EQ(it1.Second(), it2->second);  // value;
    ++it1;
    ++it2;
  }

  s21::Map<int, char>::iterator it1_2 = m1_2.Begin();
  std::map<int, char>::iterator it2_2 = m2_2.begin();
  for (size_t i = 0; i < m1_2.Size(); i++) {
    EXPECT_EQ(it1_2.First(), it2_2->first);    // key
    EXPECT_EQ(it1_2.Second(), it2_2->second);  // value;
    ++it1;
    ++it2;
  }
}

TEST(MapModifiers, Contains) {
  s21::Map<int, int> m{{1, 2}, {5, 6}};
  EXPECT_TRUE(m.Contains(1));
  EXPECT_FALSE(m.Contains(7));
}

TEST(MapConstructor, MoveConstructor) {
  s21::Map<int, int> m{{1, 2}, {5, 6}};
  s21::Map<int, int> res{{1, 2}, {5, 6}};
  s21::Map<int, int> m_copy(std::move(m));
  s21::Map<int, int>::iterator it1 = res.Begin();
  s21::Map<int, int>::iterator it2 = m_copy.Begin();
  for (size_t i = 0; i < res.Size(); i++) {
    EXPECT_EQ(it1.First(), it2.First());    // key
    EXPECT_EQ(it1.Second(), it2.Second());  // value;
    ++it1;
    ++it2;
  }
}

TEST(MapConstructor, EmptyMap) {
  s21::Map<int, int> m1{};
  EXPECT_EQ(m1.Size(), 0);
}

TEST(MapIterator, DecrementEnd) {
  s21::Map<int, int> m1{{1, 2}, {5, 6}};
  std::map<int, int> m2{{1, 2}, {5, 6}};
  s21::Map<int, int>::iterator it1 = m1.End();
  std::map<int, int>::iterator it2 = m2.end();
  --it1;
  --it2;
  EXPECT_EQ((*it1).first, (*it1).first);
  EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(MapIterator, DecrementBegin) {
  s21::Map<int, int> m1{{1, 2}, {5, 6}};
  s21::Map<int, int>::iterator it1 = m1.Begin();
  --it1;
  EXPECT_EQ(it1.First(), 1);
  EXPECT_EQ(it1.Second(), 2);
}

TEST(MapIterator, DecrementBeginEmpty) {
  s21::Map<int, int> m1;
  s21::Map<int, int>::iterator it1 = m1.Begin();

  ASSERT_ANY_THROW(--it1);

  ASSERT_ANY_THROW((*it1).first);
  ASSERT_ANY_THROW((*it1).second);

  it1 = m1.Begin();
  ASSERT_ANY_THROW(it1.First());
  ASSERT_ANY_THROW(it1.Second());
}

TEST(MapIterator, IteratorMinus) {
  s21::Map<int, double> m1{{1, 2}, {5, 6}};
  std::map<int, double> m2{{1, 2}, {5, 6}};
  s21::Map<int, double>::iterator it1 = m1.End();
  std::map<int, double>::iterator it2 = m2.end();
  --it1;
  --it1;
  --it2;
  --it2;
  EXPECT_EQ((*it1).first, (*it2).first);
  EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(MapIterator, IteratorEqual) {
  s21::Map<int, std::string> ma{{1, "apple"}, {5, "pear"}, {10, "banana"}};
  s21::Map<int, std::string>::iterator it1 = ma.Begin();
  s21::Map<int, std::string>::iterator it2 = ma.End();
  ++it1;
  --it2;
  --it2;
  EXPECT_TRUE(it1 == it2);
}

TEST(MapCopyConstructor, CopyConstructor1) {
  s21::Map<int, int> m2;
  s21::Map<int, int> m1(m2);
  EXPECT_EQ(m2.Size(), m1.Size());
}

TEST(MapCopyConstructor, CopyConstructor2) {
  s21::Map<int, int> m2;
  s21::Map<int, int> m1{{3, 2}};
  m2 = m1;
  EXPECT_EQ(m2.Size(), m1.Size());
}

TEST(MapCopyConstructor, CopyConstructor4) {
  s21::Map<int, int> m2;
  s21::Map<int, int> m1{{3, 2}};
  s21::Map<int, int> res{{3, 2}};
  m2 = std::move(m1);
  EXPECT_EQ(m2.Size(), 1);
  for (auto it1 = m2.Begin(), it2 = res.Begin(); it1 != m2.End(); ++it1) {
    EXPECT_EQ((*it1).first, (*it2).first);
    EXPECT_EQ((*it1).second, (*it2).second);
    ++it2;
  }
}

TEST(MapCopyConstructor, CopyConstructor3) {
  s21::Map<int, std::string> m2{{5, "apple"}};
  s21::Map<int, std::string> m1(m2);
  EXPECT_EQ(m2.Size(), m1.Size());
}

TEST(MapInsert, InsertSquareBracket) {
  s21::Map<int, int> m2;
  m2[2] = 5;
  EXPECT_EQ(m2.Size(), 1);
}

TEST(MapCopyConstructor, CopyTree1) {
  s21::Map<int, int> m2{{2, 3}, {-1, 3}};
  s21::Map<int, int> m1;
  m1 = m2;
  EXPECT_EQ(m2.Size(), m1.Size());
}

TEST(MapCopyConstructor, CopyTree2) {
  s21::Map<int, int> m2{{2, 3}, {5, 3}};
  s21::Map<int, int> m1;
  m1 = m2;
  EXPECT_EQ(m2.Size(), m1.Size());
}

TEST(MapCopyConstructor, CopyTree3) {
  // уничтожили объект и его копировали. В root - nullptr
  s21::Map<int, int> m2{{2, 3}, {5, 3}};
  s21::Map<int, int> m1;
  m1.~Map();
  m2 = m1;
  EXPECT_EQ(m2.Size(), m1.Size());
}

TEST(MapPredecessor, Predecessor) {
  // уничтожили объект и его копировали. В root - nullptr
  s21::Map<int, int> m2{{2, 3}, {5, 3},   {4, 7}, {12, 12},
                        {8, 7}, {14, 13}, {11, 7}};

  auto it = m2.End();
  for (size_t i = 0; i < m2.Size(); ++i) {
    --it;
  }
  EXPECT_EQ((*it).first, 2);
  EXPECT_EQ((*it).second, 3);
}

TEST(MapEmplace, Emplace) {
  s21::Map<int, int> m1{{1, 2}, {5, 6}};
  s21::Map<int, int> res{{1, 2}, {5, 6}, {0, 0}, {3, 4}, {7, 7}};
  m1.Emplace(std::pair<int, int>(0, 0), std::pair<int, int>(3, 4),
             std::pair<int, int>(7, 7));
  EXPECT_EQ(m1[0], res[0]);
  EXPECT_EQ(m1[3], res[3]);
  EXPECT_EQ(res.Size(), m1.Size());
}

TEST(MapEmplace, Emplace1) {
  s21::Map<int, int> m;
  m.Emplace();
  EXPECT_EQ(m.Size(), 1);
}

TEST(MapEmplace, Emplace2) {
  s21::Map<int, int> m1{{1, 1}, {2, 2}};
  std::map<int, int> m2{{1, 1}, {2, 2}};
  m1.Emplace(std::pair(2, 3));
  m2.emplace(std::pair(2, 3));
  s21::Map<int, int>::iterator it1 = m1.Begin();
  std::map<int, int>::iterator it2 = m2.begin();

  for (size_t i = 0; i < m1.Size(); i++) {
    EXPECT_EQ(it1.First(), it1.Second());
    EXPECT_EQ(it2->first, it2->second);
    ++it1;
    ++it2;
  }
  EXPECT_EQ(m1.Size(), m2.size());
}
