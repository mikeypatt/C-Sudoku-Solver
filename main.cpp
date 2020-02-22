#include <iostream>
#include <cstdio>
#include "sudoku.h"


using namespace std;



int main() {
    
    
  char board[MAX_ROWS][MAX_COLLUMNS];

  /* This section illustrates the use of the pre-supplied helper functions. */
  cout << "============= Pre-supplied functions =============" << "\n\n";

  cout << "Calling load_board():" << '\n';
  load_board("easy.dat", board);

  cout << '\n' << "Displaying Sudoku board with display_board():" << '\n';
  display_board(board);
  cout << "Done!" << "\n\n";


  cout << "=================== Question 1 ===================" << "\n\n";

  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board,0))
    cout << "NOT ";
  cout << "complete." << "\n\n";

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board,0))
    cout << "NOT ";
  cout << "complete." << "\n\n";
  
  /*Test to see if the board is filled according to Sudoku logic. Toggle switch is set to 1.
    Please ensure the file fullof1s.dat is in the current working directory. */
  load_board("fullof1s.dat", board);
  cout << "Board is ";
  if (!is_complete(board,1))
    cout << "NOT ";
  cout << "complete." << "\n\n";

  
  
  cout << "=================== Question 2 ===================" << "\n\n";

  load_board("easy.dat", board);

  // Should be OK
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);
  
  //Aditional Testing conducted to ensure a robust solution 
  
  //Tries to put the lowercase equivalent of the allowable letters as the position input
  cout << "Putting '1' into a8 is ";
  if (!make_move("a8", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);
  
  //Tries to place 1 into a postion that does not exist on the board
  cout << "Putting '1' into P8 is ";
  if (!make_move("P8", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);
  
  //Tries to 1 into a postion that does not exist on the board
  cout << "Putting '1' into A11 is ";
  if (!make_move("A11", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);
  
  //Tries to 1 into a postion that does not exist on the board
  cout << "Putting '1' into A0 is ";
  if (!make_move("A0", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  //Tries to 0 into a valid position on the board
  cout << "Putting '0' into A0 is ";
  if (!make_move("A1", '0', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  //Tries to put 10 into a valid position on the board
  cout << "Putting '10' into A0 is ";
  if (!make_move("A1", '10', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);
  
  
   //Tries to an invalid digit into a postion that does not exist on the board
  cout << "Putting '%' into P8 is ";
  if (!make_move("P8", '%', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  
  cout << "=================== Question 3 ===================" << "\n\n";

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board))
    cout << "Save board to 'easy-copy.dat' successful." << '\n';
  else
    cout << "Save board failed." << '\n';
  cout << '\n';
  

  cout << "=================== Question 4 ===================" << "\n\n";

  load_board("easy.dat", board);
  if (solve_board(board)) {
    cout << "The 'easy' board has a solution:" << '\n';
    display_board(board);
  } else 
    cout << "A solution cannot be found." << '\n';
  cout << '\n';

  load_board("medium.dat", board);
  if (solve_board(board)) {
    cout << "The 'medium' board has a solution:" << '\n';
    display_board(board);
  } else 
    cout << "A solution cannot be found." << '\n';
  cout << '\n';

/*Additonal check to ensure the alogorithm can solve extremely hard puzzzles. Puzzle
was taken from http://www.7sudoku.com/view-puzzle and was the chosen puzzle on Monday 28th of October.
Please ensure the file veryhard.dat is placed within the current working directory.*/
  load_board("veryhard.dat", board);
  if (solve_board(board)) {
    cout << "The 'external very hard' board has a solution:" << '\n';
    display_board(board);
  } else 
    cout << "A solution cannot be found." << '\n';
  cout << '\n';

  cout << "=================== Question 5 ===================" << "\n\n";

	
  
  load_board("mystery1.dat", board) ;
  if (solve_board(board)) {
    cout << "The 'mystery1' board has a solution:" << '\n';
    display_board(board);
  } else 
    cout << "A solution cannot be found." << '\n';
  cout << '\n';
  

  load_board("mystery2.dat",board) ;
  if (solve_board(board)) {
    cout << "The 'mystery3' board has a solution:" << '\n';
    display_board(board);
  } else 
    cout << "A solution cannot be found." << '\n';
  cout << '\n';
  

  load_board("mystery3.dat",board) ;
  if (solve_board(board)) {
    cout << "The 'mystery3' board has a solution:" << '\n';
    display_board(board);
  } else 
    cout << "A solution cannot be found." << '\n';
  cout << '\n';
  
  return 0;
}
