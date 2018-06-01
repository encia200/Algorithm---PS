#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

#define INF (int)2e9

using namespace std;

int T;
int n, m, t;
int s, g, h;

struct EDGE{
    int u, v, cost;
    EDGE(int u, int v, int cost):u(u),v(v),cost(cost){}
    EDGE(){}
};

vector<EDGE> edge;
vector<int> before_dist,after_dist;
vector<int> candi;

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &n, &m, &t);
        scanf("%d %d %d", &s, &g, &h);
        
        edge = vector<EDGE>(m*2+1);
        before_dist = vector<int>(n+1, INF);
        after_dist = vector<int>(n+1, INF);
        candi = vector<int>(t+1);
        
        for(int i=1;i<=m;i++){
            int a, b, d;
            scanf("%d %d %d", &a, &b, &d);
            edge[i] = EDGE(a,b,d);
            edge[i+m] = EDGE(b,a,d);
        }
        
        for(int i=1;i<=t;i++){
            scanf("%d", &candi[i]);
        }
        sort(candi.begin(), candi.end());
        
        before_dist[s]=0;
        for(int i=1;i<=n-1;i++){
            for(int j=1;j<=m*2;j++){
                if(before_dist[edge[j].v]>before_dist[edge[j].u]+edge[j].cost){
                    before_dist[edge[j].v] = before_dist[edge[j].u]+edge[j].cost;
                }
            }
        }
        
        int before_node = before_dist[g]<before_dist[h]?h:g;
        
        
        after_dist[before_node] = 0;
        for(int i=1;i<=n-1;i++){
            for(int j=1;j<=m*2;j++){
                if(after_dist[edge[j].v]>after_dist[edge[j].u]+edge[j].cost){
                    after_dist[edge[j].v] = after_dist[edge[j].u]+edge[j].cost;
                }
            }
        }
        
        for(int i=1;i<=t;i++){
            if(before_dist[candi[i]]==before_dist[before_node]+after_dist[candi[i]]){
                printf("%d ", candi[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

