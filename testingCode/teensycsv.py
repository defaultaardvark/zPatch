import serial
import time
import csv

teensy_ser = serial.Serial('COM9')
teensy_ser.flushInput()

while True:
	try:
		teensy_bytes = teensy_ser.readline()
		decoded_bytes = float(teensy_bytes[0:len(teensy_bytes)-2].decode("utf-8"))
		print(decoded_bytes)
		with open("finger_data.csv", "a") as f:
			writer = csv.writer(f, delimiter=",")
			writer.writerow([time.time(), decoded_bytes])
	except:
		print("KeyboardInterrupt")
		break