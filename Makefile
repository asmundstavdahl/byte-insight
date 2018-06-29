F_OUT = byte-insight
F_SRC = main.c
D_INSTALL = /usr/bin
F_TEST_INPUT = /tmp/byte-insight-test-input

all: build

build:
	gcc -o $(F_OUT) $(F_SRC)

install:
	cp $(F_OUT) $(D_INSTALL)/$(F_OUT)

test:
	gcc -g -o $(F_OUT) $(F_SRC)
	bash -c "echo test >$(F_TEST_INPUT) && echo 'run <$(F_TEST_INPUT)' | gdb -quiet ./$(F_OUT)"
