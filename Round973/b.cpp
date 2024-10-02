#include <iostream>
#include <vector>
#define ll long long

using namespace std;


ll solution(vector<int> &ratings, int n) {
  ll res = -1 * ratings[n-2];
  for(int i = 0; i < n-2; ++i) {
    res += ratings[i];
  }
  res += ratings[n-1];
  return res;
}

int main() {
    int t;
    cin >> t;

    int n;
    int r;
    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        vector<int> ratings;
        for (int j = 0; j < n; ++j)
        {
            cin >> r;
            ratings.push_back(r);
        }
        cout << solution(ratings, n) << "\n";
    }

    return 0;
}
