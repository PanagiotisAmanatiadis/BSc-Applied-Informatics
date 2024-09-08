def variable_byte_code(x):
    binary = bin(x)[2:]
    if(len(binary)%7!=0):
        binary='0'*(7-len(binary)%7) + binary
    out=''
    while len(binary)>7:
        out+='0'+ binary[:7]
        binary=binary[7:]
    out+='1'+binary
    return out

#I check my function with different values.
print("16383",variable_byte_code(16383))
print("127",variable_byte_code(127))
print("128",variable_byte_code(128))
print("243467",variable_byte_code(243467))
