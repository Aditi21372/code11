#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<dirent.h>
#include<time.h>

char ca(char a[],char b[],int s_z,int num12)    {
    if(num12==1)
    {
          int i;
         for(i=0;i<s_z;i++){
            if(a[i]!=b[i])
                  return 1;
         }
         if(a[s_z+1]==b[s_z+1])
            return 0;
         else
            return 1;
         return 0;

    }
    else
    {
       int i;
         for(i=0;i<s_z+1;i++){
            if(a[i]!=b[i])
                  return 1;
         }
    }
    return 0;
   
}
// void make_empty( int rows, int cols)
//     {
//      int i,j;
//      for(i = 0; i <rows; i++)
//      {
//        for(j=0; j<cols;j++)
//        {
//           arg_array[i][j] = '\0';
//        }
//      }
//     return;
//     }
void currentdir()
{
   char b[1024];
   if (getcwd(b, sizeof(b)) == NULL)
      perror("error");
   else
      printf("%s\n",b);
}
void ls()
{  
   char b[1024];
    getcwd(b, sizeof(b));
   struct dirent *dp;
   DIR *dir = opendir(b);
   
   while ((dp = readdir(dir)) != NULL)
   {
      if (dp->d_name[0] != '.')
         {printf("%s  ", dp->d_name);}
   }
   printf("\n");

}
void ls2()
{  
    char b[1024];
    getcwd(b, sizeof(b));
   struct dirent *dp;
   DIR *dir = opendir(b);
   
   while ((dp = readdir(dir)) != NULL)
   {
   
         printf("%s  ", dp->d_name);
   }
   printf("\n");

}
char cal(char a[],char b[],int s_z)    {
    int i=0;

   while(i<s_z)
   {
      if(a[i]!=b[i])
      {
         return 1;
      }
      i++;
   }
   
   
   return 0;
}

void main()
{
   
   int rd = 0;

   printf("-----------------------------------Welcome to custom Linux Shell----------------------------------\n");
   do{
      char raw[4096];
      char input[200][200]; 
      char commands[200][200]={"echo","ls","pwd","cd","exit","cat","date","rm","mkdir","-a","-m","-R","-u","~","..","*","-help"};
      char b[1024];
      if (getcwd(b, sizeof(b)) == NULL)
         perror("error");
      else
         printf("%s-> ",b);
      int j = 0;
      int wor = 0;
      int flag=0;
      int it=0;
      int limit =0;
     
    //   scanf("%[^\n]s", raw);
      fgets(raw, sizeof raw, stdin);
      
      while(raw[it]==' ')
      { 
        it++;

      }
      for(int i =it;i<=(strlen(raw));i++)
      {
         // if space or NULL found, assign NULL into input[wor]
         if(raw[i]=='\0'||raw[i]==' ')
         {
            input[wor][j]='\0';
            wor=wor+1;  //for next word
            j=0;    //for next word, init index to 0
         }
         else
         {
            input[wor][j]=raw[i];
            j=j+1;
         }
      }
      limit = wor;
      int i=0;
      int num12=0;
      while(raw[i]!='\0')
      {
         if(raw[i]==' ')
         {
            num12++;
         }
         i++;
      }
      num12++;
      
      if(ca(input[0],commands[0],4,num12)==0)
      {
         
         
         int i = 0;
         int t=0;
         do
         {
            i=i+1;
         }while(input[i][0]=='\0');

         if(cal(input[i],commands[15],1)==0)
         {
            ls();
         }
         if(cal(input[i],commands[16],1)==0)
         {
            printf("help\n");
            printf("echo - print the string\n");
            printf("ech*-ls - list the files in the current directory\n");
         }
         else{
         t=i;
      
            printf("\n");
            printf("->");
            
            for(t=i;t<wor;t++)
            {
               
               if (input[t][0]!='\0')
               {  
                  printf(" %s",input[t]);
                 
                  
               }
               
               else
               {
                  
                  continue;
               }
               
            }
            printf("\n");
         printf("\n");
         }
         
         memset(input, 0, sizeof(input));
         memset(raw, 0, sizeof raw); 
      }
      
      else if(ca(input[0],commands[2],3,num12)==0)
      {
         
         currentdir();
         memset(input, 0, sizeof(input));
         memset(raw, 0, sizeof raw); 
      }
      else if(ca(input[0],commands[3],2,num12)==0)
      {
         printf("cd");
         char compareArraycd(char a[],char b[],int s_z)    
            {
               int i=0;

               while(i<s_z)
               {
                  if(a[i]!=b[i])
                  {
                     return 1;
                  }
                  i++;
               }
               
               
               return 0;
            }
               int i =1;
               while(input[i][0]=='\0')
               {
                  i++;
               }
             
         if(num12==1 || compareArraycd(input[i],commands[14],2)==0)
         {
            chdir("..");
         }
         else if(compareArraycd(input[i],commands[13],1)==0)
         {
            chdir("/home");
         }
         else{
            printf("Invalid");
         }
         memset(input, 0, sizeof(input));
         memset(raw, 0, sizeof raw); 
      }
      else if(ca(input[0],commands[4],4,num12)==0)
      {
         
         rd=1;
         memset(input, 0, sizeof(input));
         memset(raw, 0, sizeof raw); 

      }
      else if(ca(input[0],commands[1],2,num12)==0)
      {  
         
         int i =1;
         while(input[i][0]=='\0')
         {
            i++;
         }
         if(num12==1)
         {

            
            printf("  ls\n");
            ls();
            
            
            
         }
         
         if(num12==2)
         {
            if(cal(input[i],commands[9],2)==0)
            {
               printf("  ls -a\n");
               ls2();
            }
            else
            {
               ls();
            }
           
         }
      
         // {
         //    int t = 0;
         //    int i = 1;
         //    while(t==0)
         //    {
         //       if(input[i][0]=='\0')
         //       {
         //          i++;
         //       }
         //       else
         //       {
         //          t=1;
         //       }
         //    }
         //    if(input[i])
         //    printf("  ls\n");
         
         //    struct dirent *dp;
         //    DIR *dir = opendir(path);
            
         //    while ((dp = readdir(dir)) != NULL)
         //    {
               
         //          printf("%s  ", dp->d_name);
         //    }
         //    printf("\n");

         // }
         else if(num12!=2&&num12!=1){
            printf("  Pass valid arguements\n");
         }
         // else if(num12>1)
         // {
         //    struct dirent *dp;
         //    DIR *dir = opendir(path);
            
         //    while ((dp = readdir(dir)) != NULL)
         //    {
         //       if (dp->d_name[0] != '.')
                  
         //          for(int i =0;i<strlen(dp->d_name);i++)
         //          {
         //             name[i]=dp->d_name[i];
                    
         //          }
         //    }
         //    // for(int i =0;i<strlen(dp->d_name);i++)
         //    // {
         //    //    printf("%c ",name[i]);
         //    //    j++;
         //    // }
         //    int a =0;
         //    int j=0;
         //    for(int i =it;i<=(strlen(dp->d_name));i++)
         //    {
         //       // if space or NULL found, assign NULL into input[wor]
         //       if(dp->d_name[i]==' '||dp->d_name[i]=='\0')
         //       {
         //          name[a][j]='\0';
         //          a++;  //for next word
         //          j=0;    //for next word, init index to 0
         //       }
         //       else
         //       {
         //          name[a][j]=dp->d_name[i];
         //          j++;
         //       }
         //    }
         //    for(int i =0;i<a;i++)
         //    {
         //       printf("%s ",name[i]);
               
         //    }
         // }
         memset(input, 0, sizeof(input));
         memset(raw, 0, sizeof raw); 
      }
      else if(ca(input[0],commands[5],3,num12)==0)
      {
         printf("  cat\n");
         memset(input, 0, sizeof(input));
         memset(raw, 0, sizeof raw); 
      }
      else if(ca(input[0],commands[8],5,num12)==0)
      {
         printf("  mkdir\n");
         memset(input, 0, sizeof(input));
         memset(raw, 0, sizeof raw); 
      }
      else if(ca(input[0],commands[6],4,num12)==0)
      {
          printf("  date\n");
          char compareArraydate(char a[],char b[],int s_z)    
            {
               int i=0;

               while(i<s_z)
               {
                  if(a[i]!=b[i])
                  {
                     return 1;
                  }
                  i++;
               }
               
               
               return 0;
            }
               int i =1;
               while(input[i][0]=='\0')
               {
                  i++;
               }
            time_t currenttime;
            currenttime = time(NULL);
            struct tm *timeinfo;
            timeinfo = localtime(&currenttime);
            struct timeval tv;
            char timebuffer[64];
            gettimeofday(&tv, NULL);
            currenttime = tv.tv_sec;
            if(num12<2){
            timeinfo=localtime(&currenttime);
            strftime (timebuffer, sizeof timebuffer,"%a %d %b %H:%M:%S %p IST ", timeinfo);
            printf("%s", timebuffer);}
            
            else if(compareArraydate(input[i],commands[11],2)==0)
            {timeinfo=localtime(&currenttime);
            strftime (timebuffer, sizeof timebuffer,"%a, %d %b %Y %H:%M:%S %p +0530 ", timeinfo);
            printf("%s", timebuffer);
            }
            else if(compareArraydate(input[i],commands[12],2)==0)
            {
               timeinfo = gmtime(&currenttime);
            strftime (timebuffer, sizeof timebuffer,"%a %d %b %Y %H:%M:%S %p UTC ", timeinfo);
            printf("%s", timebuffer);

            }
         memset(input, 0, sizeof(input));
         memset(raw, 0, sizeof raw); 
      }
      else if(ca(input[0],commands[7],2,num12)==0)
      {
         printf("  rm\n");
         memset(input, 0, sizeof(input));
         memset(raw, 0, sizeof raw); 
      }
      else
      {
         printf("Invalid command");
         memset(input, 0, sizeof(input));
         memset(raw, 0, sizeof raw); 
      }
      
      
   }while (rd == 0);

}