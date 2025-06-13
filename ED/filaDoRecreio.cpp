#include <bits/stdc++.h>
using namespace std;

int main(){

   vector<int> orig,reorg;
   int N;
   cin>>N;
   while(N--){
      int X;
      cin>>X;
      for(int i = 0;i < X;i++){
         int x;
         cin>>x;
         orig.push_back(x);
         reorg.push_back(x);
      }
      for(int i = 0;i < X;i++){
         int aux = reorg[i];
         for(int j = i + 1;j < X;j++){
            if(reorg[j] > aux){
               aux = reorg[j];
               reorg[j] = reorg[i];
               reorg[i] = aux;
            }
         }
      }
      int naomudou = 0;
      for(int i = 0;i < X;i++){
         if(reorg[i] == orig[i]){
            naomudou++;
         }
      }
      cout<<naomudou<<"\n";
      reorg.clear();
      orig.clear();
   }

   return 0;
}