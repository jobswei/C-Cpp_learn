#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<stack>
#define N 100
using namespace std;

class graph{
    public :
        // 邻接表表示
        vector<int> Adj[N];
        int n;

        // 深度遍历
        void DFSgraph(int p){
            bool isok[n]={true};
            DFS(p,isok);
        }
        void DFS(int p,bool (&isok)[]){
            cout<<p<<" ";
            isok[p]=false;
            for(auto i: Adj[p]){
                if (isok[i]){
                    
                    DFS(i,isok);
                }
            }
        }

        // 广度遍历
        void BFSgraph(){
            for(int i=0;i<n;i++){
                BFS(i);    // 主要考虑到非连通图的情况
            }
        }
        void BFS(int p){
            bool isok[n]={true};
            queue<int> qu;
            qu.push(p);
            cout<<p<<" ";
            isok[p]=false;
            while(!qu.empty()){
                int temp=qu.front();
                qu.pop();
                for(auto i:Adj[temp]){
                    if (isok[i]){
                        cout<<i<<" ";
                        isok[i]=false;
                        qu.push(i);
                    }
                }
            }
        }
};

// Dijkstra 算法
int n,G[N][N];
int INF=10000000;
int dis[N]; // 从起点到达各个顶点的路程
bool vis[N]={false};  // 是否已经访问
void Dijkstra(int s){
    fill(dis,dis+N,INF);

    dis[s]=0;
    for(int i=0;i<N;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<N;j++){
            if(vis[j]==false && dis[j]< MIN){ // 找到距离最小的
                u=j;
                MIN=dis[j];
            }
            if (u==-1) return ;
            vis[u]=true;
            for(int v=0;v<N;v++){
                if(vis[v]==false && G[u][v]!=INF && dis[u]+G[u][v]<dis[v]){
                    dis[v]=dis[u]+G[u][v];
                }
            }
        }
    }
}
// 邻接表版
vector<int> Adj[N];
void Dijkstra2(int s){
    fill(dis,dis+N,INF);
    fill(vis,vis+N,false);
    dis[s]=0;
    for(int i=0;i<N;i++){
        int u=-1;
        int MIN=INF;
        for(int j=0;j<N;j++){
            if(vis[j]==false && dis[j]<MIN){
                u=j;
                MIN=dis[j];
            }
            if(u==-1) return;
            vis[u]=true;   // vis 起到了永久集合的作用

            for(auto v:Adj[u]){
                //if(dis[v]==false && dis[u]+v.dist<dis[v]) dis[v]=dis[u]+v.dist   这里v得是一个Node类，储存距离
            }
        }
    }
}

// Floyd 算法
class Floyd{
    public:
        int MAXV=100;
        int INF=100000;
        int **dis;
        Floyd(){
            dis=new int*[MAXV];
            for(int i=0;i<MAXV;i++){
                *(dis+i)=new int[MAXV];
            }
        }
        void floyd(){
            for(int k=0;k<MAXV;k++ ){
                for(int i=0;i<MAXV;i++){
                    for(int j=0;j<MAXV;j++){
                        if(dis[i][k]!=INF && dis[k][j]!=INF && dis[i][k]+dis[j][k]<dis[i][j]){
                            dis[i][j]=dis[i][k]+dis[j][k];
                        }
                    }
                }
            }
        }
};

// prim 算法，适用于稠密图
class Prim{
    public: 
        void prim(int **G, int n){
            bool vis[n]={false};
            int dis[n]={INF};
            int close[n];

            int p=0;
            fill(close,close+n,0);// 最近邻点先都设为0
            for (int i=0;i<n;i++){
                dis[i]=G[i][0]; // 更新U-V的各个点到U的最近邻距离
            }
            vis[0]=true;
            for(int j=0;j<n;j++){
                p=-1;
                int MIN=INF;
                for(int i=0;i<n;i++){
                    if(vis[i]==false && dis[i]<MIN){
                        MIN=dis[i];
                        p=i;
                    }
                }
                if (p==-1) return;
                vis[p]=true;
                for(int k=0;k<n;k++){
                    if(vis[k]==false && dis[k]>G[p][k]){
                        dis[k]=G[p][k];
                        close[k]=p;
                    }
                }
            }   
        }
};
// kruakal 算法 适用于稀疏图
class TopSort{
    public:
        vector<int> sque;
        int n;
        TopSort(int n){
            this->n=n;
            
        }

        void sort(int **G){
            int inDegree[n]={0}; // 记录入度的数组
            stack<int> sta;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(G[i][j]<INF){
                        inDegree[j]+=1;
                    }
                }
            }
            for(int i=0;i<n;i++){
                if(inDegree[i]==0){
                    sta.push(i);
                }
            }
            while(!sta.empty()){
                int p=sta.top();
                sta.pop();
                sque.push_back(p);
                for(int j=0;j<n;j++){
                    if(G[p][j]<INF){
                        inDegree[j]--;  // G[p][p]=0<INF , p的入度这时候为负数了，所以不用重复考虑
                    }
                    if(inDegree[j]==0){
                        sta.push(j);
                    }
                }
            }
            if(sque.size()!=n){
                cout<<"Error"<<endl;
            }
            return;

        }
};
