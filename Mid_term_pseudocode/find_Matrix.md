# 행렬에서 특정 원소 찾기

```python
Alg findRow(A, x)
    #intput: array A of n elements, element x
    #output: the index i such that x = A[i] or -1 if no element of A is equal x.

    i <- 0
    while(i < n)
        if(x = A[i])
            return i
        else
            i <- i + 1
    return -1

Alg findMatrix(A, x)
    #input: array A of n X n elements, element x
    #output: the location of x in A or a failure message if no element of A is equal to x

    r <- 0
    while (r < n)
        i <- findRow(A[r], x)
        if(i >= 0)
            write("found at", r, i)
            return
        else
            r <- r + 1
    write("not found")
    return

#n^2은 2차시간이다. 즉 실행시간이 입력 크기에 제곱비례한다. 선형시간이 되려면 실행시간이 입력 크기에 정비례해야 한다. 
```