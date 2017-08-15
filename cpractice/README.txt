# practising code from k and r - c

# run after compiling
./a.out

#compile with warnings, with debug(-g) enabled
gcc -Wall -g source.c

#debugger, needs -g in gcc.
gdb a.out
break linenumber
run ./a.out < test.txt
explore variable

# include maths functions in linux. like <math.h>, else you'll get error like  undefined reference to 'sqrt'
gcc -lm

# windows - stdin as input
echo "123" | cprog.exe