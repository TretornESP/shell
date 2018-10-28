#include "system.h"

unsigned char *textmemptr;
int attrib = 0x0F;
int csr_x = 0, csr_y = 0;

void init_video() {
	textmemptr = (unsigned char*) 0xB8000;
	return;
}

void move_csr(void) {
	    unsigned temp = csr_y * 80 + csr_x;

	    //outportb(0x3D4, 14);
	    //outportb(0x3D5, temp >> 8);
	    //outportb(0x3D4, 15);
	    //outportb(0x3D5, temp);
}

void pc(unsigned char c) {
	*textmemptr = c;
	textmemptr += 2;
}

void p(char* string) {
	for (int i = 0; ; i++) {
		if (string[i]=='\0') return;
		pc(string[i]);
	}
}
