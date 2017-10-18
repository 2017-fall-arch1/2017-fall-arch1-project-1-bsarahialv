#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BTree.h"

tnode* readTree (char *s, int limit){
  /*for indexing into s */
  char *p = s;
  char c;

  FILE *employees;
  //opening the file input for reading
  employees = fopen ("input.txt","r") ; //read
  if (employees == NULL){
    printf("Can't open the file\n");
    exit(1);

  }

  if(fgets(s,limit,employees)){

    while((c=*p) && c!= '\n')

      p++;
    if(c=='\n')
      *p = 0;
  }
  return (p-s);
}



int main (char *s, int limit){

  int a;
  char string[50];


  // char buf[100];
  //tnode *root = btAlloc();
  // btPrint (root, "Tree prior to reading the file:");
  //  root = btPut (root, str);
  //btPrint(root,0);

  // while (gets_n(buf,100))
  // root= btPut(root,buf);
  // btPrint(root, "Tree after reading the file:");
  tnode* root = NULL;
  
  printf("\n\t\t\t MENU \n\n\n");
  printf("\t 1) Add Emloyee\n");
  printf("\t 2) Remove Employee\n");
  printf("\t 3) List all Employees\n");


  scanf("%d", &a);
  int num;
  if(a == 1){
    printf("\t How many employees do you want to enter\n");
    
    scanf("%d", &num);
    // printf("num is \n", num);
    while(num != 0){
      printf("\t Enter Employee Name:\n");
      scanf("%s", string); //check if includes 0
      // printf("str1 is: %s \n", string);
      root = btPut(root,string);
      num -= 1;

    }
   
    // int depth = 0;
    // btPrint(root,depth);
    bPrintPreorder (root);
  }
  else if (a==2){
  }

  else if (a==3){
  }

  else{
  }
    

  return 0;
  

}
