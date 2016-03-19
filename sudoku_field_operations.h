#ifndef _SUDOKU_FIELD_OPERATIONS_H_
#define _SUDOKU_FIELD_OPERATIONS_H_
/*
  file sudoku_field_operations.h
  This file contains fiend operations like: create, delete, compare etc.
*/
#include "sudoku_types.h"

/*
  Creates a new field empty (all initialized in NULL or 0's)
  INPUT:  None
  OUTPUT: None
  RETURN: Field* (This is the Pointer to the new created structure.)
*/
Field* new_field();

/*
  Deletes the given Field
  INPUT:  Field* (Fileld to delete, this can't be used before this call)
  OUTPUT: None
  RETURN: None
*/
void delete_field(Field* f);

/*
  This compare two fields and return TRUE if they are the same otherwise FALSE
  INPUT:  Field* f1 (First field to compare), Field* f2 (Second field to compare)
  OUTPUR: NONE
  RETURN: TRUE or FALSE
*/
bool is_the_same_field (Field* f1,Field* f2);

/*
  This creates a new Field with the same numbers in all cells but in diferent memory address.
  INPUT:  Field* (Field to be copied)
  OUTPUT: NONE
  RETURN: Field* (New field created with the same cell values as the input)

*/
Field* copy_field(Field* field_to_copy);

/*
  Check if the given Field is a solved Fiels
  RETURN: FALSE or TRUE
*/
bool is_solution(Field* f);

Field* new_field(){
  unsigned int tam;
  tam = BLOCK_SIZE*BLOCK_SIZE*BLOCKS*BLOCKS;
  Field* ret = (Field*) malloc(sizeof(Field));
#ifdef DEBUG
  printf("[DEBUG] new_field bytes required in malloc  %lu in address %p \n",(sizeof(CELL)),ret);
#endif
  int i;
  for(i = 0;i < tam;i++)
  {
    (*ret).line[i] = 0;
  }
  return ret;
}

void delete_field(Field* f) {
  #ifdef DEBUG
  printf("[DEBUG] Deleting field [%p] \n",f);
  #endif
  free (f);
}

bool is_the_same_field (Field* f1,Field* f2) {

  int idx;

  for (idx = 0; idx < BLOCK_SIZE*BLOCK_SIZE*BLOCKS*BLOCKS;idx++) {
    if ((*f1).line[idx] != (*f2).line[idx]) {
      return FALSE;
    }
  }
  return TRUE;
}

Field* copy_field(Field* field_to_copy) {
  Field* ret;
  int i;
  ret = (Field*) malloc(sizeof(Field));

  if(ret == NULL) {
    printf("[ERROR] Out of resources, malloc has failed (copy_field)\n");
    return ret;
  }

  for (i = 0; i < BLOCK_SIZE*BLOCK_SIZE*BLOCKS*BLOCKS; ++i)
  {
    /* code */
    (*ret).line[i] = (*field_to_copy).line[i];
  }
  #ifdef DEBUG
  printf("[DEBUG] copy_field succes\n");
  #endif
  return ret;
}

bool is_solution(Field* f) {
  int i;
  for (i = 0; i < BLOCKS*BLOCKS*BLOCK_SIZE*BLOCK_SIZE; ++i)
  {
    if( (*f).line[i] == 0) {
      return FALSE;
    }
  }
  return TRUE;
}

#endif