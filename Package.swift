// swift-tools-version:5.5

import PackageDescription

let package = Package(
    name: "rdlog",
    platforms: [
        .macOS(.v10_11),
    ],
    products: [
        .executable(
            name: "rdlog",
            targets: ["rdlog"]
        ),
        .library(
            name: "rdlog_client",
            targets: ["rdlog_client"]
        ),
        .library(
            name: "reswrapper",
            targets: ["reswrapper"]
        )
    ],
    dependencies: [
        .package(
            name: "rdlib",
            url: "git@github.com:drrost/rdlib.git",
            .exact("0.0.6")
        ),
        .package(
            name: "JSON",
            url: "git@github.com:drrost/c-json.git",
            .exact("0.0.3")
        ),
        .package(
            name: "MemUtils",
            url: "git@github.com:drrost/c-memutils.git",
            .exact("0.0.2")
        ),
        .package(
            name: "RDFoundation",
            url: "git@github.com:drrost/swift-extensions-foundation.git",
            .exact("1.3.1")
        )
    ],
    targets: [
        // Server
        .target(
            name: "rdlog",
            dependencies: ["rdlib", "JSON", "reswrapper", "MemUtils"],
            publicHeadersPath: "inc",
            cSettings: [
                .headerSearchPath("inc"),
                .headerSearchPath("libs/json/inc"),
                // Enable only during development
                .unsafeFlags(
                    ["-std=c11", "-Wall", "-Wextra", "-Werror", "-Wpedantic"]
                )
                // TODO: Add -Weverything, replace `-Wpedantic' with `pedantic'.
                // Details: https://clang.llvm.org/docs/UsersManual.html
            ]
        ),
        .testTarget(
            name: "rdlogTests",
            dependencies: ["rdlog", "MemUtils"]
        ),

        // Client
        .target(
            name: "rdlog_client",
            dependencies: ["rdlib"]
        ),
        .testTarget(
            name: "rdlogClientTests",
            dependencies: ["rdlog_client"]
        ),
        .target(
            name: "reswrapper",
            dependencies: ["RDFoundation"],
            resources: [
                .process("Resources")
            ]
        )
    ]
)

