#ifndef DEF_H
#define DEF_H

#include <stdint.h>
#include "rusty.h"

#define IS_NULL(PTR)    (NULL == PTR)
#define IS_NOT_NULL(PTR)(!IS_NULL(PTR))
#define IS_ZERO(V)      (0 == V)
#define IS_NOT_ZERO(V)  (!IS_ZERO(V))
#define IS_NEG(V)       (V < 0)
#define IS_POS(V)       (V > 0)
#define IS_ZNEG(V)      (IS_ZERO(V) || IS_NEG(V))
#define IS_ZPOS(V)      (IS_ZERO(V) || IS_POS(V))
#define NOT(A)          (!A)
#define OR(A,B)         ((A) || (B))
#define AND(A,B)        ((A) && (B))
#define XOR(A,B)        OR(AND(A,NOT(B)), AND(NOT(A),B))
#define B_NOT(A)        (~A)
#define B_OR(A,B)       (A|B)
#define B_AND(A,B)      (A&B)
#define B_XOR(A,B)      (A^B)
#define IN(V,A,B)       AND(A <= V, V <= B)

typedef int64_t isize_t;
typedef uint64_t usize_t;

#endif
