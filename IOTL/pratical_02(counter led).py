import Rpi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BOARD)
GPIO.setup(36,GPIO.OUT)
GPIO.setup(38,GPIO.OUT)
GPIO.setup(40,GPIO.OUT)
c=1
while(True):
    if(c<=100):
        GPIO.output(36,GPIO.HIGH)
        GPIO.output(38,GPIO.LOW)
        GPIO.output(40,GPIO.LOW)
        time.sleep(1)
        counter+=100
    elif(c>100 and c<200):
        GPIO.output(36,GPIO.LOW)
        GPIO.output(38,GPIO.HIGH)
        GPIO.output(40,GPIO.LOW)
        time.sleep(1)
        counter+=100
    elif(c>=200):
        GPIO.output(36,GPIO.LOW)
        GPIO.output(38,GPIO.LOW)
        GPIO.output(40,GPIO.HIGH)
        time.sleep(1)
        counter=1