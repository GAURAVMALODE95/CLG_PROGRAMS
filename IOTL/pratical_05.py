import Adafruit_DHT
import time
import Rpi.GPIO as GPIO
while(True):
    temp,humidity=Adafruit_dht.read_retry(11,21)
    print("temp : ",temp)
    print("humidity : ",humidity)
    
