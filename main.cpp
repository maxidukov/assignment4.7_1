#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

void dfs(const std::vector<std::vector<bool>>& graph, const int& vertex, std::vector<bool>& visited);

void dfs(const std::vector<std::vector<bool>>& graph);

int main() {
  std::ifstream infile("input.txt");
  int size{};
  infile >> size;
  //std::cout<<size<<"\n";
  std::vector<std::vector<bool>> graph(size);
  int i{};
  std::string str;
  while(std::getline(infile,str)){
    //std::cout<<str<<"\n";
    if(str.empty()) continue;
    std::istringstream ss(str);
    bool v{};
    while(ss>>v){
       graph[i].push_back(v);
    }
    i++;
  }
  /*std::cout<<"Print graph:\n";
  for(const auto& vec:graph){
    for(const auto& v:vec){
       std::cout<<v<<" ";
    }
    std::cout<<std::endl;
  }*/
  std::cout << "Порядок обхода вершин: ";
  dfs(graph);
  std::cout<<std::endl;
}

void dfs(const std::vector<std::vector<bool>>& graph, const int& vertex, std::vector<bool>& visited){
   visited[vertex] = true;
   std::cout<<vertex+1<<" ";
   for(int v{}; v<graph.size(); v++){
     if(graph[vertex][v] && !visited[v]){
        dfs(graph,v,visited);
     }
}
}

void dfs(const std::vector<std::vector<bool>>& graph){
  std::vector<bool> visited(graph.size(),false);
  for(int v{}; v<graph.size();v++){
    if(!visited[v]){
      dfs(graph,v,visited);
    }
  }
}
