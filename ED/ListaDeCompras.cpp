#include <bits/stdc++.h>
using namespace std;

int main(){

   int N;
   set<string>::iterator it;
   set<string> lista;
   cin>>N;
   cin.ignore();
   for(int i = 0;i < N;i++){ 
      string x;
      getline(cin,x);
      istringstream tudo(x);
      while(tudo >> x){
         lista.insert(x);
      }
      for(it = lista.begin();it != lista.end();it++){
         if(it == prev(lista.end())){
            cout<<*it<<"\n";
         }
         else{
            cout<<*it<<" ";
         }
      }
      lista.clear();
   }

   return 0;
}