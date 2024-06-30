#include <stdio.h>
int gcd(int a, int b) {
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
}
int main() {
  int numberOfInput;
  scanf("%d", &numberOfInput);
  int arrInput[numberOfInput];
  for (int i = 0; i < numberOfInput; i++) {
    scanf("%d", &arrInput[i]);   
  }
  int gcdPair1 = 0;
  gcdPair1 = gcd(arrInput[0],arrInput[1]);
  for(int i=2;i<numberOfInput;i++){
    gcdPair1 = gcd(gcdPair1,arrInput[i+1]);
  }
  printf("%d",gcdPair1);
return 0;
}