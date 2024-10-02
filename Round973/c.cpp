#include <iostream>
#include <string>

using namespace std;

bool query(string pass) {
  cout << "? " << pass << "\n";
  cout.flush();
  int res;
  cin >> res;
  return res;
}

void revealPass(string pass) {
  cout << "! " << pass << "\n";
  cout.flush();
}

void solve() {
  int n;
  cin >> n;
  string pass = "";
  while (pass.size() < n) {
    if (query(pass + "0")) {
      pass += "0";
    } else if (query(pass + "1")) {
      pass += "1";
    } else
      break;
  }

  while (pass.size() < n) {
    if (query("0" + pass)) {
      pass = "0" + pass;
    } else {
      pass = "1" + pass;
    }
  }
  revealPass(pass);
}

int main() {

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}
