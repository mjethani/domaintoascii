.PHONY: all clean

all: encoder.wasm encoder.wat

encoder.wasm: idna.c punycode.c
	emcc idna.c punycode.c -o encoder.wasm --no-entry -O3 \
		-s EXPORTED_FUNCTIONS='["_punycode_encode", "_punycode_get_input_ptr", "_punycode_get_output_ptr"]' \
		-s IMPORTED_MEMORY -s TOTAL_STACK=21536 -s TOTAL_MEMORY=65536

encoder.wat: encoder.wasm
	wasm2wat encoder.wasm > encoder.wat

clean:
	rm -f encoder.wat encoder.wasm
