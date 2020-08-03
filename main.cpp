#include <iostream>
#include <vector>
#include <queue>
#define NOPATH 9223372036854775807
using namespace std;

vector<long long> Distance;
vector<int> reachable;
vector<int> shortest;

void shortest_paths(vector<vector<int> >&adj, vector<vector<long long> > &cost,int s)
{
 queue<int>Queue;
 vector<int>prev(adj.size(),-1);
 vector<bool>infinity(adj.size(),false);
 vector<bool>isVisited(adj.size());
 Distance[s]=0;
 reachable[s]=1;
 shortest[s]=1;
for(int i=0 ; i < adj[s].size() ; i++)
 {
     Distance[ adj[s][i] ] = cost[s][i];
     reachable[ adj[s][i] ]=1;
     shortest[ adj[s][i]  ]=1;
 }
for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj.size()-1;j++)
        {
            for(int k=0;k<adj[j].size();k++)
            {
               prev[ adj[j][k] ]=k;
               if(Distance[ adj[j][k] ] > Distance[j]+cost[j][k] && Distance[j]!= NOPATH )
               {
                   reachable[ adj[j][k] ]= 1;
                   Distance[ adj[j][k] ] = Distance[j]+cost[j][k];
                   shortest[ adj[j][k] ] = 1;
               }
            }
        }
    }

for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj.size();j++)
        {
            for(int k=0;k<adj[j].size();k++)
            {
               if(Distance[ adj[j][k] ] > Distance[j]+cost[j][k] && Distance[j]!= NOPATH)
               {
                   reachable[ adj[j][k] ]= 1;
                   Distance[ adj[j][k] ] = Distance[j]+cost[j][k];
                   shortest[ adj[j][k] ] = 0;
                   infinity[ adj[j][k] ] =true;
               }
            else if(prev[ adj[j][k] ]!=-1 && infinity[  prev[ adj[j][k] ]  ] ==true )
                {
                    infinity[ adj[j][k] ]=true;
                    shortest[ adj[j][k] ]= 0;
                    reachable[ adj[j][k] ]=1;
                }
            }

        }
    }


}// last

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<long long> > cost(n, vector<long long>());
  Distance.resize(n,NOPATH);
  reachable.resize(n, 0);
  shortest.resize(n, 0);

  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;

  shortest_paths(adj, cost, s);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << Distance[i] << "\n";
    }
  }
}
