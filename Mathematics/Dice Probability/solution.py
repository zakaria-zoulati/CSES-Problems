n , a , b = map( int , input().split() )

if b < n : 
    print(0)
else :
    a = max( n , a )
    dp = [ [0]*(6*n+1) for i in range(n+1) ] 
    dp[0][0] = 1 
    for i in range(1,n+1) :
        for j in range( 1 , 6*n+1 ) : 
            for k in range( 1 , 7 ) :
                if j - k >= 0 : 
                    dp[i][j] += dp[i-1][j-k]
    p1 = 0 
    p2 = 0  
    for i in range( a , b+1 ) : 
        p1 += dp[n][i] 
    for i in range( n , 6*n +1 ) : 
        p2 += dp[n][i]
    rs = p1/p2 
    print(f"{rs:.6f}")
