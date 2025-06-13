#include <bits/stdc++.h>
using namespace std;

int main(){

   map<int,vector<int>>::iterator it;
   map<int,vector<int>> chaves;
   int N;
   cin>>N;
   for(int a = 0;a < N;a++){
      if(a > 0){
         cout<<"\n";
      }
      int base, quantChaves;
      cin>>base>>quantChaves;
      for(int i = 0;i < quantChaves;i++){
         int x;
         cin>>x;
         chaves[x%base].push_back(x);
      }
      for(int i = 0;i < base;i++){
         it = chaves.find(i);
         if(it == chaves.end()){
            cout<<i<<" -> \\";
            cout<<"\n";
         }
         else{
            cout<<i;
            for(int j = 0;j < chaves[i].size();j++){
               cout<<" -> "<<chaves[i][j];
            }
            cout<<" -> \\";
            cout<<"\n";
         }
      }
      chaves.clear();
   }

   return 0;
}