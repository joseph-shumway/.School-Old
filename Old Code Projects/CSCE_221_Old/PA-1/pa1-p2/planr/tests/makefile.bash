#!/bin/bash

set -e -o pipefail

TESTCASE="${0##*/}"

SRCDIR="$(planr config srcdir)"
TESTDIR="$(planr config configdir)/tests"

TMPDIR="$(pwd)/${TESTCASE}"

cleanup_testdir() {
    cd ..
    rm -rf "$TMPDIR"
}

mkdir -p "$TMPDIR"
cd "$TMPDIR"
cp -R "$SRCDIR"/* .

trap 'cleanup_testdir' ERR

make clean
make all
make run

if [[ ! -e "${TMPDIR}/test" ]]; then
    echo "Can't find test executable"
    cleanup_testdir
    exit 1
fi

cleanup_testdir
exit 0
