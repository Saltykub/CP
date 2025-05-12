#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
double dp[305][305][305]; // dp[i][j][k] = prob when have 3 ith numbers, 2 jth numbers, 1 kth numbers
void solve (){
    double n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= n; k++){
                if(!(i|j|k)) continue;
                dp[i][j][k] = n/(i+j+k);
                double sm = 0,cnt = 0;
                if(i-1 >= 0) sm+=dp[i-1][j+1][k]*i,cnt+=i;
                if(j-1 >= 0) sm+=dp[i][j-1][k+1]*j,cnt+=j;
                if(k-1 >= 0) sm+=dp[i][j][k-1]*k,cnt+=k;
                dp[i][j][k]+= sm/cnt;
            }
        }
    }
    vector<int> arr(4,0);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        arr[x]++;
    }
    printf("%.10f",dp[arr[3]][arr[2]][arr[1]]);
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}