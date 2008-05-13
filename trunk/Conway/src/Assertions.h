#ifndef ASSERTIONS_H_
#define ASSERTIONS_H_
#define ASSERT_TRUE(A) if (!(A)) printf("Fallo en ASSERT_TRUE, archivo: %s, linea: %d.\n",__FILE__,__LINE__);
#define ASSERT_EQUALS(A,B) if ((A)!=(B)) printf("Fallo en ASSERT_EQUALS, archivo: %s, linea: %d.\n",__FILE__,__LINE__);
#endif /*ASSERTIONS_H_*/
