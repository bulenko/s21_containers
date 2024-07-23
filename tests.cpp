#include <gtest/gtest.h>

#include <array>
#include <climits>
#include <cmath>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include "tests/s21_array_test.cpp"
#include "tests/s21_list_test.cpp"
#include "tests/s21_map_test.cpp"
#include "tests/s21_multiset_test.cpp"
#include "tests/s21_queque_test.cpp"
#include "tests/s21_set_test.cpp"
#include "tests/s21_stack_test.cpp"
#include "tests/s21_vector_test.cpp"

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
