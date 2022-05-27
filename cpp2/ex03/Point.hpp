#ifndef POINT_CLASS_H
# define POINT_CLASS_H
# include "Fixed.hpp"

class Point
{
	public:
		Point( void );
		Point( Point & src );
		Point( Fixed const x, Fixed const y );
		~Point( void );

		Point & operator=( Point & rhs );

		Fixed const & getX( void ) const;
		Fixed const & getY( void ) const;

	private:
		Fixed const _x;
		Fixed const _y;
};
#endif
