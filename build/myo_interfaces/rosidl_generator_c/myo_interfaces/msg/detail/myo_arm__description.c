// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from myo_interfaces:msg/MyoArm.idl
// generated code does not contain a copyright notice

#include "myo_interfaces/msg/detail/myo_arm__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_myo_interfaces
const rosidl_type_hash_t *
myo_interfaces__msg__MyoArm__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd1, 0x70, 0xb3, 0x71, 0xe3, 0x1d, 0x58, 0x82,
      0xdc, 0xb5, 0x5f, 0x3e, 0x9f, 0xf6, 0xb7, 0x0e,
      0xc0, 0x20, 0x73, 0xe2, 0x12, 0xf5, 0x6c, 0x74,
      0xba, 0xd5, 0x60, 0xf9, 0x94, 0x2a, 0x16, 0x9b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char myo_interfaces__msg__MyoArm__TYPE_NAME[] = "myo_interfaces/msg/MyoArm";

// Define type names, field names, and default values
static char myo_interfaces__msg__MyoArm__FIELD_NAME__arm[] = "arm";
static char myo_interfaces__msg__MyoArm__FIELD_NAME__xdir[] = "xdir";

static rosidl_runtime_c__type_description__Field myo_interfaces__msg__MyoArm__FIELDS[] = {
  {
    {myo_interfaces__msg__MyoArm__FIELD_NAME__arm, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {myo_interfaces__msg__MyoArm__FIELD_NAME__xdir, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
myo_interfaces__msg__MyoArm__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {myo_interfaces__msg__MyoArm__TYPE_NAME, 25, 25},
      {myo_interfaces__msg__MyoArm__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "#Arm message for the Thalmic Myo. Using firmware 1.1.4.2, \n"
  "#Thalmic Gesture Recognition is possible after sync gesture is performed.\n"
  "\n"
  "#arm represents which arm the device is on\n"
  "#Enumerated: UNKNOWN=0, RIGHT=1, LEFT=2\n"
  "uint8 arm\n"
  "#xdir represents the direction of the x-axis\n"
  "#Enumerated: UNKNOWN=0, X_TOWARD_WRIST=1, X_TOWARD_ELBOW=2\n"
  "uint8 xdir";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
myo_interfaces__msg__MyoArm__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {myo_interfaces__msg__MyoArm__TYPE_NAME, 25, 25},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 342, 342},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
myo_interfaces__msg__MyoArm__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *myo_interfaces__msg__MyoArm__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
