#include <bits/stdc++.h>
using namespace std;

int main(){

   string str;
   map<char,pair<string,int>>::iterator it;
   map<string,int>::iterator IT;
   map<char,pair<string,int>> abrevs;
   map<string,int> quant;
   while(getline(cin,str) && str != "."){
      int cont = 0;
      istringstream tudo(str);
      string x;
      while(tudo >> x){
         if(x.size() > 2){
            it = abrevs.find(x[0]);
            IT = quant.find(x);
            if(IT == quant.end()){
               quant[x] = 1;
            }
            else{
               quant[x]++;
            }
            if(it == abrevs.end()){
               abrevs[x[0]] = {x,x.size()};
               cont++;
            }
            else{
               if((x.size() - 2)*quant[x] > (it->second.first.size() - 2)*quant[it->second.first]){
                  abrevs[x[0]] = {x,x.size()};
               }
            }
         }
      }
      bool cond = true;
      istringstream tudodenovo(str);
      while(tudodenovo >> x){
         it = abrevs.find(x[0]);
         if(it == abrevs.end()){
            if(cond){
               cout<<x;
               cond = false;
            }
            else{
               cout<<" "<<x;
            }
         }
         else{
            if(it->second.first == x){
               if(cond){
                  cout<<it->first<<".";
                  cond = false;
               }
               else{
                  cout<<" "<<it->first<<".";
               }
            }
            else{
               if(cond){
                  cout<<x;
                  cond = false;
               }
               else{
                  cout<<" "<<x;
               }
            }
         }
      }
      cout<<"\n"<<cont<<"\n";
      for(it = abrevs.begin();it != abrevs.end();it++){
         cout<<it->first<<"."<<" = "<<it->second.first<<"\n";
      }
      abrevs.clear();
      quant.clear();
   }

   return 0;
}