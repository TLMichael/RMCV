# usr/bin/python3
# coding: utf-8
import serial
from time import sleep

ser = serial.Serial("/dev/ttyUSB0", 115200, timeout=0.5)

def recv(serial):
    global data
    while True:
        data = serial.read(30)
        if data == '':
            continue
        else:
            break
        sleep(0.02)
    return data

while True:
    data = recv(ser)
    print(data)
    ser.write(data)