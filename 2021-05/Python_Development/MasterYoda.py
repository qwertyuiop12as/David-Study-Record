def master_yoda(sentence) :
    temp = ' '.join(sentence.split()[::-1])
    return temp

print(master_yoda("I am home"))
print(master_yoda('We are ready'))