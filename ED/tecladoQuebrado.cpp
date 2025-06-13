#include <bits/stdc++.h>
using namespace std;

int main(){

   string x;
   while(cin>>x){
      vector<char> texto;
      for(int i = x.size() - 1;i >= 0;i--){
         if(x[i] == '['){
            for(int j = i + 1;j < x.size() && x[j] != ']' && x[j] != '[';j++){
               texto.push_back(x[j]);
            }
         }
      }
      bool cond = true;
      for(int i = 0;i < x.size();i++){
         if(x[i] == '['){
            cond = false;
         }
         if(cond && x[i] != ']'){
            texto.push_back(x[i]);
         }
         if(x[i] == ']'){
            cond = true;
         }
      }
      cond = false;
      for(int i = 0;i < texto.size();i++){
         cout<<texto[i];
         cond = true;
      }
      if(cond){
         cout<<"\n";
      }
   }

   return 0;
}