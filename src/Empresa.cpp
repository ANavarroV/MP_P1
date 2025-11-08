#include "Empresa.h"

//el constructor de la clase empresa debe crear un array dinámico de tamaño inicial 10
//debe inicializar a 0 los contadores de clientes (ncli) y contratos (ncon)
//y debe inicializar la constante nmaxcli a 100 y la variable nmaxcon a 10
Empresa::Empresa():nmaxcli(100) {
    this->ncli=0;
    this->ncon=0;
    this->contratos=new Contrato *[10]; //inicialmente capacidad para 10 Contratos
    this->nmaxcon=10;
}

//el destructor debe, además de eliminar el array dinámico creado en el constructor,
//eliminar los objetos clientes y contratos apuntados por ambos arrays
Empresa::~Empresa() {
    for(int i=0; i<this->ncon; i++) { //primero elimino los objetos contratos
        delete this->contratos[i];
    }

    delete [] this->contratos; //luego elimino el array de punteros

    for(int i=0; i<this->ncli; i++) { //primero elimino los objetos contratos
        delete this->clientes[i];
    }
    //delete [] this->clientes; //ERROR el array clientes no es dinámico
}

//método auxiliar usado por el método crearContrato
int Empresa::altaCliente(Cliente *c) { //añade cliente apuntado por c al array clientes
    int pos=-1; //devuelve -1 si no cabe y la posición donde

    if (ncli < nmaxcli) { //donde lo he metido si cabe
        clientes[ncli]=c;
        pos = ncli;
        ncli++;
    } else {
        cout << "Lo siento, el cupo de clientes esta lleno";
        pos=-1;
    }

    return pos;
}

bool Empresa::bajaCliente(long int dni){

    bool result = false;
    int pos = -1;

    for(int i = 0; i < ncli && pos == -1; i++){ // Busqueda del cliente
        if(clientes[i]->getDni() == dni){
            pos = i;
        }
    }

    if(pos != -1){ // Si el cliente existe ...

        for(int j = 0; j < ncon; j++){ // Recorremos contactos
            if(contratos[j]->getDniContrato() == dni){ // Si contrato tiene mismo dni ...
                /*delete contratos[j];

                for(int k=j+1; k<ncon; k++){ // Movemos los contratos una pos -1 <--
                    contratos[k-1]= contratos[k];
                }
                ncon--;*/
                cancelarContrato(j);
                j--; // Puede haber 2 contratos seguidos con el mismo dni, hay que evaluarlo
            }
        }

        delete clientes[pos];
        result = true;

        for(int k=pos+1; k<ncli; k++){
            clientes[k-1]= clientes[k];
        }
        ncli--;
    }

    return result;
}

//método auxiliar usado por el método crearContrato
int Empresa::buscarCliente(long int dni) const { //si no existe devuelve -1 y si existe devuelve la posición del cliente

    int pos = -1;
    for(int i = 0; i < ncli; i++){
        if(clientes[i]->getDni() == dni){
            pos = i;
        }
    }

    return pos;
}

int Empresa::nContratosTP() const{

    int cont = 0;

    for(int i = 0; i < ncon; i++){
        if(typeid(*contratos[i])==typeid(ContratoTP)){
            cont++;
        }
    }

    return cont;
}

void Empresa::crearContrato() {

    long int dni;
    int pos;
    cout << "\nIntroduzca dni: ";
    cin >> dni;

    pos = buscarCliente(dni);

    if (pos==-1) { //el cliente no existe y hay que darlo de alta

        int dia, mes, anio;
        char nombre[100];
        Cliente *c; //NO CREO NINGUN CLIENTE SINO SOLO UN PUNTERO A CLIENTE

        cout << "Nombre del cliente: ";
        cin.ignore();
        cin.getline(nombre, 100);

        cout << "Fecha de alta\n";
        cout << "dia: "; cin >> dia;
        cout << "mes: "; cin >> mes;
        cout << "anio: "; cin >> anio;

        c = new Cliente(dni, nombre, Fecha(dia, mes, anio));
        pos = altaCliente(c); //OJO HAY QUE IMPLEMENTARLO
    }

    if (pos!=-1) { //el cliente existe o se ha dado de alta
        //PREGUNTAR QUE TIPO DE CONTRATO QUIERE Y LOS DATOS NECESARIOS
        //CREAR EL OBJETO CONTRATO CORRESPONDIENTE Y AÑADIR AL ARRAY
        //contratos UN PUNTERO A DICHO OBJETO
        int tipoContrato;
        cout << "Tipo de Contrato a abrir (1-Tarifa Plana, 2-Movil): ";

        do{

            cin >> tipoContrato;
            if(tipoContrato != 1 && tipoContrato != 2){
                cout << "CONTRATO NO VALIDO! 1-Tarifa Plana o 2-Movil: ";
            }


        } while(tipoContrato != 1 && tipoContrato !=2);

        int diaC, mesC, anioC, minC;
        float precioM;
        char nacionalidad[50];

        cout << "Fecha del contrato\n";
        cout << "dia: "; cin >> diaC;
        cout << "mes: "; cin >> mesC;
        cout << "anio: "; cin >> anioC;

        cout << "minutos hablados: ";
        cin >> minC;
        Fecha fC(diaC, mesC, anioC);

        switch(tipoContrato){

            case 1:{
                ContratoTP *cTP = new ContratoTP(dni, fC, minC);

                capacidadContratos();

                contratos[ncon++] = cTP;

                break;
            }
            case 2:{
                cout << "Precio minuto: ";
                cin >> precioM;

                cout << "Nacionalidad: ";
                cin.ignore();
                cin.getline(nacionalidad, 50);

                ContratoMovil *cM = new ContratoMovil(dni, fC, precioM, minC, nacionalidad);

                capacidadContratos();
                contratos[ncon++] = cM;

                break;
            }
        }
    }
}

bool Empresa::cancelarContrato(int idContrato){

    bool result = false;
    int pos = -1;

    for(int i = 0; i < ncon; i++){
        if(contratos[i]->getIdContrato() == idContrato){
            pos = i;
            result = true;
        }
    }

    if(pos != -1){
        delete contratos[pos];

        for(int j=pos+1; j<ncon; j++){
            contratos[j-1]= contratos[j];
        }
        ncon--;

    }

    return result;
}

void Empresa::capacidadContratos(){
    if (ncon == nmaxcon) {
        Contrato **aux = contratos;
        contratos = new Contrato*[nmaxcon * 2];

        for (int i = 0; i < ncon; ++i)
            contratos[i] = aux[i];

        delete [] aux;
        nmaxcon *= 2;
    }
}

void Empresa::cargarDatos() {
    Fecha f1(29,2,2001), f2(31,1,2002), f3(1,2,2002);
    this->clientes[0] = new Cliente(75547001, "Peter Lee", f1);
    this->clientes[1] = new Cliente(45999000, "Juan Perez", Fecha(29,2,2000));
    this->clientes[2] = new Cliente(37000017, "Luis Bono", f2);
    this->ncli=3;
    this->contratos[0] = new ContratoMovil(75547001, f1, 0.12, 110, "DANES"); //habla 110m a 0.12€/m
    this->contratos[1] = new ContratoMovil(75547001, f2, 0.09, 170, "DANES"); //habla 170m a 0.09€/m
    this->contratos[2] = new ContratoTP(37000017, f3, 250); //habla 250m (300m a 10€, exceso 0.15€/m)
    this->contratos[3] = new ContratoTP(75547001, f1, 312); //habla 312m (300m a 10€, exceso 0.15€/m)
    this->contratos[4] = new ContratoMovil(45999000, f2, 0.10, 202, "ESPAÑOL"); //habla 202m a 0.10/m
    this->contratos[5] = new ContratoMovil(75547001, f2, 0.15, 80, "DANES"); //habla 80m a 0.15€/m
    this->contratos[6] = new ContratoTP(45999000, f3, 400); //habla 400m (300m a 10€, exceso 0.15€/m)
    this->ncon=7;
}

int Empresa::descuento(float porcentaje) const{ // Rebajar la tarifa de todos los contratos MOVIL

    float factor = 1.0 - (porcentaje/100);
    float precioM;
    int cont = 0;

    for(int i = 0; i < ncon; i++){
        if(ContratoMovil *cm = dynamic_cast<ContratoMovil*>(contratos[i])){

            precioM = cm->getPrecioMinuto();
            cm->setPrecioMinuto(precioM * factor);
            cont++;
        }
    }


    return cont;
}

void Empresa::ver() const{

    cout << "\nLa Empresa tiene " << ncli << " clientes y " << ncon << " contratos" << endl;
    cout << "Clientes:" << endl;
    for(int i = 0; i < ncli; i++){
        clientes[i]->ver();
        cout << endl;
    }

    cout << endl << "Contratos:" << endl;
    for(int i = 0; i < ncon; i++){
        contratos[i]->ver();
        cout << endl;
    }
}
