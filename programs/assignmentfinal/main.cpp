/***************************************************************************
 * Program Filename: main.cpp
 * Author:Jose Manuel Lopez Alcala
 * Date: 6/3/2016
 * Description:This program is  a version of Langton's Ant
 * Input: Reading from a file
 * Output: Printing to the screen  
 * ************************************************************************/
#include <iostream>
#include <fstream>
#include <cstring> 
#include <string> 
#include <cstdlib>
#include <unistd.h>
using namespace std;


/***************************************************************************
 * Structue:ANT 
 * Description:Template the serves to make ant instances. It holds the direction 
 * 	       and the x and y current location of the ant
 * Parameters:None
 * Pre-condition:None
 * Post_condition:None
 * ************************************************************************/
struct ANT{
   char* direction;
   int x_current , y_current;
};
//All of the need functions to make program run 
void configuration( int argc, char* argv[], int &iterations, ANT &ant1, char **file);
void num_orientation( ANT ant1, int &orent);
char **grid(char *file, ANT &ant1, char &cell_color, int &rows, int &cols);
void xy_change( int &x_change, int &y_change, int orientation);
void move( char &cell_color, int &orientation, char **array, ANT &ant1,int rows, int cols);
void grid_print(char ** array, int rows,int cols);
void validation( int argc, char *argv[]);
void validate_int(char* a);

int main(int argc, char* argv[]){
   validation(argc,argv);

   int iterations = 0;
   char* file;
   int orientation,rows,cols;
   char color;
   ANT ant1;
   configuration(argc, argv, iterations, ant1, &file);
   char **array = grid(file, ant1, color,rows,cols );
   num_orientation(ant1,orientation);
   //This for loop goes through all of the indicated iterations
   for(int q = 0; q < iterations;q++){
      move(color, orientation, array, ant1,rows,cols);
      grid_print(array,rows,cols);
      cout << endl;
      sleep(1);
   }
}
/***************************************************************************
 * Function: validatoin() 
 * Description: This function will serve to vaidate the users input from the command line arguments 
 * Parameters:argc and argv(command line arguments) 
 * Pre-condition:argc and argv must exist
 * Post_condition: It will validate the usefulness of the command line arguments.
 * 		   If the arguments are not what the program needs, the program wil tell 
 * 		   the user and then it will terminate the program
 * ************************************************************************/
void validation( int argc, char *argv[]){
  //checks to make sure to have the correct amount of arguments 
   if(argc != 11){
      cout << "Your input was invalid, not enough arguments.Program exited." << endl; exit(1);
   }
   //runs through the rest of the arguments and validates correspondingly
   for( int i = 1; i < argc; i+=2){
      if(strcmp(argv[i],"-n") == 0)
      {
	 validate_int(argv[i+1]);
      }
      else if(strcmp(argv[i],"-x") == 0)
      {
	 validate_int(argv[i+1]);
      
      }
      else if(strcmp(argv[i],"-y") == 0)
      {
	 validate_int(argv[i+1]);
      }
      else if(strcmp(argv[i],"-d") == 0)
      {
	 if( strcmp(argv[i+1], "n")!=0 &&  strcmp(argv[i+1], "e")!=0 &&
	     strcmp(argv[i+1], "s")!=0 &&  strcmp(argv[i+1], "w")!=0 
	   ){
	    cout << "You direction has to be n(north),e(east),s(south) or w(west).Program exited." << endl; exit(1);
	 }

      }

   }




}

/***************************************************************************
 * Function:validate()
 * Description:This function will serve to validate the command line arguments 
 * 	       that are supposed to only have integers.
 * Parameters: a is an argv[] c string to be validated 
 * Pre-condition:a must be a c string 
 * Post_condition:This funciton will validate the cstring, if it is valid,
 * 		  it will continue, if not it will tell the user that the input
 * 		  was not valid and then terminate the program.
 * ************************************************************************/
void validate_int(char* a){
   for(int i = 0; a[i]!='\0';i++){
      if(a[i]<'0' || a[i]>'9'){
	 cout << "There is non-numerical element in an integer only argument. Program exited." << endl; exit(1);
      }
   }
}


/***************************************************************************
 * Function:configuration()
 * Description: This function will set up the initial configuration of the 
 * 		the whole thing.It sets the iterations, starting x and y position,
 * 		intial direction.
 * Parameters:argc, argv, iterations ant, and file
 * Pre-condition: argv has to be validated. Iterations and file must exist.
 * 		  ant1 instance must exist 
 * Post_condition:set variables to correspondign information of the program initial 
 * 	          configuration
 * ************************************************************************/
void configuration( int argc, char *argv[], int &iterations, ANT &ant1, char **file){
   for( int i = 1; i < argc; i+=2){
      if(strcmp(argv[i],"-n") == 0)
      {
	 iterations = atoi(argv[i+1]);
      }
      else if(strcmp(argv[i],"-x") == 0)
      {
	 ant1.x_current = atoi(argv[i+1]);
      }
      else if(strcmp(argv[i],"-y") == 0)
      {
	 ant1.y_current = atoi(argv[i+1]);
      }
      else if(strcmp(argv[i],"-d") == 0)
      {
	 ant1.direction = argv[i+1];
      }
      else if( strcmp(argv[i],"-f") == 0)
      {
	 *file = argv[i+1];
      }

   }
}


/***************************************************************************
 * Function:grid() 
 * Description:This function will set up the grid for the ant to travel on. 
 * 	       It will read the configuration from the fiel provided by the 
 * 	       user 
 * Parameters:file, ant, cell_color, rows, cols
 * Pre-condition:ant instance must exist, cell_color, rows, cols, and file must
 * 		 have all initial information within them at this point
 * Post_condition:Makes the first grid and prints it to the screen containg the 
 * 		  configuration of the file. 
 * ************************************************************************/
char **grid(char *file, ANT &ant1, char &cell_color, int &rows, int &cols){
   
   ifstream config_file(file);
   config_file >> rows >> cols;
   char **array = new char*[rows];

   for(int i = 0; i < rows; i++){
      array[i] = new char[cols];
   }
   
   int color;//variable to store the reading from the file  
   for(int i = 0; i < rows; i++){
      for(int k = 0; k < cols; k++){
	config_file >> color;
	if ( color == 0){
	   array[i][k] = ' ';// space is 0 (white)
	}
	 else if( color  == 1){
	    array[i][k] = '*';// * is 1 (dark)
	 }
      }
   }

   //sets the the cell_color variable to "color"
   if(array[ant1.x_current][ant1.y_current] == ' ' ){
      cell_color = ' '; 
   }else if (array[ant1.x_current][ant1.y_current] == '*'){
      cell_color = '*';
   }

   // places the ant in the intial locaiton  
   array[ant1.x_current][ant1.y_current] = '#';
  
   //prints out the array 
   for(int i = 0; i < rows; i++){
      for(int k = 0; k < cols; k++){
	 cout << array[i][k];
	}
      cout << endl;
   }
   cout << endl;
   config_file.close();
   sleep(1);
  return array;
}

/***************************************************************************
 * Function:num_orientation() 
 * Description:This function converts the inital command line argument of the 
 *    	       orientation to a numerical equivalent. This way it is easier to 
 *    	       handle while running the program  
 * Parameters:ant object, orent variable
 * Pre-condition:ant must exist, variable must have a memory location
 * Post_condition:sets orientation to the correspoding integer equivalent 
 * ************************************************************************/
void num_orientation( ANT ant1, int &orent){
   if( strcmp( ant1.direction, "n") == 0){
      orent = 0;
   }else if(strcmp(ant1.direction,"e") == 0){
      orent = 1;
   }else if(strcmp(ant1.direction,"s") == 0){
      orent = 2;
   }else if ( strcmp(ant1.direction,"w") == 0){
      orent = 3;
   }
}


/***************************************************************************
 * Function:move()
 * Description:The most imporant function in regards to moving the ant around
 * 	       the grid.It makes sure that the color of the grid is how it is
 * 	       supposed to. It also moves the ant to the correct location.It
 * 	       will also verify that the ant is still within the grid perimeters
 * Parameters:cell_color, orienttation, array, ant object, rows, cols
 * Pre-condition:ant must be ready to move and orientation shoudl be in the new
 * 		 direction.
 * Post_condition:the ant will be moved to the next lacation
 * ************************************************************************/
void move( char &cell_color, int &orientation, char **array, ANT &ant1,int rows, int cols){
   if(cell_color == ' '){
     orientation++;
     array[ant1.x_current][ant1.y_current] = '*';// inverts the color of the cell for when the ant leaves
   }else if(cell_color == '*'){
      orientation --;
      array[ant1.x_current][ant1.y_current] = ' ';// inverts the color of the cell for when the ant leaves
   }

   //orientation can only be 0,1,2 and 3 checks for when it goes over or under
   if(orientation == -1){
      orientation = 3;
   }else if(orientation == 4){
      orientation = 0;
   }

   //these are the deltas in the x and y axis 
   int x_c = 0;
   int y_c = 0;

   xy_change( x_c, y_c, orientation);

   //checks to make sure the ant hasn't lef the screen 
   if((ant1.x_current + x_c) >= rows || (ant1.x_current + x_c) < 0){
     cout << "The ant left the grid. Program terminated." << endl; exit(1);
   }
   if((ant1.y_current + y_c) >= cols || (ant1.y_current + y_c) < 0){
     cout << "The ant left the grid. Program terminated." << endl; exit(1); 
   }
   cell_color = array[ant1.x_current + x_c][ant1.y_current + y_c];
   ant1.x_current += x_c;
   ant1.y_current += y_c;

   array[ant1.x_current][ant1.y_current] = '#';



}



/***************************************************************************
 * Function:xy_change()
 * Description:This function will make sure that the ant moves in the 1 unit 
 * 	       in the correct direction.
 * Parameters:x_change, y_change, orientation
 * Pre-condition:it must be called by the move() function 
 * Post_condition:sets the change in x and y for the ant to move 
 * ************************************************************************/
void xy_change( int &x_change, int &y_change, int orientation){
   if(orientation == 1){
      y_change++;
   }else if(orientation == 2){
      x_change++;
   }else if(orientation == 3){
      y_change--;
   }else if(orientation == 0){
      x_change--;
   }
}

/***************************************************************************
 * Function:grid_print() 
 * Description: prints the grid back to the user
 * Parameters: array, rows, cols
 * Pre-condition: the grid must be set up with the ant in the new location 
 * Post_condition:returns the grid to the screen 
 * ************************************************************************/
void grid_print(char ** array, int rows,int cols){

   for(int i = 0; i < rows; i++){
      for(int k = 0; k < cols; k++){
	 cout << array[i][k];
	}
      cout << endl;
   }
}

