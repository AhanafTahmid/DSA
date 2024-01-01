#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}

void solve(){
    string s;
    cin>>s;
    vector< pair<char,int>> vc;
    int fr[30]={};
    for(auto x: s){
        fr[x-'A']++;
        //vc.push_back({x,fr[x-'A']++});
    }
    int oc = 0;
    for(int i=0;i<26;i++){
        vc.push_back({char(i+65),fr[i]});
        if(fr[i]%2==1)oc++;
    }

    if(oc>1){
        cout<<"NO SOLUTION"<<endl;
        return;
    }

    sort(vc.begin(),vc.end(),comp);

    deque<char> ans;
    //print odd(which will only appear once)
    for(auto x: vc){
        if(x.second!=0){
            if(x.second%2==1){
                while(x.second--){
                    if(x.second%2==0)ans.push_front(x.first);
                    else ans.push_back(x.first);
                }  
            } 
        }
        //cout<<x.first<<" "<<x.second<<endl;
    }
    
    //print all evens
    for(auto x: vc){
        if(x.second!=0 && x.second%2!=1){
           while(x.second--){
                if(x.second%2==0)ans.push_front(x.first);
                else ans.push_back(x.first);
            }  
        }     
        //cout<<x.first<<" "<<x.second<<endl;
    }



    for(auto x: ans)cout<<x;



}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}