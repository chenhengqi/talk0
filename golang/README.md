# Trace Go programs

```shell
$ strings hello16 | grep hello
main.hello
```

```shell
$ gdb --args ./hello16 hello world
(gdb) b main.hello
Breakpoint 1 at 0x497660: file /home/src/main.go, line 9.
(gdb) r
Thread 1 "hello16" hit Breakpoint 1, main.hello (s=..., ss=...) at /home/src/main.go:9
9       func hello(s string, ss string) {
(gdb) info args
s = <optimized out>
ss = <optimized out>
(gdb) info registers
rax            0x7fffffffe2b9      140737488347833
rbx            0x7fffffffe2b3      140737488347827
rcx            0x5                 5
rdx            0xc000010180        824633786752
rsi            0x5                 5
rdi            0x537c18            5471256
rbp            0xc000078f78        0xc000078f78
rsp            0xc000078f50        0xc000078f50
r8             0x1                 1
r9             0x8                 8
...
rip            0x497660            0x497660 <main.hello>
eflags         0x202               [ IF ]
cs             0x33                51
ss             0x2b                43
...
(gdb) x /5dg 0xc000078f50
0xc000078f50:   4814783 140737488347827
0xc000078f60:   5       140737488347833
0xc000078f70:   5
```

```shell
$ gdb --args ./hello17 hello world
(gdb) b main.hello
Breakpoint 1 at 0x47e300: file /home/src/main.go, line 9.
(gdb) r
Thread 1 "hello17" hit Breakpoint 1, main.hello (s=..., ss=...) at /home/src/main.go:9
9       func hello(s string, ss string) {
(gdb) info args
s = 0x7fffffffe2b3 "hello"
ss = 0x485360 "\001\000\000\000"
(gdb) info registers
rax            0x7fffffffe2b3      140737488347827
rbx            0x5                 5
rcx            0x7fffffffe2b9      140737488347833
rdx            0xc000010180        824633786752
rsi            0x1                 1
rdi            0x5                 5
rbp            0xc000078f70        0xc000078f70
rsp            0xc000078f48        0xc000078f48
r8             0x1                 1
r9             0x8                 8
...
rip            0x47e300            0x47e300 <main.hello>
eflags         0x202               [ IF ]
cs             0x33                51
ss             0x2b                43
...
(gdb) x /5dg 0xc000078f48
0xc000078f48:   4711461 0
0xc000078f58:   4283685 4739936
0xc000078f68:   824633721248
(gdb)
```

## Reference

  https://go.googlesource.com/go/+/refs/heads/dev.regabi/src/cmd/compile/internal-abi.md
