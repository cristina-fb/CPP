#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

class Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed const & src );
		~Fixed( void );

		Fixed & operator=( Fixed const & rhs);
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int _f_value;
		static const int _f_bits = 8;
};
#endif
