class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;

        // Find S
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
            }
        }

        // Give every L an id
        map<pair<int, int>, int> id;
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'L') {
                    id[{i, j}] = cnt;
                    cnt++;
                }
            }
        }

        // All litter collected
        int all = (1 << cnt) - 1;

        // visited[r][c][mask] = maximum energy reached here
        vector<vector<vector<int>>> visited(
            m,
            vector<vector<int>>(n, vector<int>(1 << cnt, -1))
        );

        // row, col, energy, mask
        queue<tuple<int, int, int, int>> q;

        q.push({sr, sc, energy, 0});

        visited[sr][sc][0] = energy;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {

            int size = q.size();

            // Process one BFS level
            while (size--) {

                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == all) {
                    return moves;
                }

                // No energy
                if (currEnergy == 0) {
                    continue;
                }

                // Try 4 directions
                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Outside
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    // Wall
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Use one energy
                    int newEnergy = currEnergy - 1;

                    // Reset
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // Collect litter
                    int newMask = mask;

                    if (classroom[nr][nc] == 'L') {
                        int x = id[{nr, nc}];
                        newMask = mask | (1 << x);
                    }

                    // If we have already reached this state
                    // with equal or more energy, skip it.
                    if (visited[nr][nc][newMask] >= newEnergy) {
                        continue;
                    }

                    visited[nr][nc][newMask] = newEnergy;

                    q.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};