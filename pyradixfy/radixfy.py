import serial
import socket
from select import select
import sys
s=socket.socket()
s.connect(('192.168.43.123',7777))
ser=serial.Serial("/dev/ttyACM0",9600);
inp=[sys.stdin,s]
d=''
while(d!='q'):
    inputrd,outputrd,exceptrd=select(inp,[],[])
    for i in inputrd:
        if s==sys.stdin:
            dd=str(sys.stdin.readline())
            print(dd)
            if q in dd:
                d='q'
    ard=ser.readline().decode('ascii')
    strn=str(ard)[:-1]
    s.send(strn.encode('utf-8'))
s.close()

