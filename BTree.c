#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BSTree.h"

/* create a new list */

tnode *btAlloc();
{
  tnode *b = (tnode*) malloc (size of(tnode));
  b-> leftt = b -> right = 0;
  return b;
}

/* discarding all items it contains*/
void btFree(tnode *b){
  btMMakeEmpty(b);
  free(b);
}

/*delete all items from the tree*/
void btMakeEmpty(tnode *b){
  tnode *current = b-> ,*next;
  while(current){
    next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
  b =0 ;
}

/* append a copy of str to end of list */
tnode* btPut (tnode *b, char *s){
 if(tnode == NULL){
   
   tnode = newNode(s);
  }
  else if (newNode != NULL){
    if(strcmp(s,tnode->s)<0){
      tnode->left = btPut (tnode->left, s);
    }
    else if (strcmp(s,tnode->s)>0){
      tnode->right = btPut (tnode->right,s):
    }
  }
 return tnode;
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


tnode* newNode (char *s){
  tnode *temp;
  temp = (tnode*) malloc (sizeof(tnode));
  temp->s= malloc(sizeof(tnode));
  temp->s =s;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}


btPrint(tnode *b, int depth){
  tnode *temp = b;
  if(b == NULL){
    padding('',depth);
    printf("-\n");
  }
  else{
    btPrint(current->left, depth+1);
    padding('',depth);
    printf("%s\n", b->);
  }


}

