#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

class Fixed
{
	public:
		Fixed( void );
		Fixed( int const num );
		Fixed( float const num );
		Fixed( Fixed const & src );
		~Fixed( void );

		Fixed & operator=( Fixed const & rhs);
		bool operator<( Fixed const & rhs);
		bool operator>( Fixed const & rhs);
		bool operator<=( Fixed const & rhs);
		bool operator>=( Fixed const & rhs);
		bool operator==( Fixed const & rhs);
		bool operator!=( Fixed const & rhs);
		float operator+( Fixed const & rhs);
		float operator-( Fixed const & rhs);
		float operator*( Fixed const & rhs);
		float operator/( Fixed const & rhs);
		Fixed & operator++( int );
		Fixed & operator++( );
		Fixed & operator--( int );
		Fixed & operator--( );
		const Fixed & operatormin( Fixed const &rhs);
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const; 
		int toInt( void ) const; 

		/*static Fixed & min( Fixed & a, Fixed & b );
		static Fixed & max( Fixed & a, Fixed & b );*/

	private:
		int _f_value;
		static const int _f_bits = 8;
};
std::ostream & operator<<( std::ostream & o, Fixed const & rhs);
#endif
