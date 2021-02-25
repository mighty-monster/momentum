#pragma once

#include <cstddef>
#include <cstdint>

#include "simple.hpp"
#include "simple.cpp"

namespace nne {
  template <typename T>
  class SimpleHeapMemory : public SimpleMemory<nullptr, nullptr>
  {
  public:
    SimpleHeapMemory();
    SimpleHeapMemory(const char* file_path);
    SimpleHeapMemory(const size_t& length);
    ~SimpleHeapMemory();

    void Allocate(const size_t& length);
    void Deallocate();

    void LoadFromFile(const char* file_path) override;

    void LoadFromHexFile(const char* file_path) override;

    void Resize(const size_t& length) override;

    T& operator [] (const int64_t& index);
    const T& operator [] (const int64_t& index) const;

    size_t Length();

  private:
    size_t m_length = 0;
  };

}


