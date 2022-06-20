#include "testC.h"

#include "ace/OS_NS_stdlib.h"
#include "ace/OS_main.h"
#include "ace/streams.h"
#include <cstdlib>
#include <cstring>

namespace stream8 {
  std::ostream &
  operator<< (std::ostream &os, CORBA::UInt8 value) {
    return os << static_cast<unsigned>(value);
  }

  std::ostream &
  operator<< (std::ostream &os, CORBA::Int8 value) {
    return os << static_cast<int>(value);
  }
}

template <typename IntType>
void
expect_equals (bool &any_failed, const char *name, IntType actual, IntType expected)
{
  if (actual != expected)
    {
      using stream8::operator<<;
      *ACE_DEFAULT_LOG_STREAM
        << "ERROR: For " << name << " expected: " << expected
        << ", but got " << actual << "\n";
      any_failed = true;
    }
}

template <>
void
expect_equals (bool &any_failed, const char *name, const char* actual, const char* expected)
{
  if (std::strcmp(actual, expected) != 0)
    {
      using stream8::operator<<;
      *ACE_DEFAULT_LOG_STREAM
        << "ERROR: For " << name << " expected: " << expected
        << ", but got " << actual << "\n";
      any_failed = true;
    }
}

int ACE_TMAIN(int, ACE_TCHAR *[])
{
  DataStruct d;
  d.mapData[0] = 0;
  d.mapData[1] = 1;
  d.mapData[2] = 2;
  d.mapData[3] = 3;
  d.mapData[4] = 4;
  d.mapData[5] = 5;

  bool any_failed = false;
  expect_equals<CORBA::Long> (any_failed, "d.mapData.size()", d.mapData.size(), 6);
  expect_equals<CORBA::Long> (any_failed, "d.mapData[0]", d.mapData[0], 0);
  d.mapData[0] = 10;
  expect_equals<CORBA::Long> (any_failed, "d.mapData[0]", d.mapData[0], 10);

  d.stringMapStructs["Test"] = TestStruct{0, "Test Struct"};
  expect_equals<CORBA::Long> (any_failed, "d.stringMapStructs['Test']", d.stringMapStructs["Test"].id, 0);
  expect_equals<const char*> (any_failed, "d.stringMapStructs['Test']", d.stringMapStructs["Test"].msg, "Test Struct");

  if (any_failed)
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}
