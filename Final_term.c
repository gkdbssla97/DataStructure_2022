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
    if (!tree->rightThread) // false
        while (!tmp->leftThread) // false
            tmp = tmp->leftChild;
    return tmp;
}
threadedPointer insucc(threadedPointer tree) { //중위 후속자의 탐색
    threadedPointer tmp;
    tmp = tree->rightThread;
    if(!tree->rightThread)
        while(!tmp->leftThread)
            tmp = tmp->leftChild;
    return tmp;
}
void tinorder(threadedPointer tree) { // 중위순회 탐색
    threadedPointer tmp = tree;
    for(;;) {
        tmp = insucc(tmp);
        if(tmp == tree)
            break;
        printf("%3c", tmp->data);
    }
}
//
void insertRight(threadedPointer s, threadedPointer r) {
    // s의 오른쪽 자식으로 r을 삽입
    threadedPointer tmp;
    r->rightChild = parent->rightChild;
    r->righThread = parent->rightThread;
    r->leftChild = parent;
    r->leftThread = TRUE;
    s->rightChild = child;
    s->rightThread = FALSE;
    if(!r->rightThread) { // FALSE
        tmp = insucc(r);
        tmp -> leftChild = r;
    }
}
threadedPointer inSucc(threadedPointer tree) {
    //중위 후속탐색자
    threadedPointer tmp;
    tmp = tree->rightChild;
    if(!tree->rightThread) // FALSE
        while(!tmp->leftChild) // FALSE
            tmp = tmp.next;
        return tmp;
}
void tinorder(threadedPointer tree) {
    threadedPointer tmp = tree;
    for(;;) {
        tmp = inSucc(tmp);
        if(tmp == tree)
            break;
        printf("%3c", tmp->data);
    }
}
void insertRight(threadedPointer s, threadedPointer r) {
    threadedPointer tmp;
    r->rightChild = parent->rightChild;
    r->rightThread = parent->rightThread;
    r->leftChild = parent;
    r->leftThread = TRUE;
    s->rightChild = child;
    s->rightThread = FALSE;
    if (!r->rightThread) {
        tmp = inSucc(r);
        tmp->leftChild = r;
    }
}
Alg find(e) {
    return setid((node[e].set).elem)
}

Alg union(A, B) {
    if(S[A].size < S[B].size)
        smallerSet, largerSet <- A, B
    else
        smallerSet, largerSet <- B, A
    headS, tailS <- S[smallerSet].head, S[smallerSet].tail;
    headL, tailL <- S[largerSet].head, S[largerSet].tail;
    p <- headS
    while(p != 0) {
        p.set <- headL
        p <- p.next
    }
    tail.next <- headS
    S[largerSet].tail <- tailS
    S[largerSet].size = S[A].size + S[B].size
    S[smallerSet].head, S[smallerSet].tail <- 0
    S[smallerSet].size <- 0
    return
}
Alg find(e) {
    if(Parent[e] = e)
        return e
    else
        Parent[e] <- find(Parent[e])
        return Parent[e] //Total log*n
}
Alg union(x, y) {
    if(Size[x] < Size[y])
        Parent[x] <- y
        Size[y] <- Size[x] + Size[y]
    else
        Parent[y] <- x
        Size[x] <- Size[x] + Size[y]
    return
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
    tailL.next <- headS
    S[largerSet].tail <- tailS
    S[smallerSet].head, S[smallerSet].tail <- 0
    S[smallerSet].size <- 0
    S[largerSet].size = S[A].size + S[B].size
   return Tatal O(min(|A|, |B|))
}
threadedPointer inSucc(threadedPointer tree) {
    //중위후속자 탐색노드
    threadedPointer tmp;
    tmp = tree->rightChild;
    if (!tree->rightThread) //FALSE
        while (!tmp->leftThread) // FALSE
            tmp = tmp->leftChild;
    return tmp;
}
void tinorder(threadedPointer tree) {
    threadedPointer tmp = tree;
    for(;;) {
        tmp = inSucc(tmp);
        if(tmp == tree) break;
        printf("%3c", tmp->data);
    }
}
void insertRight(threadedPointer s, threadedPointer r) {
    threadedPointer tmp;
    r->rightChild = parent->rightChild;
    r->rightThread = parent->rightThread;
    r->leftChild = parent;
    r->leftThread = TRUE;
    s->rightChild = child;
    s->rightThread = FALSE;
    if(!r->rightThread) { // FALSE
        tmp = inSucc(r);
        tmp->leftChild = r;//**
    }
}
Alg children(v) {
    C <- 0
    c <- v.first
    while(c != 0) {
        C <- C U {c}
        c <- c.next
    } return C
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
Alg PostOrderSucc(v) {
    if(isRoot(v))
        invalidNodeException()
    p <- parent(v)
    if(rightChild(p) = v)
        return p
    v <- rightChild(p)
    while(!isExternal(v))
        v <- leftChild(v)
    return v
}

Alg PreOrderSucc(v) {
    if(isInternal(v))
        return leftChild(v);
    p <- parent(v)
    while(leftChild(p) != v) {
        if(isRoot(p))
            invalidNodeException()
        v <- p
        p <- parent(p)
    } return rightChild(p)
}
Alg InorderSucc(v) {
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
Alg PostOrderSucc(v) {
    if(isRoot(v))
        invalidNodeException()
    p <- parent(v)
    if(rightChild(p) = v)
        return p
    while(!isExternal(v))
        v <- leftChild(v)
    return v
}
Alg preOrderSucc(v) {
    if(isInternal(v))
        return leftChild(v)
    p <- parent(v)
    while(leftChild(p) != v) {
        v <- p
        p <- parent(p)
    }
    return rightChild(p)
}
Alg preOrderSucc(v) { //내부노드, 외부노드가 왼쪽, 오른쪽
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
Alg inOrderSucc(v) { //내부노드, 외부노드 왼쪽, 오른쪽
    if(isInternal(v)) {
        v <- rightChild(v)
        while(isInternal(v)) {
            v <- leftChild(v)
        } return v
    }
    p <- parent(v)
    while(leftChild(p) != v) {
        if(isRoot(p))
            invalidNodeException()
        v <- p
        p <- parent(p)
    }
    return p
}
Alg PostOrderSucc(v) { //루트노드 외부노드 왼쪽, 오른쪽
    if(isRoot(v))
        invalidNodeException()
    p <- parent(v)
    if(rightChild(p) = v)
        return p
    v <- rightChild(p)
    while(!isExternal(v))
        v <- leftChild(v)
    return v
}
threadPointer insucc(threadedPointer tree) {
    threadedPointer tmp;
    tmp = tree->rightChild;
    if(!tree->rightThread) {
        while(!temp->leftThread)
            tmp = tmp->leftChild;
    }
    return tmp;
}
중위순환 탐색노드 threadedPointer
중위순환 탐색 tinorder
노드 합치기 insertRight

Alg preOrderSucc(v) { //내부노드 외부노드 왼쪽, 오른쪽
    if(isInternal(v))
        return leftChild(v)
    p <- parent(v)
    while(leftChild(p) != v) { //오른쪽노드
        if(isRoot(p))
            invalid()
        v <- p
        p <- parent(p)
    }
    return rightChild(p)
}
Alg inOrderSucc(v) { //내부노드 외부노드 LR
    if(isInternal(v))
        v <- rightchild(v)
        while(isInternal(v))
            v <- leftchild(v);
        return v
    p <- parent(v);
    while(leftchild(p) != v)
        if(isRoot(p))
            intvail()
        v <- p
        p <- parnt(p);
    return p
}
Alg postOrderSucc(v) { //내부노드 외부노드 LR
    if(isRoot(v))
        invalidNode()
    p <- parent(v);
    if(rightChild(p) = v)
        return p
    v <- rightchild(p)
    while(!isExternal(v)) {
        v <- leftChild(v)
    }
    return v
}

threadedPointer insucc(threadedPointer tree) {
    threadedPointer tmp
    tmp = tree->rightChild;
    if(!tree->rightThread) {
        while(!tmp->leftThread)
            tmp = tmp->leftChild;
    }
    return tmp;
}
void tinorder(threadedPointer tree) {
    threadedPointer tmp = tree;
    for(;;) {
        tmp = insucc(tmp);
        if(tmp == tree) break;
        printf("%3c", tmp->data);
    }
}
void insertRight(threadedPointer r, threadedPointer s) {
    threadedPointer tmp;
    r->rightChild = parent->rightChild;
    r->rightThread = parent->rightThread;
    r->leftChild = parent;
    r->leftThread = TRUE;
    s->rightChild = child;
    s->rightThread = FALSE;
    if(!r->rightThread) {
        tmp = insucc(r);
        tmp->leftChild = r;
    }
}

void preOrderSucc(v) { //내부, 외부 LR
    if(isInternal(v))
        return leftChild(v)
    p <- parent(v)
    while(leftChild(p) != v) {
        if(isRoot(p))
            invalid()
        v <- p
        p <- parent(p)
    }
    return rightChild(p)
}
void inOrderSucc(v) { //내부, 외부 LR
    if(isInternal(v))
        v <- rightChild(v)
        while(isInternal(v))
            v <- leftChild(v)
        return v
    p <- parent(v)
    while(leftChild(p) != v)
        if(isRoot(p))
            invalid()
        v <- p
        p <- parent(p)
    return p
}
void PostOrderSucc(v) { //루트노드 외부 LR
    if(isRoot(v))
        invalid()
    p <- parent(v)
    if(rightChild(p) = v)
        return p
    v <- rightChild(p)
    while(!isExternal(v)) {
        v <- leftChild(v)
    }
    return v
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
    tailL.next <- headS
    S[largerSet].tail <- tailS
    S[largerSet].size <- S[A].size + S[B].size
    S[smallerSet].head, S[smallerSet].tail <- 0
    S[smallerSet].size <- 0
    return
}
Alg levelOrder(v) {
    Q <- empty queue
    Q.enqueue(v)
    while(!Q.isEmpty()) {
        v <- Q.dequeue()
        visit(v)
        for each w c- children(v)
            Q.enqueue(w)
    } return
}
Alg depth(v) {
    if(isRoot(v))
        return 0
    else
        return 1 + depth(parent(v))
}
Alg height(v) {
    if(isExternal(v))
        return 0
    else
        h <- max(height(leftChild(v)), height(rightChild(v)))
        return 1 + h
}
Alg evalExpr(v) {
    if(isExternal(v))
        return element(v)
    else {
        x <- evalExpr(leftChild(v))
        y <- evalExpr(rightChild(v))
        * <- element(v)
        return x * y
    }
}
Alg printExpr(v) {
    if(isInternal(v))
        write('(')
        printExpr(leftChild(v))
    write(element(v))
    if(isInternal(v)) {
        printExpr(rightChild(v))
        write(')')
    }
}
Alg romanSize(v) {
    if(isExternal(v))
        return 1
    l <-romanSize(leftChild(v))
    if(l = 0)
        return 0
    r <- romanSize(rightChild(v))
    if((r>0) &(|l-r| <= 5))
        return l + r + 1
    else
        return 0
}

threadedPointer insucc(threadedPointer tree) {
    threadedPointer tmp;
    tmp = tree->rightChild;
    if(!tree->rightThread) {
        while(!tmp->leftThread)
            tmp = tmp->leftChild;
    }
    return tmp;
}

void tinorder(threadedPointer tree) {
    threadedPointer tmp = tree;
    for(;;) {
        tmp = insucc(tmp);
        if(tmp == tree)
            break;
        printf("%3c", tmp->data);
    }
}
void insertRight(threadedPointer s, threadedPointer r->) {
    threadedPointer tmp;
    r->rightChild = parent.rightChild;
    r->rightThread = parent.rightThread;
    r->leftChild = parent;
    r->leftThread = TRUE;
    s.rightChild = child;
    s.rightThread = FALSE;
    if(!r->rightThread) {
        tmp = insucc(r);
        tmp->leftChild = r;
    }
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
    tailL.next <- headS
    S[largerSet].tail <- tailS
    S[smallerSet].head, S[smallerSet].tail <- 0
    S[smallerSet].size <- 0
    S[largerSet].size <- S[A].size + S[B].size
}

Alg find(e) {
    if(parent[e] = e)
        return e
    else {
        parent[e] <- find(parent[e])
        return parent[e]
    }
}
Alg union(x, y) {
    if(Size[x] < Size[y])
        praent[x] <- y
        Size[y] <- Size[x] = size[y]
}
Alg PreOrderSucc(v) { //
    if(isInternal)(v)
        return leftChild(v)
    p <- parent(v)
    while(leftChild(p) != v)
        if(isRoot(p))
            invalid()
      v <- p
      p <- parent(p)
  return rightChild(p)
}
Alg inOrderSucc(v) {
    if(isInternal(v))
        v <- rightChild(v)
        while(isInternal(v))
            v <- leftChild(v)
        return v
    p <- parent(v)
    while(leftChild(p) != v)
        if(isRoot(p))
            invalid()
        v <- p
        p <- parent(p)
    return p
}
Alg postOrderSucc(v) {
    if(isRoot(v))
        invalid()
    p <- parent(v)
    if(rightChild(p) = v)
        return p
    v <- rightChild(p)
    while(!isExternal(v))
        v <- leftChild(v)
    return v
}
Alg romanSize(v) {
    if(isExternal(v))
        return 1
    l <- romanSize(leftChild(v))
    lf(l = 0)
        return 0
    r <- romanSize(rightChild(v))
    if((r>0)&(|l-r|<=5))
        return l + r + 1
    else
        return 0
}
Alg enqueue(e) {
    p <- getnode()
    p.elem <- e
    p.next <- 0
    if(isEmpty())
        f,r <- p
    else
        r.next <- p
        r <- p
    return
}
Alg enqueue(e) {
    p <- getnode()
    p.elem <- e
    p.next <- 0
    if(isEmtpy())
        f, r <- p
    else
        r.next <- p
        r <- p
    return
}
Alg dequeue() {
    if(isEmpty())
        invalidException()
    e <- f.elem
    p <- f
    f <- f.next
    if(f = 0)
        r <- 0
    putnode(p)
    return e
}
Alg dequeue() {
    if(isEmpty())
        invalid
    e <- f.elem
    p <- f
    f <- f.next
    if(f = 0)
        r <- 0
    putnode(p)
    return e
}
Alg push(e) {
    p <- getnode()
    p.elem <- e
    p.next <- t
    t <- p
    return
}
Alg pop() {
    if(isEmpty)
        emptyStackException()
    e <-t.elem
    p <- t
    t <- t.next
    putnode(p)
    return e
}
Alg isBalanced() {
    S <- empty Stack
    while(!endOfFile()) {
        s <- getSymbol()
        if(isOpenSymbol(s))
            S.push(s)
        else if(isCloseSymbol(s))
            if(S.isEmpty())
                return False
            t <- S.pop()
            if(!isCounterpart(s, t))
                return False
    } return S.isEmpty()
}
Alg spans(X,S,n) {
    A <- empty Stack
    for i to n - 1
        while(!A.isEmpty() & (X[A.top()] <= X[i]))
            A.pop()
        if(A.isEmpty())
            S[i] <- i + 1
        else
            S[i] <- i - A.top()
        A.push(i)
    while(!A.isEmpty())
        A.pop()
    return
}

Alg spans(X,S,n) {
    A <- empty Stack
    for i to n - 1
        while(!A.isEmpty() & (X[A.top()]<=X[i]))
            A.pop()
        if(A.isEmpty())
            S[i] <- i + 1
        else
            S[i] <- i - A.top()
        A.push(i)
    while(!A.isEmpty())
        A.pop()
    return
}
Alg convert() {
    S <- empty Stack
    while(!endOfFile()) {
        s < -getSymbol()
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
    while(!S.isEmpty())
        write(S.pop())
    return
}
Alg convert() {
    S <- empty Stack
    while(!endOfFile()) {
        s <- getSymbol()
        if(isOperand(s))
            write(s)
        else if(s = '(')
            S.push(s)
        else if(s = ')') {
            while (S.top() != ')')
                write(S.pop())
            S.pop()
        }
        else {
            while(!S.isEmpty() & (P[s] <= P[S.top()]))
                write(S.pop())
            S.push(s)
        }
    }
    while(!S.isEmpty())
        write(S.pop())
    return
}
Alg evaluate() {
    S <- empty Stack
    while(!endOfFile()) {
        s <- getSymbol()
        if(isOperand(s)) //피연산자 + -
            S.push(s)
        else {
            a <- S.pop()
            b <- S.pop()
            S.push(doOpeartor(s,b,a))
        }
    }
    write(S.pop())
    return
}
Alg doOperator(op, x, y) {
    switch(op) {
        '+' : v <- x + y
        '-' : v <- x - y
        '*' : v <- x * y
        '/' : v <- x / y
    } return v
}
Alg push(i, e) {
    q <- getnode()
    q.elem <- e
    q.next <- t[i]
    t[i] <- q
    return
}
Alg pop(i) {
    if(isEmpty(i))
        emptyStackException()
    e <- t[i].elem
    q <- t[i]
    t[i] <- t[i].next
    putnode(q)
    return e
}
Alg evaluate() {
    S <-empty Stack
    while(!endOfFile())
        s <-getSymbol()
        if(isOperand(s))
            S.push(s)
        else {
            a <- S.pop()
            b <- S.pop()
            S.push(doOpearator(s, b, a))
        }
    write(S.pop())
    return
}
Alg doOperator(op, x, y) {
    switch(op) {
        ....

    } return v
}
Alg convert() { // 후위수식표기
    S <- stack empty
    while(!endOfFile()) {
        s <- getSymbol()
        if(isOperand(s))
            S.push(s)
        else if (s = '(')
            S.push(s)
        else if (s = ')') {
            while(S.top() != '(')
                write(S.pop())
            S.pop()
        }
        else {
            while(!S.isEmpty() & (P[s] <= P[S.top()]))
                write(S.pop())
            S.push(s)
        }
    }
    while(!S.isEmpty())
        write(S.pop())
    return
}
threadedPointer insucc(threadedPointer tree) {
    threadedPointer tmp;
    tmp = tree->rightChild;
    if(!tree->rightThread)
        while(!tmp->leftThread)
            tmp = tmp->leftChild;
    return tmp;
}
void tinorder(threadedPointer tree) {
    threadedPointer tmp = tree;
    for(;;) {
        tmp = insucc(tmp);
        if(tree == tmp) break;
        printf("%3c", tmp->data);
    }
}
void insertRight(threadedPointer r, threadedPointer s) {
    threadedPointer tmp;
    r->rightChild = parent->rightChild;
    r->rightThread = parent->rightThread;
    r->leftChild = parent;
    r->leftThread = TRUE;
    s->rightChild = child;
    s->rightThread = FALSE;
    if(!r->rightThread) {
        tmp = insucc(r);
        tmp->leftChild = r;
    }
}
Alg preOrdersucc(v) {
    if(isInternal(v))
        return leftChild(v)
    p <- parent(v)
    while(leftChild(p) != v) {
        if(isRoot(p))
            invalid()
        v <- p
        p <- parent(p)
    }
    return rightChild(p)
}
Alg inOrdersucc(v) {
    if(isInternal(v))
        v <- rightChild(v)
        while(isInternal(v))
            v <- leftChild(v)
        return v
    p <- parent(v)
    while(leftChild(p) != v)
        if(isRoot(p))
            invalid()
        v <- p
        p <- parent(p)
    return p
}
Alg PostOrderSucc(v) {
    if(isRoot(v))
        invalid()
    p <- parent(v)
    if(rightChild(p) = v)
        return p
    v <- rightChild(p)
    while(!isExternal(v))
        v <- leftChild(v)
    return v
}
Alg romanSize(v) {
    if(isExternal(v))
        return 1
    l <- romanSize(leftChild(v))
    if(l = 0)
        return 0
    r <- romanSize(rightChild(v))
    if((r>0)&(|l-r|<=5))
        return l + r + 1
    else
        return 0
}
search(x, k) {
    if x = NULL
        then return NULL
    if k = x->key
        then return x
    else if k<x->key
        then return search(x->left, k)
    else return search(x->right, k)
}
TreeNode *search(TreeNode *node, int key) {
    if(node == null) return NULL;
    if(key == node->key) return node;
    else if(key < node->key)
        return search(node->left, keyy);
}
TreeNode *search(TreeNode *node, int key) {
    while(node != NULL) {
        if(key == node->key) return node;
        else if(key < node->key)
            node = node->left;
        else
            node = node->right;
    }
    return NULL;
}

insert_node(T, z) {
    p <- NULL
    t <- root
    while(t != NULL)
        do p<-t
        if(z->key < p->key)
            then t <- p->left
        else
            t <- p->right
    if p = NULL
        then root <- z
    else if z->key < p->key
        then p->left <- z
    else p->right <- z 
}