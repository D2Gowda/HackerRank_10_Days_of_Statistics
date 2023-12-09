#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'interQuartile' function below.
#
# The function accepts following parameters:
#  1. INTEGER_ARRAY values
#  2. INTEGER_ARRAY freqs
#

def getMedian(arr):
    arr.sort()
    mid = len(arr) // 2
    return arr[mid] if len(arr) % 2 != 0 else (arr[mid-1] + arr[mid]) / 2

def interQuartile(values, freqs):
    # Print your answer to 1 decimal place within this function
    arr = [] 
    for f, v in zip(freqs, values):
        for i in range(f):
            arr.append(v)
    arr.sort()
    
    mid = len(arr) // 2
    
    q1 = getMedian(arr[0:mid])
    
    if len(arr) % 2 == 0:
        q2 = getMedian(arr[mid:len(arr)])
    else:
        q2 = getMedian(arr[mid+1:len(arr)])
        
    result = float(q2 - q1)
    print(round(result, 1))

if __name__ == '__main__':
    n = int(input().strip())

    val = list(map(int, input().rstrip().split()))

    freq = list(map(int, input().rstrip().split()))

    interQuartile(val, freq)
