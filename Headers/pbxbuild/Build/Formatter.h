/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef __pbxbuild_Formatter_h
#define __pbxbuild_Formatter_h

#include <pbxbuild/Base.h>

namespace pbxbuild {

class BuildContext;
class ToolInvocation;

namespace Build {

class Formatter {
protected:
    Formatter();
    ~Formatter();

public:
    virtual std::string begin(BuildContext const &buildContext) = 0;
    virtual std::string success(BuildContext const &buildContext) = 0;
    virtual std::string failure(BuildContext const &buildContext, std::vector<ToolInvocation> const &failingInvocations) = 0;

public:
    virtual std::string beginTarget(BuildContext const &buildContext, pbxproj::PBX::Target::shared_ptr const &target) = 0;
    virtual std::string checkDependencies(pbxproj::PBX::Target::shared_ptr const &target) = 0;

public:
    virtual std::string beginWriteAuxiliaryFiles(pbxproj::PBX::Target::shared_ptr const &target) = 0;
    virtual std::string createAuxiliaryDirectory(std::string const &directory) = 0;
    virtual std::string writeAuxiliaryFile(std::string const &file) = 0;
    virtual std::string setAuxiliaryExecutable(std::string const &file) = 0;
    virtual std::string finishWriteAuxiliaryFiles(pbxproj::PBX::Target::shared_ptr const &target) = 0;

public:
    virtual std::string createProductStructure(pbxproj::PBX::Target::shared_ptr const &target) = 0;

public:
    virtual std::string invocation(ToolInvocation const &invocation, std::string const &executable) = 0;

public:
    static void Print(std::string const &output);
};

}
}

#endif // !__pbxbuild_Formatter_h
