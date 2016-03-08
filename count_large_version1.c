#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_permission(char *org, char *cmp);
int check_argument(char *org);


int main(int argc, char *argv[])
{   
    /* Declare variables */
    char temp_hold[31];
    int i = 1;
    int j = 1;
    int check = 0;
    int num = 0;
    int cmp_filesize = 0;
    int filesize_check = 0;
    int permission_check = 0;
    int flag_filesize = 0;
    int total_check = 0;
    int argument_check = 0;
    char *directory = "d";
    
    /* If need to check filesize and permission case */
    if(argc == 3)
    {
       while(scanf("%s", temp_hold) != EOF)
       {
          if(i > 2)
          {
             if(j == 1)
             {  
                if(strncmp(temp_hold, directory, 1) != 0) /* Check is it Directory */
                {
                   check = check_permission(temp_hold+1, argv[2]);
                }
             }
             if(j == 5) /* Check filesize */
             {  
                cmp_filesize = atoi(argv[1]);
                num = atoi(temp_hold);
                if(num >= cmp_filesize)
                { 
                  flag_filesize = 1;
                }
             }
             if(j == 9)
             {
                j = 0;
             }
             j++;
             if((flag_filesize + check) ==  2) /* Final check both cases */
             {  
                total_check += 1;
             }
             flag_filesize = 0;
          }
          getchar();
          i++;
        }
        printf("%d\n", total_check);
    }
    
    if(argc == 2) /* If only need to check filesize or permission */
    {
       argument_check = check_argument(argv[1]); /* Check permission or filesize */
       if(argument_check == 1)  /* Only check permission */
       {
          while(scanf("%s", temp_hold) != EOF)
          {
             if(i > 2)
             {
                if(j == 1)
                {
                   if(strncmp(temp_hold, directory, 1) != 0)
                   {
                      check = check_permission(temp_hold+1, argv[1]);
                      if(check == 1)
                      {
                        permission_check += 1;
                      }
                   }
                   
                }
                if(j == 9)
                {
                   j = 0;
                }
                j++;
             }
             getchar();
             i++;
          } 
          printf("%d\n", permission_check);
       }
       else /* Only check filesize */
       {
          while(scanf("%s", temp_hold) != EOF)
          {
             if(i > 2)
             {
                if(j == 5)
                {
                   cmp_filesize = atoi(argv[1]);
                   num = atoi(temp_hold);
                   if(num >= cmp_filesize)
                   { 
                      filesize_check += 1;
                   }
                }
                if(j == 9)
                {
                   j = 0;
                }
                j++;
             }
             getchar();
             i++;
          }
          printf("%d\n", filesize_check);
       }

    }
    
    return 0;

}


int check_permission(char *org, char *cmp)
{
    int total = 0;
    int count = 0;
    char *delim = "-";
    int i = 0;
    char *current = cmp;
    for(i = 0; i < 9; i++)
    {
        if(strncmp(cmp+i, delim, 1) != 0)
        {
            total += 1;
        }
    }
    for(i = 0; i < 9; i++)
    {
        if(strncmp(current+i, delim, 1) != 0)
        {
            if(strncmp(current+i, org+i, 1) == 0)
            {
                count += 1;
            }
        }
    }

    if(total == count)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int check_argument(char *org)
{   
    /* Check Only 1 argument case, filesize or permission */
    char *read = "r";
    char *write = "w";
    char *execute = "x";
    char *minus = "-";
    int check = 0;

    if(strncmp(org, read, 1) == 0)
    {
       check += 1;
    }

    if(strncmp(org, write, 1) == 0)
    {
       check += 1;
    }

    if(strncmp(org, execute, 1) == 0)
    {
       check += 1;
    }

    if(strncmp(org, minus, 1) == 0)
    {
       check += 1;
    }

    if(check > 0)
    {
       return 1;
    }

    return 0;
}