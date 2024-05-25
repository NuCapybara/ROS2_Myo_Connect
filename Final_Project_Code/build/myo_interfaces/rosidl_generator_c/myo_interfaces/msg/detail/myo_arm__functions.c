// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from myo_interfaces:msg/MyoArm.idl
// generated code does not contain a copyright notice
#include "myo_interfaces/msg/detail/myo_arm__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
myo_interfaces__msg__MyoArm__init(myo_interfaces__msg__MyoArm * msg)
{
  if (!msg) {
    return false;
  }
  // arm
  // xdir
  return true;
}

void
myo_interfaces__msg__MyoArm__fini(myo_interfaces__msg__MyoArm * msg)
{
  if (!msg) {
    return;
  }
  // arm
  // xdir
}

bool
myo_interfaces__msg__MyoArm__are_equal(const myo_interfaces__msg__MyoArm * lhs, const myo_interfaces__msg__MyoArm * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // arm
  if (lhs->arm != rhs->arm) {
    return false;
  }
  // xdir
  if (lhs->xdir != rhs->xdir) {
    return false;
  }
  return true;
}

bool
myo_interfaces__msg__MyoArm__copy(
  const myo_interfaces__msg__MyoArm * input,
  myo_interfaces__msg__MyoArm * output)
{
  if (!input || !output) {
    return false;
  }
  // arm
  output->arm = input->arm;
  // xdir
  output->xdir = input->xdir;
  return true;
}

myo_interfaces__msg__MyoArm *
myo_interfaces__msg__MyoArm__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myo_interfaces__msg__MyoArm * msg = (myo_interfaces__msg__MyoArm *)allocator.allocate(sizeof(myo_interfaces__msg__MyoArm), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(myo_interfaces__msg__MyoArm));
  bool success = myo_interfaces__msg__MyoArm__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
myo_interfaces__msg__MyoArm__destroy(myo_interfaces__msg__MyoArm * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    myo_interfaces__msg__MyoArm__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
myo_interfaces__msg__MyoArm__Sequence__init(myo_interfaces__msg__MyoArm__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myo_interfaces__msg__MyoArm * data = NULL;

  if (size) {
    data = (myo_interfaces__msg__MyoArm *)allocator.zero_allocate(size, sizeof(myo_interfaces__msg__MyoArm), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = myo_interfaces__msg__MyoArm__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        myo_interfaces__msg__MyoArm__fini(&data[i - 1]);
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
myo_interfaces__msg__MyoArm__Sequence__fini(myo_interfaces__msg__MyoArm__Sequence * array)
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
      myo_interfaces__msg__MyoArm__fini(&array->data[i]);
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

myo_interfaces__msg__MyoArm__Sequence *
myo_interfaces__msg__MyoArm__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myo_interfaces__msg__MyoArm__Sequence * array = (myo_interfaces__msg__MyoArm__Sequence *)allocator.allocate(sizeof(myo_interfaces__msg__MyoArm__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = myo_interfaces__msg__MyoArm__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
myo_interfaces__msg__MyoArm__Sequence__destroy(myo_interfaces__msg__MyoArm__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    myo_interfaces__msg__MyoArm__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
myo_interfaces__msg__MyoArm__Sequence__are_equal(const myo_interfaces__msg__MyoArm__Sequence * lhs, const myo_interfaces__msg__MyoArm__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!myo_interfaces__msg__MyoArm__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
myo_interfaces__msg__MyoArm__Sequence__copy(
  const myo_interfaces__msg__MyoArm__Sequence * input,
  myo_interfaces__msg__MyoArm__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(myo_interfaces__msg__MyoArm);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    myo_interfaces__msg__MyoArm * data =
      (myo_interfaces__msg__MyoArm *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!myo_interfaces__msg__MyoArm__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          myo_interfaces__msg__MyoArm__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!myo_interfaces__msg__MyoArm__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
