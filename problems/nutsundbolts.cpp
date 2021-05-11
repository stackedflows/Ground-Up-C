class Solution{

#define P0 7
#define P1 19
#define P2 457
#define P3 6599

public:
    int hash(char item){
        int hashed = (int) ((P0 * item * P1 / P2) * P3 );
        cout << hashed;
        cout << "\n";
        return hashed;
    }

public:	
	void matchPairs(char nuts[], char bolts[], int n) {
	    
        char target[] = {'!', '#', '$', '%', '&', '*', '@', '^', '~'};
        
        int len = sizeof(target)/sizeof(target[0]);
        
        for(int i = 0; i < len; i++){
            hash(target[i]);
        }
	}

};
