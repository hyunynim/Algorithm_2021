#include<bits/stdc++.h>
using namespace std;
int board[22][22];
int tmp[22][22];
vector<int> pick;
int n, ans; 
void move(){
    for(auto d : pick){
	    if (d == 0) {
	    	for (int j = 0; j < n; ++j) {
	    		for (int k = 0; k < n; ++k) {
	    			for (int i = n - 1; i > 0; --i) {
	    				if (tmp[j][i] == 0) {
	    					tmp[j][i] = tmp[j][i - 1];
	    					tmp[j][i - 1] = 0;
	    				}
	    			}
	    		}
	    	}
	    	for (int j = 0; j < n; ++j) {
	    		for (int i = n - 1; i > 0; --i) {
	    			if (tmp[j][i] == tmp[j][i - 1]) {
	    				tmp[j][i] *= 2;
	    				tmp[j][i - 1] = 0;
	    			}
	    		}
	    	}
	    	for (int j = 0; j < n; ++j) {
	    		for (int k = 0; k < n; ++k) {
	    			for (int i = n - 1; i > 0; --i) {
	    				if (tmp[j][i] == 0) {
	    					tmp[j][i] = tmp[j][i - 1];
	    					tmp[j][i - 1] = 0;
	    				}
	    			}
	    		}
	    	}
	    }
	    else if (d == 1) {
	    	for (int j = 0; j < n; ++j) {
	    		for (int k = 0; k < n; ++k) {
	    			for (int i = 0; i < n - 1; ++i) {
	    				if (tmp[j][i] == 0) {
	    					tmp[j][i] = tmp[j][i + 1];
	    					tmp[j][i + 1] = 0;
	    				}
	    			}
	    		}
	    	}
	    	for (int j = 0; j < n; ++j) {
	    		for (int i = 0; i < n - 1; ++i) {
	    			if (tmp[j][i] == tmp[j][i + 1]) {
	    				tmp[j][i] *= 2;
	    				tmp[j][i + 1] = 0;
	    			}
	    		}
	    	}
	    	for (int j = 0; j < n; ++j) {
	    		for (int k = 0; k < n; ++k) {
	    			for (int i = 0; i < n - 1; ++i) {
	    				if (tmp[j][i] == 0) {
	    					tmp[j][i] = tmp[j][i + 1];
	    					tmp[j][i + 1] = 0;
	    				}
	    			}
	    		}
	    	}
	    }
	    else if (d == 2) {
	    	for (int j = 0; j < n; ++j) {
	    		for (int k = 0; k < n; ++k) {
	    			for (int i = n - 1; i > 0; --i) {
	    				if (tmp[i][j] == 0) {
	    					tmp[i][j] = tmp[i - 1][j];
	    					tmp[i - 1][j] = 0;
	    				}
	    			}
	    		}
	    	}
	    	for (int j = 0; j < n; ++j) {
	    		for (int i = n - 1; i > 0; --i) {
	    			if (tmp[i][j] == tmp[i - 1][j]) {
	    				tmp[i][j] *= 2;
	    				tmp[i - 1][j] = 0;
	    			}
	    		}
	    	}
	    	for (int j = 0; j < n; ++j) {
	    		for (int k = 0; k < n; ++k) {
	    			for (int i = n - 1; i > 0; --i) {
	    				if (tmp[i][j] == 0) {
	    					tmp[i][j] = tmp[i - 1][j];
	    					tmp[i - 1][j] = 0;
	    				}
	    			}
	    		}
	    	}
	    }
	    else if (d == 3) {
	    	for (int j = 0; j < n; ++j) {
	    		for (int k = 0; k < n; ++k) {
	    			for (int i = 0; i < n - 1; ++i) {
	    				if (tmp[i][j] == 0) {
	    					tmp[i][j] = tmp[i + 1][j];
	    					tmp[i + 1][j] = 0;
	    				}
	    			}
	    		}
	    	}
	    	for (int j = 0; j < n; ++j) {
	    		for (int i = 0; i < n - 1; ++i) {
	    			if (tmp[i][j] == tmp[i + 1][j]) {
	    				tmp[i][j] *= 2;
	    				tmp[i + 1][j] = 0;
	    			}
	    		}
	    	}
	    	for (int j = 0; j < n; ++j) {
	    		for (int k = 0; k < n; ++k) {
	    			for (int i = 0; i < n - 1; ++i) {
	    				if (tmp[i][j] == 0) {
	    					tmp[i][j] = tmp[i + 1][j];
	    					tmp[i + 1][j] = 0;
	    				}
	    			}
	    		}
	    	}
	    }
    }
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<n; ++j)
            ans = max(ans, tmp[i][j]);
}
void go(int toPick){
    if(toPick == 0){
        memcpy(tmp, board, sizeof(board));
        move();
        return;
    }
    for(int i = 0; i<4; ++i){
        pick.push_back(i);
        go(toPick - 1);
        pick.pop_back();
    }
}

int main(){scanf("%d", &n);
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<n; ++j)
            scanf("%d", &board[i][j]);
    
    go(5);
    printf("%d", ans);
}
