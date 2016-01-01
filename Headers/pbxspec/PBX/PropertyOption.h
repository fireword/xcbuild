/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef __pbxspec_PBX_PropertyOption_h
#define __pbxspec_PBX_PropertyOption_h

#include <pbxsetting/pbxsetting.h>
#include <libutil/Base.h>
#include <plist/plist.h>

namespace pbxspec { namespace PBX {

class BuildSystem;
class Tool;

class PropertyOption {
public:
    typedef std::shared_ptr <PropertyOption> shared_ptr;
    typedef std::vector <shared_ptr> vector;
    typedef std::unordered_map <std::string, size_t> used_map;

    static void Insert(vector *options, used_map *used, shared_ptr const &option)
    {
        auto it = used->find(option->name());
        if (it != used->end()) {
            (*options)[it->second] = option;
        } else {
            used->insert({ option->name(), options->size() });
            options->push_back(option);
        }
    }

protected:
    std::string             _name;
    std::string             _displayName;
    std::string             _type;
    std::string             _uiType;
    std::string             _category;
    std::string             _description;
    std::string             _condition;
    std::string             _appearsAfter;
    std::string             _inputInclusions;
    std::string             _outputDependencies;
    bool                    _basic;
    bool                    _commonOption;
    bool                    _avoidEmptyValues;
    std::string             _commandLineCondition;
    pbxsetting::Value       _commandLineFlag;
    pbxsetting::Value       _commandLineFlagIfFalse;
    pbxsetting::Value       _commandLinePrefixFlag;
    bool                    _hasCommandLinePrefixFlag;
    plist::Object          *_commandLineArgs;
    plist::Object          *_additionalLinkerArgs;
    plist::Object          *_defaultValue;
    plist::Object          *_allowedValues;
    plist::Object          *_values;
    libutil::string_vector  _architectures;
    libutil::string_vector  _fileTypes;
    libutil::string_vector  _conditionFlavors;
    libutil::string_vector  _supportedVersionRanges;
    bool                    _isInputDependency;
    bool                    _isCommandInput;
    bool                    _isCommandOutput;
    bool                    _outputsAreSourceFiles;
    bool                    _avoidMacroDefinition;
    bool                    _flattenRecursiveSearchPathsInValue;
    pbxsetting::Value       _setValueInEnvironmentVariable;

protected:
    friend class BuildSystem;
    friend class BuildSettings;
    friend class Tool;
    PropertyOption();

public:
    ~PropertyOption();

public:
    inline std::string const &name() const
    { return _name; }
    inline std::string const &displayName() const
    { return _displayName; }
    inline std::string const &category() const
    { return _category; }
    inline std::string const &description() const
    { return _description; }

public:
    inline std::string const &type() const
    { return _type; }
    inline std::string const &uiType() const
    { return _uiType; }

public:
    inline bool basic() const
    { return _basic; }
    inline bool commonOption() const
    { return _commonOption; }

public:
    inline std::string const &condition() const
    { return _condition; }
    inline std::string const &appearsAfter() const
    { return _appearsAfter; }

public:
    inline libutil::string_vector const &architectures() const
    { return _architectures; }

public:
    inline bool avoidEmptyValues() const
    { return _avoidEmptyValues; }
    inline plist::Object const *defaultValue() const
    { return _defaultValue; }
    inline plist::Object const *allowedValues() const
    { return _allowedValues; }
    inline plist::Object const *values() const
    { return _values; }

public:
    inline std::string const &commandLineCondition() const
    { return _commandLineCondition; }
    inline plist::Object const *commandLineArgs() const
    { return _commandLineArgs; }
    inline pbxsetting::Value const &commandLineFlag() const
    { return _commandLineFlag; }
    inline pbxsetting::Value const &commandLineFlagIfFalse() const
    { return _commandLineFlagIfFalse; }
    inline pbxsetting::Value const &commandLinePrefixFlag() const
    { return _commandLinePrefixFlag; }
    inline bool hasCommandLinePrefixFlag() const
    { return _hasCommandLinePrefixFlag; }

public:
    inline plist::Object const *additionalLinkerArgs() const
    { return _additionalLinkerArgs; }

public:
    inline bool isCommandInput() const
    { return _isCommandInput; }
    inline bool isCommandOutput() const
    { return _isCommandOutput; }

public:
    inline std::string const &inputInclusions() const
    { return _inputInclusions; }
    inline std::string const &outputDependencies() const
    { return _outputDependencies; }

public:
    inline bool outputsAreSourceFiles() const
    { return _outputsAreSourceFiles; }

public:
    inline libutil::string_vector const &fileTypes() const
    { return _fileTypes; }

public:
    inline libutil::string_vector const &conditionFlavors() const
    { return _conditionFlavors; }

public:
    inline libutil::string_vector const &supportedVersionRanges() const
    { return _supportedVersionRanges; }

public:
    inline bool isInputDependency() const
    { return _isInputDependency; }

public:
    inline bool avoidMacroDefinition() const
    { return _avoidMacroDefinition; }

public:
    inline bool flattenRecursiveSearchPathsInValue() const
    { return _flattenRecursiveSearchPathsInValue; }

public:
    inline pbxsetting::Value const &setValueInEnvironmentVariable() const
    { return _setValueInEnvironmentVariable; }

public:
    pbxsetting::Setting defaultSetting(void) const;
    pbxsetting::Value defaultPropertyValue(void) const;

protected:
    bool parse(plist::Dictionary const *dict);

public:
    static PropertyOption::shared_ptr Create(plist::Dictionary const *dict);
};

} }

#endif  // !__pbxspec_PBX_PropertyOption_h
