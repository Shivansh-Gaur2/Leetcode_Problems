class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flattenBoard(n * n + 1, -1);
        
        // Convert the 2D board into a 1D array
        bool leftToRight = true;
        int idx = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < n; j++) {
                    flattenBoard[idx++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    flattenBoard[idx++] = board[i][j];
                }
            }
            leftToRight = !leftToRight;
        }

        // BFS initialization
        queue<int> q;
        vector<int> visited(n * n + 1, false);
        q.push(1); // Start at the first square
        visited[1] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();

                if (curr == n * n) return steps;

                // Try all moves (dice roll from 1 to 6)
                for (int dice = 1; dice <= 6; dice++) {
                    int next = curr + dice;
                    if (next > n * n) continue; // Out of bounds

                    // If there's a snake or ladder, move to that square
                    if (flattenBoard[next] != -1) {
                        next = flattenBoard[next];
                    }

                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            steps++;
        }

        return -1; // If we can't reach the last square
    }
};
