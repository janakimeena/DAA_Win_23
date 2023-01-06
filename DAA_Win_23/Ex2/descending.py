#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan  4 21:30:54 2022

@author: janaki
"""
import sys

import sys
if len(sys.argv)==2:
    n=int(sys.argv[1])
else:
    n=10000
fp = open("descending_"+str(n)+".txt","w")
fp.write(str(n)+" ")  
for i in range(n,1,-1):
    fp.write(str(i)+" ")  
fp.write(str(1))
fp.close()
