#include <bits/stdc++.h>
using namespace std;

bitset <100001> dp;
int s[100001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, q, x;
  cin >> n >> q;
  dp[0] = 1;
  for(int i = 0; i < n; i++) {
    cin >> x;
    dp |= (dp << x);
  }
  for(int i = 1; i <= 1e5; i++)
    s[i] = s[i - 1] + dp[i];
  while(q--) {
    long long l, r;
    cin >> l >> r;
    cout << s[r] - s[l - 1] << "\n";
  }
}
