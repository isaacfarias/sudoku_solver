//sudoku_validate_movements
#ifndef _VALID_MOVES_
#define _VALID_MOVES_

#include "sudoku_types.h"

/*
  validates if a movement is valid for the specific row and column from
  block perspective
*/
bool valid_block(Field* f,int row, int column, CELL value_to_place) {
  int block_row,block_column,i,j;

  block_row = row/BLOCK_SIZE;
  block_column = column/BLOCK_SIZE;

  #ifdef DEBUG
  printf("[DEBUG] validatig block at %d,%d  to place: %hu\n",row,column,value_to_place);
  #endif

  for(i = 0; i < BLOCK_SIZE;i++) {
    for(j=0;j< BLOCK_SIZE;j++) {
      #ifdef DEBUG
      printf("%hu ",(*f).bloque[block_row][i][block_column][j]);
      #endif
      if((*f).bloque[block_row][i][block_column][j] == value_to_place) {
        #ifdef DEBUG
        printf("[DEBUG] Returning FALSE\n");
        #endif
        return FALSE;
      }
    }
    #ifdef DEBUG
    printf("\n");
    #endif
  }
  #ifdef DEBUG
  printf("[DEBUG] Returning TRUE\n");
  #endif
  return TRUE;
}

bool valid_column(Field* f,int col_number,CELL value_to_place) {
  int i,offset;

  #ifdef DEBUG
  printf("[DEBUG] validatig column number: %d, to place: %hu\n",col_number,value_to_place);
  #endif

  for(i = 0; i < BLOCKS*BLOCK_SIZE;i++) {
    #ifdef DEBUG
    printf("%hu\n",(*f).line[ (i*(BLOCK_SIZE*BLOCKS-1)+i)+col_number]);
    #endif
    if((*f).line[ (i*(BLOCK_SIZE*BLOCKS-1)+i)+col_number]== value_to_place) {
      #ifdef DEBUG
      printf("\n[DEBUG] valid_column returning FALSE\n");
      #endif
      return FALSE;
    }
  }

  #ifdef DEBUG
  printf("\n[DEBUG] valid_column returning TRUE\n");
  #endif
  return TRUE;
}

bool valid_row(Field* f,int row_number,CELL value_to_place) {

  int i,offset;
  offset = (row_number*(BLOCKS*BLOCK_SIZE-1)) + row_number;
  #ifdef DEBUG
  printf("[DEBUG] validatig row number: %d, to place: %hu\n",row_number,value_to_place);
  #endif

  for(i = 0; i < BLOCK_SIZE*BLOCKS; i++) {
    #ifdef DEBUG
    printf("%hu ",(*f).line[i+offset]);
    #endif
    if ((*f).line[i+offset] == value_to_place) {
      #ifdef DEBUG
      printf("\n[DEBUG] valid_row returning FALSE\n");
      #endif
      return FALSE;
    }
  }
  #ifdef DEBUG
  printf("\n[DEBUG] valid_row returning TRUE\n");
  #endif
  return TRUE;

}

int get_column_from_line(int line_offset) {
  return line_offset%9;
}

int get_row_from_line(int line_offset) {
  return line_offset/9;
}

bool valid_move(Field* f,int line_index, CELL value_to_place) {
  return valid_row(f,get_row_from_line(line_index),value_to_place) && 
         valid_column(f,get_column_from_line(line_index),value_to_place) && 
         valid_block(f,get_row_from_line(line_index),get_column_from_line(line_index),value_to_place);
}


#endif