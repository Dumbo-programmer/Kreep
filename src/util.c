#include "../include/util.h"

char* read_ascii_file(const char* path){
    FILE* file = fopen(path, "r");
    if(!file){
        printf("can't open file %s\n", path);
        
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buf = (char*) malloc(sizeof(char) * (size + 1));
    if(!buf){
        printf("couldn't allocate memory for respected file!\n");
    }
    fread(buf, 1, size, file);
    buf[size] = '\0';
    fclose(file);
    return buf;
}
uint8_t* read_binary_file(const char* path) {
	FILE* file = fopen(path, "rb");
	if (!file) {
		printf("Could not open file '%s'\n", path);
		return NULL;
	}

	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fseek(file, 0, SEEK_SET);

	uint8_t* buffer = (uint8_t*) malloc(sizeof(uint8_t) * size);
	fread(buffer, 1, size, file);
	fclose(file);

	return buffer;
}

void write_binary_file(const char* path, ByteBuffer* bb) {
	FILE* file = fopen(path, "wb");
	if (!file) {
		printf("Could not write to file '%s'\n", path);
		return;
	}

	fwrite(bb->buffer, 1, bb->ptr, file);
	fclose(file);
}

uint16_t read16(uint8_t* buffer, uint32_t index) {
	return (buffer[index] << 8) | (buffer[index + 1]);
}

uint32_t read32(uint8_t* buffer, uint32_t index) {
	return (buffer[index] << 24) | (buffer[index + 1] << 16) | 
		(buffer[index + 2] << 8) | (buffer[index + 3]);
