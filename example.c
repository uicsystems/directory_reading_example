/* -----------------------------------------------
   CS 361 - C reading contents of Directory Example

   Program reads in contents of a directory and prints
   out contents to std out. Pass directory as argument
   to this program. Example:
      Terminal Input:
        "./example test_dir"

      Terminal Output:
        Contents of test_dir are:
        .
        ..
        test1.c
        test2.txt
        sub_dir
  ------------------------------------------------
*/
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define PATH_ARG 1
#define DIRECTORY_LISTING_MAX_CHAR 1013 // can get overflow if have a large directory and not enough characters

/*
*
* Note: Returns raw pointer to malloc'ed space. User is responsible
* for freeing up this pointer after its use
*
*/
char* get_directory_contents(char* directory_path)
{
  char* directory_listing = NULL;
  
  // open directory path up 
  DIR* path = opendir(directory_path);

  // check to see if opening up directory was successful
  if(path != NULL)
  {
      directory_listing = (char*) malloc(sizeof(char)*DIRECTORY_LISTING_MAX_CHAR);
      directory_listing[0] = '\0';

      // stores underlying info of files and sub_directories of directory_path
      struct dirent* underlying_file = NULL;

      // iterate through all of the  underlying files of directory_path
      while((underlying_file = readdir(path)) != NULL)
      {
          strcat(directory_listing, underlying_file->d_name);
          strcat(directory_listing, "\n");
      }
      
      closedir(path);
  }

  return directory_listing;
}


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
    fprintf(stderr, "Arguments to Program not correct. Exiting.\n");
    exit(-1);
  }

  //check if file exists
  struct stat file_stat;
  if (stat(argv[PATH_ARG], &file_stat) != 0) {
    printf("%s does not exist!  Program exiting\n", argv[PATH_ARG]);
    exit(-1);
  }


  //check if file is a directory
  if (S_ISDIR(file_stat.st_mode)) {
    printf("%s is a directory\n", argv[PATH_ARG]);
  } else {
    printf("%s is NOT a directory!  Program exiting\n", argv[PATH_ARG]);
    exit(-1);
  }

  // read in contents and check for read in errors
  char* directory_contents_str = get_directory_contents(argv[PATH_ARG]); 
  if(directory_contents_str != NULL)
  {
    printf("Contents of %s are:\n", argv[PATH_ARG]);
    printf("%s\n", directory_contents_str); 
  }
  else
  {
    fprintf(stderr, "Error reading contents of %s\n", argv[PATH_ARG]);
    exit(-2);
  }

  return 0;
}
