#include <dirent.h> 
#include <stdio.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void func (char *direc){
    pid_t pid=fork();
    
    if (pid==0) { /* child process */
        char *argv[]={"lsdir",direc,NULL};
        execv("lsdir",argv);
        exit(7); /* only if execv fails */
    }
    else { /* pid!=0; parent process */
        waitpid(pid,0,0); /* wait for child to exit */
    }
}

int main(void)
{
  DIR           *d;
  struct dirent *dir;
  struct stat buf;
  char *str;
  char folderName[255];
  int i=0;
  d = opendir(".");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {i++;

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
    if(i>2){
    if(strcmp(str,"directory")==0){
        strncpy(folderName, dir->d_name, 254);
        folderName[254] = '\0';
       printf("%s pasta pasta pasta \n",folderName);
        if(folderName!="."){
           printf("%s nome da pasta a entrar \n",folderName);
        func(folderName);}
    }
    }}

    closedir(d);
  }

  return(0);
}

