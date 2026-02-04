#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void d(){
    cout<<"DEBUG";
}
void solve()
{
    int n,sx,sy;
    cin>>n>>sx>>sy;
    int start=(sx+sy)%2;
    vector<int> arr(n+1),even,odd;
    set<int> point;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        arr[i]=(x+y)%2;
        if(arr[i])odd.pb(i);
        else even.pb(i);
        point.insert(i);
    }
    int sum = accumulate(arr.begin(),arr.end(),0);
    int e=0,o=0;
    // start with odd
    if(start){
    if(sum-(n-sum)>=0){ 
        cout<<"First"<<endl;
        for(int i=1;i<=n;i++){
            if(i%2==1){
                if(e!=even.size()){
                    while(true){
                        if(point.count(even[e])){
                            cout<<even[e]<<endl;point.erase(even[e]);e++;break;
                        }
                        e++;
                        if(e==even.size()){
                            while(point.count(odd[o])!=1)o++;
                            cout<<odd[o]<<endl;
                            point.erase(odd[o]);
                            o++;
                            break;
                        }
                    }
                }
                else {
                    while(point.count(odd[o])!=1)o++;
                    cout<<odd[o]<<endl;
                    point.erase(odd[o]);
                    o++;
                }
            }
            else {
                int fp; //friend pick
                cin>>fp;
                point.erase(fp);
                cout<<endl;
            }
        }
    }
    else {
         cout<<"Second"<<endl;
         for(int i=1;i<=n;i++){
            if(i%2==0){
                if(o!=odd.size()){
                    while(true){
                        if(point.count(odd[o])){
                            cout<<odd[o]<<endl;point.erase(odd[o]);o++;break;
                        }
                        o++;
                        if(o==odd.size()){
                            while(point.count(even[e])!=1)e++;
                            cout<<even[e]<<endl;
                            point.erase(even[e]);
                            e++;
                            break;
                        }
                    }
                }
                else {
                    while(point.count(even[e])!=1)e++;
                    cout<<even[e]<<endl;
                    point.erase(even[e]);
                    e++;
                }
            }
            else {
                int fp; //friend pick
                cin>>fp;
                point.erase(fp);
                cout<<endl;
            }
        }
    }
    }//start with even
    else {  
        if(n-2*sum>=0){
            cout<<"First"<<endl;
            for(int i=1;i<=n;i++){
               // cout<<i;d();
                if(i%2==1){
                if(o!=odd.size()){
                    while(true){
                        if(point.count(odd[o])){
                            cout<<odd[o]<<endl;point.erase(odd[o]);o++;break;
                        }
                        o++;
                        if(o==odd.size()){
                            while(point.count(even[e])!=1)e++;
                            cout<<even[e]<<endl;
                            point.erase(even[e]);
                            e++;
                            break;
                        }
                    }
                }
                else {
                    while(point.count(even[e])!=1)e++;
                    cout<<even[e]<<endl;
                    point.erase(even[e]);
                    e++;
                }
            }
            else {
                int fp; //friend pick
                cin>>fp;
                point.erase(fp);
                cout<<endl;
            }
        }
    }
    else {
         cout<<"Second"<<endl;
         for(int i=1;i<=n;i++){
            if(i%2==0){
                if(e!=even.size()){
                    while(true){
                        if(point.count(even[e])){
                            cout<<even[e]<<endl;point.erase(even[e]);e++;break;
                        }
                        e++;
                        if(e==even.size()){
                            while(point.count(odd[o])!=1)o++;
                            cout<<odd[o]<<endl;
                            point.erase(odd[o]);
                            o++;
                            break;
                        }
                    }
                }
                else {
                    while(point.count(odd[o])!=1)o++;
                    cout<<odd[o]<<endl;
                    point.erase(odd[o]);
                    o++;
                }
            }
            else {
                int fp; //friend pick
                cin>>fp;
                point.erase(fp);
                cout<<endl;
            }
        }
    }
    }
} 

int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve();
    }
}
