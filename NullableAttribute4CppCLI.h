#pragma once

// no-hint or forget: 0
#define DISALLOWNULL  1
#define ALLOWNULL     2
#define NOTNULL  ::System::Runtime::CompilerServices::NullableAttribute(DISALLOWNULL)
#define NULLABLE ::System::Runtime::CompilerServices::NullableAttribute(ALLOWNULL)

#define NOTNULL_CONTEXT  ::System::Runtime::CompilerServices::NullableContextAttribute(DISALLOWNULL)
#define NULLABLE_CONTEXT ::System::Runtime::CompilerServices::NullableContextAttribute(ALLOWNULL)


namespace System {
namespace Runtime {
namespace CompilerServices {

[
    ::System::AttributeUsageAttribute(
        ::System::AttributeTargets::Class |
        ::System::AttributeTargets::Event |
        ::System::AttributeTargets::Field |
        ::System::AttributeTargets::GenericParameter |
        ::System::AttributeTargets::Module |
        ::System::AttributeTargets::Parameter |
        ::System::AttributeTargets::Property |
        ::System::AttributeTargets::ReturnValue |
        static_cast<::System::AttributeTargets>(0),
        AllowMultiple = false)
]
/// <summary>
/// <para>
/// コンパイラが認識するNullableアノテーションをCLIから使用できるように、
/// 明示的に<see cref="NullableAttribute"/>を実装します。
/// C#コンパイラから参照されたくないのでアクセスレベルをinternalにしている。
/// </para>
/// </summary>
ref class NullableAttribute sealed : ::System::Attribute {
public:
    ::cli::array<::System::Byte, 1>^ const NullableFlags;
    NullableAttribute(::cli::array<::System::Byte, 1>^ flags) :
        NullableFlags(flags) { }
    NullableAttribute(::System::Byte flag) :
        NullableFlags(gcnew ::cli::array<::System::Byte, 1>(1)) {
        NullableFlags[0] = flag;
    }

public:
    /// <summary>For Debug</summary>
    System::String^ ToString() override {
        auto strs = gcnew ::cli::array<::System::String^>(this->NullableFlags->Length);
        static auto fmt = gcnew ::System::String("{0}");
        for (int i = 0; i < this->NullableFlags->Length; ++i) {
            strs[i] = ::System::String::Format(fmt, this->NullableFlags[i]);
        }
        return System::String::Format("{0} ", ::System::String::Join(", ",
            NullableFlags
        ));
    }
};
} // CompilerServices
} // Runtime
} // System
