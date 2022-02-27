# rdlog

A simple log server that takes messages by a socket connection. The server is 
written in pure C. There is some infrastructural Swift code but it needs only
to support building as a Swift package.

## How to execute
```shell
swift build
./.build/debug/rdlog 7778
```

or run `./run.sh` that does the same.

## Client, how to add

### `Package.swift` file add:
```swift
// Package dependencies:
.package(
    name: "rdlog",
    url: "git@github.com:drrost/rdlog.git",
    .exact("0.0.1")
)

// Target dependencies:
dependencies: [
    .product(name: "rdlog_client", package: "rdlog")
]
```

## Useful findings
* Only public API should have prfeixes.

### Swift
* Swift string to C string `makeCString(from:)`.

### C
* CFString to C string `cstr_from_cf`.
* Call Swfit code from C (via Obj-C) `path_for_res`.
* Check if a string has a suffix`rd_str_has_suffix`.

## TODO

1. Get rid off Swift targets. For now we use Swift targets only to obtain
resources since SPM can't work with resources in C-based packages.
2. Move `rd_str_has_suffix` to `rdlib`.
3. Create `rd_str_has_prefix` in `rdlib`.
4. Move DB path and name to the application's settings. That means that the
application should have a settings storing mechanism.

## Things should be tested automatically
* Starting the server in a new environment.
* Starting the server in the enveironment it already run.
* Send a log message to the server.
