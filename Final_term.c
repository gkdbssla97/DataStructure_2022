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

TreeNode *search(TreeNode *node, int key) {
    if(node == NULL) return NULL;
    if(key == node->key) return node;
    else if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}
TreeNode *search(TreeNode *node, int key) {
    while(node != NULL) {
        if(key == node->key) return node;
        else if(key < node->key)
            node = node->left;
        else
            node = node->right;
    } return NULL;
}
insert_node(T,z) {
    p <- NULL;
    t <- root;
    while t != NULL do
        p <- t
        if z->key < p->key
            then t <- p->left
            else t <- p->right
    if p = NULL
        then root <- z
        else if z->key < p->key
            then p->left <- z
            else p->right <- z
}
Alg romanSize(v) {
    if(isExternal(v))
        return 1
    l <- romanSize(leftChild(v))
    if(l = 0)
        return 0
    r <- romanSize(rightChild(v))
    if((r > 0) & (|l-r| <= 5))
        return l + r + 1
    else
        return 0
}
Alg Sibling(v) {
    p <- v.parent
    if(p.left = v)
        return p.right
    else
        return p.left
}
Alg children(v) {
    C <- 0
    c <- v.first
    while(c != 0)
        C <- C U {c}
        c <- c.next
    return C
}
#분리집합
Alg find(e) {
    return S[e] // Total O(1)
}
Alg union(x, y) {
    for i <- 0 to n - 1
        if(S[i] = y)
            S[i] <- x
    return  // Total O(n)
}
Alg find(e) {
    return setid((node(e).set).elem)
}
Alg union(A, B) {
    if(S[A].size < S[B].size)
        smallerSet, largerSet <- A, B
    else
        smallerSet, largerSet <- B, A
    headS, tailS <- S[smallerSet].head, S[smallerSet].tail
    headL, tailL <- S[largerSet].head, S[largerSet].tail
    p <- headS
    while(p != 0) {
        p.set <- headL
        p <- p.next
    }
    tail.next <- headS
    S[largerSet].tail <- tailS
    S[largerSet].size <- S[A].size + S[B].size
    S[smallerSet].head, S[smallerSet].tail <- 0
    S[smallerSet].size <- 0

    return //Total O(min(|A|, |B|)
}

Alg union(A, B) {
    if(S[A].size < S[B].size)
        smallerSet, largerSet <- A, B
    else
        smallerSet, largerSet <- B, A

    headS, tailS <- S[smallerSet].head, S[smallerSet].tail
    headL, tailL <- S[largerSet].head, S[largerSet].tail

    p <- headS
    while(p != 0) {
        p.set <- headL
        p <- p.next
    }
    tail.next <- headS
    S[largerSet].tail <- tailS
    S[largerSet].size <- S[A].size + S[B].size
    S[smallerSet].head, S[smallerSet].tail <- 0
    S[smallerSet].size <- 0
}
Alg union(x, y) {
    if(Size[x] < Size[y]) {
        Parent[x] <- y
        Size[y] <- Size[x] + Size[y]
    }
    else
        parent[y] <- x
        Size[x] <- Size[x] + Size[y]
    reurn
}
threadedPointer insucc(threadedPointer tree) {
    threadedPointer tmp;
    tmp = tree->rightChild;
    if (!tree->rightTread) // false
        while (!temp->leftThread) // false
            tmp = tmp->leftChild;
    return tmp;
}