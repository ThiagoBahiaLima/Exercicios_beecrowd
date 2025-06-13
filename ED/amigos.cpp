#include <bits/stdc++.h>
using namespace std;

int main(){

   vector<string> nomes;
   string x,y,z;
   getline(cin,x);
   istringstream atual(x);
   getline(cin,x);
   istringstream nova(x);
   getline(cin,x);
   while(atual >> y){
      if(y == x){
         while(nova >> z){
            nomes.push_back(z);
         }
      }
      nomes.push_back(y);
   }
   while(nova >> z){
      nomes.push_back(z);
   }
   bool primeiro = true;
   for(int i = 0;i < nomes.size();i++){
      if(primeiro){
         cout<<nomes[i];
         primeiro = false;
      }
      else{
         cout<<" "<<nomes[i];
      }
   }
   cout<<"\n";

   return 0;
}

