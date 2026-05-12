#include <bits/stdc++.h>
using namespace std;
void solve(string s,int i,vector<string>& ans,string s2){
  if(i == s.size()){
    ans.push_back(s2);
    return;
  }
  solve(s,i+1,ans,s2+s[i]);
  solve(s,i+1,ans,s2);
}
int main() {
  string s;
  cin>>s;
  int n;
  cin>>n;
  vector<string> arr;
  for(int i=0;i<n;i++){
    string temp;
    cin>>temp;
    arr.push_back(temp);
  }
  int count = 0;
  /*for(string s1: arr){
    int i = 0;
    int j = 0;
    while(i<s1.size() && j<s.size()){
      if(s1[i] == s[j]){
        i++;
        j++;
      }else{
        j++;
      }
    }
    if(i == s1.size()) count++;
  }
  cout<<count<<endl;*/
  vector<string> ans;
  solve(s,0,ans,"");
  for(string s2: arr){
    if(find(ans.begin(),ans.end(),s2) != ans.end()) count++;
  }
  cout<<count<<endl;
}