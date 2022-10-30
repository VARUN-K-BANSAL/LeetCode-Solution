class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        const int MOVES[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            const int ROWS = grid.size(), COLS = grid[0].size();
            int minSteps = max( 0, ROWS + COLS - 2 ), obstacles = minSteps - 1, minStepsNextRound = minSteps, steps = 0;
            if( obstacles <= k ) return minSteps; // take a shortcut if we can afford it

            list<vector<int>> togo; togo.push_back({ 0, 0, k }); // BFS: { row, col, remaining k }
            vector<vector<int>> visited( ROWS, vector<int>(COLS, -1) ); visited[0][0] = k; // position -> k remaining

            while( togo.size() ) {
                steps++;
                minSteps = minStepsNextRound;

                for( int sz = togo.size(); sz > 0; sz-- ) {
                    int currR = togo.front()[0], currC = togo.front()[1], currK = togo.front()[2];
                    togo.pop_front();

                    // moves attempty in 4 directions
                    for( auto& move : MOVES ) {
                        int nextR = currR + move[0], nextC = currC + move[1];
                        if( nextR < 0 || nextR >= ROWS || nextC < 0 || nextC >= COLS ) continue;

                        int nextK = currK - grid[nextR][nextC];
                        if( visited[nextR][nextC] >= nextK ) continue; // have been passing less obstacles

                        // maybe we can take a shortcut and go straight to the goal
                        // but jump only from the point closest to the target
                        int stepsToTarget = ( ROWS - nextR ) + ( COLS - nextC ) - 2; // Manhattan distance indeed
                        if( stepsToTarget - 1 <= nextK && stepsToTarget == minSteps - 1 ) 
                            return steps + stepsToTarget;

                        togo.push_back({ nextR, nextC, nextK });
                        visited[nextR][nextC] = nextK;
                        minStepsNextRound = min( minStepsNextRound, stepsToTarget );
                    }
                }
            }

            return -1;
    }
};