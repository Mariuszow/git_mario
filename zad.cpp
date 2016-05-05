#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
using namespace std;
int sprawdzanie(long n);
int check_fun(long f, long s);
int check_sum(long a, long f, long ar);
int check_errors(int a, int b, int c);

int main(int argc, char* argv[])
{
    long adres;
    long funkcja;
    long argument;
    
    const char* b = "0x";

    if (strncmp(argv[1], b, 2) == 0)
    adres = strtol(argv[1],NULL ,16);
    else
    adres = strtol(argv[1],NULL ,10);
    if (strncmp(argv[2], b, 2) == 0)
    funkcja = strtol(argv[2],NULL ,16);
    else
    funkcja = strtol(argv[2],NULL ,10);
    if (strncmp(argv[3], b, 2) == 0)
    argument = strtol(argv[3],NULL ,16);
    else
    argument = strtol(argv[3],NULL ,10);
  
    check_errors(check_sum(adres, funkcja, argument), check_fun(funkcja, argument),sprawdzanie(adres));
    return 0;
}
int sprawdzanie(long n)
{
    if(n == 1)
    {
      printf("Camera 1, ");
      return 0;
    }
     else if(n == 2)
     {
      printf("Camera 2, ");
      return 0;
     }
        else if(n == 3)
        {
         printf("Camera 3, ");
         return 0;
        }
         else if(n == 4)
         {
         printf("Camera 4, ");
         return 0;
         }
         else
         {
         //printf("Error 0x01");
         return 1;
         }
}
int check_fun(long f, long s)
{

            if(f == 10)
            {
             printf("POWER, ");

            if(s==0){
                printf("OFF, ");
                return 0;}
            else if (s==1){
                printf("ON, ");
                return 0;}
            else
                //printf("0x03");
                return 3;
            }
             else if(f == 11)
             {
                 printf("ZOOM, ");
                 if(s<5)
             {printf("LEVEL %ld ,", s);
             return 0;}
             else
                return 3;

             }
              else if(f == 12)
              {
                  printf("LIGHT, ");
                 if(s==0)
                {printf("OFF, ");
                return 0;}
                  else if (s==1){
                printf("ON, ");
                return 0;}
                   else if (s==2){
                    printf("FLASH, ");
                    return 0;}
                   else
                   // printf("0x03");
                   return 3;
              }
            else
            {
            //printf("0x02");
            return 2;

            }
        }
int check_sum(long a, long f, long ar)
{

    //long sum = 0xFF;
    long sum_end = 0xFF - a - f - ar;
    printf("0x%0x, ", sum_end);
    if(sum_end<0)
    return 4;
    else
    return 0;

}
int check_errors(int a, int b, int c)
{
    if (a>b)
        printf("0x0%d", a);
    else if(b>c)
        printf("0x0%d", b);
    else if(c>a)
        printf("0x0%d", c);
    else
        printf("0x00");
        return 0;


}
