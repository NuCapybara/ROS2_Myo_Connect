// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from myo_interfaces:msg/MyoArm.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "myo_interfaces/msg/detail/myo_arm__rosidl_typesupport_introspection_c.h"
#include "myo_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "myo_interfaces/msg/detail/myo_arm__functions.h"
#include "myo_interfaces/msg/detail/myo_arm__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void myo_interfaces__msg__MyoArm__rosidl_typesupport_introspection_c__MyoArm_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  myo_interfaces__msg__MyoArm__init(message_memory);
}

void myo_interfaces__msg__MyoArm__rosidl_typesupport_introspection_c__MyoArm_fini_function(void * message_memory)
{
  myo_interfaces__msg__MyoArm__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember myo_interfaces__msg__MyoArm__rosidl_typesupport_introspection_c__MyoArm_message_member_array[2] = {
  {
    "arm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myo_interfaces__msg__MyoArm, arm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "xdir",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myo_interfaces__msg__MyoArm, xdir),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers myo_interfaces__msg__MyoArm__rosidl_typesupport_introspection_c__MyoArm_message_members = {
  "myo_interfaces__msg",  // message namespace
  "MyoArm",  // message name
  2,  // number of fields
  sizeof(myo_interfaces__msg__MyoArm),
  myo_interfaces__msg__MyoArm__rosidl_typesupport_introspection_c__MyoArm_message_member_array,  // message members
  myo_interfaces__msg__MyoArm__rosidl_typesupport_introspection_c__MyoArm_init_function,  // function to initialize message memory (memory has to be allocated)
  myo_interfaces__msg__MyoArm__rosidl_typesupport_introspection_c__MyoArm_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t myo_interfaces__msg__MyoArm__rosidl_typesupport_introspection_c__MyoArm_message_type_support_handle = {
  0,
  &myo_interfaces__msg__MyoArm__rosidl_typesupport_introspection_c__MyoArm_message_members,
  get_message_typesupport_handle_function,
  &myo_interfaces__msg__MyoArm__get_type_hash,
  &myo_interfaces__msg__MyoArm__get_type_description,
  &myo_interfaces__msg__MyoArm__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_myo_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, myo_interfaces, msg, MyoArm)() {
  if (!myo_interfaces__msg__MyoArm__rosidl_typesupport_introspection_c__MyoArm_message_type_support_handle.typesupport_identifier) {
    myo_interfaces__msg__MyoArm__rosidl_typesupport_introspection_c__MyoArm_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &myo_interfaces__msg__MyoArm__rosidl_typesupport_introspection_c__MyoArm_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
