#include "integer.h"
#include "rusty.h"
#define make_iarch_converter_function(name, result_kind, min, max)\
  Result name(Integer *addr_new_int, isize_t iarch) {\
    if (IN(iarch, min, max)) {\
      addr_new_int->kind = result_kind;\
      addr_new_int->iarch = iarch;\
      return Result_Ok;\
    }\
    return Result_Err;\
  }
#define make_uarch_converter_function(name, result_kind, max)\
  Result name(Integer *addr_new_int, usize_t uarch) {\
    if (uarch <= max) {\
      addr_new_int->kind = result_kind;\
      addr_new_int->iarch = uarch;\
      return Result_Ok;\
    }\
    return Result_Err;\
  }
#define make_iarch_converter_function_unsigned_dest(name,result_kind,max) \
  Result name(Integer *addr_new_int, isize_t iarch) {\
    if (AND(IS_ZPOS(iarch),iarch <= max)) {\
      addr_new_int->kind = result_kind;\
      addr_new_int->uarch = iarch;\
      return Result_Ok; \
    }\
    return Result_Err;\
  }
#define make_uarch_converter_function_unsigned_dest(name, result_kind, max)\
  Result name(Integer *addr_new_int, usize_t uarch) {\
    if (uarch <= max) {\
      addr_new_int->kind = result_kind;\
      addr_new_int->uarch = uarch;\
      return Result_Ok;\
    }\
    return Result_Err;\
  }
inline Result integer_kind_a_is_greater(
const Integer_Kind a,
const Integer_Kind b) {
      if (a > b) return Result_Ok;
      return Result_Err; // Equal or b is less
}

inline Result integer_is_unsigned_unsafe(const Integer *int_addr) {
  switch (int_addr->kind) {
    case Integer_Kind_I8:
    case Integer_Kind_I16:
    case Integer_Kind_I32:
    case Integer_Kind_I64: break; 
    default: return Result_Ok; // unsigned
  }
  return Result_Err;
}

// i8
make_iarch_converter_function(integer_iarch_to_i8_unsafe, Integer_Kind_I8, INT8_MIN, INT8_MAX)
make_uarch_converter_function(integer_uarch_to_i8_unsafe, Integer_Kind_I8, INT8_MAX)
// u8
make_iarch_converter_function_unsigned_dest(integer_iarch_to_u8_unsafe, Integer_Kind_U8, UINT8_MAX)
make_uarch_converter_function_unsigned_dest(integer_uarch_to_u8_unsafe, Integer_Kind_U8, UINT8_MAX)
// i16
make_iarch_converter_function(integer_iarch_to_i16, Integer_Kind_I16, INT16_MIN, INT16_MAX)
make_uarch_converter_function(integer_uarch_to_i16_unsafe, Integer_Kind_I16, INT16_MAX)
// u16
make_iarch_converter_function_unsigned_dest(integer_iarch_to_u16_unsafe, Integer_Kind_U16, UINT16_MAX)
make_uarch_converter_function_unsigned_dest(integer_uarch_to_u16_unsafe, Integer_Kind_U16, UINT16_MAX)
// i32
make_iarch_converter_function(integer_iarch_to_i32_unsafe, Integer_Kind_I32, INT32_MIN, INT32_MAX)
make_uarch_converter_function(integer_uarch_to_i32_unsafe, Integer_Kind_I32, INT32_MAX)
// u32
make_iarch_converter_function_unsigned_dest(integer_iarch_to_u32_unsafe, Integer_Kind_U32, UINT32_MAX)
make_uarch_converter_function_unsigned_dest(integer_uarch_to_u32_unsafe, Integer_Kind_U32, UINT32_MAX)
// i64
make_iarch_converter_function(integer_iarch_to_i64_unsafe, Integer_Kind_I64, INT64_MIN, INT64_MAX)
make_uarch_converter_function(integer_uarch_to_i64_unsafe, Integer_Kind_I64, INT64_MAX)
// u64
make_iarch_converter_function_unsigned_dest(integer_iarch_to_u64_unsafe, Integer_Kind_U64, UINT64_MAX)
make_uarch_converter_function_unsigned_dest(integer_uarch_to_u64_unsafe, Integer_Kind_U64, UINT64_MAX)

Result integer_to_uarch_unsafe(const Integer *int_ptr, usize_t *v_ptr) {
  if (Result_Ok == integer_is_unsigned_unsafe(int_ptr)) {
    *v_ptr = int_ptr->uarch;
    return Result_Ok;
  }
  return Result_Err;
}

Result integer_to_iarch_unsafe(const Integer *int_ptr, isize_t *v_ptr) {
  if (Result_Err == integer_is_unsigned_unsafe(int_ptr)) {
    *v_ptr = int_ptr->iarch;
    return Result_Ok;
  }
  return Result_Err;
}