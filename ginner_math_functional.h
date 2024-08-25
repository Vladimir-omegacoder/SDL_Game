#pragma once

#ifndef GINNER_MATH_FUNCTIONAL

#define GINNER_MATH_FUNCTIONAL
#include "ginner_mat_setup.h"
#include "ginner_types.h"
#include <cmath>

namespace gin
{

	template <typename T> GINNER_CONSTEXPR bool epsilon_equal(const T& val1, const T& val2, const T& eps);

	template <length_t L, typename T> GINNER_CONSTEXPR bool epsilon_equal(const vec<L, T>& v1, const vec<L, T>& v2, const T& eps);

	template <length_t C, length_t R, typename T> GINNER_CONSTEXPR bool epsilon_equal(const mat<C, R, T>& m1, const mat<C, R, T>& m2, const T& eps);


	template <length_t L, typename T> GINNER_CONSTEXPR T dot(const vec<L, T>& v1, const vec<L, T>& v2);

	template <typename T> GINNER_CONSTEXPR vec<3, T> cross(const vec<3, T>& v1, const vec<3, T>& v2);

	template <length_t L, typename T> GINNER_CONSTEXPR T length(const vec<L, T>& v);

	template <length_t L, typename T> GINNER_CONSTEXPR T distance(const vec<L, T>& p1, const vec<L, T>& p2);

	template <length_t L, typename T> GINNER_CONSTEXPR vec<L, T> normalize(const vec<L, T>& v);



	template <typename T> GINNER_CONSTEXPR T determinant(const mat2x2<T>& m);
	template <typename T> GINNER_CONSTEXPR T determinant(const mat3x3<T>& m);
	template <typename T> GINNER_CONSTEXPR T determinant(const mat4x4<T>& m);

	template <typename T> GINNER_CONSTEXPR mat2x2<T> inverse(const mat2x2<T>& m);
	template <typename T> GINNER_CONSTEXPR mat3x3<T> inverse(const mat3x3<T>& m);
	template <typename T> GINNER_CONSTEXPR mat4x4<T> inverse(const mat4x4<T>& m);

	template <length_t C, length_t R, typename T> GINNER_CONSTEXPR mat<R, C, T> transpose(const mat<C, R, T>& m);



	template <typename T>
	struct compute_epsilon_equal
	{};

	template <typename T>
	struct compute_epsilon_equal<vec<1, T>>
	{
		static GINNER_CONSTEXPR T call(const vec<1, T>& v1, const vec<1, T>& v2, const T& eps);
	};

	template <typename T>
	struct compute_epsilon_equal<vec<2, T>>
	{
		static GINNER_CONSTEXPR T call(const vec<2, T>& v1, const vec<2, T>& v2, const T& eps);
	};

	template <typename T>
	struct compute_epsilon_equal<vec<3, T>>
	{
		static GINNER_CONSTEXPR T call(const vec<3, T>& v1, const vec<3, T>& v2, const T& eps);
	};

	template <typename T>
	struct compute_epsilon_equal<vec<4, T>>
	{
		static GINNER_CONSTEXPR T call(const vec<4, T>& v1, const vec<4, T>& v2, const T& eps);
	};

	template <typename T>
	struct compute_epsilon_equal<mat<2, 2, T>>
	{
		static GINNER_CONSTEXPR T call(const mat<2, 2, T>& m1, const mat<2, 2, T>& m2, const T& eps);
	};

	template <typename T>
	struct compute_epsilon_equal<mat<2, 3, T>>
	{
		static GINNER_CONSTEXPR T call(const mat<2, 3, T>& m1, const mat<2, 3, T>& m2, const T& eps);
	};

	template <typename T>
	struct compute_epsilon_equal<mat<2, 4, T>>
	{
		static GINNER_CONSTEXPR T call(const mat<2, 4, T>& m1, const mat<2, 4, T>& m2, const T& eps);
	};

	template <typename T>
	struct compute_epsilon_equal<mat<3, 2, T>>
	{
		static GINNER_CONSTEXPR T call(const mat<3, 2, T>& m1, const mat<3, 2, T>& m2, const T& eps);
	};

	template <typename T>
	struct compute_epsilon_equal<mat<3, 3, T>>
	{
		static GINNER_CONSTEXPR T call(const mat<3, 3, T>& m1, const mat<3, 3, T>& m2, const T& eps);
	};

	template <typename T>
	struct compute_epsilon_equal<mat<3, 4, T>>
	{
		static GINNER_CONSTEXPR T call(const mat<3, 4, T>& m1, const mat<3, 4, T>& m2, const T& eps);
	};

	template <typename T>
	struct compute_epsilon_equal<mat<4, 2, T>>
	{
		static GINNER_CONSTEXPR T call(const mat<4, 2, T>& m1, const mat<4, 2, T>& m2, const T& eps);
	};

	template <typename T>
	struct compute_epsilon_equal<mat<4, 3, T>>
	{
		static GINNER_CONSTEXPR T call(const mat<4, 3, T>& m1, const mat<4, 3, T>& m2, const T& eps);
	};

	template <typename T>
	struct compute_epsilon_equal<mat<4, 4, T>>
	{
		static GINNER_CONSTEXPR T call(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2, const T& eps);
	};


	template <length_t L, typename T>
	struct compute_dot
	{};

	template <typename T>
	struct compute_dot<1, T>
	{
		static GINNER_CONSTEXPR T call(const vec<1, T>& v1, const vec<1, T>& v2);
	};

	template <typename T>
	struct compute_dot<2, T>
	{
		static GINNER_CONSTEXPR T call(const vec<2, T>& v1, const vec<2, T>& v2);
	};

	template <typename T>
	struct compute_dot<3, T>
	{
		static GINNER_CONSTEXPR T call(const vec<3, T>& v1, const vec<3, T>& v2);
	};

	template <typename T>
	struct compute_dot<4, T>
	{
		static GINNER_CONSTEXPR T call(const vec<4, T>& v1, const vec<4, T>& v2);
	};


	template <length_t L, typename T>
	struct compute_length
	{};

	template <typename T>
	struct compute_length<1, T>
	{
		static GINNER_CONSTEXPR T call(const vec<1, T>& v);
	};

	template <typename T>
	struct compute_length<2, T>
	{
		static GINNER_CONSTEXPR T call(const vec<2, T>& v);
	};

	template <typename T>
	struct compute_length<3, T>
	{
		static GINNER_CONSTEXPR T call(const vec<3, T>& v);
	};

	template <typename T>
	struct compute_length<4, T>
	{
		static GINNER_CONSTEXPR T call(const vec<4, T>& v);
	};


	template <length_t C, length_t R, typename T>
	struct compute_transpose
	{};

	template <typename T>
	struct compute_transpose<2, 2, T>
	{
		static GINNER_CONSTEXPR mat<2, 2, T> call(const mat<2, 2, T>& m);
	};

	template <typename T>
	struct compute_transpose<2, 3, T>
	{
		static GINNER_CONSTEXPR mat<3, 2, T> call(const mat<2, 3, T>& m);
	};

	template <typename T>
	struct compute_transpose<2, 4, T>
	{
		static GINNER_CONSTEXPR mat<4, 2, T> call(const mat<2, 4, T>& m);
	};

	template <typename T>
	struct compute_transpose<3, 2, T>
	{
		static GINNER_CONSTEXPR mat<2, 3, T> call(const mat<3, 2, T>& m);
	};

	template <typename T>
	struct compute_transpose<3, 3, T>
	{
		static GINNER_CONSTEXPR mat<3, 3, T> call(const mat<3, 3, T>& m);
	};

	template <typename T>
	struct compute_transpose<3, 4, T>
	{
		static GINNER_CONSTEXPR mat<4, 3, T> call(const mat<3, 4, T>& m);
	};

	template <typename T>
	struct compute_transpose<4, 2, T>
	{
		static GINNER_CONSTEXPR mat<2, 4, T> call(const mat<4, 2, T>& m);
	};

	template <typename T>
	struct compute_transpose<4, 3, T>
	{
		static GINNER_CONSTEXPR mat<3, 4, T> call(const mat<4, 3, T>& m);
	};

	template <typename T>
	struct compute_transpose<4, 4, T>
	{
		static GINNER_CONSTEXPR mat<4, 4, T> call(const mat<4, 4, T>& m);
	};

}

#include "ginner_math_functional.inl"

#endif