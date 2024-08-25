#pragma once
#ifndef GINNER_TYPES
#define GINNER_TYPES



namespace gin
{

	using length_t = int;


	template <length_t L, typename T> struct vec;


	template <typename T> using vec1 = vec<1, T>;
	template <typename T> using vec2 = vec<2, T>;
	template <typename T> using vec3 = vec<3, T>;
	template <typename T> using vec4 = vec<4, T>;


	using vec1i = vec<1, int>;
	using vec2i = vec<2, int>;
	using vec3i = vec<3, int>;
	using vec4i = vec<4, int>;

	using vec1l = vec<1, long>;
	using vec2l = vec<2, long>;
	using vec3l = vec<3, long>;
	using vec4l = vec<4, long>;

	using vec1f = vec<1, float>;
	using vec2f = vec<2, float>;
	using vec3f = vec<3, float>;
	using vec4f = vec<4, float>;

	using vec1d = vec<1, double>;
	using vec2d = vec<2, double>;
	using vec3d = vec<3, double>;
	using vec4d = vec<4, double>;



	template <length_t C, length_t R, typename T> struct mat;


	template <typename T> using mat2x2 = mat<2, 2, T>;
	template <typename T> using mat2x3 = mat<2, 3, T>;
	template <typename T> using mat2x4 = mat<2, 4, T>;

	template <typename T> using mat3x2 = mat<3, 2, T>;
	template <typename T> using mat3x3 = mat<3, 3, T>;
	template <typename T> using mat3x4 = mat<3, 4, T>;

	template <typename T> using mat4x2 = mat<4, 2, T>;
	template <typename T> using mat4x3 = mat<4, 3, T>;
	template <typename T> using mat4x4 = mat<4, 4, T>;


	using mat2x2i = mat<2, 2, int>;
	using mat2x3i = mat<2, 3, int>;
	using mat2x4i = mat<2, 4, int>;

	using mat2x2l = mat<2, 2, long>;
	using mat2x3l = mat<2, 3, long>;
	using mat2x4l = mat<2, 4, long>;

	using mat2x2f = mat<2, 2, float>;
	using mat2x3f = mat<2, 3, float>;
	using mat2x4f = mat<2, 4, float>;

	using mat2x2d = mat<2, 2, double>;
	using mat2x3d = mat<2, 3, double>;
	using mat2x4d = mat<2, 4, double>;


	using mat3x2i = mat<3, 2, int>;
	using mat3x3i = mat<3, 3, int>;
	using mat3x4i = mat<3, 4, int>;

	using mat3x2l = mat<3, 2, long>;
	using mat3x3l = mat<3, 3, long>;
	using mat3x4l = mat<3, 4, long>;

	using mat3x2f = mat<3, 2, float>;
	using mat3x3f = mat<3, 3, float>;
	using mat3x4f = mat<3, 4, float>;

	using mat3x2d = mat<3, 2, double>;
	using mat3x3d = mat<3, 3, double>;
	using mat3x4d = mat<3, 4, double>;


	using mat4x2i = mat<4, 2, int>;
	using mat4x3i = mat<4, 3, int>;
	using mat4x4i = mat<4, 4, int>;

	using mat4x2l = mat<4, 2, long>;
	using mat4x3l = mat<4, 3, long>;
	using mat4x4l = mat<4, 4, long>;

	using mat4x2f = mat<4, 2, float>;
	using mat4x3f = mat<4, 3, float>;
	using mat4x4f = mat<4, 4, float>;

	using mat4x2d = mat<4, 2, double>;
	using mat4x3d = mat<4, 3, double>;
	using mat4x4d = mat<4, 4, double>;

}

#endif