#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;

void DFS(int cnt, string path){
	
	if(cnt == M){
		cout << path << "\n";
	}
	else {
	
		vector<bool> selected(10001, false); 
	
		for(int i = 0; i < N; i++){
			
			if(selected[arr[i]] == false){
				
				selected[arr[i]] = true;
				if(path == "")
					DFS(cnt + 1, path + to_string(arr[i]));
				else
					DFS(cnt + 1, path + " " + to_string(arr[i]));
					
			}
			
		}
		
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	
	sort(arr.begin(), arr.end());
		
	DFS(0, "");
	
	return 0;
}
