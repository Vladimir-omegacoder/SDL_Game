#pragma once

#ifndef GINNER_VEC

#define GINNER_VEC
#include "ginner_mat_setup.h"
#include "ginner_types.h"

namespace gin
{

	template <typename T>
	struct vec<1, T>
	{

		T x;


		GINNER_CONSTEXPR vec();

		GINNER_CONSTEXPR vec(const T& x);

		GINNER_CONSTEXPR vec(const vec<1, T>& other);


		template<typename U>
		GINNER_CONSTEXPR GINNER_EXPLICIT vec(const vec<1, U>& other);


		GINNER_CONSTEXPR static length_t get_length() { return 1; }


		GINNER_CONSTEXPR vec<1, T>& operator=(const vec<1, T>& other);


		GINNER_CONSTEXPR T& operator[](length_t i);
		GINNER_CONSTEXPR const T& operator[](length_t i) const;


		GINNER_CONSTEXPR vec<1, T> operator+() const;

		GINNER_CONSTEXPR vec<1, T> operator-() const;

		GINNER_CONSTEXPR vec<1, T>& operator++();

		GINNER_CONSTEXPR vec<1, T> operator++(int);

		GINNER_CONSTEXPR vec<1, T>& operator--();

		GINNER_CONSTEXPR vec<1, T> operator--(int);


		GINNER_CONSTEXPR vec<1, T>& operator+=(const vec<1, T>& v);

		GINNER_CONSTEXPR vec<1, T>& operator-=(const vec<1, T>& v);

		GINNER_CONSTEXPR vec<1, T>& operator*=(const T& k);

		GINNER_CONSTEXPR vec<1, T>& operator/=(const T& k);

		GINNER_CONSTEXPR vec<1 ,T>& operator%= (const T& k);



	};

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const vec<1, T>& left, const vec<1, T>& right);

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const vec<1, T>& left, const vec<1, T>& right);

	template <typename T>
	GINNER_CONSTEXPR vec<1, T> operator+(const vec<1, T>& left, const vec<1, T>& right);

	template <typename T>
	GINNER_CONSTEXPR vec<1, T> operator-(const vec<1, T>& left, const vec<1, T>& right);

	template <typename T>
	GINNER_CONSTEXPR vec<1, T> operator*(const vec<1, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR vec<1, T> operator*(const T& left, const vec<1, T>& right);

	template <typename T>
	GINNER_CONSTEXPR vec<1, T> operator/(const vec<1, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR vec<1, T> operator%(const vec<1, T>& left, const T& right);



	template <typename T>
	struct vec<2, T>
	{

		T x;
		T y;


		GINNER_CONSTEXPR vec();

		GINNER_CONSTEXPR vec(const T& x, const T& y);

		GINNER_CONSTEXPR vec(const vec<2, T>& other);


		template<typename U>
		GINNER_CONSTEXPR GINNER_EXPLICIT vec(const vec<2, U>& other);


		GINNER_CONSTEXPR static length_t get_length() { return 2; }


		GINNER_CONSTEXPR vec<2, T>& operator=(const vec<2, T>& other);


		GINNER_CONSTEXPR T& operator[](length_t i);
		GINNER_CONSTEXPR const T& operator[](length_t i) const;


		GINNER_CONSTEXPR vec<2, T> operator+() const;

		GINNER_CONSTEXPR vec<2, T> operator-() const;

		GINNER_CONSTEXPR vec<2, T>& operator++();

		GINNER_CONSTEXPR vec<2, T> operator++(int);

		GINNER_CONSTEXPR vec<2, T>& operator--();

		GINNER_CONSTEXPR vec<2, T> operator--(int);


		GINNER_CONSTEXPR vec<2, T>& operator+=(const vec<2, T>& v);

		GINNER_CONSTEXPR vec<2, T>& operator-=(const vec<2, T>& v);

		GINNER_CONSTEXPR vec<2, T>& operator*=(const T& k);

		GINNER_CONSTEXPR vec<2, T>& operator/=(const T& k);

		GINNER_CONSTEXPR vec<2, T>& operator%= (const T& k);

	};

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const vec<2, T>& left, const vec<2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const vec<2, T>& left, const vec<2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR vec<2, T> operator+(const vec<2, T>& left, const vec<2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR vec<2, T> operator-(const vec<2, T>& left, const vec<2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR vec<2, T> operator*(const vec<2, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR vec<2, T> operator*(const T& left, const vec<2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR vec<2, T> operator/(const vec<2, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR vec<2, T> operator%(const vec<2, T>& left, const T& right);



	template <typename T>
	struct vec<3, T>
	{

		T x;
		T y;
		T z;


		GINNER_CONSTEXPR vec();
		GINNER_CONSTEXPR vec(const T& x, const T& y, const T& z);
		GINNER_CONSTEXPR vec(const vec<3, T>& other);


		template<typename U>
		GINNER_CONSTEXPR vec(const vec<3, U>& other);


		GINNER_CONSTEXPR static length_t get_length() { return 3; }


		GINNER_CONSTEXPR vec<3, T>& operator=(const vec<3, T>& other);


		GINNER_CONSTEXPR T& operator[](length_t i);
		GINNER_CONSTEXPR const T& operator[](length_t i) const;


		GINNER_CONSTEXPR vec<3, T> operator+() const;

		GINNER_CONSTEXPR vec<3, T> operator-() const;

		GINNER_CONSTEXPR vec<3, T>& operator++();

		GINNER_CONSTEXPR vec<3, T>& operator++(int);

		GINNER_CONSTEXPR vec<3, T>& operator--();

		GINNER_CONSTEXPR vec<3, T>& operator--(int);


		GINNER_CONSTEXPR vec<3, T>& operator+=(const vec<3, T>& v);

		GINNER_CONSTEXPR vec<3, T>& operator-=(const vec<3, T>& v);

		GINNER_CONSTEXPR vec<3, T>& operator*=(const T& k);

		GINNER_CONSTEXPR vec<3, T>& operator/=(const T& k);

		GINNER_CONSTEXPR vec<3, T>& operator%= (const T& k);

	};

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const vec<3, T>& left, const vec<3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const vec<3, T>& left, const vec<3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR vec<3, T> operator+(const vec<3, T>& left, const vec<3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR vec<3, T> operator-(const vec<3, T>& left, const vec<3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR vec<3, T> operator*(const vec<3, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR vec<3, T> operator*(const T& left, const vec<3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR vec<3, T> operator/(const vec<3, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR vec<3, T> operator%(const vec<3, T>& left, const T& right);



	template <typename T>
	struct vec<4, T>
	{

		T x;
		T y;
		T z;
		T w;


		GINNER_CONSTEXPR vec();
		GINNER_CONSTEXPR vec(const T& x, const T& y, const T& z, const T& w);
		GINNER_CONSTEXPR vec(const vec<4, T>& other);

		template<typename U>
		GINNER_CONSTEXPR vec(const vec<4, U>& other);


		GINNER_CONSTEXPR static length_t get_length() { return 4; }


		GINNER_CONSTEXPR vec<4, T>& operator=(const vec<4, T>& other);


		GINNER_CONSTEXPR T& operator[](length_t i);
		GINNER_CONSTEXPR const T& operator[](length_t i) const;


		GINNER_CONSTEXPR vec<4, T> operator+() const;

		GINNER_CONSTEXPR vec<4, T> operator-() const;

		GINNER_CONSTEXPR vec<4, T>& operator++();

		GINNER_CONSTEXPR vec<4, T> operator++(int);

		GINNER_CONSTEXPR vec<4, T>& operator--();

		GINNER_CONSTEXPR vec<4, T> operator--(int);


		GINNER_CONSTEXPR vec<4, T>& operator+=(const vec<4, T>& v);

		GINNER_CONSTEXPR vec<4, T>& operator-=(const vec<4, T>& v);

		GINNER_CONSTEXPR vec<4, T>& operator*=(const T& k);

		GINNER_CONSTEXPR vec<4, T>& operator/=(const T& k);

		GINNER_CONSTEXPR vec<4, T>& operator%= (const T& k);

	};

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const vec<4, T>& left, const vec<4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const vec<4, T>& left, const vec<4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR vec<4, T> operator+(const vec<4, T>& left, const vec<4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR vec<4, T> operator-(const vec<4, T>& left, const vec<4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR vec<4, T> operator*(const vec<4, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR vec<4, T> operator*(const T& left, const vec<4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR vec<4, T> operator/(const vec<4, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR vec<4, T> operator%(const vec<4, T>& left, const T& right);

}

#include "ginner_vec.inl"

#endif