/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef __pbxproj_PBX_BaseGroup_h
#define __pbxproj_PBX_BaseGroup_h

#include <pbxproj/PBX/GroupItem.h>
#include <pbxproj/Context.h>

namespace pbxproj { namespace PBX {

class BaseGroup : public GroupItem {
public:
    typedef std::shared_ptr <BaseGroup> shared_ptr;

private:
    GroupItem::vector _children;

protected:
    BaseGroup(std::string const &isa, GroupItem::Type type);

public:
    inline GroupItem::vector const &children() const
    { return _children; }
    inline GroupItem::vector &children()
    { return _children; }

public:
    virtual bool parse(Context &context, plist::Dictionary const *dict);
};

} }

#endif  // !__pbxproj_PBX_BaseGroup_h
