#ifndef _SUDOKU_
#define _SUDOKU_

#include <stdio.h>
#include "sudoku_types.h"
#include "sudoku_valid_moves.h"
#include "sudoku_printf.h"
#include "sudoku_field_operations.h"
#include "sudoku_linked_list.h"


/*
  Add in to opens those fields that are neighbors of the first not valid value (0) in the field
  INPUT:
  OUTPUT:
  RETURN:
*/
void create_neighbors (Head* opens,Head* closed,Field* f);

void search_solution(Field* initial_field) {

  Head* open = get_new_head();
  Head* closed= get_new_head();
  bool done = FALSE;

  Field* auxF = copy_field(initial_field);
  insert_node(open,auxF);

  while(!done) {
    auxF = pop(open);
    /* TODELETE
        printf("Closed\n");
        print_list(closed);
        printf("Open\n");
        print_list(open);
*/
    if (auxF != NULL) {
      print_field(auxF);
      printf("------------------\n");
      if (is_solution(auxF)) {
        done = TRUE;
        printf("Original...\n");
        print_field(initial_field);
        printf("Solved!!!\n");
        print_field(auxF);
      } else {
        insert_node(closed,auxF);
        create_neighbors(open,closed,auxF);
      }
      
    } else {
      printf("Pop returns NULL, opens empty\n");
      done = TRUE;
    }

  }
}

void create_neighbors (Head* opens,Head* closed,Field* f) {
  //vars
  Field* auxF;
  int index;
  int num_to_place;
  int i;
  bool dene;
#ifdef DEBUG
  printf("Creating neigbors for:\n");
  print_field(f);
#endif
  // find first cell that has 0 as value (empty)
  for (i = 0; i < BLOCK_SIZE*BLOCK_SIZE*BLOCKS*BLOCKS; i++) {
    if((*f).line[i] != 0) {
      continue;
    }
#ifdef DEBUG
    printf("neighbors...\n");
#endif
    //For each cell, try to put one digit from 1 to 9.

    for (num_to_place = 1; num_to_place <= 9; num_to_place++) {

      if (valid_move(f,i,num_to_place)) {
        
        auxF = copy_field(f);
        (*auxF).line[i] = num_to_place;

        if(search_field(closed,auxF) < 0) {
          insert_node(opens,auxF);
#ifdef DEBUG
          print_field(auxF);
#endif
        } else {
          //release auxF memory
          delete_field(auxF);
        }

      }
    }
    break;
  }
#ifdef DEBUG
  printf("neighbors DONE...\n");
#endif
  //TODO create this function but not sure if is going to work well, need to think again if
  // I  am using all permutations, not only minimal
}


/*

Create a new field from scratch

*/







#endif// _SUDOKU_