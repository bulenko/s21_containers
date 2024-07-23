COMPILER = g++
CFLAGS =  -std=c++17 -g -fno-elide-constructors -Wextra -Werror -Wall
GTFLAGS = -lgtest -lpthread
FILES = s21_containers.h s21_containerplus.h
TEST = tests.cpp

all rebuild: clean s21_containers.o tests.o

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info *.gch *.out *.gcov *.txt coverage_report report test

s21_containers.o:
	$(COMPILER) $(FILES) $(CFLAGS) -o s21_containers.o

tests.o:
	$(COMPILER) tests.cpp $(FILES) $(CFLAGS) $(GTFLAGS) -o test

test: clean tests.o	
	./test

clang:
	clang-format -n *.h *.cpp ./*/*.inl ./*/*.h ./*/*.cpp   
    
clang_help:
	clang-format -i *.h *.cpp ./*/*.inl ./*/*.h ./*/*.cpp

cppcheck:
	cppcheck  --enable=all --suppress=missingIncludeSystem --std=c++17 --language=c++   s21_*.h s21_*.cpp ./*/s21_*.inl ./*/s21_*.h ./*/s21_*.h ./*/s21_*.cpp

leaks_linux: clean test
	valgrind --trace-children=yes --track-fds=yes --leak-check=yes --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind_log.txt ./test 9>&1 
	tail -n 8 valgrind_log.txt

leaks_mac: clean test
	CK_FORK=no leaks --atExit -- ./test

gcov_report: clean
	$(COMPILER) --coverage -fno-elide-constructors $(FILES) tests.cpp $(CFLAGS) $(GTFLAGS) -o test
	./test
	lcov -c --directory . --output-file s21_container_coverage.info --no-external
	genhtml s21_container_coverage.info --output-directory coverage_report

