#pragma once

namespace System {
namespace Runtime {
namespace CompilerServices {


[AttributeUsage(AttributeTargets::Class | AttributeTargets::Event | AttributeTargets::Field |
    AttributeTargets::GenericParameter | AttributeTargets::Module | AttributeTargets::Parameter |
    AttributeTargets::Property | AttributeTargets::ReturnValue,
    AllowMultiple = false)]
/// <summary>
/// <para>
/// コンパイラが認識するNullableアノテーションをCCLIから使用できるように、
/// 明示的に<see cref="NullableAttribute"/>を実装します。
/// C#コンパイラから参照されたくないのでアクセスレベルをinternalにしている。
/// </para>
/// </summary>
ref class NullableAttribute sealed : Attribute {
private:
    using byte = unsigned __int8;
    using arraybyte = array<byte>^;
    using listbyte = System::Collections::Generic::List<byte>^;

public:
    const arraybyte NullableFlags;
    NullableAttribute(byte flag) :
        NullableFlags(gcnew array<byte>{flag}) { }

    // C#コンパイラからのアクセス用
    NullableAttribute(arraybyte flags) :
        NullableFlags(flags) {}


internal:
    // C++コンパイラからのアクセス用
    template<class... Bytes>
    NullableAttribute(Bytes... flags) {
        NullableFlags = ToManagedArray(gcnew System::Collections::Generic::List<byte>, modes...);
    }

private:
    // Modesの生成用 Attributeを使うたびにgcnewを書かせたくないのでtemplate実装
    template<class... Bytes>
    arraybyte ToManagedArray(listbyte list, byte mode, Bytes... modes) {
        list->Add(mode);
        return ToManagedArray(list, modes...);
    }
    arraybyte ToManagedArray(listbyte list) {
        return list->ToArray();
    }

public:
    /// <summary>For Debug</summary>
    System::String^ ToString() override {
        return System::String::Format("{0} ", System::String::Join(", ", NullableFlags));
    }

};
}
}
}
