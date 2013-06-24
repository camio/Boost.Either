.PHONY: run
run: build/test.exe
	build/test.exe

build/test.exe: src/test.cpp include/boost/either.hpp
	g++ -I../vc110-x64/odillo_meta/boost -Iinclude/ -std=c++11 src/test.cpp -o build/test.exe
