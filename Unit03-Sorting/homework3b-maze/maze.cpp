#include <iostream>
#include <string>
#include <fstream>
#include "Grid.h"
#include <stack>

using namespace std;

// if maze is solvable from this point or not
bool solveMaze(Grid &maze, int row, int col, int lev, int max_r, int max_col, int max_lev, stack<string> &stack) {

    // base cases

    string coors = to_string(row)+" "+to_string(col)+" "+to_string(lev);
    //cout << coors << endl;

    // if you go outside the maze coordinates
    if ((row < 0) || (col < 0) || (lev < 0) || (row > max_r) || (col > max_col) || (lev > max_lev)) {
        return false;
    }
    //add if you have been there before return false
    if (maze.at(row, col, lev) == 2) {
         return false;
    }

    // if there is a wall
    if (maze.at(row, col, lev) == 0) {
        return false;
    }

    // if you succesfully make it to the end
    if ((row == 0) && (col == 0) && (lev == 0)) {
        stack.push(coors);
        //cout << "hits 0" << endl;
        return true;

    }

    if (maze.at(row,col,lev) == 1) {
        maze.at(row,col,lev) = 2;

        //push coordinates onto stack
        stack.push(coors);
    }


    // recursive step
    if (solveMaze(maze,row-1,col,lev, max_r, max_col, max_lev, stack) ||
        solveMaze(maze,row+1,col,lev, max_r, max_col, max_lev, stack) ||
        solveMaze(maze,row,col-1,lev, max_r, max_col, max_lev, stack) ||
        solveMaze(maze,row,col+1,lev, max_r, max_col, max_lev, stack) ||
        solveMaze(maze,row,col,lev-1, max_r, max_col, max_lev, stack) ||
        solveMaze(maze,row,col,lev+1, max_r, max_col, max_lev, stack)) {
        return true;
    }


    return false;
}

// 0 is a wall, 1 is empty (able to walk through)
int main(int argc, char* argv[]) {
    stack<string> stack;

    string filename = argv[1];
    string output = argv[2];
    ifstream ifp(filename);
    ofstream ofp(output);


    Grid maze; // allocate a new, blank Grid
    ifp >> maze; // read from an input stream into a Grid
    //cout << "The maze is " << maze.height() << " spaces tall, " << maze.width() << " spaces wide, and " << maze.depth() << " spaces deep" << std::endl; // access the maze's dimensions
    int row = maze.height();
    int col = maze.width();
    int lev = maze.depth();

    //cout << maze.at(row-1, col-1, lev-1); // access the value at a specific location
    //maze.at(row-1, col-1, lev-1) = 2;
    //cout << maze.at(row-1, col-1, lev-1);
    //cout << maze.at(0, 0, 0);

    bool solved = solveMaze(maze, row - 1, col - 1, lev - 1, row - 1, col - 1, lev - 1,stack);

    if (!solved) {
        ofp << "NO SOLUTION" << endl;
    }

    if (solved) {

        ofp << "SOLUTION" << endl;
        while (!stack.empty()){
            ofp << ' ' << stack.top() << endl;
            stack.pop();
        }

    }



    return 0;
}
