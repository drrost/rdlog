#!/bin/bash

APP_NAME="rdlog"
PATH_TO="/usr/local/bin/shared/"

# build
swift build

if [[ $? -ne 0 ]];
then
    echo "Build failed"
    exit 1
fi

# delete old
FULL_PATH="${PATH_TO}${APP_NAME}"
rm -f $FULL_PATH

# move new
mv "./.build/debug/${APP_NAME}" $FULL_PATH
