#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
   int n;
   string s;
   cin >> n >> s;
   bool z = false;
   int one = 0, zero = 0;
   for(int i = 0; i < n; i++){
       if(s[i] == '1') {
        one++;
        z = false;
       }
       else {
         if(!z){
            z = true;
            zero ++;
         }
       }
   }
   if( zero >= one) cout << "no\n";
   else cout << "yes\n";
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