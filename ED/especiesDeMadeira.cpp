#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int main(){

   int total = 0;
   int N = 0;
   map<string,float>::iterator it;
   map<string,float> arvores;
   cin>>N;
   cin.ignore();
   string y;
   getline(cin,y);
   for(int i = 0;i < N;i++){
      string x;
      if(i > 0){
         cout<<"\n";
      }
      while(getline(cin,x)){
         bool teste = true;
         for (char c : x){
            if (!isspace(c)){
               teste = false;
               break;
            }
         }
         if(x.empty() || teste){
            break;
         }
         total++;
         it = arvores.find(x);
         if(it == arvores.end()){
            arvores[x] = 1;
         }
         else{
            arvores[x]++;
         }
      }
      for(it = arvores.begin();it != arvores.end();it++){
         cout<<fixed<<setprecision(4);
         cout<<it->first<<" "<<((it->second)/total)*100<<"\n";
      }
      total = 0;
      arvores.clear();
   }

   return 0;
}