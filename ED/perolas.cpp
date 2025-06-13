#include <bits/stdc++.h>
using namespace std;

int main(){

   set<string>::iterator it;
   map<string,int>::iterator IT;
   set<string> perolas;
   map<string,int> alunos;
   int P, A, R;
   while(cin>>P>>A>>R && P != 0){
      cin.ignore();
      for(int i = 0;i < P;i++){
         string x;
         getline(cin,x);
         perolas.insert(x);
      }
      int maisErros = 0;
      for(int i = 0;i < A;i++){
         string x;
         int erros = 0;
         getline(cin,x);
         alunos[x] = 0;
         for(int j = 0;j < R;j++){
            string y;
            getline(cin,y);
            it = perolas.find(y);
            if(it != perolas.end()){
               alunos[x]++;
               erros++;
            }
            if(erros > maisErros){
               maisErros = erros;
            }
         }
      }
      bool primeiro = true;
      for(IT = alunos.begin();IT != alunos.end();IT++){
         if(IT->second == maisErros){
            if(primeiro){
               cout<<IT->first;
               primeiro = false;
            }
            else{
               cout<<", "<<IT->first;
            }
         }
      }
      cout<<"\n";
      perolas.clear();
      alunos.clear();
   }

   return 0;
}