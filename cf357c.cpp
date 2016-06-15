#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
#include <queue> 
#include <vector> 
#include <utility> 
#include <string> 
using namespace std; 

typedef pair<string,int> P;  
typedef pair<int,P> PP;  

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	priority_queue< int, vector<int>, greater<int> > pq; 
	vector<P> v; 
	int n; 
	cin >> n;  
	int m;   
	for (int i = 0; i < n; i++){
		string s; int val;  // val = x
		cin >> s;  
		if (s == "insert"){ // no operation we have to do. 
			cin >> val;  
			pq.push(val);   
			v.push_back(P("insert",val)); 
		}else if (s == "getMin"){ // if pq.top() < getMin x or if pq.empty()
			cin >> val; 
			if (pq.empty()){
				pq.push(val);  
				v.push_back(P("insert",val)); 
				v.push_back(P("getMin",val)); 
			}else if (pq.top() < val){  
				while (true){
					if (pq.top() == val){
						v.push_back(P("getMin",val)); 
						break; 
					}else if (pq.top() > val){
						pq.push(val); 
						v.push_back(P("insert",val)); 
						v.push_back(P("getMin",val)); 
						break; 
					}else if (pq.empty()){
						pq.push(val); 
						v.push_back(P("insert",val)); 
						v.push_back(P("getMin",val));  
						break; 
					}
					pq.pop(); 
					v.push_back(P("removeMin",-1));  // -1 is a rubbish value.
				}
			}else if (pq.top() > val){
				pq.push(val); 
				v.push_back(P("insert",val)); 
				v.push_back(P("getMin",val)); 
			}else if (pq.top() == val){
				v.push_back(P("getMin",val)); 
			}
		}else if (s == "removeMin"){	
			if (pq.empty()){
				//pq.push(1);  
				v.push_back(P("insert",1)); 
				//pq.pop(); 
				v.push_back(P("removeMin",-1)); 
			}else{
				pq.pop();  
				v.push_back(P("removeMin",-1));   
			}
		}
	}
	cout << (int)v.size() << endl; 
	for (int i = 0; i < v.size(); i++){
		if (v[i].first == "removeMin"){
			cout << v[i].first << endl; 
		}else{
			cout << v[i].first << " " << v[i].second << endl; 
		}
	}
	return 0; 
}
