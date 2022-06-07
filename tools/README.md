# Tools

```shell
$ bpftool prog
1421: cgroup_sock_addr  name connect4  tag 6106875feedaecef  gpl recursion_misses 111473450971243
        loaded_at 2022-06-01T18:03:32+0800  uid 0
        xlated 72B  not jited  memlock 4096B  map_ids 1853
        btf_id 431

$ bpftool map
1853: array  name kprobe_b.rodata  flags 0x480
        key 4B  value 91B  max_entries 1  memlock 8192B
        btf_id 431  frozen

$ bpftool map dump id 1853
[{
        "value": {
            ".rodata": [{
                    "connect4.____fmt": [99,111,110,110,101,99,116,32,116,111,58,32,37,100,32,37,120,10,0
                    ]
                },{
                    "____do_unlinkat.____fmt": [75,80,82,79,66,69,32,69,78,84,82,89,32,112,105,100,32,61,32,37,100,44,32,102,105,108,101,110,97,109,101,32,61,32,37,115,10,0
                    ]
                },{
                    "____do_unlinkat_exit.____fmt": [75,80,82,79,66,69,32,69,88,73,84,58,32,112,105,100,32,61,32,37,100,44,32,114,101,116,32,61,32,37,108,100,10,0
                    ]
                }
            ]
        }
    }
]

$ bpftool btf dump file /sys/kernel/btf/vmlinux
[1] INT 'long unsigned int' size=8 bits_offset=0 nr_bits=64 encoding=(none)
[2] CONST '(anon)' type_id=1
[3] VOLATILE '(anon)' type_id=1
[4] ARRAY '(anon)' type_id=1 index_type_id=21 nr_elems=2
[5] PTR '(anon)' type_id=8
[6] CONST '(anon)' type_id=5
[7] INT 'char' size=1 bits_offset=0 nr_bits=8 encoding=(none)
...

$ bpftool btf dump file /sys/kernel/btf/vmlinux format c > vmlinux.h

$ bpftrace -e 'k:vfs_* { @count[probe] = count(); }'
Attaching 64 probes...
^C

@count[kprobe:vfs_fadvise]: 7
@count[kprobe:vfs_write]: 102
@count[kprobe:vfs_lock_file]: 135
@count[kprobe:vfs_statx_fd]: 643
@count[kprobe:vfs_statx]: 681
@count[kprobe:vfs_readlink]: 1049
@count[kprobe:vfs_open]: 2238
@count[kprobe:vfs_getattr_nosec]: 2554
@count[kprobe:vfs_read]: 2646
```
