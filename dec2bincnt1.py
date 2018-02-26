dn,ct=int(input()),0
while dn>0:
    if dn%2==1:
        ct+=1
    dn=int(dn/2)
print(ct)
