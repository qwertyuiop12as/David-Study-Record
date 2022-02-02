def paper_doll(a):
    result = ''
    for i in range(len(a)):
        result += a[i] * 3

    return result


print(paper_doll('Hello'))
print(paper_doll('Mississippi'))
