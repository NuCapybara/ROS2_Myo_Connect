// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from myo_interfaces:msg/EmgArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "myo_interfaces/msg/detail/emg_array__rosidl_typesupport_introspection_c.h"
#include "myo_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "myo_interfaces/msg/detail/emg_array__functions.h"
#include "myo_interfaces/msg/detail/emg_array__struct.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__EmgArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  myo_interfaces__msg__EmgArray__init(message_memory);
}

void myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__EmgArray_fini_function(void * message_memory)
{
  myo_interfaces__msg__EmgArray__fini(message_memory);
}

size_t myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__size_function__EmgArray__data(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__get_const_function__EmgArray__data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__get_function__EmgArray__data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__fetch_function__EmgArray__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__get_const_function__EmgArray__data(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__assign_function__EmgArray__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__get_function__EmgArray__data(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__resize_function__EmgArray__data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__EmgArray_message_member_array[1] = {
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myo_interfaces__msg__EmgArray, data),  // bytes offset in struct
    NULL,  // default value
    myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__size_function__EmgArray__data,  // size() function pointer
    myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__get_const_function__EmgArray__data,  // get_const(index) function pointer
    myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__get_function__EmgArray__data,  // get(index) function pointer
    myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__fetch_function__EmgArray__data,  // fetch(index, &value) function pointer
    myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__assign_function__EmgArray__data,  // assign(index, value) function pointer
    myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__resize_function__EmgArray__data  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__EmgArray_message_members = {
  "myo_interfaces__msg",  // message namespace
  "EmgArray",  // message name
  1,  // number of fields
  sizeof(myo_interfaces__msg__EmgArray),
  myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__EmgArray_message_member_array,  // message members
  myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__EmgArray_init_function,  // function to initialize message memory (memory has to be allocated)
  myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__EmgArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__EmgArray_message_type_support_handle = {
  0,
  &myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__EmgArray_message_members,
  get_message_typesupport_handle_function,
  &myo_interfaces__msg__EmgArray__get_type_hash,
  &myo_interfaces__msg__EmgArray__get_type_description,
  &myo_interfaces__msg__EmgArray__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_myo_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, myo_interfaces, msg, EmgArray)() {
  if (!myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__EmgArray_message_type_support_handle.typesupport_identifier) {
    myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__EmgArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &myo_interfaces__msg__EmgArray__rosidl_typesupport_introspection_c__EmgArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
