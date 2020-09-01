#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int inf = 1000000000000000000;

int b[2][5001][5001];
int dp[5002][5002];

void go(int s, int e, int lo, int hi, int i) {
  if(s > e)
    return ;
  int m = (s + e) >> 1;
  int x = inf, mi;
  for(int y = max(lo, m); y <= hi;  y++) {
    if(dp[y + 1][i - 1] != inf && dp[y + 1][i - 1] + b[1][m][y] < x) {
      x = dp[y + 1][i - 1] + b[1][m][y];
      mi = y;
    }
  }
  dp[m][i] = x;
  go(s, m - 1, lo, mi, i);
  go(m + 1, e, mi, hi, i);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k, ans = inf;
  cin >> n >> k;
  vector <int> a(n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      b[0][i][j] = b[1][i][j] = 0;
    dp[i][0] = inf;
  }
  for(int &i :  a)
    cin >> i;
  for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++)
      b[0][i][j] = b[0][i][j - 1] + (a[i] ^ a[j]);
  for(int i = 1; i <= n; i++)
    for(int j = i - 1; ~j; j--)
      b[1][j][i] = b[1][j + 1][i] + b[0][j][i];
  for(int i = 1; i <= k + 1; i++) {
    go(0, n - 1, 0, n - 1, i);
    ans = min(ans, dp[0][i]);
  }
  cout << ans << "\n";
}
