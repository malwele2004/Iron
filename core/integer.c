#include "integer.h"
/**
   UNSAFE
   ------
   [-] No checks on int_addr(could be NULL)
*/

inline Result integer_kind_a_is_greater(
const Integer_Kind a,
const Integer_Kind b) {
      if (a > b) return Result_Ok;
      return Result_Err; // Equal or b is less
}

inline Result integer_is_unsigned_unsafe(const Integer *int_addr) {
  switch (int_addr->kind) {
    default: return Result_Ok; // unsigned
    case Integer_Kind_I8:
    case Integer_Kind_I16:
    case Integer_Kind_I32:
    case Integer_Kind_I64:
  }
  return Result_Err;
}

Result integer_try_cast_i8_from_uarch(Integer *addr_new_int, usize_t uarch) {

}
       
Result integer_from_unsigned(Integer *int_addr, uint64_t v, const Integer_Kind suggested) {
}

Integer_Operation_Return_Status integer_unsigned_arithmetic_unsafe(
Integer *dest_int_addr,
const Integer *const opr1_int_addr,
const Integer *const opr2_int_addr,
const Integer_Operation operation) {
  if (Result_Err == integer_is_unsigned(opr1_int_addr)||
      Result_Err == integer_is_unsigned(opr2_int_addr))
    return Integer_Operation_Return_Status_Unused;

  Integer_Kind probable_resulting_type =
    (Result_Ok == integer_kind_a_is_greater(opr1_int_addr->kind, opr2_int_addr->kind))?
       opr1_int_addr->kind : opr2_int_addr->kind;
  switch (operation) {
    case Integer_Operation_Add: {
    }
  }
}
