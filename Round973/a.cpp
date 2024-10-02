#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, int x, int y) {
    int consume = min(x, y);
    return n / consume + ((n % consume) ?  1 : 0);
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, x, y;
        cin >> n;
        cin >> x;
        cin >> y;
        cout << solution(n, x, y) << "\n";
    }

    return 0;
}
