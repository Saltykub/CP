#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int mod = 1e9+7;
void solve(){
   string s;
   cin >> s;
   bool have = false;
   int h = -1;
   for(int i = 0; i < s.size() -1; i++){
        if(s[i] == s[i+1]){
            have = true;
            h = i;
        }
   }
   string ans = "";
   if(have){
       if(s[h] == 'a'){
          for(int i = 0; i <= h; i++) ans += s[i];
          ans += 'b';
          for(int i = h+1; i < s.size(); i++) ans += s[i];
       }
       else {
          for(int i = 0; i <= h; i++) ans += s[i];
          ans += 'a';
          for(int i = h+1; i < s.size(); i++) ans += s[i];
       }
   }
   else {
    ans = s;
    if(s[s.size()-1] == 'a') ans += 'b';
    else ans += 'a';
   }
   cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }
}