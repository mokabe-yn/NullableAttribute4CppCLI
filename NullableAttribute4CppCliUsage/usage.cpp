#include "pch.h"
#include "NullableAttribute4CppCli.hpp"

namespace NullableAttribute4CppCliUsage {

using NullableAttribute = System::Runtime::CompilerServices::NullableAttribute;

// Nullableアノテーションを付加されるかの確認用
// 実際のクラスとしては機能しない
public ref class Class {
    using value = int;
    using ref = System::Object^;
public:
    [NULLABLE]
    property System::String^ Nullable {
        System::String^ get() { return nullptr; }
    }
    [NOTNULL]
    property System::String^ NotNull {
        System::String^ get() { return nullptr; }
    }
    property System::String^ Unknown {
        System::String^ get() { return nullptr; }
    }

    [NULLABLE_ARRAY(ALLOWNULL, ALLOWNULL)]
        property System::Action<ref>^ Multiple22 {
        System::Action<ref>^ get() { return nullptr; }
    }
    [NULLABLE_ARRAY(ALLOWNULL, ALLOWNULL, ALLOWNULL)]
    property System::Action<ref, ref>^ Multiple222 {
        System::Action<ref, ref>^ get() { return nullptr; }
    }
    [NULLABLE_ARRAY(DISALLOWNULL, ALLOWNULL, ALLOWNULL)]
        property System::Action<ref, ref>^ Multiple122 {
        System::Action<ref, ref>^ get() { return nullptr; }
    }
    [NULLABLE_ARRAY(ALLOWNULL, DISALLOWNULL, ALLOWNULL)]
        property System::Action<ref, ref>^ Multiple212 {
        System::Action<ref, ref>^ get() { return nullptr; }
    }
    [NULLABLE_ARRAY(ALLOWNULL, ALLOWNULL, DISALLOWNULL)]
        property System::Action<ref, ref>^ Multiple221 {
        System::Action<ref, ref>^ get() { return nullptr; }
    }
    property System::Action<ref, value>^ MultipleWithValueRefValue {
        System::Action<ref, value>^ get() { return nullptr; }
    }

    [returnvalue: NULLABLE]
    ref Method([NULLABLE] ref arg1, [NULLABLE] ref arg2) { return arg1; }
    ref MethodWithOtherAnnotation(ref arg1, ref arg2) { return arg1; }
};

}
