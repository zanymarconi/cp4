#include <pddef.h>
using namespace std;

void print_subsets(int N) {
    for (int i = 0; i < (1 << N); ++i) {
        printf("{ ");
        int pos = i;
        while (pos) {
            int ls = LSOne(pos);            // Get the least significant bit
            int index = __builtin_ctz(ls);  // Count trailing zeros to find the index
            printf("%d ", index);
            pos -= ls;                      // Remove the least significant bit
        }
        printf("}\n");
    }
}

int main() {
    print_subsets(5);
    return 0;
}
