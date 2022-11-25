LCC=g++
WCC=x86_64-w64-mingw32-g++

ifneq ($(RELEASE), TRUE)
	CFLAGS=-Wall -Wextra -g -std=c++2a --shared -fPIC
else
	CFLAGS=-Wall -Wextra -O3 -std=c++2a -s --shared -fPIC
endif

all: linux windows

linux : double/quaternion.cpp double/quaternion.h
	$(LCC) $(CFLAGS) -o bin/quaternion.so double/quaternion.cpp
	
windows : double/quaternion.cpp double/quaternion.h
	$(WCC) $(CFLAGS) -o bin/quaternion.lib double/quaternion.cpp