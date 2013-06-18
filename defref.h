#ifndef _DEFREF_H_
#define _DEFREF_H_

#ifdef DEF // define external variables here
    #define EXTERN // no-op
    #define INIT( X ) = X // initialize variable
#else // just declare as extern
    #define EXTERN extern
    #define INIT( X ) // no-op
#endif

#endif // _DEFREF_H_
