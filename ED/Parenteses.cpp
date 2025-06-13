#include <bits/stdc++.h>
using namespace std;

int main(){

   queue<char> equacao;
   string x;
   while(cin>>x){
      for(int i = 0;i < x.size();i++){
         equacao.push(x[i]);
      }
      int E = 0,D = 0,EM = 0;
      while(!equacao.empty()){
         if(equacao.front() == '('){
            E++;
            EM++;
         }
         if(equacao.front() == ')'){
            D++;
         }
         if(equacao.front() == ')' && E > 0){
            E--;
         }
         equacao.pop();
      }
      if(EM == D && E == 0){
         cout<<"correct"<<"\n";
      }
      else{
         cout<<"incorrect"<<"\n";
      }
   }

   return 0;
}