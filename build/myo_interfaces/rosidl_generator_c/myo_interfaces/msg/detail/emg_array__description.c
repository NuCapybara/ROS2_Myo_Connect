// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from myo_interfaces:msg/EmgArray.idl
// generated code does not contain a copyright notice

#include "myo_interfaces/msg/detail/emg_array__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_myo_interfaces
const rosidl_type_hash_t *
myo_interfaces__msg__EmgArray__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x01, 0xe3, 0xad, 0x45, 0xcc, 0x37, 0xc5, 0x15,
      0xf3, 0xb2, 0xd2, 0x75, 0xbd, 0xfd, 0x1d, 0xa7,
      0x98, 0xb1, 0xa4, 0x69, 0xcc, 0x42, 0xb1, 0xbb,
      0x50, 0x2e, 0xf1, 0xbb, 0x69, 0x93, 0xc6, 0xe9,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char myo_interfaces__msg__EmgArray__TYPE_NAME[] = "myo_interfaces/msg/EmgArray";

// Define type names, field names, and default values
static char myo_interfaces__msg__EmgArray__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field myo_interfaces__msg__EmgArray__FIELDS[] = {
  {
    {myo_interfaces__msg__EmgArray__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
myo_interfaces__msg__EmgArray__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {myo_interfaces__msg__EmgArray__TYPE_NAME, 27, 27},
      {myo_interfaces__msg__EmgArray__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "#EmgArray message for the Thalmic Myo, which has 8 EMG sensors \n"
  "#arranged about the arm\n"
  "\n"
  "int16[] data";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
myo_interfaces__msg__EmgArray__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {myo_interfaces__msg__EmgArray__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 102, 102},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
myo_interfaces__msg__EmgArray__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *myo_interfaces__msg__EmgArray__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
