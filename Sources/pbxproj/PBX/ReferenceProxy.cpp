/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#include <pbxproj/PBX/ReferenceProxy.h>
#include <pbxproj/Context.h>

using pbxproj::PBX::ReferenceProxy;

ReferenceProxy::ReferenceProxy() :
    GroupItem(Isa(), kTypeReferenceProxy)
{
}

bool ReferenceProxy::
parse(Context &context, plist::Dictionary const *dict)
{
    if (!GroupItem::parse(context, dict))
        return false;

    std::string RRID;

    auto RR = context.indirect <ContainerItemProxy> (dict, "remoteRef", &RRID);
    auto FT = dict->value <plist::String> ("fileType");

    if (RR != nullptr) {
        _remoteRef = context.parseObject(context.containerItemProxies, RRID, RR);
        if (_remoteRef == nullptr) {
            abort();
            return false;
        }
    }

    if (FT != nullptr) {
        _fileType = FT->value();
    }

    return true;
}
