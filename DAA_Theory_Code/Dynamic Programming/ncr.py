def fact(n):
    factorial = []
    if n==1:
        return 1;
    if len(factorial)>=n:
        return factorial[n-1];
    res = fact(n-1)*n;
    factorial.append(res);
    return res
print(fact(1000))
