# 비트행렬에서 최대 1행 찾기

```python
Alg mostOnes1(A, n)
    #input: bit matrix A[n X n]
    #output: the row of A with most 1's

    i <- j <- 0
    while(1)
        while(A[i,j] = 1)
            j <- j + 1
            if(j = n)
                return i
        row <- i
        while(A[i,j] = 0)
            i <- i + 1
            if(i = n)
                return row  # Total O(n)

Alg mostOnes1(A, n)
    #input: bit matrix A[n X n]
    #output: the row of A with most 1's

    i <- j <- row <- 0
    while((i < n) & (j < n))
        if(A[i,j] = 0)
            i <- i + 1
        else
            row <- i
            j <- j + 1
    return row  # Total O(n)
```