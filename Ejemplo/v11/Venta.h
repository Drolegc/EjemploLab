// Venta.h

#ifndef VENTA_H 
#define VENTA_H 

class Venta {
public:
    explicit Venta(double valor);
    Venta(const Venta&) = delete;
    Venta& operator=(const Venta&) = delete;
    ~Venta() {}

    double darValor() { return val; }

private:
    double val;
};

#endif
