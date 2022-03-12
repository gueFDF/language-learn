#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#define MAX_LEN 150
int g_leavelen = MAX_LEN;
int g_maxlen;
void do_ls(char []);
int  main(int argc,char  *argv[])
{
  if(argc==1)
  {
    do_ls(".");  // .代表当前目录 
  }
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
  int len=0;
  DIR*dir_ptr;
  struct dirent*direntp;
  if((dir_ptr=opendir(dirname))==NULL)     //打开失败
  {
    fprintf(stderr,"lsl:cannot open %s\n",dirname);
  }
  else                                   //打开成功
  {
     while((direntp=readdir(dir_ptr))!=NULL)  //依次读取目录，找到最大长度
      {
        if(direntp->d_name[0]!='.')
         { 
            printf("%s  ",direntp->d_name);                                                                                                                          
         }
      }
    closedir(dir_ptr);
  }
}
