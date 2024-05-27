// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from myo_interfaces:msg/MyoArm.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "myo_interfaces/msg/detail/myo_arm__functions.h"
#include "myo_interfaces/msg/detail/myo_arm__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace myo_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MyoArm_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) myo_interfaces::msg::MyoArm(_init);
}

void MyoArm_fini_function(void * message_memory)
{
  auto typed_message = static_cast<myo_interfaces::msg::MyoArm *>(message_memory);
  typed_message->~MyoArm();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MyoArm_message_member_array[2] = {
  {
    "arm",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myo_interfaces::msg::MyoArm, arm),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "xdir",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myo_interfaces::msg::MyoArm, xdir),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MyoArm_message_members = {
  "myo_interfaces::msg",  // message namespace
  "MyoArm",  // message name
  2,  // number of fields
  sizeof(myo_interfaces::msg::MyoArm),
  MyoArm_message_member_array,  // message members
  MyoArm_init_function,  // function to initialize message memory (memory has to be allocated)
  MyoArm_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MyoArm_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MyoArm_message_members,
  get_message_typesupport_handle_function,
  &myo_interfaces__msg__MyoArm__get_type_hash,
  &myo_interfaces__msg__MyoArm__get_type_description,
  &myo_interfaces__msg__MyoArm__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace myo_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<myo_interfaces::msg::MyoArm>()
{
  return &::myo_interfaces::msg::rosidl_typesupport_introspection_cpp::MyoArm_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, myo_interfaces, msg, MyoArm)() {
  return &::myo_interfaces::msg::rosidl_typesupport_introspection_cpp::MyoArm_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
