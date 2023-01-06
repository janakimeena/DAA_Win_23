#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan  4 21:32:01 2022

@author: janaki
"""
import sys
import random


if len(sys.argv)==2:
    n=int(sys.argv[1])
else:
    n=10000
fp = open("rand_"+str(n)+".txt","w")
fp.write(str(n)+" ")  
for i in range(1,n):
    x = random.random()
    fp.write(str(int(x*n))+" ")  
x = random.random()
fp.write(str(int(x*n))+" ")  
fp.close()
