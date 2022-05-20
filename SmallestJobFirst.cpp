#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of process"<<endl;
    cin>>n;
    pair<int,int>time[n];
    int ct[n];
    int bt_[n];
    pair<int,int> bt[n];
    int curr=0;
    cout<<"Enter the bust time of the process"<<endl;
    for(int i=0;i<n;i++){
        cin>>bt[i].first;
        bt_[i]=bt[i].first;
        bt[i].second=i;
    }
    sort(bt,bt+n);
    for(int i=0;i<n;i++){
        ct[bt[i].second]=curr+bt[i].first;
        curr+=bt[i].first;
    }
    // for(int i=0;i<n;i++){
    //     tat[i]=ct[i]-bt_[i];
    // }
    float avgTat=0;
    for(int i=0;i<n;i++){
        avgTat+=ct[i];
    }
    cout<<"Turnaround Time of the process is as follows: "<<"\n";
    for(int i=0;i<n;i++){
        cout<<ct[i]<<" ";
    }
    cout<<endl;
    cout<<"Waiting Time of the process is as follows: "<<"\n";
    for(int i=0;i<n;i++){
        cout<<ct[i]-bt_[i]<<" ";
    }
    avgTat/=n;
    cout<<"\n"<<avgTat<<endl;
    
    
}