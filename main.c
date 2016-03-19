/*
  writen by Isaac F.
  Contact info...

  This code has been created to solve sudokus
  The input for the program is a plain text file with sudoku matrix.

*/
//#define DEBUG

#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"
#include "sudoku_file_input.h"


int main(int arg,char **argv) {

  Field* f;
  Field* field;
  Field* toSearch;
  Head* opens = get_new_head();
  Head* closed = get_new_head();
  f = create_from_file("input_files/input_1.txt");
  search_solution(f); 

  return 0;
}