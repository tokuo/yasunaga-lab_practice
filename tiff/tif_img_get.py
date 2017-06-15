import os
from PIL import Image
import glob
import tensorflow as tf

class preparation_tensorflow:
    """essential library list
        os, PIL, tensorflow, glob"""
    def __init__(self):
        self.img = ""
        self.SIZE = ()
        self.MODE = "P"
        self.preX = []
        self.x = []
        self.file_list = []
        
    def init_get(self,tif_path):
        self.img = Image.open(tif_path)
        if self.MODE != self.img.mode:
            self.img = self.img.convert(self.MODE)
        self.SIZE = self.img.size
        for i in range(self.SIZE[0]):
            for j in range(self.SIZE[1]):
                self.preX.append(self.img.getpixel((i,j)))
        self.x.append(self.preX)
        self.preX = []
                
    def get_tiff(self,file_name):
        self.img = Image.open(file_name)
        if self.MODE != self.img.mode:
            self.img = self.img.convert(self.MODE)
        if self.SIZE != self.img.size:
            self.img = self.img.resize(self.SIZE)
        for i in range(self.SIZE[0]):
            for j in range(self.SIZE[1]):
                self.preX.append(self.img.getpixel((i,j)))
        self.x.append(self.preX)
        self.preX = []
                
    def get_in_dir(self,dir_path):
        self.file_list = glob.glob(dir_path + "/*.tif")
        if len(self.x) == 0:
            self.init_get(self.file_list[0])
            del self.file_list[0]
        for f in self.file_list:
            self.get_tiff(f)
