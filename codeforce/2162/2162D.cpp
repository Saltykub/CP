#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
int ask(int op, int l, int r){
    cout << op << " " << l << " " << r << endl;
    int ret;
    cin >> ret;
    return ret;
}
int cal(int l, int r){
    int o = ask(1,l,r);
    int m = ask(2,l,r);
    return m-o;
}
void solve (){
    int n;
    cin >> n;
    int l = 1, r = n;
    int target = ask(2,1,n)-ask(1,1,n);
    while(l<r){
        int mid = (l+r)/2;
        if(cal(l,mid)){
            r = mid;
        }
        else {
            l = mid+1;
        }
    }
    
    cout << "! " << l << " " << l+target-1 << endl;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}