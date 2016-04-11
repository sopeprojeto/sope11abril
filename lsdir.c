#include <dirent.h> 
#include <stdio.h> 
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
  DIR           *d;
  struct dirent *dir;
  struct stat buf;
  char *str;
  printf("ENTROU LSDIR");
  d = opendir(argv[1]);
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {

printf("%s: is ", dir->d_name);

lstat(dir->d_name, &buf); 
if (S_ISREG(buf.st_mode)) str = "regular";
else if (S_ISDIR(buf.st_mode)) str = "directory";
else if (S_ISCHR(buf.st_mode)) str = "character special";
else if (S_ISBLK(buf.st_mode)) str = "block special";
else if (S_ISFIFO(buf.st_mode)) str = "fifo";
else if (S_ISLNK(buf.st_mode)) str = "symbolic link";
else if (S_ISSOCK(buf.st_mode)) str = "socket";
else str = "unknown";
printf("%s\n", str);

    }

    closedir(d);
  }

  return(0);
}