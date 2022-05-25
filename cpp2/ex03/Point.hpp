#ifndef POINT_CLASS_H
# define POINT_CLASS_H
# include "Fixed.hpp"

class Point
{
	public:
		Point( void );
		Point( Point const & src );
		Point( Fixed const x, Fixed const y );
		~Point( void );

		Point & operator=( Point & rhs );

		const Fixed & getX( void );
		const Fixed & getY( void );

	private:
		Fixed const _x;
		Fixed const _y;
};
#endif
