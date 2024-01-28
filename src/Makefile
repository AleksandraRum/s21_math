TARGET = s21_math.a
OBJ = objects
CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
TESTFLAGS = -lcheck -lm -lpthread -lrt -lsubunit --coverage
RBIN = gcov_test gcov_test-test.gcda gcov_test-test.gcno gcov_test.info report
VALGR = valgrind -s ./
SRCS = s21$(C)
OBJS = s21$(O)
OBJSDIR = OBJS/
TESTDIR=tests/
RAN = ranlib
AR = ar rc
RM = rm -rf
MK = mkdir -p
MV = mv
CPP = cppcheck
CLANG = clang-format -style=Google -n *.c *.h
C = *.c
H = *.h
O = *.o
A = *.a
G = *.gcno
GA = *.gcda

.PHONY: all clean rebuild test

all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) $(TARGET) $(OBJSDIR)$(OBJS)
	$(RAN) $(TARGET)
$(OBJ):
	$(MK) $(OBJSDIR)
	$(CC) $(CFLAGS) -c $(SRCS) 
	$(MV) $(OBJS) $(OBJSDIR)
test: $(TESTDIR)test.c $(TARGET)
	$(CC) $(CFLAGS) -g $(TESTDIR)test.c $(TESTDIR)test_*.c $(TESTDIR)test.h $(TARGET) -o test $(TESTFLAGS)
	./test
clean:
	$(RM) $(OBJSDIR) test
	$(RM) $(O) $(A) $(RBIN)
	$(RM) $(GA)
	$(RM) $(G)
rebuild:
	$(RM) $(TARGET)
style_test:
	$(CLANG) $(C) $(H) $(C)
	$(CPP) $(C)  $(H) $(C)
	$(VALGR)test
gcov_report: $(TESTDIR)test.c
	$(CC) $(CFLAGS) --coverage $(TESTDIR)*.c $(SRCS) $(TARGET) $(TESTFLAGS) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info -c -d .
	genhtml -o report gcov_test.info
	open ./report/index.html