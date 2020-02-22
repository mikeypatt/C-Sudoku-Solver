#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

//Function 1 - see sudoku.h for function description.
/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char* filename, char board[][MAX_COLLUMNS]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << '\n';
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << '\n';
  assert(row == 9);
}
//End of Function 1.

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << '\n';
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << '\n';
}


/* internal helper function */
void print_row(const char* data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << '\n';
}


//Function 2 - see sudoku.h for function description.
/* pre-supplied function to display a Sudoku board */
void display_board(const char board[][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) 
    cout << (char) ('1'+r) << "   ";
  cout << '\n';
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}
//End of Function 2.

/* Added functions for the different stages of the courswork*/

//Function 3 - see sudoku.h for function description.
bool is_complete(char board[][MAX_COLLUMNS],int toggle)
{
    //Declares integer variables row_count,collumn_count a used in the function to iterate through the cells of the board.
    int row_count,collumn_count;
    
    //Adtional declarations required for defensive programming addition
    char position[2] ;
    char number ;
    
    //Iterates through each cell in the given board (collumn by colloumn then row by row)
    for(row_count = 0 ; (row_count <= 8) ; row_count++)
    {
        for(collumn_count= 0 ; (collumn_count <= 8) ; collumn_count++)
        {
            //If the cell does not contain a number between 1 and 9 return the whole function false.
            if ((static_cast<int>(board[row_count][collumn_count])- '0') < 1 || (static_cast<int>(board[row_count][collumn_count])- '0') > 9)
                return false ;
            
            //Additional defensive programming code to ensure the board is filled according to Sudoku logic. It is only computed when the toggle switch is turned on (==1)
            if (toggle == 1)
            {   
                //Converts the row and collumn integer postion to a character array to be inputted into the make move function(function 4)
                position[0] = static_cast<char>(row_count+'A')  ;
                position[1] = static_cast<char>(collumn_count + '1')  ;
                //Gets the number in the current postion on the board to be inputted to the make move function (check whether the board is valid)
                number = board[row_count][collumn_count] ;
                //Replaces the number with a dot to allow the make move function (function 4) to check validity of the board and  put the number back if valid.
                board[row_count][collumn_count] = '.' ;
                //If it is not valid it will return the entire function false
                if (!make_move(position,number,board))
                {
                    return false ;
                }
            }
        }
    }
    
    return true ;
    
}
//End of Function 3.


//Function 4 - see sudoku.h for function description
bool make_move(char position[],char input_digit,char board[][MAX_COLLUMNS])
{
    //Declaring the variables of type integer that will be used to ensure that the input number is valid for A game of Sudoku (not for the given board)
    int row ,collumn , position_length = strlen(position) ;
    
    //Declaring the variables of type integer that will be used to ensure that the input number is valid for GIVEN board 
    int row_index = 0, collumn_index = 0 ;
    int block_row = row_index/static_cast<int>(3) ;
    int block_collumn = collumn_index/static_cast<int>(3) ;
    int starting_row_position,starting_collumn_position ;
    
    //Check to ensure that the input digit is not outside the range from 1-9. 
    if (input_digit < '1' || input_digit > '9' )
    {
        return false ;
    }
    
    //Check to ensure that the input postion is not of greater length than two characters. 
    if (position_length > 2)
    {
        return false ;
    }
    
    //Check to ensure that the input row is Uppercase. Unlike the rest of the tests the program will automatically convert the lowercase row index to the correct upper case.
    if (position[0] >= 'a'  && position[0] <= 'i')
    {
        position = (position - 32) ;
    }
    
    //Check to ensure that the input collumn index is in the range 1-9.
    if (position[1] < '1' || position[1] > '9')
    {
        return false ;
    }

    //Converting the input position of rows A-I to an integer index from 0-8
    row_index = static_cast<int>(position[0]-'A') ; 
    //Converting the input position of colloumns 1-9 of type character to an integer index from 0-8.
    collumn_index = static_cast<int>(position[1]-'1')  ; 
    
    
    block_collumn = collumn_index/static_cast<int>(3) ;
    block_row = row_index/static_cast<int>(3) ;
    
    //Check to see if the postion on the original board is occupied by another digit
    if (board[row_index][collumn_index] != '.')
    {
        return false ;
    }

    //Checking if the given collumn contains the number already
    for (collumn=0 ; collumn<= 8 ; collumn++)
    {
        if (board[row_index][collumn] == input_digit)
        {
            return false ; 
        }
    }
        
    //Checking if the given row has the number already
    for (row=0 ; row<= 8 ; row++)
    {
        if (board[row][collumn_index] == input_digit)
        {
            return false ; 
        }
    }
    
    //Switch case to designate the given block number a starting row index on the whole board
    switch (block_row)
    {
        case 0:  starting_row_position = 0;
                 break;
        case 1:  starting_row_position = 3;
                 break;
        case 2:  starting_row_position = 6;
                 break;
    }

    //Switch case to designate the given block number a starting collumn index on the whole board
    switch (block_collumn)
    {
        case 0:  starting_collumn_position = 0;
                 break;
        case 1:  starting_collumn_position = 3;
                 break;
        case 2:  starting_collumn_position = 6;
                 break;
    }
        
    //A For loop that iterates through the 9 cells in the given block to establish whether the move is valid.
    for (row = starting_row_position ;row <= (starting_row_position+2) ; row++)
    {
        for (collumn = starting_collumn_position ;collumn <= (starting_collumn_position+2) ; collumn++)
        {
            if (board[row][collumn] == input_digit)
            {
                return false ;
            }
        }
    }
            
    
    //Changing that position on the board to be the input digit     
    board[row_index][collumn_index] = input_digit ;
    
    //If the move is valid after the board is changed to contain the new input nubmer the function returns true.
    return true ;
}
// End of Function 4


//Function 5 - see sudoku.h for function description
bool save_board(char filename[], char board[][MAX_COLLUMNS])
{
    //Declares two integer variables to enable row and collumn iteration.
    int row,collumn ;
    
    //Creates an Output File Stream called out_stream.
    ofstream out_stream ;
    
    //Opens the output stream to write to the specified filename.
    out_stream.open(filename);
    
    
    
    //A For loop to iterate through the cells and write the designated character to the specified filename.
    for(row=0 ; (row<= 8) ||out_stream.fail() ; row++)
    {
        for(collumn=0 ; (collumn<= 8) ; collumn++)
        {
            out_stream << board[row][collumn] ;
        }
        out_stream << "\r\n" ;
    }
    
    //A check to ensure that the file has written succesfully and will return false if an error occurs.
    if(out_stream.fail())
    {
        return false ;
    }
    
    //Once the file is written the Output file stream is closed.
    out_stream.close() ;
    
    //Once the file is written the Output file stream is closed.
    return true ;
}
// End of Function 5


//Function 6 - see sudoku.h for function description
bool solve_board(char board[][MAX_COLLUMNS])
{

    //Declares integer variables row,collumn and number used throughout the function.
    int row,collumn, number ;
    char charnumber ; // Character variable to convert  the integer number to be inputted into the make move function(function 4)
    char position[2] ; // Character array to be inputted into the make move function(function 4)

    //Declares stactic integer that is used to count the number of times that the function recurses on itself while attempting to solve the board.
    static int Recursive_Counter = 0 ;
    
    //Initial check to see if the board is complete. If the is_complete function returns true the function will exit as the board has been solved. The defenive toggle is turned off as it is not neccessary as the funciton solve board has sudoku logic built in already.
    if(is_complete(board,0))
    {
        //Output the number of times that the function recursed on itself as standard output.
        cout << Recursive_Counter << '\n' << '\n'   ;
        Recursive_Counter = 0 ;
        return true ;
    } 

    //Iterates through each cell in the given board (collumn by colloumn then row by row)
    for(row= 0 ; (row<= 8) ; row++)
    {
        for(collumn= 0 ; (collumn<= 8) ; collumn++)
        {
            //If the cell contains a '.' (is empyty) enter the block to the preceding for loop.
            if(board[row][collumn] == '.')
            {
                //Attempts to add a number to the empty cell using a for loop that iterates through the allowalbe range
                for (number = 1 ; number <= 9 ; number ++ )
                {
                    //Converting the current row and collumn to a character array of a postion on the sudoku board
                    position[0] = static_cast<char>(row+'A')  ;
                    position[1] = static_cast<char>(collumn + '1')  ;
                    charnumber = static_cast<char>(number+'0') ;
                    //Checks to see whether the number is permitted in the given cell and places the number if it is permissiable.
                    if(make_move(position,charnumber,board))
                    {
                        //The recursive counter is incremented by one.
                        Recursive_Counter++ ;
                        
                        //The function is called again and the process is therefore repeated untill the is_complete function returns true
                        if(solve_board(board))
                        {
                            return true ;
                        }
                    }
                    //If the number is not permitted the program places a '.' back in its place. This is requried during the stepping back of the recursive function.
                    board[row][collumn] = '.' ;
                }
                //If numbers none of the numbers 1-9 are permitted in the cell then the function returns false.
                return false ;
            }
        }
    }
    
    return false ;
}
// End of Function 6


