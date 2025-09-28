#include <iostream>
#include <vector>
#include <map>
#include <queue>

struct trio
{
   std::string part;
   std::string dest;
   std::string dir;

   trio() : part(""), dest(""), dir("") {}

   trio(std::string part, std::string dest, std::string dir) : part(part), dest(dest), dir(dir) {}
};

int main()
{

   std::map<std::string,bool>::iterator it;

   int casos = 0;
   bool primeiro = true;

   std::cin >> casos;

   while(casos--)
   {
      if(!primeiro)
      {
         std::cout << "\n";
      }

      primeiro = false;

      std::map<std::string,std::vector<std::string>> garfo;
      std::map<std::string,bool> vis;
      std::map<std::string,std::map<std::string,trio>> caminho;

      int ligas = 0, metas = 0;

      std::cin >> ligas >> metas;

      std::string part;
      std::string dest;

      while(ligas--)
      {
         std::cin >> part >> dest;
         garfo[part].push_back(dest);
         garfo[dest].push_back(part);
         vis[part] = false;
         vis[dest] = false;
      }

      while(metas--)
      {
         for(it = vis.begin(); it != vis.end(); it++)
         {
            it->second = false;
         }

         std::cin >> part >> dest;

         std::queue<trio> fila;
         fila.push({"sexo", part, dest});
         bool chegou = false;
         std::pair<std::string,std::string> indices;
         caminho["sexo"][part] = {"vazio", "vazio", part};

         while(!fila.empty() && !chegou)
         {
            trio Q = fila.front();
            fila.pop();

            for(unsigned int i = 0; i < garfo[Q.dest].size(); i++)
            {
               if(!vis[garfo[Q.dest][i]])
               {
                  fila.push({Q.dest, garfo[Q.dest][i], Q.dest});
                  caminho[Q.dest][garfo[Q.dest][i]] = {Q.part, Q.dest, garfo[Q.dest][i]};
                  vis[garfo[Q.dest][i]] = true;

                  if(garfo[Q.dest][i] == dest)
                  {
                     chegou = true;
                     indices = {Q.dest, garfo[Q.dest][i]};
                  }
               }
            }
         }

         std::string c;
         while(indices.first != "vazio")
         {
            c = caminho[indices.first][indices.second].dir[0] + c;
            indices = {caminho[indices.first][indices.second].part, caminho[indices.first][indices.second].dest};
         }

         std::cout << c << "\n";
      }
   }

   return 0;
}