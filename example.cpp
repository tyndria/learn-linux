#include <iostream>
#include <string>

using namespace std;

int main(int c, char* argv[]) {
  for (int i = 0; i < c; i ++) {
    cout << i + 1 << ". " << argv[i] << endl;
  }
  return 0;
}
