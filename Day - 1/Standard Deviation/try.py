#!/bin/python3

import math

def stdDev(arr):
    # Print your answers to 1 decimal place within this function
    mean = sum(arr) / len(arr)
    squares = [(x - mean)**2 for x in arr]
    
    sum_squares = sum(squares)
    
    result = math.sqrt(sum_squares / len(arr))
    
    print(round(result, 1))

if __name__ == '__main__':
    n = int(input().strip())

    vals = list(map(int, input().rstrip().split()))

    stdDev(vals)
