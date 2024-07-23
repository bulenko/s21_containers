#include "../multiset/s21_multiset.h"

TEST(MultisetCapacity, Empty) {
  s21::Multiset<int> a{1, 2, 3, 3};
  std::multiset<int> b{1, 2, 3, 3};
  EXPECT_EQ(a.Empty(), b.empty());

  s21::Multiset<int> aTemp;
  std::multiset<int> bTemp;
  EXPECT_EQ(aTemp.Empty(), bTemp.empty());
}

TEST(MultisettCapacity, Size) {
  s21::Multiset<char> aTemp{'a', 'b', 'x', 'z'};
  std::multiset<char> bTemp{'a', 'b', 'x', 'z'};
  EXPECT_EQ(aTemp.Size(), bTemp.size());
}

TEST(MultisetCapacity, MaxSize) {
  s21::Multiset<double> a;
  EXPECT_TRUE(a.MaxSize());
}

TEST(MultisetModifiers, Clear) {
  s21::Multiset<std::string> a{"21", "BRYAN", "PROGRAMMER", "TEST"};
  std::multiset<std::string> b{"21", "BRYAN", "PROGRAMMER", "TEST"};
  a.Clear();
  b.clear();
  EXPECT_EQ(a.Size(), b.size());
}

TEST(MultisetModifiers, InsertFirstSituation) {
  s21::Multiset<double> a;
  std::multiset<double> b;
  s21::Multiset<double>::iterator myIt = a.Insert(13.21);
  std::multiset<double>::iterator originalIt = b.insert(13.21);
  EXPECT_EQ(myIt.First(), *originalIt);
}

TEST(MultisetModifiers, InsertSecondSituation) {
  s21::Multiset<int> a{13};
  std::multiset<int> b{13};
  a.Insert(8);
  b.insert(8);
  a.Insert(17);
  b.insert(17);
  s21::Multiset<int>::iterator myIt = a.Begin();
  std::multiset<int>::iterator originalIt = b.begin();
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(myIt.First(), *originalIt);
    ++myIt;
    ++originalIt;
  }
}

TEST(MultisetModifiers, InsertThirdSituation) {
  s21::Multiset<int> a{13, 8, 17, 1, 11};
  std::multiset<int> b{13, 8, 17, 1, 11};
  a.Insert(15);
  b.insert(15);
  s21::Multiset<int>::iterator myIt = a.Begin();
  std::multiset<int>::iterator originalIt = b.begin();
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(myIt.First(), *originalIt);
    ++myIt;
    ++originalIt;
  }
}

TEST(MultisetModifiers, InsertFourthSituation) {
  s21::Multiset<int> a{13, 8, 17, 1, 11, 15, 25};
  std::multiset<int> b{13, 8, 17, 1, 11, 15, 25};
  a.Insert(6);
  b.insert(6);
  s21::Multiset<int>::iterator myIt = a.End();
  std::multiset<int>::iterator originalIt = b.end();
  --myIt;
  --originalIt;
  EXPECT_EQ(myIt.First(), *originalIt);
}

TEST(MultisetModifiers, InsertFithSituation) {
  s21::Multiset<char> a{'a', 'a', 'v'};
  std::multiset<char> b{'a', 'a', 'v'};
  a.Insert('a');
  b.insert('a');
  s21::Multiset<char>::iterator myIt = a.End();
  std::multiset<char>::iterator originalIt = b.end();
  --myIt;
  --originalIt;
  EXPECT_EQ(myIt.First(), *originalIt);
}

TEST(MultisetModifiers, EraseFirstElement) {
  s21::Multiset<int> a{13, 8, 17, 1, 11, 15, 25};
  std::multiset<int> b{13, 8, 17, 1, 11, 15, 25};
  s21::Multiset<int>::iterator myIt = a.Begin();
  std::multiset<int>::iterator originalIt = b.begin();
  a.Erase(myIt);
  b.erase(originalIt);
  s21::Multiset<int>::iterator myItTemp = a.Begin();
  std::multiset<int>::iterator originalItTemp = b.begin();
  while (myItTemp != a.End()) {
    EXPECT_EQ(myItTemp.First(), *originalItTemp);
    ++myItTemp;
    ++originalItTemp;
  }
}

TEST(MultisetModifiers, EraseLastElement) {
  s21::Multiset<int> a{13, 8, 17, 1, 11, 15, 25};
  std::multiset<int> b{13, 8, 17, 1, 11, 15, 25};
  a.Erase(a.Find(25));
  b.erase(b.find(25));
  s21::Multiset<int>::iterator myItTemp = a.Begin();
  std::multiset<int>::iterator originalItTemp = b.begin();
  while (myItTemp != a.End()) {
    EXPECT_EQ(myItTemp.First(), *originalItTemp);
    ++myItTemp;
    ++originalItTemp;
  }
}

TEST(MultisetModifiers, EraseMidleElement) {
  s21::Multiset<int> a{13, 8, 17, 1, 11, 15, 25};
  std::multiset<int> b{13, 8, 17, 1, 11, 15, 25};
  a.Erase(a.Find(13));
  b.erase(b.find(13));
  s21::Multiset<int>::iterator myItTemp = a.Begin();
  std::multiset<int>::iterator originalItTemp = b.begin();
  while (myItTemp != a.End()) {
    EXPECT_EQ(myItTemp.First(), *originalItTemp);
    ++myItTemp;
    ++originalItTemp;
  }
}

TEST(MultisetModifiers, Swap) {
  s21::Multiset<int> a{13, 8, 17, 1, 11, 15, 25};
  s21::Multiset<int> aTemp{1, 2, 3};
  a.Swap(aTemp);
  s21::Multiset<int> aEq{1, 2, 3};
  s21::Multiset<int>::iterator myIt = a.Begin();
  s21::Multiset<int>::iterator eqIt = aEq.Begin();
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(myIt.First(), eqIt.First());
    ++myIt;
    ++eqIt;
  }
}

TEST(MultisetModifiers, Merge) {
  s21::Multiset<int> a{13, 8, 17, 1, 11, 15, 25};
  s21::Multiset<int> aTemp{12, 3, 2};
  std::multiset<int> b{13, 8, 17, 1, 11, 15, 25};
  std::multiset<int> bTemp{12, 3, 2};
  a.Merge(aTemp);
  b.merge(bTemp);
  s21::Multiset<int>::iterator myIt = a.Begin();
  std::multiset<int>::iterator originalIt = b.begin();
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(myIt.First(), *originalIt);
    ++myIt;
    ++originalIt;
  }
}

TEST(MultisetLookup, Find) {
  s21::Multiset<int> a{13, 8, 17, 1, 11, 15, 25};
  std::multiset<int> b{13, 8, 17, 1, 11, 15, 25};
  auto myFind = a.Find(11);
  auto originalFind = b.find(11);
  EXPECT_EQ(myFind.First(), *originalFind);
}

TEST(MultisetLookup, Contains) {
  s21::Multiset<int> a{13, 8, 17, 1, 11, 15, 25};
  auto myContains = a.Contains(11);
  EXPECT_TRUE(myContains);
  myContains = a.Contains(123);
  EXPECT_FALSE(myContains);
}

TEST(MultisetLookup, LowerBoundFirst) {
  s21::Multiset<int> a{13, 8, 17, 1, 11, 15, 25};
  std::multiset<int> b{13, 8, 17, 1, 11, 15, 25};
  s21::Multiset<int>::iterator myIt = a.LowerBound(1);
  std::multiset<int>::iterator originalIt = b.lower_bound(1);
  EXPECT_EQ(myIt.First(), *originalIt);
}

TEST(MultisetLookup, LowerBoundSecond) {
  s21::Multiset<char> a{'a', 'b', 'b', 'd'};
  std::multiset<char> b{'a', 'b', 'b', 'd'};
  s21::Multiset<char>::iterator myIt = a.LowerBound('a');
  std::multiset<char>::iterator originalIt = b.lower_bound('a');
  EXPECT_EQ(myIt.First(), *originalIt);
}

TEST(MultisetLookup, LowerBoundThird) {
  s21::Multiset<char> a{'a', 'b', 'b', 'd'};
  std::multiset<char> b{'a', 'b', 'b', 'd'};
  s21::Multiset<char>::iterator myIt = a.LowerBound('b');
  std::multiset<char>::iterator originalIt = b.lower_bound('b');
  EXPECT_EQ(myIt.First(), *originalIt);
}

TEST(MultisetLookup, UpperBoundFirst) {
  s21::Multiset<int> a{13, 8, 17, 1, 11, 15, 25};
  std::multiset<int> b{13, 8, 17, 1, 11, 15, 25};
  s21::Multiset<int>::iterator myIt = a.UpperBound(1);
  std::multiset<int>::iterator originalIt = b.upper_bound(1);
  EXPECT_EQ(myIt.First(), *originalIt);
}

TEST(MultisetLookup, UpperBoundSecond) {
  s21::Multiset<char> a{'a', 'b', 'b', 'd'};
  std::multiset<char> b{'a', 'b', 'b', 'd'};
  s21::Multiset<char>::iterator myIt = a.UpperBound('a');
  std::multiset<char>::iterator originalIt = b.upper_bound('a');
  EXPECT_EQ(myIt.First(), *originalIt);
}

TEST(MultisetLookup, UpperBoundThird) {
  s21::Multiset<char> a{'a', 'b', 'b', 'd'};
  std::multiset<char> b{'a', 'b', 'b', 'd'};
  s21::Multiset<char>::iterator myIt = a.UpperBound('b');
  std::multiset<char>::iterator originalIt = b.upper_bound('b');
  EXPECT_EQ(myIt.First(), *originalIt);
}

TEST(MultisetLookup, EqualRangeFirst) {
  s21::Multiset<int> a{13, 8, 17, 1, 11, 15, 25};
  std::multiset<int> b{13, 8, 17, 1, 11, 15, 25};
  auto myPair = a.EqualRange(1);
  auto originalPair = b.equal_range(1);
  EXPECT_EQ(myPair.first.First(), *originalPair.first);
  EXPECT_EQ(myPair.second.First(), *originalPair.second);
}

TEST(MultisetLookup, EqualRangeSecond) {
  s21::Multiset<char> a{'a', 'b', 'b', 'd'};
  std::multiset<char> b{'a', 'b', 'b', 'd'};
  auto myPair = a.EqualRange('a');
  auto originalPair = b.equal_range('a');
  EXPECT_EQ(myPair.first.First(), *originalPair.first);
  EXPECT_EQ(myPair.second.First(), *originalPair.second);
}

TEST(MultisetLookup, EqualRangeThird) {
  s21::Multiset<char> a{'a', 'b', 'b', 'd'};
  std::multiset<char> b{'a', 'b', 'b', 'd'};
  auto myPair = a.EqualRange('b');
  auto originalPair = b.equal_range('b');
  EXPECT_EQ(myPair.first.First(), *originalPair.first);
  EXPECT_EQ(myPair.second.First(), *originalPair.second);
}

TEST(MultisetConstructor, CopyConstructor) {
  s21::Multiset<int> a{13, 8, 17, 17, 1, 11, 17, 15, -1, 25};
  s21::Multiset<int> copySet(a);
  s21::Multiset<int>::iterator myIt = a.Begin();
  s21::Multiset<int>::iterator copyIt = copySet.Begin();
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(myIt.First(), copyIt.First());
    ++myIt;
    ++copyIt;
  }
}

TEST(MultisetConstructor, MoveConstructor) {
  s21::Multiset<int> a{13, 8, 17, 17, 1, 11, 17, 15, -1, 25};
  s21::Multiset<int> aTemp{13, 8, 17, 17, 1, 11, 17, 15, -1, 25};
  s21::Multiset<int> copySet(std::move(a));
  s21::Multiset<int>::iterator myIt = aTemp.Begin();
  s21::Multiset<int>::iterator copyIt = copySet.Begin();
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(myIt.First(), copyIt.First());
    ++myIt;
    ++copyIt;
  }
}

TEST(MapConstruction, MoveOperator) {
  s21::Multiset<int> a{13, 8, 17, 17, 1, 11, 17, 15, -1, 25};
  s21::Multiset<int> aTemp;
  aTemp = std::move(a);
  EXPECT_FALSE(aTemp.Empty());
}

TEST(MultisetConstructor, OperatorEqual) {
  s21::Multiset<int> a{13, 8, 17, 17, 1, 11, 17, 15, -1, 25};
  s21::Multiset<int> copySet;
  copySet = a;
  s21::Multiset<int>::iterator myIt = a.Begin();
  s21::Multiset<int>::iterator copyIt = copySet.Begin();
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(myIt.First(), copyIt.First());
    ++myIt;
    ++copyIt;
  }
}

TEST(MultisetIterator, IteratorBegin) {
  s21::Multiset<int> a({1, 4, 5, 2, 7, 12, 14});
  std::multiset<int> b({1, 4, 5, 2, 7, 12, 14});
  s21::Multiset<int>::iterator myIt = a.Begin();
  std::multiset<int>::iterator originalIt = b.begin();
  EXPECT_EQ(myIt.First(), *originalIt);
}

TEST(MultisetIterator, IteratorEnd) {
  s21::Multiset<int> a({1, 4, 5, 2, 7, 12, 14});
  std::multiset<int> b({1, 4, 5, 2, 7, 12, 14});
  s21::Multiset<int>::iterator myIt = a.End();
  std::multiset<int>::iterator originalIt = b.end();
  --myIt;
  --originalIt;
  EXPECT_EQ(myIt.First(), *originalIt);
}

TEST(MultisetIterator, IteratorPlus) {
  s21::Multiset<int> a({1, 4, 5, 2, 7, 12, 14});
  std::multiset<int> b({1, 4, 5, 2, 7, 12, 14});
  s21::Multiset<int>::iterator myIt = a.Begin();
  std::multiset<int>::iterator originalIt = b.begin();
  ++myIt;
  ++myIt;
  ++originalIt;
  ++originalIt;
  EXPECT_EQ(myIt.First(), *originalIt);
}

TEST(MultisetIterator, IteratorMinus) {
  s21::Multiset<int> a({1, 4, 5, 2, 7, 12, 14});
  std::multiset<int> b({1, 4, 5, 2, 7, 12, 14});
  s21::Multiset<int>::iterator myIt = a.End();
  std::multiset<int>::iterator originalIt = b.end();
  --myIt;
  --myIt;
  --originalIt;
  --originalIt;
  EXPECT_EQ(myIt.First(), *originalIt);
}

TEST(MultisetIterator, IteratorEqual) {
  s21::Multiset<int> a({1, 4, 5, 2, 7, 12, 14});
  std::multiset<int> b({1, 4, 5, 2, 7, 12, 14});
  s21::Multiset<int>::iterator myIt = a.Begin();
  std::multiset<int>::iterator originalIt = b.begin();
  EXPECT_TRUE(myIt.First() == *originalIt);
}

TEST(MultisetIterator, IteratorNotEqual) {
  s21::Multiset<int> a({1, 4, 5, 2, 7, 12, 14});
  std::multiset<int> b({1, 4, 5, 2, 7, 12, 14});
  s21::Multiset<int>::iterator myIt = a.Begin();
  std::multiset<int>::iterator originalIt = b.begin();
  EXPECT_FALSE(myIt.First() != *originalIt);
}

TEST(MultisetConstructor, ConstuctorCopy) {
  // уничтожили объект и его cкопировали. В root - nullptr
  s21::Multiset<int> a({1, 4, 5, 2, 7, 12, 14});
  s21::Multiset<int> b;
  b = a;
  EXPECT_EQ(a.Size(), b.Size());
}

TEST(MultisetIterator, Decrement1) {
  s21::Multiset<int> a({1, 4, 5, 2, 7, 12, 14});
  a.Clear();
  s21::Multiset<int>::iterator myIt = a.Begin();
  ASSERT_ANY_THROW(--myIt);
}

TEST(MultisetIterator, Increment) {
  s21::Multiset<int> a({1, 4, 5, 2, 7, 12, 14});
  std::multiset<int> b({1, 4, 5, 2, 7, 12, 14});
  s21::Multiset<int>::iterator myIt = a.Begin();
  std::multiset<int>::iterator originalIt = b.begin();
  ++myIt;
  ++originalIt;
  EXPECT_EQ(myIt.First(), *originalIt);
}

TEST(MultisetIterator, EqualOperator) {
  s21::Multiset<int> a({1, 4, 5});

  s21::Multiset<int>::iterator it1 = a.Begin();
  s21::Multiset<int>::iterator it2 = a.End();
  ++it1;
  --it2;
  --it2;
  EXPECT_TRUE(it1 == it2);
}

TEST(MultisetCount, Increment) {
  s21::Multiset<int> a({1, 2, 5, 2, 7, 2, 14});
  std::multiset<int> b({1, 2, 5, 2, 7, 2, 14});
  EXPECT_TRUE(a.Count(2) == b.count(2));
  EXPECT_TRUE(a.Count(13) == b.count(13));
}

TEST(MultisetIterator, Decrement2) {
  s21::Multiset<int> a({5, 5, 5});

  s21::Multiset<int>::iterator it1 = a.End();
  EXPECT_ANY_THROW(*it1);
  EXPECT_ANY_THROW(it1.First());
  for (size_t i = 0; i < a.Size(); ++i) {
    --it1;
    EXPECT_TRUE(it1.First() == 5);
  }
}

TEST(MultisetErase, Erase) {
  s21::Multiset<int> a({10, 8, 5, 5, 5, 6, 3});
  std::multiset<int> b({10, 8, 5, 5, 5, 6, 3});
  s21::Multiset<int>::Iterator it1 = a.Begin();
  std::multiset<int>::iterator it2 = b.begin();
  ++it1;
  a.Erase(it1);
  it1 = a.Begin();
  ++it2;
  b.erase(it2);
  it2 = b.begin();
  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_TRUE(*it1 == *it2);
    ++it1;
    ++it2;
  }
}

TEST(MultisetErase, EraseRoot1_1) {
  // удаляем корень, если есть правый потомок, нет левого
  s21::Multiset<int> ms1({10, 11});
  s21::Multiset<int> res({11});
  ms1.Erase(ms1.Begin());  // удалили 10

  s21::Multiset<int>::iterator it1 = ms1.Begin();
  s21::Multiset<int>::iterator it2 = res.Begin();
  EXPECT_EQ(ms1.Size(), 1);
  EXPECT_EQ(*it1, *it2);
}

TEST(MultisetErase, EraseRoot1_2) {
  // удаляем корень, если есть правый потомок, нет левого
  s21::Multiset<int> ms1({10, 10, 11});
  s21::Multiset<int> res({10, 11});
  ms1.Erase(ms1.Begin());  // удалили 10

  s21::Multiset<int>::iterator it1 = ms1.Begin();
  s21::Multiset<int>::iterator it2 = res.Begin();
  EXPECT_EQ(ms1.Size(), 2);
  for (size_t i = 0; i < res.Size(); i++) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(MultisetErase, EraseRoot2_1) {
  // удаляем корень, если есть левый потомок, нет правого
  s21::Multiset<int> ms1({10, 8});
  s21::Multiset<int> res({8});
  ms1.Erase(++ms1.Begin());  // удалили 10

  s21::Multiset<int>::iterator it1 = ms1.Begin();
  s21::Multiset<int>::iterator it2 = res.Begin();
  EXPECT_EQ(ms1.Size(), 1);
  EXPECT_EQ(*it1, *it2);
}

TEST(MultisetErase, EraseRoot2_2) {
  // удаляем корень, если есть левый потомок, нет правого
  s21::Multiset<int> ms1({10, 10, 8});
  s21::Multiset<int> res({10, 8});
  ms1.Erase(++ms1.Begin());  // удалили 10

  s21::Multiset<int>::iterator it1 = ms1.Begin();
  s21::Multiset<int>::iterator it2 = res.Begin();
  EXPECT_EQ(ms1.Size(), 2);
  for (size_t i = 0; i < res.Size(); i++) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(MultisetErase, Erase2) {
  s21::Multiset<int> ms1({10, 8, 5, 6, 5});
  std::multiset<int> ms2({10, 8, 5, 6, 5});
  ms1.Erase(ms1.Begin());
  ms2.erase(ms2.begin());
  s21::Multiset<int>::iterator it1 = ms1.Begin();
  std::multiset<int>::iterator it2 = ms2.begin();
  for (size_t i = 0; i < ms1.Size(); i++) {
    EXPECT_EQ(*it1, *it2);  // key
    ++it1;
    ++it2;
  }
}

TEST(MultisetErase, Erase3) {
  s21::Multiset<int> ms1({10, 18, 16, 16, 15});
  std::multiset<int> ms2({10, 18, 16, 16, 15});
  s21::Multiset<int>::iterator it1 = ms1.Begin();
  std::multiset<int>::iterator it2 = ms2.begin();
  ++it1;
  ++it1;
  ++it2;
  ++it2;
  ms1.Erase(it1);
  ms2.erase(it2);
  it1 = ms1.Begin();
  it2 = ms2.begin();
  for (size_t i = 0; i < ms1.Size(); i++) {
    EXPECT_EQ(*it1, *it2);  // key
    ++it1;
    ++it2;
  }
  EXPECT_TRUE(ms1.Find(16).Second() == 0);
}

TEST(MultisetErase, Erase4) {
  s21::Multiset<int> ms1({10, 18, 16, 15});
  std::multiset<int> ms2({10, 18, 16, 15});
  s21::Multiset<int>::iterator it1 = ms1.Begin();
  std::multiset<int>::iterator it2 = ms2.begin();
  ++it1;
  ++it1;
  ++it2;
  ++it2;
  ms1.Erase(it1);
  ms2.erase(it2);
  it1 = ms1.Begin();
  it2 = ms2.begin();
  for (size_t i = 0; i < ms1.Size(); i++) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(MultisetErase, Erase5) {
  s21::Multiset<int> ms1({10, 8, 5, 1, 3});
  std::multiset<int> ms2({10, 8, 5, 1, 3});
  ms1.Erase(ms1.Find(5));
  ms2.erase(ms2.find(5));
  s21::Multiset<int>::iterator it1 = ms1.Begin();
  std::multiset<int>::iterator it2 = ms2.begin();
  for (size_t i = 0; i < ms1.Size(); i++) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(MultisetErase, Erase6) {
  s21::Multiset<int> ms1({10, 8, 5, 7, 6});
  std::multiset<int> ms2({10, 8, 5, 7, 6});
  ms1.Erase(ms1.Find(5));
  ms2.erase(ms2.find(5));
  s21::Multiset<int>::iterator it1 = ms1.Begin();
  std::multiset<int>::iterator it2 = ms2.begin();
  for (size_t i = 0; i < ms1.Size(); i++) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(MultisetErase, Erase7) {
  // удаляем корень, если есть правый потомок, нет левого
  s21::Multiset<int> ms1({10, 10, 11});
  std::multiset<int> ms2({10, 10, 11});
  ms1.Erase(ms1.Begin());  // удалили 10
  ms2.erase(ms2.begin());
  ms1.Erase(ms1.Begin());  // удалили еще 10
  ms2.erase(ms2.begin());
  ms1.Erase(ms1.Begin());  // удалили 11
  ms2.erase(ms2.begin());
  EXPECT_EQ(ms1.Size(), ms2.size());
  EXPECT_ANY_THROW((ms1.Begin()).Second());
}

TEST(MultisetErase, Emplace1) {
  s21::Multiset<int> ms1({1, 5, 6});
  std::multiset<int> ms2({1, 5, 6});
  ms1.Emplace(0, 3);
  ms2.emplace(0);
  ms2.emplace(3);
  s21::Multiset<int>::iterator it1 = ms1.Begin();
  std::multiset<int>::iterator it2 = ms2.begin();
  for (size_t i = 0; i < ms1.Size(); i++) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
  EXPECT_EQ(ms2.size(), ms1.Size());
}

TEST(MultisetErase, Emplace2) {
  s21::Multiset<int> ms1({1, 5, 6});
  s21::Multiset<int> res({1, 5, 6, 0, 3, 5, 0, 3, 5});
  ms1.Emplace(0, 3, 5, 0, 3, 5);
  s21::Multiset<int>::iterator it1 = ms1.Begin();
  s21::Multiset<int>::iterator it2 = res.Begin();
  for (size_t i = 0; i < ms1.Size(); i++) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
  EXPECT_EQ(res.Size(), ms1.Size());
}

TEST(MultisetErase, Emplace3) {
  s21::Multiset<int> ms1({1, 5, 6});
  std::multiset<int> ms2({1, 5, 6});
  ms1.Emplace();
  ms1.Emplace();
  ms2.emplace();
  ms2.emplace();
  s21::Multiset<int>::iterator it1 = ms1.Begin();
  std::multiset<int>::iterator it2 = ms2.begin();
  for (size_t i = 0; i < ms2.size(); i++) {
    EXPECT_EQ(*it1, *it2);
    ++it2;
    ++it1;
  }
  EXPECT_EQ(ms2.size(), ms1.Size());
}

TEST(MultisetErase, Emplace4) {
  s21::Multiset<int> ms1({1, 5, 6});
  std::multiset<int> ms2({1, 5, 6});
  ms1.Emplace(5);
  ms2.emplace(5);
  s21::Multiset<int>::iterator it1 = ms1.Begin();
  std::multiset<int>::iterator it2 = ms2.begin();
  for (size_t i = 0; i < ms2.size(); i++) {
    EXPECT_EQ(*it1, *it2);
    ++it2;
    ++it1;
  }
  EXPECT_EQ(ms2.size(), ms1.Size());
}
