#include <bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll, ll>
#define nd second #define pb push_back
using namespace std;
void solve() {
  string s;
  cin >> s;
  int ans = 1;
  int sz = s.size();
  if (s[0] - '0' == 0) {
    cout << 0 << "\n";
    return;
  }
  if (s[0] == '?')
    ans *= 9;
  for (int i = 1; i < sz; i++) {
    if (s[i] == '?')
      ans *= 10;
  }
  cout << ans << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
