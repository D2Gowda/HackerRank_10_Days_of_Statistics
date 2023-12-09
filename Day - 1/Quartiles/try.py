#!/bin/python3

import math
import os
import random
import re
import sys

def getMedian(arr):
    arr.sort()
    mid = len(arr) // 2
    if len(arr) % 2 != 0:
        return arr[mid]
    else:
        return (arr[mid] + arr[mid-1]) / 2

def quartiles(arr):
    arr.sort()
    n = len(arr)
    mid = n // 2
    
    if n % 2 != 0:
        q1 = getMedian(arr[:mid])
        q2 = getMedian(arr)
        q3 = getMedian(arr[mid+1:])
    else:
        q1 = getMedian(arr[:mid])
        q2 = getMedian(arr)
        q3 = getMedian(arr[mid:])
        
    return [int(x) for x in [q1, q2, q3]]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    data = list(map(int, input().rstrip().split()))

    res = quartiles(data)

    fptr.write('\n'.join(map(str, res)))
    fptr.write('\n')

    fptr.close()
