#include "ginner_mat.h"

namespace gin
{

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T>::mat()
	{
		value[0] = vec<2, T>();
		value[1] = vec<2, T>();
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T>::mat(const T& x1, const T& y1, const T& x2, const T& y2)
	{
		value[0] = vec<2, T>(x1, y1);
		value[1] = vec<2, T>(x2, y2);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T>::mat(const row_t & r1, const row_t & r2)
	{
		value[0] = r1;
		value[1] = r2;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T>::mat(const mat<2, 2, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
	}

	template<typename T>
	template<typename X1, typename Y1, typename X2, typename Y2>
	GINNER_CONSTEXPR mat<2, 2, T>::mat(const X1& x1, const Y1& y1, const X2& x2, const Y2& y2)
	{
		value[0] = vec<2, T>(x1, y1);
		value[1] = vec<2, T>(x2, y2);
	}

	template<typename T>
	template<typename V1, typename V2>
	GINNER_CONSTEXPR mat<2, 2, T>::mat(const vec<2, V1>& r1, const vec<2, V2>& r2)
	{
		value[0] = r1;
		value[1] = r2;
	}

	template<typename T>
	template<typename U>
	GINNER_CONSTEXPR mat<2, 2, T>::mat(const mat<2, 2, U>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator=(const mat<2, 2, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T>& mat<2, 2, T>::operator[](length_t i)
	{
		GINNER_ASSERT_LENGTH(i, 2);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR const vec<2, T>& mat<2, 2, T>::operator[](length_t i) const
	{
		GINNER_ASSERT_LENGTH(i, 2);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T> mat<2, 2, T>::operator+() const
	{
		return mat<2, 2, T>(value[0], value[1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T> mat<2, 2, T>::operator-() const
	{
		return mat<2, 2, T>(-value[0], -value[1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator++()
	{
		++value[0];
		++value[1];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T> mat<2, 2, T>::operator++(int)
	{
		mat<2, 2, T> result(*this);
		++value[0];
		++value[1];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator--()
	{
		--value[0];
		--value[1];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T> mat<2, 2, T>::operator--(int)
	{
		mat<2, 2, T> result(*this);
		--value[0];
		--value[1];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator+=(const mat<2, 2, T>& v)
	{
		value[0] += v.value[0];
		value[1] += v.value[1];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator-=(const mat<2, 2, T>& v)
	{
		value[0] -= v.value[0];
		value[1] -= v.value[1];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator*=(const T& k)
	{
		value[0] *= k;
		value[1] *= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator/=(const T& k)
	{
		value[0] /= k;
		value[1] /= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator%=(const T& k)
	{
		value[0] %= k;
		value[1] %= k;
		return *this;
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<2, 2, T>& left, const mat<2, 2, T>& right)
	{
		return ((left[0] == right[0]) && (left[1] == right[1]));
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<2, 2, T>& left, const mat<2, 2, T>& right)
	{
		return !(left == right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator+(const mat<2, 2, T>& left, const mat<2, 2, T>& right)
	{
		return mat<2, 2, T>(left[0] + right[0], left[1] + right[1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator-(const mat<2, 2, T>& left, const mat<2, 2, T>& right)
	{
		return mat<2, 2, T>(left[0] - right[0], left[1] - right[1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator*(const mat<2, 2, T>& left, const T& right)
	{
		return mat<2, 2, T>(left[0] * right, left[1] * right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator*(const T& left, const mat<2, 2, T>& right)
	{
		return mat<2, 2, T>(left * right[0], left * right[1]);
	}

	template <typename T>
	GINNER_CONSTEXPR typename mat<2, 2, T>::col_t operator*(const mat<2, 2, T>& left, const typename mat<2, 2, T>::row_t& right)
	{
		return typename mat<2, 2, T>::col_t(
			left[0][0] * right[0] + left[0][1] * right[1],
			left[1][0] * right[0] + left[1][1] * right[1]
		);
	}

	template <typename T>
	GINNER_CONSTEXPR typename mat<2, 2, T>::row_t operator*(const typename mat<2, 2, T>::col_t& left, const mat<2, 2, T>& right)
	{
		return typename mat<2, 2, T>::row_t(
			left[0] * right[0][0] + left[1] * right[1][0],
			left[0] * right[0][1] + left[1] * right[1][1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator*(const mat<2, 2, T>& left, const mat<2, 2, T>& right)
	{
		return mat<2, 2, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0], 
			left[0][0] * right[0][1] + left[0][1] * right[1][1],
			left[1][0] * right[0][0] + left[1][1] * right[1][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator*(const mat<2, 2, T>& left, const mat<2, 3, T>& right)
	{
		return mat<2, 3, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2],
			left[1][0] * right[0][0] + left[1][1] * right[1][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator*(const mat<2, 2, T>& left, const mat<2, 4, T>& right)
	{
		return mat<2, 4, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2],
			left[0][0] * right[0][3] + left[0][1] * right[1][3],
			left[1][0] * right[0][0] + left[1][1] * right[1][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2],
			left[1][0] * right[0][3] + left[1][1] * right[1][3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator/(const mat<2, 2, T>& left, const T& right)
	{
		return mat<2, 2, T>(left[0] / right, left[1] / right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator%(const mat<2, 2, T>& left, const T& right)
	{
		return mat<2, 2, T>(left[0] % right, left[1] % right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T>::mat()
	{
		value[0] = vec<3, T>();
		value[1] = vec<3, T>();
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T>::mat(const T& x1, const T& y1, const T& z1, const T& x2, const T& y2, const T& z2)
	{
		value[0] = vec<3, T>(x1, y1, z1);
		value[1] = vec<3, T>(x2, y2, z2);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T>::mat(const row_t& r1, const row_t& r2)
	{
		value[0] = r1;
		value[1] = r2;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T>::mat(const mat<2, 3, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
	}

	template<typename T>
	template<typename X1, typename Y1, typename Z1, typename X2, typename Y2, typename Z2>
	GINNER_CONSTEXPR mat<2, 3, T>::mat(const X1& x1, const Y1& y1, const Z1& z1, const X2& x2, const Y2& y2, const Z2& z2)
	{
		value[0] = vec<3, T>(x1, y1, z1);
		value[1] = vec<3, T>(x2, y2, z2);
	}

	template<typename T>
	template<typename V1, typename V2>
	GINNER_CONSTEXPR mat<2, 3, T>::mat(const vec<3, V1>& r1, const vec<3, V2>& r2)
	{
		value[0] = r1;
		value[1] = r2;
	}

	template<typename T>
	template<typename U>
	GINNER_CONSTEXPR mat<2, 3, T>::mat(const mat<2, 3, U>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T>& mat<2, 3, T>::operator=(const mat<2, 3, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T>& mat<2, 3, T>::operator[](length_t i)
	{
		GINNER_ASSERT_LENGTH(i, 2);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR const vec<3, T>& mat<2, 3, T>::operator[](length_t i) const
	{
		GINNER_ASSERT_LENGTH(i, 2);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T> mat<2, 3, T>::operator+() const
	{
		return mat<2, 3, T>(value[0], value[1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T> mat<2, 3, T>::operator-() const
	{
		return mat<2, 3, T>(-value[0], -value[1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T>& mat<2, 3, T>::operator++()
	{
		++value[0];
		++value[1];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T> mat<2, 3, T>::operator++(int)
	{
		mat<2, 3, T> result(*this);
		++value[0];
		++value[1];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T>& mat<2, 3, T>::operator--()
	{
		--value[0];
		--value[1];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T> mat<2, 3, T>::operator--(int)
	{
		mat<2, 3, T> result(*this);
		--value[0];
		--value[1];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T>& mat<2, 3, T>::operator+=(const mat<2, 3, T>& v)
	{
		value[0] += v.value[0];
		value[1] += v.value[1];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T>& mat<2, 3, T>::operator-=(const mat<2, 3, T>& v)
	{
		value[0] -= v.value[0];
		value[1] -= v.value[1];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T>& mat<2, 3, T>::operator*=(const T& k)
	{
		value[0] *= k;
		value[1] *= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T>& mat<2, 3, T>::operator/=(const T& k)
	{
		value[0] /= k;
		value[1] /= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T>& mat<2, 3, T>::operator%=(const T& k)
	{
		value[0] %= k;
		value[1] %= k;
		return *this;
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<2, 3, T>& left, const mat<2, 3, T>& right)
	{
		return ((left[0] == right[0]) && (left[1] == right[1]));
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<2, 3, T>& left, const mat<2, 3, T>& right)
	{
		return !(left == right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator+(const mat<2, 3, T>& left, const mat<2, 3, T>& right)
	{
		return mat<2, 3, T>(left[0] + right[0], left[1] + right[1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator-(const mat<2, 3, T>& left, const mat<2, 3, T>& right)
	{
		return mat<2, 3, T>(left[0] - right[0], left[1] - right[1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator*(const mat<2, 3, T>& left, const T& right)
	{
		return mat<2, 3, T>(left[0] * right, left[1] * right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator*(const T& left, const mat<2, 3, T>& right)
	{
		return mat<2, 3, T>(left * right[0], left * right[1]);
	}

	template<typename T>
	GINNER_CONSTEXPR typename mat<2, 3, T>::col_t operator*(const mat<2, 3, T>& left, const typename mat<2, 3, T>::row_t& right)
	{
		return typename mat<2, 3, T>::col_t(
			left[0][0] * right[0] + left[0][1] * right[1] + left[0][2] * right[2],
			left[1][0] * right[0] + left[1][1] * right[1] + left[1][2] * right[2]
		);
	}

	template<typename T>
	GINNER_CONSTEXPR typename mat<2, 3, T>::row_t operator*(const typename mat<2, 3, T>::col_t& left, const mat<2, 3, T>& right)
	{
		return typename mat<2, 3, T>::row_t(
			left[0] * right[0][0] + left[1] * right[1][0],
			left[0] * right[0][1] + left[1] * right[1][1],
			left[0] * right[0][2] + left[1] * right[1][2]
		);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator*(const mat<2, 3, T>& left, const mat<3, 2, T>& right)
	{
		return mat<2, 2, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator*(const mat<2, 3, T>& left, const mat<3, 3, T>& right)
	{
		return mat<2, 3, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2] + left[0][2] * right[2][2],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2] + left[1][2] * right[2][2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator*(const mat<2, 3, T>& left, const mat<3, 4, T>& right)
	{
		return mat<2, 4, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2] + left[0][2] * right[2][2],
			left[0][0] * right[0][3] + left[0][1] * right[1][3] + left[0][2] * right[2][3],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2] + left[1][2] * right[2][2],
			left[1][0] * right[0][3] + left[1][1] * right[1][3] + left[1][2] * right[2][3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator/(const mat<2, 3, T>& left, const T& right)
	{
		return mat<2, 3, T>(left[0] / right, left[1] / right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator%(const mat<2, 3, T>& left, const T& right)
	{
		return mat<2, 3, T>(left[0] % right, left[1] % right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T>::mat()
	{
		value[0] = vec<4, T>();
		value[1] = vec<4, T>();
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T>::mat(const T& x1, const T& y1, const T& z1, const T& w1, const T& x2, const T& y2, const T& z2, const T& w2)
	{
		value[0] = vec<4, T>(x1, y1, z1, w1);
		value[1] = vec<4, T>(x2, y2, z2, w2);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T>::mat(const row_t& r1, const row_t& r2)
	{
		value[0] = r1;
		value[1] = r2;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T>::mat(const mat<2, 4, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
	}

	template<typename T>
	template<typename X1, typename Y1, typename Z1, typename W1, typename X2, typename Y2, typename Z2, typename W2>
	GINNER_CONSTEXPR mat<2, 4, T>::mat(const X1& x1, const Y1& y1, const Z1& z1, const W1& w1,
		const X2& x2, const Y2& y2, const Z2& z2, const W2& w2)
	{
		value[0] = vec<4, T>(x1, y1, z1, w1);
		value[1] = vec<4, T>(x2, y2, z2, w2);
	}

	template<typename T>
	template<typename V1, typename V2>
	GINNER_CONSTEXPR mat<2, 4, T>::mat(const vec<4, V1>& r1, const vec<4, V2>& r2)
	{
		value[0] = r1;
		value[1] = r2;
	}

	template<typename T>
	template<typename U>
	GINNER_CONSTEXPR mat<2, 4, T>::mat(const mat<2, 4, U>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T>& mat<2, 4, T>::operator=(const mat<2, 4, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T>& mat<2, 4, T>::operator[](length_t i)
	{
		GINNER_ASSERT_LENGTH(i, 2);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR const vec<4, T>& mat<2, 4, T>::operator[](length_t i) const
	{
		GINNER_ASSERT_LENGTH(i, 2);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T> mat<2, 4, T>::operator+() const
	{
		return mat<2, 4, T>(value[0], value[1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T> mat<2, 4, T>::operator-() const
	{
		return mat<2, 4, T>(-value[0], -value[1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T>& mat<2, 4, T>::operator++()
	{
		++value[0];
		++value[1];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T> mat<2, 4, T>::operator++(int)
	{
		mat<2, 4, T> result(*this);
		++value[0];
		++value[1];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T>& mat<2, 4, T>::operator--()
	{
		--value[0];
		--value[1];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T> mat<2, 4, T>::operator--(int)
	{
		mat<2, 4, T> result(*this);
		--value[0];
		--value[1];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T>& mat<2, 4, T>::operator+=(const mat<2, 4, T>& v)
	{
		value[0] += v.value[0];
		value[1] += v.value[1];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T>& mat<2, 4, T>::operator-=(const mat<2, 4, T>& v)
	{
		value[0] -= v.value[0];
		value[1] -= v.value[1];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T>& mat<2, 4, T>::operator*=(const T& k)
	{
		value[0] *= k;
		value[1] *= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T>& mat<2, 4, T>::operator/=(const T& k)
	{
		value[0] /= k;
		value[1] /= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T>& mat<2, 4, T>::operator%=(const T& k)
	{
		value[0] %= k;
		value[1] %= k;
		return *this;
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<2, 4, T>& left, const mat<2, 4, T>& right)
	{
		return ((left[0] == right[0]) && (left[1] == right[1]));
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<2, 4, T>& left, const mat<2, 4, T>& right)
	{
		return !(left == right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator+(const mat<2, 4, T>& left, const mat<2, 4, T>& right)
	{
		return mat<2, 4, T>(left[0] + right[0], left[1] + right[1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator-(const mat<2, 4, T>& left, const mat<2, 4, T>& right)
	{
		return mat<2, 4, T>(left[0] - right[0], left[1] - right[1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator*(const mat<2, 4, T>& left, const T& right)
	{
		return mat<2, 4, T>(left[0] * right, left[1] * right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator*(const T& left, const mat<2, 4, T>& right)
	{
		return mat<2, 4, T>(left * right[0], left * right[1]);
	}

	template<typename T>
	GINNER_CONSTEXPR typename mat<2, 4, T>::col_t operator*(const mat<2, 4, T>& left, const typename mat<2, 4, T>::row_t& right)
	{
		return typename mat<2, 4, T>::col_t(
			left[0][0] * right[0] + left[0][1] * right[1] + left[0][2] * right[2] + left[0][3] * right[3],
			left[1][0] * right[0] + left[1][1] * right[1] + left[1][2] * right[2] + left[1][3] * right[3]
		);
	}

	template<typename T>
	GINNER_CONSTEXPR typename mat<2, 4, T>::row_t operator*(const typename mat<2, 4, T>::col_t& left, const mat<2, 4, T>& right)
	{
		return typename mat<2, 4, T>::row_t(
			left[0] * right[0][0] + left[1] * right[1][0],
			left[0] * right[0][1] + left[1] * right[1][1],
			left[0] * right[0][2] + left[1] * right[1][2],
			left[0] * right[0][3] + left[1] * right[1][3]
		);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator*(const mat<2, 4, T>& left, const mat<4, 2, T>& right)
	{
		return mat<2, 2, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0] + left[0][3] * right[3][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1] + left[0][3] * right[3][1],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0] + left[1][3] * right[3][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1] + left[1][3] * right[3][1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator*(const mat<2, 4, T>& left, const mat<4, 3, T>& right)
	{
		return mat<2, 3, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0] + left[0][3] * right[3][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1] + left[0][3] * right[3][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2] + left[0][2] * right[2][2] + left[0][3] * right[3][2],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0] + left[1][3] * right[3][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1] + left[1][3] * right[3][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2] + left[1][2] * right[2][2] + left[1][3] * right[3][2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator*(const mat<2, 4, T>& left, const mat<4, 4, T>& right)
	{
		return mat<2, 4, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0] + left[0][3] * right[3][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1] + left[0][3] * right[3][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2] + left[0][2] * right[2][2] + left[0][3] * right[3][2],
			left[0][0] * right[0][3] + left[0][1] * right[1][3] + left[0][2] * right[2][3] + left[0][3] * right[3][3],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0] + left[1][3] * right[3][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1] + left[1][3] * right[3][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2] + left[1][2] * right[2][2] + left[1][3] * right[3][2],
			left[1][0] * right[0][3] + left[1][1] * right[1][3] + left[1][2] * right[2][3] + left[1][3] * right[3][3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator/(const mat<2, 4, T>& left, const T& right)
	{
		return mat<2, 4, T>(left[0] / right, left[1] / right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator%(const mat<2, 4, T>& left, const T& right)
	{
		return mat<2, 4, T>(left[0] % right, left[1] % right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T>::mat()
	{
		value[0] = vec<2, T>();
		value[1] = vec<2, T>();
		value[2] = vec<2, T>();
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T>::mat(const T& x1, const T& y1, const T& x2, const T& y2, const T& x3, const T& y3)
	{
		value[0] = vec<2, T>(x1, y1);
		value[1] = vec<2, T>(x2, y2);
		value[2] = vec<2, T>(x3, y3);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T>::mat(const row_t& r1, const row_t& r2, const row_t& r3)
	{
		value[0] = r1;
		value[1] = r2;
		value[2] = r3;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T>::mat(const mat<3, 2, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
	}

	template<typename T>
	template<typename X1, typename Y1, typename X2, typename Y2, typename X3, typename Y3>
	GINNER_CONSTEXPR mat<3, 2, T>::mat(const X1& x1, const Y1& y1, const X2& x2, const Y2& y2, const X3& x3, const Y3& y3)
	{
		value[0] = vec<2, T>(x1, y1);
		value[1] = vec<2, T>(x2, y2);
		value[2] = vec<2, T>(x3, y3);
	}

	template<typename T>
	template<typename V1, typename V2, typename V3>
	GINNER_CONSTEXPR mat<3, 2, T>::mat(const vec<2, V1>& r1, const vec<2, V2>& r2, const vec<2, V3>& r3)
	{
		value[0] = r1;
		value[1] = r2;
		value[2] = r3;
	}

	template<typename T>
	template<typename U>
	GINNER_CONSTEXPR mat<3, 2, T>::mat(const mat<3, 2, U>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T>& mat<3, 2, T>::operator=(const mat<3, 2, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T>& mat<3, 2, T>::operator[](length_t i)
	{
		GINNER_ASSERT_LENGTH(i, 3);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR const vec<2, T>& mat<3, 2, T>::operator[](length_t i) const
	{
		GINNER_ASSERT_LENGTH(i, 3);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T> mat<3, 2, T>::operator+() const
	{
		return mat<3, 2, T>(value[0], value[1], value[2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T> mat<3, 2, T>::operator-() const
	{
		return mat<3, 2, T>(-value[0], -value[1], -value[2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T>& mat<3, 2, T>::operator++()
	{
		++value[0];
		++value[1];
		++value[2];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T> mat<3, 2, T>::operator++(int)
	{
		mat<3, 2, T> result(*this);
		++value[0];
		++value[1];
		++value[2];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T>& mat<3, 2, T>::operator--()
	{
		--value[0];
		--value[1];
		--value[2];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T> mat<3, 2, T>::operator--(int)
	{
		mat<3, 2, T> result(*this);
		--value[0];
		--value[1];
		--value[2];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T>& mat<3, 2, T>::operator+=(const mat<3, 2, T>& v)
	{
		value[0] += v.value[0];
		value[1] += v.value[1];
		value[2] += v.value[2];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T>& mat<3, 2, T>::operator-=(const mat<3, 2, T>& v)
	{
		value[0] -= v.value[0];
		value[1] -= v.value[1];
		value[2] -= v.value[2];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T>& mat<3, 2, T>::operator*=(const T& k)
	{
		value[0] *= k;
		value[1] *= k;
		value[2] *= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T>& mat<3, 2, T>::operator/=(const T& k)
	{
		value[0] /= k;
		value[1] /= k;
		value[2] /= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T>& mat<3, 2, T>::operator%=(const T& k)
	{
		value[0] %= k;
		value[1] %= k;
		value[2] %= k;
		return *this;
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<3, 2, T>& left, const mat<3, 2, T>& right)
	{
		return ((left[0] == right[0]) && (left[1] == right[1]) && (left[2] == right[2]));
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<3, 2, T>& left, const mat<3, 2, T>& right)
	{
		return !(left == right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator+(const mat<3, 2, T>& left, const mat<3, 2, T>& right)
	{
		return mat<3, 2, T>(left[0] + right[0], left[1] + right[1], left[2] + right[2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator-(const mat<3, 2, T>& left, const mat<3, 2, T>& right)
	{
		return mat<3, 2, T>(left[0] - right[0], left[1] - right[1], left[2] - right[2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator*(const mat<3, 2, T>& left, const T& right)
	{
		return mat<3, 2, T>(left[0] * right, left[1] * right, left[2] * right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator*(const T& left, const mat<3, 2, T>& right)
	{
		return mat<3, 2, T>(left * right[0], left * right[1], left * right[2]);
	}

	template <typename T>
	GINNER_CONSTEXPR typename mat<3, 2, T>::col_t operator*(const mat<3, 2, T>& left, const typename mat<3, 2, T>::row_t& right)
	{
		return typename mat<3, 2, T>::col_t(
			left[0][0] * right[0] + left[0][1] * right[1],
			left[1][0] * right[0] + left[1][1] * right[1],
			left[2][0] * right[0] + left[2][1] * right[1]
		);
	}

	template <typename T>
	GINNER_CONSTEXPR typename mat<3, 2, T>::row_t operator*(const typename mat<3, 2, T>::col_t& left, const mat<3, 2, T>& right)
	{
		return typename mat<3, 2, T>::row_t(
			left[0] * right[0][0] + left[1] * right[1][0] + left[2] * right[2][0],
			left[0] * right[0][1] + left[1] * right[1][1] + left[2] * right[2][1]
			);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator*(const mat<3, 2, T>& left, const mat<2, 2, T>& right)
	{
		return mat<3, 2, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1],
			left[1][0] * right[0][0] + left[1][1] * right[1][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1],
			left[2][0] * right[0][0] + left[2][1] * right[1][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator*(const mat<3, 2, T>& left, const mat<2, 3, T>& right)
	{
		return mat<3, 3, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2],
			left[1][0] * right[0][0] + left[1][1] * right[1][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2],
			left[2][0] * right[0][0] + left[2][1] * right[1][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1],
			left[2][0] * right[0][2] + left[2][1] * right[1][2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator*(const mat<3, 2, T>& left, const mat<2, 4, T>& right)
	{
		return mat<3, 4, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2],
			left[0][0] * right[0][3] + left[0][1] * right[1][3],
			left[1][0] * right[0][0] + left[1][1] * right[1][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2],
			left[1][0] * right[0][3] + left[1][1] * right[1][3],
			left[2][0] * right[0][0] + left[2][1] * right[1][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1],
			left[2][0] * right[0][2] + left[2][1] * right[1][2],
			left[2][0] * right[0][3] + left[2][1] * right[1][3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator/(const mat<3, 2, T>& left, const T& right)
	{
		return mat<3, 2, T>(left[0] / right, left[1] / right, left[2] / right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator%(const mat<3, 2, T>& left, const T& right)
	{
		return mat<3, 2, T>(left[0] % right, left[1] % right, left[2] % right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T>::mat()
	{
		value[0] = vec<3, T>();
		value[1] = vec<3, T>();
		value[2] = vec<3, T>();
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T>::mat(const T& x1, const T& y1, const T& z1, const T& x2, const T& y2, const T& z2, const T& x3, const T& y3, const T& z3)
	{
		value[0] = vec<3, T>(x1, y1, z1);
		value[1] = vec<3, T>(x2, y2, z2);
		value[2] = vec<3, T>(x3, y3, z3);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T>::mat(const row_t& r1, const row_t& r2, const row_t& r3)
	{
		value[0] = r1;
		value[1] = r2;
		value[2] = r3;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T>::mat(const mat<3, 3, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
	}

	template<typename T>
	template<typename X1, typename Y1, typename Z1, typename X2, typename Y2, typename Z2, typename X3, typename Y3, typename Z3>
	GINNER_CONSTEXPR mat<3, 3, T>::mat(const X1& x1, const Y1& y1, const Z1& z1, const X2& x2, const Y2& y2, const Z2& z2, const X3& x3, const Y3& y3, const Z3& z3)
	{
		value[0] = vec<3, T>(x1, y1, z1);
		value[1] = vec<3, T>(x2, y2, z2);
		value[2] = vec<3, T>(x3, y3, z3);
	}

	template<typename T>
	template<typename V1, typename V2, typename V3>
	GINNER_CONSTEXPR mat<3, 3, T>::mat(const vec<3, V1>& r1, const vec<3, V2>& r2, const vec<3, V3>& r3)
	{
		value[0] = r1;
		value[1] = r2;
		value[2] = r3;
	}

	template<typename T>
	template<typename U>
	GINNER_CONSTEXPR mat<3, 3, T>::mat(const mat<3, 3, U>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T>& mat<3, 3, T>::operator=(const mat<3, 3, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T>& mat<3, 3, T>::operator[](length_t i)
	{
		GINNER_ASSERT_LENGTH(i, 3);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR const vec<3, T>& mat<3, 3, T>::operator[](length_t i) const
	{
		GINNER_ASSERT_LENGTH(i, 3);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T> mat<3, 3, T>::operator+() const
	{
		return mat<3, 3, T>(value[0], value[1], value[2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T> mat<3, 3, T>::operator-() const
	{
		return mat<3, 3, T>(-value[0], -value[1], -value[2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T>& mat<3, 3, T>::operator++()
	{
		++value[0];
		++value[1];
		++value[2];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T> mat<3, 3, T>::operator++(int)
	{
		mat<3, 3, T> result(*this);
		++value[0];
		++value[1];
		++value[2];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T>& mat<3, 3, T>::operator--()
	{
		--value[0];
		--value[1];
		--value[2];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T> mat<3, 3, T>::operator--(int)
	{
		mat<3, 3, T> result(*this);
		--value[0];
		--value[1];
		--value[2];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T>& mat<3, 3, T>::operator+=(const mat<3, 3, T>& v)
	{
		value[0] += v.value[0];
		value[1] += v.value[1];
		value[2] += v.value[2];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T>& mat<3, 3, T>::operator-=(const mat<3, 3, T>& v)
	{
		value[0] -= v.value[0];
		value[1] -= v.value[1];
		value[2] -= v.value[2];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T>& mat<3, 3, T>::operator*=(const T& k)
	{
		value[0] *= k;
		value[1] *= k;
		value[2] *= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T>& mat<3, 3, T>::operator/=(const T& k)
	{
		value[0] /= k;
		value[1] /= k;
		value[2] /= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T>& mat<3, 3, T>::operator%=(const T& k)
	{
		value[0] %= k;
		value[1] %= k;
		value[2] %= k;
		return *this;
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<3, 3, T>& left, const mat<3, 3, T>& right)
	{
		return ((left[0] == right[0]) && (left[1] == right[1]) && (left[2] == right[2]));
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<3, 3, T>& left, const mat<3, 3, T>& right)
	{
		return !(left == right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator+(const mat<3, 3, T>& left, const mat<3, 3, T>& right)
	{
		return mat<3, 3, T>(left[0] + right[0], left[1] + right[1], left[2] + right[2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator-(const mat<3, 3, T>& left, const mat<3, 3, T>& right)
	{
		return mat<3, 3, T>(left[0] - right[0], left[1] - right[1], left[2] - right[2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator*(const mat<3, 3, T>& left, const T& right)
	{
		return mat<3, 3, T>(left[0] * right, left[1] * right, left[2] * right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator*(const T& left, const mat<3, 3, T>& right)
	{
		return mat<3, 3, T>(left * right[0], left * right[1], left * right[2]);
	}

	template <typename T>
	GINNER_CONSTEXPR typename mat<3, 3, T>::col_t operator*(const mat<3, 3, T>& left, const typename mat<3, 3, T>::row_t& right)
	{
		return typename mat<3, 3, T>::col_t(
			left[0][0] * right[0] + left[0][1] * right[1] + left[0][2] * right[2],
			left[1][0] * right[0] + left[1][1] * right[1] + left[1][2] * right[2],
			left[2][0] * right[0] + left[2][1] * right[1] + left[2][2] * right[2]
		);
	}

	template <typename T>
	GINNER_CONSTEXPR typename mat<3, 3, T>::row_t operator*(const typename mat<3, 3, T>::col_t& left, const mat<3, 3, T>& right)
	{
		return typename mat<3, 3, T>::row_t(
			left[0] * right[0][0] + left[1] * right[1][0] + left[2] * right[2][0],
			left[0] * right[0][1] + left[1] * right[1][1] + left[2] * right[2][1],
			left[0] * right[0][2] + left[1] * right[1][2] + left[2] * right[2][2]
		);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator*(const mat<3, 3, T>& left, const mat<3, 2, T>& right)
	{
		return mat<3, 2, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1],
			left[2][0] * right[0][0] + left[2][1] * right[1][0] + left[2][2] * right[2][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1] + left[2][2] * right[2][1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator*(const mat<3, 3, T>& left, const mat<3, 3, T>& right)
	{
		return mat<3, 3, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2] + left[0][2] * right[2][2],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2] + left[1][2] * right[2][2],
			left[2][0] * right[0][0] + left[2][1] * right[1][0] + left[2][2] * right[2][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1] + left[2][2] * right[2][1],
			left[2][0] * right[0][2] + left[2][1] * right[1][2] + left[2][2] * right[2][2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator*(const mat<3, 3, T>& left, const mat<3, 4, T>& right)
	{
		return mat<3, 4, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2] + left[0][2] * right[2][2],
			left[0][0] * right[0][3] + left[0][1] * right[1][3] + left[0][2] * right[2][3],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2] + left[1][2] * right[2][2],
			left[1][0] * right[0][3] + left[1][1] * right[1][3] + left[1][2] * right[2][3],
			left[2][0] * right[0][0] + left[2][1] * right[1][0] + left[2][2] * right[2][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1] + left[2][2] * right[2][1],
			left[2][0] * right[0][2] + left[2][1] * right[1][2] + left[2][2] * right[2][2],
			left[2][0] * right[0][3] + left[2][1] * right[1][3] + left[2][2] * right[2][3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator/(const mat<3, 3, T>& left, const T& right)
	{
		return mat<3, 3, T>(left[0] / right, left[1] / right, left[2] / right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator%(const mat<3, 3, T>& left, const T& right)
	{
		return mat<3, 3, T>(left[0] % right, left[1] % right, left[2] % right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T>::mat()
	{
		value[0] = vec<4, T>();
		value[1] = vec<4, T>();
		value[2] = vec<4, T>();
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T>::mat(
		const T& x1, const T& y1, const T& z1, const T& w1,
		const T& x2, const T& y2, const T& z2, const T& w2,
		const T& x3, const T& y3, const T& z3, const T& w3)
	{
		value[0] = vec<4, T>(x1, y1, z1, w1);
		value[1] = vec<4, T>(x2, y2, z2, w2);
		value[2] = vec<4, T>(x3, y3, z3, w3);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T>::mat(const row_t& r1, const row_t& r2, const row_t& r3)
	{
		value[0] = r1;
		value[1] = r2;
		value[2] = r3;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T>::mat(const mat<3, 4, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
	}

	template<typename T>
	template<
		typename X1, typename Y1, typename Z1, typename W1,
		typename X2, typename Y2, typename Z2, typename W2,
		typename X3, typename Y3, typename Z3, typename W3>
	GINNER_CONSTEXPR mat<3, 4, T>::mat(
		const X1& x1, const Y1& y1, const Z1& z1, const W1& w1,
		const X2& x2, const Y2& y2, const Z2& z2, const W2& w2,
		const X3& x3, const Y3& y3, const Z3& z3, const W3& w3
	)
	{
		value[0] = vec<4, T>(x1, y1, z1, w1);
		value[1] = vec<4, T>(x2, y2, z2, w2);
		value[2] = vec<4, T>(x3, y3, z3, w3);
	}

	template<typename T>
	template<typename V1, typename V2, typename V3>
	GINNER_CONSTEXPR mat<3, 4, T>::mat(const vec<4, V1>& r1, const vec<4, V2>& r2, const vec<4, V3>& r3)
	{
		value[0] = r1;
		value[1] = r2;
		value[2] = r3;
	}

	template<typename T>
	template<typename U>
	GINNER_CONSTEXPR mat<3, 4, T>::mat(const mat<3, 4, U>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T>& mat<3, 4, T>::operator=(const mat<3, 4, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T>& mat<3, 4, T>::operator[](length_t i)
	{
		GINNER_ASSERT_LENGTH(i, 3);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR const vec<4, T>& mat<3, 4, T>::operator[](length_t i) const
	{
		GINNER_ASSERT_LENGTH(i, 3);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T> mat<3, 4, T>::operator+() const
	{
		return mat<3, 4, T>(value[0], value[1], value[2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T> mat<3, 4, T>::operator-() const
	{
		return mat<3, 4, T>(-value[0], -value[1], -value[2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T>& mat<3, 4, T>::operator++()
	{
		++value[0];
		++value[1];
		++value[2];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T> mat<3, 4, T>::operator++(int)
	{
		mat<3, 4, T> result(*this);
		++value[0];
		++value[1];
		++value[2];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T>& mat<3, 4, T>::operator--()
	{
		--value[0];
		--value[1];
		--value[2];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T> mat<3, 4, T>::operator--(int)
	{
		mat<3, 4, T> result(*this);
		--value[0];
		--value[1];
		--value[2];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T>& mat<3, 4, T>::operator+=(const mat<3, 4, T>& v)
	{
		value[0] += v.value[0];
		value[1] += v.value[1];
		value[2] += v.value[2];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T>& mat<3, 4, T>::operator-=(const mat<3, 4, T>& v)
	{
		value[0] -= v.value[0];
		value[1] -= v.value[1];
		value[2] -= v.value[2];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T>& mat<3, 4, T>::operator*=(const T& k)
	{
		value[0] *= k;
		value[1] *= k;
		value[2] *= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T>& mat<3, 4, T>::operator/=(const T& k)
	{
		value[0] /= k;
		value[1] /= k;
		value[2] /= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T>& mat<3, 4, T>::operator%=(const T& k)
	{
		value[0] %= k;
		value[1] %= k;
		value[2] %= k;
		return *this;
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<3, 4, T>& left, const mat<3, 4, T>& right)
	{
		return ((left[0] == right[0]) && (left[1] == right[1]) && (left[2] == right[2]));
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<3, 4, T>& left, const mat<3, 4, T>& right)
	{
		return !(left == right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator+(const mat<3, 4, T>& left, const mat<3, 4, T>& right)
	{
		return mat<3, 4, T>(left[0] + right[0], left[1] + right[1], left[2] + right[2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator-(const mat<3, 4, T>& left, const mat<3, 4, T>& right)
	{
		return mat<3, 4, T>(left[0] - right[0], left[1] - right[1], left[2] - right[2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator*(const mat<3, 4, T>& left, const T& right)
	{
		return mat<3, 4, T>(left[0] * right, left[1] * right, left[2] * right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator*(const T& left, const mat<3, 4, T>& right)
	{
		return mat<3, 4, T>(left * right[0], left * right[1], left * right[2]);
	}

	template <typename T>
	GINNER_CONSTEXPR typename mat<3, 4, T>::col_t operator*(const mat<3, 4, T>& left, const typename mat<3, 4, T>::row_t& right)
	{
		return typename mat<3, 4, T>::col_t(
			left[0][0] * right[0] + left[0][1] * right[1] + left[0][2] * right[2] + left[0][3] * right[3],
			left[1][0] * right[0] + left[1][1] * right[1] + left[1][2] * right[2] + left[1][3] * right[3],
			left[2][0] * right[0] + left[2][1] * right[1] + left[2][2] * right[2] + left[2][3] * right[3]
		);
	}

	template <typename T>
	GINNER_CONSTEXPR typename mat<3, 4, T>::row_t operator*(const typename mat<3, 4, T>::col_t& left, const mat<3, 4, T>& right)
	{
		return typename mat<3, 4, T>::row_t(
			left[0] * right[0][0] + left[1] * right[1][0] + left[2] * right[2][0],
			left[0] * right[0][1] + left[1] * right[1][1] + left[2] * right[2][1],
			left[0] * right[0][2] + left[1] * right[1][2] + left[2] * right[2][2],
			left[0] * right[0][3] + left[1] * right[1][3] + left[2] * right[2][3]
		);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator*(const mat<3, 4, T>& left, const mat<4, 2, T>& right)
	{
		return mat<3, 2, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0] + left[0][3] * right[3][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1] + left[0][3] * right[3][1],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0] + left[1][3] * right[3][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1] + left[1][3] * right[3][1],
			left[2][0] * right[0][0] + left[2][1] * right[1][0] + left[2][2] * right[2][0] + left[2][3] * right[3][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1] + left[2][2] * right[2][1] + left[2][3] * right[3][1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator*(const mat<3, 4, T>& left, const mat<4, 3, T>& right)
	{
		return mat<3, 3, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0] + left[0][3] * right[3][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1] + left[0][3] * right[3][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2] + left[0][2] * right[2][2] + left[0][3] * right[3][2],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0] + left[1][3] * right[3][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1] + left[1][3] * right[3][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2] + left[1][2] * right[2][2] + left[1][3] * right[3][2],
			left[2][0] * right[0][0] + left[2][1] * right[1][0] + left[2][2] * right[2][0] + left[2][3] * right[3][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1] + left[2][2] * right[2][1] + left[2][3] * right[3][1],
			left[2][0] * right[0][2] + left[2][1] * right[1][2] + left[2][2] * right[2][2] + left[2][3] * right[3][2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator*(const mat<3, 4, T>& left, const mat<4, 4, T>& right)
	{
		return mat<3, 4, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0] + left[0][3] * right[3][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1] + left[0][3] * right[3][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2] + left[0][2] * right[2][2] + left[0][3] * right[3][2],
			left[0][0] * right[0][3] + left[0][1] * right[1][3] + left[0][2] * right[2][3] + left[0][3] * right[3][3],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0] + left[1][3] * right[3][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1] + left[1][3] * right[3][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2] + left[1][2] * right[2][2] + left[1][3] * right[3][2],
			left[1][0] * right[0][3] + left[1][1] * right[1][3] + left[1][2] * right[2][3] + left[1][3] * right[3][3],
			left[2][0] * right[0][0] + left[2][1] * right[1][0] + left[2][2] * right[2][0] + left[2][3] * right[3][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1] + left[2][2] * right[2][1] + left[2][3] * right[3][1],
			left[2][0] * right[0][2] + left[2][1] * right[1][2] + left[2][2] * right[2][2] + left[2][3] * right[3][2],
			left[2][0] * right[0][3] + left[2][1] * right[1][3] + left[2][2] * right[2][3] + left[2][3] * right[3][3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator/(const mat<3, 4, T>& left, const T& right)
	{
		return mat<3, 4, T>(left[0] / right, left[1] / right, left[2] / right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator%(const mat<3, 4, T>& left, const T& right)
	{
		return mat<3, 4, T>(left[0] % right, left[1] % right, left[2] % right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T>::mat()
	{
		value[0] = vec<2, T>();
		value[1] = vec<2, T>();
		value[2] = vec<2, T>();
		value[3] = vec<2, T>();
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T>::mat(
		const T& x1, const T& y1,
		const T& x2, const T& y2,
		const T& x3, const T& y3,
		const T& x4, const T& y4)
	{
		value[0] = vec<2, T>(x1, y1);
		value[1] = vec<2, T>(x2, y2);
		value[2] = vec<2, T>(x3, y3);
		value[3] = vec<2, T>(x4, y4);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T>::mat(const row_t& r1, const row_t& r2, const row_t& r3, const row_t& r4)
	{
		value[0] = r1;
		value[1] = r2;
		value[2] = r3;
		value[3] = r4;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T>::mat(const mat<4, 2, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
		value[3] = other.value[3];
	}

	template<typename T>
	template<
		typename X1, typename Y1,
		typename X2, typename Y2,
		typename X3, typename Y3,
		typename X4, typename Y4>
	GINNER_CONSTEXPR mat<4, 2, T>::mat(
		const X1& x1, const Y1& y1,
		const X2& x2, const Y2& y2,
		const X3& x3, const Y3& y3,
		const X4& x4, const Y4& y4)
	{
		value[0] = vec<2, T>(x1, y1);
		value[1] = vec<2, T>(x2, y2);
		value[2] = vec<2, T>(x3, y3);
		value[3] = vec<2, T>(x4, y4);
	}

	template<typename T>
	template<typename V1, typename V2, typename V3, typename V4>
	GINNER_CONSTEXPR mat<4, 2, T>::mat(
		const vec<2, V1>& r1,
		const vec<2, V2>& r2,
		const vec<2, V3>& r3,
		const vec<2, V4>& r4)
	{
		value[0] = r1;
		value[1] = r2;
		value[2] = r3;
		value[3] = r4;
	}

	template<typename T>
	template<typename U>
	GINNER_CONSTEXPR mat<4, 2, T>::mat(const mat<4, 2, U>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
		value[3] = other.value[3];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T>& mat<4, 2, T>::operator=(const mat<4, 2, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
		value[3] = other.value[3];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T>& mat<4, 2, T>::operator[](length_t i)
	{
		GINNER_ASSERT_LENGTH(i, 4);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR const vec<2, T>& mat<4, 2, T>::operator[](length_t i) const
	{
		GINNER_ASSERT_LENGTH(i, 4);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T> mat<4, 2, T>::operator+() const
	{
		return mat<4, 2, T>(value[0], value[1], value[2], value[3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T> mat<4, 2, T>::operator-() const
	{
		return mat<4, 2, T>(-value[0], -value[1], -value[2], -value[3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T>& mat<4, 2, T>::operator++()
	{
		++value[0];
		++value[1];
		++value[2];
		++value[3];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T> mat<4, 2, T>::operator++(int)
	{
		mat<4, 2, T> result(*this);
		++value[0];
		++value[1];
		++value[2];
		++value[3];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T>& mat<4, 2, T>::operator--()
	{
		--value[0];
		--value[1];
		--value[2];
		--value[3];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T> mat<4, 2, T>::operator--(int)
	{
		mat<4, 2, T> result(*this);
		--value[0];
		--value[1];
		--value[2];
		--value[3];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T>& mat<4, 2, T>::operator+=(const mat<4, 2, T>& v)
	{
		value[0] += v.value[0];
		value[1] += v.value[1];
		value[2] += v.value[2];
		value[3] += v.value[3];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T>& mat<4, 2, T>::operator-=(const mat<4, 2, T>& v)
	{
		value[0] -= v.value[0];
		value[1] -= v.value[1];
		value[2] -= v.value[2];
		value[3] -= v.value[3];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T>& mat<4, 2, T>::operator*=(const T& k)
	{
		value[0] *= k;
		value[1] *= k;
		value[2] *= k;
		value[3] *= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T>& mat<4, 2, T>::operator/=(const T& k)
	{
		value[0] /= k;
		value[1] /= k;
		value[2] /= k;
		value[3] /= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T>& mat<4, 2, T>::operator%=(const T& k)
	{
		value[0] %= k;
		value[1] %= k;
		value[2] %= k;
		value[3] %= k;
		return *this;
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<4, 2, T>& left, const mat<4, 2, T>& right)
	{
		return ((left[0] == right[0]) && (left[1] == right[1]) && (left[2] == right[2]) && (left[3] == right[3]));
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<4, 2, T>& left, const mat<4, 2, T>& right)
	{
		return !(left == right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator+(const mat<4, 2, T>& left, const mat<4, 2, T>& right)
	{
		return mat<4, 2, T>(left[0] + right[0], left[1] + right[1], left[2] + right[2], left[3] + right[3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator-(const mat<4, 2, T>& left, const mat<4, 2, T>& right)
	{
		return mat<4, 2, T>(left[0] - right[0], left[1] - right[1], left[2] - right[2], left[3] - right[3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator*(const mat<4, 2, T>& left, const T& right)
	{
		return mat<4, 2, T>(left[0] * right, left[1] * right, left[2] * right, left[3] * right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator*(const T& left, const mat<4, 2, T>& right)
	{
		return mat<4, 2, T>(left * right[0], left * right[1], left * right[2], left * right[3]);
	}

	template <typename T>
	GINNER_CONSTEXPR typename mat<4, 2, T>::col_t operator*(const mat<4, 2, T>& left, const typename mat<4, 2, T>::row_t& right)
	{
		return typename mat<4, 2, T>::col_t(
			left[0][0] * right[0] + left[0][1] * right[1],
			left[1][0] * right[0] + left[1][1] * right[1],
			left[2][0] * right[0] + left[2][1] * right[1],
			left[3][0] * right[0] + left[3][1] * right[1]
		);
	}

	template <typename T>
	GINNER_CONSTEXPR typename mat<4, 2, T>::row_t operator*(const typename mat<4, 2, T>::col_t& left, const mat<4, 2, T>& right)
	{
		return typename mat<4, 2, T>::row_t(
			left[0] * right[0][0] + left[1] * right[1][0] + left[2] * right[2][0] + left[3] * right[3][0],
			left[0] * right[0][1] + left[1] * right[1][1] + left[2] * right[2][1] + left[3] * right[3][1]
		);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator*(const mat<4, 2, T>& left, const mat<2, 2, T>& right)
	{
		return mat<4, 2, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1],
			left[1][0] * right[0][0] + left[1][1] * right[1][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1],
			left[2][0] * right[0][0] + left[2][1] * right[1][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1],
			left[3][0] * right[0][0] + left[3][1] * right[1][0],
			left[3][0] * right[0][1] + left[3][1] * right[1][1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator*(const mat<4, 2, T>& left, const mat<2, 3, T>& right)
	{
		return mat<4, 3, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2],
			left[1][0] * right[0][0] + left[1][1] * right[1][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2],
			left[2][0] * right[0][0] + left[2][1] * right[1][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1],
			left[2][0] * right[0][2] + left[2][1] * right[1][2],
			left[3][0] * right[0][0] + left[3][1] * right[1][0],
			left[3][0] * right[0][1] + left[3][1] * right[1][1],
			left[3][0] * right[0][2] + left[3][1] * right[1][2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator*(const mat<4, 2, T>& left, const mat<2, 4, T>& right)
	{
		return mat<4, 4, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2],
			left[0][0] * right[0][3] + left[0][1] * right[1][3],
			left[1][0] * right[0][0] + left[1][1] * right[1][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2],
			left[1][0] * right[0][3] + left[1][1] * right[1][3],
			left[2][0] * right[0][0] + left[2][1] * right[1][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1],
			left[2][0] * right[0][2] + left[2][1] * right[1][2],
			left[2][0] * right[0][3] + left[2][1] * right[1][3],
			left[3][0] * right[0][0] + left[3][1] * right[1][0],
			left[3][0] * right[0][1] + left[3][1] * right[1][1],
			left[3][0] * right[0][2] + left[3][1] * right[1][2],
			left[3][0] * right[0][3] + left[3][1] * right[1][3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator/(const mat<4, 2, T>& left, const T& right)
	{
		return mat<4, 2, T>(left[0] / right, left[1] / right, left[2] / right, left[3] / right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator%(const mat<4, 2, T>& left, const T& right)
	{
		return mat<4, 2, T>(left[0] % right, left[1] % right, left[2] % right, left[3] % right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T>::mat()
	{
		value[0] = vec<3, T>();
		value[1] = vec<3, T>();
		value[2] = vec<3, T>();
		value[3] = vec<3, T>();
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T>::mat(
		const T& x1, const T& y1, const T& z1,
		const T& x2, const T& y2, const T& z2,
		const T& x3, const T& y3, const T& z3,
		const T& x4, const T& y4, const T& z4)
	{
		value[0] = vec<3, T>(x1, y1, z1);
		value[1] = vec<3, T>(x2, y2, z2);
		value[2] = vec<3, T>(x3, y3, z3);
		value[3] = vec<3, T>(x4, y4, z4);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T>::mat(const row_t& r1, const row_t& r2, const row_t& r3, const row_t& r4)
	{
		value[0] = r1;
		value[1] = r2;
		value[2] = r3;
		value[3] = r4;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T>::mat(const mat<4, 3, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
		value[3] = other.value[3];
	}

	template<typename T>
	template<
		typename X1, typename Y1, typename Z1,
		typename X2, typename Y2, typename Z2,
		typename X3, typename Y3, typename Z3,
		typename X4, typename Y4, typename Z4>
	GINNER_CONSTEXPR mat<4, 3, T>::mat(
		const X1& x1, const Y1& y1, const Z1& z1,
		const X2& x2, const Y2& y2, const Z2& z2,
		const X3& x3, const Y3& y3, const Z3& z3,
		const X4& x4, const Y4& y4, const Z4& z4)
	{
		value[0] = vec<3, T>(x1, y1, z1);
		value[1] = vec<3, T>(x2, y2, z2);
		value[2] = vec<3, T>(x3, y3, z3);
		value[3] = vec<3, T>(x4, y4, z4);
	}

	template<typename T>
	template<typename V1, typename V2, typename V3, typename V4>
	GINNER_CONSTEXPR mat<4, 3, T>::mat(
		const vec<3, V1>& r1,
		const vec<3, V2>& r2,
		const vec<3, V3>& r3,
		const vec<3, V4>& r4)
	{
		value[0] = r1;
		value[1] = r2;
		value[2] = r3;
		value[3] = r4;
	}

	template<typename T>
	template<typename U>
	GINNER_CONSTEXPR mat<4, 3, T>::mat(const mat<4, 3, U>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
		value[3] = other.value[3];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T>& mat<4, 3, T>::operator=(const mat<4, 3, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
		value[3] = other.value[3];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T>& mat<4, 3, T>::operator[](length_t i)
	{
		GINNER_ASSERT_LENGTH(i, 4);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR const vec<3, T>& mat<4, 3, T>::operator[](length_t i) const
	{
		GINNER_ASSERT_LENGTH(i, 4);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T> mat<4, 3, T>::operator+() const
	{
		return mat<4, 3, T>(value[0], value[1], value[2], value[3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T> mat<4, 3, T>::operator-() const
	{
		return mat<4, 3, T>(-value[0], -value[1], -value[2], -value[3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T>& mat<4, 3, T>::operator++()
	{
		++value[0];
		++value[1];
		++value[2];
		++value[3];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T> mat<4, 3, T>::operator++(int)
	{
		mat<4, 3, T> result(*this);
		++value[0];
		++value[1];
		++value[2];
		++value[3];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T>& mat<4, 3, T>::operator--()
	{
		--value[0];
		--value[1];
		--value[2];
		--value[3];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T> mat<4, 3, T>::operator--(int)
	{
		mat<4, 3, T> result(*this);
		--value[0];
		--value[1];
		--value[2];
		--value[3];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T>& mat<4, 3, T>::operator+=(const mat<4, 3, T>& v)
	{
		value[0] += v.value[0];
		value[1] += v.value[1];
		value[2] += v.value[2];
		value[3] += v.value[3];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T>& mat<4, 3, T>::operator-=(const mat<4, 3, T>& v)
	{
		value[0] -= v.value[0];
		value[1] -= v.value[1];
		value[2] -= v.value[2];
		value[3] -= v.value[3];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T>& mat<4, 3, T>::operator*=(const T& k)
	{
		value[0] *= k;
		value[1] *= k;
		value[2] *= k;
		value[3] *= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T>& mat<4, 3, T>::operator/=(const T& k)
	{
		value[0] /= k;
		value[1] /= k;
		value[2] /= k;
		value[3] /= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T>& mat<4, 3, T>::operator%=(const T& k)
	{
		value[0] %= k;
		value[1] %= k;
		value[2] %= k;
		value[3] %= k;
		return *this;
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<4, 3, T>& left, const mat<4, 3, T>& right)
	{
		return ((left[0] == right[0]) && (left[1] == right[1]) && (left[2] == right[2]) && (left[3] == right[3]));
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<4, 3, T>& left, const mat<4, 3, T>& right)
	{
		return !(left == right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator+(const mat<4, 3, T>& left, const mat<4, 3, T>& right)
	{
		return mat<4, 3, T>(left[0] + right[0], left[1] + right[1], left[2] + right[2], left[3] + right[3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator-(const mat<4, 3, T>& left, const mat<4, 3, T>& right)
	{
		return mat<4, 3, T>(left[0] - right[0], left[1] - right[1], left[2] - right[2], left[3] - right[3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator*(const mat<4, 3, T>& left, const T& right)
	{
		return mat<4, 3, T>(left[0] * right, left[1] * right, left[2] * right, left[3] * right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator*(const T& left, const mat<4, 3, T>& right)
	{
		return mat<4, 3, T>(left * right[0], left * right[1], left * right[2], left * right[3]);
	}

	template <typename T>
	GINNER_CONSTEXPR typename mat<4, 3, T>::col_t operator*(const mat<4, 3, T>& left, const typename mat<4, 3, T>::row_t& right)
	{
		return typename mat<4, 3, T>::col_t(
			left[0][0] * right[0] + left[0][1] * right[1] + left[0][2] * right[2],
			left[1][0] * right[0] + left[1][1] * right[1] + left[1][2] * right[2],
			left[2][0] * right[0] + left[2][1] * right[1] + left[2][2] * right[2],
			left[3][0] * right[0] + left[3][1] * right[1] + left[3][2] * right[2]
		);
	}

	template <typename T>
	GINNER_CONSTEXPR typename mat<4, 3, T>::row_t operator*(const typename mat<4, 3, T>::col_t& left, const mat<4, 3, T>& right)
	{
		return typename mat<4, 3, T>::row_t(
			left[0] * right[0][0] + left[1] * right[1][0] + left[2] * right[2][0] + left[3] * right[3][0],
			left[0] * right[0][1] + left[1] * right[1][1] + left[2] * right[2][1] + left[3] * right[3][1],
			left[0] * right[0][2] + left[1] * right[1][2] + left[2] * right[2][2] + left[3] * right[3][2]
		);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator*(const mat<4, 3, T>& left, const mat<3, 2, T>& right)
	{
		return mat<4, 2, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1],
			left[2][0] * right[0][0] + left[2][1] * right[1][0] + left[2][2] * right[2][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1] + left[2][2] * right[2][1],
			left[3][0] * right[0][0] + left[3][1] * right[1][0] + left[3][2] * right[2][0],
			left[3][0] * right[0][1] + left[3][1] * right[1][1] + left[3][2] * right[2][1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator*(const mat<4, 3, T>& left, const mat<3, 3, T>& right)
	{
		return mat<4, 3, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2] + left[0][2] * right[2][2],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2] + left[1][2] * right[2][2],
			left[2][0] * right[0][0] + left[2][1] * right[1][0] + left[2][2] * right[2][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1] + left[2][2] * right[2][1],
			left[2][0] * right[0][2] + left[2][1] * right[1][2] + left[2][2] * right[2][2],
			left[3][0] * right[0][0] + left[3][1] * right[1][0] + left[3][2] * right[2][0],
			left[3][0] * right[0][1] + left[3][1] * right[1][1] + left[3][2] * right[2][1],
			left[3][0] * right[0][2] + left[3][1] * right[1][2] + left[3][2] * right[2][2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator*(const mat<4, 3, T>& left, const mat<3, 4, T>& right)
	{
		return mat<4, 4, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2] + left[0][2] * right[2][2],
			left[0][0] * right[0][3] + left[0][1] * right[1][3] + left[0][2] * right[2][3],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2] + left[1][2] * right[2][2],
			left[1][0] * right[0][3] + left[1][1] * right[1][3] + left[1][2] * right[2][3],
			left[2][0] * right[0][0] + left[2][1] * right[1][0] + left[2][2] * right[2][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1] + left[2][2] * right[2][1],
			left[2][0] * right[0][2] + left[2][1] * right[1][2] + left[2][2] * right[2][2],
			left[2][0] * right[0][3] + left[2][1] * right[1][3] + left[2][2] * right[2][3],
			left[3][0] * right[0][0] + left[3][1] * right[1][0] + left[3][2] * right[2][0],
			left[3][0] * right[0][1] + left[3][1] * right[1][1] + left[3][2] * right[2][1],
			left[3][0] * right[0][2] + left[3][1] * right[1][2] + left[3][2] * right[2][2],
			left[3][0] * right[0][3] + left[3][1] * right[1][3] + left[3][2] * right[2][3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator/(const mat<4, 3, T>& left, const T& right)
	{
		return mat<4, 3, T>(left[0] / right, left[1] / right, left[2] / right, left[3] / right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator%(const mat<4, 3, T>& left, const T& right)
	{
		return mat<4, 3, T>(left[0] % right, left[1] % right, left[2] % right, left[3] % right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T>::mat()
	{
		value[0] = vec<4, T>();
		value[1] = vec<4, T>();
		value[2] = vec<4, T>();
		value[3] = vec<4, T>();
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T>::mat(
		const T& x1, const T& y1, const T& z1, const T& w1,
		const T& x2, const T& y2, const T& z2, const T& w2,
		const T& x3, const T& y3, const T& z3, const T& w3,
		const T& x4, const T& y4, const T& z4, const T& w4)
	{
		value[0] = vec<4, T>(x1, y1, z1, w1);
		value[1] = vec<4, T>(x2, y2, z2, w2);
		value[2] = vec<4, T>(x3, y3, z3, w3);
		value[3] = vec<4, T>(x4, y4, z4, w4);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T>::mat(const row_t& r1, const row_t& r2, const row_t& r3, const row_t& r4)
	{
		value[0] = r1;
		value[1] = r2;
		value[2] = r3;
		value[3] = r4;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T>::mat(const mat<4, 4, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
		value[3] = other.value[3];
	}

	template<typename T>
	template<
		typename X1, typename Y1, typename Z1, typename W1,
		typename X2, typename Y2, typename Z2, typename W2,
		typename X3, typename Y3, typename Z3, typename	W3,
		typename X4, typename Y4, typename Z4, typename W4>
	GINNER_CONSTEXPR mat<4, 4, T>::mat(
		const X1& x1, const Y1& y1, const Z1& z1, const W1& w1,
		const X2& x2, const Y2& y2, const Z2& z2, const W2& w2,
		const X3& x3, const Y3& y3, const Z3& z3, const W3& w3,
		const X4& x4, const Y4& y4, const Z4& z4, const W4& w4)
	{
		value[0] = vec<4, T>(x1, y1, z1, w1);
		value[1] = vec<4, T>(x2, y2, z2, w2);
		value[2] = vec<4, T>(x3, y3, z3, w3);
		value[3] = vec<4, T>(x4, y4, z4, w4);
	}

	template<typename T>
	template<typename V1, typename V2, typename V3, typename V4>
	GINNER_CONSTEXPR mat<4, 4, T>::mat(
		const vec<4, V1>& r1,
		const vec<4, V2>& r2,
		const vec<4, V3>& r3,
		const vec<4, V4>& r4)
	{
		value[0] = r1;
		value[1] = r2;
		value[2] = r3;
		value[3] = r4;
	}

	template<typename T>
	template<typename U>
	GINNER_CONSTEXPR mat<4, 4, T>::mat(const mat<4, 4, U>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
		value[3] = other.value[3];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T>& mat<4, 4, T>::operator=(const mat<4, 4, T>& other)
	{
		value[0] = other.value[0];
		value[1] = other.value[1];
		value[2] = other.value[2];
		value[3] = other.value[3];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T>& mat<4, 4, T>::operator[](length_t i)
	{
		GINNER_ASSERT_LENGTH(i, 4);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR const vec<4, T>& mat<4, 4, T>::operator[](length_t i) const
	{
		GINNER_ASSERT_LENGTH(i, 4);
		return value[i];
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T> mat<4, 4, T>::operator+() const
	{
		return mat<4, 4, T>(value[0], value[1], value[2], value[3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T> mat<4, 4, T>::operator-() const
	{
		return mat<4, 4, T>(-value[0], -value[1], -value[2], -value[3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T>& mat<4, 4, T>::operator++()
	{
		++value[0];
		++value[1];
		++value[2];
		++value[3];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T> mat<4, 4, T>::operator++(int)
	{
		mat<4, 4, T> result(*this);
		++value[0];
		++value[1];
		++value[2];
		++value[3];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T>& mat<4, 4, T>::operator--()
	{
		--value[0];
		--value[1];
		--value[2];
		--value[3];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T> mat<4, 4, T>::operator--(int)
	{
		mat<4, 4, T> result(*this);
		--value[0];
		--value[1];
		--value[2];
		--value[3];
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T>& mat<4, 4, T>::operator+=(const mat<4, 4, T>& v)
	{
		value[0] += v.value[0];
		value[1] += v.value[1];
		value[2] += v.value[2];
		value[3] += v.value[3];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T>& mat<4, 4, T>::operator-=(const mat<4, 4, T>& v)
	{
		value[0] -= v.value[0];
		value[1] -= v.value[1];
		value[2] -= v.value[2];
		value[3] -= v.value[3];
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T>& mat<4, 4, T>::operator*=(const T& k)
	{
		value[0] *= k;
		value[1] *= k;
		value[2] *= k;
		value[3] *= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T>& mat<4, 4, T>::operator/=(const T& k)
	{
		value[0] /= k;
		value[1] /= k;
		value[2] /= k;
		value[3] /= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T>& mat<4, 4, T>::operator%=(const T& k)
	{
		value[0] %= k;
		value[1] %= k;
		value[2] %= k;
		value[3] %= k;
		return *this;
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<4, 4, T>& left, const mat<4, 4, T>& right)
	{
		return ((left[0] == right[0]) && (left[1] == right[1]) && (left[2] == right[2]) && (left[3] == right[3]));
	}

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<4, 4, T>& left, const mat<4, 4, T>& right)
	{
		return !(left == right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator+(const mat<4, 4, T>& left, const mat<4, 4, T>& right)
	{
		return mat<4, 4, T>(left[0] + right[0], left[1] + right[1], left[2] + right[2], left[3] + right[3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator-(const mat<4, 4, T>& left, const mat<4, 4, T>& right)
	{
		return mat<4, 4, T>(left[0] - right[0], left[1] - right[1], left[2] - right[2], left[3] - right[3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator*(const mat<4, 4, T>& left, const T& right)
	{
		return mat<4, 4, T>(left[0] * right, left[1] * right, left[2] * right, left[3] * right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator*(const T& left, const mat<4, 4, T>& right)
	{
		return mat<4, 4, T>(left * right[0], left * right[1], left * right[2], left * right[3]);
	}

	template <typename T>
	GINNER_CONSTEXPR typename mat<4, 4, T>::col_t operator*(const mat<4, 4, T>& left, const typename mat<4, 4, T>::row_t& right)
	{
		return typename mat<4, 4, T>::col_t(
			left[0][0] * right[0] + left[0][1] * right[1] + left[0][2] * right[2] + left[0][3] * right[3],
			left[1][0] * right[0] + left[1][1] * right[1] + left[1][2] * right[2] + left[1][3] * right[3],
			left[2][0] * right[0] + left[2][1] * right[1] + left[2][2] * right[2] + left[2][3] * right[3],
			left[3][0] * right[0] + left[3][1] * right[1] + left[3][2] * right[2] + left[3][3] * right[3]
		);
	}

	template <typename T>
	GINNER_CONSTEXPR typename mat<4, 4, T>::row_t operator*(const typename mat<4, 4, T>::col_t& left, const mat<4, 4, T>& right)
	{
		return typename mat<4, 4, T>::row_t(
			left[0] * right[0][0] + left[1] * right[1][0] + left[2] * right[2][0] + left[3] * right[3][0],
			left[0] * right[0][1] + left[1] * right[1][1] + left[2] * right[2][1] + left[3] * right[3][1],
			left[0] * right[0][2] + left[1] * right[1][2] + left[2] * right[2][2] + left[3] * right[3][2],
			left[0] * right[0][3] + left[1] * right[1][3] + left[2] * right[2][3] + left[3] * right[3][3]
		);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator*(const mat<4, 4, T>& left, const mat<4, 2, T>& right)
	{
		return mat<4, 2, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0] + left[0][3] * right[3][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1] + left[0][3] * right[3][1],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0] + left[1][3] * right[3][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1] + left[1][3] * right[3][1],
			left[2][0] * right[0][0] + left[2][1] * right[1][0] + left[2][2] * right[2][0] + left[2][3] * right[3][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1] + left[2][2] * right[2][1] + left[2][3] * right[3][1],
			left[3][0] * right[0][0] + left[3][1] * right[1][0] + left[3][2] * right[2][0] + left[3][3] * right[3][0],
			left[3][0] * right[0][1] + left[3][1] * right[1][1] + left[3][2] * right[2][1] + left[3][3] * right[3][1]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator*(const mat<4, 4, T>& left, const mat<4, 3, T>& right)
	{
		return mat<4, 3, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0] + left[0][3] * right[3][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1] + left[0][3] * right[3][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2] + left[0][2] * right[2][2] + left[0][3] * right[3][2],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0] + left[1][3] * right[3][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1] + left[1][3] * right[3][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2] + left[1][2] * right[2][2] + left[1][3] * right[3][2],
			left[2][0] * right[0][0] + left[2][1] * right[1][0] + left[2][2] * right[2][0] + left[2][3] * right[3][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1] + left[2][2] * right[2][1] + left[2][3] * right[3][1],
			left[2][0] * right[0][2] + left[2][1] * right[1][2] + left[2][2] * right[2][2] + left[2][3] * right[3][2],
			left[3][0] * right[0][0] + left[3][1] * right[1][0] + left[3][2] * right[2][0] + left[3][3] * right[3][0],
			left[3][0] * right[0][1] + left[3][1] * right[1][1] + left[3][2] * right[2][1] + left[3][3] * right[3][1],
			left[3][0] * right[0][2] + left[3][1] * right[1][2] + left[3][2] * right[2][2] + left[3][3] * right[3][2]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator*(const mat<4, 4, T>& left, const mat<4, 4, T>& right)
	{
		return mat<4, 4, T>(
			left[0][0] * right[0][0] + left[0][1] * right[1][0] + left[0][2] * right[2][0] + left[0][3] * right[3][0],
			left[0][0] * right[0][1] + left[0][1] * right[1][1] + left[0][2] * right[2][1] + left[0][3] * right[3][1],
			left[0][0] * right[0][2] + left[0][1] * right[1][2] + left[0][2] * right[2][2] + left[0][3] * right[3][2],
			left[0][0] * right[0][3] + left[0][1] * right[1][3] + left[0][2] * right[2][3] + left[0][3] * right[3][3],
			left[1][0] * right[0][0] + left[1][1] * right[1][0] + left[1][2] * right[2][0] + left[1][3] * right[3][0],
			left[1][0] * right[0][1] + left[1][1] * right[1][1] + left[1][2] * right[2][1] + left[1][3] * right[3][1],
			left[1][0] * right[0][2] + left[1][1] * right[1][2] + left[1][2] * right[2][2] + left[1][3] * right[3][2],
			left[1][0] * right[0][3] + left[1][1] * right[1][3] + left[1][2] * right[2][3] + left[1][3] * right[3][3],
			left[2][0] * right[0][0] + left[2][1] * right[1][0] + left[2][2] * right[2][0] + left[2][3] * right[3][0],
			left[2][0] * right[0][1] + left[2][1] * right[1][1] + left[2][2] * right[2][1] + left[2][3] * right[3][1],
			left[2][0] * right[0][2] + left[2][1] * right[1][2] + left[2][2] * right[2][2] + left[2][3] * right[3][2],
			left[2][0] * right[0][3] + left[2][1] * right[1][3] + left[2][2] * right[2][3] + left[2][3] * right[3][3],
			left[3][0] * right[0][0] + left[3][1] * right[1][0] + left[3][2] * right[2][0] + left[3][3] * right[3][0],
			left[3][0] * right[0][1] + left[3][1] * right[1][1] + left[3][2] * right[2][1] + left[3][3] * right[3][1],
			left[3][0] * right[0][2] + left[3][1] * right[1][2] + left[3][2] * right[2][2] + left[3][3] * right[3][2],
			left[3][0] * right[0][3] + left[3][1] * right[1][3] + left[3][2] * right[2][3] + left[3][3] * right[3][3]);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator/(const mat<4, 4, T>& left, const T& right)
	{
		return mat<4, 4, T>(left[0] / right, left[1] / right, left[2] / right, left[3] / right);
	}

	template<typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator%(const mat<4, 4, T>& left, const T& right)
	{
		return mat<4, 4, T>(left[0] % right, left[1] % right, left[2] % right, left[3] % right);
	}

}