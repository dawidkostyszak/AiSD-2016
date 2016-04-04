#include <iostream>

using namespace std;

int main() {
    char s, a;
    unsigned int n, m;
    scanf("%d %d",&n, &m);
    int table[n][m];

    for (unsigned int i=0; i<n; i++) {
        scanf("%c", &s);
        for (unsigned int j=0; j<m; j++) {
            scanf("%c", &a);
            table[i][j] = (a - '0') % 48;
        }
    }

    for (unsigned int i=0; i<n; i++) {
        for (unsigned int j=0; j<m; j++) {
            printf("%d", table[i][j]);
        }
        printf("\n");
    }

    printf("%d", n);
    return 0;
}

