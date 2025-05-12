#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 3e5+1;
bool CASE = false;
bool is_prime[N];
void solve (){
    vector<int> prime;
    for(int i = 0; i < N; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < N; i++){
        if(is_prime[i] && (long long)i*i < N){
            for(int j = i*i; j < N; j += i){
                is_prime[j] = false;
            }
        }
    }
    for(int i = 2; i < N; i++) if(is_prime[i]) prime.pb(i);
    int n;
    cin >> n;
    vector<int> spider(n);
    for(int i = 0; i < n; i++) cin >> spider[i];
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}