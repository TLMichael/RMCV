#include <iostream>
#include "serial.h"

int main()
{
    string dev  = "/dev/ttyUSB0"; //串口号
    Serial sel((char *)dev.data());
    sel.setPara();

    int nwrite, nread;
    string buff_t = "hello world\n";
    char * buff_r;

    int i=0;
    while(i < 1000)
    {
        nwrite = sel.writeData(buff_t.data(), (int)buff_t.length());
        cout << "发送了" << nwrite << "个字符" << endl;
        sel.delay(1);

        //nread = sel.readData(buff_r);
        //cout << "[" << nread << "]" << buff_r << endl;
        //sel.delay(1);
        i++;

    }

    return 0;
}
