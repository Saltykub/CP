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
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    int mx = 0;
    for(auto x:v) mx = max(x,mx);
    int l = 1, r = n;
    vector<int> ans(n,-1);
    for(int i = 1; i <= mx; i++){
        int ch = false;
        if(i%2){
            for(int j = 0; j < n; j++){
                if(v[j] != 0){
                    if(!ch){
                        if(v[j] == i){
                            int tmp = j;
                            while(j < n && (v[j] == i || v[j] == 0) ){
                                j++;
                            }
                            for(int k = tmp; k < j; k++){
                                if(v[k] != 0) ans[k] = r--;
                                v[k] = 0;
                            }
                        }
                        ch = true;
                    }
                    else if(v[j] == i){
                        int tmp = j;
                        while(j < n && (v[j] == i || v[j] == 0)){
                            j++;
                        }
                        for(int k = j-1; k >= tmp; k--){
                            if(v[k] != 0) ans[k] = r--;
                            v[k] = 0;
                        }
                    }
                }
                
            }
        }
        else {
            for(int j = 0; j < n; j++){
                if(v[j] != 0){
                    if(!ch){
                         if(v[j] == i){
                            int tmp = j;
                            while(j < n && (v[j] == i || v[j] == 0)){
                                j++;
                            }
                            for(int k = tmp; k < j; k++){
                                if(v[k] != 0) ans[k] = l++;
                                v[k] = 0;
                            }
                        }
                        ch = true;
                    }
                    else if(v[j] == i){
                        int tmp = j;
                        while(j < n && (v[j] == i || v[j] == 0)){
                            j++;
                        }
                        //cout << j-1 << " " << tmp << "\n";
                        for(int k = j-1; k >= tmp; k--){
                            if(v[k] != 0) ans[k] = l++;
                            v[k] = 0;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(ans[i] == -1) cout << l << " ";
        else cout << ans[i] << " ";
    }
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}