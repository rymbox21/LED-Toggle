import smbus

bus = smbus.SMBus(1)
# I2C address
address = 0x04

#Write function to Arduino
def writeNumber(value):
    bus.write_byte(address, value)
    return -1

while True:
	#Test user input for a valid number
	try:	
		num = int(input("Please choose from 1-3: "))
		if 3 >= num >= 1:
			writeNumber(num)
		else:
			print ("Invalid number")
	#Mark characters and no input as invalid input
	except (SyntaxError, NameError):
		print("Invalid input")
		
	
		
	
