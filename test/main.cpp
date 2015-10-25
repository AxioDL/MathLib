#include <iostream>
#include <iomanip>
#include <MathLib.hpp>

// This is only for testing, do NOT do this normally
using namespace Zeus;

int main()
{
    assert(!CAABox({100, 100, 100}, {100, 100, 100}).invalid());
    assert(CAABox().invalid());
    CVector3f vec{320, 632162.f, 800.f};
    assert(vec.canBeNormalized());
    assert(!vec.isZero());
    assert(CVector3f().isZero());
    assert(!vec.normalized().canBeNormalized());
    float blarg = 5.f;
    CVector3f t{100, 100, 200};
    blarg = Math::clamp(0.f, blarg, 1.f);
    CAABox test{{-100, -100, -100}, {100, 100, 100}};
    CAABox test2{{-100, -100, -100}, {100, 100, 100}};
    CAABox test3{{-50, -50, -50},  {50, 50, 50}};
    CAABox test4{{-50, -50, -105}, {50, 50, 105}};
    CVector3f point(-90, 67, -105);
    CVector3f closestPoint = test.closestPointAlongVector(point);
    CVector3d doubleVec(100, -100, -200);

    assert(t.isEqu(t));
    assert(test.inside(test));
    assert(test2.inside(test));
    assert(test3.inside(test));
    assert(!test4.inside(test));

    std::cout << Math::min(1, 3) << std::endl;
    std::cout << Math::min(2, 1) << std::endl;
    std::cout << Math::max(1, 3) << std::endl;
    std::cout << Math::max(2, 1) << std::endl;
    std::cout << Math::clamp(-50,  100, 50) << std::endl;
    std::cout << Math::clamp(-50, -100, 50) << std::endl;
    std::cout << Math::powF(6.66663489, 2) << std::endl;
    std::cout << Math::invSqrtF(1) << std::endl;
    std::cout << Math::floorPowerOfTwo(256) << std::endl;
    CLine line({-89.120926, 59.328712, 3.265882}, CUnitVector3f({-90.120926, 59.328712, 3.265882}));

    return 0;
}
