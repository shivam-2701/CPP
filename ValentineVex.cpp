#include<bits/stdc++.h>
using namespace std;
#define ll long long



pair<ll,ll> Solve(priority_queue<ll> pEven ,priority_queue<ll> pOdd,int mask){

     ll ans1 =0;
        ll ans2=0;
        int count=1;
        bool f1=0,f2=0;
        bool s1=0,s2=0;
        switch(mask){
            case 0: f1=0, f2=0;
            break;
            case 1: f1=0, f2=1;
            break;
            case 2: f1=1,f2=0;
            break;
            case 3: f1=1,f2=1;
            break;
        }
        // cout<<f1<<" "<<f2<<endl;
         while (s1==0 || s2==0){
                if(f1==0){
                    if(!pEven.empty()){
                    ans1+=pEven.top();
                    pEven.pop();
                    
                    if(f1==0){
                        f1=1;
                    }else{
                        f1=0;
                    }

                    }
                    else{
                        s1=1;
                    }
                }else{
                    if(!pOdd.empty()){
                    ans1+=pOdd.top();
                    pOdd.pop();
                     if(f1==0){
                        f1=1;
                    }else{
                        f1=0;
                    }
                    }else{
                        s1=1;
                    }
                }
                if(f2==0){
                    if(!pEven.empty()){
                    ans2+=pEven.top();
                    pEven.pop();
                     if(f2==0){
                        f2=1;
                    }else{
                        f2=0;
                    }
                    }
                    else{
                        s2=1;
                    }
                }else{
                    if(!pOdd.empty()){
                    ans2+=pOdd.top();
                    pOdd.pop();
                    if(f2==0){
                        f2=1;
                    }else{
                        f2=0;
                    }
                    }else{
                        s2=1;
                    }
                } 
            }
            // cout<<ans1<<" "<<ans2<<endl;
            return {ans1,ans2};

}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        priority_queue<ll> pEven,pOdd;
        for(int i=0;i<n;i++){
            ll temp;
            cin >> temp;
            if(temp%2==0){
                pEven.push(temp);
            }else{
                pOdd.push(temp);
            }
        }
        vector<pair<ll,ll>> ans;
       for(int i=0;i<4;i++){
          ans.push_back(Solve(pEven,pOdd,i)); 
       }
        int idx=-1;
        ll score1=INT_MIN,score2=INT_MIN;
        if(ans[0].second>ans[1].second){
            score1=ans[0].first;
        }else if(ans[0].second==ans[1].second){
            score1=max(ans[0].first,ans[1].first);
        }
        else{
            score1=ans[1].first;
        }
        if(ans[2].second>ans[3].second){
            score2=ans[2].first;
        }else if(ans[2].second==ans[3].second){
            score2=max(ans[2].first,ans[3].first);
        }
        else{
            score2=ans[3].first;
        }
        cout<<max(score2,score1)<<endl;

        
        

    }
    
}
