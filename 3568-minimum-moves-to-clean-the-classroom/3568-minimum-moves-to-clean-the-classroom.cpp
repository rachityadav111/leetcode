class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;

        vector<pair<int, int>> litter;

        vector<vector<int>> litterId(
            m,
            vector<int>(n, -1)
        );

        // Find S and all L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                else if (classroom[i][j] == 'L') {
                    litterId[i][j] = litter.size();
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();
        int fullMask = (1 << k) - 1;

        /*
        best[r][c][mask]
        = maximum energy with which we have reached
          this cell with this mask
        */

        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1 << k, -1)
            )
        );

        // r, c, mask, remainingEnergy, moves
        queue<tuple<int, int, int, int, int>> q;

        q.push({sr, sc, 0, energy, 0});

        best[sr][sc][0] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [r, c, mask, currEnergy, moves] = q.front();
            q.pop();

            // All litter collected
            if (mask == fullMask) {
                return moves;
            }

            // Cannot move without energy
            if (currEnergy == 0) {
                continue;
            }

            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                // Outside grid
                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n) {
                    continue;
                }

                // Wall
                if (classroom[nr][nc] == 'X') {
                    continue;
                }

                int newEnergy = currEnergy - 1;
                int newMask = mask;

                // Collect litter
                if (classroom[nr][nc] == 'L') {

                    int id = litterId[nr][nc];

                    newMask |= (1 << id);
                }

                // Recharge energy
                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                /*
                If we have already reached this same:
                position + collectedMask

                with equal or more energy,
                current state is useless.
                */

                if (best[nr][nc][newMask] >= newEnergy) {
                    continue;
                }

                best[nr][nc][newMask] = newEnergy;

                q.push({
                    nr,
                    nc,
                    newMask,
                    newEnergy,
                    moves + 1
                });
            }
        }

        return -1;
    }
};
