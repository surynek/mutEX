/*============================================================================*/
/*                                                                            */
/*                                                                            */
/*                              mutEX 0-007_void                              */
/*                                                                            */
/*                      (C) Copyright 2020 Pavel Surynek                      */
/*                                                                            */
/*                http://www.surynek.net | <pavel@surynek.net>                */
/*       http://users.fit.cvut.cz/surynek | <pavel.surynek@fit.cvut.cz>       */
/*                                                                            */
/*============================================================================*/
/* basic_test.cpp / 0-007_void                                                */
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

#include "defs.h"
#include "compile.h"
#include "result.h"
#include "version.h"

#include "common/types.h"

#include "core/mutex.h"

#include "test/basic_test.h"


using namespace std;
using namespace mutEX;


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

    sNetwork mutex_network_1(10);
    mutex_network_1.to_Screen();

    mutex_network_1.add_Link(2,3);
    mutex_network_1.to_Screen();        
    mutex_network_1.add_Link(1,2);
    mutex_network_1.to_Screen();
    mutex_network_1.add_Link(1,3);
    mutex_network_1.to_Screen();
    mutex_network_1.add_Link(4,1);
    mutex_network_1.to_Screen();
    mutex_network_1.add_Link(4,2);
    mutex_network_1.to_Screen();
    mutex_network_1.add_Link(4,3);
    mutex_network_1.to_Screen();   
    mutex_network_1.add_Link(5,1);
    mutex_network_1.to_Screen();
    mutex_network_1.add_Link(5,2);
    mutex_network_1.to_Screen();
    mutex_network_1.add_Link(5,3);
    mutex_network_1.to_Screen();
    mutex_network_1.add_Link(5,4);
    mutex_network_1.to_Screen();

    mutex_network_1.add_Link(6,1);
    mutex_network_1.to_Screen();
    mutex_network_1.add_Link(6,2);
    mutex_network_1.to_Screen();
    mutex_network_1.add_Link(6,3);
    mutex_network_1.to_Screen();
    mutex_network_1.add_Link(6,4);
    mutex_network_1.to_Screen();
    mutex_network_1.add_Link(6,5);
    mutex_network_1.to_Screen();

    mutex_network_1.add_Link(7,6);
    mutex_network_1.to_Screen();
    mutex_network_1.add_Link(7,1);
    mutex_network_1.to_Screen();                
    
    printf("Testing basic 1 ... finished\n");

    return sRESULT_SUCCESS;
}


}  // namespace mutEX


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
