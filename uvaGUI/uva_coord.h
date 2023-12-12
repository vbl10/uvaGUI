#pragma once

namespace uva
{
	template <typename T = float>
	struct coord
	{
		T x, y;

		coord operator+(coord rhs) const
		{
			rhs.x += x;
			rhs.y += y;
			return rhs;
		}
		coord operator-(coord rhs) const
		{
			rhs.x = x - rhs.x;
			rhs.y = y - rhs.y;
			return rhs;
		}
		coord operator*(coord rhs) const
		{
			rhs.x *= x;
			rhs.y *= y;
			return rhs;
		}
		coord operator/(coord rhs) const
		{
			rhs.x = x / rhs.x;
			rhs.y = y / rhs.y;
			return rhs;
		}
		coord operator*(const T& rhs) const
		{
			coord c = (*this);
			c.x *= rhs;
			c.y *= rhs;
			return c;
		}
		coord operator/(const T& rhs) const
		{
			coord c = (*this);
			c.x /= rhs;
			c.y /= rhs;
			return c;
		}

		coord operator+=(const coord& rhs)
		{
			return (*this) = (*this) + rhs;
		}
		coord operator-=(const coord& rhs)
		{
			return (*this) = (*this) - rhs;
		}
		coord operator*=(const coord& rhs)
		{
			return (*this) = (*this) * rhs;
		}
		coord operator/=(const coord& rhs)
		{
			return (*this) = (*this) / rhs;
		}
		coord operator*=(const T& rhs)
		{
			return (*this) = (*this) * rhs;
		}
		coord operator/=(const T& rhs)
		{
			return (*this) = (*this) / rhs;
		}

	};
	template <typename T>
	using dimension = coord<T>;
};

template <typename T>
uva::coord<T> operator+(const T& lhs, const uva::coord<T>& rhs)
{
	uva::coord c = { 0 };
	c.x = lhs + rhs.x;
	c.y = lhs + rhs.y;
	return c;
}

template <typename T>
uva::coord<T> operator-(const T& lhs, const uva::coord<T>& rhs)
{
	uva::coord c = { 0 };
	c.x = lhs - rhs.x;
	c.y = lhs - rhs.y;
	return c;
}

template <typename T>
uva::coord<T> operator*(const T& lhs, const uva::coord<T>& rhs)
{
	uva::coord c = { 0 };
	c.x = lhs * rhs.x;
	c.y = lhs * rhs.y;
	return c;
}

template <typename T>
uva::coord<T> operator/(const T& lhs, const uva::coord<T>& rhs)
{
	uva::coord c = { 0 };
	c.x = lhs / rhs.x;
	c.y = lhs / rhs.y;
	return c;
}