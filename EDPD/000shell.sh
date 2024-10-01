#!/bin/bash

TEMPLATE_FILE="../template.cpp"

for file in A B C D E F G H I J K L M N O P Q R S T U V W X Y Z; do
  cp "$TEMPLATE_FILE" "$file.cpp"
done