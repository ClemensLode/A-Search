PROG = AStarExercise


CXXFLAGS = -g -ansi -pedantic-errors -W -Wall -Wmissing-braces -Wredundant-decls -Wundef -Wunused -Wconversion -Woverloaded-virtual -Wmissing-noreturn -Wdisabled-optimization -Wsign-promo -Wwrite-strings -Wlong-long -Woverloaded-virtual -Wfloat-equal -Wreturn-type -Wparentheses -Wchar-subscripts -Wimplicit  -Wtrigraphs  -Wendif-labels -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings -Winline -Wold-style-cast -Wswitch-enum -Wswitch -Wswitch-default -Wno-unknown-pragmas -O0 -ftest-coverage -fprofile-arcs
#CXXFLAGS = -ansi -pedantic-errors -W -Wall -Wmissing-braces -Wredundant-decls -Wundef -Wunused -Wconversion -Woverloaded-virtual -Wmissing-noreturn -Wdisabled-optimization -Wsign-promo -Wwrite-strings -Wlong-long -Woverloaded-virtual -Wfloat-equal -Wreturn-type -Wparentheses -Wchar-subscripts -Wimplicit  -Wtrigraphs  -Wendif-labels -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings -Winline -Wold-style-cast -Wswitch-enum -Wswitch -Wswitch-default -Wno-unknown-pragmas -O3 -pg -pipe -ftracer -ffast-math -march=pentium4 -fmerge-all-constants --param max-crossjump-edges=2000 --param max-gcse-memory=209715200 --param max-gcse-passes=40 --param max-pending-list-length=1000 --param max-delay-slot-insn-search=2000 --param max-delay-slot-live-search=4000 -ffast-math -g -ftest-coverage -fprofile-arcs

CXX = g++ 

.SUFFIXES: .o .cpp

OBJS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

GENPNG = genpng
USE_GENPNG := $(shell $(GENPNG) --help >/dev/null 2>/dev/null; echo $$?)
ifeq ($(USE_GENPNG),0)
	FRAMES := --frames
else
	FRAMES :=
endif


$(PROG): $(OBJS)
	$(CXX) -o $(PROG) $(CXXFLAGS) $(OBJS) 

cov:
	@lcov --zerocounters --directory .
	@./$(PROG) AStarMap.txt 20 20 120 10 showmap
	@lcov --capture --directory . --output-file $@ --test-name my_test_main

output: 
	@LC_ALL=en_US
	@export LC_ALL
	@rm coverage/* -rf
	@genhtml cov --output-directory coverage --title "AStarExercise Coverage" --show-details $(FRAMES) --legend

clean:
	@rm -vf *.o $(PROG)
	@rm -vf *.a
	@find . -name \*.gcov -type f -delete
	@find . -name \*.gcda -type f -delete
	@find . -name \*.gcno -type f -delete
	@rm -vf cov
	@rm -vf *.info  
	@rm -vf *.out
	@echo "done."
