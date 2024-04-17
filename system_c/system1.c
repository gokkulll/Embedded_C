/*
*  Executing a shell command using system()
*/
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char* argv[]){
   system(argv[1]);
   printf("\nDone... Bye argv[1] : %s \n",argv[1]);
   exit(0);
}
