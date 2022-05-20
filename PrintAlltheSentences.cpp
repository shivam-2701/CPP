#include<bits/stdc++.h>
using namespace std;

void printSentence(vector<vector<string>>& wordList,int idx,vector<string>& wordL){

    if(idx==wordList.size()){
        for(int i=0;i<wordL.size();i++){
            cout<<wordL[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<wordList[idx].size();i++){
        wordL.push_back(wordList[idx][i]);
        printSentence(wordList,idx+1,wordL);
        wordL.pop_back();
    }

}
void printAll(vector<vector<string>>& wordList){

    vector<string> wordL;
    
    printSentence(wordList,0,wordL);


}

int main(){
    vector<vector<string>> wordList;
    
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
       int n;
       cin>>n;
       vector<string> tempList;
       for(int j=0;j<n;j++){
           string temp;
           cin>>temp;
           tempList.push_back(temp);
       }
       wordList.push_back(tempList);
    }
    printAll(wordList);

}