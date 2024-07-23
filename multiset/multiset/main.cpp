#include <iostream>
#include "../s21_multiset.h"
#include <set>
using namespace std;


//template <typename Key, typename T>
//class Buka {
//public:
//    struct TreeNode {
//       Key key_ = {};
//       T value= {};
//       TreeNode *parent_ = nullptr;
//       TreeNode *left_ = nullptr;
//       TreeNode *right_ = nullptr;

//       TreeNode(){};
//       explicit TreeNode(Key k) : key_(k){};
//       explicit TreeNode(Key k, T v) : key_(k), value(v){};
//     };
//};

int main()
{
    s21::Multiset<int> ms1({1, 5, 6});
     std::multiset<int> ms2({1, 5, 6});
     ms1.Emplace();
     // ms1.Emplace();
    ms2.emplace();
     // ms2.emplace();
     s21::Multiset<int>::iterator it1 = ms1.Begin();
     std::multiset<int>::iterator it2 = ms2.begin();
      for (; it1!= ms1.End(); it1++) {
        cout << "|" << *it1 << "|";

      }
      cout << "\n";
      for (; it2!= ms2.end(); it2++) {
        cout << "|" << *it2 << "|";

      }
    cout << "\n";


//    Buka<int, int>::TreeNode *n = new Buka<int, int>::TreeNode{};
//    //      cout << "|" << *n << "|" << "\n";
    return 0;
}

