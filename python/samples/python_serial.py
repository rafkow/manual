import serial
import struct

ser = serial.Serial(
    port='/dev/ttyS0',
    baudrate=115200,
    timeout=1.0)

print(ser.isOpen())

while(1):
    x = input("podaj znak:") 
    if x == "e" : ser.write(serial.to_bytes([128]))
    if x == "d" : ser.write(serial.to_bytes([129]))
    if x == "s" : ser.write(serial.to_bytes([1]))

ser.close()
