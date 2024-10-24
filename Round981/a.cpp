#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  int turn;
  while (t-- > 0) {
    cin >> turn;
    string res = ((turn % 2) == 1) ? "Kosuke\n" : "Sakurako\n";
    cout << res;
  }
  return 0;
}
