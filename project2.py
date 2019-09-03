import time
import matplotlib.pyplot as plt
from drawnow import *
import serial
val = [ ]
val1=[ ]
cnt = 0
cnt1=0
#create the serial port object
port = serial.Serial('COM12', 115200, timeout=0.5)
plt.ion()

#create the figure function
def makeFig():
    plt.ylim(-10,10)
    plt.title('Group N: Workshop Project\n Oscilloscope')
    plt.grid(True)
    plt.ylabel('Voltage(V)')
    plt.plot(val, 'b-', label='Channel 0')
    plt.plot(val1, color="red", label='Channel 1')
    plt.legend(loc='lower right')

while (True):
    port.write(b's') # ready signal to Arduino
    if (port.inWaiting()):# if the arduino replies
        value = port.readline()# read the reply
        value1=port.readline()
        print(value)#print value on terminal for monitoring
        number = (float(value)*5/1024)#scale data to corresponding value in V
        number1 = (float(value1)*5/1024)
        val.append(number)
        val1.append(number1)
        time.sleep(0.001)
        drawnow(makeFig)#update plot to reflect new data input
        plt.pause(0.000001)
        cnt = cnt+1
        cnt1=cnt1+1
    if(cnt>50):
        val.pop(0)#keep the plot fresh by deleting the data at position 0
    if(cnt1>50):
        val1.pop(0)
