#include <iostream>
#include "../s21_list.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;

//    s21::List<std::string> s21_a; //{1 ,2 ,3};
//    s21::List<std::string>::Iterator it = s21_a.End();
//    std::list<std::string> a;// {1 ,2, 3};
//    std::list<std::string>::iterator it1;

//     a.emplace_back();

//     s21_a.EmplaceBack();
//    a.emplace_front();
//    a.emplace_back();

    s21::List<bool> s21_a{true, false, true};
     s21::List<bool> check{true, false, true};
     s21_a.EmplaceFront(true, false, true, true, false, true);
      for (auto it = s21_a.Begin(); it != s21_a.End(); ++it) {

       cout <<  *(it) << " ";

      }
      cout << endl;
//      for (auto it = check.Begin(); it != check.End(); ++it) {

//       cout <<  *(it) << " ";

//      }
//cout << endl;


//     std::cout << s21_a.Size() << std::endl;
//     for (auto it = s21_a.Begin(); it !=s21_a.End(); ++it) {
//         std::cout << "|" << *it << "|";
//     }
//     cout << endl;
//   // cout << *it<< endl;

//    std::cout << a.size() << std::endl;
//    for (auto it = a.begin(); it !=a.end(); ++it) {
//        std::cout << "|" << *it << "|";
//    }
//    cout << endl;
   //cout << *b<< endl;

    return 0;
}
