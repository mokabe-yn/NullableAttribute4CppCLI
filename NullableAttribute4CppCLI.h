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
public ref class NullableAttribute : Attribute {
private:
    using byte = unsigned __int8;
    using arraybyte = array<byte>^;

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

    NullableAttribute(arraybyte modes) {
        Modes = modes;
    }

    //public NullableAttribute(params byte[] modes) => this.Modes = modes;

};
}
}
}
