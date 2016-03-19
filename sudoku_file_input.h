#ifndef _file_input_
#define _file_input_

#include "sudoku.h"

Field* create_from_file(char* file) {
  FILE* fi;
  Field* field;
  int index;
  int offset;
  unsigned short aux[9];


  fi = fopen(file,"r+");
  if (fi == NULL) {
    printf("[ERROR] fopen returns NULL\n");
    return NULL;
  }

  field = new_field();
  if (field == NULL) {
    printf("[ERROR] new_field returns NULL \n");
  }

  #ifdef DEBUG
  printf("[DEBUG] Creating field from file: %s\n",file);
  #endif
  for (index = 0; index <BLOCK_SIZE*BLOCKS;index ++) {
    fscanf(fi,"%hu %hu %hu %hu %hu %hu %hu %hu %hu",
          &aux[0],
          &aux[1],
          &aux[2],
          &aux[3],
          &aux[4],
          &aux[5],
          &aux[6],
          &aux[7],
          &aux[8]);
    #ifdef DEBUG
    //printf("%hu,",aux );
    #endif
    for(offset = 0; offset < BLOCK_SIZE*BLOCKS; offset++) {
      (*field).line[index*9+offset] = aux[offset];
    }
  }
  return field;
}
#endif