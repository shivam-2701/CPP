#include<bits/stdc++.h>
using namespace std;
void fixUsed(string &ans,int*used){
    for(int i = 0; i < 10;i++){
        used[i] =0;
    }
    for(int i=0;i<ans.size();i++){
        used[ans[i]-'0']=1;
    }
}
int main(){
    int l,r;
    cin>>l>>r;
    string left=to_string(l),right=to_string(r);
    string ans="";
    int used[10] ={0};
    ans+=left[0];
    used[left[0]-'0']=1;
    
    for(int i=1;i<left.size();i++){
        
        if(used[left[i]-'0']==0){
            ans+=left[i];
            used[left[i]-'0']=1;
        }
        else{
            int currR=right[i]-'0';
            if(left[i]-'0'>=right[i]-'0'){
                if(left[i-1]-'0'<right[i-1]-'0'){
                    currR=right[i]-'0' +10;
                }
            }

            int idx=left[i]-'0';
            while(idx<10 and idx<=currR and used[idx]!=0){
                idx++;
            }
            if(idx>currR or idx==10){
                if(ans.size()+1<right.size()){
                    int temp= stoi(ans);
                    temp++;
                    ans=to_string(temp);
                    fixUsed(ans,used);
                  
                }else{
                    cout<<-1<<endl;
                    return 0;
                }
                
            }
            ans+=idx+'0';
        }
    }
    cout<<ans<<endl;
}