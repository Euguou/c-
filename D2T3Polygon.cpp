#include<iostream>  
  
using namespace std;  
  
#define MAXN 101  
struct Node {  
    long mmax;  
    long mmin;  
} f[MAXN][MAXN];  
  
int main() {  
  
    long n, num[101], l, i, k, j, len, maxx[101], want=-65535;  
    char op[101];  
    cin >> n;  
    for (i = 1;  
            i <= n;  
            i++) {  
                cin >> op[i] >> num[i];  
                num[i + n] = num[i];  
                op[i + n] = op[i];  
            }  
            for (l = 1; l <= n; l++) {  
                for (k = 1; k <= 100; k++) {  
                    for (j = 1; j <= 100; j++) {  
                        f[k][j].mmax = -65535;  
                        f[k][j].mmin = 65535;  
                    }  
                }  
                for (k = l; k <= l + n - 1; k++) {  
                    f[k][k].mmax = f[k][k].mmin = num[k];  
                }  
                for (len = 2; len <= n; len++)  
                    for (i = l; i <= l + n - 1; i++) {  
                        j = i + len - 1;  
                        if (j > l + n - 1)  
                            break;  
                        for (k = i + 1; k <= j; k++) {  
                            if (op[k] == 't') {  
                                f[i][j].mmax = max(f[i][j].mmax,  
                                        f[i][k - 1].mmax + f[k][j].mmax);  
                                f[i][j].mmin = min(f[i][j].mmin,  
                                        f[i][k - 1].mmin + f[k][j].mmin);  
                            } else {  
                                f[i][j].mmax = max(f[i][j].mmax, max(  
                                        f[i][k - 1].mmax * f[k][j].mmax,  
                                        max(f[i][k - 1].mmin * f[k][j].mmax,  
                                                max(f[i][k - 1].mmax  
                                                        * f[k][j].mmin, f[i][k  
                                                        - 1].mmin  
                                                        * f[k][j].mmin))));  
                                f[i][j].mmin = min(f[i][j].mmin, min(  
                                        f[i][k - 1].mmax * f[k][j].mmax,  
                                        min(f[i][k - 1].mmin * f[k][j].mmax,  
                                                min(f[i][k - 1].mmax  
                                                        * f[k][j].mmin, f[i][k  
                                                        - 1].mmin  
                                                        * f[k][j].mmin))));  
                            }  
                        }  
                    }  
                maxx[l] = f[l][l + n - 1].mmax;  
                want = max(want, maxx[l]);  
            }  
            cout << want << endl;  
            for (l = 1; l <= n; l++)  
                if (maxx[l] == want)  
                    cout << l <<" ";  
            cout << endl;  
            return 0;  
        }  
