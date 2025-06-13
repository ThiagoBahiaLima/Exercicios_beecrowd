#include <bits/stdc++.h>
using namespace std;

int main(){

   int N;
   while(cin>>N && N != 0){
      stack<int> trem,molejo;
      vector<int> reorg;
      int i = 0;
      int n = 1;
      while(n != 0){
         cin>>n;
         reorg.push_back(n);
         i++;
         if(i == N){
            trem.push(0);
            for(int j = N;j >= 1;j--){
               trem.push(j);
            }
            molejo.push(0);
            i = 0;
            bool entrando = true;
            while(i <= N && entrando){
               if(trem.top() == reorg[i]){
                  trem.pop();
                  i++;
               }
               else{
                  if(molejo.top() == reorg[i]){
                     molejo.pop();
                     i++;
                  }
                  else{
                     if(trem.top() != reorg[i] && trem.top() != 0){
                        molejo.push(trem.top());
                        trem.pop();
                     }
                     else{
                        entrando = false;
                     }
                  }
               }
            }
            i = 0;
            molejo.pop();
            if(molejo.empty()){
               cout<<"Yes\n";
            }
            else{
               cout<<"No\n";
            }
            reorg.clear();
            while(!trem.empty()){
               trem.pop();
            }
            while(!molejo.empty()){
               molejo.pop();
            }
         }
      }
      cout<<"\n";
   }

   return 0;
}