import Adafruit_DHT
import time

min=50
max=0

while True:
    h,t=Adafruit_dht.read_retry(11,21)
    print("temp in cel : ",t)
    f=(t*1.8)+32
    print("temp in farh : ",f)
    print("humidity : ",h)


    for i in range(5):
        if(t<min):
            min=t
            time.sleep(1)
        print("min temp = ",min)

    for i in range(5):
        if(t>max):
            max=t
            time.sleep(1)
        print("max temp : ",max)
        
