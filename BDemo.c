#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BSTree.h"

tnode* readTree (char *s, int limit){
  /*for indexing into s */
  char *p = s;
  char c;

  FILE *employees;
  //opening the file input for reading
  employees = fopen ("input.txt","r") ;
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
  char str [50];


  char buf[100];
  tnode* root = btAlloc();
  btPrint (root, "Tree prior to reading the file:");
  while (gets_n(buf,100))
     root= btPut(root,buf);
  btPrint(root, "Tree after reading the file:");

  
  printf("\n\t\t\t MENU \n\n\n");
  printf("\t 1) Add Emloyee\n");
  printf("\t 2) Remove Employee\n");
  printf("\t 3) List all Employees\n");


  scanf("%d", &a);



  if(a == 1){
    printf("\t Enter Employee Name:\n");
    scanf("%[^\n]s", str);
    
  }
  else if (a==2){
  }

  else if (a==3){
  }

  else{
  }
    
  








 
 

  
  
  
 

  return 0;
  

}
