#include<iostream>
#include<queue>
#include<queue>
using namespace std;

class Node{
    public :
        int data=0;
        int height=0; // 记录以当前节点为根节点的二叉树高度
        Node * lchild=NULL;
        Node * rchild=NULL;

        Node(int data):data(data){}

        bool operator < ( Node * node2){
            return this->data<node2->data;
        }
};

class BTree{
    public:
        Node * root=NULL;

        void replace_all(Node *root, int x, int newdata){
            if(root==NULL){
                return ;
            }
            if(root->data==x){
                root->data=newdata;
            }
            replace_all(root->lchild,x,newdata);
            replace_all(root->rchild, x, newdata);
        }
        void insert(Node *&root, int x){
            if(root==NULL){
                root=new Node(x);
                return;
            }
            if(x<root->data){
                insert(root->lchild,x);
            }else{
                insert(root->rchild,x);
            }
        }
        void Create(int data[], int n)  { // 创建方法因地制宜
            for(int i=0;i<n;i++){
                insert(this->root,data[i]);
            }
        }

        // 先序遍历
        void preorder(Node *root){
            if(root==NULL){
                return;
            }
            cout<<root->data<<" ";
            preorder(root->lchild);
            preorder(root->rchild);
        }
        // 中序遍历
        void inorder(Node *root){
            if(root==NULL){
                return;
            }
            preorder(root->lchild);
            cout<<root->data<<" ";
            preorder(root->rchild);
        }
        // 后序遍历
        void posorder(Node *root){
            if(root==NULL){
                return;
            }
            preorder(root->lchild);
            preorder(root->rchild);
            cout<<root->data<<" ";
        }
        // 层序遍历
        void layerorder(Node *root){
            queue<Node*> qu;
            qu.push(root);
            while(!qu.empty()){
                Node *now=qu.front();
                cout<<now->data<<" ";
                qu.pop();
                if(!root->lchild){
                    qu.push(root->lchild);
                }
                if(!root->rchild){
                    qu.push(root->rchild);
                }
            }
        }

        // 由先序序列和中序序列构建二叉树
        void createby_pos_in(Node *& root,int (&pre)[],int (&in)[],int n){
            // 先序序列的第一个节点为根节点
            if(n==0) return ;
            int data=pre[0];
            root= new Node(data);
            int lpre[n],rpre[n],lin[n],rin[n];
            int num=0;
            // 统计左子树所含结点的多少，并将左子树分出来
            while(num<n){
                if(in[num]==data) break;
                lin[num]=in[num];
                lpre[num]=pre[num+1];
                num++;
            }
            // 将右子树分出来
            for(int i=1;i<n-num;i++){
                rin[i-1]=in[num+i];
                rpre[i-1]=pre[num+i];
            }
            delete(pre);
            delete(in);
            int left=num;
            int right=n-num-1;
            createby_pos_in(root->lchild,lpre,lin,left);
            createby_pos_in(root->rchild,rpre,rin,right);
        }
};

class AVLTree{
    public:
        Node * root=NULL;
    
    int getHeight(Node * root){
        if(root==NULL) return 0;
        return root->height;
    }
    // 计算结点root的平衡因子
    int getBalanceFactor(Node *root){
        return getHeight(root->lchild)-getHeight(root->rchild);
    }
    int updateHeight(Node* root){
        root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
    }

    // 查找
    Node * search(Node* root, int x){
        Node * res=NULL;
        if(root==NULL) return NULL;
        if (root->data==x){
            return root;
        }else if(x<root->data){
            return search(root->lchild,x);
        }else{
            return search(root->rchild,x);
        }
    }
    // 左旋
    void leftRotation(Node *& root){
        Node* rchild=root->rchild;
        // Node * rlchild=rchild->lchild;
        root-> lchild=rchild->lchild;
        rchild->lchild=root;
        // root->rchild=rlchild;
        updateHeight(root);
        updateHeight(rchild);
        root=rchild;
    }
    // 右旋
    void rightRotation(Node *& root){
        Node *lchild=root->lchild;
        root->lchild=lchild->rchild;
        lchild->rchild=root;
        updateHeight(root);
        updateHeight(lchild);
        root=lchild;
    }
    void insert(Node *& root, int x){
        if(root==NULL) {
            root=new Node(x);
            return ;
        }

        if(root->data>x){
            insert(root->lchild,x);
            updateHeight(root);
            if(getBalanceFactor(root)==2){
                if(getBalanceFactor(root->lchild)==1){ // LL型
                    rightRotation(root);
                }else if(getBalanceFactor(root->lchild)==-1){ // LR型
                    leftRotation(root->lchild);
                    rightRotation(root);

                }
            }
        }else{
            insert(root->rchild,x);
            updateHeight(root);
            if(getBalanceFactor(root)==-2){
                if(getBalanceFactor(root->rchild)==-1){//RR型
                    leftRotation(root);
                }else if(getBalanceFactor(root->rchild)==1){ // RL型
                    rightRotation(root->rchild);
                    leftRotation(root);
                }
            }
        }
    }

    // AVL 树的建立
    void create(int a[], int n){
        for(int i=0;i<n;i++){
            insert(this->root,a[i]);
        }
    }
};

// 大顶堆
class BigHeap{
    public :
        const int maxn=100;
        int heap[100];
        int n=0;

        // i的孩子结点为 i*2, i*2+1
        // i的父亲结点为 1/2
        void downAdjust(int low , int height){
            int i=low;
            int j=2*i;
            while(j<=height){
                if(j+1<=height && heap[j+1]>heap[j]){
                    j++;
                }
                if(heap[j]>heap[i]){
                    swap(heap[j],heap[i]);
                    i=j;
                    j=2*i;
                }else break;
                
            }
        }

        void create(){
            // 自下而上进行调节
            for(int i=n/2;i>=1;i++){
                downAdjust(i,n);
            }
        }

        void deleteTop(){
            heap[1]=heap[n--];
            downAdjust(1,n);
        }

        // 向上调节，主要用于插入
        void upAdjust(int low, int height){
            int i=height;
            int j=i/2;
            while(j>=low){
                if(heap[i]>heap[j]){
                    swap(heap[i],heap[j]);
                    i=j;
                    j=i/2;
                }else break;
            }
        }

        void insert(int x){
            heap[++n]=x;
            upAdjust(1,n);
        }

};

// 哈夫曼树
class HaffTree{
    public:
        Node *root=NULL;
        string code="";
        void create(int a[], int n){
            priority_queue<Node *> pq;
            for(int i=0;i<n;i++){
                Node *node=new Node(a[i]);
                pq.push(node);
            }

            while(pq.size()>1){
                Node *node1=pq.top();
                pq.pop();
                Node *node2=pq.top();
                pq.pop();
                Node *node3=new Node(node1->data+node2->data);
                node3->lchild=node1;
                node3->rchild=node2;
                pq.push(node3);
            }
            this->root=pq.top();
        }

        string haffCode(int x){
            getCode(this->root, "",x);
            return this->code;
        }
        void getCode(Node *&nownode,string nowstring,int x){
            if(nownode->lchild==NULL && nownode->rchild==NULL ){
                if(nownode->data==x){
                    this->code=nowstring;
                    return;
                }else return;
            }
            if(nownode->lchild != NULL){
                nowstring+="0";
                getCode(nownode->lchild,nowstring,x);
            }
            if(nownode->rchild != NULL){
                nowstring+="1";
                getCode(nownode->rchild,nowstring,x);
            }
        }
};

// 并查集
class UnionFindDisjointSet{
    public :
        int n;
        int *Father=NULL;
        int *rank=NULL;

        UnionFindDisjointSet(int n){
            Father=new int[n];
            for(int i=0;i<n;i++){
                Father[i]=i;
                rank[i]=1;
            }
        }

        int find(int x){
            if(Father[x]==x) return x;
            // return find(Father[x]);
            Father[x]=find(Father[x]);// 同时添加路径压缩
            rank[Father[x]]=2;
            return Father[x];
        }
        void union_xy(int x, int y){
            int fx=find(x);
            int fy=find(y);
            if(rank[fx]<rank[fy]){
                Father[fx]=fx;
            }else{
                if(rank[fx]==rank[fy]){
                    rank[fx]++;
                }
                Father[fy]=Father[fx];
            }
        }
};