# 누적평균 

```python
Alg prefixAverages(X, n)
    #input: array X, A of n integers
    #output: array A if prefix averages of X

    sum <- 0
    for i <- 0 to n - 1
        sum <- sum + X[i]
        A[i] <- sum/(i + 1)
    return 