
/* I understand that this is not the best place to declare the size of the sudoku board but
as one would look at the header file when picking up the code this is the most global place I could put it to only write it once.
*/
//Delcaring the size of the board.
const int MAX_ROWS = 9, MAX_COLLUMNS = 9 ;

/*
Function 1 loads the various board from the given data file(.dat) that matches the correct file name.
    Input 1 - A constant of type character.
    Input 2 - An array of type character that resembles the sudoku board.*/
void load_board(const char* filename, char board[][MAX_COLLUMNS]);


/*
Function 2 (display_board) displays the loaded board as standard output in the unix command line 
    Input 1 - An array of type character that resembles the sudoku board.*/
void display_board(const char board[9][MAX_COLLUMNS]);


/*
Function 3 (is_complete) is a boolean function that returns true if the board is filled with numbers 1-9.
An addtional functionality was added to ensure that the filled board also conforms to Sudoku rules. 
The integer "toggle" will allow the this defensive code ensuring a board filled comforming to sodoku logic to be switched on and off. 
Toggle == 1 to switch defensive code on and Toggle == 0 to switch it off to help speed up compuation time when not neccessary. 
A board full of 1's will return false when the toggle switch is turned on for example.
    Input 1 - An array of type character that resembles the sudoku board.
    Input 2 - toggle switch to turn the defensive code on or off (default set to off)*/
bool is_complete(char board[][MAX_COLLUMNS],int toggle = 0) ;


/*
Function 4 (make_move) is a boolean function that returns true if the board if the input digit of type character is allowed to be placed in the designated postion of type character  conforming to sudoku rules.
    Input 1 - A character array to allow a character string of two characters long to be inputted to the function.
    Input 2 - A number of type character that is to be placed on the board
    Input 3 - An array of type character that resembles the sudoku board.*/
bool make_move(char position[],char input_digit,char board[][MAX_COLLUMNS]) ;


/*
Function 5 (save_board) is a boolean function that returns true if the updated character array "board" has saved under a given filename succesfully. 
    Input 1 - An array of characters (string) of the output filename.
    Input 2 - An array of type character that resembles the sudoku board.*/
bool save_board(char filename[], char board[][MAX_COLLUMNS]) ;

/*
Function 6 (solve_bard) solves the given sudoku board by means of recursively moving through the allowable coordinates and returns true if the board has a solution and false if the board is unsolvable.
Input 1 - An array of type character that resembles the sudoku board.*/
bool solve_board(char board[][MAX_COLLUMNS]) ;





