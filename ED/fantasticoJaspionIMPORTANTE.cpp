#include <bits/stdc++.h>
using namespace std;

int main(){

   map<string,string>::iterator it;
   map<string,string> tradutor;
   int N;
   cin>>N;
   cin.ignore();
   for(int i = 0;i < N;i++){
      int T,M;
      if(i > 0){
         cout<<"\n";
      }
      cin>>T>>M;
      while(T--){
         string x,y;
         cin>>x;
         cin.ignore();
         getline(cin,y);
         tradutor[x] = y;
      }
      for(int j = 0;j < M;j++){
         string x,y;
         getline(cin,x);
         istringstream tudo(x);
         while(tudo >> x){
            streampos pos = tudo.tellg();
            bool ultima = !(tudo >> y);
            if(!ultima){
               tudo.seekg(pos);
            }
            it = tradutor.find(x);
            if(it == tradutor.end()){
               cout<<x;
            }
            else{
               cout<<it->second;
            }
            if(!ultima){
               cout<<" ";
            }
            else{
               cout<<"\n";
            }
         }
      }
      tradutor.clear();
   }
   cout<<"\n";

   return 0;
}