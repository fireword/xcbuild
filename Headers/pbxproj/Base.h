/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef __pbxproj_Base_h
#define __pbxproj_Base_h

#include <plist/plist.h>
#include <pbxsetting/pbxsetting.h>

namespace pbxproj {

class Context;

using string_vector = libutil::string_vector;
using string_set = libutil::string_set;
using string_map = libutil::string_map;

}

#endif  // !__pbxproj_Base_h
