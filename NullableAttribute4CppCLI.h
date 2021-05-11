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
ref class NullableAttribute : Attribute {
private:
    using byte = unsigned __int8;
    using arraybyte = array<byte>^;
    using listbyte = System::Collections::Generic::List<byte>^;
    byte _Mode;
    arraybyte _Modes = nullptr;

public:
    property byte Mode {
public:
    byte get() { return _Mode; }
private:
    void set(byte value) { _Mode = value; }
    }
    property arraybyte Modes {
public:
    arraybyte get() { return _Modes; }
private:
    void set(arraybyte value) { _Modes = value; }
    }

public:
    NullableAttribute(byte mode) {
        Mode = mode;
    }

    template<class... Bytes>
    NullableAttribute(Bytes... modes) {
        Modes = ToManagedArray(gcnew System::Collections::Generic::List<byte>, modes...);
    }

    // Modesの生成用 Attributeを使うたびにgcnewを書かせたくないのでtemplate実装
    template<class... Bytes>
    arraybyte ToManagedArray(listbyte list, byte mode, Bytes... modes) {
        list->Add(mode);
        return ToManagedArray(list, modes...);
    }
    arraybyte ToManagedArray(listbyte list) {
        return list->ToArray();
    }

    /// <summary>For Debug</summary>
    System::String^ ToString() override {
        if (Modes == nullptr) {
            return System::String::Format("{0}", Mode);
        }
        else {
            return System::String::Format("({0}) ", Mode, System::String::Join(", ", Modes));
        }
    }

};
}
}
}
