import random
from collections import deque
import numpy as np
import VectorMath
from mapping import mapInit
from bitstring import BitArray

__author__ = "Saurabh Jain, https://github.com/saurabhjn76/"


row_mapping = {}
row_reverse_mapping = {}
col_mapping = {}
col_reverse_mapping = {}


# Made the respective mappings testing for 10*10
row_mapping, row_reverse_mapping = mapInit(row_mapping,row_reverse_mapping,10)
col_mapping, col_reverse_mapping = mapInit(col_mapping,col_reverse_mapping,10)

# term * document matrix
source = []
for i in range(0,10000):
	s = random.randint(0, 2**10000 - 1)
	b = BitArray(uint=s, length=10000)
	source.append(b.bin)
print source






