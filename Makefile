F_OUT = byte-insight
F_SRC = main.c utf8.c ascii.c printing.c
D_INSTALL = /usr/bin
F_TEST_INPUT = /tmp/byte-insight-test-input

all: build

build:
	gcc -o $(F_OUT) $(F_SRC)

install:
	cp $(F_OUT) $(D_INSTALL)/$(F_OUT)

test: build-generator
	gcc -g -o $(F_OUT) $(F_SRC)
	###
	## Test basic usage…
	###
	bash -c "echo test >$(F_TEST_INPUT) && echo 'run <$(F_TEST_INPUT)' | gdb -quiet ./$(F_OUT)"
	###
	## Test 0..255
	###
	./generator >$(F_TEST_INPUT)
	bash -c "echo 'run <$(F_TEST_INPUT)' | gdb -quiet ./$(F_OUT)"
	###
	## Test 255..0
	###
	./generator reverse >$(F_TEST_INPUT)
	bash -c "echo 'run <$(F_TEST_INPUT)' | gdb -quiet ./$(F_OUT)"

test-utf8: test
	###
	## Test UTF-8…
	###
	bash -c "echo 'Æ e ÅsmuŊ' >$(F_TEST_INPUT) && echo 'run <$(F_TEST_INPUT)' | gdb -quiet ./$(F_OUT)"
	###
	## Test invalid UTF-8… (0x85 should wrap to extended ASCII)
	###
	bash -c "echo -e '\xc3\x85\x85\x85\x85\x85\x85\x85' >$(F_TEST_INPUT) && echo 'run <$(F_TEST_INPUT)' | gdb -quiet ./$(F_OUT)"

build-generator:
	gcc -o generator generator.c
