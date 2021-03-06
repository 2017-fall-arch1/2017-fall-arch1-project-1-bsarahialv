#ifndef BTree_included
#define BTree_included

//define the structure of the nodes
typedef struct tnode {
  char *str;
  struct tnode *left;
  struct tnode *right;

 
} tnode;


//Functions

/*create a new node*/
  tnode *btAlloc();

/* free memory associated with a node*/
//void btFree(tnode *b);

/*append a copy of str to end of list*/
void btPut(char *s);

tnode* newNode (char *s);

/*Delete all elements off the tree*/
//void btMakeEmpty (tnode *b);

/* print */
  void btPrint (tnode *b, int depth);

void bPrintPreorder (tnode *b);
/*check consistency, always returns zero*/
//int btCheck(tnode *b);

tnode* checkChildren (tnode *current);

tnode* Seacrh (tnode *root, char *employee);

#endif /*included*/
