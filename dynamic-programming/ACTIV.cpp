#include <bits/stdc++.h>
using namespace std;

vector <long long> s, e, a;
long long dp[200010];

void upd(long long i, long long x) {
  for(; i <= 200009; i += (i & -i))
    dp[i] = (dp[i] + x) % 100000000ll;
}

long long get(long long i) {
  long long sum = 0;
  for(; i; i -= (i & -i))
    sum = (sum + dp[i]) % 100000000ll;
  return sum;
}

bool comp(long long i, long long j) {
  if(e[i] < e[j])
    return true;
  if(e[j] < e[i])
    return false;
  if(s[i] < s[j])
    return true;
  return false;
}



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while(true) {
    long long n;
    cin >> n;
    if(n == -1)
      break;
    s.resize(n);
    e.resize(n);
    a.resize(n);
    map <long long, long long> mp;
    for(long long i = 0; i < n; i++) {
      cin >> s[i] >> e[i];
      mp[s[i]] = 0;
      mp[e[i]] = 0;
      a[i] = i;
    }
    sort(a.begin(), a.end(), comp);
    long long id = 1;
    for(auto it : mp) {
      dp[id] = 0;
      mp[it.first] = id++;
    }
    for(long long i : a)
      upd(mp[e[i]], (get(mp[s[i]]) + 1ll) % 100000000ll);
    long long ans = get(id - 1ll);
    string s = to_string(ans);
    reverse(s.begin(), s.end());
    while((long long)s.size() < 8ll) {
      s.push_back('0');
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
  }
}
