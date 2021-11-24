#!/bin/bash -ex

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd)"
SOURCE_DIR=$(realpath ${DIR}/..)
BUILD_DIR=$(realpath ${DIR}/../_build)
mkdir -p ${BUILD_DIR}

scl enable devtoolset-9 beef-dev211 -- cmake -S ${SOURCE_DIR} -B ${BUILD_DIR}
scl enable devtoolset-9 beef-dev211 -- cmake --build ${BUILD_DIR}
