#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
void do_ls(char[]);
void dostat(char*filename);
int main(int argc,char*argv[])
{
    if(argc==1)
      do_ls(".");
    else 
    {
      while(--argc)
      {
        printf("%s:\n",*++argv);
        do_ls(*argv);
      }
    }
    return 0;
}
void do_ls(char dirname[])
{
  int i=0;
  DIR*dir_ptr;
  struct dirent*direntp;
  if((dir_ptr=opendir(dirname))==NULL)
    fprintf(stderr,"ls1:cannot open %s\n",dirname);
  else 
  {
    while((direntp=readdir(dir_ptr))!=NULL)
    {
      if(direntp->d_name[0]!='.')
      {
        struct stat info;
        if(stat(direntp->d_name,&info)==-1)
          perror(direntp->d_name);
        else 
        {
          printf("%d     %-22s",info.st_ino,direntp->d_name);
          i++;
          if(i==4)
          {
            printf("\n");
            i=0;
          }
        }
      }
    }
  }
  closedir(dir_ptr);
  printf("\n");

}


