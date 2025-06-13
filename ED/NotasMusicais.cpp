#include <bits/stdc++.h>
using namespace std;

int main(){

   string x = "Placeholder";
   while(cin>>x && x != "*"){
      int quantos = 0;
      float tempo = 0;
      for(int i = 0;i < x.length();i++){
         if(x[i] == '/'){
            if(tempo == 1){
               quantos++;
            }
            tempo = 0;
         }
         if(x[i] == 'W'){
            tempo += 1;
         }
         if(x[i] == 'H'){
            tempo += (float)1/2;
         }
         if(x[i] == 'Q'){
            tempo += (float)1/4;
         }
         if(x[i] == 'E'){
            tempo += (float)1/8;
         }
         if(x[i] == 'S'){
            tempo += (float)1/16;
         }
         if(x[i] == 'T'){
            tempo += (float)1/32;
         }
         if(x[i] == 'X'){
            tempo += (float)1/64;
         }
      }
      cout<<quantos<<"\n";
      quantos = 0;
   }

   return 0;
}