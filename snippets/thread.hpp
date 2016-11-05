#ifndef THREAD_HPP__6HRWAG0C
#define THREAD_HPP__6HRWAG0C

#include <thread>

//==========================================================================

/// std::thread wrapper and join guard
class Thread
{
  public:
    template<typename ...Args>
    Thread(Args&&... args)
      : m_thread(std::forward<Args>(args)...)
    {
    }

    Thread& operator=(Thread&&) = default;

    ~Thread()
    {
      if (m_thread.joinable())
      {
        m_thread.join();
      }
    }

  private:
    std::thread m_thread;
};

//--------------------------------------------------------------------------

static_assert(std::is_move_constructible<Thread>::value,
              "Thread must be move constructible");
static_assert(std::is_move_assignable<Thread>::value,
              "Thread must be moveable");

#endif /* end of include guard: THREAD_HPP__6HRWAG0C */
