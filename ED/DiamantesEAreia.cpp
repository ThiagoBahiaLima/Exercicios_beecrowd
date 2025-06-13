#include <bits/stdc++.h>
using namespace std;

int main(){

   int N;
   cin>>N;
   while(N--){
      queue<char> terreno;
      string x;
      cin>>x;
      for(int i = 0;i < x.size();i++){
         terreno.push(x[i]);
      }
      int dima = 0,E = 0;
      while(!terreno.empty()){
         if(terreno.front() == '<'){
            E++;
         }
         if(terreno.front() == '>' && E > 0){
            dima++;
            E--;
         }
         terreno.pop();
      }
      cout<<dima<<"\n";
   }

   return 0;
}