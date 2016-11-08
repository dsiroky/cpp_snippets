#ifndef THREAD_HPP__6HRWAG0C
#define THREAD_HPP__6HRWAG0C

#include <thread>

//==========================================================================

/// Thread join guard.
class ThreadGuard
{
  public:
    explicit ThreadGuard(std::thread&& thread)
      : m_thread(std::move(thread))
    {
    }

    ThreadGuard(ThreadGuard&&) = default;
    ThreadGuard& operator=(ThreadGuard&&) = default;

    ~ThreadGuard()
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

static_assert(std::is_move_constructible<ThreadGuard>::value,
              "ThreadGuard must be move constructible");
static_assert(std::is_move_assignable<ThreadGuard>::value,
              "ThreadGuard must be moveable");

#endif /* end of include guard: THREAD_HPP__6HRWAG0C */
