using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;

namespace NullableAttribute4CppCLIProbe {
    class Program {
        static void Main(string[] args) {
            Console.WriteLine("Hello World!");

            Probe<object>();
        }


        static Dictionary<MemberInfo, object?> Probe<TargetType>(string? membername = null) {
            static object? GetNullableAttribute(MemberInfo member) {
                var atts = member.GetCustomAttributes(true);
                var att = atts[1];
                return atts.FirstOrDefault(a => a.GetType().FullName == "System.Runtime.CompilerServices.NullableAttribute");
            }

            Type t = typeof(TargetType);
            var members = t.GetMembers(
                System.Reflection.BindingFlags.Public |
                System.Reflection.BindingFlags.Instance |
                System.Reflection.BindingFlags.Static);

            if (membername is not null) {
                members = members
                    .Where(m => m.Name == membername)
                    .ToArray();
            }
            return new(members.Select(m => KeyValuePair.Create(m, GetNullableAttribute(m))));
        }


        class NullableMode {
            public byte Mode { get; init; }
            public byte[]? Modes { get; init; }
            public override string ToString() {
                if(Modes is null) {
                    return $"{Mode}";
                } else {
                    return $"({Mode}) {string.Join(", ", Modes)}";
                }
            }
        }
    }
}
