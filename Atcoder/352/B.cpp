#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
  string s,t;
  cin >> s >> t;
  int j = 0;
  for(int i = 0; i < t.size(); i++){
     if(s[j] == t[i]){
        cout << i+1 << " ";
        j++;
     }
  }
}
int main(){   
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    // cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}