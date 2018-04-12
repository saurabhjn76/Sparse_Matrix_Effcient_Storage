from collections import Counter
from collections import deque
import time
from random import randint

import Sparse_Matrix

__author__ = "Saurabh Jain, https://github.com/saurabhjn76/"


vocabulary = Counter()

with open('../../data/freud_fixed.txt') as f:
    for line in f:
        for word in line.split(' '):
            vocabulary[word] += 1

vocabulary = [x[0] for x in vocabulary.most_common(word_space.size)]
