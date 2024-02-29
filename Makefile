CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec-test.cpp llrec.cpp
	$(CXX) $(CXXFLAGS) -o llrec-test llrec-test.cpp llrec.cpp


clean:
	rm -f *.o rh llrec-test *~

check: llrec-test
	$(VALGRIND) ./llrec-test

.PHONY: clean 