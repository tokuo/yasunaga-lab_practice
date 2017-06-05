import sys
"""import tensorflow as tf"""

class tfdif:
    def __init__(self):
        self.dif = ''
        
    def difget(self,dimage):
        self.dif = open(dimage,'rb').read()
        
    """def"""
    
demo = tfdif()
demo.difget('demo.tif')
print(demo.dif)