#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
long long res , taxi , bus , station , b [ 100005 ] , n , house , m [ 100005 ] , f [ 100005 ] ;
long long l , r, b1 , b2 ;
long long bs( long long i )
{
    long long temp = 0 ;
    l = 0 ; r = station + 1 ;
    while ( l <= r ) {
        long long mid = ( l + r ) >> 1 ;
        if ( b [ mid ] > m [ i ] ) r = mid - 1 ;
        else
        {
            temp = mid ;
            l = mid + 1 ;
        }
    }
    //cout << b [temp] << endl ;
    return temp ;
}
long long binarySearch ( int i )
{
    long long temp = station + 1 ;
    l = 0 ; r = station + 1 ;
    while ( l <= r ) {
        long long mid = ( l + r ) >> 1 ;
        if ( b [ mid ] < m [ i ] ) l = mid + 1 ;
        else
        {
            temp = mid ;
            r = mid - 1 ;
        }
    }
    //cout << b [temp] << endl ;
    return temp ;
}
int main ()
{
    ios_base::sync_with_stdio (0) ;
    cin.tie (0) ; cout.tie (0) ;
    // freopen ( "test.inp" , "r" , stdin );
    // freopen ( "test.out" , "w" , stdout ) ;
    cin >> n >> house >> station >> taxi >> bus ;
    for ( int i = 1 ; i <= house ; ++i )
    {
        cin >> m [ i ] ;
    }
    for ( int i = 1 ; i <= station ; ++i )
    {
        cin >> b [ i ] ;
    }
    //sort ( m + 1 , m + house + 1 );
    m [ 0 ] = 1 ;
    m [ house + 1 ] = n ;
    b [ 0 ] = 1 ;
    b [ station + 1 ] = n ;
    for ( int i = 1 ; i <= house + 1 ; ++i )
    {
        b2 = min ( abs ( m [ i ] - b [ bs ( i ) ] ) , abs ( m [ i ] - b [ binarySearch ( i ) ] ) ) ;
        b1 = min ( abs ( m [ i - 1 ] - b [ bs ( i - 1 ) ] ) , abs ( m [ i - 1 ] - b [ binarySearch ( i - 1 ) ] ) ) ;
        //cout << b1 << " " << b2 << endl ;
            res += min ( abs ( m [ i ] - m [ i - 1 ] ) * taxi ,
                         (  ( b1 + b2 ) * taxi + bus ) ) ;
    }
    cout << res ;
}
