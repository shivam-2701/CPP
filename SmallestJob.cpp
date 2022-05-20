#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
class Compare
{
public:
    bool operator() (pair<int,int>& a, pair<int,int>& b)
    {
        if(a.first>b.first){
            return true;
        }else{
            return false;
        }
    }
};
int main(){
    int n;
    cout<<"Enter the number of process"<<endl;
    cin>>n;
    int ct[n];
    int bt[n];
    pp time[n];
    int at[n];
    cout<<"Enter the arrival time"<<endl;
    for(int i=0;i<n;i++){
        cin>>time[i].first;
        at[i]=time[i].first;
        time[i].second=i;
    }
    sort(time,time +n);
    cout<<"Enter the bust time"<<endl;
    for(int i=0;i<n;i++){
        cin>>bt[i];
    }
    priority_queue<pp,vector<pp> ,Compare> pq;
    int visited[n]={0};
    int count=0;
    for(int i=0;i<n;i++){
        if(count<time[i].first){
            count=time[i].first;
        }
        int j=i;
        while(j<n and time[j].first<=count){
            if(visited[j]==0){
            visited[j]=1;
            pp curr =make_pair(bt[time[j].second],time[j].second);
            pq.push(curr);
            }
            j++;
        }
        pp curr=pq.top();
        
        count+=curr.first;
        ct[curr.second]=count;
        pq.pop();
    }
    // for(int i=0;i<n;i++){
    //     cout<<time[i].first<<" "<<time[i].second<<" "<<bt[time[i].second]<<endl;
    // }
    
    int tat[n];
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
    }
     cout<<"Completion time of earch process is as follows"<<endl;
    for(int i=0;i<n;i++){
        cout<<ct[i]<<" ";
    }
    cout<<endl;

    double avgTat=0;

    cout<<"Turnaround time of earch process is as follows"<<endl;
    for(int i=0;i<n;i++){
        cout<<tat[i]<<" ";
        avgTat+=tat[i];
    }
    cout<<endl; 
    cout<<"Average tat is "<<avgTat/n<<endl;   
}