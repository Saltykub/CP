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
   int n;
   cin >> n >> s;
   int op = 0;
   for(int i = 0; i < n; i++){
     if(s[i] == '_'){
        if(op == 0){
            s[i] = '(';
            op++;
        }
        else {
            s[i] = ')';
            op--;
        }
     }
     else if(s[i] == ')'){
        op--;
     }
     else {
        op++;
     }
   }
   stack <int> ss;
   int ans = 0;
   for(int i = 0 ; i < n; i++){
     if(s[i] == '(') ss.push(i);
     else {
        ans += i - ss.top();
        ss.pop();
     }
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