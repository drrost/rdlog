# rdlog Swit Client

This target contains classes that allow fast and useful send messages to `rdlog`
server.

## How to

### Add to a package

```swift
// Snippet to add the package/target.
```

### Add to an Xcode project

SSH git link to the package.

### Use

```swift
import rdlog_client_swift

let logger = RDLogManager.getLogger()
logger.log(.info, "test message")
```
