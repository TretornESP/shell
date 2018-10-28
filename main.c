#include "system.h"

int main(void)
{
    //Prints a "X" on the upper-left corner
	init_video();
	move_csr();
	p("XABI\0");
	while(1){}
	return 1;

}

/* You will need to code these up yourself!  */
char *memcpy(char *dest, char *src, int count)
{
	for (int c = 0; c < count; c++) {
		dest[c] = src[c];
	}

	return dest;
}

char *memset(char *dest, char val, int count)
{
	for (int i = 0; i < count; i++) {
		dest[i] = val;
	}

	return dest;
}

char *memsetw(char *dest, char val, int count)
{
    /* Same as above, but this time, we're working with a 16-bit
    *  'val' and dest pointer. Your code can be an exact copy of
    *  the above, provided that your local variables if any, are
    *  unsigned short */
	for (int i = 0; i < count; i++) {
		dest[i] = val;
	}

	return dest;
}

int strlen(const char *str)
{
    /* This loops through character array 'str', returning how
    *  many characters it needs to check before it finds a 0.
    *  In simple words, it returns the length in bytes of a string */
	const char *s;	
	for (s = str; *s; ++s);
	return (s-str);
}

/* We will use this later on for reading from the I/O ports to get data
*  from devices such as the keyboard. We are using what is called
*  'inline assembly' in these routines to actually do the work */
unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %0, %1" : "=a" (rv) : "dN" (_port));
    return rv;
}

/* We will use this to write to I/O ports to send bytes to devices. This
*  will be used in the next tutorial for changing the textmode cursor
*  position. Again, we use some inline assembly for the stuff that simply
*  cannot be done in C */
void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %0, %1" : : "dN" (_port), "a" (_data));
}

	
