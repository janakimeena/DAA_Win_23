
import sys
import os
import numpy as np
import pandas as pd
import subprocess as sb

inp=[]
tm=[]

def generate(otype):
    for i in range(1000,50000,1000):
        os.system('python3 '+otype+'.py '+str(i))
        inp.append(i)
        tmr='./a.out<'+otype+'_'+str(i)+'.txt'
        t=sb.run(tmr,stdout=sb.PIPE,shell=True)
        tm.append(float(t.stdout.decode('utf-8').split('\n')[0].split(' ')[3]))
        os.system('rm -r '+otype+'_*')
        #print('log')
        data={
            'input':inp,
            'time':tm
        }
    return data

def put_graph():

    if len(sys.argv)==2:
        dtype=sys.argv[1]
    else:
        print('using default -argument: ascending')
        print('available -args: ascending descending rand')
        dtype='ascending'
    df=generate(dtype)
    df=pd.DataFrame.from_dict(df)
    #print('log')
    print(df.head())
    df.plot(x='input',y='time').get_figure().savefig(dtype+'.jpg')
    df.to_csv(dtype+'.csv',index=False)

if __name__=="__main__":
    put_graph()

