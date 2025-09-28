#include <iostream>
#include <vector>
#include <map>
#include <queue>

struct trio
{
   std::string part;
   std::string dest;
   std::string path;

   trio() : part(""), dest(""), path("") {}

   trio(std::string part, std::string dest, std::string path) : part(part), dest(dest), path(path) {}
};

int main(){

   bool primeiro = true;
   int ligas = 0;
   while(std::cin >> ligas)
   {

      if(!primeiro)
      {
         std::cout << "\n";
      }

      primeiro = false;

      std::map<std::string,std::vector<std::string>> garfo;
      std::map<std::string,bool> vis;
      std::map<std::string,std::map<std::string,trio>> caminho;

      std::string x;
      std::string y;

      while(ligas--)
      {
         std::cin >> x >> y;
         garfo[x].push_back(y);
         garfo[y].push_back(x);
         vis[x] = false;
         vis[y] = false;
      }

      std::cin >> x >> y;

      std::queue<trio> fila;
      fila.push({"SEXO", x, "INTENSO"});
      vis[x] = true;
      bool chegou = false;
      std::pair<std::string,std::string> indices;

      while(!fila.empty() && !chegou)
      {
         trio z = fila.front();
         fila.pop();

         for(unsigned int i = 0; i < garfo[z.dest].size(); i++)
         {
            if(!vis[garfo[z.dest][i]])
            {
               
               fila.push(trio(z.dest, garfo[z.dest][i], "SEXO"));
               vis[garfo[z.dest][i]] = true;

               caminho[z.dest][garfo[z.dest][i]] = trio(z.part, z.dest, z.dest + " " + garfo[z.dest][i]);
               
               if(garfo[z.dest][i] == y)
               {
                  chegou = true;
                  indices = {z.dest, garfo[z.dest][i]};
               }
            }
         }

      }

      if(chegou)
      {
         std::string c;
         while(indices.first != "SEXO")
         {
            c = caminho[indices.first][indices.second].path + "\n" + c;
            indices = {caminho[indices.first][indices.second].part, caminho[indices.first][indices.second].dest};
         }

         std::cout << c;
      }
      else
      {
         std::cout << "No route\n";
      }
   }

   return 0;
}