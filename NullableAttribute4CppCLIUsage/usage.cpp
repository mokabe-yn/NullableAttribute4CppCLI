#include "pch.h"

namespace NullableAttribute4CppCLIUsage {

// Nullableアノテーションを付加されるかの確認用
// 実際のクラスとしては機能しない
public ref class Class {
    using value = int;
    using ref = System::Object^;
public:
    property System::String^ Nullable {
        System::String^ get() { return nullptr; }
    }

    property System::String^ NotNull {
        System::String^ get() { return nullptr; }
    }
    property System::String^ Unknown {
        System::String^ get() { return nullptr; }
    }

    property System::Action<ref>^ Multiple22 {
        System::Action<ref>^ get() { return nullptr; }
    }
    property System::Action<ref, ref>^ Multiple222 {
        System::Action<ref, ref>^ get() { return nullptr; }
    }
    property System::Action<ref, ref>^ Multiple122 {
        System::Action<ref, ref>^ get() { return nullptr; }
    }
    property System::Action<ref, ref>^ Multiple212 {
        System::Action<ref, ref>^ get() { return nullptr; }
    }
    property System::Action<ref, ref>^ Multiple221 {
        System::Action<ref, ref>^ get() { return nullptr; }
    }
    property System::Action<ref, value>^ MultipleWithValueRefValue {
        System::Action<ref, value>^ get() { return nullptr; }
    }

    ref Method(ref arg1, ref arg2) { return arg1; }
    ref MethodWithOtherAnnotation(ref arg1, ref arg2) { return arg1; }
};

}
