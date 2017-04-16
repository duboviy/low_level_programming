#include <iostream>     // std::cout
#include <algorithm>    // std::swap
#include <vector>       // std::vector


template <typename T >
void bubble_sort( T &a )
{
    for( T::size_type i = 0; a.size() && i < a.size() - 1; ++i )
    {
        for( T::size_type j = i; j + 1 > 0; --j )
        {
            if( a[j] > a[j+1] )
                std::swap( a[j], a[j+1] );
        }
    }
}


int main () {

    std::vector<int> v;
    v.push_back( 8 );
    v.push_back( 100 );
    v.push_back( 35 );
    v.push_back( 22 );
    v.push_back( 1 );

    bubble_sort( v );

    std::vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); ++it) {
        std::cout << (*it) << '\n';
    }

    return 0;
}
