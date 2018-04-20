from bitstring import BitArray
import random


# s = random.randint(0, 2**10000 - 1)
# b = BitArray(uint=s, length=10000)
# for i in range(0,100):
# 	print b[i]


row_mapping = {}
row_reverse_mapping = {}
col_mapping = {}
col_reverse_mapping = {}
limit_index = 3

def mapInit(mapping, reverse_mapping,limit_index):
	count = 0
	while(count<limit_index):
		s = random.randint(0, 2**10000 - 1)
		b = BitArray(uint=s, length=10000)
		if str(b.bin) not in mapping.keys():
			mapping[str(b.bin)] = count
			reverse_mapping[count] = str(b.bin)
			count = count + 1
	return mapping, reverse_mapping

	# if reverse_mapping[0]== str(BitArray(bin =reverse_mapping[0]).bin):
	# 	print 'Yes'
	# else:
	# 	print 'failed'

#print mapping



