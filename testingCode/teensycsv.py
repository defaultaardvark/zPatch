import serial
import time
import csv
import cv2
import datetime

teensy_ser = serial.Serial("COM8", timeout = 1, baudrate = 9600)
teensy_ser.flushInput()
vid = cv2.VideoCapture(0)

teensync =	[]

while True:
	grabbed, frame = vid.read()
	if not grabbed:
		break
	cv2.imshow("Feed", frame)
	#timestmp = datetime.datetime.now()
	#print("Time: %d" % timestmp)
	key = cv2.waitKey(1) & 0xFF
	if key == ord('e') or key == ord('r'):
		key = bytes(chr(key), 'utf-8')
		teensy_ser.write(key)
		teensy_int = teensy_ser.readline().decode('utf-8').rstrip()
		teensync.append(teensy_int)	
	if key == ord('q'):
		print(teensync)
		with open ('teensync.csv', 'w') as csvFile:
			writer = csv.writer(csvFile)
			writer.writerow(teensync)
		break	
vid.release()
cv2.destroyAllWindows()
teensy_ser.close()
exit()