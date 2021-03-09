#!/usr/bin/env python3

t = int(input())

for _ in range(t):
    n = int(input())
    
    for i in range(n + 1):
        v = 1
        for j in range(n):
            v *= (2 if j < i else 11)
        if len(str(v)) == n:
            for j in range(n):
                print(2 if j < i else 11, end=('\n' if j == n - 1 else ' '))
            break