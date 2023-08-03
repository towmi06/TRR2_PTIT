#include <bits/stdc++.h>
using namespace std;

int a[100][100],n,u,d;
int X[100];
bool chuaxet[100];
int cnt=0;//dem so chu trinh 
void init(){
    cin>>n>>u;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin>>a[i][j];
    
}
void tao(){
	 for (int i = 0; i <= n; i++)
    {
        chuaxet[i] =true;
	}
    
}
void hmt(int k){
    for (int i = 0; i <= n; i++){
        if (a[X[k-1]][i]){
            if(k==n+1 &&i==u){
                cnt++;
                for(int i=1;i<=n;i++) cout<<X[i]<<" ";cout<<X[1];
                    cout<<endl;
            }
            else if(chuaxet[i]){
                X[k]=i;
                chuaxet[i]=false;
                hmt(k+1);
                chuaxet[i]=true;
                
            }
        }
    }        
}
int main() {
    init();
    tao();
    cout << endl;
    X[1]=u;
    chuaxet[u]=false;
    hmt(2);
    cout << "So chu trinh Hamilton: "<< cnt << endl;
}