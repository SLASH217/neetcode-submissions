class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //what if I traverse the whole grid once
        //maintaining a bool array of whatever if possible is that
        //slot then keep updating the bool array as we move through 
        //the grid, more data less uncertainty 
        //suppose slot 3 it will be effected if anything in row 0 
        // col 2 and grid 1 is touched 
        // at max there will be 81 empty slots
        // one state each row and col 
        // one state range for the 3X3 grid each cell gets a unique 
        // state for changes
        // a cell either has number already or doesn't 
        // if already has a number state collapses into that number
        // if blank bool array of possible numbers calculated how?
        // calculated by whatever current local information we have 
        // updated when those states

        //wait wait wait new plan
        //we maintain a row state and a column state as pass the 
        //bool array along the iterator 
        //pause everything I just realized I am solving a different 
        //problem not the given question



        //Valid sudoku , just find out if the given config is even
        //playable to begin with

        //we maintain 3 data that can be shared
        //row data can be shared by the whole row
        //col data for the whole column
        //grid data for the whole grid
        // 9 cols data, 9 rows data, 9 grid data
        
        bitset<10> rows(0);
        bitset<10> cols(0);

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    if (!(rows[board[i][j] - '0'])){
                        rows.flip(board[i][j] - '0');
                    }else{
                        return false;
                    }
                }
                if (board[j][i] != '.'){

                    if (!(cols[board[j][i] - '0'])){
                        cols.flip(board[j][i] - '0');
                    }else{
                        return false;
                    }
                }

            }
            rows.reset();
            cols.reset();
        }

                bitset<10> grid(0);
        for (int k = 0; k < 9; k++){
            // 1. Deriving exact starting rows/columns using integer division and modulo
            int startRow = (k / 3) * 3;
            int startCol = (k % 3) * 3;
            
            // 2. Loop exactly across the 3x3 grid boundaries
            for (int i = startRow; i < startRow + 3; i++){
                for (int j = startCol; j < startCol + 3; j++){
                    if (board[i][j] == '.'){
                        continue;
                    }
                    if(!grid[board[i][j] - '0']){
                        grid.flip(board[i][j] - '0');
                    }else{
                        return false;
                    }
                }
            }
            grid.reset(); // Correctly clears tracking before moving to the next subgrid
        }

        return true;
    }
};
