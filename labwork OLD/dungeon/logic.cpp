#include "logic.h"

#define INFO(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;
#define INFO_STRUCT(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = {" << X.row << "," << X.col << "," << X.treasure << "}" << endl;

void printMap(char** map, int maxRow, int maxCol, string header) {
    cout << header << endl;
    for (int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxCol; j++)
        {
            cout << map[i][j] << ",";
        }
        cout << endl;
        
    }
    cout << endl;
}

/**
 * This function is provided; do not change
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  2D dynamic array representation of dungeon map with player's location.
 */
char** loadLevel(const string fileName, int& maxRow, int& maxCol, Player& player) {

    ifstream ifs(fileName);
    if (!ifs.is_open()) {
        cout << "ERROR: Unable to open: " << fileName << endl;
        return nullptr;
    }
    ifs >> maxRow >> maxCol;
    ifs >> player.row >> player.col;

    char** dungeon = createMap(maxRow,maxCol);
    if (dungeon == nullptr) {
        cout << "ERROR: Map did not load." << endl;
        return nullptr;
    }

    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < maxCol; j++) {
            ifs >> dungeon[i][j];
            if (i == player.row && j == player.col) {
                dungeon[i][j] = TILE_PLAYER;
            }
        }
    }

    return dungeon;
}

/**
 * This function is provided; do not change
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 */
void getDirection(char input, int& nextRow, int& nextCol) {
    switch(input) {
        case MOVE_UP:
            nextRow--;
            break;
        case MOVE_DOWN:
            nextRow++;
            break;
        case MOVE_LEFT:
            nextCol--;
            break;
        case MOVE_RIGHT:
            nextCol++;
            break;
    }
}

/*
 * TODO: Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol) {
    char** map = new char*[maxRow];
    for (int i = 0; i < maxRow; i++)
    {
        map[i] = new char[maxCol];
        for (int j = 0; j < maxCol; j++)
        {
            map[i][j] = TILE_OPEN;
        }
    }
    return map;
}

/*
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 */
void deleteMap(char** map, int maxRow) {
    for (int i = 0; i < maxRow; i++)
    {
        delete[] map[i];

    }
    
    delete[] map;

    return;
}

/*
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can call your createMap and deleteMap functions to help with this one!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  An updated 2D map that has twice as many columns and rows in size.
 */
char** resizeMap(char** map, int& maxRow, int& maxCol) {
    char** newMap = createMap(maxRow * 2, maxCol * 2);
    
    
    //   A  |  B
    //   C  |  D

    // subArray A
    for (int row = 0; row < maxRow; row++)
    {
        for (int col = 0; col < maxCol; col++) 
        {
            newMap[row][col] = map[row][col];
        }
    }

    
    
    // subArray B
    for (int row = 0; row < maxRow; row++)
    {
        for (int col = maxCol; col < maxCol * 2; col++) 
        {
            // if current tile is player, assign open tile instead
            if (map[row][col - maxCol] == TILE_PLAYER) {
                newMap[row][col] = TILE_OPEN;
            } else {
                newMap[row][col] = map[row][col - maxCol];
            }
            
        }
    }

    

    // subArray C
    for (int row = maxRow; row < maxRow * 2; row++)
    {
        for (int col = 0; col < maxCol; col++) 
        {
           // if current tile is player, assign open tile instead
            if (map[row - maxRow][col] == TILE_PLAYER) {
                newMap[row][col] = TILE_OPEN;
            } else {
                newMap[row][col] = map[row - maxRow][col];
            }
        }
    }

    

    // subArray D
    for (int row = maxRow; row < maxRow * 2; row++)
    {
        for (int col = maxCol; col < maxCol * 2; col++) 
        {
            // if current tile is player, assign open tile instead
            if (map[row - maxRow][col - maxCol] == TILE_PLAYER) {
                newMap[row][col] = TILE_OPEN;
            } else {
                newMap[row][col] = map[row - maxRow][col - maxCol];
            }
        }
    }

    //printMap(newMap, maxRow * 2, maxCol * 2, "resizeMap new map: ");

    deleteMap(map, maxRow);

    maxRow *= 2;
    maxCol *= 2;

    return newMap;
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int& nextRow, int& nextCol) {

    // don't move out of the map
    if (nextRow > maxRow || nextRow < 0) 
    {
        nextRow = player.row; 
        nextCol = player.col; 
        return STATUS_STAY;
    }

    // don't move out of the map
    if (nextCol > maxCol || nextCol < 0) 
    {   
        nextRow = player.row; 
        nextCol = player.col; 
        return STATUS_STAY;
    }

    //printMap(map, maxRow, maxCol, "Current Map: ");

    char nextTile = map[nextRow][nextCol];

    // don't move into pillars or monsters
    if (nextTile == TILE_PILLAR || nextTile == TILE_MONSTER) 
    {
        nextRow = player.row; 
        nextCol = player.col; 
        return STATUS_STAY;
    }

    if (nextTile == TILE_OPEN) {
        map[nextRow][nextCol] = TILE_PLAYER;
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        return STATUS_MOVE;
    }

    // move to and pick up treasure
    if (nextTile == TILE_TREASURE) 
    {
        map[nextRow][nextCol] = TILE_PLAYER;
        map[player.row][player.col] = TILE_OPEN;
        player.treasure++;
        player.row = nextRow;
        player.col = nextCol;
        return STATUS_TREASURE;
    }

    // move to and pick up amulet
    if (nextTile == TILE_AMULET) 
    {
        map[nextRow][nextCol] = TILE_PLAYER;
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        return STATUS_AMULET;
    }

    // move to and enter door
    if (nextTile == TILE_DOOR) 
    {
        map[nextRow][nextCol] = TILE_PLAYER;
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        return STATUS_LEAVE;
    }

    // move to and escape through exit if player has at least one treasure
    if (nextTile == TILE_EXIT && player.treasure > 0) 
    {
        return STATUS_ESCAPE;
    } else if (nextTile == TILE_EXIT && player.treasure == 0) {
        nextRow = player.row;
        nextCol = player.col;
        return STATUS_STAY;
    }



    return STATUS_STAY; // update to use STATUS consts from logic.h!
}

/*
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 */
bool doMonsterAttack(char** map, int maxRow, int maxCol, Player& player) {
    bool monsterOnPlayer = false;

    //printMap(map, maxRow, maxCol, "MAP Before: ");

    
    // check up
    for (int row = player.row; row >= 0; row--)
    {
        if (map[row][player.col] == TILE_PILLAR) {
            break;
        }
        if (map[row][player.col] == TILE_MONSTER) {
            map[row + 1][player.col] = TILE_MONSTER;
            map[row][player.col] = TILE_OPEN;
            //cout << "Monster moved down at " << row + 1 << "," << player.col << endl;
        }
    }
    
    // check down
    for (int row = player.row; row < maxRow; row++)
    {
        if (map[row][player.col] == TILE_PILLAR) {
            break;
        }

        if (map[row][player.col] == TILE_MONSTER) {
            map[row - 1][player.col] = TILE_MONSTER;
            map[row][player.col] = TILE_OPEN;
            //cout << "Monster moved up at " << row - 1 << "," << player.col << endl;
        }
    }

    // check left
    for (int col = player.col; col >= 0; col--)
    {
        if (map[player.row][col] == TILE_PILLAR) {
            break;
        }

        if (map[player.row][col] == TILE_MONSTER) {
            map[player.row][col + 1] = TILE_MONSTER;
            map[player.row][col] = TILE_OPEN;
            //cout << "Monster moved right at " << player.row << "," << col + 1 << endl;
        } 
    }

    // check right
    for (int col = player.col; col < maxCol; col++)
    {
        if (map[player.row][col] == TILE_PILLAR) {
            break;
        }

        if (map[player.row][col] == TILE_MONSTER) {
            map[player.row][col - 1] = TILE_MONSTER;
            map[player.row][col] = TILE_OPEN;
            //cout << "Monster moved left at " << player.row << "," << col - 1 << endl;
        }
    }

    // check if any monster is on player
    if (map[player.row][player.col] == TILE_MONSTER) {
        return true;
    }

    //printMap(map, maxRow, maxCol, "MAP After: ");
    return false;
}
