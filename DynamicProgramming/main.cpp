//
//  main.cpp
//  DynamicProgramming
//
//  Created by Hamkuu Shaw on 6/13/16.
//  Copyright © 2016 hamkuu. All rights reserved.
//

#include <iostream>

template <typename T>
T max (T a, T b) {
    return (a > b) ? a : b;
}

// get the length of Longest Common Sequence
template <typename T>
int LCS (T * X, T * Y, int m, int n) {
    
    int l[m+1][n+1];
    
    for (int i=0; i<=m; ++i) {
        
        for (int j=0; j<=n; ++j) {
            
            if (i == 0 || j == 0) {
                
                l[i][j] = 0;
                
            } else if (X[i-1] == Y[j-1]) {
                
                l[i][j] = l[i-1][j-1] + 1;
                
            } else {
                
                l[i][j] = max(l[i-1][j], l[i][j-1]);
                
            }
            
        }
        
    }
    
    for (int i=0; i<=m; ++i) {
        
        for (int j=0; j<=n; ++j) {
            
            std::cout << l[i][j];
            
        }
        
        std::cout << std::endl;
        
    }
    
//    std::cout << std::endl;
//    
//    for (int i=m; i>=0; --i) {
//        
//        for (int j=n; j>=0; --j) {
//            
//            std::cout << l[i][j];
//            
//            if ((l[i-1][j] == l[i][j-1]) && (l[i][j] - 1 == l[i-1][j-1]) && (i-1 != 0 || j-1 != 0)) {
//                
//                std::cout << "";
//                
//            }
//            
//        }
//        
//        std::cout << std::endl;
//        
//    }
    
    return l[m][n];
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
 
    std::cout << LCS(X, Y, 6, 7) << std::endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
