// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from myo_interfaces:msg/EmgArray.idl
// generated code does not contain a copyright notice
#include "myo_interfaces/msg/detail/emg_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
myo_interfaces__msg__EmgArray__init(myo_interfaces__msg__EmgArray * msg)
{
  if (!msg) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->data, 0)) {
    myo_interfaces__msg__EmgArray__fini(msg);
    return false;
  }
  return true;
}

void
myo_interfaces__msg__EmgArray__fini(myo_interfaces__msg__EmgArray * msg)
{
  if (!msg) {
    return;
  }
  // data
  rosidl_runtime_c__int32__Sequence__fini(&msg->data);
}

bool
myo_interfaces__msg__EmgArray__are_equal(const myo_interfaces__msg__EmgArray * lhs, const myo_interfaces__msg__EmgArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
myo_interfaces__msg__EmgArray__copy(
  const myo_interfaces__msg__EmgArray * input,
  myo_interfaces__msg__EmgArray * output)
{
  if (!input || !output) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

myo_interfaces__msg__EmgArray *
myo_interfaces__msg__EmgArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myo_interfaces__msg__EmgArray * msg = (myo_interfaces__msg__EmgArray *)allocator.allocate(sizeof(myo_interfaces__msg__EmgArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(myo_interfaces__msg__EmgArray));
  bool success = myo_interfaces__msg__EmgArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
myo_interfaces__msg__EmgArray__destroy(myo_interfaces__msg__EmgArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    myo_interfaces__msg__EmgArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
myo_interfaces__msg__EmgArray__Sequence__init(myo_interfaces__msg__EmgArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myo_interfaces__msg__EmgArray * data = NULL;

  if (size) {
    data = (myo_interfaces__msg__EmgArray *)allocator.zero_allocate(size, sizeof(myo_interfaces__msg__EmgArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = myo_interfaces__msg__EmgArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        myo_interfaces__msg__EmgArray__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
myo_interfaces__msg__EmgArray__Sequence__fini(myo_interfaces__msg__EmgArray__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      myo_interfaces__msg__EmgArray__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

myo_interfaces__msg__EmgArray__Sequence *
myo_interfaces__msg__EmgArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myo_interfaces__msg__EmgArray__Sequence * array = (myo_interfaces__msg__EmgArray__Sequence *)allocator.allocate(sizeof(myo_interfaces__msg__EmgArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = myo_interfaces__msg__EmgArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
myo_interfaces__msg__EmgArray__Sequence__destroy(myo_interfaces__msg__EmgArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    myo_interfaces__msg__EmgArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
myo_interfaces__msg__EmgArray__Sequence__are_equal(const myo_interfaces__msg__EmgArray__Sequence * lhs, const myo_interfaces__msg__EmgArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!myo_interfaces__msg__EmgArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
myo_interfaces__msg__EmgArray__Sequence__copy(
  const myo_interfaces__msg__EmgArray__Sequence * input,
  myo_interfaces__msg__EmgArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(myo_interfaces__msg__EmgArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    myo_interfaces__msg__EmgArray * data =
      (myo_interfaces__msg__EmgArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!myo_interfaces__msg__EmgArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          myo_interfaces__msg__EmgArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!myo_interfaces__msg__EmgArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
