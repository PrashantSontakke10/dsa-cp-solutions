🧩 Spell Checker
Problem Statement
You are given a magic dictionary string s and n query words. A query word is considered castable if you can form it using characters from s (each character in s can only be used as many times as it appears).
Determine how many query words are castable from s.

Input Format

First line: a string s (the magic dictionary)
Second line: an integer n (number of query words)
Next n lines: one query word per line

Output Format

A single integer — the count of castable query words

Constraints

1 ≤ |s| ≤ 10^5
1 ≤ n ≤ 10^4
1 ≤ |each query word| ≤ 10^3
All strings contain only lowercase English letters


Example
Input:
aabbccdd
4
abc
abc
aabbcc
aabbbcc
Output:
3
Explanation:

abc → needs 1×a, 1×b, 1×c — ✅ available
abc → same — ✅ available
aabbcc → needs 2×a, 2×b, 2×c — ✅ available
aabbbcc → needs 3×b, but only 2×b in s — ❌ not castable



1) Brute Approach
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

3) Optimize Approach 
#include <bits/stdc++.h>
using namespace std;
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
  unordered_map<char,deque<int>> mpp;
  for(int i=0;i<s.size();i++){
    mpp[s[i]].push_back(i);
  }
  for(int i=0;i<n;i++){
    string s2 = arr[i];
    unordered_map<char,deque<int>> mpp2 = mpp;
    int j = 0;
    while(j<s2.size()){
      if(mpp2.find(s2[j]) != mpp2.end() && mpp2[s2[j]].size() != 0){
        mpp2[s2[j]].pop_front();
        j++;
      }else{
       break; 
      }
    }
    if(j == s2.size()) count++;
  }
  cout<<count<<endl;
}
