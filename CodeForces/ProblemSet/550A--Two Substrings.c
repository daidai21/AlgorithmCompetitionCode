// https://codeforces.com/problemset/problem/550/A


#include <stdio.h>
#include <string.h>


int main() {
  char S[100000], * p;
  scanf("%s", &S);

  if ( (p = strstr(S, "AB")) && (strstr(p + 2, "BA")) )
    printf("YES\n");
  else if ( (p = strstr(S, "BA")) && (strstr(p + 2, "AB")) )
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}




