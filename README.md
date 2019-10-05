# Arduino-Oscilloscope
A simple waveform-depicting oscilloscope using an Arduino microprocessor (tested on Arduino Uno) and Python's matplotlib library

Arduino-Oscilloscope is a very basic program written in Python that plots a low-frequency positive voltage signal against time, hence depicting the waveform of the said input voltage signal.
The arduino code file (osc.ino) constantly reads 100 values of input voltage separated by a fix value (timeBase) of time and stores those values in an array. The array values are then sent to the python script which simply plots them with the help of the matplotlib library.
To create the illusion of a moving waveform, the plot is constantly uppdated with time, and the output appears to be a moving wave due to the persistence of vision.

To run the oscilloscope, simply clone the repository, upload the arduino code to your microprocessor, connect any source of varying voltage (be it a circuit or a function generator) to the correct input pin, and run the python script. That's all.
