#include <bits/stdc++.h>
using namespace std;

int main(){

   string alfa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   int casos;
   cin>>casos;
   while(casos--){
      int val = 0;
      int N;
      cin>>N;
      string x;
      cin>>x;
      for(int i = 0;i < N;i++){
         if(alfa[i] != x[i]){
            val++;
         }
      }
      if(val == 2){
         cout<<"There are the chance.\n";
      }
      else{
         cout<<"There aren't the chance.";
      }
   }

   return 0;
}