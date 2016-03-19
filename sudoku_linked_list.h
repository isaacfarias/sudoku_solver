//TODO create push, pop, insert_at
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include "sudoku_types.h"
#include "sudoku_field_operations.h"
#include "sudoku.h"

typedef struct NODE {
  Field* field;
  struct NODE* next;
} Node;

typedef struct HEAD {
  Node *first;
  int number_of_elements;
} Head;


int search_field(Head* h,Field* n);
bool is_empty(Head* h);
Head* get_new_head();
void insert_node (Head * h, Field *f);
void delete_node(Head* h, int idx);
void print_list(Head *h);
Field* pop(Head* h);
int search_field(Head* h,Field* n) {
  int idx;
  idx = 0;
  Node* aux = (*h).first;
  if (is_empty(h)) {
    return -1;
  }

  while ( idx<(*h).number_of_elements) {
    if ( is_the_same_field((*aux).field,n )) {
      return idx;
    }
    aux = (*aux).next;
    idx++;
  }
  return -1;
}

bool is_empty(Head* h) {
  if( (*h).number_of_elements == 0) {
    return TRUE;
  }
  return FALSE;
}

/*
  Returns *Head initialized or NULL
*/
Head* get_new_head() {
  Head * ret = (Head*) malloc(sizeof(Head));
  if(ret == NULL) {
    printf("[ERROR] can not get a new linked list head [malloc returns NULL]\n");
    return ret;
  }
  (*ret).number_of_elements = 0;
  (*ret).first = NULL;
  return ret;
}

void insert_node (Head * h, Field *f) {

  Node* aux = (*h).first;
  Field* f_copy;
  Node* node_to_insert = (Node*) malloc (sizeof(Node));

  if (node_to_insert == NULL) {
    printf("[ERROR] can not insert a new Node [malloc returns NULL]\n");
    return;
  }

  f_copy = copy_field(f);

  (*node_to_insert).field = f_copy;
  (*node_to_insert).next = NULL;

  if(aux == NULL) { 
    (*h).first = node_to_insert;
  } else {
    while((*aux).next != NULL) {
      aux = (*aux).next; 
    }
    (*aux).next = node_to_insert;
  }

   (*h).number_of_elements++;
   #ifdef DEBUG
    printf("[DEBUG] Inserting... list_head[%p], node[%p], number[%d]\n",h,node_to_insert,(*h).number_of_elements);
   #endif
}

void delete_node(Head* h, int idx) {
  int i;
  Node* aux;
  Node* toDelete;
  
  #ifdef DEBUG
  printf("[DEBUG] Deleting node[%d], list[%p]...\n",idx,h);
  #endif
  
  if(is_empty(h)) {
    #ifdef DEBUG
    printf("[DEBUG] Can't delete, list is empty.\n");
    #endif
    return;
  }

  if( idx >= (*h).number_of_elements ) {
    #ifdef DEBUG
    printf("[DEBUG] Can't delete, index to delete is greater than number of elements.\n");
    #endif
    return;
  }

  aux = (*h).first;

  if(idx == 0) {
    //For first element
    toDelete = (*h).first;
    (*h).first = (*aux).next;
  } else {
    //For others
    i = 0;
    while (i != idx-1) {
      i++;
      aux = (*aux).next;
    }
    toDelete = (*aux).next;
    (*aux).next = (*toDelete).next;
  }
  delete_field((*toDelete).field);
  #ifdef DEBUG
    printf("[DEBUG] Deleting node [%p]\n",toDelete);
  #endif
  free(toDelete);
  (*h).number_of_elements--;
}

Field* pop(Head* h) {
  Node* aux;
  Field* ret;
  int idx;
  if ( (*h).number_of_elements == 0) {
    return NULL;
  } else {
    aux = (*h).first;
    idx = 0;
     while((*aux).next != NULL ){
      aux = (*aux).next;
      idx++;
    }
    ret = copy_field((*aux).field);
    delete_node(h,idx);
    return ret;
  }
}

void print_list(Head *h) {
  int idx;
  Node* aux;
  
    printf("[DEBUG] Printing list[%p] with %d elements...\n",h,(*h).number_of_elements);
  
  aux = (*h).first;

  if( aux == NULL) {
    printf("List empty [%p]\n",h );
    return;
  }

  for (idx = 0;idx < (*h).number_of_elements; idx++) {
    printf("[%d]\n",idx);
    print_field((*aux).field);
    aux = (*aux).next;
  }
}

#endif