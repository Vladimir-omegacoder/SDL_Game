#pragma once

#ifndef GINNER_MAT

#define GINNER_MAT
#include "ginner_types.h"

namespace gin
{

	template <typename T>
	struct mat<2, 2, T>
	{

		using col_t = vec<2, T>;
		using row_t = vec<2, T>;

		using value_type = T;
		using transpose_type = mat<2, 2, T>;

	private:

		row_t value[2];

	public:

		GINNER_CONSTEXPR mat();
		GINNER_CONSTEXPR mat(const T& x1, const T& y1, const T& x2, const T& y2);
		GINNER_CONSTEXPR mat(const row_t& r1, const row_t& r2);
		GINNER_CONSTEXPR mat(const mat<2, 2, T>& other);


		template<typename X1, typename Y1, typename X2, typename Y2>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const X1& x1, const Y1& y1, const X2& x2, const Y2& y2);
		template<typename V1, typename V2>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const vec<2, V1>& r1, const vec<2, V2>& r2);
		template<typename U>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const mat<2, 2, U>& other);


		GINNER_CONSTEXPR mat<2, 2, T>& operator=(const mat<2, 2, T>& other);

		GINNER_CONSTEXPR vec<2, T>& operator[](length_t i);
		GINNER_CONSTEXPR const vec<2, T>& operator[](length_t i) const;

		GINNER_CONSTEXPR mat<2, 2, T> operator+() const;

		GINNER_CONSTEXPR mat<2, 2, T> operator-() const;

		GINNER_CONSTEXPR mat<2, 2, T>& operator++();
		GINNER_CONSTEXPR mat<2, 2, T> operator++(int);

		GINNER_CONSTEXPR mat<2, 2, T>& operator--();
		GINNER_CONSTEXPR mat<2, 2, T> operator--(int);


		GINNER_CONSTEXPR mat<2, 2, T>& operator+=(const mat<2, 2, T>& v);

		GINNER_CONSTEXPR mat<2, 2, T>& operator-=(const mat<2, 2, T>& v);

		GINNER_CONSTEXPR mat<2, 2, T>& operator*=(const T& k);

		GINNER_CONSTEXPR mat<2, 2, T>& operator/=(const T& k);

		GINNER_CONSTEXPR mat<2, 2, T>& operator%=(const T& k);

	};

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<2, 2, T>& left, const mat<2, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<2, 2, T>& left, const mat<2, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator+(const mat<2, 2, T>& left, const mat<2, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator-(const mat<2, 2, T>& left, const mat<2, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator*(const mat<2, 2, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator*(const T& left, const mat<2, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<2, 2, T>::col_t operator*(const mat<2, 2, T>& left, const typename mat<2, 2, T>::row_t& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<2, 2, T>::row_t operator*(const typename mat<2, 2, T>::col_t& left, const mat<2, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator*(const mat<2, 2, T>& left, const mat<2, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator*(const mat<2, 2, T>& left, const mat<2, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator*(const mat<2, 2, T>& left, const mat<2, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator/(const mat<2, 2, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator%(const mat<2, 2, T>& left, const T& right);



	template <typename T>
	struct mat<2, 3, T>
	{

		using col_t = vec<2, T>;
		using row_t = vec<3, T>;

		using value_type = T;
		using transpose_type = mat<3, 2, T>;

	private:

		row_t value[2];

	public:

		GINNER_CONSTEXPR mat();
		GINNER_CONSTEXPR mat(const T& x1, const T& y1, const T& z1, const T& x2, const T& y2, const T& z2);
		GINNER_CONSTEXPR mat(const row_t& r1, const row_t& r2);
		GINNER_CONSTEXPR mat(const mat<2, 3, T>& other);


		template<typename X1, typename Y1, typename Z1, typename X2, typename Y2, typename Z2>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const X1& x1, const Y1& y1, const Z1& z1, const X2& x2, const Y2& y2, const Z2& z2);
		template<typename V1, typename V2>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const vec<3, V1>& r1, const vec<3, V2>& r2);
		template<typename U>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const mat<2, 3, U>& other);


		GINNER_CONSTEXPR mat<2, 3, T>& operator=(const mat<2, 3, T>& other);

		GINNER_CONSTEXPR vec<3, T>& operator[](length_t i);
		GINNER_CONSTEXPR const vec<3, T>& operator[](length_t i) const;

		GINNER_CONSTEXPR mat<2, 3, T> operator+() const;

		GINNER_CONSTEXPR mat<2, 3, T> operator-() const;

		GINNER_CONSTEXPR mat<2, 3, T>& operator++();
		GINNER_CONSTEXPR mat<2, 3, T> operator++(int);

		GINNER_CONSTEXPR mat<2, 3, T>& operator--();
		GINNER_CONSTEXPR mat<2, 3, T> operator--(int);


		GINNER_CONSTEXPR mat<2, 3, T>& operator+=(const mat<2, 3, T>& v);

		GINNER_CONSTEXPR mat<2, 3, T>& operator-=(const mat<2, 3, T>& v);

		GINNER_CONSTEXPR mat<2, 3, T>& operator*=(const T& k);

		GINNER_CONSTEXPR mat<2, 3, T>& operator/=(const T& k);

		GINNER_CONSTEXPR mat<2, 3, T>& operator%=(const T& k);

	};

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<2, 3, T>& left, const mat<2, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<2, 3, T>& left, const mat<2, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator+(const mat<2, 3, T>& left, const mat<2, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator-(const mat<2, 3, T>& left, const mat<2, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator*(const mat<2, 3, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator*(const T& left, const mat<2, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<2, 3, T>::col_t operator*(const mat<2, 3, T>& left, const typename mat<2, 3, T>::row_t& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<2, 3, T>::row_t operator*(const typename mat<2, 3, T>::col_t& right, const mat<2, 3, T>& left);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator*(const mat<2, 3, T>& left, const mat<3, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator*(const mat<2, 3, T>& left, const mat<3, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator*(const mat<2, 3, T>& left, const mat<3, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator/(const mat<2, 3, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator%(const mat<2, 3, T>& left, const T& right);



	template <typename T>
	struct mat<2, 4, T>
	{

		using col_t = vec<2, T>;
		using row_t = vec<4, T>;

		using value_type = T;
		using transpose_type = mat<4, 2, T>;

	private:

		row_t value[2];

	public:

		GINNER_CONSTEXPR mat();
		GINNER_CONSTEXPR mat(const T& x1, const T& y1, const T& z1, const T& w1, const T& x2, const T& y2, const T& z2, const T& w2);
		GINNER_CONSTEXPR mat(const row_t& r1, const row_t& r2);
		GINNER_CONSTEXPR mat(const mat<2, 4, T>& other);


		template<typename X1, typename Y1, typename Z1, typename W1,
			typename X2, typename Y2, typename Z2, typename W2>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const X1& x1, const Y1& y1, const Z1& z1, const W1& w1,
			const X2& x2, const Y2& y2, const Z2& z2, const W2& w2);
		template<typename V1, typename V2>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const vec<4, V1>& r1, const vec<4, V2>& r2);
		template<typename U>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const mat<2, 4, U>& other);


		GINNER_CONSTEXPR mat<2, 4, T>& operator=(const mat<2, 4, T>& other);

		GINNER_CONSTEXPR vec<4, T>& operator[](length_t i);
		GINNER_CONSTEXPR const vec<4, T>& operator[](length_t i) const;

		GINNER_CONSTEXPR mat<2, 4, T> operator+() const;

		GINNER_CONSTEXPR mat<2, 4, T> operator-() const;

		GINNER_CONSTEXPR mat<2, 4, T>& operator++();
		GINNER_CONSTEXPR mat<2, 4, T> operator++(int);

		GINNER_CONSTEXPR mat<2, 4, T>& operator--();
		GINNER_CONSTEXPR mat<2, 4, T> operator--(int);


		GINNER_CONSTEXPR mat<2, 4, T>& operator+=(const mat<2, 4, T>& v);

		GINNER_CONSTEXPR mat<2, 4, T>& operator-=(const mat<2, 4, T>& v);

		GINNER_CONSTEXPR mat<2, 4, T>& operator*=(const T& k);

		GINNER_CONSTEXPR mat<2, 4, T>& operator/=(const T& k);

		GINNER_CONSTEXPR mat<2, 4, T>& operator%=(const T& k);

	};

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<2, 4, T>& left, const mat<2, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<2, 4, T>& left, const mat<2, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator+(const mat<2, 4, T>& left, const mat<2, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator-(const mat<2, 4, T>& left, const mat<2, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator*(const mat<2, 4, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator*(const T& left, const mat<2, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<2, 4, T>::col_t operator*(const mat<2, 4, T>& left, const typename mat<2, 4, T>::row_t& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<2, 4, T>::row_t operator*(const typename mat<2, 4, T>::col_t& left, const mat<2, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 2, T> operator*(const mat<2, 4, T>& left, const mat<4, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 3, T> operator*(const mat<2, 4, T>& left, const mat<4, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator*(const mat<2, 4, T>& left, const mat<4, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator/(const mat<2, 4, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<2, 4, T> operator%(const mat<2, 4, T>& left, const T& right);



	template <typename T>
	struct mat<3, 2, T>
	{

		using col_t = vec<3, T>;
		using row_t = vec<2, T>;

		using value_type = T;
		using transpose_type = mat<2, 3, T>;

	private:

		row_t value[3];

	public:

		GINNER_CONSTEXPR mat();
		GINNER_CONSTEXPR mat(const T& x1, const T& y1, const T& x2, const T& y2, const T& x3, const T& y3);
		GINNER_CONSTEXPR mat(const row_t& r1, const row_t& r2, const row_t& r3);
		GINNER_CONSTEXPR mat(const mat<3, 2, T>& other);


		template<typename X1, typename Y1, typename X2, typename Y2, typename X3, typename Y3>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const X1& x1, const Y1& y1, const X2& x2, const Y2& y2, const X3& x3, const Y3& y3);
		template<typename V1, typename V2, typename V3>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const vec<2, V1>& r1, const vec<2, V2>& r2, const vec<2, V3>& r3);
		template<typename U>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const mat<3, 2, U>& other);


		GINNER_CONSTEXPR mat<3, 2, T>& operator=(const mat<3, 2, T>& other);

		GINNER_CONSTEXPR vec<2, T>& operator[](length_t i);
		GINNER_CONSTEXPR const vec<2, T>& operator[](length_t i) const;

		GINNER_CONSTEXPR mat<3, 2, T> operator+() const;

		GINNER_CONSTEXPR mat<3, 2, T> operator-() const;

		GINNER_CONSTEXPR mat<3, 2, T>& operator++();
		GINNER_CONSTEXPR mat<3, 2, T> operator++(int);

		GINNER_CONSTEXPR mat<3, 2, T>& operator--();
		GINNER_CONSTEXPR mat<3, 2, T> operator--(int);


		GINNER_CONSTEXPR mat<3, 2, T>& operator+=(const mat<3, 2, T>& v);

		GINNER_CONSTEXPR mat<3, 2, T>& operator-=(const mat<3, 2, T>& v);

		GINNER_CONSTEXPR mat<3, 2, T>& operator*=(const T& k);

		GINNER_CONSTEXPR mat<3, 2, T>& operator/=(const T& k);

		GINNER_CONSTEXPR mat<3, 2, T>& operator%=(const T& k);

	};

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<3, 2, T>& left, const mat<3, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<3, 2, T>& left, const mat<3, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator+(const mat<3, 2, T>& left, const mat<3, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator-(const mat<3, 2, T>& left, const mat<3, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator*(const mat<3, 2, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator*(const T& left, const mat<3, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<3, 2, T>::col_t operator*(const mat<3, 2, T>& left, const typename mat<3, 2, T>::row_t& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<3, 2, T>::row_t operator*(const typename mat<3, 2, T>::col_t& left, const mat<3, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator*(const mat<3, 2, T>& left, const mat<2, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator*(const mat<3, 2, T>& left, const mat<2, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator*(const mat<3, 2, T>& left, const mat<2, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator/(const mat<3, 2, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator%(const mat<3, 2, T>& left, const T& right);



	template <typename T>
	struct mat<3, 3, T>
	{

		using col_t = vec<3, T>;
		using row_t = vec<3, T>;

		using value_type = T;
		using transpose_type = mat<3, 3, T>;

	private:

		row_t value[3];

	public:

		GINNER_CONSTEXPR mat();
		GINNER_CONSTEXPR mat(
			const T& x1, const T& y1, const T& z1,
			const T& x2, const T& y2, const T& z2,
			const T& x3, const T& y3, const T& z3);
		GINNER_CONSTEXPR mat(const row_t& r1, const row_t& r2, const row_t& r3);
		GINNER_CONSTEXPR mat(const mat<3, 3, T>& other);


		template<
			typename X1, typename Y1, typename Z1,
			typename X2, typename Y2, typename Z2,
			typename X3, typename Y3, typename Z3>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(
			const X1& x1, const Y1& y1, const Z1& z1,
			const X2& x2, const Y2& y2, const Z2& z2,
			const X3& x3, const Y3& y3, const Z3& z3);
		template<typename V1, typename V2, typename V3>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const vec<3, V1>& r1, const vec<3, V2>& r2, const vec<3, V3>& r3);
		template<typename U>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const mat<3, 3, U>& other);


		GINNER_CONSTEXPR mat<3, 3, T>& operator=(const mat<3, 3, T>& other);

		GINNER_CONSTEXPR vec<3, T>& operator[](length_t i);
		GINNER_CONSTEXPR const vec<3, T>& operator[](length_t i) const;

		GINNER_CONSTEXPR mat<3, 3, T> operator+() const;

		GINNER_CONSTEXPR mat<3, 3, T> operator-() const;

		GINNER_CONSTEXPR mat<3, 3, T>& operator++();
		GINNER_CONSTEXPR mat<3, 3, T> operator++(int);

		GINNER_CONSTEXPR mat<3, 3, T>& operator--();
		GINNER_CONSTEXPR mat<3, 3, T> operator--(int);


		GINNER_CONSTEXPR mat<3, 3, T>& operator+=(const mat<3, 3, T>& v);

		GINNER_CONSTEXPR mat<3, 3, T>& operator-=(const mat<3, 3, T>& v);

		GINNER_CONSTEXPR mat<3, 3, T>& operator*=(const T& k);

		GINNER_CONSTEXPR mat<3, 3, T>& operator/=(const T& k);

		GINNER_CONSTEXPR mat<3, 3, T>& operator%=(const T& k);

	};

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<3, 3, T>& left, const mat<3, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<3, 3, T>& left, const mat<3, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator+(const mat<3, 3, T>& left, const mat<3, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator-(const mat<3, 3, T>& left, const mat<3, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator*(const mat<3, 3, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator*(const T& left, const mat<3, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<3, 3, T>::col_t operator*(const mat<3, 3, T>& left, const typename mat<3, 3, T>::row_t& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<3, 3, T>::row_t operator*(const typename mat<3, 3, T>::col_t& left, const mat<3, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator*(const mat<3, 3, T>& left, const mat<3, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator*(const mat<3, 3, T>& left, const mat<3, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator*(const mat<3, 3, T>& left, const mat<3, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator/(const mat<3, 3, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator%(const mat<3, 3, T>& left, const T& right);



	template <typename T>
	struct mat<3, 4, T>
	{

		using col_t = vec<3, T>;
		using row_t = vec<4, T>;

		using value_type = T;
		using transpose_type = mat<4, 3, T>;

	private:

		row_t value[3];

	public:

		GINNER_CONSTEXPR mat();
		GINNER_CONSTEXPR mat(
			const T& x1, const T& y1, const T& z1, const T& w1,
			const T& x2, const T& y2, const T& z2, const T& w2,
			const T& x3, const T& y3, const T& z3, const T& w3);
		GINNER_CONSTEXPR mat(const row_t& r1, const row_t& r2, const row_t& r3);
		GINNER_CONSTEXPR mat(const mat<3, 4, T>& other);


		template<
			typename X1, typename Y1, typename Z1, typename W1,
			typename X2, typename Y2, typename Z2, typename W2,
			typename X3, typename Y3, typename Z3, typename W3>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(
			const X1& x1, const Y1& y1, const Z1& z1, const W1& w1, 
			const X2& x2, const Y2& y2, const Z2& z2, const W2& w2,
			const X3& x3, const Y3& y3, const Z3& z3, const W3& w3);
		template<typename V1, typename V2, typename V3>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const vec<4, V1>& r1, const vec<4, V2>& r2, const vec<4, V3>& r3);
		template<typename U>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const mat<3, 4, U>& other);


		GINNER_CONSTEXPR mat<3, 4, T>& operator=(const mat<3, 4, T>& other);

		GINNER_CONSTEXPR vec<4, T>& operator[](length_t i);
		GINNER_CONSTEXPR const vec<4, T>& operator[](length_t i) const;

		GINNER_CONSTEXPR mat<3, 4, T> operator+() const;

		GINNER_CONSTEXPR mat<3, 4, T> operator-() const;

		GINNER_CONSTEXPR mat<3, 4, T>& operator++();
		GINNER_CONSTEXPR mat<3, 4, T> operator++(int);

		GINNER_CONSTEXPR mat<3, 4, T>& operator--();
		GINNER_CONSTEXPR mat<3, 4, T> operator--(int);


		GINNER_CONSTEXPR mat<3, 4, T>& operator+=(const mat<3, 4, T>& v);

		GINNER_CONSTEXPR mat<3, 4, T>& operator-=(const mat<3, 4, T>& v);

		GINNER_CONSTEXPR mat<3, 4, T>& operator*=(const T& k);

		GINNER_CONSTEXPR mat<3, 4, T>& operator/=(const T& k);

		GINNER_CONSTEXPR mat<3, 4, T>& operator%=(const T& k);

	};

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<3, 4, T>& left, const mat<3, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<3, 4, T>& left, const mat<3, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator+(const mat<3, 4, T>& left, const mat<3, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator-(const mat<3, 4, T>& left, const mat<3, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator*(const mat<3, 4, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator*(const T& left, const mat<3, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<3, 4, T>::col_t operator*(const mat<3, 4, T>& left, const typename mat<3, 4, T>::row_t& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<3, 4, T>::row_t operator*(const typename mat<3, 4, T>::col_t& left, const mat<3, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 2, T> operator*(const mat<3, 4, T>& left, const mat<4, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 3, T> operator*(const mat<3, 4, T>& left, const mat<4, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator*(const mat<3, 4, T>& left, const mat<4, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator/(const mat<3, 4, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<3, 4, T> operator%(const mat<3, 4, T>& left, const T& right);



	template <typename T>
	struct mat<4, 2, T>
	{

		using col_t = vec<4, T>;
		using row_t = vec<2, T>;

		using value_type = T;
		using transpose_type = mat<2, 4, T>;

	private:

		row_t value[4];

	public:

		GINNER_CONSTEXPR mat();
		GINNER_CONSTEXPR mat(
			const T& x1, const T& y1,
			const T& x2, const T& y2,
			const T& x3, const T& y3,
			const T& x4, const T& y4);
		GINNER_CONSTEXPR mat(const row_t& r1, const row_t& r2, const row_t& r3, const row_t& r4);
		GINNER_CONSTEXPR mat(const mat<4, 2, T>& other);


		template<
			typename X1, typename Y1,
			typename X2, typename Y2,
			typename X3, typename Y3,
			typename X4, typename Y4>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(
			const X1& x1, const Y1& y1,
			const X2& x2, const Y2& y2,
			const X3& x3, const Y3& y3,
			const X4& x4, const Y4& y4);
		template<typename V1, typename V2, typename V3, typename V4>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(
			const vec<2, V1>& r1,
			const vec<2, V2>& r2,
			const vec<2, V3>& r3,
			const vec<2, V4>& r4);
		template<typename U>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const mat<4, 2, U>& other);


		GINNER_CONSTEXPR mat<4, 2, T>& operator=(const mat<4, 2, T>& other);

		GINNER_CONSTEXPR vec<2, T>& operator[](length_t i);
		GINNER_CONSTEXPR const vec<2, T>& operator[](length_t i) const;

		GINNER_CONSTEXPR mat<4, 2, T> operator+() const;

		GINNER_CONSTEXPR mat<4, 2, T> operator-() const;

		GINNER_CONSTEXPR mat<4, 2, T>& operator++();
		GINNER_CONSTEXPR mat<4, 2, T> operator++(int);

		GINNER_CONSTEXPR mat<4, 2, T>& operator--();
		GINNER_CONSTEXPR mat<4, 2, T> operator--(int);


		GINNER_CONSTEXPR mat<4, 2, T>& operator+=(const mat<4, 2, T>& v);

		GINNER_CONSTEXPR mat<4, 2, T>& operator-=(const mat<4, 2, T>& v);

		GINNER_CONSTEXPR mat<4, 2, T>& operator*=(const T& k);

		GINNER_CONSTEXPR mat<4, 2, T>& operator/=(const T& k);

		GINNER_CONSTEXPR mat<4, 2, T>& operator%=(const T& k);

	};

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<4, 2, T>& left, const mat<4, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<4, 2, T>& left, const mat<4, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator+(const mat<4, 2, T>& left, const mat<4, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator-(const mat<4, 2, T>& left, const mat<4, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator*(const mat<4, 2, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator*(const T& left, const mat<4, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<4, 2, T>::col_t operator*(const mat<4, 2, T>& left, const typename mat<4, 2, T>::row_t& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<4, 2, T>::row_t operator*(const typename mat<4, 2, T>::col_t& left, const mat<4, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator*(const mat<4, 2, T>& left, const mat<2, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator*(const mat<4, 2, T>& left, const mat<2, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator*(const mat<4, 2, T>& left, const mat<2, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator/(const mat<4, 2, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator%(const mat<4, 2, T>& left, const T& right);



	template <typename T>
	struct mat<4, 3, T>
	{

		using col_t = vec<4, T>;
		using row_t = vec<3, T>;

		using value_type = T;
		using transpose_type = mat<3, 4, T>;

	private:

		row_t value[4];

	public:

		GINNER_CONSTEXPR mat();
		GINNER_CONSTEXPR mat(
			const T& x1, const T& y1, const T& z1,
			const T& x2, const T& y2, const T& z2,
			const T& x3, const T& y3, const T& z3,
			const T& x4, const T& y4, const T& z4);
		GINNER_CONSTEXPR mat(const row_t& r1, const row_t& r2, const row_t& r3, const row_t& r4);
		GINNER_CONSTEXPR mat(const mat<4, 3, T>& other);


		template<
			typename X1, typename Y1, typename Z1,
			typename X2, typename Y2, typename Z2,
			typename X3, typename Y3, typename Z3,
			typename X4, typename Y4, typename Z4>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(
			const X1& x1, const Y1& y1, const Z1& z1,
			const X2& x2, const Y2& y2, const Z2& z2,
			const X3& x3, const Y3& y3, const Z3& z3,
			const X4& x4, const Y4& y4, const Z4& z4);
		template<typename V1, typename V2, typename V3, typename V4>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(
			const vec<3, V1>& r1,
			const vec<3, V2>& r2,
			const vec<3, V3>& r3,
			const vec<3, V4>& r4);
		template<typename U>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const mat<4, 3, U>& other);


		GINNER_CONSTEXPR mat<4, 3, T>& operator=(const mat<4, 3, T>& other);

		GINNER_CONSTEXPR vec<3, T>& operator[](length_t i);
		GINNER_CONSTEXPR const vec<3, T>& operator[](length_t i) const;

		GINNER_CONSTEXPR mat<4, 3, T> operator+() const;

		GINNER_CONSTEXPR mat<4, 3, T> operator-() const;

		GINNER_CONSTEXPR mat<4, 3, T>& operator++();
		GINNER_CONSTEXPR mat<4, 3, T> operator++(int);

		GINNER_CONSTEXPR mat<4, 3, T>& operator--();
		GINNER_CONSTEXPR mat<4, 3, T> operator--(int);


		GINNER_CONSTEXPR mat<4, 3, T>& operator+=(const mat<4, 3, T>& v);

		GINNER_CONSTEXPR mat<4, 3, T>& operator-=(const mat<4, 3, T>& v);

		GINNER_CONSTEXPR mat<4, 3, T>& operator*=(const T& k);

		GINNER_CONSTEXPR mat<4, 3, T>& operator/=(const T& k);

		GINNER_CONSTEXPR mat<4, 3, T>& operator%=(const T& k);

	};

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<4, 3, T>& left, const mat<4, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<4, 3, T>& left, const mat<4, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator+(const mat<4, 3, T>& left, const mat<4, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator-(const mat<4, 3, T>& left, const mat<4, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator*(const mat<4, 3, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator*(const T& left, const mat<4, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<4, 3, T>::col_t operator*(const mat<4, 3, T>& left, const typename mat<4, 3, T>::row_t& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<4, 3, T>::row_t operator*(const typename mat<4, 3, T>::col_t& left, const mat<4, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator*(const mat<4, 3, T>& left, const mat<3, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator*(const mat<4, 3, T>& left, const mat<3, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator*(const mat<4, 3, T>& left, const mat<3, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator/(const mat<4, 3, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator%(const mat<4, 3, T>& left, const T& right);



	template <typename T>
	struct mat<4, 4, T>
	{

		using col_t = vec<4, T>;
		using row_t = vec<4, T>;

		using value_type = T;
		using transpose_type = mat<4, 4, T>;

	private:

		row_t value[4];

	public:

		GINNER_CONSTEXPR mat();
		GINNER_CONSTEXPR mat(
			const T& x1, const T& y1, const T& z1, const T& w1,
			const T& x2, const T& y2, const T& z2, const T& w2,
			const T& x3, const T& y3, const T& z3, const T& w3,
			const T& x4, const T& y4, const T& z4, const T& w4);
		GINNER_CONSTEXPR mat(const row_t& r1, const row_t& r2, const row_t& r3, const row_t& r4);
		GINNER_CONSTEXPR mat(const mat<4, 4, T>& other);


		template<
			typename X1, typename Y1, typename Z1, typename W1,
			typename X2, typename Y2, typename Z2, typename W2,
			typename X3, typename Y3, typename Z3, typename	W3,
			typename X4, typename Y4, typename Z4, typename W4>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(
			const X1& x1, const Y1& y1, const Z1& z1, const W1& w1,
			const X2& x2, const Y2& y2, const Z2& z2, const W2& w2,
			const X3& x3, const Y3& y3, const Z3& z3, const W3& w3,
			const X4& x4, const Y4& y4, const Z4& z4, const W4& w4);
		template<typename V1, typename V2, typename V3, typename V4>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(
			const vec<4, V1>& r1,
			const vec<4, V2>& r2,
			const vec<4, V3>& r3,
			const vec<4, V4>& r4);
		template<typename U>
		GINNER_CONSTEXPR GINNER_EXPLICIT mat(const mat<4, 4, U>& other);


		GINNER_CONSTEXPR mat<4, 4, T>& operator=(const mat<4, 4, T>& other);

		GINNER_CONSTEXPR vec<4, T>& operator[](length_t i);
		GINNER_CONSTEXPR const vec<4, T>& operator[](length_t i) const;

		GINNER_CONSTEXPR mat<4, 4, T> operator+() const;

		GINNER_CONSTEXPR mat<4, 4, T> operator-() const;

		GINNER_CONSTEXPR mat<4, 4, T>& operator++();
		GINNER_CONSTEXPR mat<4, 4, T> operator++(int);

		GINNER_CONSTEXPR mat<4, 4, T>& operator--();
		GINNER_CONSTEXPR mat<4, 4, T> operator--(int);


		GINNER_CONSTEXPR mat<4, 4, T>& operator+=(const mat<4, 4, T>& v);

		GINNER_CONSTEXPR mat<4, 4, T>& operator-=(const mat<4, 4, T>& v);

		GINNER_CONSTEXPR mat<4, 4, T>& operator*=(const T& k);

		GINNER_CONSTEXPR mat<4, 4, T>& operator/=(const T& k);

		GINNER_CONSTEXPR mat<4, 4, T>& operator%=(const T& k);

	};

	template <typename T>
	GINNER_CONSTEXPR bool operator==(const mat<4, 4, T>& left, const mat<4, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR bool operator!=(const mat<4, 4, T>& left, const mat<4, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator+(const mat<4, 4, T>& left, const mat<4, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator-(const mat<4, 4, T>& left, const mat<4, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator*(const mat<4, 4, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator*(const T& left, const mat<4, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<4, 4, T>::col_t operator*(const mat<4, 4, T>& left, const typename mat<4, 4, T>::row_t& right);

	template <typename T>
	GINNER_CONSTEXPR typename mat<4, 4, T>::row_t operator*(const typename mat<4, 4, T>::col_t& left, const mat<4, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 2, T> operator*(const mat<4, 4, T>& left, const mat<4, 2, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 3, T> operator*(const mat<4, 4, T>& left, const mat<4, 3, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator*(const mat<4, 4, T>& left, const mat<4, 4, T>& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator/(const mat<4, 4, T>& left, const T& right);

	template <typename T>
	GINNER_CONSTEXPR mat<4, 4, T> operator%(const mat<4, 4, T>& left, const T& right);

}

#include "ginner_mat.inl"

#endif
