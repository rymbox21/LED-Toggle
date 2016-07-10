import smbus
import time

bus = smbus.SMBus(1)
address = 0x04

def writeNumber(value):
    bus.write_byte(address, value)
    return -1

while True:
	num = int(input("Please choose 1-3: "))
	if num > 3:
		print "Invalid number"

	writeNumber(num)
    