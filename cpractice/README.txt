# practising code from k and r - c

# run after compiling
./a.out

#compile with warnings, with debug(-g) enabled
gcc -Wall -g source.c

# compile multiple files together, where 
gcc -Wall -g file1.c file2.c

# compile and assemble but no link, produces filename.o
gcc -Wall -c filename.c

# compile/link with main file with pre assembled files
gcc -Wall -g mainfile.c filename.o

#debugger, needs -g in gcc.
gdb a.out
break linenumber
break filename:linenum
run ./a.out < test.txt
explore variable

n - next line
c - continue run, will break on next break point

# include maths functions in linux. like <math.h>, else you'll get error like  undefined reference to 'sqrt'
gcc -lm

# windows - stdin as input
echo "123" | cprog.exe