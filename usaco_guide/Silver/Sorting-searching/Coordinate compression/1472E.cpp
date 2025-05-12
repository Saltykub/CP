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
    vector<pair<pii,int>> arr(n), arr2(n);
    vector<int> ans(n,-1);
    for(int i = 0; i < n; i++) cin >> arr[i].st.st >> arr[i].st.nd;
    for(int i = 0; i < n; i++) {
        arr[i].nd = i;
        arr2[i].st.st = arr[i].st.nd;
        arr2[i].st.nd = arr[i].st.st;
        arr2[i].nd = i;
    }
    // check first condition
    sort(arr.begin(),arr.end());
    ll mnw_cal = INT_MAX, mnw = INT_MAX, cur_ans = -1,cur_h = arr[0].st.st, cur_w = -1;
    for(int i = 0; i < n; i++){
        //cout << mnw << " " << arr[i].st.nd << "\n";
        if(arr[i].st.nd > mnw){
            ans[arr[i].nd] = cur_ans;
        }
        if(arr[i].st.nd < mnw_cal){
            mnw_cal = arr[i].st.nd;
            cur_w = arr[i].nd + 1;
        }
        if(i+1 < n && arr[i+1].st.st > cur_h){
            cur_h = arr[i+1].st.st;
            if(mnw > mnw_cal){
                mnw = mnw_cal;  
                cur_ans = cur_w;
            }
        }
        
    }
    // check second condition
    sort(arr2.begin(),arr2.end());
    mnw_cal = INT_MAX, mnw = INT_MAX, cur_ans = -1,cur_h = arr[0].st.st, cur_w = -1;
    ll j = 0;
    for(int i = 0; i < n; i++){
        while(j < n && arr[j].st.st < arr2[i].st.st){
            if(arr[j].st.nd > mnw){
                ans[arr[j].nd] = cur_ans; 
            }
            j++;
        }
        if(arr2[i].st.nd < mnw_cal){
            mnw_cal = arr[i].st.nd;
            cur_w = arr[i].nd + 1;
        }
        if(j+1 < n && arr[j+1].st.st > cur_h){
            cur_h = arr[i+1].st.st;
            if(mnw > mnw_cal){
                mnw = mnw_cal;  
                cur_ans = cur_w;
            }
        }
    }
    for(auto u:ans) cout << u << " ";
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