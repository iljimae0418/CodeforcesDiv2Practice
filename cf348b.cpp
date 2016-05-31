#include <iostream> 
#include <cstdio>
#include <cstdlib>
#include <algorithm> 
#include <queue>
using namespace std; 

char a[100001];  
int jumplen[100001];  
bool visited[100001];  

int main(){
	int n; 
	cin >> n;  
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	for (int i = 1; i <= n; i++){
		cin >> jumplen[i];  
	}
	int idx = 1; 
	while (true){
		if (idx < 1 || idx > n){
			printf("FINITE\n");  
			break; 
		}
		if (visited[idx]){
			printf("INFINITE\n"); 
			break; 
		}else{
			visited[idx] = true; 
			if (a[idx] == '>') idx += jumplen[idx]; 
			else idx -= jumplen[idx]; 
		}
	} 
	return 0; 
}
