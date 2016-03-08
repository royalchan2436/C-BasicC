#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int check_permission(char *org, char *cmp);
int check_argument(char *org);

int main(int argc, char **argv)
{
	char temp_hold[20];
	int num;
	int condition = 0;
	int permission_check = 0;
	int filesize_check = 0;
	scanf("%*s %*d");
	if(argc == 3)
	{
		while(scanf("%s %*s %*s %*s %d %*s %*s %*s %*s\n",temp_hold, &num) != EOF)
	    {
			if(temp_hold[0] != 'd')
			{
				if(num >= atoi(argv[1]))
				{
					filesize_check = 1;
				}
                
                if((filesize_check + check_permission(temp_hold+1, argv[2])) == 2)
                {
                	permission_check++;
                }
                filesize_check = 0;
			}

	    }
	    printf("%d\n", permission_check);
	}

	if(argc == 2)
	{
		condition = check_argument(argv[1]);
		if(condition == 1)
		{
			while(scanf("%s %*s %*s %*s %d %*s %*s %*s %*s\n",temp_hold, &num) != EOF)
			{
				if(temp_hold[0] != 'd')
				{
					if(check_permission(temp_hold+1, argv[1]) == 1)
					{
						permission_check++;
					}
				}
			}
			printf("%d\n", permission_check);
		}
		else
		{
			while(scanf("%s %*s %*s %*s %d %*s %*s %*s %*s\n",temp_hold, &num) != EOF)
			{
				if(num >= atoi(argv[1]))
				{
					filesize_check++;
				}
			}
			printf("%d\n", filesize_check);
		}
	}

	return 0;
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
