#include <bits/stdc++.h>
using namespace std;

int main(){

   map<int,vector<string>>::iterator it;
   map<int,vector<string>,greater<>> palavras;
   int N;
   cin>>N;
   cin.ignore();
   while(N--){
      string x;
      getline(cin,x);
      istringstream tudo(x);
      while(tudo >> x){
         palavras[x.size()].push_back(x);
      }
      bool espaco = false;
      for(it = palavras.begin();it != palavras.end();it++){
         for(int i = 0;i < it->second.size();i++){
            if(espaco){
               cout<<" "<<it->second[i];
            }
            else{
               cout<<it->second[i];
               espaco = true;
            }
         }
      }
      cout<<"\n";
      palavras.clear();
   }


   return 0;
}