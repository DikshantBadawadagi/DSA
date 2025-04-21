class Solution {
private:
    bool checkDfs(int start, int n, int clr, int color[], vector<vector<int>>& graph){
        color[start] = clr;
        for(auto it :  graph[start]){
            if(color[it] == -1){
                if (!checkDfs(it, n, !color[start], color, graph)){
                    return false;
                }
            }
            else if(color[it] == color[start]){
                return false;
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        for(int i=0; i<n; i++){
            color[i] = -1;
        }

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(!checkDfs(i, n, 0, color, graph)){
                    return false;
                }
            }
        }

        return true;
    }
};
