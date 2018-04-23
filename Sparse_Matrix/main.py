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
# for i in range(0,10000):
# 	s = random.randint(0, 2**10000 - 1)
# 	b = BitArray(uint=s, length=10000)
# 	source.append(b.bin)
# print source

def pad_zeroes(s):
	if(len(s)==3):
		return s
	elif(len(s)==2):
		return "0"+s
	else:
		return "00" + s




def make8bitstring(s):
	f=''
	for i in range(0,1250):
		#print i, s[8*i:8*(i+1)]
		c = s[8*i:8*(i+1)]
		f+= pad_zeroes(str(int(c[::-1],2)))
	return f

def binfrom8bitstring(s):
	bin8 = lambda x : ''.join(([str((x >> i) & 1) for i in range(8)]))
	f =''
	for i in range(0,1250):
		#print i, s[3*i: 3*(i+1)]
		c = s[3*i: 3*(i+1)]
		print "-------",bin8(int(c))
		f+= bin8(int(c))
	return f

def leftShift(s):
	ss =''
	ss+= '0' + s[0:len(s)-1]
	return ss
def rightShift(s):
	ss =''
	ss+= s[1:] +'0'
	return ss

def hammingDistance(s1,s2):
	count = 0
	for i in range(0,len(s2)):
		if s1[i]!=s2[i]:
			count += 1
	return count 
def xorString(s1,s2):
	f =''
	for i in range(0,len(s2)):
		if s1[i]!=s2[i]:
			f += '1'
		else:
			f += '0'
	return f




s = random.randint(0, 2**10000 - 1)
b = BitArray(uint=s, length=10000)
a1 = str(b.bin)
#print str(b.bin)
print make8bitstring(str(b.bin))
#print('/////////////////////////////////////////////////////////')
s = random.randint(0, 2**10000 - 1)
b = BitArray(uint=s, length=10000)
a2 = str(b.bin)
#print str(b.bin)
print make8bitstring(str(b.bin))

#print xorString('1010101010','0101010101')

print ('XORRRrrrrrrrrrr')

print make8bitstring(xorString(a1,a2))
print ('hamming distance')
print hammingDistance(a1,a2)
print ('left shift')
print make8bitstring(leftShift(a1))
print ('right shift')
print make8bitstring(rightShift(a1))



		
# print binfrom8bitstring('255255')

# print binfrom8bitstring('254255')

# print binfrom8bitstring('255255')

# print binfrom8bitstring('255127')

# #print a1
# a3 = '1010101010000001'
# print a3
# print leftShift(a3)
# print a3
# print rightShift(a3)










