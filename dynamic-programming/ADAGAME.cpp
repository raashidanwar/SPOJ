#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int dp[10][10][10][10][100];
int m, n;

int go(int a, int b, int c, int d, int i) {
  if(m == i) {
    int num = a * 1000 + b * 100 + c * 10 + d;
    return num > n;
  }
  if(dp[a][b][c][d][i] != -1)
    return dp[a][b][c][d][i];
  int& x = dp[a][b][c][d][i];
  x = 0;
  if(i & 1)
    x = 1;
  if(i & 1)
    x = min(x, min(go((a + 1) % 10, b, c, d, i + 1), min(go(a, (b + 1) % 10, c, d, i + 1), min(go(a, b, (c + 1) % 10, d, i + 1), go(a, b, c, (d + 1) % 10, i + 1)))));
  else
    x = max(x, max(go((a + 1) % 10, b, c, d, i + 1), max(go(a, (b + 1) % 10, c, d, i + 1), max(go(a, b, (c + 1) % 10, d, i + 1), go(a, b, c, (d + 1) % 10, i + 1)))));
  return x;
}



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s >> m;
    memset(dp, -1, sizeof(dp));
    n = int(s[0] - '0') * 1000 + int(s[1]  - '0') * 100 + int(s[2] - '0') * 10 + int(s[3] - '0');
    if(go(s[0] - '0', s[1] - '0', s[2] - '0', s[3] - '0', 0))
      cout << "Ada\n";
    else
      cout << "Vinit\n";
  }
}
