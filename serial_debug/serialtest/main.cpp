#include<serial.h>

int main
{
    char *dev  = "/dev/ttyUSB0"; //串口号
    Serial sel(dev);
    sel.setPara(); 

    int nwrite;
    string buff = "hello world\n";

    while(true)
    {
        nread = sel.writeData(buff.data(), buff.length());
        sel.delay(1);
    }

    return 0;
}