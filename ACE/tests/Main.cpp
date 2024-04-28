
//=============================================================================
/**
 *  @file    Main.cpp
 *
 *   This is a wrapper for the test programs.  It obviates the test cpp's
 *   from having to always include OS.h.
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 */
//=============================================================================

#include "ace/OS_main.h"

// setup posix
#include <sys/authtable.h>

UserEntry users[] = {
    {"root","",0,NULLObject,0,NULL,0,NULLObject,{0},"/"},
    {"somebody","insecure",100,NULLObject,100,NULL,1,NULLObject,{200},""},
    {"nobody","whocares",__nobody,NULLObject,__nogroup,NULL,0,NULLObject,{0},""}
};
int num_users = sizeof(users)/sizeof(UserEntry);

GroupEntry groups[] = {
    {"root",0,NULLObject},
    {"somegrp",(gid_t)100,NULLObject},
    {"othergrp",(gid_t)200,NULLObject},
    {"nogroup",__nogroup,NULLObject}
};
int num_groups = sizeof(groups)/sizeof(GroupEntry);
// end posix setup

int run_main (int argc, ACE_TCHAR *argv[]);

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  return run_main (argc, argv);
}
