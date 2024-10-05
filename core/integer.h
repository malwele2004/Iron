#include <limits.h>
#include <stdint.h>
#include "def.h"

#ifndef INTEGER_H
#define INTEGER_H

typedef enum {
  Integer_Kind_I8,
  Integer_Kind_U8,
  Integer_Kind_I16,
  Integer_Kind_U16,
  Integer_Kind_I32,
  Integer_Kind_U32,
  Integer_Kind_I64,
  Integer_Kind_U64
} Integer_Kind ;

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

/// @Brief
/// ------
/// Try to create <Kind> from iarch
/// @Return
/// -------
/// Result_Ok  -> Success 
/// Result_Err -> Failed
Result integer_iarch_to_i8_unsafe(Integer *addr_new_int, isize_t iarch);
Result integer_iarch_to_u8_unsafe(Integer *addr_new_int, isize_t iarch);
Result integer_iarch_to_i16_unsafe(Integer *addr_new_int, isize_t iarch);
Result integer_iarch_to_u16_unsafe(Integer *addr_new_int, isize_t iarch);
Result integer_iarch_to_i32_unsafe(Integer *addr_new_int, isize_t iarch);
Result integer_iarch_to_u32_unsafe(Integer *addr_new_int, isize_t iarch);
Result integer_iarch_to_i64_unsafe(Integer *addr_new_int, isize_t iarch);
Result integer_iarch_to_u64_unsafe(Integer *addr_new_int, isize_t iarch);

/// @Brief
/// ------
/// Try to create <Kind> from uarch
/// @Return
/// -------
/// Result_Ok  -> Success 
/// Result_Err -> Failed
Result integer_uarch_to_i8_unsafe(Integer *addr_new_int, usize_t uarch);
Result integer_uarch_to_u8_unsafe(Integer *addr_new_int, usize_t uarch);
Result integer_uarch_to_i16_unsafe(Integer *addr_new_int, usize_t uarch);
Result integer_uarch_to_u16_unsafe(Integer *addr_new_int, usize_t uarch);
Result integer_uarch_to_i32_unsafe(Integer *addr_new_int, usize_t uarch);
Result integer_uarch_to_u32_unsafe(Integer *addr_new_int, usize_t uarch);
Result integer_uarch_to_i64_unsafe(Integer *addr_new_int, usize_t uarch);
Result integer_uarch_to_u64_unsafe(Integer *addr_new_int, usize_t uarch);

/// @Brief
/// ------
/// Get from <Integer> uarch for computation, if possible
/// @Return
/// -------
/// Result_Ok  -> Success 
/// Result_Err -> Failed
Result integer_to_uarch_unsafe(const Integer *int_ptr, usize_t *v_ptr);

/// @Brief
/// ------
/// Get from <Integer> iarch for computation, if possible
/// @Return
/// -------
/// Result_Ok  -> Success 
/// Result_Err -> Failed
Result integer_to_iarch_unsafe(const Integer *int_ptr, isize_t *v_ptr);

#endif
