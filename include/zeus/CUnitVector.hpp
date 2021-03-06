#pragma once

#include "zeus/CVector3f.hpp"

namespace zeus {
class CUnitVector3f : public CVector3f {
public:
  constexpr CUnitVector3f() : CVector3f(0.f, 1.f, 0.f) {}

  constexpr CUnitVector3f(float x, float y, float z, bool doNormalize = true) : CVector3f(x, y, z) {
    if (doNormalize && canBeNormalized())
      normalize();
  }

  constexpr CUnitVector3f(const CVector3f& vec, bool doNormalize = true) : CVector3f(vec) {
    if (doNormalize && canBeNormalized())
      normalize();
  }
};
} // namespace zeus
