#include "PcgRandomTest.h"
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

PcgRandomTest::PcgRandomTest(const std::string& name): CppUnit::TestCase(name)
{
}

PcgRandomTest::~PcgRandomTest()
{
}

void PcgRandomTest::testPcgRandom()
{
  assert true;
}

void PcgRandomTest::setUp()
{
}

void PcgRandomTest::tearDown()
{
}

CppUnit::Test* PcgRandomTest::suite()
{
  CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("PcgRandomTest");
  CppUnit_addTest(pSuite, PcgRandomTest, testPcgRandom);
  return pSuite;
}
