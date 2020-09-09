from machine import Pin
from time import sleep
import network

led = Pin(2, Pin.OUT)

def do_connect():
    import network
    sta_if = network.WLAN(network.STA_IF)
    if not sta_if.isconnected():
        print('connecting to network...')
        sta_if.active(True)
        sta_if.connect('Pomidor', 'PomidoryuJanka')
        while not sta_if.isconnected():
            pass
    print('network config:', sta_if.ifconfig())

def scan_local_wifi():
    import network
    sta_if = network.WLAN(network.STA_IF)
    sta_if.active(True)
    for i in sta_if.scan():
      print(i)

def get_synchronize_RTC():
  response = urequests.get(url='http://192.168.5.123:8000/api/synchronize')
  j = ujson.loads(response.text)
  rtc.datetime(j['current'])
  print(rtc.datetime())
  response.close()

if rtc.datetime()[0] == 2000:
  get_synchronize_RTC()

import usocket as socket
addr = socket.getaddrinfo('micropython.org', 80)[0][-1]
s = socket.socket()
print(addr)
s.connect(addr)

while False:
  led.value(not led.value())
  sleep(0.5)

 do_connect()
