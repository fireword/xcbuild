/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef __pbxbuild_BuildEnvironment_h
#define __pbxbuild_BuildEnvironment_h

#include <pbxbuild/Base.h>

namespace pbxbuild {

class BuildEnvironment {
private:
    pbxspec::Manager::shared_ptr         _specManager;
    std::shared_ptr<xcsdk::SDK::Manager> _sdkManager;
    pbxsetting::Environment              _baseEnvironment;

public:
    BuildEnvironment(pbxspec::Manager::shared_ptr const &specManager, std::shared_ptr<xcsdk::SDK::Manager> const &sdkManager, pbxsetting::Environment const &baseEnvironment);

public:
    pbxspec::Manager::shared_ptr const &specManager() const
    { return _specManager; }
    std::shared_ptr<xcsdk::SDK::Manager> const &sdkManager() const
    { return _sdkManager; }

public:
    pbxsetting::Environment const &baseEnvironment() const
    { return _baseEnvironment; }

public:
    static std::unique_ptr<BuildEnvironment>
    Default(void);
};

}

#endif // !__pbxbuild_BuildEnvironment_h
