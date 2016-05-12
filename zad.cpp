#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
int check_device(long n);
int check_fun(long f, long s);
int check_sum(long a, long f, long ar);
int check_errors(int a, int b, int c);

int main(int argc, char* argv[])
{
    if(argc<2)
      {
          printf("Usage: zad.exe [device_adress] [funktion_adress] [argument_of_funkction]");
          return 0;
      }
    else if (argc>5)
    {
          printf("too many argumenets Usage: zad.exe [device_adress] [funktion_adress] [argument_of_funkction] ");
    }
    else
    {
    long device_adress;
    long function_adress;
    long arg_function;
    const char* check_hex = "0x";
    const char* check_option = "-r";
    const char* power = "POW";
    const char* zoom = "ZOO";
    const char* light = "LGH";
    if (strncmp(argv[1], check_option, 2) == 0)
    {
        if (strncmp(argv[2], check_hex, 2) == 0)
        device_adress = strtol(argv[2],NULL ,16);
        else
        device_adress = strtol(argv[2],NULL ,10);
        if (strncmp(argv[3], check_hex, 2) == 0)
        function_adress = strtol(argv[3],NULL ,16);
        else
        function_adress = strtol(argv[3],NULL ,10);
        if (strncmp(argv[4], check_hex, 2) == 0)
        arg_function = strtol(argv[4],NULL ,16);
        else
        arg_function = strtol(argv[4],NULL ,10);

        check_errors(check_sum(device_adress, function_adress, arg_function), check_fun(function_adress, arg_function),check_device(device_adress));
    }
    else
    {
        if (strncmp(argv[1], power, 3) == 0)
        {
            function_adress = 10;
            printf("POW 0x00 0x02 ");
            check_sum(0, function_adress, 0);
        }
        else if(strncmp(argv[1], zoom, 3) == 0)
        {
            function_adress = 11;
            printf("ZOO 0x00 0x06 ");
            check_sum(0, function_adress, 0);
        }
        else if(strncmp(argv[1], light, 3) == 0)
        {
            function_adress = 12;
            printf("LGH 0x00 0x03 ");
            check_sum(0, function_adress, 0);
        }
        else
        {
            printf(argv[1]);
            printf(" 0x05");
        }
    }
    return 0;
    }
}
int check_device(long n)
{
    if(n == 1)
    {
      printf("0x01 ");
      return 0;
    }
     else if(n == 2)
     {
      printf("0x02 ");
      return 0;
     }
        else if(n == 3)
        {
         printf("0x03 ");
         return 0;
        }
         else if(n == 4)
         {
         printf("0x04 ");
         return 0;
         }
         else
         {
         printf("[] ");
         return 1;
         }
}
int check_fun(long f, long s)
{
            if(f == 10)
            {
             printf("0x0A ");
            if(s==0){
                printf("0x00 ");
                return 0;}
            else if (s==1){
                printf("0x01 ");
                return 0;}
            else
                printf("[] ");
                return 3;
            }
             else if(f == 11)
             {
                 printf("0xB ");
                 if(s<5)
             {printf("0x%.2X", s);
             return 0;}
             else
             printf("[] ");
                return 3;
             }
              else if(f == 12)
              {
                  printf("0x0C");
                 if(s==0)
                {
                    printf("0x00 ");
                   return 0;}
                  else if (s==1)
                    {
                    printf("0x01 ");
                    return 0;}
                   else if (s==2){
                    printf("0x02 ");
                    return 0;}
                   else
                   printf("[] ");
                   return 3;
              }
            else
            {
            printf("[] ");
            return 2;
            }
        }
int check_sum(long a, long f, long ar)
{
    int sum_end = 0xFF - a - f - ar;
    printf("0x%.2X ", sum_end);
    if(sum_end<0)
    {printf("[] ");
    return 4;}
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
