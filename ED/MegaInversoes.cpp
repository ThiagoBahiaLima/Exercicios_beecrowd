#include <bits/stdc++.h>
using namespace std;

int main(){

   int N;
   vector<int> carlos;
   cin>>N;
   for(int i = 0;i < N;i++){
      int x;
      cin>>x;
      carlos.push_back(x);
   }
   int triplas = 0;
   for(int i = 0;i < N - 2;i++){
      int val = 0;
      int aux = carlos[i];
      for(int j = i;j < N && val < 2;j++){
         if(carlos[j] < aux){
            aux = carlos[j];
            val++;
         }
      }
      if(val > 1){
         triplas++;
      }
   }
   cout<<triplas<<"\n";

   return 0;
}