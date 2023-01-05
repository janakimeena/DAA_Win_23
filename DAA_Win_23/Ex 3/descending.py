#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan  4 21:30:54 2022

@author: janaki
"""

n=1000000
fp = open("descending_1000000.txt","w")
fp.write(str(n)+" ")  
for i in range(n,1,-1):
    fp.write(str(i)+" ")  
fp.write(str(1))
fp.close()
