# NullableAttribute4CppCLI

C#8 で導入された Null非許容型の機能をC++/CLIで作成したプロジェクトでも利用できるようにする。

提供するファイルは[NullableAttribute4CppCLI.h](NullableAttribute4CppCLI.h)の1つだけで、
この.hファイルを各cppファイルから #include することを想定している。

想定する開発環境は Visual Studio 2019 の .NET5。

# 参照
[C#向けのNullableAttribute](https://github.com/epsitec/nullable-type-reflection)を
解説しているリポジトリを参考にしてる。
便利に使えそうだったのでC++/CLI向けに1から書き直した。

(RoslynのNullableAttribute実装)[https://github.com/dotnet/roslyn/blob/main/docs/features/nullable-metadata.md]