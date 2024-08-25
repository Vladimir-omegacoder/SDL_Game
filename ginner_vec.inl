#include "ginner_vec.h"

namespace gin
{

	template<typename T>
	GINNER_CONSTEXPR vec<1, T>::vec()
	{}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T>::vec(const T& x) 
		: x(x)
	{}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T>::vec(const vec<1, T>& other)
		: x(other.x)
	{}

	template<typename T>
	template<typename U>
	GINNER_CONSTEXPR vec<1, T>::vec(const vec<1, U>& other)
		: x(static_cast<T>(other.x))
	{}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T>& vec<1, T>::operator=(const vec<1, T>& other)
	{
		x = other.x;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR T& vec<1, T>::operator[](length_t i)
	{
		GINNER_ASSERT_LENGTH(i, 1);
		switch (i)
		{
		case 0:
			return x;
			break;
		}
	}

	template<typename T>
	GINNER_CONSTEXPR const T& vec<1, T>::operator[](length_t i) const
	{
		GINNER_ASSERT_LENGTH(i, 1);
		switch (i)
		{
		case 0:
			return x;
			break;
		}
	}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T> vec<1, T>::operator+() const
	{
		return vec<1, T>(x);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T> vec<1, T>::operator-() const
	{
		return vec<1, T>(-x);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T>& vec<1, T>::operator++()
	{
		++x;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T> vec<1, T>::operator++(int)
	{
		vec<1, T> result(x);
		++x;
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T>& vec<1, T>::operator--()
	{
		--x;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T> vec<1, T>::operator--(int)
	{

		vec<1, T> result(x);
		--x;
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T>& vec<1, T>::operator+=(const vec<1, T>& v)
	{
		x += v.x;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T>& vec<1, T>::operator-=(const vec<1, T>& v)
	{
		x -= v.x;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T>& vec<1, T>::operator*=(const T& k)
	{
		x *= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T>& vec<1, T>::operator/=(const T& k)
	{
		x /= k;
		return *this;
	}
	
	template<typename T>
	GINNER_CONSTEXPR vec<1, T>& vec<1, T>::operator%=(const T& k)
	{
		x %= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR bool operator==(const vec<1, T>& left, const vec<1, T>& right)
	{
		return left.x == right.x;
	}

	template<typename T>
	GINNER_CONSTEXPR bool operator!=(const vec<1, T>& left, const vec<1, T>& right)
	{
		return !(left == right);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T> operator+(const vec<1, T>& left, const vec<1, T>& right)
	{
		return vec<1, T>(left.x + right.x);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T> operator-(const vec<1, T>& left, const vec<1, T>& right)
	{
		return vec<1, T>(left.x - right.x);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T> operator*(const vec<1, T>& left, const T& right)
	{
		return vec<1, T>(left.x * right);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T> operator*(const T& left, const vec<1, T>& right)
	{
		return vec<1, T>(left * right.x);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T> operator/(const vec<1, T>& left, const T& right)
	{
		return vec<1, T>(left.x / right);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<1, T> operator%(const vec<1, T>& left, const T& right)
	{
		return vec<1, T>(left.x % right);
	}



	template<typename T>
	GINNER_CONSTEXPR vec<2, T>::vec()
	{}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T>::vec(const T& x, const T& y)
		: x(x), y(y)
	{}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T>::vec(const gin::vec<2, T>& other)
		: x(other.x), y(other.y)
	{}

	template<typename T>
	template<typename U>
	GINNER_CONSTEXPR vec<2, T>::vec(const vec<2, U>& other)
		: x(static_cast<T>(other.x)), y(static_cast<T>(y))
	{}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T>& vec<2, T>::operator=(const vec<2, T>& other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR T& vec<2, T>::operator[](length_t i)
	{
		GINNER_ASSERT_LENGTH(i, 2);
		switch (i)
		{
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		}
	}

	template<typename T>
	GINNER_CONSTEXPR const T& vec<2, T>::operator[](length_t i) const
	{
		GINNER_ASSERT_LENGTH(i, 2);
		switch (i)
		{
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		}
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T> vec<2, T>::operator+() const
	{
		return vec<2, T>(x, y);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T> vec<2, T>::operator-() const
	{
		return vec<2, T>(-x, -y);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T>& vec<2, T>::operator++()
	{
		++x;
		++y;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T> vec<2, T>::operator++(int)
	{
		vec<2, T> result(x, y);
		++x;
		++y;
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T>& vec<2, T>::operator--()
	{
		--x;
		--y;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T> vec<2, T>::operator--(int)
	{
		vec<2, T> result(x, y);
		--x;
		--y;
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T>& vec<2, T>::operator+=(const vec<2, T>& v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T>& vec<2, T>::operator-=(const vec<2, T>& v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T>& vec<2, T>::operator*=(const T& k)
	{
		x *= k;
		y *= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T>& vec<2, T>::operator/=(const T& k)
	{
		x /= k;
		y /= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T>& vec<2, T>::operator%=(const T& k)
	{
		x %= k;
		y %= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR bool operator==(const vec<2, T>& left, const vec<2, T>& right)
	{
		return (left.x == right.x) && (left.y == right.y);
	}

	template<typename T>
	GINNER_CONSTEXPR bool operator!=(const vec<2, T>& left, const vec<2, T>& right)
	{
		return !(left == right);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T> operator+(const vec<2, T>& left, const vec<2, T>& right)
	{
		return vec<2, T>(left.x + right.x, left.y + right.y);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T> operator-(const vec<2, T>& left, const vec<2, T>& right)
	{
		return vec<2, T>(left.x - right.x, left.y - right.y);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T> operator*(const vec<2, T>& left, const T& right)
	{
		return vec<2, T>(left.x * right, left.y * right);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T> operator*(const T& left, const vec<2, T>& right)
	{
		return vec<2, T>(left * right.x, left * right.y);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T> operator/(const vec<2, T>& left, const T& right)
	{
		return vec<2, T>(left.x / right, left.y / right);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<2, T> operator%(const vec<2, T>& left, const T& right)
	{
		return vec<2, T>(left.x % right, left.y % right);
	}



	template<typename T>
	GINNER_CONSTEXPR vec<3, T>::vec()
	{}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T>::vec(const T& x, const T& y, const T& z)
		: x(x), y(y), z(z)
	{}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T>::vec(const vec<3, T>& other)
		: x(other.x), y(other.y), z(other.z)
	{}

	template<typename T>
	template<typename U>
	GINNER_CONSTEXPR vec<3, T>::vec(const vec<3, U>& other)
		: x(static_cast<T>(x)), y(static_cast<T>(y)), z(static_cast<T>(z))
	{}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T>& vec<3, T>::operator=(const vec<3, T>& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR T& vec<3, T>::operator[](length_t i)
	{
		GINNER_ASSERT_LENGTH(i, 3);
		switch (i)
		{
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		case 2:
			return z;
			break;
		}
	}

	template<typename T>
	GINNER_CONSTEXPR const T& vec<3, T>::operator[](length_t i) const
	{
		GINNER_ASSERT_LENGTH(i, 3);
		switch (i)
		{
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		case 2:
			return z;
			break;
		}
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T> vec<3, T>::operator+() const
	{
		return vec<3, T>(x, y, z);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T> vec<3, T>::operator-() const
	{
		return vec<3, T>(-x, -y, -z);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T>& vec<3, T>::operator++()
	{
		++x;
		++y;
		++z;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T>& vec<3, T>::operator++(int)
	{
		vec<3, T> result(x, y, z);
		++x;
		++y;
		++z;
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T>& vec<3, T>::operator--()
	{
		--x;
		--y;
		--z;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T>& vec<3, T>::operator--(int)
	{
		vec<3, T> result(x, y, z);
		--x;
		--y;
		--z;
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T>& vec<3, T>::operator+=(const vec<3, T>& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T>& vec<3, T>::operator-=(const vec<3, T>& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T>& vec<3, T>::operator*=(const T& k)
	{
		x *= k;
		y *= k;
		z *= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T>& vec<3, T>::operator/=(const T& k)
	{
		x /= k;
		y /= k;
		z /= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T>& vec<3, T>::operator%=(const T& k)
	{
		x %= k;
		y %= k;
		z %= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR bool operator==(const vec<3, T>& left, const vec<3, T>& right)
	{
		return (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
	}

	template<typename T>
	GINNER_CONSTEXPR bool operator!=(const vec<3, T>& left, const vec<3, T>& right)
	{
		return !(left == right);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T> operator+(const vec<3, T>& left, const vec<3, T>& right)
	{
		return vec<3, T>(left.x + right.x, left.y + right.y, left.z + right.z);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T> operator-(const vec<3, T>& left, const vec<3, T>& right)
	{
		return vec<3, T>(left.x - right.x, left.y - right.y, left.z - right.z);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T> operator*(const vec<3, T>& left, const T& right)
	{
		return vec<3, T>(left.x * right, left.y * right, left.z * right);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T> operator*(const T& left, const vec<3, T>& right)
	{
		return vec<3, T>(left * right.x, left * right.y, left * right.z);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T> operator/(const vec<3, T>& left, const T& right)
	{
		return vec<3, T>(left.x / right, left.y / right, left.z / right);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<3, T> operator%(const vec<3, T>& left, const T& right)
	{
		return vec<3, T>(left.x % right, left.y % right, left.z % right);
	}



	template<typename T>
	GINNER_CONSTEXPR vec<4, T>::vec()
	{}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T>::vec(const T& x, const T& y, const T& z, const T& w)
		: x(x), y(y), z(z), w(w)
	{}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T>::vec(const vec<4, T>& other)
		: x(other.x), y(other.y), z(other.z), w(other.w)
	{}

	template<typename T>
	template<typename U>
	GINNER_CONSTEXPR vec<4, T>::vec(const vec<4, U>& other)
		: x(static_cast<T>(x)), y(static_cast<T>(y)), z(static_cast<T>(z)), w(static_cast<T>(w))
	{}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T>& vec<4, T>::operator=(const vec<4, T>& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR T& vec<4, T>::operator[](length_t i)
	{
		GINNER_ASSERT_LENGTH(i, 4);
		switch (i)
		{
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		case 2:
			return z;
			break;
		case 3:
			return w;
			break;
		}
	}

	template<typename T>
	GINNER_CONSTEXPR const T& vec<4, T>::operator[](length_t i) const
	{
		GINNER_ASSERT_LENGTH(i, 4);
		switch (i)
		{
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		case 2:
			return z;
			break;
		case 3:
			return w;
			break;
		}
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T> vec<4, T>::operator+() const
	{
		return vec<4, T>(x, y, z, w);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T> vec<4, T>::operator-() const
	{
		return vec<4, T>(-x, -y, -z, -w);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T>& vec<4, T>::operator++()
	{
		++x;
		++y;
		++z;
		++w;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T> vec<4, T>::operator++(int)
	{
		vec<4, T> result(x, y, z, w);
		++x;
		++y;
		++z;
		++w;
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T>& vec<4, T>::operator--()
	{
		--x;
		--y;
		--z;
		--w;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T> vec<4, T>::operator--(int)
	{
		vec<4, T> result(x, y, z, w);
		--x;
		--y;
		--z;
		--w;
		return result;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T>& vec<4, T>::operator+=(const vec<4, T>& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T>& vec<4, T>::operator-=(const vec<4, T>& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T>& vec<4, T>::operator*=(const T& k)
	{
		x *= k;
		y *= k;
		z *= k;
		w *= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T>& vec<4, T>::operator/=(const T& k)
	{
		x /= k;
		y /= k;
		z /= k;
		w /= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T>& vec<4, T>::operator%=(const T& k)
	{
		x %= k;
		y %= k;
		z %= k;
		w %= k;
		return *this;
	}

	template<typename T>
	GINNER_CONSTEXPR bool operator==(const vec<4, T>& left, const vec<4, T>& right)
	{
		return (left.x == right.x) && (left.y == right.y) && (left.z == right.z) && (left.w == right.w);
	}

	template<typename T>
	GINNER_CONSTEXPR bool operator!=(const vec<4, T>& left, const vec<4, T>& right)
	{
		return !(left == right);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T> operator+(const vec<4, T>& left, const vec<4, T>& right)
	{
		return vec<4, T>(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T> operator-(const vec<4, T>& left, const vec<4, T>& right)
	{
		return vec<4, T>(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T> operator*(const vec<4, T>& left, const T& right)
	{
		return vec<4, T>(left.x * right, left.y * right, left.z * right, left.w * right);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T> operator*(const T& left, const vec<4, T>& right)
	{
		return vec<4, T>(left * right.x, left * right.y, left * right.z, left * right.w);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T> operator/(const vec<4, T>& left, const T& right)
	{
		return vec<4, T>(left.x / right, left.y / right, left.z / right, left.w / right);
	}

	template<typename T>
	GINNER_CONSTEXPR vec<4, T> operator%(const vec<4, T>& left, const T& right)
	{
		return vec<4, T>(left.x % right, left.y % right, left.z % right, left.w % right);
	}

}