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
    multiset<int> l,r;
    while(n--){
        char order;
        cin>>order;
        if(order=='+'){
            int x,y;
            cin>>x>>y;
            l.insert(x);
            r.insert(y);
            // if(x==y)l.erase(x);
        }
        else {
            int x,y;
            cin>>x>>y;
            // if(x==y)l.insert(x);
            l.erase(l.find(x));
            r.erase(r.find(y));
        }
        // if(!r.empty()&&!l.empty())cout<<*(r.begin())<<" "<<*(--l.end())<<"\n";
        // for(auto itr:r) cout << itr << " ";
        // cout << endl;
        if(r.size()>1&&l.size()>1&&*(r.begin())<*(--l.end()))cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
}
int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}