#!/bin/bash -ex

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd)"
SOURCE_DIR=$(realpath ${DIR}/..)
BUILD_DIR=$(realpath ${DIR}/../_build)

scl enable devtoolset-9 beef-dev211 -- ${BUILD_DIR}/qt-sandbox -platform vnc:size=1024x768
