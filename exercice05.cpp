#include <iostream>
using namespace std;

class Test {
private:
  static int callCount;

public:
  void call() {
    callCount++;
    cout << "La fonction call() a été appelée." << endl;
  }

  static int getCallCount() { return callCount; }
};

int Test::callCount = 0;

int main() {
  Test t1, t2;

  t1.call();
  t2.call();
  t1.call();

  cout << "La fonction call() a été appelée " << Test::getCallCount()
       << " fois." << endl;

  return 0;
}
