// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from myo_interfaces:msg/EmgArray.idl
// generated code does not contain a copyright notice

#ifndef MYO_INTERFACES__MSG__DETAIL__EMG_ARRAY__STRUCT_H_
#define MYO_INTERFACES__MSG__DETAIL__EMG_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/EmgArray in the package myo_interfaces.
/**
  * EmgArray message for the Thalmic Myo, which has 8 EMG sensors 
  * arranged about the arm
 */
typedef struct myo_interfaces__msg__EmgArray
{
  rosidl_runtime_c__int32__Sequence data;
} myo_interfaces__msg__EmgArray;

// Struct for a sequence of myo_interfaces__msg__EmgArray.
typedef struct myo_interfaces__msg__EmgArray__Sequence
{
  myo_interfaces__msg__EmgArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} myo_interfaces__msg__EmgArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MYO_INTERFACES__MSG__DETAIL__EMG_ARRAY__STRUCT_H_
