CC=g++
CFLAGS=

cpp_source_files = $(wildcard src/*.cpp)

build/run.bin: src/main.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@	

.PHONY: clean test
clean:
	rm -r build

test: 
	echo "[TEST] starting test"

