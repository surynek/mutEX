all: debug

debug:	libCore_mutEX_dbg.a 

optimized:	libCore_mutEX_opt.a 

libCore_mutEX_dbg.a:	mutex.o_dbg graph.o_dbg cnf.o_dbg 
	ar r libCore_mutEX_dbg.a mutex.o_dbg graph.o_dbg cnf.o_dbg

mutex.o_dbg:	../../src/version.h ../../src/defs.h ../../src/config.h ../../src/compile.h ../../src/result.h mutex.h graph.h cnf.h mutex.cpp
	g++ -Wall -Wextra -pedantic -Wno-class-memaccess -Wno-long-long -Wno-unused-result -Wno-sign-compare -Wno-delete-non-virtual-dtor -g -std=c++0x -c -I../../src -I../../src/core -omutex.o_dbg mutex.cpp

graph.o_dbg:	../../src/version.h ../../src/defs.h ../../src/config.h ../../src/compile.h ../../src/result.h mutex.h graph.h cnf.h graph.cpp
	g++ -Wall -Wextra -pedantic -Wno-class-memaccess -Wno-long-long -Wno-unused-result -Wno-sign-compare -Wno-delete-non-virtual-dtor -g -std=c++0x -c -I../../src -I../../src/core -ograph.o_dbg graph.cpp

cnf.o_dbg:	../../src/version.h ../../src/defs.h ../../src/config.h ../../src/compile.h ../../src/result.h mutex.h graph.h cnf.h cnf.cpp
	g++ -Wall -Wextra -pedantic -Wno-class-memaccess -Wno-long-long -Wno-unused-result -Wno-sign-compare -Wno-delete-non-virtual-dtor -g -std=c++0x -c -I../../src -I../../src/core -ocnf.o_dbg cnf.cpp


libCore_mutEX_opt.a:	mutex.o_opt graph.o_opt cnf.o_opt 
	ar r libCore_mutEX_opt.a mutex.o_opt graph.o_opt cnf.o_opt

mutex.o_opt:	../../src/version.h ../../src/defs.h ../../src/config.h ../../src/compile.h ../../src/result.h mutex.h graph.h cnf.h mutex.cpp
	g++ -std=c++0x -c -w -O9 -mtune=native -I../../src -I../../src/core -omutex.o_opt mutex.cpp

graph.o_opt:	../../src/version.h ../../src/defs.h ../../src/config.h ../../src/compile.h ../../src/result.h mutex.h graph.h cnf.h graph.cpp
	g++ -std=c++0x -c -w -O9 -mtune=native -I../../src -I../../src/core -ograph.o_opt graph.cpp

cnf.o_opt:	../../src/version.h ../../src/defs.h ../../src/config.h ../../src/compile.h ../../src/result.h mutex.h graph.h cnf.h cnf.cpp
	g++ -std=c++0x -c -w -O9 -mtune=native -I../../src -I../../src/core -ocnf.o_opt cnf.cpp


clean:
	rm -f -r *~ *.o_dbg *.o_opt *.a *.bak output*.txt
