#include <iostream>
#include <string>
#include <map>
using namespace std;

class Zebra {
private:
  string name;
  static int count; // turns into extern
  static map<string,Zebra*> zebraByName;
public:
  Zebra(const string& name) : name(name) {
    count++;
    cout << "Zebra " << name << " born count="
	 << count << '\n';
    zebraByName[name] = this;
  }
  ~Zebra() {
    count--;
    cout << "Zebra " << name << " dying count="
	 << count << '\n';
    zebraByName[name] = NULL;
  }
  static Zebra* find(const string& name) {
    return zebraByName[name];
  }
};

int Zebra::count = 0;
map<string,Zebra*> Zebra::zebraByName;

void g() {
  Zebra z4("Mary");
}

void f() {
  Zebra z3("Bob");
  g();
}

int main() {
  Zebra z1("Fred");
  Zebra z2("Alice");
  cout << Zebra::find("Fred") << '\n';
  f();
}
