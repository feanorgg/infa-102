#include "Array.h"
#include "Functor.h"

class Resolver {
    private:
        Array* arrays;
        Functor functor;
        int integer;
        double* doubles;
    public:
        Resolver(fun* functions);
};
