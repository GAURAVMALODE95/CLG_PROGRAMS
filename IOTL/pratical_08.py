import Rpi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BOARD)
GPIO.setup(40,GPIO.IN)
GPIO.setup(3,GPIO.OUT)
while True:
    i=GPIO.INPUT(40)
    if(i==0):
        print("OBSTACLE !!!!")
        GPIO.output(3,GPIO.HIGH)
        time.sleep(1)
    else:
        print("OBSTACLE NOT FOUND")
        GPIO.output(3,GPIO.LOW)
        time.sleep(1)

