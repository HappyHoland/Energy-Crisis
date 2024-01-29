#include <iostream>
 
using namespace std;

//Josephus flavius algorithm
int josephus (int num, int hop) {
    int res = 0;

    for (int i = 1; i <= num - 1; i++) {
        if (i == 1) {
            continue;
        } else {
            res = ((hop - 1)%i + 1 + res)%i;
        }
                
    }

    return res + 1;
}
 
int main() {
 
    int nRegions = -1;
    
    
    do {
        int finalRegion = 0;
        int hop = 1;
        
        cin >> nRegions;
        
        //End case and invalid cases check
        if (nRegions == 0) {
            break;
        } else if (nRegions < 13) {
            cout << "Invalid number" << endl;
            continue;
        }
        
        //Find first hop amount that ends in region 13 for current number of regions
        for (; finalRegion != 13;hop++) {
            finalRegion = 0;
            
            //Skip hops that will eliminate 13 quickly
            if (12%hop == 0 && hop != 1) {
                continue;
            }

            //Calculate last region with current hop and number of regions
            finalRegion = josephus(nRegions-1, hop) + 1;
        }
        
        //correct hop and send
        cout << hop-1 << endl;
        
    } while (nRegions != 0);
 
    return 0;
}