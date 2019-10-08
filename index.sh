#!/bin/sh

find . -name "*.h" -o -name "*.cpp" > cscope.files
cscope -Rbkq -i cscope.files
# ctags -R
ctags -R --c++-kinds=+p --fields=+iaS --extra=+q
