#include <stdio.h>
#include <math.h>
#include <string.h>

#include "itoa.h"

long a = 5;

typedef struct {
  double x;
  double y;
  double z;
} affinePoint;

affinePoint opInv(affinePoint P) {
  affinePoint R;
  R.x = P.x;
  R.y = -P.y;
  R.z = P.z;
  return R;
}

affinePoint opAdd(affinePoint P, affinePoint Q) {
  affinePoint R;
  double lambda = 0;

  R.x=0; R.y=0; R.z=0;

  if(P.z == 0) return Q;
  if(Q.z == 0) return P;
  if(P.x == Q.x) {
    if(P.y + Q.y == 0) {
      if(P.y + Q.y == 0) {
        R.x=0; R.y=1; R.z=0;
        return R;
      }
      lambda = (3 * pow(P.x, 2) + a)/(2 * P.y);
    }
  }  
  
  else
    lambda = (Q.y - P.y)/(Q.x - P.x);

   R.x = pow(lambda, 2) - P.x - Q.x;
   R.y = lambda * (P.x - R.x) - P.y;
   R.z = 1;

   return R;
}

affinePoint opMult(long n, affinePoint P) {
  affinePoint R = {0,1,0};
  char m[20];

  itoa(n, m, 2);

  for(long i=strlen(m); i >= 0; i--) {
      R = opAdd(R, R);
      if(m[i] == '1') {
        R = opAdd(R, P);
      }
  }

  return R;
}

int main() {
  affinePoint p1, p2, r = {0,0,0};
  long s;
  
  printf("X-coordinate of point 1: ");
  scanf("%lf", &p1.x);
  printf("Y-coordinate of point 1: ");
  scanf("%lf", &p1.y);
  printf("Z-coordinate of point 1: ");
  scanf("%lf", &p1.z);

  printf("P1 = { %f, %f, %f }\n\n", p1.x, p1.y, p1.z);

  printf("X-coordinate of point 2: ");
  scanf("%lf", &p2.x);
  printf("Y-coordinate of point 2: ");
  scanf("%lf", &p2.y);
  printf("Z-coordinate of point 2: ");
  scanf("%lf", &p2.z);

  printf("P2 = { %f, %f, %f }\n\n", p2.x, p2.y, p2.z);
  printf("Scalar number: ");
  scanf("%ld", &s);

  printf("\n-----------------------------------------\n");

  r = opAdd(p1, p2);
  printf("\nP1 + P2 = { %f, %f, %f }\n", r.x, r.y, r.z);

  r = opMult(s, p1);
  printf("\nP1 * n = { %f, %f, %f }\n", r.x, r.y, r.z);

  return 0;
}
