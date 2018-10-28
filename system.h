#ifndef __SYSTEM_H
#define __SYSTEM_H

/* MAIN.C */

extern char *memcpy(char *dest, char *src, int count);
extern char *memset(char *dest, char val, int count);
extern char *memsetw(char *dest, char val, int count);
extern int strlen(const char *str);
extern unsigned char inportb (unsigned short _port);
extern void outportb (unsigned short _port, unsigned char _data);

extern void move_csr(void);

extern void init_video();
extern void pc(unsigned char);
extern void p(char*);

#endif
		
