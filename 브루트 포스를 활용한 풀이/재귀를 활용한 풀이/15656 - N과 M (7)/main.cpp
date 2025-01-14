#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N, M;
vector<int> arr;

void DFS(int level, string path){
	
	if(level == M){
		cout << path << "\n";
	}
	else {
	
		for(int i = 0; i < N; i++){
			
			if(path == "")
				DFS(level + 1, path + to_string(arr[i]));
			else
				DFS(level + 1, path + " " + to_string(arr[i]));
			
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
