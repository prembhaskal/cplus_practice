#include <stdio.h>

void pchar(char);
void pshort(short);
void pint(int);
void puint(unsigned int);
void plong(long);
void pulong(unsigned long);
void pdouble(double);
void pstring(char[]);

int main() {
	
	pshort(1234);
	// pshort(123452344); // compiler warns for overflow, exec we do see overflow.
	
	pint(123);
	
	//octal and hexadecimal nos.
	pint(012);
	pint(0x1F);
	pint(0xFF);
	
	puint(-1233u); // undefined result.
	puint(1233u);
	pint(01223u);
	
	plong(1234567890L);
	plong(0X1223L);
	
	pulong(12);
	pulong(1214985713248UL);
	
	pdouble(12.345);
	pdouble(12.345f);
	pdouble(123.4e-2);
	pdouble(123.4l);
	
	// character constants.
	pchar('x');
	pchar('X');
	pchar('0');
	pchar('\n');
	pchar('\007');
	pchar('\x1F');
	
	// string constants;
	pstring("hello");
	pstring("hello " "world!!!"); // concatenate string.
	pstring("hello \" " "world!!!"); // print the double quotes too.
	
	//enum constants;
	enum boolean {NO, YES};
	pint(NO);
	pint(YES);
	
	enum months {JAN=1, FEB, MAR};
	pint(JAN);
	pint(FEB);
	pint(MAR);
	
	enum confuse {FIRST=2, SEC=1, THIRD}; // numbering continues from last specified one.
	pint(FIRST);
	pint(SEC);
	pint(THIRD);	
	
	return 0;
}

void pchar(char c) {
	printf("printing value of character -- ");
	putchar(c);
	printf(" -- integer value is %d\n", c);
}

void pshort(short c) {
	printf("printing a short integer - %hd\n", c);
}

void pint(int c) {
	printf("printing a integer - %d\n", c);
}

void puint(unsigned int c) {
	printf("printing a unsigned integer - %u\n", c);
}

void plong(long c) {
	printf("printing a long integer - %ld\n", c);
}

void pulong(unsigned long c) {
	printf("printing a unsigned long integer - %lu\n", c);
}

void pdouble(double c) {
	printf("printing a double - %f\n", c);
}

void pldouble(long double c) {
	printf("printing a double - %Lf\n", c);
}

void pstring(char str[]) {
	printf("printing string - %s\n", str);
}

