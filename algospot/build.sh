#!/bin/bash
builddir=".build"
rm -rf $builddir
rm run
meson $builddir && ninja -C $builddir && ln -s $builddir/run .
