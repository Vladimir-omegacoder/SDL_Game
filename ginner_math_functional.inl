#include "ginner_math_functional.h"

template<typename T> GINNER_CONSTEXPR bool gin::epsilon_equal(const T& val1, const T& val2, const T& eps)
{
	return abs(val1 - val2) < eps;
}

template<gin::length_t L, typename T> GINNER_CONSTEXPR bool gin::epsilon_equal(const vec<L, T>& v1, const vec<L, T>& v2, const T& eps)
{
	return compute_epsilon_equal<vec<L, T>>::call(v1, v2, eps);
}

template<gin::length_t C, gin::length_t R, typename T> GINNER_CONSTEXPR bool gin::epsilon_equal(const mat<C, R, T>& m1, const mat<C, R, T>& m2, const T& eps)
{
	return compute_epsilon_equal<mat<C, R, T>>::call(m1, m2, eps);
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_epsilon_equal<gin::vec<1, T>>::call(const vec<1, T>& v1, const vec<1, T>& v2, const T& eps)
{
	vec<1, T> temp = v1 - v2;
	temp.x = abs(temp.x);
	return temp.x < eps;
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_epsilon_equal<gin::vec<2, T>>::call(const vec<2, T>& v1, const vec<2, T>& v2, const T& eps)
{
	vec<2, T> temp = v1 - v2;
	temp.x = abs(temp.x);
	temp.y = abs(temp.y);
	return (temp.x < eps) && (temp.y < eps);
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_epsilon_equal<gin::vec<3, T>>::call(const vec<3, T>& v1, const vec<3, T>& v2, const T& eps)
{
	vec<3, T> temp = v1 - v2;
	temp.x = abs(temp.x);
	temp.y = abs(temp.y);
	temp.z = abs(temp.z);
	return (temp.x < eps) && (temp.y < eps) && (temp.z < eps);
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_epsilon_equal<gin::vec<4, T>>::call(const vec<4, T>& v1, const vec<4, T>& v2, const T& eps)
{
	vec<4, T> temp = v1 - v2;
	temp.x = abs(temp.x);
	temp.y = abs(temp.y);
	temp.z = abs(temp.z);
	temp.w = abs(temp.w);
	return (temp.x < eps) && (temp.y < eps) && (temp.z < eps) && (temp.w < eps);
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_epsilon_equal<gin::mat<2, 2, T>>::call(const mat<2, 2, T>& m1, const mat<2, 2, T>& m2, const T& eps)
{
	return (m1[0] == m2[0]) && (m1[1] == m2[1]);
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_epsilon_equal<gin::mat<2, 3, T>>::call(const mat<2, 3, T>& m1, const mat<2, 3, T>& m2, const T& eps)
{
	return (m1[0] == m2[0]) && (m1[1] == m2[1]);
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_epsilon_equal<gin::mat<2, 4, T>>::call(const mat<2, 4, T>& m1, const mat<2, 4, T>& m2, const T& eps)
{
	return (m1[0] == m2[0]) && (m1[1] == m2[1]);
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_epsilon_equal<gin::mat<3, 2, T>>::call(const mat<3, 2, T>& m1, const mat<3, 2, T>& m2, const T& eps)
{
	return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]);
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_epsilon_equal<gin::mat<3, 3, T>>::call(const mat<3, 3, T>& m1, const mat<3, 3, T>& m2, const T& eps)
{
	return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]);
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_epsilon_equal<gin::mat<3, 4, T>>::call(const mat<3, 4, T>& m1, const mat<3, 4, T>& m2, const T& eps)
{
	return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]);
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_epsilon_equal<gin::mat<4, 2, T>>::call(const mat<4, 2, T>& m1, const mat<4, 2, T>& m2, const T& eps)
{
	return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]) && (m1[3] == m2[3]);
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_epsilon_equal<gin::mat<4, 3, T>>::call(const mat<4, 3, T>& m1, const mat<4, 3, T>& m2, const T& eps)
{
	return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]) && (m1[3] == m2[3]);
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_epsilon_equal<gin::mat<4, 4, T>>::call(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2, const T& eps)
{
	return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]) && (m1[3] == m2[3]);
}

template<gin::length_t L, typename T>
GINNER_CONSTEXPR T gin::dot(const vec<L, T>& v1, const vec<L, T>& v2)
{
	return compute_dot<L, T>::call(v1, v2);
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_dot<1, T>::call(const vec<1, T>& v1, const vec<1, T>& v2)
{
	return v1.x * v2.x;
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_dot<2, T>::call(const vec<2, T>& v1, const vec<2, T>& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_dot<3, T>::call(const vec<3, T>& v1, const vec<3, T>& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_dot<4, T>::call(const vec<4, T>& v1, const vec<4, T>& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

template<typename T>
GINNER_CONSTEXPR gin::vec<3, T> gin::cross(const vec<3, T>& v1, const vec<3, T>& v2)
{
	return vec<3, T>(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

template<gin::length_t L, typename T>
GINNER_CONSTEXPR T gin::length(const vec<L, T>& v)
{
	return compute_length<L, T>::call(v);
}

template<gin::length_t L, typename T>
GINNER_CONSTEXPR T gin::distance(const vec<L, T>& p1, const vec<L, T>& p2)
{
	return length(p2 - p1);
}

template<gin::length_t L, typename T>
GINNER_CONSTEXPR gin::vec<L, T> gin::normalize(const vec<L, T>& v)
{
	return v / length(v);
}

template<typename T>
GINNER_CONSTEXPR T gin::determinant(const mat2x2<T>& m)
{
	return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

template<typename T>
GINNER_CONSTEXPR T gin::determinant(const mat3x3<T>& m)
{
	return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
		- m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
		+ m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}

template<typename T>
GINNER_CONSTEXPR T gin::determinant(const mat4x4<T>& m)
{
	return m[0][0] * determinant(mat3x3<T>(m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3])) -
		m[0][1] * determinant(mat3x3<T>(m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3])) +
		m[0][2] * determinant(mat3x3<T>(m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3])) -
		m[0][3] * determinant(mat3x3<T>(m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]));

}

template<typename T>
GINNER_CONSTEXPR gin::mat2x2<T> gin::inverse(const mat2x2<T>& m)
{
	return (static_cast<T>(1) / (m[0][0] * m[1][1] - m[0][1] * m[1][0])) * mat2x2<T>(m[1][1], -m[0][1], -m[1][0], m[0][0]);
}

template<typename T>
GINNER_CONSTEXPR gin::mat3x3<T> gin::inverse(const mat3x3<T>& m)
{
	return mat3x3<T>(
		 determinant(mat2x2<T>(m[1][1], m[1][2], m[2][1], m[2][2])),
		-determinant(mat2x2<T>(m[0][1], m[0][2], m[2][1], m[2][2])),
		 determinant(mat2x2<T>(m[0][1], m[0][2], m[1][1], m[1][2])),
		
		-determinant(mat2x2<T>(m[1][0], m[1][2], m[2][0], m[2][2])),
		 determinant(mat2x2<T>(m[0][0], m[0][2], m[2][0], m[2][2])),
		-determinant(mat2x2<T>(m[0][0], m[0][2], m[1][0], m[1][2])),

		 determinant(mat2x2<T>(m[1][0], m[1][1], m[2][0], m[2][1])),
		-determinant(mat2x2<T>(m[0][0], m[0][1], m[2][0], m[2][1])),
		 determinant(mat2x2<T>(m[0][0], m[0][1], m[1][0], m[1][1]))
	)
		/ determinant(m);
}

template<typename T>
GINNER_CONSTEXPR gin::mat4x4<T> gin::inverse(const mat4x4<T>& m)
{
	return mat4x4<T>(
		determinant(mat3x3<T>(m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3])),
		-determinant(mat3x3<T>(m[0][1], m[0][2], m[0][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3])),
		determinant(mat3x3<T>(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[3][1], m[3][2], m[3][3])),
		-determinant(mat3x3<T>(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3])),

		-determinant(mat3x3<T>(m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3])),
		determinant(mat3x3<T>(m[0][0], m[0][2], m[0][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3])),
		-determinant(mat3x3<T>(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[3][0], m[3][2], m[3][3])),
		determinant(mat3x3<T>(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3])),

		determinant(mat3x3<T>(m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3])),
		-determinant(mat3x3<T>(m[0][0], m[0][1], m[0][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3])),
		determinant(mat3x3<T>(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[3][0], m[3][1], m[3][3])),
		-determinant(mat3x3<T>(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3])),

		-determinant(mat3x3<T>(m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2])),
		determinant(mat3x3<T>(m[0][0], m[0][1], m[0][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2])),
		-determinant(mat3x3<T>(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[3][0], m[3][1], m[3][2])),
		determinant(mat3x3<T>(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2]))
	) / determinant(m);
}

template <gin::length_t C, gin::length_t R, typename T>
GINNER_CONSTEXPR gin::mat<R, C, T> gin::transpose(const mat<C, R, T>& m)
{
	return compute_transpose<C, R, T>::call(m);
}

template<typename T>
GINNER_CONSTEXPR gin::mat<2, 2, T> gin::compute_transpose<2, 2, T>::call(const mat<2, 2, T>& m)
{
	return mat2x2<T>(m[0][0], m[1][0], m[0][1], m[1][1]);
}

template<typename T>
GINNER_CONSTEXPR gin::mat<3, 2, T> gin::compute_transpose<2, 3, T>::call(const mat<2, 3, T>& m)
{
	return mat3x2<T>(m[0][0], m[1][0], m[0][1], m[1][1], m[0][2], m[1][2]);
}

template<typename T>
GINNER_CONSTEXPR gin::mat<4, 2, T> gin::compute_transpose<2, 4, T>::call(const mat<2, 4, T>& m)
{
	return mat4x2<T>(m[0][0], m[1][0], m[0][1], m[1][1], m[0][2], m[1][2], m[0][3], m[1][3]);
}

template<typename T>
GINNER_CONSTEXPR gin::mat<2, 3, T> gin::compute_transpose<3, 2, T>::call(const mat<3, 2, T>& m)
{
	return mat2x3<T>(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1]);
}

template<typename T>
GINNER_CONSTEXPR gin::mat<3, 3, T> gin::compute_transpose<3, 3, T>::call(const mat<3, 3, T>& m)
{
	return mat3x3<T>(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2]);
}

template<typename T>
GINNER_CONSTEXPR gin::mat<4, 3, T> gin::compute_transpose<3, 4, T>::call(const mat<3, 4, T>& m)
{
	return mat4x3<T>(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2], m[0][3], m[1][3], m[2][3]);
}

template<typename T>
GINNER_CONSTEXPR gin::mat<2, 4, T> gin::compute_transpose<4, 2, T>::call(const mat<4, 2, T>& m)
{
	return mat2x4<T>(m[0][0], m[1][0], m[2][0], m[3][0], m[0][1], m[1][1], m[2][1], m[3][1]);
}

template<typename T>
GINNER_CONSTEXPR gin::mat<3, 4, T> gin::compute_transpose<4, 3, T>::call(const mat<4, 3, T>& m)
{
	return mat3x4<T>(m[0][0], m[1][0], m[2][0], m[3][0], m[0][1], m[1][1], m[2][1], m[3][1], m[0][2], m[1][2], m[2][2], m[3][2]);
}

template<typename T>
GINNER_CONSTEXPR gin::mat<4, 4, T> gin::compute_transpose<4, 4, T>::call(const mat<4, 4, T>& m)
{
	return mat4x4<T>(m[0][0], m[1][0], m[2][0], m[3][0], m[0][1], m[1][1], m[2][1], m[3][1], m[0][2], m[1][2], m[2][2], m[3][2], m[0][3], m[1][3], m[2][3], m[3][3]);
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_length<1, T>::call(const vec<1, T>& v)
{
	return v.x;
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_length<2, T>::call(const vec<2, T>& v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_length<3, T>::call(const vec<3, T>& v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

template<typename T>
GINNER_CONSTEXPR T gin::compute_length<4, T>::call(const vec<4, T>& v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}