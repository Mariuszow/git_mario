#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
int check_device(long n);
int check_fun(long f, long s);
int check_sum(long a, long f, long ar);
int check_sum2(long checksum, long a, long f, long ar);
int check_errors(int a, int b, int c, int d);

int main(int argc, char* argv[])
{
    if(argc<2)
      {
          printf("Usage:zad.exe [comand_of_device] [comand_of_function] [argument_of_function] and later -r and result first command ");
          return 0;
      }
    else if (argc>6)
    {
          printf("too many argumenets Usage:zad.exe [comand_of_device] [comand_of_function] [argument_of_function] and later -r and result first command  ");
    }
    else
    {
    long device_adress;
    long function_adress;
    long arg_function;
    long check_sum1;
    const char* check_option = "-r";

    if (strncmp(argv[1], check_option, 2) == 0)
    {
        device_adress = strtol(argv[2],NULL ,16);
        function_adress = strtol(argv[3],NULL ,16);
        arg_function = strtol(argv[4],NULL ,16);
        check_sum1 = strtol(argv[5],NULL ,16);
        check_errors(check_sum2(check_sum1, device_adress, function_adress, arg_function), check_sum(device_adress, function_adress, arg_function), check_fun(function_adress, arg_function),check_device(device_adress));
        return 0;
    }
    else
    {
        if (strncmp(argv[1], "CAM1", 4) == 0)
        {
            device_adress = 1;
            if(strncmp(argv[2], "POW", 3) == 0)
            {
                function_adress = 10;
                if(strncmp(argv[3], "ON", 2) == 0)
                {
                   arg_function = 1;
                }
                else if (strncmp(argv[3], "OFF", 3) == 0)
                  {
                    arg_function = 0;
                  }
                else
                    printf("WRONG_COMMAND_OF_ARGUMENT ");
            }
            else if(strncmp(argv[2], "LGH", 3) == 0)
            {
               function_adress = 11;
                 if(strncmp(argv[3], "ON", 2) == 0)
                {
                    arg_function = 1;
                }
                else if (strncmp(argv[3], "OFF", 3) == 0)
                {
                   arg_function = 0;
                }
                else if (strncmp(argv[3], "FLASH", 5) == 0)
                {
                    arg_function = 2;
                }
                else
                    printf("[WRONG_COMMAND_OF_ARGUMENT]");
            }
            else
            printf("WRONG_COMMAND_OF_FUNCTION");
        }
        else if (strncmp(argv[1], "CAM2", 4) == 0)
        {
            device_adress = 2;
            if(strncmp(argv[2], "POW", 3) == 0)
            {
                function_adress = 10;
                if(strncmp(argv[3], "ON", 2) == 0)
                {
                    arg_function =1;
                }
                else if (strncmp(argv[3], "OFF", 3) == 0)
                {
                    arg_function =0;
                }
                else
                    printf("WRONG_COMMAND_OF_ARGUMENT ");
            }
            else if(strncmp(argv[2], "LGH", 3) == 0)
            {
               function_adress =11;
                 if(strncmp(argv[3], "ON", 2) == 0)
                {
                    arg_function = 1;
                }
                else if (strncmp(argv[3], "OFF", 3) == 0)
                {
                    arg_function = 0;
                }
                else if (strncmp(argv[3], "FLASH", 5) == 0)
                {
                    arg_function = 2;
                }
                else
                    printf("[WRONG_COMMAND_OF_ARGUMENT]");
            }
            else
            printf("WRONG_COMMAND_OF_FUNCTION");
        }
        else if (strncmp(argv[1], "CAM3", 4) == 0)
        {
            device_adress =3;
            if(strncmp(argv[2], "POW", 3) == 0)
            {
                function_adress = 10;
                if(strncmp(argv[3], "ON", 2) == 0)
                {
                    arg_function =1;
                }
                else if (strncmp(argv[3], "OFF", 3) == 0)
                {
                    arg_function =0;
                }
                else
                    printf("WRONG_COMMAND_OF_ARGUMENT ");
            }
            else if(strncmp(argv[2], "LGH", 3) == 0)
            {
               function_adress =11;
                 if(strncmp(argv[3], "ON", 2) == 0)
                {
                    arg_function = 1;
                }
                else if (strncmp(argv[3], "OFF", 3) == 0)
                {
                    arg_function = 0;
                }
                else if (strncmp(argv[3], "FLASH", 5) == 0)
                {
                    arg_function = 2;
                }
                else
                    printf("[WRONG_COMMAND_OF_ARGUMENT]");
            }
            else
            printf("WRONG_COMMAND_OF_FUNCTION");
        }
        else if (strncmp(argv[1], "CAM4", 4) == 0)
        {
            device_adress = 4;
           if(strncmp(argv[2], "POW", 3) == 0)
            {
                function_adress = 10;
                if(strncmp(argv[3], "ON", 2) == 0)
                {
                    arg_function =1;
                }
                else if (strncmp(argv[3], "OFF", 3) == 0)
                {
                    arg_function =0;
                }
                else
                    printf("WRONG_COMMAND_OF_ARGUMENT ");
            }
            else if(strncmp(argv[2], "LGH", 3) == 0)
            {
               function_adress =11;
                 if(strncmp(argv[3], "ON", 2) == 0)
                {
                    arg_function = 1;
                }
                else if (strncmp(argv[3], "OFF", 3) == 0)
                {
                    arg_function = 0;
                }
                else if (strncmp(argv[3], "FLASH", 5) == 0)
                {
                    arg_function = 2;
                }
                else
                    printf("[WRONG_COMMAND_OF_ARGUMENT]");
            }
            else
            printf("WRONG_COMMAND_OF_FUNCTION");
        }
        else
            {
                printf("WRONG COMMAND OF CAMERA");
            }


    check_device(device_adress);
    check_fun(function_adress, arg_function);
    check_sum(device_adress, function_adress, arg_function);
    return 0;
    }
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
        if(s==0)
        {
            printf("0x00 ");
            return 0;
        }
        else if (s==1)
        {
            printf("0x01 ");
            return 0;
        }
        else
        {
            printf("[] ");
            return 3;
        }
    }

    else if(f == 11)
    {
            printf("0x0B ");

        if(s==0)
        {
            printf("0x00 ");
            return 0;
        }
        else if (s==1)
        {
            printf("0x01 ");
            return 0;
        }
        else if (s==2)
        {
            printf("0x02 ");
            return 0;
        }
        else
        {
            printf("[] ");
            return 3;
        }
    }
    else
    {
      printf("[] [] ");
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
int check_errors(int a, int b, int c ,int d)
{
    if (a>b)
        printf("0x0%d", a);
    else if(b>c)
        printf("0x0%d", b);
    else if(c>a)
        printf("0x0%d", c);
    else if(d>a)
        printf("0x0%d", c);
    else
        printf("0x00");
        return 0;
}
int check_sum2(long checksum, long a, long f, long ar)
{
    int sum_end = 0x00 + checksum - a -f - ar ;

    if(sum_end<0)
    {printf("[] ");
    return 4;}
    else
    {printf("0x%.2X ", sum_end);
    return 0;}

}
