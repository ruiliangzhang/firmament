// The Firmament project
// Copyright (c) 2011-2012 Malte Schwarzkopf <malte.schwarzkopf@cl.cam.ac.uk>
//
// Common type definitions.

#ifndef FIRMAMENT_BASE_TYPES_H
#define FIRMAMENT_BASE_TYPES_H

#include <stdint.h>

#ifdef __PLATFORM_HAS_BOOST__
#include <boost/uuid/uuid.hpp>
#endif

namespace firmament {

#ifdef __PLATFORM_HAS_BOOST__
typedef boost::uuids::uuid ResourceID_t;
#else
typedef uint64_t ResourceID_t;
#endif

}  // namespace firmament

#endif  // FIRMAMENT_BASE_TYPES_H
