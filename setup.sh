#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "usage: $0 RoundName"
    exit 1
fi

ROUND=$1
TEMPLATE="default_snippet.cpp"
FILES=("a.cpp" "b.cpp" "c.cpp" "d.cpp" "e.cpp")

mkdir -p "$ROUND"

for file in "${FILES[@]}"; do
    cp "$TEMPLATE" "$ROUND/$file"
done

echo "$ROUND Setup Completed!"
