#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int count_1=0,count1=0;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            if(a==-1){
                count_1++;
            }else{
                count1++;
            }
        }
    if(n%2==0){
    if((abs(count_1-count1)==2 and count_1%2==0 )or abs(count_1-count1)==0 ){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    }else{
        if(abs(count_1-count1)==1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

    }


}