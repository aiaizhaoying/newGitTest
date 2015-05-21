#include <iostream>
using namespace std;

class A {
private:
  int x, y;
public:
  A(int x, int y) : x(x), y(y) {}
  friend ostream& operator <<(ostream& s, A a) {
    return s << a.x << ", " << a.y;
  }
};

int main() {
  A a1(1,2);
  A a2 = a1; // makes a copy
  A a3(a1); // makes a copy
  cout << a1 << '\n';
  cout << a2 << '\n';
  cout << a3 << '\n';
}
