#include<iostream>
#include<vector>

using namespace std;
int map[1000][1000];
bool check[1000];
int tptl = 0;

void DFS(int u, int n){
    check[u]= true;
    for(int i=1; i <= n; i++){
        if(check[i] == false && map[u][i] == 1){
            DFS(i,n);
        }
    }
} 

void reset(int n){
    for(int i = 1; i<= n; i++){
        check[i]= false;
    }
}

int main(){
    int n; cin >>n;
    for(int i = 1; i<= n; i++){
        for(int j= 1; j <= n; j++){
            cin >> map[i][j];
        }
    }
    reset(n);
    for(int j = 1; j <= n; j++){
        check[j] = true;
        DFS(1,n);
        for(int i = 1; i <= n; i++){
            if(check[i]== false){
                cout << j <<" ";
                break;
            }
        }
        reset(n);
    }
}