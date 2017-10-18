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
  char employeeRemove[50];
  
  tnode* root = NULL;
  
  printf("\n\t\t\t MENU \n\n\n");
  printf("\t 1) Add Emloyee\n");
  printf("\t 2) Remove Employee\n");
  printf("\t 3) List all Employees\n");


  scanf("%d", &a);
  int num;
  tnode *current;
  if(a == 1){
    printf("\t How many employees do you want to enter\n");
    scanf("%d", &num);
    
    while(num != 0){
      printf("\t Enter Employee Name:\n");
      scanf("%s", string); 
      root = btPut(root,string);
      num -= 1;
    }
    

    // printf("\t Root: \n");
    // printf("%s\n", root->str);
   
    // int depth = 0;
    // btPrint(root,depth);
    bPrintPreorder (root);
  }
  else if (a==2){
    

    printf("\t Enter the name of the employee you want to delete\n");
    scanf("%s", employeeRemove);
    Search(root, employeeRemove);
  }

  else if (a==3){
  }

  else{
  }
    

  return 0;
  

}
