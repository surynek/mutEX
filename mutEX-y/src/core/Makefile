all: debug

debug:	libCore_mutEX_dbg.a 

optimized:	libCore_mutEX_opt.a 

libCore_mutEX_dbg.a:	mutex.o_dbg 
	ar r libCore_mutEX_dbg.a mutex.o_dbg

mutex.o_dbg:	../../src/version.h ../../src/defs.h ../../src/config.h ../../src/compile.h ../../src/result.h mutex.h mutex.cpp
	g++ -Wall -Wextra -pedantic -Wno-class-memaccess -Wno-long-long -Wno-unused-result -Wno-sign-compare -Wno-delete-non-virtual-dtor -g -std=c++0x -c -I../../src -I../../src/core -omutex.o_dbg mutex.cpp


libCore_mutEX_opt.a:	mutex.o_opt 
	ar r libCore_mutEX_opt.a mutex.o_opt

mutex.o_opt:	../../src/version.h ../../src/defs.h ../../src/config.h ../../src/compile.h ../../src/result.h mutex.h mutex.cpp
	g++ -std=c++0x -c -w -O9 -mtune=native -I../../src -I../../src/core -omutex.o_opt mutex.cpp


clean:
	rm -f -r *~ *.o_dbg *.o_opt *.a *.bak output*.txt
