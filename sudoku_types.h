#ifndef _SUDOKU_TYPES_
#define _SUDOKU_TYPES_

#define BLOCK_SIZE 3
#define BLOCKS 3
#define TRUE 1
#define FALSE 0

typedef unsigned short int CELL;
typedef int bool;

typedef union FIELD {
  CELL line[BLOCKS*BLOCKS*BLOCK_SIZE*BLOCK_SIZE];
  CELL panel[BLOCK_SIZE*BLOCKS][BLOCK_SIZE*BLOCKS];
  CELL bloque[BLOCKS][BLOCKS][BLOCK_SIZE][BLOCK_SIZE];
} Field;

#endif