#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;

void solve()
{   
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    deque<int> q;
    for(int i=0;i<n;i++)q.push_back(arr[i]);
    ll cur=0;
    ll ans=0;
    while(q.size()>1){
        int val=q.front();
        //cout<<val<<" ";
        q.pop_front();
        if(cur+val<q.back()){
            cur+=val;
        }
        else {
            cur=cur+val-q.back();
            if(cur != 0) q.push_front(cur);
            cur=0;
            ans+=q.back()+1;
            //cout<<q.back()+1<<" ";
            q.pop_back();
        }
    }
    //ans+=cur;
    if(q.size()==1){
        int b=q.back();
        if(b==1)ans++;
        else {cur+=b;
        if((cur)%2){cur--;ans++;}
        ans+=cur/2;
        ans++;}
    }
    cout<<ans<<"\n";

    

}  
int main()
{   
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}