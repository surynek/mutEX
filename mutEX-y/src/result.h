/*============================================================================*/
/*                                                                            */
/*                                                                            */
/*                              mutEX 0-004_void                              */
/*                                                                            */
/*                      (C) Copyright 2020 Pavel Surynek                      */
/*                                                                            */
/*                http://www.surynek.net | <pavel@surynek.net>                */
/*       http://users.fit.cvut.cz/surynek | <pavel.surynek@fit.cvut.cz>       */
/*                                                                            */
/*============================================================================*/
/* result.h / 0-004_void                                                      */
/*----------------------------------------------------------------------------*/

#ifndef __RESULT_H__
#define __RESULT_H__

#include <limits.h>

#include "config.h"
#include "compile.h"


/*----------------------------------------------------------------------------*/

namespace mutEX
{

typedef int sResult;


/*----------------------------------------------------------------------------*/
// Common results

enum sStandard_Result
{
    sRESULT_SUCCESS    =  0,
    sRESULT_INFO       =  1,
    sRESULT_ERROR      = -1,
    sRESULT_UNDEFINED  = INT_MAX
};


enum sType_Result
{
    sRESULT_TYPE__INFO               =  10000,
    sRESULT_TYPE__ERROR              = -10000,
    sRESULT_TYPE__INT_8_FPRN_ERROR   = (sRESULT_TYPE__ERROR -  1),
    sRESULT_TYPE__UINT_8_FPRN_ERROR  = (sRESULT_TYPE__ERROR -  2),
    sRESULT_TYPE__INT_16_FPRN_ERROR  = (sRESULT_TYPE__ERROR -  3),
    sRESULT_TYPE__UINT_16_FPRN_ERROR = (sRESULT_TYPE__ERROR -  4),
    sRESULT_TYPE__INT_32_FPRN_ERROR  = (sRESULT_TYPE__ERROR -  5),
    sRESULT_TYPE__UINT_32_FPRN_ERROR = (sRESULT_TYPE__ERROR -  6),
    sRESULT_TYPE__INT_64_FPRN_ERROR  = (sRESULT_TYPE__ERROR -  7),
    sRESULT_TYPE__UINT_64_FPRN_ERROR = (sRESULT_TYPE__ERROR -  8),
    sRESULT_TYPE__BOOL_FPRN_ERROR    = (sRESULT_TYPE__ERROR -  9),
    sRESULT_TYPE__CHAR_FPRN_ERROR    = (sRESULT_TYPE__ERROR - 10),
    sRESULT_TYPE__WCHAR_FPRN_ERROR   = (sRESULT_TYPE__ERROR - 11),
    sRESULT_TYPE__STRING_FPRN_ERROR  = (sRESULT_TYPE__ERROR - 12),
    sRESULT_TYPE__PHRASE_FPRN_ERROR  = (sRESULT_TYPE__ERROR - 13),
    sRESULT_TYPE__FLOAT_FPRN_ERROR   = (sRESULT_TYPE__ERROR - 14),
    sRESULT_TYPE__DOUBLE_FPRN_ERROR  = (sRESULT_TYPE__ERROR - 15),
    sRESULT_TYPE__POINTER_FPRN_ERROR = (sRESULT_TYPE__ERROR - 16),
    sRESULT_TYPE__BYTES_FPRN_ERROR   = (sRESULT_TYPE__ERROR - 17),
    sRESULT_TYPE__INT_8_SCAN_ERROR   = (sRESULT_TYPE__ERROR - 18),
    sRESULT_TYPE__UINT_8_SCAN_ERROR  = (sRESULT_TYPE__ERROR - 19),
    sRESULT_TYPE__INT_16_SCAN_ERROR  = (sRESULT_TYPE__ERROR - 20),
    sRESULT_TYPE__UINT_16_SCAN_ERROR = (sRESULT_TYPE__ERROR - 21),
    sRESULT_TYPE__INT_32_SCAN_ERROR  = (sRESULT_TYPE__ERROR - 22),
    sRESULT_TYPE__UINT_32_SCAN_ERROR = (sRESULT_TYPE__ERROR - 23),
    sRESULT_TYPE__INT_64_SCAN_ERROR  = (sRESULT_TYPE__ERROR - 24),
    sRESULT_TYPE__UINT_64_SCAN_ERROR = (sRESULT_TYPE__ERROR - 25),
    sRESULT_TYPE__BOOL_SCAN_ERROR    = (sRESULT_TYPE__ERROR - 26),
    sRESULT_TYPE__CHAR_SCAN_ERROR    = (sRESULT_TYPE__ERROR - 27),
    sRESULT_TYPE__WCHAR_SCAN_ERROR   = (sRESULT_TYPE__ERROR - 28),
    sRESULT_TYPE__STRING_SCAN_ERROR  = (sRESULT_TYPE__ERROR - 29),
    sRESULT_TYPE__PHRASE_SCAN_ERROR  = (sRESULT_TYPE__ERROR - 30),
    sRESULT_TYPE__FLOAT_SCAN_ERROR   = (sRESULT_TYPE__ERROR - 31),
    sRESULT_TYPE__DOUBLE_SCAN_ERROR  = (sRESULT_TYPE__ERROR - 32)
};


enum sUndirectedGraph_Result
{
    sUNDIRECTED_GRAPH_INFO       =  11000,
    sUNDIRECTED_GRAPH_ERROR      = -11000,
    sUNDIRECTED_GRAPH_OPEN_ERROR = (sUNDIRECTED_GRAPH_ERROR - 1)
};




/*----------------------------------------------------------------------------*/

#define sFAILED(result)    ((result) < sRESULT_SUCCESS)
#define sSUCCEEDED(result) ((result) >= sRESULT_SUCCESS)
#define sINFORMED(result)  ((result) > sRESULT_SUCCESS) 

#define sCHECK_RESULT(command)                                                           \
    {                                                                                    \
        sResult result;                                                                  \
        if (sFAILED(result = (command)))				                 \
        {                                                                                \
            return result;                                                               \
        }                                                                                \
    }


#define sCHECK_INT(command, result)                                                      \
    {                                                                                    \
	if ((command) < 0)                                                               \
	{                                                                                \
	    return result;                                                               \
	}                                                                                \
    }


/*----------------------------------------------------------------------------*/

#ifdef sDEBUG
  #define sASSERT(condition)                                                             \
    {                                                                                    \
      if (!(condition))							                 \
      {                                                                                  \
        printf("sASSERT: assertion failed (file: %s, line:%d).\n", __FILE__, __LINE__);  \
	fflush(NULL);                                                                    \
	exit(-1);						   	                 \
      }                                                                                  \
    }
#else
  #define sASSERT(condition)
#endif /* DEBUG */


#ifdef sDEBUG
  #define sASSERT_MESSAGE(condition, message)					         \
    {                                                                                    \
      if (!(condition))							                 \
      {                                                                                  \
        printf("sASSERT: assertion failed (file: %s, line:%d).\n", __FILE__, __LINE__);  \
	printf("Assertion message: %s\n", (message));			                 \
	fflush(NULL);                                                                    \
	exit(-1);						   	                 \
      }                                                                                  \
    }
#else
  #define sASSERT_MESSAGE(condition, message)
#endif /* DEBUG */


/*----------------------------------------------------------------------------*/

#ifdef sCONSISTENCY
  #define sTEST(condition)				                                                          \
    {                                                                                                             \
      sResult result;							                                          \
      if ((result = (condition)) != sRESULT_SUCCESS)			                                          \
      {                                                                                                           \
	printf("sTEST: consistency test failed (file: %s, line:%d, result: %d).\n", __FILE__, __LINE__, result);  \
	fflush(NULL);                                                                                             \
	exit(-1);						   	                                          \
      }                                                                                                           \
    }
#else
  #define sTEST_MESSAGE(condition, message)
#endif /* CONSISTENCY */


#ifdef sCONSISTENCY
  #define sTEST_MESSAGE(condition, message)				                                          \
    {                                                                                                             \
      sResult result;							                                          \
      if ((result = (condition)) != sRESULT_SUCCESS)		       	                                          \
      {                                                                                                           \
	printf("sTEST: consistency test failed (file: %s, line:%d, result: %d).\n", __FILE__, __LINE__, result);  \
	printf("Test message: %s\n", (message));			                                          \
	fflush(NULL);                                                                                             \
	exit(-1);						   	                                          \
      }                                                                                                           \
    }
#else
  #define sTEST_MESSAGE(condition, message)
#endif /* CONSISTENCY */


/*----------------------------------------------------------------------------*/

#ifdef sTHOROUGH_CONSISTENCY
  #define sTHOROUGH_TEST(condition)				                                                                    \
    {                                                                                                                               \
      sResult result;							                                                            \
      if ((result = (condition)) != sRESULT_SUCCESS)			                                                            \
      {                                                                                                                             \
	printf("sTHOROUGH_TEST: thorough consistency test failed (file: %s, line:%d, result: %d).\n", __FILE__, __LINE__, result);  \
	fflush(NULL);                                                                                                               \
	exit(-1);						   	                                                            \
      }                                                                                                                             \
    }
#else
  #define sTHOROUGH_TEST_MESSAGE(condition, message)
#endif /* THOROUGH_CONSISTENCY */


#ifdef sTHOROUGH_CONSISTENCY
  #define sTHOROUGH_TEST_MESSAGE(condition, message)				                                                    \
    {                                                                                                                               \
      sResult result;							                                                            \
      if ((result = (condition)) != sRESULT_SUCCESS)		       	                                                            \
      {                                                                                                                             \
	printf("sTHOROUGH_TEST: thorough consistency test failed (file: %s, line:%d, result: %d).\n", __FILE__, __LINE__, result);  \
	printf("Test message: %s\n", (message));			                                                            \
	fflush(NULL);                                                                                                               \
	exit(-1);						   	                                                            \
      }                                                                                                                             \
    }
#else
  #define sTHOROUGH_TEST_MESSAGE(condition, message)
#endif /* THOROUGH_CONSISTENCY */


/*----------------------------------------------------------------------------*/

#ifdef sDEEP_CONSISTENCY
  #define sDEEP_TEST(condition)				                                                                    \
    {                                                                                                                       \
      sResult result;							                                                    \
      if ((result = (condition)) != sRESULT_SUCCESS)			                                                    \
      {                                                                                                                     \
	printf("sDEEP_TEST: deep consistency test failed (file: %s, line:%d, result: %d).\n", __FILE__, __LINE__, result);  \
	fflush(NULL);                                                                                                       \
	exit(-1);						   	                                                    \
      }                                                                                                                     \
    }
#else
  #define sDEEP_TEST_MESSAGE(condition, message)
#endif /* DEEP_CONSISTENCY */


#ifdef sDEEP_CONSISTENCY
  #define sDEEP_TEST_MESSAGE(condition, message)				                                            \
    {                                                                                                                       \
      sResult result;							                                                    \
      if ((result = (condition)) != sRESULT_SUCCESS)		       	                                                    \
      {                                                                                                                     \
	printf("sDEEP_TEST: deep consistency test failed (file: %s, line:%d, result: %d).\n", __FILE__, __LINE__, result);  \
	printf("Test message: %s\n", (message));			                                                    \
	fflush(NULL);                                                                                                       \
	exit(-1);						   	                                                    \
      }                                                                                                                     \
    }
#else
  #define sDEEP_TEST_MESSAGE(condition, message)
#endif /* DEEP_CONSISTENCY */


/*----------------------------------------------------------------------------*/

} // namespace mutEX

#endif /* __RESULT_H__ */

