#ifndef PcgRandomTest_INCLUDED
#define PcgRandomTest_INCLUDED

#include "CppUnit/TestCase.h"

class PcgRandomTest: public CppUnit::TestCase
{
public:
  PcgRandomTest(const std::string& name);
  ~PcgRandomTest();

  void testPcgRandom();

  void setUp();
  void tearDown();

  static CppUnit::Test* suite();

private:
};


#endif // PcgRandomTest_INCLUDED
