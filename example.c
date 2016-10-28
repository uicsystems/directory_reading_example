/* -----------------------------------------------
   CS 361 - C reading contents of Directory Example

   Program reads in contents of a directory and prints
   out contents to std out. Pass directory as argument
   to this program. Output looks like:

      * Fill this in *


  ------------------------------------------------
*/
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>





/*
* Program requires one argument
*  1) the directory to print out its contents
*
*/
int main(int argc, char** argv)
{

  //Check for enough arguments
  if(argc != 2)
  {
    perror("Arguments to Program not correct. Exiting.\n");
    exit(-1);
  }


  return 0;
}
