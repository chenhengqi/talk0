# Trace Python programs

```shell
$ docker run -it python:3.10 bash
$ readelf -n /usr/bin/python3

Displaying notes found in: .note.gnu.build-id
  Owner                Data size        Description
  GNU                  0x00000014       NT_GNU_BUILD_ID (unique build ID bitstring)
    Build ID: f902f8a561c3abdb9c8d8c859d4243bd8c3f928f

Displaying notes found in: .note.ABI-tag
  Owner                Data size        Description
  GNU                  0x00000010       NT_GNU_ABI_TAG (ABI version tag)
    OS: Linux, ABI: 3.2.0

Displaying notes found in: .note.stapsdt
  Owner                Data size        Description
  stapsdt              0x00000033       NT_STAPSDT (SystemTap probe descriptors)
    Provider: python
    Name: audit
    Location: 0x00000000004252be, Base: 0x0000000000883cd0, Semaphore: 0x000000000093a1ce
    Arguments: 8@%rbp 8@%r12
  stapsdt              0x00000030       NT_STAPSDT (SystemTap probe descriptors)
    Provider: python
    Name: gc__done
    Location: 0x0000000000428aea, Base: 0x0000000000883cd0, Semaphore: 0x000000000093a1c8
    Arguments: -8@%r14
  stapsdt              0x00000036       NT_STAPSDT (SystemTap probe descriptors)
    Provider: python
    Name: gc__start
    Location: 0x0000000000428b5d, Base: 0x0000000000883cd0, Semaphore: 0x000000000093a1c6
    Arguments: -4@112(%rsp)
  stapsdt              0x0000003b       NT_STAPSDT (SystemTap probe descriptors)
    Provider: python
    Name: line
    Location: 0x000000000042ccef, Base: 0x0000000000883cd0, Semaphore: 0x000000000093a1c4
    Arguments: 8@%r15 8@%rax -4@%r14d
  stapsdt              0x00000045       NT_STAPSDT (SystemTap probe descriptors)
    Provider: python
    Name: function__entry
    Location: 0x000000000042daa2, Base: 0x0000000000883cd0, Semaphore: 0x000000000093a1b8
    Arguments: 8@%r13 8@%r14 -4@%eax
  stapsdt              0x00000046       NT_STAPSDT (SystemTap probe descriptors)
    Provider: python
    Name: function__return
    Location: 0x000000000042dc51, Base: 0x0000000000883cd0, Semaphore: 0x000000000093a1ba
    Arguments: 8@%r12 8@%r13 -4@%eax
  stapsdt              0x00000047       NT_STAPSDT (SystemTap probe descriptors)
    Provider: python
    Name: import__find__load__done
    Location: 0x00000000004373b7, Base: 0x0000000000883cd0, Semaphore: 0x000000000093a1cc
    Arguments: 8@%rax -4@%ecx
  stapsdt              0x00000040       NT_STAPSDT (SystemTap probe descriptors)
    Provider: python
    Name: import__find__load__start
    Location: 0x00000000004373c5, Base: 0x0000000000883cd0, Semaphore: 0x000000000093a1ca
    Arguments: 8@%rax
```

## References

  https://docs.python.org/3/howto/instrumentation.html#available-static-markers
