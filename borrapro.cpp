#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std; 


struct empleados{	char nom[22];
					char pat[22];
					char mat[22];
					char direccion[50];
					int telefono;
					int clavedep;
					int claveturno;
					int ventas;
					bool valido;};
					
struct medicamentos{ char nom[22];
					 char gen[40];
					 int clave;
					 float preventa;
					 float precosto;
					 int existencia;
					 int vendidos;
					 bool valido;};
					
struct articulos{	char nom[22];
					int clave;
					float preventa;
					float precosto;
					int existencia;
					int vendidos;
					bool valido;};
					
struct venta{		char fe[40];//fecha de la venta
					int num;///numero de venta
					int idem;//id empleado
					float total;//totaln sin iva
					float des;//descuento
					float iva;
					int identi; //suma de los contado
					int coa;//contador de ar
					int conm;//contador de med
					char cliente[50];};				

struct fechas{		char fec[40];
					int num;};


void inicio(fechas &f);
void basico(void);
int menu(void);
//funciones para empleados
void capturaempleados(empleados &em);
void altasempleados(empleados &em);
void reingresoempleados(empleados &em);
void bajaempleados(empleados &em);
void imprimeempleados(empleados &em);
//funciones para articulos
void capturaarticulos(articulos &ar);
void altasarticulos (articulos &ar);
void bajasarticulos(articulos &ar);
void reingresoarticulos(articulos &ar);
void imprimearticulos(articulos &ar);
//funciones para medicamentos
void capturamed(medicamentos &med);
void altasmed (medicamentos &med);
void bajasmed(medicamentos &med);
void imprimemed(medicamentos &med);
void reingresomed(medicamentos &med);
//funciones ventas
void ventas(empleados &em,medicamentos &med,articulos &ar,venta &v,fechas &f);
void altaven(venta &v,fechas &f);
void imprimeventas(venta &v);

//funciones de consultas
void consultas(empleados &em,medicamentos &med,articulos &ar,venta &v,fechas &f);
int menuconsultas(void);
void conemp(empleados &em);
void conart(articulos &ar);
void conmed(medicamentos &med);
void conunoemp(empleados &em);
void conunoart(articulos &ar);
void conunomed(medicamentos &med);
void consven(venta &v);
void conventas(empleados &em,medicamentos &med,articulos &ar,venta &v,fechas &f);
void pru(/*empleados &em,medicamentos &med,articulos &ar,*/venta &v,fechas &f);

//funciones de cambio
void cambios(empleados &em,medicamentos &med,articulos &ar);
int menucambios(void);
void camemp(empleados &em);
void menucamemp(empleados &em);
void camart(articulos &ar);
void menucamart(articulos &ar);
void cammed(medicamentos &med);
void menucammed(medicamentos &med);


char fecha[40];
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
int main(){
	venta v;
	empleados em;
	medicamentos med;
	articulos ar;
	fechas f;
	
	int op;
	//inicio(f);

	do {
		op = menu();
		
		switch (op){
			case 1:		
				 capturaempleados(em);
				 altasempleados(em);
				break;
			case 2:		
				reingresoempleados(em);
				break;	
			case 3:		
				bajaempleados(em);
				break;
			case 4:		
				capturaarticulos(ar);
				altasarticulos(ar);
				break;
			case 5:		
				reingresoarticulos(ar);
				break;	
			case 6:		
				bajasarticulos(ar);
				break;	
			case 7:		
				capturamed(med);
				altasmed(med);
				break;	
			case 8:		
				reingresomed(med);
				break;	
			case 9:		
				bajasmed(med);
				break;
			case 10:		
				ventas(em,med,ar,v,f);
				altaven(v,f);
				break;
			case 11:		
				cambios(em,med,ar);
				break;	
			case 12:		
				consultas(em,med,ar,v,f);
				break;	
			case 13:		
				
				break;		
			default : cout <<"Opcion incorrecta"<<endl;					
		}
		system("pause");
	}while (op!=13);
	
	
}

void inicio(fechas &f){ 
	ofstream arch1; 
    arch1.open("C://Archivos/fechas.dat" ,ios::out | ios::app | ios::binary); 
	system("cls");
	cout <<"\n";
	cout << "\t\t\tFarmacia Chayanne"<<endl<<endl;
	cout <<"\t Compra aqui, por que chayane lo tiene todo"<<endl;
	cout << "\n"<<endl;
	cout <<"----------------------------------------------------------------"<<endl;
	cout <<"\n";	
	cout <<"\t\t\t    Bienvenido"<<endl;
	cout <<"\n";
	cout <<"\t\t  Ingrese la fecha: ";
	cin >>fecha;
	f.fec[40]=fecha[40];
	if (arch1){ 
        arch1.write((char *)&f, sizeof(f)); 
	} else 
     cout << "Error en el archivo de fecha" << endl;  
     
     
    arch1.close();
	
}

void basico(void){
	system("cls");
	cout <<"\n";
	cout <<"\t\t\t\t\t\t"<<fecha<<endl;
	cout << "\t\t\tFarmacia Chayanne"<<endl<<endl;
	cout <<"\t Compra aqui, por que chayane lo tiene todo"<<endl;
	cout << "\n"<<endl;
	cout <<"----------------------------------------------------------------"<<endl;
	cout <<"\n";
}

int menu(void){
	int op;
	basico();
	cout <<"\n\t\t    ¿Qué desea hacer? "<<endl;
	cout <<"\n";
	cout <<"\t\t1) Captura     de  empleados"<<endl;
	cout <<"\t\t2) Reingreso   de  empelados"<<endl;
	cout <<"\t\t3) Bajas      de   empleados"<<endl;
	cout <<"\t\t4) Captura    de   articulos"<<endl;
	cout <<"\t\t5) Reingreso   de  articulos"<<endl;
	cout <<"\t\t6) Bajas      de   articulos"<<endl;
	cout <<"\t\t7) Captura  de  medicamentos"<<endl;
	cout <<"\t\t8) Reingreso de medicamentos"<<endl;
	cout <<"\t\t9) Bajas   de   medicamentos"<<endl;
	cout <<"\t\t10) Realizar          ventas"<<endl;
	cout <<"\t\t11) Realizar         cambios"<<endl;
	cout <<"\t\t12) Realizar       consultas"<<endl;
	cout <<"\t\t13)                    Salir"<<endl<<endl;
	cout <<"\tIntroduce el numero de la opcion deseada: ";
	cin >> op;
	return op;
}

void capturaempleados(empleados &em){
	string enter;
	string turno[]={"","Matutino", "Vespertino","Nocturno"};
	string departamento[]={"","Ventas","Dependencia"};
	getline(cin,enter);
    
    basico();
	cout <<"\t\t\tCaptura de empleados"<<endl;
	cout <<"\n";
	cout <<"\tNombre : "; 
	cin.getline(em.nom,22); 
	cout << "\tApellido Paterno: ";
	cin.getline(em.pat,22);
	cout << "\tApellido Materno: ";
	cin.getline(em.mat,22);
	cout <<"\tDireccion ";
	cin.getline(em.direccion,50);
	cout << "\tTelefono ";
	cin >>em.telefono;
	cout << "\tSeleccione el departamento 1 o 2 "<<endl;
	for(int i=1;i<=2; i++){
		cout <<"\t"<< i<<" - "<<departamento[i]<<endl;
	}
	cout << "\tDepartamento ";
	cin >>em.clavedep;
	cout << "\tSeleccione el el turno 1 a 3 "<<endl;
	for(int i=1;i<=3; i++){
		cout <<"\t"<< i<<" - "<<turno[i]<<endl;
	}
	cout << "\tTurno ";
	cin >>em.claveturno;
	
	em.valido=true;
}

void altasempleados(empleados &em){ 
	ofstream arch; 
    arch.open("C://Archivos/empleados.dat" ,ios::out | ios::app | ios::binary); 
    basico();
    cout <<"\n\t\t\tAltas de empleados "<<endl;
	cout <<"\n";
	if (arch){ 
        arch.write((char *)&em, sizeof(em)); 
        cout << "\tEl registro se grabo con exito \n" << endl;
	}
   else 
   cout << "Error en el archivo " << endl; 
   arch.close(); 
}

void reingresoempleados(empleados &em){
	fstream arch;
	arch.open("C://Archivos/empleados.dat", ios::in | ios::out|ios::binary);
	int id;
	string res;
	
	if(arch){
		basico();
		cout<<"\n\t Dame tu ID: ";
		cin>>id;
		cout <<"\n";
		arch.seekg((id-1)*sizeof(em),ios::beg);//instrucion que busca 
		arch.read((char *)&em, sizeof(em));
		imprimeempleados(em);
		
		if(em.valido==false){
			em.valido=true;
			cout<<"\n\tSeguro que quieres regresar? s/n ";
			cin>>res;
			if(res=="s"){
				arch.seekg((id-1)*sizeof(em),ios::beg);//instrucion que busca 
				arch.write((char *)&em, sizeof(em)); 
				cout<<"\n\tBienvenido nuevamente\n"<<endl;	
			}
			else
				cout<<"\n\tQuedate en casa....\n"<<endl;
				
		}
		else
			cout<<"\n\tEl registro esta activo \n"<<endl;
	}
	else
		cout<<"Error en el archivo"<<endl;
		arch.close();
}

void bajaempleados(empleados &em){
	fstream arch;
	arch.open("C://Archivos/empleados.dat", ios::in | ios::out|ios::binary);
	int id;
	string seguro;
	if(arch){
		basico();
		cout<<"\n\t Dame tu ID: ";
		cin>>id;
		cout <<"\n";
		arch.seekg((id-1)*sizeof(em),ios::beg);//instrucion que busca 
		arch.read((char *)&em, sizeof(em));
		imprimeempleados(em);
		cout<<"Estas seguro? s/n ";
		cin>>seguro;
		
		if(seguro=="s"){
			arch.seekg((id-1)*sizeof(em),ios::beg);
			em.valido=false;
			arch.write((char *)&em, sizeof(em));
			cout<<"\n\tEl registro de dio de baja con exito\n"<<endl;
		
		}
		else
		cout<<"El registro no de dio de baja..."<<endl;
	}
	else
	cout<<"Error en el archivo"<<endl;
	arch.close();
}

void imprimeempleados(empleados &em){
	string turno[]={"","Matutino", "Vespertino","Nocturno"};
	string departamento[]={"","Ventas","Dependencia"};
	cout <<"\tNombre : "<<em.nom<<endl;
	cout << "\tApellido Paterno : "<<em.pat<<endl;
	cout << "\tApellido Materno : "<<em.mat<<endl;	
	cout <<"\tDireccion : "<<em.direccion<<endl;
	cout << "\tTelefono :"<<em.telefono<<endl;
	cout << "\tDepartamento : ";
	if(em.claveturno==1){
		cout << "Ventas "<<endl;
	}else{
		cout << "Dependencia "<<endl;
	}
	cout << "\tTurno : ";
	
	if(em.claveturno==1){
		cout << "Matutino "<<endl;
	}else{
		if(em.claveturno==2){
			cout << "Vespertino"<<endl;
		}else{
			if(em.claveturno==3){
				cout << "Nocturno"<<endl;
			}
		}
	}
	cout <<"\tValido  -----> "<<em.valido<<endl;
	cout <<"\n";
	
}
	


void capturaarticulos(articulos &ar){
	basico();
	string enter;
	getline(cin,enter);		
	cout <<"\t\t\tCaptura de articulos"<<endl;
	cout <<"\n";
	cout <<"\tNombre : "; 
	cin.getline(ar.nom,22); 	
	cout <<"\tPrecio de venta : "; 
	cin >>ar.preventa;
	cout <<"\tCosto : "; 
	cin >>ar.precosto;
	cout <<"\tExistencia : ";
	cin >>ar.existencia;
	ar.valido=true;
	system("pause");

}

void altasarticulos (articulos &ar){
	ofstream arch; 
    arch.open("C://Archivos/articulos.dat" ,ios::out | ios::app | ios::binary); 
    basico();
    cout <<"\n\t\t\tAltas de articulos "<<endl;
	cout <<"\n";
	if (arch){ 
        arch.write((char *)&ar, sizeof(ar)); 
        cout << "\tEl registro se grabo con exito " << endl;
	}
   else 
   cout << "Error en el archivo " << endl; 
   arch.close(); 
}

void bajasarticulos(articulos &ar){
	fstream arch;
	arch.open("C://Archivos/articulos.dat", ios::in | ios::out|ios::binary);
	int id;
	string seguro;
	if(arch){
		basico();
		cout<<"\n\t Dame el ID del producto: ";
		cin>>id;
		cout <<"\n";
		arch.seekg((id-1)*sizeof(ar),ios::beg);//instrucion que busca 
		arch.read((char *)&ar, sizeof(ar));
		imprimearticulos(ar);
		cout<<"Estas seguro? s/n ";
		cin>>seguro;
		
		if(seguro=="s"){
			arch.seekg((id-1)*sizeof(ar),ios::beg);
			ar.valido=false;
			arch.write((char *)&ar, sizeof(ar));
			cout<<"\n\tEl registro de dio de baja con exito\n"<<endl;
		
		}
		else
		cout<<"El registro no de dio de baja..."<<endl;
	}
	else
	cout<<"Error en el archivo"<<endl;
	arch.close();
}

void imprimearticulos(articulos &ar){
	cout <<"\n\tNombre : "<<ar.nom<<endl; 	
	cout <<"\tPrecio de venta : "<<ar.preventa<<endl; 
	cout <<"\tCosto : "<<ar.precosto<<endl; 
	cout <<"\tExistencia : "<<ar.existencia<<endl;
	cout <<"\tClave "<<ar.clave <<endl;
	cout <<"\tValido  -----> "<<ar.valido<<endl;
	cout <<"\n";
}

void reingresoarticulos(articulos &ar){
	fstream arch;
	arch.open("C://Archivos/articulos.dat", ios::in | ios::out|ios::binary);
	int id;
	string res;
	
	if(arch){
		basico();
		cout<<"\n\t Dame el ID del producto: ";
		cin>>id;
		cout <<"\n";
		arch.seekg((id-1)*sizeof(ar),ios::beg);//instrucion que busca 
		arch.read((char *)&ar, sizeof(ar));
		imprimearticulos(ar);
		
		if(ar.valido==false){
			ar.valido=true;
			cout<<"\n\tSeguro que quieres regresar? s/n ";
			cin>>res;
			if(res=="s"){
				arch.seekg((id-1)*sizeof(ar),ios::beg);//instrucion que busca 
				arch.write((char *)&ar, sizeof(ar)); 
				cout<<"\n\tBienvenido nuevamente\n"<<endl;	
			}
			else
				cout<<"\n\tQuedate en casa....\n"<<endl;
				
		}
		else
			cout<<"\n\tEl registro esta activo \n"<<endl;
	}
	else
		cout<<"Error en el archivo"<<endl;
		arch.close();
}



void capturamed(medicamentos &med){
	
	string enter;
	getline(cin,enter);
	basico();
	cout <<"\t\t\tCaptura de medicamentos"<<endl;
	cout <<"\n";
	cout <<"\tNombre : "; 
	cin.getline(med.nom,22); 	
	cout <<"\tNombre generico : "; 
	cin.getline(med.gen,40);
	cout <<"\tPrecio de venta : "; 
	cin >>med.preventa;
	cout <<"\tCosto : "; 
	cin >>med.precosto;
	cout <<"\tExistencia : ";
	cin >>med.existencia;
	med.valido=true;
	
}

void altasmed (medicamentos &med){
	ofstream arch; 
    arch.open("C://Archivos/medicamentos.dat" ,ios::out | ios::app | ios::binary); 
    basico();
    cout <<"\n\t\t\tAltas de articulos "<<endl;
	cout <<"\n";
	if (arch){ 
        arch.write((char *)&med, sizeof(med)); 
        cout << "\tEl registro se grabo con exito " << endl;
	}
   else 
   cout << "Error en el archivo " << endl; 
   arch.close(); 
}

void bajasmed(medicamentos &med){
	fstream arch;
	arch.open("C://Archivos/medicamentos.dat", ios::in | ios::out|ios::binary);
	int id;
	string seguro;
	if(arch){
		basico();
		cout<<"\n\t Dame el ID del producto: ";
		cin>>id;
		cout <<"\n";
		arch.seekg((id-1)*sizeof(med),ios::beg);//instrucion que busca 
		arch.read((char *)&med, sizeof(med));
		imprimemed(med);
		cout<<"Estas seguro? s/n ";
		cin>>seguro;
		
		if(seguro=="s"){
			arch.seekg((id-1)*sizeof(med),ios::beg);
			med.valido=false;
			arch.write((char *)&med, sizeof(med));
			cout<<"\n\tEl registro de dio de baja con exito\n"<<endl;
		}
		else
		cout<<"El registro no de dio de baja..."<<endl;
	}
	else
	cout<<"Error en el archivo"<<endl;
	arch.close();
}

void imprimemed(medicamentos &med){
	cout <<"\n\tNombre : "<< med.nom<<endl; 
	cout <<"\tNombre generico : "<<med.gen <<endl;
	cout <<"\tPrecio de venta : "<<med.preventa <<endl;
	cout <<"\tCosto : "<< med.precosto<<endl;
	cout <<"\tExistencia : "<<med.existencia <<endl;
	cout <<"\tClave : "<<med.clave <<endl;
	cout <<"\tValido  -----> "<<med.valido <<endl;
	cout <<"\n";
}

void reingresomed(medicamentos &med){
	fstream arch;
	arch.open("C://Archivos/medicamentos.dat", ios::in | ios::out|ios::binary);
	int id;
	string res;
	
	if(arch){
		basico();
		cout<<"\n\t Dame el ID del producto: ";
		cin>>id;
		cout <<"\n";
		arch.seekg((id-1)*sizeof(med),ios::beg);//instrucion que busca 
		arch.read((char *)&med, sizeof(med));
		imprimemed(med);
		
		if(med.valido==false){
			med.valido=true;
			cout<<"\n\tSeguro que quieres regresar? s/n ";
			cin>>res;
			if(res=="s"){
				arch.seekg((id-1)*sizeof(med),ios::beg);//instrucion que busca 
				arch.write((char *)&med, sizeof(med)); 
				cout<<"\n\tBienvenido nuevamente\n"<<endl;	
			}
			else
				cout<<"\n\tQuedate en casa....\n"<<endl;
				
		}
		else
			cout<<"\n\tEl registro esta activo \n"<<endl;
	}
	else
		cout<<"Error en el archivo"<<endl;
		arch.close();
}



void ventas(empleados &em,medicamentos &med,articulos &ar,venta &v,fechas &f){	
	ofstream arch; 
	arch.open("C://Archivos/ventas.dat" ,ios::out | ios::app | ios::binary);
	fstream arch2;
	arch2.open("C://Archivos/medicamentos.dat" ,ios::in | ios::out|ios::binary); 
	fstream arch3;
	arch3.open("C://Archivos/articulos.dat",ios::in | ios::out|ios::binary);
	ifstream arch4; 
	arch4.open("C://Archivos/empleados.dat",ios::in | ios::out|ios::binary);
	
	int cona=0, conm=0, a5, contado=0,edad=0;	
	int a, idv=1, a2,a3, a4,id=1;
	string op, op2,op3;
	string enter;
	float total=0,total1=0;
	int idart[100000];
	int idmed[100000];
	int caart[100000];
	int camed[100000];
	
	basico();
	cout <<"\n\t\t\tIngresa tu id para realizar ventas: ";
	cin >>v.idem;
	cout <<"\n\t\t\t¿El cliente es mayor de 68 años? 1-si /2-no ";
	cin >>edad;
	getline(cin,enter);
	cout <<"\n\t\t\tIngresa el nombre del cliente: ";
	cin.getline(v.cliente,50);
	basico();
	total1=0;
	v.total=0;
	v.des=0;
	med.vendidos=0;	
	int am;
	
	do{
		cout <<"\n\t\t\t1.-Medicamentos 2.-articulos : ";
		cin >>am;
		if (am==1){
				do{
				cout <<"\n\t\t\tIngresa ID o clave del producto: ";
				cin >>a;
				conm++;	
				idmed[idv]=a;
				arch2.seekg((idmed[idv]-1)*sizeof(med),ios::beg);//instrucion que busca 
				arch2.read((char *)&med, sizeof(med));
				imprimemed(med);
				cout <<"\n\t\t\tIngresa la cantidad del producto: ";
				cin >>camed[idv];
				arch2.seekg((idmed[idv]-1)*sizeof(med),ios::beg);//instrucion que busca 
				arch2.read((char *)&med, sizeof(med));
				total=total+(camed[idv]*med.preventa);
				v.total=v.total+total;
				if(edad==1){
					v.des=v.des+total*.10;
					v.total=total*.90;
				}					
				a2=med.existencia-camed[idv];
				if (med.existencia==0){
					idv-2;
					cout <<	"\n\t\t\t No hay existentes "<<endl;
				}
				if(med.existencia<camed[idv]){
					idv-2;
					cout <<	"\n\t\t\t No hay suficientes "<<endl;
				
				}
				arch2.seekg((idmed[idv]-1)*sizeof(med),ios::beg);//instrucion que busca 
				arch2.read((char *)&med, sizeof(med));
				med.existencia= a2;
				med.vendidos=med.vendidos+camed[idv];
				arch2.seekg((idmed[idv]-1)*sizeof(med),ios::beg);
				arch2.write((char*)&med, sizeof(med));
				
				
				
				
			cout <<"\n\t\t\t Desea realizar mas ventas de medicamentos? s/n ";
			cin >>op;
			}while(op!="n");
		}
		if (am==2){
			do{
				cout <<"\n\t\t\tIngresa ID o clave del producto: ";
				cin >>a;
				cona++;
				idart[idv]=a;
				arch3.seekg((idart[idv]-1)*sizeof(ar),ios::beg);//instrucion que busca 
				arch3.read((char *)&ar, sizeof(ar));
				imprimearticulos(ar);
				cout <<"\n\t\t\tIngresa la cantidad del producto: ";
				cin >>caart[idv];
				
				a2=ar.existencia-caart[idv];
				if (ar.existencia==0){
					idv-2;
					cout <<	"\n\t\t\t No hay existentes "<<endl;
				}
				if(ar.existencia<caart[idv]){
					idv-2;
					cout <<	"\n\t\t\t No hay suficientes "<<endl;
				}
				arch3.seekg((idart[idv]-1)*sizeof(ar),ios::beg);//instrucion que busca 
				arch3.read((char *)&ar, sizeof(ar));
				ar.existencia= a2;
				ar.vendidos=ar.vendidos+caart[idv];
				arch3.seekg((idart[idv]-1)*sizeof(ar),ios::beg);
				arch3.write((char*)&ar, sizeof(ar));
				total1=total1+(caart[idv]*ar.preventa);
				v.total=v.total+total1;	
				cout <<"\n\t\t\t Desea realizar mas ventas de articulos? s/n ";
				cin >>op2;
			}while(op2!="n");
		}
		
		idv ++;
		cout <<"\n\t\t\t Desea realizar mas ventas? s/n ";
		cin >>op3;	
	}while(op3!="n");
	
	

	cout <<"\n\t\t\t¿El cliente desea pagar a contado? 1-si /2-no ";
	cin >>contado;		
	if(contado==1){
		a3=v.total*.10;
		v.total=v.total*.90;
		v.des=v.des+a3;
	}
		
	basico();
	v.iva= v.total*.16;
	cout <<"\n";
	cout <<"\t\t\t    Av. Torero #12 "<<endl;
	cout <<"\t\t\t Aguascalientes centro"<<endl;	
	cout <<"\t\t\t Cliente "<<v.cliente<<endl;
	cout <<"\n";
	cout <<"                            Caja #1                    "<<endl;	
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout<< setw(15)<< "Producto"<< setw(20)<< "Cantidad"<<setw(15)<< "Precio"<<endl;
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	for(int i=1; i<=conm; i++){
		a5 = idmed[i];
		
		arch2.seekg((a5-1)*sizeof(med),ios::beg);//instrucion que busca 
		arch2.read((char *)&med, sizeof(med));
		cout<< setw(15)<<med.nom<< setw(20)<<camed[i]<<setw(15)<< med.preventa<<endl;
	}
	for(int i=1; i<=cona; i++){
		a5 = idart[i];
		arch2.seekg((a5 -1)*sizeof(ar),ios::beg);//instrucion que busca 
		arch2.read((char *)&ar, sizeof(ar));
		cout<< setw(15)<<ar.nom<< setw(20)<<caart[i]<<setw(15)<< ar.preventa<<endl;
	}
	v.identi=conm+cona;
	v.coa=cona;
	v.conm=conm;
	
	cout <<"\n\n";
	cout << setw(45)<< "Monto: $"<<v.total<<endl;
	cout << setw(45)<< " Iva:  $"<<v.iva<<endl;
	cout << setw(45)<< "Total: $"<<v.total+v.iva<<endl;
	///lo de la liberia 
	cout <<"\n\n";
	cout <<"----------------------------------------------------------------"<<endl;
	cout << setw(35)<<"Folio de venta: #"<<id<<idv<<"G3A6"<<endl;
	
	if(arch4){
		arch4.seekg((v.idem-1)*sizeof(em),ios::beg);//instrucion que busca 
		arch4.read((char *)&em, sizeof(em));
		cout << setw(35)<<"Clave del empleado: "<<v.idem<<endl;
		cout << setw(35)<<"Atendido por: "<<em.nom<<" "<<em.pat<<endl;
		em.ventas+1;
	}
	else
	 cout<<"Error en el archivo";
	cout <<"\n\n";
	cout <<"----------------------------------------------------------------"<<endl;
	cout <<"\n\n";
	cout <<"                     Gracias por escojernos"<<endl;
	cout <<"\n";
	cout <<"----------------------------------------------------------------"<<endl;
	cout <<"\n";
	system ("pause");
	
	
	v.fe[40]=fecha[40];
	v.num=id;
	
	
	id ++;
	arch.close();
	arch2.close();
	arch3.close();
	arch4.close();
}

void altaven(venta &v,fechas &f){
	ofstream arch; 
    arch.open("C://Archivos/ventas.dat" ,ios::out | ios::app | ios::binary); 
       
    basico();
	if (arch){ 
        arch.write((char *)&v, sizeof(v)); 
        cout << "\tLa venta se grabo con exito " << endl;
	} else 
     cout << "Error en el archivo " << endl; 
    arch.close();
}

void imprimeventas(venta &v){
	cout <<"\n\tNumero de venta: "<< v.num<<endl; 
	cout <<"\tNombre del clinte : "<< v.cliente<<endl;
	cout <<"\tID empleado : "<< v.idem<<endl;
	cout <<"\tDescuento : "<< v.des<<endl;
	cout <<"\tIva : "<<v.iva <<endl;
	cout <<"\tTotal de venta : "<<v.total <<endl;
	cout <<"\n";
}



void consultas(empleados &em,medicamentos &med,articulos &ar,venta &v,fechas &f){
	int op;
	basico();
	do{
		op = menuconsultas();	
		switch (op){
			case 1:
				conmed(med);
				break;
			case 2:
				conemp(em);
				break;
			case 3:
				conart(ar);
				break;
			case 4:
				conmed(med);
				break;
			case 5:
				conunoemp(em);
				break;	
			case 6:
				conart(ar);
				break;	
			case 7:
				consven(v);
				break;	
			case 8:
				conventas(em,med,ar,v,f);
				break;	
			case 9:
				
				break;						
			default :cout <<"Opcion incorrecta";	
		}	
	}while (op!=9);
}

int menuconsultas(void){
	int op;
	basico();
	cout <<"\n\t\t\t¿Qué desea hacer? "<<endl;
	cout <<"\n";
	cout <<"\t1) Consulta total de medicamentos"<<endl;
	cout <<"\t2) Consulta  total  de  empleados"<<endl;
	cout <<"\t3) Consulta  total  de  articulos"<<endl;
	cout <<"\t4) Consulta    de    medicamentos"<<endl;
	cout <<"\t5) Consulta      de     empleados"<<endl;
	cout <<"\t6) Consulta      de     articulos"<<endl;
	cout <<"\t7) Consulta      de        ventas"<<endl;
	cout <<"\t8) Consulta  generales de  ventas"<<endl;
	cout <<"\t9)                          Salir"<<endl<<endl;
	cout <<"Introduce el numero de la opcion deseada: ";
	cin >> op;
	return op;
}

void conemp(empleados &em){
	int id=1;
	ifstream arch; 
	arch.open("C://Archivos/empleados.dat", ios::in | ios::binary);
	if(arch){
		arch.seekg(0, ios::beg); //se posiciona al inicio del archivo
		arch.read((char *)&em, sizeof(em));
		
		basico();
		cout <<"\n\t\tConsulta de todos los empleados "<<endl;
		cout <<"\n";
		while(!arch.eof()){
			cout<<"\tID: "<<id<<endl;
			imprimeempleados(em);
			id=id+1;
			arch.read((char *)&em, sizeof(em));//para moverse se vuelve a leer 
		}
		
	}
	else
	cout<<"error en el archivo"<<endl;
	
	arch.close();
	system("pause");
}

void conart(articulos &ar){
	int id=1;
	ifstream arch; 
	arch.open("C://Archivos/articulos.dat", ios::in | ios::binary);
	if(arch){
		arch.seekg(0, ios::beg); //se posiciona al inicio del archivo
		arch.read((char *)&ar, sizeof(ar));
		ar.clave=id;
		basico();
		cout <<"\n\t\tConsulta de todos los articulos "<<endl;
		cout <<"\n";
		while(!arch.eof()){
			cout<<"\tID o Clave: "<<id<<endl;
			imprimearticulos(ar);
			id=id+1;
			arch.read((char *)&ar, sizeof(ar));//para moverse se vuelve a leer 
		}
		
	}
	else
	cout<<"error en el archivo"<<endl;
	
	arch.close();
	system("pause");
}

void conmed(medicamentos &med){
	int id=1;
	ifstream arch; 
	arch.open("C://Archivos/medicamentos.dat", ios::in | ios::binary);
	if(arch){
		arch.seekg(0, ios::beg); //se posiciona al inicio del archivo
		arch.read((char *)&med, sizeof(med));
		med.clave=id;
		basico();
		cout <<"\n\t\tConsulta de todos los medicamentos "<<endl;
		cout <<"\n";
		while(!arch.eof()){
			cout<<"\tID o clave: "<<id<<endl;
			imprimemed(med);
			id=id+1;
			arch.read((char *)&med, sizeof(med));//para moverse se vuelve a leer 
		}
		
	}
	else
	cout<<"error en el archivo"<<endl;
	
	arch.close();
	system("pause");
}

void conunoemp(empleados &em){
	int id;
	fstream arch;
	arch.open("C://Archivos/empleados.dat", ios::in | ios::out|ios::binary);
	if(arch){
		basico();
		cout <<"\n\t\tConsulta de empleados "<<endl;
		cout <<"\n";
		cout<<"\n\t Dame tu ID: ";
		cin>>id;
		cout <<"\n";
		arch.seekg((id-1)*sizeof(em),ios::beg);//instrucion que busca 
		arch.read((char *)&em, sizeof(em));
		imprimeempleados(em);
	}
	else
	 cout<<"Error en el archivo";
	arch.close(); 
	system("pause");
}

void conunoart(articulos &ar){
	int id;
	fstream arch;
	arch.open("C://Archivos/articulos.dat", ios::in | ios::out|ios::binary);
	if(arch){
		basico();
		cout <<"\n\t\tConsulta de medicamentos "<<endl;
		cout <<"\n";
		cout<<"\n\t Dame el ID: ";
		cin>>id;
		cout <<"\n";
		arch.seekg((id-1)*sizeof(ar),ios::beg);//instrucion que busca 
		arch.read((char *)&ar, sizeof(ar));
		imprimearticulos(ar);
	}
	else
	 cout<<"Error en el archivo";
	arch.close(); 
	system("pause");
}

void conunomed(medicamentos &med){
	int id;
	fstream arch;
	arch.open("C://Archivos/medicamentos.dat", ios::in | ios::out|ios::binary);
	if(arch){
		basico();
		cout <<"\n\t\tConsulta de medicamentos "<<endl;
		cout <<"\n";
		cout<<"\n\t Dame tu ID: ";
		cin>>id;
		cout <<"\n";
		arch.seekg((id-1)*sizeof(med),ios::beg);//instrucion que busca 
		arch.read((char *)&med, sizeof(med));
		imprimemed(med);
	}
	else
	 cout<<"Error en el archivo";
	arch.close(); 
	system("pause");
}

void consven(venta &v){
	int id=1;
	ifstream arch; 
	arch.open("C://Archivos/ventas.dat", ios::in | ios::binary);
	if(arch){
		arch.seekg(0, ios::beg); //se posiciona al inicio del archivo
		arch.read((char *)&v, sizeof(v));
		basico();
		cout <<"\n\t\tConsulta de todos las ventas "<<endl;
		cout <<"\n";
		while(!arch.eof()){
			cout<<"\tNumero de venta : "<<id<<endl;
			imprimeventas(v);
			arch.read((char *)&v, sizeof(v));//para moverse se vuelve a leer 
		}
		
	}
	else
	cout<<"error en el archivo"<<endl;
	
	arch.close();
	system("pause");
}

void conventas(empleados &em,medicamentos &med,articulos &ar,venta &v,fechas &f){
	ifstream arch; 
	arch.open("C://Archivos/ventas.dat", ios::in | ios::binary);
	ifstream arch1; 
	arch1.open("C://Archivos/medicamentos.dat", ios::in | ios::binary);
	ifstream arch2; 
	arch2.open("C://Archivos/articulos.dat", ios::in | ios::binary);
	ifstream arch3; 
	arch3.open("C://Archivos/empleados.dat", ios::in | ios::binary);
	ifstream arch4; 
	arch4.open("C://Archivos/fechas.dat", ios::in | ios::binary);
	int mayor=0, menor=1000000,id,idmen,idma;
	float descutotal=0,prom=0;
	
	basico();
	cout <<"\n";
	cout <<"\t\t\t    Av. Torero #12 "<<endl;
	cout <<"\t\t\t Aguascalientes centro"<<endl;	
	cout <<"\t\t\t Cliente "<<v.cliente<<endl;
	cout <<"\n";
	cout <<"                            Caja #1                    "<<endl;	
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout <<"\n                       Ventas por dia \t"<<fecha<<endl;
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	id=1;
	if(arch4){
		arch4.seekg(0, ios::beg); //se posiciona al inicio del archivo
		arch4.read((char *)&f, sizeof(f));
		while(!arch4.eof()){
				if(arch){
					arch.seekg(0, ios::beg); //se posiciona al inicio del archivo
					arch.read((char *)&v, sizeof(v));
					while(!arch.eof()){
						if(f.fec==v.fe){
							cout <<setw(45)<<"Dia "<<f.fec<<endl;
							cout <<"\tNumero de venta : "<<id <<endl;
							imprimeventas(v);
							f.num++;
					}
				id=id+1;	
				}//arch
			}//arch
		}//arch4
			
	}
	
	system("pause");
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout <<"\n                           Clientes \t"<<fecha<<endl;
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout <<"\n";
	id=1;
	if(arch){
		arch.seekg(0, ios::beg); //se posiciona al inicio del archivo
		arch.read((char *)&v, sizeof(v));
		while(!arch.eof()){
			cout <<setw(30)<<"Cliente  # "<<id<<"  "<<v.cliente<<endl;
			id=id+1;
			arch.read((char *)&v, sizeof(v));//para moverse se vuelve a leer 
		}
	}
	else
	cout<<"error en el archivo"<<endl;
		
	system("pause");
	
	cout <<"\n";
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout <<"\n                     Ventas por vendedores \t"<<fecha<<endl;
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout <<"\n";
	id=1;
	if(arch3){
		arch3.seekg(0, ios::beg); //se posiciona al inicio del archivo
		arch3.read((char *)&em, sizeof(em));
		while(!arch3.eof()){
			cout <<setw(30)<<"ID "<<id<<endl;
			imprimeempleados(em);
			cout << "\tNumero de ventas hechas : "<<em.ventas<<endl;
			id=id+1;
			arch3.read((char *)&em, sizeof(em));//para moverse se vuelve a leer 
		}
	}else
	cout<<"error en el archivo"<<endl;
	

	
	system("pause");
	cout <<"\n";
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout <<"\n                        Artículos vendidos \t"<<fecha<<endl;
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout <<"\n";
	cout <<"\n                        Medicamentos"<<endl;
	cout <<setw(30)<<"Nombre "<<setw(15)<<" Nombre generico"<<setw(20)<<"Cantidad vendidos"<<endl;
	id=1;
	if(arch1){
		arch1.seekg(0, ios::beg); //se posiciona al inicio del archivo
		arch1.read((char *)&med, sizeof(med));
		while(!arch1.eof()){
			arch1.seekg((id-1)*sizeof(med),ios::beg);//instrucion que busca 
			arch1.read((char *)&med, sizeof(med));
			if(med.vendidos>0){
				cout <<setw(30)<<med.nom<<setw(15)<<med.gen<<setw(15)<<med.vendidos<<endl;
			}
			id++;
			arch1.read((char *)&med, sizeof(med));	
		}
	}else
	cout<<"error en el archivo"<<endl;
	
	cout <<"\n                         Articulos"<<endl;
	cout <<setw(15)<<"Nombre "<<setw(20)<<"Cantidad vendidos"<<endl;
	id=1;
	if(arch2){
		arch2.seekg(0, ios::beg); //se posiciona al inicio del archivo
		arch2.read((char *)&ar, sizeof(ar));
		while(!arch2.eof()){
			arch2.seekg((id-1)*sizeof(ar),ios::beg);//instrucion que busca 
			arch2.read((char *)&ar, sizeof(ar));
			if(ar.vendidos>0){
				cout <<setw(15)<<ar.nom<<setw(15)<<ar.vendidos<<endl;
			}
			id++;
			arch2.read((char *)&ar, sizeof(ar));		
		}	
	}else
	cout<<"error en el archivo"<<endl;
	
	system("pause");
	cout <<"\n";
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout <<"\n                        Descuento aplicado\t"<<fecha<<endl;
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout <<"\n";
	
	id=1;
	
	if(arch){
		arch.seekg(0, ios::beg); //se posiciona al inicio del archivo
		arch.read((char *)&v, sizeof(v));
		while(!arch.eof()){
			cout <<setw(30)<<"Venta # "<<id <<endl;
			cout <<setw(30)<<"Descuento "<<v.des<<endl;	
			id++;
			descutotal=descutotal+v.des;
			arch.read((char *)&v, sizeof(v));
		}
	}else
	cout<<"error en el archivo"<<endl;

	cout <<setw(50)<<"Descuento total"<<descutotal<<endl;	
	
	system("pause");
	cout <<"\n";
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout <<"\n                      Artículos más vendidos\t"<<fecha<<endl;
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout <<"\n";
	id=1;
	if(arch1){
		arch1.seekg(0, ios::beg); //se posiciona al inicio del archivo
		arch1.read((char *)&med, sizeof(med));
		while(!arch1.eof()){
			if(mayor>=med.vendidos){
				mayor=med.vendidos;
				idma=id;
			}	
			arch1.read((char *)&med, sizeof(med));
			id++;
		}
		
	}else
	cout<<"error en el archivo"<<endl;
	
	cout <<"\n                        Medicamento"<<endl;
	arch1.seekg((idma-1)*sizeof(med),ios::beg);//instrucion que busca 
	arch1.read((char *)&med, sizeof(med));
	imprimemed(med);
		
	mayor=0;
	idma=0;	
	id=1;
	if(arch2){
		arch2.seekg(0, ios::beg); //se posiciona al inicio del archivo
		arch2.read((char *)&ar, sizeof(ar));
		while(!arch2.eof()){
			if(mayor>=ar.vendidos){
				mayor=ar.vendidos;
				idma=id;
			}
		arch2.read((char *)&ar, sizeof(ar));
		id++;
		}	
	}else
	cout<<"error en el archivo"<<endl;
	
	cout <<"\n                         Articulo"<<endl;
	arch2.seekg((idma-1)*sizeof(ar),ios::beg);//instrucion que busca 
	arch2.read((char *)&ar, sizeof(ar));
	imprimearticulos(ar);
	
	system("pause");
	cout <<"\n";
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout <<"\n                     Articulos menos vendidos\t"<<fecha<<endl;
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout <<"\n";
	cout <<"\n                        Medicamento"<<endl;
	id=1;
	if(arch1){
		arch1.seekg(0, ios::beg); //se posiciona al inicio del archivo
		arch1.read((char *)&med, sizeof(med));
		while(!arch1.eof()){
			if(menor<=med.vendidos){
				menor=med.vendidos;
				idmen=id;
			}
			arch1.read((char *)&med, sizeof(med));
			id++;
		}
		
	}else
	cout<<"error en el archivo"<<endl;
	arch1.seekg((idma-1)*sizeof(med),ios::beg);//instrucion que busca 
	arch1.read((char *)&med, sizeof(med));
	imprimemed(med);
	
	
	id=1;
	menor=1000000;
	idmen=0;
	
	if(arch2){
		arch2.seekg(0, ios::beg); //se posiciona al inicio del archivo
		arch2.read((char *)&ar, sizeof(ar));
		while(!arch2.eof()){
			if(menor<=ar.vendidos){
				menor=ar.vendidos;
				idmen=id;
			}
		id++;	
		arch2.read((char *)&ar, sizeof(ar));
		}	
	}else
	cout<<"error en el archivo"<<endl;
	cout <<"\n                         Articulo"<<endl;
	arch2.seekg((idma-1)*sizeof(ar),ios::beg);//instrucion que busca 
	arch2.read((char *)&ar, sizeof(ar));
	imprimearticulos(ar);	
	system("pause");
	cout <<"\n";
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout <<"\n                  Vendedor con más ventas\t"<<fecha<<endl;
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout <<"\n";
	mayor=0;
	idma=0;	
	id=1;
	if(arch3){
		arch3.seekg(0, ios::beg); //se posiciona al inicio del archivo
		arch3.read((char *)&em, sizeof(em));
		while(!arch3.eof()){
			if(mayor>em.ventas){
				mayor=em.ventas;
				idma=id;
			}
		id++;
		arch3.read((char *)&em, sizeof(em));	
		}
	}
	arch3.seekg((v.idem-1)*sizeof(em),ios::beg);//instrucion que busca 
	arch.read((char *)&em, sizeof(em));
	imprimeempleados(em);
	system("pause");
	cout <<"\n";
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout <<"\n                  Vendedor con menos ventas\t"<<fecha<<endl;
	cout <<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = "<<endl;
	cout <<"\n";
	id=1;
	menor=1000000;
	idmen=0;
	
	if(arch3){
		arch3.seekg(0, ios::beg); //se posiciona al inicio del archivo
		arch3.read((char *)&em, sizeof(em));
		while(!arch3.eof()){
			if(menor<=em.ventas){
				menor=em.ventas;
				idmen=id;
			}
		id++;	
		arch3.read((char *)&em, sizeof(em));
		}	
	}else
	cout<<"error en el archivo"<<endl;
	
	system("pause");
	
	
	arch.close();
	arch1.close();
	arch2.close();
	arch3.close();
}

void pru(/*empleados &em,medicamentos &med,articulos &ar,*/venta &v,fechas &f){
	ifstream arch; 
	arch.open("C://Archivos/ventas.dat", ios::in | ios::binary);
	int id;
	float descutotal;
	
	
	
	system("pause");
}



void cambios(empleados &em,medicamentos &med,articulos &ar){
	int op;
	basico();
	do{	
		op=menucambios();
		switch (op){
			case 1:
				cammed(med);
				break;
			case 2:
				camemp(em);
				break;
			case 3:
				camart(ar);
				break;
			case 4:
				
				break;					
			default :cout <<"Opcion incorrecta";	
		}	
	}while (op!=4);
	
}

int menucambios(void){
	int op;
	basico();
	cout <<"\n\t\t\t¿Qué desea hacer? "<<endl;
	cout <<"\n";
	cout <<"\t1) Cambios de medicamentos"<<endl;
	cout <<"\t2) Cambios   de  empleados"<<endl;
	cout <<"\t3) Cambios  de   articulos"<<endl;
	cout <<"\t4)                   Salir"<<endl;
	cout <<"Introduce el numero de la opcion deseada: ";
	cin >> op;
	return op;
}

void camemp(empleados &em){
	int id,op;
	string op2, enter;
	fstream arch;
	arch.open("C://Archivos/empleados.dat", ios::in | ios::out|ios::binary);
	
	if(arch){
		basico();
		cout <<"\n\t\tCambios en empleados"<<endl;
		cout <<"\n";
		cout<<"\n\t Dame tu ID: ";
		cin>>id;
		cout <<"\n";
		arch.seekg((id-1)*sizeof(em),ios::beg);//instrucion que busca 
		arch.read((char *)&em, sizeof(em));
		menucamemp(em);
		
		arch.seekg((id-1)*sizeof(em),ios::beg);
		arch.write((char*)&em, sizeof(em));
		basico();
		cout<<"Cambios realizado con exito"<<endl;
			
	}
	else
		cout<<"Error en el archivo";
	arch.close();
}

void menucamemp(empleados &em){
	int op;
	string op2, enter;
	string turno[]={"","Matutino", "Vespertino","Nocturno"};
	string departamento[]={"","Ventas","Dependencia"};

	do{
		basico();
		cout <<"\n\t\t¿Qué deseas cambiar? "<<endl;
		cout <<"\n";
		cout <<"\t1)    Direccion"<<endl;
		cout <<"\t2)     Telefono"<<endl;
		cout <<"\t3) Departamento"<<endl;
		cout <<"\t4)        Salir"<<endl;
		cout <<"Introduce el numero de la opcion deseada: ";
		cin >> op;
		switch(op){
			case 1:
				basico();
				getline(cin,enter);
				cout <<"\tDireccion ";
				cin.getline(em.direccion,50);
				break;
			case 2:
				basico();
				getline(cin,enter);
				cout << "\tTelefono ";
				cin >>em.telefono;
				break;
			case 3:
				basico();
				getline(cin,enter);
				for(int i=1;i<=2; i++){
					cout <<"\t"<< i<<" - "<<departamento[i]<<endl;
				}
				cout << "\tDepartamento ";
				cin >>em.clavedep;
				break;
			case 4:
				basico();
				getline(cin,enter);
				cout << "\tSeleccione el el turno 1 a 3 "<<endl;
				for(int i=1;i<=3; i++){
					cout <<"\t"<< i<<" - "<<turno[i]<<endl;
				}
				cout << "\tTurno ";
				cin >>em.claveturno;
				break;
			case 5:
			
				break;				
			default :cout <<"Opcion incorrecta";	
		}
	
		basico();
		cout<<"Cambios completos? s/n ";
		cin>>op2;
	}while(op2!="s");
	
}

void camart(articulos &ar){
	int id,op;
	string op2, enter;
	fstream arch;
	arch.open("C://Archivos/articulos.dat", ios::in | ios::out|ios::binary);
	
	if(arch){
		basico();
		cout <<"\n\t\tCambios en articulos "<<endl;
		cout <<"\n";
		cout<<"\n\t Dame el ID: ";
		cin>>id;
		cout <<"\n";
		arch.seekg((id-1)*sizeof(ar),ios::beg);//instrucion que busca 
		arch.read((char *)&ar, sizeof(ar));
		menucamart(ar);
		
		arch.seekg((id-1)*sizeof(ar),ios::beg);
		arch.write((char*)&ar, sizeof(ar));
		basico();
		cout<<"Cambios realizado con exito"<<endl;
			
	}
	else
		cout<<"Error en el archivo";
	arch.close();
}

void menucamart(articulos &ar){
	int op;
	string op2, enter;

	do{
		basico();
		cout <<"\n\t\t¿Qué deseas cambiar? "<<endl;
		cout <<"\n";
		cout <<"\t1)          Nombre"<<endl;
		cout <<"\t2) Precio de venta"<<endl;
		cout <<"\t3) Precio de costo"<<endl;
		cout <<"\t4)      Existencia"<<endl;
		cout <<"\t5)  	       Salir"<<endl;
		cout <<"Introduce el numero de la opcion deseada: ";
		cin >> op;
		switch(op){
			case 1:
				basico();
				getline(cin,enter);
				cout <<"\tNombre : ";	
				cin.getline(ar.nom,22); 
				break;
			case 2:
				basico();
				getline(cin,enter);
				cout <<"\tPrecio de venta : "; 
				cin >>ar.preventa;
				break;
			case 3:
				basico();
				getline(cin,enter);
				cout <<"\tCosto : "; 
				cin >>ar.precosto;
				break;
				break;
			case 4:
				basico();
				getline(cin,enter);
				cout <<"\tExistencia : "; 
				cin >>ar.existencia;
			case 5:
			
				break;			
			default :cout <<"Opcion incorrecta";	
		}
	
		basico();
		cout<<"Cambios completos? s/n ";
		cin>>op2;
	}while(op2!="s");

		
}

void cammed(medicamentos &med){
	int id,op;
	string op2, enter;
	fstream arch;
	arch.open("C://Archivos/medicamentos.dat", ios::in | ios::out|ios::binary);
	
	if(arch){
		basico();
		cout <<"\n\t\tCambios en medicamentos "<<endl;
		cout <<"\n";
		cout<<"\n\t Dame el ID: ";
		cin>>id;
		cout <<"\n";
		arch.seekg((id-1)*sizeof(med),ios::beg);//instrucion que busca 
		arch.read((char *)&med, sizeof(med));
		menucammed(med);
		
		arch.seekg((id-1)*sizeof(med),ios::beg);
		arch.write((char*)&med, sizeof(med));
		basico();
		cout<<"Cambios realizado con exito"<<endl;
			
	}
	else
		cout<<"Error en el archivo";
	arch.close();
}

void menucammed(medicamentos &med){
	int op;
	string op2, enter;
		
	do{
		basico();
		cout <<"\n\t\t¿Qué deseas cambiar? "<<endl;
		cout <<"\n";
		cout <<"\t1)          Nombre"<<endl;
		cout <<"\t2) Nombre generico"<<endl;
		cout <<"\t3) Precio de venta"<<endl;
		cout <<"\t4) Precio de costo"<<endl;
		cout <<"\t5)      Existencia"<<endl;
		cout <<"\t6)  	       Salir"<<endl;
		cout <<"Introduce el numero de la opcion deseada: ";
		cin >> op;
		switch(op){
			case 1:
				basico();
				getline(cin,enter);
				cout <<"\tNombre : ";	
				cin.getline(med.nom,22); 
				break;
			case 2:
				basico();
				getline(cin,enter);
				cout <<"\tNombre generico : "; 
				cin.getline(med.gen,40);
				break;	
			case 3:
				basico();
				getline(cin,enter);
				cout <<"\tPrecio de venta : "; 
				cin >>med.preventa;
				break;
				break;
			case 4:
				basico();
				getline(cin,enter);
				cout <<"\tCosto : "; 
				cin >>med.precosto;
			case 5:
				basico();
				getline(cin,enter);
				cout <<"\tExistencia : "; 
				cin >>med.existencia;
				break;		
			case 6:
		
				break;			
			default :cout <<"Opcion incorrecta";	
		}
	
		basico();
		cout<<"\tCambios completos? s/n ";
		cin>>op2;
	}while(op2!="s");
	system("pause");
	
}





