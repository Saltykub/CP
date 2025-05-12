#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
    int sz;
    cin  >> sz;
    int ans[sz+1];
    memset(ans,0,sizeof ans);
    while(true){
        for(int i = 1;i <= sz;i++){
            if(ans[i])continue;
            cout << "? " << i << endl;
            string clue;
            cin >> clue;
            if(clue == "=") {
                ans [i] = 
            }
        }
    }
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