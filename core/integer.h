#include <limits.h>
#include <stdint.h>
#include "def.h"

#ifndef INTEGER_H
#define INTEGER_H

typedef enum Integer_Kind {
  Integer_Kind_I8,
  Integer_Kind_U8,
  Integer_Kind_I16,
  Integer_Kind_U16,
  Integer_Kind_I32,
  Integer_Kind_U32,
  Integer_Kind_I64,
  Integer_Kind_U64
};

typedef struct {
  Integer_Kind kind;
  union {
    isize_t iarch; // largest possible signed int on architecture (naturely)
    usize_t uarch; // largest possible unsigned int on architecture (naturely)
  };
} Integer ;

typedef enum {
  Integer_Operation_Add,
  Integer_Operation_Sub,
  Integer_Operation_Mod,
  Integer_Operation_Div,
  Integer_Operation_Mul,
  Integer_Operation_Cmp
} Integer_Operation ;

typedef enum {
  Integer_Operation_Return_Unused,
  Integer_Operation_Return_Status_Lt,
  Integer_Operation_Return_Status_Gt,
  Integer_Operation_Return_Status_Lte,
  Integer_Operation_Return_Status_Gte,
  Integer_Operation_Return_Status_Eq
} Integer_Operation_Return_Status ;

/// @Brief
/// ------
/// Checks for Larger integer range a > b
/// Where a and b are of <Integer_Kind>
/// @Return
/// -------
/// Result_Ok -> a > b
/// Result_Err-> a <= b
inline Result integer_kind_a_is_greater(
const Integer_Kind a,
const Integer_Kind b);

/// @Brief
/// ------
/// Checks if given <Integer> belongs to any unsigned integer range
/// Is unsafe -> No checks on int_addr == NULL
/// @Return
/// -------
/// Result_Ok -> unsigned
/// Result_Err-> signed
inline Result integer_is_unsigned_unsafe(const Integer *int_addr);
#endif
