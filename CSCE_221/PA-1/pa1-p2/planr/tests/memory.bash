#!/bin/bash

set -e -o pipefail

TESTCASE="${0##*/}"

SRCDIR="$(planr config srcdir)"
TMPDIR="$(pwd)/${TESTCASE}"
TESTDIR="$(planr config configdir)/tests"

cleanup_testdir() {
    cd ..
    rm -rf "$TMPDIR"
}

mkdir -p "$TMPDIR"
cd "$TMPDIR"
cp -R "$SRCDIR"/* .

trap 'cleanup_testdir' ERR

###########################################

MAKEFILE=sanitizer-test-makefile

make -f "${MAKEFILE}"

for i in {0..5}; do
    make -f "${MAKEFILE}" run
done

cleanup_testdir
exit 0