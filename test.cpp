#include <iostream>

#include "snippets/thread.hpp"

//==========================================================================

class ThreadTest
{
  public:
    void f()
    {
      std::cout << "thread test" << std::endl;
    }
};

//--------------------------------------------------------------------------

void test_thread()
{
  ThreadTest c;

  ThreadGuard t(std::thread(&ThreadTest::f, &c));
  auto t2 = ThreadGuard(std::thread(&ThreadTest::f, &c));
  ThreadGuard t3(std::move(t));
  ThreadGuard t4 = std::move(t2);
}

//==========================================================================

int main(int argc, char *argv[])
{
  test_thread();
  return 0;
}
