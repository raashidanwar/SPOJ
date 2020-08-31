#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while(true) {
    string s;
    cin >> s;
    if(s == "0")
      break;
    int n = s.size();
    vector <int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
      if(s[i - 1] > '0')
        dp[i] += dp[i - 1];
      if(i > 1) {
        int x = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
        if(x >= 10 && x <= 26)
          dp[i] += dp[i - 2]; 
      }
    }
    cout << dp[n] << "\n";
  }
}
