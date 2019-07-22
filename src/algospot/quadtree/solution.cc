#include <iostream>
#include <string>
using namespace std;

namespace {
string reverse(string::iterator& it) {
  char head = *it;
  ++it;
  if (head == 'b' || head == 'w') {
    return string(1, head);
  }
  string upperLeft = reverse(it);
  string upperRight = reverse(it);
  string lowerLeft = reverse(it);
  string lowerRight = reverse(it);
  return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}
}

int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    string line, answer;
    cin >> line;
    string::iterator it = line.begin();
    answer = reverse(it);
    cout << answer << endl;
  }
}