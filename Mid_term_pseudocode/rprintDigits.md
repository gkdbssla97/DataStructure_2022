# 출력 재귀

```python
Alg printDigits()
    write("Enter a number")
    n <- read()
    if(n < 0)
        write("Negative number!")
    else
        rPrintDigits(n)

Alg rPrintDigits(n)
    if(n < 10)
        write(n)
    else
        rPrintDigits(n/10)
        write(n%10)
```