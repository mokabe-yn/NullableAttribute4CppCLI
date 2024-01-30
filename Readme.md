# NullableAttribute4CppCli

C#8 で導入された Null非許容型の機能をC++/CLIで作成したプロジェクトでも利用できるようにする。

提供するファイルは[NullableAttribute4CppCli.hpp](NullableAttribute4CppCli.hpp)の1つだけで、
この.hファイルを各cppファイルから #include することを想定している。

想定する開発環境は Visual Studio 2019 or later。
.NET Framework 4.x 用にバックポートした Attribute class を提供。
.NET Core 系列 (.NET Core 3.1 or .NET 5 or later)ならマクロのみ提供。


# 参照
[C#向けのNullableAttribute](https://github.com/epsitec/nullable-type-reflection)を
解説しているリポジトリを参考にしてる。
便利に使えそうだったのでC++/CLI向けに1から書き直した。

(RoslynのNullableAttribute実装)[https://github.com/dotnet/roslyn/blob/main/docs/features/nullable-metadata.md]
