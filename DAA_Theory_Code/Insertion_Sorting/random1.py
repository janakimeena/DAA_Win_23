#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan  4 21:32:01 2022

@author: janaki
"""
import random
n = 100000
fp = open("random_100000.txt","w")
fp.write(str(n)+" ")  
for i in range(1,n):
    x = random.random()
    fp.write(str(int(x*n))+" ")  
x = random.random()
fp.write(str(int(x*n))+" ")  
fp.close()
