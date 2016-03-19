#ifndef _SUDOKU_PRINTF_
#define _SUDOKU_PRINTF_
#include "sudoku_types.h"

void print_bloques(Field *b) {
  int i,j,k,l;
  for(i = 0 ; i <BLOCKS; i++) {
    for (j= 0; j < BLOCKS ; j++) {
      for (k = 0;k<BLOCK_SIZE;k++) {
        for(l = 0;l<BLOCK_SIZE ; l++) {
          printf("%u ",(*b).bloque[i][k][j][l]);
        }
        printf("\n");
      }
    }
  }
}

void print_field(Field* f) {
  int i;
  unsigned int tam;
  tam = BLOCK_SIZE*BLOCK_SIZE*BLOCKS*BLOCKS;
#ifdef DEBUG
  //printf("[DEBUG] print_field tam calculated : %u \n",tam);
#endif
  for(i = 0; i < tam; i++) {
    if(i != 0  && i%9 == 0) {
      printf("\n");
    }
    if((*f).line[i] == 0) {
      printf("- ");
    } else { 
     printf("%u ",(*f).line[i]);
    }
  }
  printf("\n");
}

void print_panels(Field *f) {

  int i,j;
  for (i=0;i<BLOCK_SIZE*BLOCKS;i++) {
    for(j=0;j<BLOCKS*BLOCK_SIZE;j++) {
      printf("%u ",(*f).panel[i][j]);
    }
    printf("\n");
  }
}

#endif