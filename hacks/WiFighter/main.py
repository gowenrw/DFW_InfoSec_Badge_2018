import board
import busio
import neopixel
from time import sleep
pixels = neopixel.NeoPixel(board.NEOPIXEL, 10, brightness=.01)
uart = busio.UART(board.TX, board.RX, baudrate=115200)
data = uart.read(2)
while True:
    data = uart.read(2)
    if data is not None:
        data_string = ''.join([chr(b) for b in data])
        print(data_string, end="")

        count = int(data_string)
        if count <= 9:
            for x in range(count):
                pixels[x] = (255, 0, 0)
                sleep(.05)
            pixels[count] = (0, 255, 0)
        else:
            for x in range(count % 10):
                pixels[x] = (255, 0, 0)
                sleep(.05)
            pixels[count % 10] = (0, 0, 255)
            count = count % 10
        for x in range(count - 1, -1, -1):
            pixels[x] = (0, 0, 0)
            sleep(.05)
        sleep(.75)
        pixels.fill((0, 0, 0))