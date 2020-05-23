all: debug

debug:	basic_test.o_dbg 
	g++ basic_test.o_dbg -L../../src/glucose -L../../src/common -L../../src/core -L../../src/util -lUtil_mutEX_dbg -lCore_mutEX_dbg -lGlucose_mutEX_dbg -lCommon_mutEX_dbg -pthread -otest_basic_mutEX

optimized:	basic_test.o_opt 
	g++ basic_test.o_opt -L../../src/glucose -L../../src/common -L../../src/core -L../../src/util -lUtil_mutEX_opt -lCore_mutEX_opt -lGlucose_mutEX_opt -lCommon_mutEX_opt -pthread -otest_basic_mutEX

basic_test.o_dbg:	../../src/version.h ../../src/defs.h ../../src/config.h ../../src/compile.h ../../src/result.h ../../src/util/statistics.h ../../src/util/io.h ../../src/version.h ../../src/defs.h ../../src/config.h ../../src/compile.h ../../src/result.h ../../src/core/mutex.h ../../src/core/graph.h ../../src/core/cnf.h ../../src/glucose/Alg.h ../../src/glucose/Alloc.h ../../src/glucose/BoundedQueue.h ../../src/glucose/Constants.h ../../src/glucose/Dimacs.h ../../src/glucose/Heap.h ../../src/glucose/IntTypes.h ../../src/glucose/Map.h ../../src/glucose/Options.h ../../src/glucose/ParseUtils.h ../../src/glucose/Queue.h ../../src/glucose/Solver.h ../../src/glucose/SolverTypes.h ../../src/glucose/Sort.h ../../src/glucose/System.h ../../src/glucose/Vec.h ../../src/glucose/XAlloc.h ../../src/version.h ../../src/defs.h ../../src/config.h ../../src/compile.h ../../src/result.h ../../src/common/types.h ../../src/version.h ../../src/defs.h ../../src/config.h ../../src/compile.h ../../src/result.h basic_test.h basic_test.cpp
	g++ -Wall -Wextra -pedantic -Wno-class-memaccess -Wno-long-long -Wno-unused-result -Wno-sign-compare -Wno-delete-non-virtual-dtor -g -std=c++0x -c -I../../src -I../../src/glucose -I../../src/common -I../../src/core -I../../src/util -obasic_test.o_dbg basic_test.cpp


basic_test.o_opt:	../../src/version.h ../../src/defs.h ../../src/config.h ../../src/compile.h ../../src/result.h ../../src/util/statistics.h ../../src/util/io.h ../../src/version.h ../../src/defs.h ../../src/config.h ../../src/compile.h ../../src/result.h ../../src/core/mutex.h ../../src/core/graph.h ../../src/core/cnf.h ../../src/glucose/Alg.h ../../src/glucose/Alloc.h ../../src/glucose/BoundedQueue.h ../../src/glucose/Constants.h ../../src/glucose/Dimacs.h ../../src/glucose/Heap.h ../../src/glucose/IntTypes.h ../../src/glucose/Map.h ../../src/glucose/Options.h ../../src/glucose/ParseUtils.h ../../src/glucose/Queue.h ../../src/glucose/Solver.h ../../src/glucose/SolverTypes.h ../../src/glucose/Sort.h ../../src/glucose/System.h ../../src/glucose/Vec.h ../../src/glucose/XAlloc.h ../../src/version.h ../../src/defs.h ../../src/config.h ../../src/compile.h ../../src/result.h ../../src/common/types.h ../../src/version.h ../../src/defs.h ../../src/config.h ../../src/compile.h ../../src/result.h basic_test.h basic_test.cpp
	g++ -std=c++0x -c -w -O9 -mtune=native -I../../src -I../../src/glucose -I../../src/common -I../../src/core -I../../src/util -obasic_test.o_opt basic_test.cpp


clean:
	rm -f -r *~ *.o_dbg *.o_opt *.a *.bak output*.txt test_basic_mutEX
