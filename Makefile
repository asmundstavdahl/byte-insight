F_OUT = byte-insight
F_SRC = main.c
D_INSTALL = /usr/bin

all: build

build:
	gcc -o $(F_OUT) $(F_SRC)

install:
	cp $(F_OUT) $(D_INSTALL)/$(F_OUT)
