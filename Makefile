.PHONY: all clean

all: encoder.wasm encoder.wat

encoder.wasm: idna_tables-generated.h idna.c punycode.c
	emcc idna.c punycode.c -o encoder.wasm --no-entry -O3 \
		-s EXPORTED_FUNCTIONS='["_punycode_encode", "_punycode_get_input_ptr", "_punycode_get_output_ptr", "_idna_map", "_idna_get_input_ptr", "_idna_get_output_ptr"]' \
		-s IMPORTED_MEMORY -s TOTAL_STACK=0 -s TOTAL_MEMORY=196608

encoder.wat: encoder.wasm
	wasm2wat encoder.wasm > encoder.wat

clean:
	rm -f encoder.wat encoder.wasm
