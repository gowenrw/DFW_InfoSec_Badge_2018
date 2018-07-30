import network
from time import sleep
from machine import UART
sta_if = network.WLAN(network.STA_IF)
sta_if.active(True)
uart = UART(2,115200)
uart.init(115200, bits=8, parity=None, stop=1)
while True:
    sleep(.2)
    x = sta_if.scan()
    l = len(x)
    print("Length:", l)
    if l <= 9:
        uart.write("0" + str(l))
    else:
        uart.write(str(l))