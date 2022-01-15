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
            targets: ["rdlog"]),
        .library(
            name: "reswrapper",
            targets: ["reswrapper"])
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
        )
    ],
    targets: [
        .target(
            name: "rdlog",
            dependencies: ["rdlib", "JSON", "reswrapper"],
            resources: [
                .process("Resources")
            ],
            publicHeadersPath: "inc",
            cSettings: [
                .headerSearchPath("inc"),
                .headerSearchPath("libs/json/inc"),
                // Enable only during development
//                .unsafeFlags(
//                    ["-std=c11", "-Wall", "-Wextra", "-Werror", "-Wpedantic"]
//                )
                // TODO: Add -Weverything, replace `-Wpedantic' with `pedantic'.
                // Details: https://clang.llvm.org/docs/UsersManual.html
            ]
        ),
        .testTarget(
            name: "rdlogTests",
            dependencies: ["rdlog", "MemUtils"]),
        .target(
            name: "reswrapper",
            dependencies: [],
            publicHeadersPath: "inc",
            cSettings: [
                .headerSearchPath("."),
            ]
//            resources: [
//                .process("Resources")
//            ],
        )
    ]
)
