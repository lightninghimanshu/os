#include <stdio.h>
#include <dirent.h>

int listdir(const char *path) 
{
  struct dirent *entry;
  DIR *dp;

  dp = opendir(path);
  if (dp == NULL) 
  {
    perror("opendir");
    return -1;
  }

  while((entry = readdir(dp)))
    printf("%c\n",entry->d_name[0]);
    // puts(entry->d_name[0]);

  closedir(dp);
  return 0;
}

int main(int argc, char **argv) {
  int counter = 1;

  if (argc == 1)
	listdir(".");

  while (++counter <= argc) {
    printf("\nListing %s...\n", argv[counter-1]);
    listdir(argv[counter-1]);
  }

  return 0;
}
