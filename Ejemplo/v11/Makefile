OBJETOS = ICollectible.o IKey.o \
OrderedKey.o IIterator.o ICollection.o \
ListNode.o ListIterator.o List.o IDictionary.o \
OrderedDictionaryEntry.o \
OrderedDictionary.o \
DtReporteDep.o DtReporteZ.o \
ReporteDepartamento.o ReporteZona.o DtReporteInm.o \
InfoPropiedad.o InfoAp.o InfoC.o DtInmobiliaria.o \
StringKey.o IntKey.o \
Direccion.o DtOferta.o DtCodDirProp.o DtDepartamento.o DtEdificio.o \
DtZona.o FechaYHora.o HoraSistema.o \
DtPropiedad.o \
Usuario.o Interesado.o Administrador.o Inmobiliaria.o Sesion.o \
Edificio.o ColeccionEdificios.o DtMensaje.o \
Alquiler.o Venta.o \
Propiedad.o Apartamento.o Casa.o Zona.o Departamento.o Mensaje.o Conversa.o \
LetraIdentificadora.o \
ControladorUsuarios.o \
ControladorPropiedades.o

FUENTES = interfaces/ICollectible.cpp interfaces/ICollectible.h \
interfaces/IKey.cpp interfaces/IKey.h \
interfaces/OrderedKey.cpp interfaces/OrderedKey.h \
interfaces/IIterator.cpp interfaces/IIterator.h \
interfaces/ICollection.cpp interfaces/ICollection.h \
collections/ListNode.cpp collections/ListNode.h \
collections/ListIterator.cpp collections/ListIterator.h \
collections/List.cpp collections/List.h \
interfaces/IDictionary.cpp interfaces/IDictionary.h \
collections/OrderedDictionaryEntry.cpp collections/OrderedDictionaryEntry.h \
collections/OrderedDictionary.cpp collections/OrderedDictionary.h \
DtReporteDep.cpp DtReporteDep.h DtReporteZ.cpp DtReporteZ.h \
ReporteDepartamento.cpp ReporteDepartamento.h ReporteZona.cpp ReporteZona.h \
DtReporteInm.cpp DtReporteInm.h \
InfoPropiedad.cpp InfoPropiedad.h InfoAp.cpp InfoAp.h InfoC.cpp InfoC.h \
DtInmobiliaria.cpp DtInmobiliaria.h \
StringKey.cpp StringKey.h IntKey.cpp IntKey.h \
Direccion.cpp Direccion.h DtOferta.cpp DtOferta.h \
DtCodDirProp.cpp DtCodDirProp.h \
DtDepartamento.cpp DtDepartamento.h\
DtEdificio.cpp DtEdificio.h \
DtZona.cpp DtZona.h \
FechaYHora.cpp FechaYHora.h HoraSistema.cpp HoraSistema.h \
DtPropiedad.cpp DtPropiedad.h \
Usuario.cpp Usuario.h \
Interesado.cpp Interesado.h \
Administrador.cpp Administrador.h \
Inmobiliaria.cpp Inmobiliaria.h \
Sesion.cpp Sesion.h \
Edificio.cpp Edificio.h ColeccionEdificios.cpp ColeccionEdificios.h \
DtMensaje.cpp DtMensaje.h Alquiler.cpp Alquiler.h Venta.cpp Venta.h \
Propiedad.cpp Propiedad.h Apartamento.cpp Apartamento.h Casa.cpp Casa.h \
Zona.cpp Zona.h \
Departamento.cpp Departamento.h \
Mensaje.cpp Mensaje.h Conversa.cpp Conversa.h \
LetraIdentificadora.cpp LetraIdentificadora.h \
ControladorUsuarios.cpp ControladorUsuarios.h \
ControladorPropiedades.cpp ControladorPropiedades.h

CC = g++
OPCIONES = -std=c++11 -g -Wall -Werror


main: $(OBJETOS) main.cpp Makefile
	$(CC) $(OPCIONES) $(OBJETOS) main.cpp -o main

ICollectible.o: interfaces/ICollectible.h interfaces/ICollectible.cpp
	$(CC) $(OPCIONES) -c interfaces/ICollectible.cpp -o ICollectible.o

IKey.o: interfaces/IKey.h interfaces/IKey.cpp
	$(CC) $(OPCIONES) -c interfaces/IKey.cpp -o IKey.o

OrderedKey.o: interfaces/OrderedKey.h interfaces/OrderedKey.cpp IKey.o
	$(CC) $(OPCIONES) -c interfaces/OrderedKey.cpp -o OrderedKey.o

IIterator.o: interfaces/IIterator.h interfaces/IIterator.cpp ICollectible.o
	$(CC) $(OPCIONES) -c interfaces/IIterator.cpp -o IIterator.o

ICollection.o: interfaces/ICollection.h interfaces/ICollection.cpp IIterator.o
	$(CC) $(OPCIONES) -c interfaces/ICollection.cpp -o ICollection.o

ListNode.o: collections/ListNode.h collections/ListNode.cpp ICollection.o
	$(CC) $(OPCIONES) -c collections/ListNode.cpp -o ListNode.o

ListIterator.o: collections/ListIterator.h collections/ListIterator.cpp ListNode.o
	$(CC) $(OPCIONES) -c collections/ListIterator.cpp -o ListIterator.o

List.o: collections/List.h collections/List.cpp ListNode.o ListIterator.o
	$(CC) $(OPCIONES) -c collections/List.cpp -o List.o

IDictionary.o: interfaces/IDictionary.h interfaces/IDictionary.cpp IKey.o ICollectible.o IIterator.o
	$(CC) $(OPCIONES) -c interfaces/IDictionary.cpp -o IDictionary.o

OrderedDictionaryEntry.o: collections/OrderedDictionaryEntry.h collections/OrderedDictionaryEntry.cpp OrderedKey.o ICollectible.o
	$(CC) $(OPCIONES) -c collections/OrderedDictionaryEntry.cpp -o OrderedDictionaryEntry.o

OrderedDictionary.o: collections/OrderedDictionary.h collections/OrderedDictionary.cpp OrderedDictionaryEntry.o ListNode.o IDictionary.o ListIterator.o
	$(CC) $(OPCIONES) -c collections/OrderedDictionary.cpp -o OrderedDictionary.o

DtReporteDep.o: DtReporteDep.h DtReporteDep.cpp \
ICollectible.o
	$(CC) $(OPCIONES) -c DtReporteDep.cpp -o DtReporteDep.o

DtReporteZ.o: DtReporteZ.h DtReporteZ.cpp ICollectible.o
	$(CC) $(OPCIONES) -c DtReporteZ.cpp -o DtReporteZ.o

ReporteDepartamento.o: ReporteDepartamento.h ReporteDepartamento.cpp \
ICollectible.o DtReporteDep.o
	$(CC) $(OPCIONES) -c ReporteDepartamento.cpp -o ReporteDepartamento.o

ReporteZona.o: ReporteZona.h ReporteZona.cpp ICollectible.o DtReporteZ.o
	$(CC) $(OPCIONES) -c ReporteZona.cpp -o ReporteZona.o

DtReporteInm.o: DtReporteInm.h DtReporteInm.cpp ICollectible.o ICollection.o \
DtInmobiliaria.o
	$(CC) $(OPCIONES) -c DtReporteInm.cpp -o DtReporteInm.o

InfoPropiedad.o: InfoPropiedad.h InfoPropiedad.cpp ICollectible.o \
Direccion.o
	$(CC) $(OPCIONES) -c InfoPropiedad.cpp -o InfoPropiedad.o

InfoAp.o: InfoAp.h InfoAp.cpp InfoPropiedad.o
	$(CC) $(OPCIONES) -c InfoAp.cpp -o InfoAp.o

InfoC.o: InfoC.h InfoC.cpp InfoPropiedad.o
	$(CC) $(OPCIONES) -c InfoC.cpp -o InfoC.o

DtInmobiliaria.o: DtInmobiliaria.h DtInmobiliaria.cpp Direccion.o
	$(CC) $(OPCIONES) -c DtInmobiliaria.cpp -o DtInmobiliaria.o

StringKey.o: StringKey.h StringKey.cpp OrderedKey.o
	$(CC) $(OPCIONES) -c StringKey.cpp -o StringKey.o

IntKey.o: IntKey.h IntKey.cpp OrderedKey.o
	$(CC) $(OPCIONES) -c IntKey.cpp -o IntKey.o

Direccion.o: Direccion.h Direccion.cpp
	$(CC) $(OPCIONES) -c Direccion.cpp -o Direccion.o

DtCodDirProp.o: DtCodDirProp.h DtCodDirProp.cpp Direccion.o ICollectible.o
	$(CC) $(OPCIONES) -c DtCodDirProp.cpp -o DtCodDirProp.o

DtOferta.o: DtOferta.h DtOferta.cpp Direccion.o
	$(CC) $(OPCIONES) -c DtOferta.cpp -o DtOferta.o

DtDepartamento.o: DtDepartamento.h DtDepartamento.cpp ICollectible.o
	$(CC) $(OPCIONES) -c DtDepartamento.cpp -o DtDepartamento.o

DtEdificio.o: DtEdificio.h DtEdificio.cpp ICollectible.o
	$(CC) $(OPCIONES) -c DtEdificio.cpp -o DtEdificio.o

DtZona.o: DtZona.h DtZona.cpp ICollectible.o
	$(CC) $(OPCIONES) -c DtZona.cpp -o DtZona.o

FechaYHora.o: FechaYHora.h FechaYHora.cpp OrderedKey.o
	$(CC) $(OPCIONES) -c FechaYHora.cpp -o FechaYHora.o

HoraSistema.o: HoraSistema.h HoraSistema.cpp FechaYHora.o
	$(CC) $(OPCIONES) -c HoraSistema.cpp -o HoraSistema.o

DtPropiedad.o: DtPropiedad.h DtPropiedad.cpp Direccion.o ICollectible.o
	$(CC) $(OPCIONES) -c DtPropiedad.cpp -o DtPropiedad.o

Usuario.o: Usuario.h Usuario.cpp ICollectible.o
	$(CC) $(OPCIONES) -c Usuario.cpp -o Usuario.o

Interesado.o: Interesado.h Interesado.cpp Usuario.o ICollection.o \
List.o
	$(CC) $(OPCIONES) -c Interesado.cpp -o Interesado.o

Administrador.o: Administrador.h Administrador.cpp Usuario.o
	$(CC) $(OPCIONES) -c Administrador.cpp -o Administrador.o

Inmobiliaria.o: Inmobiliaria.h Inmobiliaria.cpp Usuario.o Direccion.o \
ICollection.o IDictionary.o List.o OrderedDictionary.o IntKey.o \
LetraIdentificadora.o DtInmobiliaria.o DtReporteInm.o \
ReporteDepartamento.o ReporteZona.o
	$(CC) $(OPCIONES) -c Inmobiliaria.cpp -o Inmobiliaria.o

Sesion.o: Sesion.h Sesion.cpp Usuario.o
	$(CC) $(OPCIONES) -c Sesion.cpp -o Sesion.o

Edificio.o: Edificio.h Edificio.cpp ICollectible.o DtEdificio.o
	$(CC) $(OPCIONES) -c Edificio.cpp -o Edificio.o

ColeccionEdificios.o: ColeccionEdificios.h ColeccionEdificios.cpp IIterator.o IDictionary.o OrderedDictionary.o ICollection.o List.o StringKey.o Edificio.o
	$(CC) $(OPCIONES) -c ColeccionEdificios.cpp -o ColeccionEdificios.o

DtMensaje.o: DtMensaje.h DtMensaje.cpp FechaYHora.o ICollectible.o
	$(CC) $(OPCIONES) -c DtMensaje.cpp -o DtMensaje.o

Alquiler.o: Alquiler.h Alquiler.cpp Inmobiliaria.o
		$(CC) $(OPCIONES) -c Alquiler.cpp -o Alquiler.o

Venta.o: Venta.h Venta.cpp Inmobiliaria.o
		$(CC) $(OPCIONES) -c Venta.cpp -o Venta.o

Propiedad.o: Propiedad.h Propiedad.cpp ICollectible.o ICollection.o \
Alquiler.o Venta.o List.o DtCodDirProp.o DtPropiedad.o
		$(CC) $(OPCIONES) -c Propiedad.cpp -o Propiedad.o

Apartamento.o: Apartamento.h Apartamento.cpp Edificio.o Propiedad.o \
ICollectible.o InfoPropiedad.o InfoAp.o ColeccionEdificios.o
		$(CC) $(OPCIONES) -c Apartamento.cpp -o Apartamento.o

Casa.o: Casa.h Casa.cpp Propiedad.o \
ICollectible.o InfoPropiedad.o InfoC.o
		$(CC) $(OPCIONES) -c Casa.cpp -o Casa.o

Zona.o: Zona.h Zona.cpp ICollectible.o ICollection.o IDictionary.o \
IIterator.o OrderedDictionary.o List.o IntKey.o Direccion.o DtZona.o \
Propiedad.o Apartamento.o Casa.o DtOferta.o DtCodDirProp.o
		$(CC) $(OPCIONES) -c Zona.cpp -o Zona.o

Departamento.o: Departamento.h Departamento.cpp ICollectible.o ICollection.o IDictionary.o IIterator.o Direccion.o DtOferta.o \
List.o OrderedDictionary.o DtDepartamento.o Zona.o DtZona.o IntKey.o \
InfoPropiedad.o
	$(CC) $(OPCIONES) -c Departamento.cpp -o Departamento.o

Mensaje.o: Mensaje.h Mensaje.cpp ICollectible.o FechaYHora.o DtMensaje.o \
HoraSistema.o
		$(CC) $(OPCIONES) -c Mensaje.cpp -o Mensaje.o

Conversa.o: Conversa.h Conversa.cpp ICollectible.o ICollection.o \
IDictionary.o List.o OrderedDictionary.o IIterator.o \
Inmobiliaria.o \
Interesado.o Mensaje.o Propiedad.o
		$(CC) $(OPCIONES) -c Conversa.cpp -o Conversa.o

LetraIdentificadora.o: LetraIdentificadora.h LetraIdentificadora.cpp ICollectible.o OrderedKey.o
	$(CC) $(OPCIONES) -c LetraIdentificadora.cpp -o LetraIdentificadora.o

ControladorUsuarios.o: ControladorUsuarios.h ControladorUsuarios.cpp \
Usuario.o ICollection.o IDictionary.o List.o OrderedDictionary.o IIterator.o \
Sesion.o StringKey.o Administrador.o Interesado.o Inmobiliaria.o Direccion.o
	$(CC) $(OPCIONES) -c ControladorUsuarios.cpp -o ControladorUsuarios.o

ControladorPropiedades.o: ControladorPropiedades.h ControladorPropiedades.cpp IDictionary.o OrderedDictionary.o \
ICollection.o List.o IIterator.o Direccion.o DtDepartamento.o \
DtOferta.o Departamento.o LetraIdentificadora.o ColeccionEdificios.o \
InfoPropiedad.o
	$(CC) $(OPCIONES) -c ControladorPropiedades.cpp -o ControladorPropiedades.o

clean:
	rm -f $(OBJETOS) main

rebuild:
	make clean
	make


