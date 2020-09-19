#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0, index = 0 , count = 0;
    vector<vector<int>> adj;
    stack<int> s;
    bool visited[n];
    
    for(int i = 0 ; i < n ; i++){
        adj.push_back(vector<int>());
        visited[i] = false;
        for(int j = 0 ; j < n ; j++){
            if(computers[i][j] == 1 && i != j)
                adj[i].push_back(j);
        }
    }
    while(1){
        for(int i = 0 ; i < n ; i++){
            if(visited[i] == false){
                index = i;
                break;
            }
            if(i == n-1)
                return answer;
        } 
        s.push(index);
        while(!s.empty()){
            index = s.top();
            visited[index] = true;
            cout << "<" << index << ">" << endl;
            s.pop();
            for(int j = 0 ; j < adj[index].size() ; j++){
                if(visited[adj[index][j]] == false)
                   s.push(adj[index][j]);
            }
        }
        answer++;
    }

    return answer;
}