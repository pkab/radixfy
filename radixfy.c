#include<stdio.h>

int main()
{
    FILE *serial;
    serial=fopen("/dev/ttyACM0","r");
    int datread;
    while(1){
        fscanf(serial,"%d",&datread);
        printf("%d\n",datread);
    }
    return 0;
}
