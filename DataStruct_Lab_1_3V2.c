#include <stdio.h>
int gcd(int a, int b) {
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
}
int main() {
  int numberOfInput,gcdOfPair=0;
  scanf("%d", &numberOfInput);
  int arrInput[numberOfInput];
  for (int i = 0; i < numberOfInput; i++) {
    scanf("%d", &arrInput[i]);   
  }
  gcdOfPair = gcd(arrInput[0],arrInput[1]);
  for(int i=2;i<numberOfInput;i++){
    gcdOfPair = gcd(gcdOfPair,arrInput[i+1]);
  }
  printf("%d",gcdOfPair);
return 0;
}
