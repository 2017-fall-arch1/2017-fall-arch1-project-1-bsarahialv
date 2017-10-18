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
  tnode* root;
  if(b == NULL){
    if(b->left ==NULL && b->right==NULL){
      current= newNode(str);
      return current;
    }
  }
  else if (b != NULL){
    if(strcmp(str,b->str)<0){
      b->left = btPut (b->left, str);
    }
    else {
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
  printf("in node:%s\n", temp->str);
  printf("variable%s", str);
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
  //Remove
tnode* Search (tnode *root, char *employee){
    if(root == NULL){
      return root;
    }

    tnode *current = root;


    if(strcmp(employee, current->str)<0){
      current->left = Search(current->left,employee);
      }
      else if (strcmp(employee, current->str)>0){
	current->right = Search(current->right,employee);
      }
      else{
	if(current->left == NULL){
	  tnode *temp = current->right;
	  free(current);
	  return temp;

	}
	else if (current->right == NULL){
	  tnode *temp = current->left;
	  free(current);
	  return temp;
	}

	tnode *temp = current->right; 

	//tnode *temp = checkChildren (current->right);
	current->str = temp->str;
	current->right = Search(current->right, temp->str);
	
      }
    return current;

}

 tnode* checkChildren (tnode *current){
    tnode* temp = current;

    while(temp->left != NULL){
      temp =  temp->left;


    }
    return temp;


 }
