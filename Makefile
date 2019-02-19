all: proto-gen
	mkdir -p build
	gcc test.c build/test.pb-c.c -Ibuild -lprotobuf-c -lprotobuf2json-c -ggdb -o build/test

proto-gen: test.proto
	mkdir -p build
	protoc-c --c_out=./build test.proto

clean:
	rm -rf ./build