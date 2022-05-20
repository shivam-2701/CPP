#include <iostream>
#include<utility>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of process"<<endl;
    cin>>n;
    pair<int,int>time[n];
    int ct[n],tat[n];
    cout<<"Enter the arrival time of the process"<<endl;
    for(int i=0;i<n;i++){
        cin>>time[i].first;
    }
    cout<<"Enter the bust time of the process"<<endl;
    for(int i=0;i<n;i++){
        cin>>time[i].second;
    }
    sort(time,time+n);
    int curr=time[0].first;
    for(int i=0;i<n;i++){
        if(time[i].first<=curr){
        ct[i]=curr+time[i].second;
        curr+=time[i].second;
        }else{
            curr=time[i].first;
            ct[i]=curr+time[i].second;
             curr+=time[i].second;
        }
    }
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-time[i].first;
    }
    float avgTat=0;
    for(int i=0;i<n;i++){
        avgTat+=tat[i];
    }
    cout<<"Turnaround Time of the process is as follows: "<<"\n";
    for(int i=0;i<n;i++){
        cout<<tat[i]<<" ";
    }
    avgTat/=n;
    cout<<"\n"<<avgTat<<endl;
    


}