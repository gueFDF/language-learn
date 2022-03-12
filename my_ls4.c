#include<string.h>
#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
#include<grp.h>
#include<pwd.h>
void do_ls(char[]);// -al
void do_ls1(char[]);// -l
void do_ls2(char[]);// -a
void do_ls3(char[]);// ls
void do_ls4(char[]);// ls
void dostat(char*);
void show_file_info(char*,struct stat*);
void mode_to_letters(int ,char[]);
char*uid_to_name(uid_t);
char*gid_to_name(gid_t);
void match(int argc,char*argv[]);
int has_a=0;
int has_l=0;
int has_al=0;
int main(int argc,char* argv[])
{
   match(argc,argv);
  if(argc==1)
  {
    do_ls2(".");
  }
  else 
  {
    while(--argc)
    {
      if(has_a==1&&has_l!=1)
      {
        do_ls3(".");
      }
      else if(has_a!=1&&has_l==1)
      {
        do_ls(".");
      }
      else if(has_al==1)
      {
        do_ls4(".");
      }
      else 
      {
         printf("%s:\n",*++argv);
         do_ls(*argv);
      }
  }
  return 0;
  }
}
void do_ls(char dirname[])
{
  DIR*dir_ptr;
  struct dirent*direntp;
  if((dir_ptr=opendir(dirname))==NULL)
    fprintf(stderr,"lsl:cannot open %s\n",dirname);
  else 
  { 
     while((direntp=readdir(dir_ptr))!=NULL)
     {
       if(direntp->d_name[0]!='.')
       dostat(direntp->d_name);
     }
    closedir(dir_ptr);
  }
}
 void do_ls4(char dirname[])
    {
      DIR*dir_ptr;
      struct dirent*direntp;
      if((dir_ptr=opendir(dirname))==NULL)
        fprintf(stderr,"lsl:cannot open %s\n",dirname);
      else 
      { 
         while((direntp=readdir(dir_ptr))!=NULL)
         {
           dostat(direntp->d_name);
         }
        closedir(dir_ptr);
      }
    }

void do_ls1(char dirname[])
    {                                                                                                                                                                                        
      DIR*dir_ptr;
      struct dirent*direntp;
      if((dir_ptr=opendir(dirname))==NULL)
        fprintf(stderr,"lsl:cannot open %s\n",dirname);
      else 
      { 
         while((direntp=readdir(dir_ptr))!=NULL)
         {
           dostat(direntp->d_name);
         }
        closedir(dir_ptr);
      }
    }
void do_ls2(char dirname[])
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
     while((direntp=readdir(dir_ptr))!=NULL)  
      {
        if(direntp->d_name[0]!='.')
         { 
            printf("%-22s",direntp->d_name);    
            i++;
            if(i==4)
            {
              printf("\n");
              i=0;
            }
         }
      }
     printf("\n");
    closedir(dir_ptr);
  }
}
void do_ls3(char dirname[])
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
     while((direntp=readdir(dir_ptr))!=NULL)
     {
             printf("%-22s",direntp->d_name);    
             i++;
             if(i==4)
             {
               printf("\n");
               i=0;
             }
     }
  printf("\n");
    closedir(dir_ptr);
  
  }
}
void dostat(char*filename)
{
  struct stat info;
  if(stat(filename,&info)==-1)
    perror(filename);
  else 
    show_file_info(filename,&info);
}
void show_file_info(char*filename,struct stat*info_p)
{
  char*uid_to_name(),*ctime(),*git_to_name(),*filemode();
  void mode_to_letters();
  char modestr[11];
  mode_to_letters(info_p->st_mode,modestr);
  printf("%s ",modestr);
  printf("%4d ",(int)info_p->st_nlink);
  printf("%-8s ",uid_to_name(info_p->st_uid));
  printf("%-8s ",gid_to_name(info_p->st_gid));
  printf("%8ld ",(long)info_p->st_size);
  printf("%.12s ",4+ctime(&info_p->st_size));
  printf("%s\n",filename);
}
void mode_to_letters(int mode,char str[])
{
  strcpy(str,"----------");
  if(S_ISDIR(mode))str[0]='d';
  if(S_ISCHR(mode))str[0]='c';
  if(S_ISBLK(mode))str[0]='b';
  if(mode&S_IRUSR)str[1]='r';
  if(mode&S_IWUSR)str[2]='w';
  if(mode&S_IXUSR)str[3]='x';

  if(mode&S_IRGRP)str[4]='r';
  if(mode&S_IWGRP)str[5]='w';
  if(mode&S_IXGRP)str[6]='x';

  if(mode&S_IROTH)str[7]='r';
  if(mode&S_IWOTH)str[8]='w';
  if(mode&S_IXOTH)str[9]='x';
}
char*uid_to_name(gid_t uid)
{
  struct passwd*getpwuid();
  struct passwd*pw_ptr;
  static char numstr[10];
  if((pw_ptr=getpwuid(uid))==NULL)
  {
    sprintf(numstr,"%d",uid);
    return numstr;
  }
  else 
  {
    return pw_ptr->pw_name;
  }
}
char*gid_to_name(gid_t gid)
{
  struct group*getgrgid(),*grp_ptr;
  static char numstr[10];
  if((grp_ptr=getgrgid(gid))==NULL)
  {
    sprintf(numstr,"%d",gid);
    return numstr;
  }
  else 
  {
    return grp_ptr->gr_name;
  }
}
void match(int argc,char*argv[])
{
  int i=1;
  for(i=1;i<argc;i++)
  {
    if(strcmp(argv[i],"-a")==0)
      has_a=1;
    if(strcmp(argv[i],"-l")==0)
      has_l=1;
    if(strcmp(argv[i],"-al")==0||strcmp(argv[i],"-la")==0||(has_a==1&&has_l==1))
     has_al=1; 
  }
}
