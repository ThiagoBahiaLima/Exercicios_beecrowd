#include <bits/stdc++.h>
using namespace std;

int main(){

   map<string,vector<string>>::iterator it;
   map<string,vector<string>> dominio,imagem;
   int N;
   while(cin>>N && N != 0){
      cin.ignore();
      while(N--){
         string x,y;
         getline(cin,x);
         istringstream tudo(x);
         tudo >> x;
         tudo >> y;
         tudo >> y;
         dominio[x].push_back(y);
         imagem[y].push_back(x);
      }
      bool funcao = true;
      bool invertivel = true;
      for(it = dominio.begin();it != dominio.end();it++){
         if(it->second.size() != 1){
            funcao = false;
         }
      }
      for(it = imagem.begin();it != imagem.end();it++){
         if(it->second.size() != 1){
            invertivel = false;
         }
      }
      if(!funcao){
         cout<<"Not a function.\n";
      }
      else{
         if(!invertivel){
            cout<<"Not invertible.\n";
         }
         else{
            cout<<"Invertible.\n";
         }
      }
      dominio.clear();
      imagem.clear();
   }

   return 0;
}