# 재귀적 곱하기와 나누기

```python
Alg product(a, b)
    #input: positive integer a, b
    #output: product of and b

    if(b = 1)
        return a
    else
        return a + product(a, b - 1)

Alg modulo(a, b)
    #input: positive integer a, b
    #output: a % b

    if(a < b)
        return a
    else
        return modulo(a-b, b)

Alg quotient(a, b)
    #input: positive integer a, b
    #output: a/b

    if(a < b)
        return 0
    else
        return 1 + quotient(a-b,b)
```