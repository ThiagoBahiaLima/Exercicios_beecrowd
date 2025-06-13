#include <bits/stdc++.h>
using namespace std;

int main(){
   
   map<int,vector<int>> seila;
   int N,M;
   while(cin>>N>>M){
      for(int i = 0;i < N;i++){
         int x;
         cin>>x;
         seila[x].push_back(i + 1);
      }
      int oco,n;
      while(M--){
         cin>>oco>>n;
         if(oco <= seila[n].size()){
            cout<<seila[n][oco-1]<<"\n";
         }
         else{
            cout<<0<<"\n";
         }
      }
      seila.clear();
   }

   return 0;
}