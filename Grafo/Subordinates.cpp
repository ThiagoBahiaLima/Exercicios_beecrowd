#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& garfo,int pos,vector<int>& subs){
   for(unsigned int i = 0;i < garfo[pos].size();i++){
      dfs(garfo, garfo[pos][i], subs);
      subs[pos] += subs[garfo[pos][i]];
   }
}

int main(){

   int funcs = 0;
   cin>>funcs;

   vector<vector<int>> garfo(funcs);
   vector<int> subs(funcs,0);

   for(int i = 1; i < funcs;i++){
      int x;
      cin>>x;
      garfo[x - 1].push_back(i);
      subs[x - 1]++;
   }

   dfs(garfo, 0, subs);

   cout<<subs[0];

   for(int i = 1;i < funcs;i++){
      cout<<" "<<subs[i];
   }
   cout<<"\n";

   return 0;
}