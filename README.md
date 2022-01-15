# rdlog

A log server.

## How to execute
```shell
swift build
./.build/debug/rdlog 7778
```

## Useful findings

### Swift
* Swift string to C string `makeCString(from:)`.

### C
* CFString to C string `cstr_from_cf`.
* Call Swfit code from C (via Obj-C) `path_for_res`.
* Check if a string has a suffix`rd_str_has_suffix`.

## TODO

1. Get rid off Swift packages. For now we use Swift packages only to obtain
resources since SPM can't work with resources in C-based packages.
2. Move `rd_str_has_suffix` to `rdlib`.
3. Create `rd_str_has_prefix` in `rdlib`.
