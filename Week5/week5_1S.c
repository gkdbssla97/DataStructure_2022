//
// Created by 하윤 on 2022/04/17.
//
////////////초기화/////////////
/*
 * Alg init()
 *  H <- getNode()
 *  T <- getNode()
 *  H.next <- T
 *  T.prev <- H
 *  n <- 0
 *  return
 */
////////////순회/////////////
/*
 * Alg traverse()
 *  p <- H.next
 *  while(p != T)
 *      write("p",p.elem)
 *      p <- p.next
 *  return
 */
////////////삽입/////////////
/*
 * Alg add(r, e)
 *  if((r < 0) || (r > n))
 *      return invalidRankException()
 *  p <- H
 *  for i <- 1 to r
 *      p <- p.next
 *  addNodeBefore(p, e)
 *  n <- n + 1
 *  return
 *
 *  Alg addNodeBefore(r, e):
 *      q <- getNode()
 *      q.elem <- e
 *      q.prev <- p.prev
 *      q.next <- p
 *      (p.prev).next <- q
 *      p.prev <- q
 *      return
 */
////////////삭제////////////
/* Alg remove(r)
 *  if((r < 1) || (r > n))
 *      invalidException()
 *  p <- H
 *  for i <- 1 to r
 *      p <- p.next
 *  removeNode(p)
 *  n <- n - 1
 *  return
 *
 *  Alg removeNode(p)
 *      e <- p.elem
 *      (p.prev).next <- p.next
 *      (p.next).prev <- p.prev
 *      putNode(p)
 *      return e
 */