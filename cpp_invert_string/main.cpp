template <typename T >
void invert_string( T &a )
{
    T::size_type length = a.size();
    for( T::size_type i = 0; i < (length/2); ++i )
    {
        std::swap( a[i], a[length - i - 1] );
    }
}

std::string str = "abcdefg";
invert_string(str);
