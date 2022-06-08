

https://github.com/torvalds/linux/blob/v5.18/kernel/trace/bpf_trace.c#L157-L218

```c
static __always_inline int
bpf_probe_read_user_common(void *dst, u32 size, const void __user *unsafe_ptr)
{
	int ret;

	ret = copy_from_user_nofault(dst, unsafe_ptr, size);
	if (unlikely(ret < 0))
		memset(dst, 0, size);
	return ret;
}

BPF_CALL_3(bpf_probe_read_user, void *, dst, u32, size,
	   const void __user *, unsafe_ptr)
{
	return bpf_probe_read_user_common(dst, size, unsafe_ptr);
}

const struct bpf_func_proto bpf_probe_read_user_proto = {
	.func		= bpf_probe_read_user,
	.gpl_only	= true,
	.ret_type	= RET_INTEGER,
	.arg1_type	= ARG_PTR_TO_UNINIT_MEM,
	.arg2_type	= ARG_CONST_SIZE_OR_ZERO,
	.arg3_type	= ARG_ANYTHING,
};

static __always_inline int
bpf_probe_read_user_str_common(void *dst, u32 size,
			       const void __user *unsafe_ptr)
{
	int ret;

	/*
	 * NB: We rely on strncpy_from_user() not copying junk past the NUL
	 * terminator into `dst`.
	 *
	 * strncpy_from_user() does long-sized strides in the fast path. If the
	 * strncpy does not mask out the bytes after the NUL in `unsafe_ptr`,
	 * then there could be junk after the NUL in `dst`. If user takes `dst`
	 * and keys a hash map with it, then semantically identical strings can
	 * occupy multiple entries in the map.
	 */
	ret = strncpy_from_user_nofault(dst, unsafe_ptr, size);
	if (unlikely(ret < 0))
		memset(dst, 0, size);
	return ret;
}

BPF_CALL_3(bpf_probe_read_user_str, void *, dst, u32, size,
	   const void __user *, unsafe_ptr)
{
	return bpf_probe_read_user_str_common(dst, size, unsafe_ptr);
}

const struct bpf_func_proto bpf_probe_read_user_str_proto = {
	.func		= bpf_probe_read_user_str,
	.gpl_only	= true,
	.ret_type	= RET_INTEGER,
	.arg1_type	= ARG_PTR_TO_UNINIT_MEM,
	.arg2_type	= ARG_CONST_SIZE_OR_ZERO,
	.arg3_type	= ARG_ANYTHING,
};
```

https://github.com/torvalds/linux/blob/v5.18/mm/maccess.c#L153-L191

```c
/**
 * strncpy_from_user_nofault: - Copy a NUL terminated string from unsafe user
 *				address.
 * @dst:   Destination address, in kernel space.  This buffer must be at
 *         least @count bytes long.
 * @unsafe_addr: Unsafe user address.
 * @count: Maximum number of bytes to copy, including the trailing NUL.
 *
 * Copies a NUL-terminated string from unsafe user address to kernel buffer.
 *
 * On success, returns the length of the string INCLUDING the trailing NUL.
 *
 * If access fails, returns -EFAULT (some data may have been copied
 * and the trailing NUL added).
 *
 * If @count is smaller than the length of the string, copies @count-1 bytes,
 * sets the last byte of @dst buffer to NUL and returns @count.
 */
long strncpy_from_user_nofault(char *dst, const void __user *unsafe_addr,
			      long count)
{
	long ret;

	if (unlikely(count <= 0))
		return 0;

	pagefault_disable();
	ret = strncpy_from_user(dst, unsafe_addr, count);
	pagefault_enable();

	if (ret >= count) {
		ret = count;
		dst[ret - 1] = '\0';
	} else if (ret > 0) {
		ret++;
	}

	return ret;
}
```

```shell
$ bpftrace -e 'tracepoint:exceptions:page_fault_user /comm == "a.out"/ { @count[args->error_code] = count(); }'
```

## References

* https://www.intel.com/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-software-developer-vol-3a-part-1-manual.pdf

* https://en.wikipedia.org/wiki/Page_fault
