/*============================================================================*/
/*                                                                            */
/*                                                                            */
/*                              mutEX 0-003_void                              */
/*                                                                            */
/*                      (C) Copyright 2020 Pavel Surynek                      */
/*                                                                            */
/*                http://www.surynek.net | <pavel@surynek.net>                */
/*       http://users.fit.cvut.cz/surynek | <pavel.surynek@fit.cvut.cz>       */
/*                                                                            */
/*============================================================================*/
/* basic_test.cpp / 0-003_void                                                */
/*----------------------------------------------------------------------------*/
//
// Basic initial test.
//
/*----------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <signal.h>
#include <sys/time.h>

#include <z3++.h>

#include "defs.h"
#include "compile.h"
#include "result.h"
#include "version.h"

#include "common/types.h"

#include "test/basic_test.h"


using namespace std;
using namespace mutEX;
using namespace z3;


/*----------------------------------------------------------------------------*/

namespace mutEX
{




/*----------------------------------------------------------------------------*/

void print_Introduction(void)
{
    printf("----------------------------------------------------------------\n");    
    printf("%s : Basic Test Program\n", sPRODUCT);
    printf("%s\n", sCOPYRIGHT);
    printf("================================================================\n");
}


int test_basic_1(void)
{
    printf("Testing basic 1 ...\n");   
    printf("Testing basic 1 ... finished\n");

    return sRESULT_SUCCESS;
}


}  // namespace boOX


/*----------------------------------------------------------------------------*/

int main(int sUNUSED(argc), const char **sUNUSED(argv))
{
    sResult result;

    print_Introduction();

    if (sFAILED(result = test_basic_1()))
    {
	printf("Test basic 1 failed (error:%d).\n", result);
	return result;
    }
    return 0;
}
