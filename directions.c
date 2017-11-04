#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
int get_da_size(char* p){
  DIR *d = opendir(p);
  struct dirent* entry;
  entry = readdir(d);
  int returnval= 0;
  while(entry){
    if(entry-> d_type ==DT_REG){
      struct stat buffer;
      stat(entry -> d_name, &buffer);
      size_t s = buffer.st_size;
      returnval+=s;
    }
    entry = readdir(d);
  }
  return returnval;
}
    
int main(){
  DIR *d = opendir(".");
  struct dirent *f;
  struct stat buffer;
  printf("\nStatistics for directory:\n");
  printf("\nTotal directory size: %d", get_da_size(".")) ;
  printf("\nDirectories:\n");
  d = opendir(".");
  while(f = readdir(d)){
    if(f->d_type ==DT_DIR){
      printf("%s\n", f->d_name);
    }
  }
  d=opendir(".");
  printf("\nFiles:\n");
  while(f=readdir(d)){
    if(f->d_type ==DT_REG){
      stat(f ->d_name, &buffer);
      printf("%s\n", f->d_name);
    }
  }
  closedir(d);
  return 0;
}
  
 

  
	 
	 
    
