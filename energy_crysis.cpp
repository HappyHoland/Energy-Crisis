#include <iostream>
 
using namespace std;
 
int main() {
 
    int nRegions = -1;
    
    
    do {
        int finalRegion = 0;
        int hop = 1;
        
        cin >> nRegions;
        
        if (nRegions == 0) {
            break;
        } else if (nRegions < 13) {
            cout << "Invalid number" << endl;
            continue;
        }
        
        for (; finalRegion != 13;hop++) {
            finalRegion = 0;
            
            if (12%hop == 0 && hop != 1) {
                continue;
            }
        
            for (int i = 1; i <= nRegions - 1; i++) {
                if (i == 1) {
                    continue;
                } else {
                    finalRegion = ((hop - 1)%i + 1 + finalRegion)%i;
                }
                
            }
        
            finalRegion += 2;
        }
        
        cout << hop-1 << endl;
        
    } while (nRegions != 0);
 
    return 0;
}