#pragma once
#define _ZEUS_SIMD_INCLUDED
namespace zeus::_simd {
using namespace std;
}
#include "parallelism_v2_simd.hpp"
#if _M_IX86_FP >= 1 || _M_X64
#define __SSE__ 1
#endif
#if __AVX__
#include "simd_avx.hpp"
#elif __SSE__
#include "simd_sse.hpp"
#else
namespace simd_abi {
template <typename T>
struct zeus_native {};
template <>
struct zeus_native<float> {
  using type = fixed_size<4>;
};
template <>
struct zeus_native<double> {
  using type = fixed_size<4>;
};
} // namespace simd_abi
#endif
namespace zeus {
template <typename T>
using simd = _simd::simd<T, typename _simd::simd_abi::zeus_native<T>::type>;
template <typename T>
using simd_values = _simd::simd_data<simd<T>>;
using simd_floats = simd_values<float>;
using simd_doubles = simd_values<double>;
} // namespace zeus
