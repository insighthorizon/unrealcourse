#!/bin/bash

#create tags for emaxs - enables jumping to definitions etc

rm -f TAGS
find -name "*.*" -print | xargs etags -a
