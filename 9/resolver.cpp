#include "resolver.h"

Resolver::Resolver(fun* functions) {
    functor = Functor(functions);
    integer = 0;
    doubles = new double[0];
    arrays = new Array[0];
}
