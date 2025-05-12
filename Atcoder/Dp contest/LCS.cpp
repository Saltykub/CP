#include <bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll, ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 3e3 + 10;
bool CASE = false;
int dp[N][N];
void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  string ans = "";
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      cur = max(dp[i][j], cur);
    }
  }
  int tt = m;
  for (int i = n; i >= 0; i--) {
    for (int j = tt; j >= 0; j--) {
      if (dp[i][j] == cur && s[i - 1] == t[j - 1]) {
        string temp = ans;
        ans = s[i - 1] + temp;
        cur--;
        tt = j - 1;
        break;
      }
    }
    if (!cur)
      break;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  if (CASE)
    cin >> t;
  while (t--) {
    solve();
  }
}
