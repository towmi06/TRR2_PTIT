#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
bool check[100];
int a[100][100];
int n;
void BFS(int u){
	queue<int> q;
	q.push(u);
	check[u]=true;
	while(!q.empty()){
		int s=q.front();
		q.pop();
		for(int i=1; i<=n;i++){
			if(a[s][i]==1 && check[i]==false){
				check[i]=true;
				q.push(i);
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int dem=0;
	memset(check,false,sizeof(check));
	for(int i=1;i<=n;i++){
		if(check[i]==false){
			dem++;
			BFS(i);
		}
	}
	cout<<dem<<endl;
}