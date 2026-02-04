#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
    int x,y;
    cin>>x>>y;
    if(x==1&&y==2)cout<<-1;
    else if(x==1&&y==3)cout<<-1;
    else if(x==2&&y==3)cout<<-1;
    else if(x==2&&y==2)cout<<-1;
    else if(x!=y||x%2==0||y%2==0)
    {
        if(x%2==0&&x!=2)cout<<x/2<<" "<<x/2;
        else if(y%2==0)cout<<y/2<<" "<<y/2;
        else cout<<(y-1)/2<<" "<<(y-1)/2;
    }
    else if(x==y)
    {   bool can=false;
        for(int i=2;i<=sqrt(x);i++)
        {
            if(x%i==0)
            {   
                can=true;
                cout<<i<<" "<<((x/i)-1)*i;
                break;
            }
        }
        if(can==false)cout<<-1;
    }
    cout<<endl;

}
int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}