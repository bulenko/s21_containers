#include <iostream>
#include "../s21_vector.h"

using namespace std;

int main()
{
//    s21::Vector<bool> s21_a{true, false, true};
//     s21_a.Emplace(s21_a.Begin(), true, true, true);
    s21::Vector<std::string> a{"c", "b" };
     //s21::Vector<std::string> b{"c", "dg b", "dsfs", "etv", "ert", "sdf", "dssff", "3hk", "c"};
    a.EmplaceBack("f", "v");
//    for (size_t i = 0; i < a.Size(); i++) {
//      EXPECT_EQ(a[i], b[i]);
//    }
//   // s21_a.Insert(s21_a.Begin(), 5);
      for (s21::Vector<std::string>::iterator it = a.Begin(); it != a.End(); ++it) {
       cout <<  *(it) << " ";
      }
      cout << endl;
      cout << a.Size()<< endl;
//      for (auto it = b.Begin(); it != b.End(); ++it) {
//       cout <<  *(it) << " ";
//      }
//      cout << endl;
//      cout << b.Size()<< endl;
    return 0;
}
