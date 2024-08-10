#!/bin/bash

TEMPLATE_FILE="template.cpp"

FOLDER_NAME="./$1"

if [ -z "$FOLDER_NAME" ]; then
  exit 1
fi

mkdir -p "$FOLDER_NAME"

for file in A B C D E F G; do
  cp "$TEMPLATE_FILE" "$FOLDER_NAME/${file}.cpp"
done


echo "$FOLDER_NAME フォルダーとファイルを作成しました。"