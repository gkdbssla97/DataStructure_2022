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

Alg preOrderSucc(v) {
    if(isInternal(v))
        return leftChild(v)
    p <- parent(v)
    while(leftChild(p) != v) {
        if(isRoot(p))
            invalidNodeException()
        v <- p
        p <- parent(p)
    }
    return rightChild(p)
}
Alg inOrderSucc(v) {
    if(isInternal(v))
        v <- rightChild(v)
        while(isInternal(v))
            v <- leftChild(v)
        return v
    p <- parent(v)
    while(leftChild(p) != v) {
        if(isRoot(p))
            invalidNodeException()
        v <- p
        p <- parent(p)
    } return p
}
Alg postOrderSucc(v) {
    if(isRoot(v))
        invalidNodeException()
    p <- parent(v)
    if(rightChild(p) = v)
        return p
    v <- rightChild(p)
    while (!isExternal(p))
        v <- leftChild(v)
    return v
}
Alg height(v) {
    if (isExternal(v))
        return 0
    else {
        h <- max(height(leftChild(v)), rightChild(v))
                return 1 + h
    }
}
Alg levelOrder(v) {
    Q <- empty queue
    Q.enqeueu(v)
    while(!Q.isEmpty()) {
        v <- Q.dequeue
        visit(v)
        for each w [- children(v)
            Q.enqueue(w)
    return
    }
}
Alg evalExpr(v) {
    if(isExternal(v))
        return element(v)
    else {
        x <- evalExpr(leftChild(v))
        y <- evalExpr(rightChild(v))
        @ <- element(v)
        return x @ y
    }
}
Alg rDBT(v, rank) { // 중위순회
    if(isInternal(v))
        rDBT(leftChild(v), rank)
    rank <- rank + 1
    drawNodeXY(v, rank, depth(v))
    if(isInternal(v))
        rDBT(rightChild(v), rank)
}
Alg printExpr(v) {
    if(isInternal(v))
        write('(')
        printExpr(leftChild(v))
    write(element(v))
    if(isInternal(v))
        printExpr(rightChild(v))
        write(')')
}
Alg eulerTour(v) {
    visitLeft(v)
    while(isInternal(v))
        eulerTour(leftChild(v))
    visitBelow(v)
    while(isInternal(v))
        eulerTour(rightChild(v))
    visitRight(v)
}
Alg preOrderSucc(v) {
    if(isInternal(v))
        return leftChild(v)
    p <- parent(v)
    while(leftChild(p) != v) {
        if(isRoot(p))
            invalidNodeException()
        v <- p
        p <- parent(p)
    } return rightChild(p)
}
Alg InorderSucc(v) {
    if(isInternal(v)) {
        v <- rightChild(v)
        while(isInternal(v))
            v <- leftChild(v)
        return v
    p <- parent(v)
    while(leftChild(p) != v)
        if(isRoot(p))
            invalidNodeException()
        v <- p
        p <- parent(p)
    } return p
}
Alg PostOrderSucc(v) {
    if(isInternal(v))
        invalidNodeException()
    p <- parent(v)
    if(rightChild(p) = v)
        return p
    v <- rightChild(p)
    while(!isExternal(v))
        v <- leftChild(v)
    return v
}

Alg makeExternalNode() {
    v <- getnode()
    v.elem <- read()
    v.left, v.right <- 0
    return v
}
Alg makeInternalNode() {
    v <- getnode()
    v.elem <- read()
    if(read() = "yes")
        v.left <- makeInternalNode()
    else
        v.left <- makeExternalNode()
    if(read() = "no")
        v.right <- makeInternalNode()
    else
        v.right <- makeExternalNode()
    return v
}