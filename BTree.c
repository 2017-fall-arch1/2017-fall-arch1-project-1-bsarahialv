#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BTree.h"

/* create a new list */

tnode *btAlloc(){
  tnode *b = (tnode*) malloc (sizeof(tnode));
  b-> left = b -> right = 0;
  return b;
}

/* discarding all items it contains*/
/*void btFree(tnode *b){
  btMakeEmpty(b);
  free(b);
  }*/

/*delete all items from the tree*/
/*void btMakeEmpty(tnode *b){
  tnode *current = b-> *next;
  while(current){
    next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
  b =0 ;
  }*/

/* append a copy of str to end of list */
tnode* btPut (tnode *b, char *str){
 if(b == NULL){
   
   b = newNode(str);
  }
  else if (b != NULL){
    if(strcmp(str,b->str)<0){
      b->left = btPut (b->left, str);
    }
    else if (strcmp(str,b->str)>0){
      b->right = btPut (b->right,str);
    }
  }
 return b;
}

/*int len;
  char *scopy;
  tnode *i;

  for(len=0; s[len];len++)
    ;
  scopy = (char *)malloc(len+1);
  for(len=0; s[len];len++)
    scopy[len] = s[len];
  scopy[len] = 0;

  i = (tnode*) malloc(sizeof(tnode));
  i-> str = scopy;
  i->next = 0;

  }*/


tnode* newNode (char *str){
  tnode *temp;
  temp = (tnode*) malloc (sizeof(tnode));
  temp->str= malloc(sizeof(tnode));
  temp->str =str;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

void padding (char ch, int n){
  int i;
  for(i=0; i<n;i++){
    printf("%c%c%c%c", ch, ch, ch, ch);

  }
}
void btPrint(tnode *b, int depth){
  tnode *temp = b;
  if(b == NULL){
    padding('c',depth);
    printf("-\n");
  }
  else{
         btPrint(temp->left, depth+1);
    padding('c',depth);
    printf("%s\n", b->str);
    btPrint(temp->right,depth+1);
  }


}

void bPrintPreorder (tnode *b){
  if( b!=NULL){
    printf ("%s\n", b->str);
    bPrintPreorder (b->left);
    bPrintPreorder (b->right);
  }



}
