#ifndef _BASIC_MATH_MATH_H_
#define _BASIC_MATH_MATH_H_

#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <cassert>

namespace CppUtil {
	namespace Basic {
		namespace Math {
			constexpr float EPSILON = 1e-6f;

			constexpr float PI = 3.14159265358979323f;
			constexpr float INV_PI = 0.318309886183790672f;

			template<typename T, typename U>
			inline T Lerp(T v0, T v1, U t) {
				return (static_cast<U>(1) - t)*v0 + t * v1;
			}

			inline float Radians(const float degree) {
				return (PI / 180.f) * degree;
			}

			inline float Degrees(const float radians) {
				return (180.f / PI) * radians;
			}

			template <typename T> T sgn(T val) {
				return static_cast<T>((static_cast<T>(0) < val) - (val < static_cast<T>(0)));
			}

			template<typename T>
			constexpr T ToVal(T orig, T val, T bound = static_cast<T>(0.000001)) {
				const auto delta = orig - val;
				if (delta < bound && delta > -bound)
					return val;
				else
					return orig;
			}

			template<typename T>
			constexpr T ToZero(T orig, T bound = static_cast<T>(0.000001)) {
				return ToVal(orig, static_cast<T>(0), bound);
			}

			template<typename T>
			constexpr bool Equal(T lhs, T rhs, T bound = static_cast<T>(0.000001)) {
				return ToZero(rhs - lhs, bound) == static_cast<T>(0);
			}

			template<typename T>
			constexpr bool IsZero(T orig, T bound = static_cast<T>(0.000001)) {
				return Equal(orig, static_cast<T>(0));
			}

			// [-0x7FFFFFFFF, 0x7FFFFFFF]
			int Rand_I();

			// [0, 0xFFFFFFFF]
			unsigned int Rand_UI();

			// [0.0f, 1.0f]
			float Rand_F();
			// [0.0f, 1.0f]
			float Rand_F_exclude1();

			// [0.0, 1.0]
			double Rand_D();

			void RandSetSeedByCurTime();

			template <typename T>
			T Mean(const std::vector<T> & data);

			template<typename T>
			T Variance(const std::vector<T> & data);

			// 变更所有元素的位置, 新位置的概率平均
			template<typename T>
			void Permute(std::vector<T> data);

			template<typename T>
			T min(const std::vector<T> & val);

			template<typename T>
			T max(const std::vector<T> & val);

			template<typename T, typename U, typename V>
			T Clamp(T v, U minV, V maxV) {
				const auto minV_T = static_cast<T>(minV);
				const auto maxV_T = static_cast<T>(maxV);
				assert(minV_T <= maxV_T);
				if (v < minV_T)
					return minV_T;
				else if (v > maxV_T)
					return maxV_T;
				else
					return v;
			}

			template<typename Type>
			Type CastTo(const std::string & str) {
				std::istringstream iss(str);
				Type num;
				iss >> num;
				return num;
			}

			template<typename T>
			T Sinc(T x) {
				x = std::abs(x);
				if (x < static_cast<T>(1e-5)) return static_cast<T>(1);
				return std::sin(PI * x) / (PI * x);
			}

#include <CppUtil/Basic/Math.inl>
		}
	}
}

#endif // !_BASIC_MATH_MATH_H_
