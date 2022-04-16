# 하노이탑

```python
Alg hanoi(n)
    rHanoi(n, 'A', 'B', 'C')
    return

Alg rHanoi(n, from, aux, to)
    #input: integer n, peg from, aux, to
    #output: move sequence

    if(n = 1)
        write("move from", from, "to", to)
        return
    rHanoi(n-1, from, to, aux)
    write("move from", from, "to", to)
    rHanoi(n-1, aux, from, to)
    return
```