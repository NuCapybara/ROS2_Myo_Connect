// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from myo_interfaces:msg/MyoArm.idl
// generated code does not contain a copyright notice

#ifndef MYO_INTERFACES__MSG__DETAIL__MYO_ARM__STRUCT_H_
#define MYO_INTERFACES__MSG__DETAIL__MYO_ARM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/MyoArm in the package myo_interfaces.
/**
  * Arm message for the Thalmic Myo. Using firmware 1.1.4.2, 
  * Thalmic Gesture Recognition is possible after sync gesture is performed.
 */
typedef struct myo_interfaces__msg__MyoArm
{
  /// arm represents which arm the device is on
  /// Enumerated: UNKNOWN=0, RIGHT=1, LEFT=2
  uint8_t arm;
  /// xdir represents the direction of the x-axis
  /// Enumerated: UNKNOWN=0, X_TOWARD_WRIST=1, X_TOWARD_ELBOW=2
  uint8_t xdir;
} myo_interfaces__msg__MyoArm;

// Struct for a sequence of myo_interfaces__msg__MyoArm.
typedef struct myo_interfaces__msg__MyoArm__Sequence
{
  myo_interfaces__msg__MyoArm * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} myo_interfaces__msg__MyoArm__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MYO_INTERFACES__MSG__DETAIL__MYO_ARM__STRUCT_H_
