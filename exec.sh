#!/bin/sh
if [ -d /usr/local/include ]; then
	echo "DIRECTORY EXISTS."
else
	mkdir /usr/local/include
	echo "DIRECTORY CREATED."
fi
cp simple_csv.h simple_csv.cpp /usr/local/include/
OUT=$(g++ --version 2>/dev/null)
if [ "$OUT" = "" ]; then
	echo "You must install g++"
else
	g++ -o simple_csv -std=c++20 main.cpp
	./simple_csv
fi
