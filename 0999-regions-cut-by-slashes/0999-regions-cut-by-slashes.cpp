class Solution {
private:
    void dfs(vector<vector<int>>& graph, int i, int j){
        if(i < 0 || i >= graph.size() || j < 0 || j >= graph[0].size() || graph[i][j] == 1){
            return;
        }
        graph[i][j] = 1;
        dfs(graph, i-1, j);
        dfs(graph, i+1, j);
        dfs(graph, i, j-1);
        dfs(graph, i, j+1);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> graph(n * 3, vector<int>(n * 3, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '/'){
                    graph[i*3][j*3 + 2] = graph[i*3 + 1][j*3 + 1] = graph[i*3 + 2][j*3] = 1;
                }
                else if(grid[i][j] == '\\'){
                    graph[i*3][j*3] = graph[i*3 + 1][j*3 + 1] = graph[i*3 + 2][j*3 + 2] = 1;
                }
            }
        }

        int res = 0;
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph[0].size(); j++){
                if(graph[i][j] == 0){
                    dfs(graph, i, j);
                    res++;
                }
            }
        }

        return res;
    }
};