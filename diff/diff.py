import sys
import struct
"""import tensorflow as tf"""

class tfdif:
    def __init__(self):
        self.dif = ''
        self.elength = ''
        self.start = ''
        
    def difget(self,dimage):
        self.dif = open(dimage,'rb').read()
        if (self.dif[0] != 77) and (self.dif[1] != 77):
            print('this image is not diff!')
            return
        self.start = struct.unpack('>i',self.dif[4:8])[0]
        self.elength = struct.unpack('>h',self.dif[self.start:self.start+2])[0]
        '''for i in range(self.elength):'''
            
        
    """def"""
    
demo = tfdif()
demo.difget('demo.tif')

print(demo.elength)