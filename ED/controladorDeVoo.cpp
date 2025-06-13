#include <bits/stdc++.h>
using namespace std;

int main(){

   map<string,vector<string>> avioes;
   string x,y;
   int z = 0;
   while(cin>>x && x != "0"){
      if(x[0] == '-'){
         y = x;
      }
      else{
         avioes[y].push_back(x);
         z++;
      }
   }
   int printado = 0;
   bool primeiro = true;
   for(int i = 0;printado < z;i++){
      if(primeiro){
         if(i < avioes["-1"].size()){
            cout<<avioes["-1"][i];
            primeiro = false;
            printado++;
         }
         if(i < avioes["-3"].size() && primeiro){
            cout<<avioes["-3"][i];
            primeiro = false;
            printado++;
         }
         else{
            if(i < avioes["-3"].size()){
               cout<<" "<<avioes["-3"][i];
               printado++;
            }
         }
         if(i < avioes["-2"].size() && primeiro){
            cout<<avioes["-2"][i];
            primeiro = false;
            printado++;
         }
         else{
            if(i < avioes["-2"].size()){
               cout<<" "<<avioes["-2"][i];
               printado++;
            }
         }
         if(i < avioes["-4"].size() && primeiro){
            cout<<avioes["-4"][i];
            primeiro = false;
            printado++;
         }
         else{
            if(i < avioes["-4"].size()){
               cout<<" "<<avioes["-4"][i];
               printado++;
            }
         }
      }
      else{
         if(i < avioes["-1"].size()){
            cout<<" "<<avioes["-1"][i];
            printado++;
         }
         if(i < avioes["-3"].size()){
            cout<<" "<<avioes["-3"][i];
            printado++;
         }
         if(i < avioes["-2"].size()){
            cout<<" "<<avioes["-2"][i];
            printado++;
         }
         if(i < avioes["-4"].size()){
            cout<<" "<<avioes["-4"][i];
            printado++;
         }
      }
   }
   cout<<"\n";

   return 0;
}