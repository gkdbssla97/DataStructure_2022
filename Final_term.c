//
// Created by 하윤 on 2022/06/01.
//

Alg push(e) {
    p <- getnode()
    p.elem <- e
    p.next <- t // t == top
    t <- p
    return
}

Alg pop() {
    if(isEmpty())
        emptyStackException()
    e <- t.elem
    p <- t
    t <- t.next
    putnode(p)
    return e
}

Alg isBalanced() {
    S <- empty stack
    while(!endOfFile()) {
        s <- getSymbol()
        if(isOpenSymbol(s))
            S.push(s)
        else if(isCloseSymbol(s))
            if(S.isEmpty())
                return false
            t <- S.pop()
            if(!isCounterpart(s, t))
                return False
    }
    return S.isEmpty()
}

Alg convert() {
    S <- empty
    stack
    while (!endOfFile()) {
        s <- getSymbol()
        if (isOperand(s))
            write(s)
        else if (s = '(')
            S.push(s)
        else if (s = ')') {
            while (S.top() != '(')
                write(S.pop())
            S.pop()
        } else {
            while (!S.isEmpty() & (P[s] <= P[S.top()]))
                write(S.pop())
            S.push(s)
        }
    }
    while (!S.isEmpty())
        write(S.pop())

    return
}

Alg evaluate() {
    S <- empty stack
    while(!endOfFile()) {
        s <- getSymbol()
        if(isOperand(s))
            S.push(s)
        else {
            a <- S.pop()
            b <- S.pop()
            S.push(doOperator(s, a, b))
        }
    }
    write(S.pop())
}

Alg doOperator(op, x, y) {
    switch(op) {
        '+' : v <- x + y
        '-' : v <- x - y
        '*' : v <- x * y
        '/' : v <- x / y
    }
    return v
}

Alg initMultiStack() {
    for i <- 0 to n - 1
        t[i] <- 0
    return
}
Alg isEmpty(i) {
    return t[i] = 0
}
Alg top(i) {
    if(isEmpty(i))
        emptyStackException()
    return t[i].elem
}
Alg push(i, e) {
    q <- getnode()
    q.elem <- e
    q.next <- t[i]
    t[i] <- q
    return
}
Alg pop(i) {
    if(isEmpty())
        emptyStackException()
    e <- t[i].elem
    p <- t[i]
    t[i] <- t[i].next
    putnode(p)
    return e
}

Alg initQueue() {
    f,r <- 0
    return
}
Alg isEmpty() {
    return f = 0
}
Alg enqueue(e) {
    p <- getnode()
    p.elem <- e
    p.next <- 0
    if(isEmpty())
        f, r <- p
    else
        r.next <- p
        r <- p
    return
}
Alg dequeue() {
    if(isEmpty())
        emptyQueueException()
    e <- f.elem
    p <- f
    f <- f.next
    if(f = 0)
        r <- 0
    putnode(p)
    return
}
