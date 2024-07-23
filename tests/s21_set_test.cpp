#include "../set/s21_set.h"

TEST(SetCapacity, Empty) {
  s21::Set<int> a{1, 2, 3};
  std::set<int> std_a{1, 2, 3};
  EXPECT_EQ(a.Empty(), std_a.empty());
  s21::Set<int> aTemp;
  std::set<int> std_aTemp;
  EXPECT_EQ(aTemp.Empty(), std_aTemp.empty());
}

TEST(SetCapacity, Size) {
  s21::Set<char> aTemp{'a', 'b', 'x', 'z'};
  std::set<char> std_aTemp{'a', 'b', 'x', 'z'};
  EXPECT_EQ(aTemp.Size(), std_aTemp.size());
}

TEST(SetCapacity, MaxSize) {
  s21::Set<double> a;
  EXPECT_TRUE(a.MaxSize());
}

TEST(SetModifiers, Clear) {
  s21::Set<int> a{13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
  std::set<int> std_a{13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
  a.Clear();
  std_a.clear();
  EXPECT_EQ(a.Size(), std_a.size());
}

TEST(SetModifiers, InsertFalse) {
  s21::Set<int> a{13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
  std::set<int> std_a{13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
  auto myPair = a.Insert(8);
  auto originalPair = std_a.insert(8);
  EXPECT_EQ(myPair.second, originalPair.second);
}

TEST(SetModifiers, InsertTrue) {
  s21::Set<int> a{13, 8, 17, 1, 11, 15, 25, 6, 22};
  std::set<int> std_a{13, 8, 17, 1, 11, 15, 25, 6, 22};
  auto myPair = a.Insert(27);
  auto originalPair = std_a.insert(27);
  EXPECT_EQ(myPair.second, originalPair.second);
}

TEST(SetModifiers, InsertFirstSituation) {
  s21::Set<int> a;
  std::set<int> std_a;
  auto myPair = a.Insert(13);
  auto originalPair = std_a.insert(13);
  EXPECT_EQ(*myPair.first, *originalPair.first);
}

TEST(SetModifiers, InsertSecondSituation) {
  s21::Set<int> a{13};
  std::set<int> std_a{13};
  a.Insert(8);
  std_a.insert(8);
  a.Insert(17);
  std_a.insert(17);
  s21::Set<int>::iterator my_it = a.Begin();
  std::set<int>::iterator origina_it = std_a.begin();
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(*my_it, *origina_it);
    ++my_it;
    ++origina_it;
  }
}

TEST(SetModifiers, InsertThirdSituation) {
  s21::Set<int> a{13, 8, 17, 1, 11};
  std::set<int> std_a{13, 8, 17, 1, 11};
  a.Insert(15);
  std_a.insert(15);
  s21::Set<int>::iterator my_it = a.Begin();
  std::set<int>::iterator origina_it = std_a.begin();
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ((*my_it), *origina_it);
    ++my_it;
    ++origina_it;
  }
}

TEST(SetModifiers, InsertFourthSituation) {
  s21::Set<int> a{13, 8, 17, 1, 11, 15, 25};
  std::set<int> std_a{13, 8, 17, 1, 11, 15, 25};
  a.Insert(6);
  std_a.insert(6);
  s21::Set<int>::iterator my_it = a.End();
  std::set<int>::iterator origina_it = std_a.end();
  --my_it;
  --origina_it;
  EXPECT_EQ((*my_it), *origina_it);
}

TEST(SetModifiers, InsertFirthSituation) {
  s21::Set<int> a{13};
  std::set<int> std_a{13};
  a.Insert(13);
  std_a.insert(13);
  s21::Set<int>::iterator my_itTemp = a.Begin();
  std::set<int>::iterator origina_itTemp = std_a.begin();
  while (my_itTemp != a.End()) {
    EXPECT_EQ((*my_itTemp), *origina_itTemp);
    ++my_itTemp;
    ++origina_itTemp;
  }
}

TEST(SetModifiers, InsertSixSituation) {
  s21::Set<int> a{13, 17, 11};
  std::set<int> std_a{13, 17, 11};
  a.Insert(1);
  std_a.insert(1);
  a.Insert(8);
  std_a.insert(8);
  s21::Set<int>::iterator my_itTemp = a.Begin();
  std::set<int>::iterator origina_itTemp = std_a.begin();
  while (my_itTemp != a.End()) {
    EXPECT_EQ((*my_itTemp), *origina_itTemp);
    ++my_itTemp;
    ++origina_itTemp;
  }
}

TEST(SetModifiers, EraseFirstElement) {
  s21::Set<int> a{13, 8, 17, 1, 11, 15, 25};
  std::set<int> std_a{13, 8, 17, 1, 11, 15, 25};
  s21::Set<int>::iterator my_it = a.Begin();
  std::set<int>::iterator origina_it = std_a.begin();
  a.Erase(my_it);
  std_a.erase(origina_it);
  s21::Set<int>::iterator my_itTemp = a.Begin();
  std::set<int>::iterator origina_itTemp = std_a.begin();
  while (my_itTemp != a.End()) {
    EXPECT_EQ((*my_itTemp), *origina_itTemp);
    ++my_itTemp;
    ++origina_itTemp;
  }
}

TEST(SetModifiers, EraseLastElement) {
  s21::Set<int> a{13, 8, 17, 1, 11, 15, 25};
  std::set<int> std_a{13, 8, 17, 1, 11, 15, 25};
  a.Erase(a.Find(25));
  std_a.erase(std_a.find(25));
  s21::Set<int>::iterator my_itTemp = a.Begin();
  std::set<int>::iterator origina_itTemp = std_a.begin();
  while (my_itTemp != a.End()) {
    EXPECT_EQ((*my_itTemp), *origina_itTemp);
    ++my_itTemp;
    ++origina_itTemp;
  }
}

TEST(SetModifiers, EraseMidleElement) {
  s21::Set<int> a{13, 8, 17, 1, 11, 15, 25};
  std::set<int> std_a{13, 8, 17, 1, 11, 15, 25};
  a.Erase(a.Find(13));
  std_a.erase(std_a.find(13));
  s21::Set<int>::iterator my_itTemp = a.Begin();
  std::set<int>::iterator origina_itTemp = std_a.begin();
  while (my_itTemp != a.End()) {
    EXPECT_EQ((*my_itTemp), *origina_itTemp);
    ++my_itTemp;
    ++origina_itTemp;
  }
}

TEST(SetModifiers, EraseOne) {
  s21::Set<int> a{13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
  std::set<int> std_a{13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
  a.Erase(a.Find(6));
  a.Erase(a.Find(13));
  std_a.erase(std_a.find(6));
  std_a.erase(std_a.find(13));
  s21::Set<int>::iterator my_itTemp = a.Begin();
  std::set<int>::iterator origina_itTemp = std_a.begin();
  while (my_itTemp != a.End()) {
    EXPECT_EQ((*my_itTemp), *origina_itTemp);
    ++my_itTemp;
    ++origina_itTemp;
  }
}

TEST(SetModifiers, EraseTwo) {
  s21::Set<int> a{13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
  std::set<int> std_a{13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
  a.Erase(a.Find(13));
  a.Erase(a.Find(25));
  std_a.erase(std_a.find(13));
  std_a.erase(std_a.find(25));
  s21::Set<int>::iterator my_itTemp = a.Begin();
  std::set<int>::iterator origina_itTemp = std_a.begin();
  while (my_itTemp != a.End()) {
    EXPECT_EQ((*my_itTemp), *origina_itTemp);
    ++my_itTemp;
    ++origina_itTemp;
  }
}

TEST(SetModifiers, EraseThird) {
  s21::Set<int> a{13, 8, 1, 11, 15, 25, 2, 13, 123, 23, 26, 14, 16};
  std::set<int> std_a{13, 8, 1, 11, 15, 25, 2, 13, 123, 23, 26, 14, 16};
  a.Erase(a.Find(15));
  a.Erase(a.Find(1));
  a.Erase(a.Find(11));
  std_a.erase(std_a.find(15));
  std_a.erase(std_a.find(1));
  std_a.erase(std_a.find(11));
  s21::Set<int>::iterator my_itTemp = a.Begin();
  std::set<int>::iterator origina_itTemp = std_a.begin();
  while (my_itTemp != a.End()) {
    EXPECT_EQ((*my_itTemp), *origina_itTemp);
    ++my_itTemp;
    ++origina_itTemp;
  }
}

TEST(SetModifiers, EraseFourth) {
  s21::Set<int> a{13, 8, 1, 11, 15, 25, 2, 13, 123, 23, 26, 14, 16};
  std::set<int> std_a{13, 8, 1, 11, 15, 25, 2, 13, 123, 23, 26, 14, 16};
  a.Erase(a.Find(26));
  a.Erase(a.Find(23));
  std_a.erase(std_a.find(26));
  std_a.erase(std_a.find(23));
  s21::Set<int>::iterator my_itTemp = a.Begin();
  std::set<int>::iterator origina_itTemp = std_a.begin();
  while (my_itTemp != a.End()) {
    EXPECT_EQ((*my_itTemp), *origina_itTemp);
    ++my_itTemp;
    ++origina_itTemp;
  }
}

TEST(SetModifiers, Erase5) {
  s21::Set<int> a{13, 15, 17};
  std::set<int> std_a{13, 15, 17};
  a.Erase(a.Find(15));
  std_a.erase(std_a.find(15));
  s21::Set<int>::iterator my_itTemp = a.Begin();
  std::set<int>::iterator origina_itTemp = std_a.begin();
  while (my_itTemp != a.End()) {
    EXPECT_EQ((*my_itTemp), *origina_itTemp);
    ++my_itTemp;
    ++origina_itTemp;
  }
}

TEST(SetModifiers, Erase6) {
  // tree.h str 397
  s21::Set<int> a{13, 15};
  std::set<int> std_a{13, 15};
  a.Erase(a.Find(13));
  std_a.erase(std_a.find(13));
  s21::Set<int>::iterator my_itTemp = a.Begin();
  std::set<int>::iterator origina_itTemp = std_a.begin();
  while (my_itTemp != a.End()) {
    EXPECT_EQ((*my_itTemp), *origina_itTemp);
    ++my_itTemp;
    ++origina_itTemp;
  }
}

TEST(SetModifiers, Erase7) {
  // tree.h successor
  s21::Set<int> a{1, 2, 3};
  std::set<int> std_a{1, 2, 3};
  a.Erase(a.Find(1));
  std_a.erase(std_a.find(1));
  s21::Set<int>::iterator my_itTemp = a.Begin();
  std::set<int>::iterator origina_itTemp = std_a.begin();
  while (my_itTemp != a.End()) {
    EXPECT_EQ((*my_itTemp), *origina_itTemp);
    ++my_itTemp;
    ++origina_itTemp;
  }
}

TEST(SetModifiers, swap) {
  s21::Set<int> a{13, 8, 17, 1, 11, 15, 25};
  s21::Set<int> aTemp{1, 2, 3};
  a.Swap(aTemp);
  s21::Set<int> aEq{1, 2, 3};
  s21::Set<int>::iterator my_it = a.Begin();
  s21::Set<int>::iterator eqIt = aEq.Begin();
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ((*my_it), (*eqIt));
    ++my_it;
    ++eqIt;
  }
}

TEST(SetModifiers, Merge) {
  s21::Set<int> a{13, 8, 17, 1, 11, 15, 25};
  s21::Set<int> aTemp{12, 3, 2};
  std::set<int> std_a{13, 8, 17, 1, 11, 15, 25};
  std::set<int> std_aTemp{12, 3, 2};
  a.Merge(aTemp);
  std_a.merge(std_aTemp);
  s21::Set<int>::iterator my_it = a.Begin();
  std::set<int>::iterator origina_it = std_a.begin();
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ((*my_it), *origina_it);
    ++my_it;
    ++origina_it;
  }
}

TEST(SetLookup, Find) {
  s21::Set<int> a{13, 8, 17, 1, 11, 15, 25};
  std::set<int> std_a{13, 8, 17, 1, 11, 15, 25};
  auto myFind = a.Find(11);
  auto originalFind = std_a.find(11);
  EXPECT_EQ((*myFind), *originalFind);
}

TEST(SetLookup, Contains) {
  s21::Set<int> a{13, 8, 17, 1, 11, 15, 25};
  auto myContains = a.Contains(11);
  EXPECT_TRUE(myContains);
  myContains = a.Contains(123);
  EXPECT_FALSE(myContains);
}

TEST(SetConstructor, CopyConstructor) {
  s21::Set<int> a{13, 8, 17, 1, 11, 15, 25};
  s21::Set<int> copySet(a);
  s21::Set<int>::iterator my_it = a.Begin();
  s21::Set<int>::iterator copyIt = copySet.Begin();
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ((*my_it), (*copyIt));
    ++my_it;
    ++copyIt;
  }
}

TEST(SetConstructor, MoveConstructor) {
  s21::Set<int> a{13, 8, 17, 1, 11, 15, 25};
  s21::Set<int> aTemp{13, 8, 17, 1, 11, 15, 25};
  s21::Set<int> copySet(std::move(a));
  s21::Set<int>::iterator my_it = aTemp.Begin();
  s21::Set<int>::iterator copyIt = copySet.Begin();
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ((*my_it), (*copyIt));
    ++my_it;
    ++copyIt;
  }
}

TEST(SetConstructor, OperatorEqual) {
  s21::Set<int> a{13, 8, 17, 1, 11, 15, 25};
  s21::Set<int> aTemp{13, 8, 17, 1, 11, 15, 25};
  s21::Set<int> copySet;
  copySet = a;
  s21::Set<int>::iterator my_it = aTemp.Begin();
  s21::Set<int>::iterator copyIt = copySet.Begin();
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ((*my_it), (*copyIt));
    ++my_it;
    ++copyIt;
  }
}

TEST(SetIterator, IteratorBegin) {
  s21::Set<int> a{1, 4, 5, 2, 7, 12, 14};
  std::set<int> std_a{1, 4, 5, 2, 7, 12, 14};
  s21::Set<int>::iterator my_it = a.Begin();
  std::set<int>::iterator origina_it = std_a.begin();
  EXPECT_EQ((*my_it), *origina_it);
}

TEST(SetIterator, IteratorEnd) {
  s21::Set<int> a{1, 4, 5, 2, 7, 12, 14};
  std::set<int> std_a{1, 4, 5, 2, 7, 12, 14};
  s21::Set<int>::iterator my_it = a.End();
  std::set<int>::iterator origina_it = std_a.end();
  --my_it;
  --origina_it;
  EXPECT_EQ((*my_it), *origina_it);
}

TEST(SetIterator, IteratorPlus) {
  s21::Set<int> a{1, 4, 5, 2, 7, 12, 14};
  std::set<int> std_a{1, 4, 5, 2, 7, 12, 14};
  s21::Set<int>::iterator my_it = a.Begin();
  std::set<int>::iterator origina_it = std_a.begin();
  ++my_it;
  ++my_it;
  ++my_it;
  ++origina_it;
  ++origina_it;
  ++origina_it;
  EXPECT_EQ((*my_it), *origina_it);
}

TEST(SetIterator, IteratorMinus) {
  s21::Set<int> a{1, 4, 5, 2, 7, 12, 14};
  std::set<int> std_a{1, 4, 5, 2, 7, 12, 14};
  s21::Set<int>::iterator my_it = a.End();
  std::set<int>::iterator origina_it = std_a.end();
  --my_it;
  --my_it;
  --my_it;
  --origina_it;
  --origina_it;
  --origina_it;
  EXPECT_EQ((*my_it), *origina_it);
}

TEST(SetIterator, DecrementBeginEmpty) {
  s21::Set<int> s1;
  s21::Set<int>::iterator it1 = s1.Begin();

  ASSERT_ANY_THROW(--it1);
  ASSERT_ANY_THROW(*it1);
}

TEST(SetIterator, IteratorBonus) {
  s21::Set<int> a{1, 4, 5, 2, 7, 12, 14};
  std::set<int> std_a{1, 4, 5, 2, 7, 12, 14};
  s21::Set<int>::iterator my_it = a.Begin();
  std::set<int>::iterator origina_it = std_a.begin();
  ++my_it;
  ++my_it;
  ++origina_it;
  ++origina_it;
  --my_it;
  --my_it;
  --origina_it;
  --origina_it;
  EXPECT_EQ((*my_it), *origina_it);
}

TEST(SetIterator, IteratorEqual) {
  s21::Set<int> a{1, 5, 10};
  s21::Set<int>::iterator it1 = a.Begin();
  s21::Set<int>::iterator it2 = a.End();
  ++it1;
  --it2;
  --it2;
  EXPECT_TRUE(it1 == it2);
}

TEST(SetIterator, IteratorNotEqual) {
  s21::Set<int> a{1, 4, 5, 2, 7, 12, 14};
  std::set<int> std_a{1, 4, 5, 2, 7, 12, 14};
  s21::Set<int>::iterator my_it = a.Begin();
  std::set<int>::iterator origina_it = std_a.begin();
  EXPECT_FALSE((*my_it) != *origina_it);
}

TEST(SetEmplace, EmplaceFirst) {
  s21::Set<int> a;
  auto myPair = a.Emplace(21, 31);
  EXPECT_EQ(*myPair[0].first, 21);
  EXPECT_EQ(*myPair[1].first, 31);
}

TEST(SetEmplace, EmplaceSecond) {
  s21::Set<int> a;
  auto myPair = a.Emplace();
  EXPECT_EQ(myPair.Size(), 1);
}

TEST(SetEmplace, EmplaceThird) {
  s21::Set<int> a{21};
  auto myPair = a.Emplace(21);
  EXPECT_FALSE(myPair[0].second);
}

TEST(SetMoveConstructor, MoveConstructor) {
  s21::Set<int> s2;
  s21::Set<int> s1{3, 2};
  s21::Set<int> res{3, 2};
  s2 = std::move(s1);
  EXPECT_EQ(s2.Size(), res.Size());
  for (auto it1 = s2.Begin(), it2 = res.Begin(); it1 != s2.End(); ++it1) {
    EXPECT_EQ(*it1, *it2);
    ++it2;
  }
}

TEST(SetCopyConstructor, CopyConstructor1) {
  s21::Set<int> s2;
  s21::Set<int> s1(s2);
  EXPECT_EQ(s2.Size(), s1.Size());
}

TEST(SetCopyConstructor, CopyConstructor2) {
  s21::Set<int> s2;
  s21::Set<int> s1{3, 2};
  s2 = s1;
  EXPECT_EQ(s2.Size(), s1.Size());
}
