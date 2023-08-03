#include<iostream>
#include<queue>
#define MAX 100
using namespace std;
class Dothi{
    int n;
    int A[MAX][MAX];
    public:
        bool chuaxet[MAX];
        void readdata();
        void set();
        void QueueBFS(int u);
};
void Dothi::readdata(){
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) cin >> A[i][j];
}
void Dothi::set(){
    for(int i=1; i<=n; i++) chuaxet[i]=true;
}
void Dothi::QueueBFS(int u){
    queue<int> hangdoi;
    cout << " " << u;
    chuaxet[u]=false;
    hangdoi.push(u);
    while(!hangdoi.empty()){
        int s=hangdoi.front();
        hangdoi.pop();
        for(int i=1; i<=n; i++)
            if((A[s][i]==1) && (chuaxet[i]==true)){
                cout << " " << i;
                chuaxet[i]=false;
                hangdoi.push(i);
            }
    }
    return;
}
int main(){
    Dothi G;
    G.readdata();
    G.set();
    G.QueueBFS(1);
    return 0;
}