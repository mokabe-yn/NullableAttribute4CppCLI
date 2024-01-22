#pragma once

// no-hint or forget: 0
#define DISALLOWNULL  1
#define ALLOWNULL     2
#define NOTNULL  ::System::Runtime::CompilerServices::NullableAttribute(DISALLOWNULL)
#define NULLABLE ::System::Runtime::CompilerServices::NullableAttribute(ALLOWNULL)

#define NOTNULL_CONTEXT  ::System::Runtime::CompilerServices::NullableContextAttribute(DISALLOWNULL)
#define NULLABLE_CONTEXT ::System::Runtime::CompilerServices::NullableContextAttribute(ALLOWNULL)

#define NULLABLE_ARRAY(...) ::System::Runtime::CompilerServices::NullableAttribute( \
    gcnew ::cli::array<::System::Byte, 1>{ __VA_ARGS__ })


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
/// for nullable annotation.
/// see <seealso cref="https://github.com/dotnet/roslyn/blob/main/docs/features/nullable-metadata.md"/>.
/// </summary>
/// <remarks>
/// 0: oblivious, 1: notnull, 2: nullable.
/// </remarks>
public ref class NullableAttribute sealed : ::System::Attribute {
public:
    ::cli::array<::System::Byte, 1>^ NullableFlags;
    NullableAttribute(::cli::array<::System::Byte, 1>^ flags) :
        NullableFlags(flags) { }
    NullableAttribute(::System::Byte flag) :
        NullableFlags(gcnew ::cli::array<::System::Byte, 1>(1)) {
        NullableFlags[0] = flag;
    }
    /// <summary>For Debug</summary>
    System::String^ ToString() override {
        return ::System::String::Format("{0}", ::System::String::Join(", ",
            NullableFlags
        ));
    }
};
} // CompilerServices
} // Runtime
} // System
