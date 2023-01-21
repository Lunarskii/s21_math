CC= -Wall -Werror -Wextra -std=c11
GCOV= -fprofile-arcs -ftest-coverage -fPIC
OBJ_TEST= s21_test.o
OBJ= s21_math.o
OBJ_C= s21_math.c
OS=$(shell uname)

ifeq (${OS}, Linux)
      TEST_FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
else
      TEST_FLAGS = -lcheck -lm
endif

all: test

test: s21_math.a $(OBJ_TEST)
	gcc $(CC) $(GCOV) $(OBJ_TEST) -o test s21_math.a $(TEST_FLAGS)
	./test

s21_math.a: $(OBJ)
	ar rc s21_math.a $(OBJ)
	ranlib s21_math.a

s21_math.o: s21_math.c
	gcc -c s21_math.c

s21_test.o: s21_test.c
	gcc $(CC) -c s21_test.c

clean:
	rm -rf test
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcda
	rm -rf report
	rm -rf *.gcno
	rm -rf *.info

open: 
	open report/index.html
    
gcov_report: clean $(OBJ_TEST)
	gcc -o test $(OBJ_TEST) --coverage $(OBJ_C) $(TEST_FLAGS)
	./test
	lcov -t "a.out" -o test.info -c -d .
	genhtml -o report test.info
	make open

.PHONY: all clean open
