/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#include <xcassets/Asset/BrandAssets.h>
#include <plist/Keys/Unpack.h>

using xcassets::Asset::BrandAssets;
using libutil::Filesystem;

bool BrandAssets::
load(Filesystem const *filesystem)
{
    if (!Asset::load(filesystem)) {
        return false;
    }

    if (!loadChildren(filesystem, &_children)) {
        fprintf(stderr, "error: failed to load children\n");
    }

    return true;
}

bool BrandAssets::
parse(plist::Dictionary const *dict, std::unordered_set<std::string> *seen, bool check)
{
    if (!Asset::parse(dict, seen, false)) {
        return false;
    }

    /* Contents is required. */
    if (dict == nullptr) {
        return false;
    }

    auto unpack = plist::Keys::Unpack("BrandAssets", dict, seen);

    // TODO: assets

    if (!unpack.complete(check)) {
        fprintf(stderr, "%s", unpack.errorText().c_str());
    }

    return true;
}


