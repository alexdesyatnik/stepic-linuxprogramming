#include <stdio.h>
#include "solution.h"

int main() {
    const char *test1 = "test1"; // 5
    const char *test2 = "";  // 0
    int c = 0;
    printf("%i", solution(test1, 2, &c));
    printf("%i", c);
    printf("%i", solution(test2, 2, &c));
    printf("%i", c);
    return 0;
}