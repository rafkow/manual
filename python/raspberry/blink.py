import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(37,GPIO.OUT)

while True:
    GPIO.output(37,True)
    GPIO.output(37,False)
