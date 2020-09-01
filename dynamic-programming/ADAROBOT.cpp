#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int N = 200000001;

int dp[N];
int a[100];
int t, n;

int32_t main() {
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  for(int i = 1; i < 100; i++)
    a[i] = i * i * i;
  for(int i = 2; i <= N; i++)
    dp[i] = dp[i - 2] + a[__builtin_ffsl(i * (i - 1))];
  scanf("%ld", &t);
  while(t--) {
    scanf("%ld", &n);
    printf("%ld\n", dp[n]);
  }
}
