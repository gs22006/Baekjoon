#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <time.h>  
#include <math.h>  
  
long long int i, j;  
char a[110];  
long long int len;  
char b[110], cc;  
  
int main(void)  
{  
    scanf("%s", a);  
      
    len = strlen(a);  
      
    for(i = 0 ; i < len ; i++)  
    {  
        if('A' <= a[i] && a[i] <= 'Z')  
        {  
            printf("%c", a[i]);  
            continue;  
        }  
          
        if(a[i] == '(')  
        {  
            b[cc++] = a[i];  
            continue;  
        }  
          
        if(a[i] == '*' || a[i] == '/')  
        {  
            while(cc > 0)  
            {  
                if(b[cc - 1] == '*' || b[cc - 1] == '/')  
                {  
                    printf("%c", b[cc - 1]);  
                      
                    b[cc - 1] = 0;  
                    cc--;  
                }  
                  
                else  
                    break;  
            }  
              
            b[cc++] = a[i];  
        }  
          
        else if(a[i] == '+' || a[i] == '-')  
        {  
            while(cc > 0)  
            {  
                if(b[cc - 1] != '(')  
                {  
                    printf("%c", b[cc - 1]);  
                      
                    b[cc - 1] = 0;  
                    cc--;  
                }  
                  
                else  
                    break;  
            }  
              
            b[cc++] = a[i];  
        }  
          
        else  
        {  
            while(cc > 0)  
            {  
                if(b[cc - 1] == '(')  
                {  
                    b[cc - 1] = 0;  
                    cc--;  
                      
                    break;  
                }  
                  
                printf("%c", b[cc - 1]);  
                  
                b[cc - 1] = 0;  
                cc--;  
            }  
        }  
    }  
      
    while(cc > 0)  
    {  
        printf("%c", b[cc - 1]);  
        cc--;  
    }  
      
    return 0;  
}  