# Trace C++ programs

## Find the symbol

```shell
$ strings a.out | grep debug
_ZN6Logger5debugEP3Bar
$ c++filt _ZN6Logger5debugEP3Bar
Logger::debug(Bar*)
```

## Figure out Memory Layout and Calling Convention

* For method, arg0 is `this` pointer
* vtable

## Problem

  https://github.com/grpc/grpc/issues/18365
