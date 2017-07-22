// https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom

#include <algorithm>
#include <cstddef>

class DumbArray
{
public:
  DumbArray(size_t size = 0)
    : m_size{size},
      m_array{m_size ? new int[m_size]{} : nullptr}
  {
  }

  ~DumbArray()
  {
    delete[] m_array;
  }

  DumbArray(const DumbArray& other)
    : m_size{other.m_size},
      m_array{m_size ? new int[m_size] : nullptr}
  {
    std::copy(other.m_array, other.m_array + m_size, m_array);
  }

  DumbArray(DumbArray&& other)
    : DumbArray{}
  {
    swap(*this, other);
  }

  DumbArray& operator=(DumbArray other)
  {
    swap(*this, other);
    return *this;
  }

  //--------------------------------

  friend void swap(DumbArray& first, DumbArray& second) noexcept
  {
    using std::swap;

    swap(first.m_size, second.m_size);
    swap(first.m_array, second.m_array);
  }

private:
  size_t m_size{0};
  int* m_array{nullptr};
};
