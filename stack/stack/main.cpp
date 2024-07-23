#include <iostream>
#include "../s21_stack.h"

using namespace std;

int main()
{
    s21::Stack<std::string> a{"a", "b", "c"};
     a.EmplaceFront();
      while (!a.Empty()) {
      cout << "|" << a.Top() << "|" << "\n";
      a.Pop();
      }

    return 0;
}
