// Alquiler.h

#ifndef ALQUILER_H
#define ALQUILER_H 

class Alquiler {
public:
    explicit Alquiler(double precioAlquiler);
    Alquiler(const Alquiler&) = delete;
    Alquiler& operator=(const Alquiler&) = delete;
    ~Alquiler() {}

    double darPrecioAlquiler() { return precio; }

private:
    double precio;
};

#endif
