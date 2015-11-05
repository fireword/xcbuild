/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef __libutil_UnixTime_h
#define __libutil_UnixTime_h

#include <libutil/Base.h>

namespace libutil {

struct UnixTime {
    static void Decode(uint64_t in, struct tm &out);
    static uint64_t Encode(struct tm const &in);
};

}

#endif  // !__libutil_UnixTime_h
