#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    string a;
    cin >> a;
    reverse(a.begin(),a.end());
    for(int i = 0; i < a.size(); i++){
        if(a[i] == 'p') a[i] = 'q';
        else if(a[i] == 'q') a[i] = 'p';
    }
    cout << a << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}