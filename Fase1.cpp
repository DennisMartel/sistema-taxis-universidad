#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<conio.h>
#include<stdio.h>
#include "Textable.h"
#include <fstream>
#include <cstdlib>
#include <clocale>

using namespace std;

void Correlativo(int &Cor);
void LimpiarVectoresInt(vector<int> &LimpioInt);
void LimpiarVectores(vector<string> &Limpio);
void LimpiarVectoresFloat(vector<float> &LimpioFloat);
void CrearVectorConTodosLosDatos(vector<string>&VectorCTLD);
void CrearVectorConTodosLosDatosDeViajes(vector<string>&VectorCTLDDV);
void RecargarDatosString(vector<string> &DatoString,vector<string> VCTLD, int Num);
void RecargarDatosInt(vector<int> &DatoInt, vector<string>VCTLD , int Num);
void RecargarDatosIntDeViaje(vector<int> &DatoInt, vector<string>VCTLDDV , int Num);
void RecargarDatosFloatDeViaje(vector<float> &DatoInt, vector<string>VCTLDDV , int Num);
void RecargarDatosStringDeViaje(vector<string> &DatoString, vector<string>VCTLDDV , int Num);
bool VerificarItem(vector<int> Arreglo, int Info);
bool VerificarItem(vector<string> Arreglo, string Info);
void printTable(vector<int> Taxis, vector<string> Conductores, vector<string> ConductoresA, 
		vector<string> ConductoresD, vector<string> ConductoresSS, vector<string> ConductoresT, 
		vector<string> Motor, vector<string> Modelo, vector<int> Year, vector<string> Categoria, vector<string> Placas);				
void CargarDatosEjecutivosLibre(vector<string>&EJS); 
void CargarDatosEjecutivosEnUso(vector<string>&EEU);	
void CargarDatosTradicionalesLibre(vector<string>&TLS);
void CargarDatosTradicionalesEnUso(vector<string>&TEU);
void RecargarDatosEnUsoYDisponibles(vector<int> &CargarDato, vector<string>&VS ); 


int main() {
	setlocale(LC_CTYPE,"Spanish");
	system("color 06 ");
	ofstream Cars_Storage;
	Cars_Storage.open("Cars_Storage.txt", ios::app); 
	ofstream TRANSACTION_LOG;
	TRANSACTION_LOG.open("TRANSACTION_LOG.txt", ios::app); 
	
	ofstream Ejecutivos_Disponibles;
	Ejecutivos_Disponibles.open("Ejecutivos_Disponibles.txt", ios::app); 
	ofstream Ejecutivos_En_Uso;
	Ejecutivos_En_Uso.open("Ejecutivos_En_Uso.txt", ios::app); 
	ofstream Tradicionales_Disponibles;
	Tradicionales_Disponibles.open("Tradicionales_Disponibles.txt", ios::app); 
	ofstream Tradicionales_En_Uso;
	Tradicionales_En_Uso.open("Tradicionales_En_Uso.txt", ios::app); 
	
	/////////////variables//////////
	char response = '\0';
	int option;
	int Cor;
	int id;
	char confirmacion;
	int IdAReinsertar;
	string NombreC;
	string ApellidoC;
	string DUIC;
	string SSocialC;
	string TelC;
	string MotorN;
	string ModeloC;
	string CatE;
	int YearC;
	string CategoriaC;
	string PlacasN;
	////Correlativo///////
	vector<int> Corre;
	cout << "Sistema De Taxis\t\n";
		
	/////////////vectores////////////
	vector<string> VectorCTLD;
	vector<int> Taxis;
	vector<string> Conductores;
	vector<string> ConductoresA;
	vector<string> ConductoresD;
	vector<string> ConductoresSS;
	vector<string> ConductoresT;
	vector<string> Placas;
	vector<string> Motor;
	vector<string> Modelo;
	vector<int> Year;
	vector<string> Categoria;
	
	//las Colas de las categorias
	vector<int> Ejecutivo;
	vector<string> EJS;
	vector<int> EjecutivoLibre;
	vector<string> EEU;
	vector<int> EjecutivoEnUso;
	
	vector<int> Tradicional;
	vector<string> TLS;
	vector<int> TradicionalLibre;
	vector<string> TEU;
	vector<int> TradicionalEnUso;
	
	//////Datos del viaje/////
	string Salida;
	string Destino;
	float Costo;
	vector<string> VSalida;
	vector<string> VDestino;
	vector<float> VCosto;
	vector<int>IDViajes;
	vector<string>DViajes;


	
	do {
		system("cls");
		//Limpiar datos de los vectores 
		LimpiarVectores(VectorCTLD);
		LimpiarVectores(DViajes);
		LimpiarVectoresInt(Taxis);
		LimpiarVectores(Conductores);
		LimpiarVectores(ConductoresA);
		LimpiarVectores(ConductoresD);
		LimpiarVectores(ConductoresSS);
		LimpiarVectores(ConductoresT);
		LimpiarVectores(Placas);
		LimpiarVectores(Motor);
		LimpiarVectores(Modelo);
		LimpiarVectoresInt(Year);
		LimpiarVectores(Categoria);
		
		LimpiarVectores(EJS);
		LimpiarVectoresInt(EjecutivoLibre);
		LimpiarVectores(EEU);
		LimpiarVectoresInt(EjecutivoEnUso);
		LimpiarVectores(TLS);
		LimpiarVectoresInt(TradicionalLibre);
		LimpiarVectores(TEU);
		LimpiarVectoresInt(TradicionalEnUso);	
				
		LimpiarVectores(DViajes);
		LimpiarVectoresInt(IDViajes);
		LimpiarVectores(VSalida);
		LimpiarVectores(VDestino);
		LimpiarVectoresFloat(VCosto);
		
		//Recargar los datos que ya están almacenados en Cars_Storage.txt y TRANSACTION_LOG
		CrearVectorConTodosLosDatos(VectorCTLD);
		CrearVectorConTodosLosDatosDeViajes(DViajes);
		RecargarDatosInt(Taxis, VectorCTLD, 0);
		RecargarDatosString(Conductores,VectorCTLD, 1);
		RecargarDatosString(ConductoresA,VectorCTLD, 2);
		RecargarDatosString(ConductoresD,VectorCTLD, 3);
		RecargarDatosString(ConductoresSS,VectorCTLD, 4);
		RecargarDatosString(ConductoresT,VectorCTLD, 5);
		RecargarDatosString(Placas,VectorCTLD, 6);
		RecargarDatosString(Motor,VectorCTLD, 7);
		RecargarDatosString(Modelo,VectorCTLD, 8);
		RecargarDatosInt(Year, VectorCTLD, 9);
		RecargarDatosString(Categoria,VectorCTLD, 10);
		RecargarDatosIntDeViaje(IDViajes, DViajes , 0);
		RecargarDatosFloatDeViaje(VCosto, DViajes , 3);	
		RecargarDatosStringDeViaje(VSalida, DViajes , 1);
		RecargarDatosStringDeViaje(VDestino, DViajes , 2);
		
		//Recargar los datos que ya están almacenados sobre los carros disponibles y en uso
	CargarDatosEjecutivosLibre(EJS);
	RecargarDatosEnUsoYDisponibles(EjecutivoLibre, EJS); 
	CargarDatosEjecutivosEnUso(EEU);
	RecargarDatosEnUsoYDisponibles(EjecutivoEnUso, EEU); 
	CargarDatosTradicionalesLibre(TLS);
	RecargarDatosEnUsoYDisponibles(TradicionalLibre, TLS); 
	CargarDatosTradicionalesEnUso(TEU);
	RecargarDatosEnUsoYDisponibles(TradicionalEnUso, TEU); 


		cout << "Opciones del Menu:\n\n" << endl;
		cout << "\t\t1. Agregar Nuevo Taxi A La Cola de Espera" << endl;
		cout << "\t\t2. Verificar Los Datos Actuales" << endl;
		cout << "\t\t3. Enviar Un Taxi Al Cliente" << endl;
		cout << "\t\t4. Consultar Los Taxis Que Estan En Ruta" << endl;
		cout << "\t\t5. Insertar Taxi Como Disponible" << endl;
		cout << "\t\t6. Reporte de Conductores" << endl << endl;
		cout << "\t\t7. Salir del Programa" << endl << endl;
		cout << "Por Favor, Seleccione Su Opcion: ";
		cin >> option;
		switch (option) {
		case 1:
		
				Cor=Taxis.size();
			Correlativo(Cor);
			Taxis.push_back(Cor);
			id=Cor;

				cout << "Nombre del Conductor: ";
				cin.ignore();
				getline(cin, NombreC);
			
				cout << "Apellido del Conductor: ";
				getline(cin, ApellidoC);
				
				cout << "DUI Del Conductor: ";
				getline(cin, DUIC);
			
				cout << "# ISSS Del Conductor: ";
				getline(cin, SSocialC);
			
				cout << "Telefono Del Conductor: ";
				getline(cin, TelC);
			
				cout << "Placa: ";
				getline(cin, PlacasN);
			
				cout << "# Motor: ";
				getline(cin, MotorN);
		
				cout << "Modelo: ";
				getline(cin, ModeloC);
		
				cout << "Año: ";
				cin >> YearC;
	            	
				////////////////////////condicionales de años////////////7
					if(YearC> 2014){
					CatE = "Ejecutiva";
					//cout<<"\nCarro asignado a categoria ejecutiva \n";					
					EjecutivoLibre.push_back(id);
					
				//////////////////////meter el valor en 0//////////////////////////////
	
						if (Ejecutivos_Disponibles.is_open())
						{
						Ejecutivos_Disponibles.close();	
						Ejecutivos_Disponibles.open("Ejecutivos_Disponibles.txt"); 
						Ejecutivos_Disponibles<<EjecutivoLibre.at(0)<< "\n";
					 	Ejecutivos_Disponibles.close();	
						}
						
						else{
						Ejecutivos_Disponibles.open("Ejecutivos_Disponibles.txt"); 
						Ejecutivos_Disponibles<<EjecutivoLibre.at(0)<< "\n";
					 	Ejecutivos_Disponibles.close();	
				}
					 
				////////////////meter todos los demas valores del vector//////////////				 

					Ejecutivos_Disponibles.open("Ejecutivos_Disponibles.txt", ios::app); 
					 for(int i=1; i <EjecutivoLibre.size(); i++ ){
  					Ejecutivos_Disponibles <<EjecutivoLibre.at(i)<< "\n";
  					}
					  Ejecutivos_Disponibles.close();		
					
					
						if (Cars_Storage.is_open())
		{				
			Cars_Storage <<id<<endl<<NombreC<<endl<<ApellidoC<<endl<<DUIC<<endl<<SSocialC<<endl<<TelC<<endl
					<<PlacasN<<endl<<MotorN<<endl<<ModeloC<<endl<<YearC<<endl<<CatE<<endl<<endl;
		  Cars_Storage.close();
			cout<<"\nCarro asignado a categoria ejecutiva \n";		  
		}
			
			else {
				Cars_Storage.open("Cars_Storage.txt", ios::app); 
			Cars_Storage <<id<<endl<<NombreC<<endl<<ApellidoC<<endl<<DUIC<<endl<<SSocialC<<endl<<TelC<<endl
					<<PlacasN<<endl<<MotorN<<endl<<ModeloC<<endl<<YearC<<endl<<CatE<<endl<<endl;
		  Cars_Storage.close();
			cout<<"\nCarro asignado a categoria ejecutiva \n";			
		}
			
				}	
									
				else if((YearC> 2009)&&(YearC<2015)){
					CatE = "Tradicional";	
					TradicionalLibre.push_back(id);
					
				//////////////////////meter el valor en 0//////////////////////////////
	
						
						if (Tradicionales_Disponibles.is_open())
						{
						Tradicionales_Disponibles.close();	
						Tradicionales_Disponibles.open("Tradicionales_Disponibles.txt"); 
						Tradicionales_Disponibles<<TradicionalLibre.at(0)<< "\n";
					 	Tradicionales_Disponibles.close();	
						}
						
						else{
						Tradicionales_Disponibles.open("Tradicionales_Disponibles.txt"); 
						Tradicionales_Disponibles<<TradicionalLibre.at(0)<< "\n";
					 	Tradicionales_Disponibles.close();	
				}
					 
				////////////////meter todos los demas valores del vector//////////////				 

					Tradicionales_Disponibles.open("Tradicionales_Disponibles.txt", ios::app); 
					 for(int i=1; i <TradicionalLibre.size(); i++ ){
  					Tradicionales_Disponibles <<TradicionalLibre.at(i)<< "\n";
  					}
					  Tradicionales_Disponibles.close();		
					
					
						if (Cars_Storage.is_open())
		{				
			Cars_Storage <<id<<endl<<NombreC<<endl<<ApellidoC<<endl<<DUIC<<endl<<SSocialC<<endl<<TelC<<endl
					<<PlacasN<<endl<<MotorN<<endl<<ModeloC<<endl<<YearC<<endl<<CatE<<endl<<endl;
		  Cars_Storage.close();
			cout<<"\nCarro asignado a categoria tradicional \n";		  
		}
			
			else {
				Cars_Storage.open("Cars_Storage.txt", ios::app); 
			Cars_Storage <<id<<endl<<NombreC<<endl<<ApellidoC<<endl<<DUIC<<endl<<SSocialC<<endl<<TelC<<endl
					<<PlacasN<<endl<<MotorN<<endl<<ModeloC<<endl<<YearC<<endl<<CatE<<endl<<endl;
		  Cars_Storage.close();
			cout<<"\nCarro asignado a categoria tradicional \n";			
		}
			
				}
				else{
				cout<<"\nEste carro es de un año no permitido \n\n";
				system ("pause");
            	system("cls");
				main();
				}
				
				cin.ignore();
				getline(cin, CategoriaC);
			break;	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
		case 2:
			printTable(Taxis, Conductores, ConductoresA, ConductoresD, ConductoresSS, ConductoresT, 
			Motor, Modelo, Year, Categoria, Placas);
			break;		

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
		case 3:
{
			
					system("cls");
		cout<<"enviar un:"<<endl;
		cout<<"1. Ejecutivo"<<endl;
		cout<<"2. Tradicional"<<endl;
				
				cin>>option;
		switch(option){
			case 1:
					system("cls");
		
				
		if (EjecutivoLibre.size() >0){
		
				cout<<"Ingrese datos acerca del viaje"<<endl;
				
				cout<<"Ingrese punto de salida: ";
				cin>>Salida;

				cout<<"Ingrese destino: ";
				cin>>Destino;
	
				cout<<"Ingrese el costo del viaje  : $";
				cin>>Costo;
				cout<<"\n\n";
			
				{		
					int Di= EjecutivoLibre.at(0)-1;
		
		cout<<"El vehiculo asignado es el siguiente: \n\n";		
		cout<<"\n| ID: "<<Taxis.at(Di)<<"\t| Placa: "<<Placas.at(Di)<<"\t| Modelo: "<<Modelo.at(Di)<<"\t|Año: "<<Year.at(Di)<<"\t|\n";
	}
			
				if (TRANSACTION_LOG.is_open())
		{ TRANSACTION_LOG.close();
			TRANSACTION_LOG.open("TRANSACTION_LOG.txt", ios::app); 
			TRANSACTION_LOG <<EjecutivoLibre.at(0)<<endl<<Salida<<endl<<Destino<<endl<<Costo<<endl<<endl;
		  TRANSACTION_LOG.close();	  
		}
			
			else {
			TRANSACTION_LOG.open("TRANSACTION_LOG.txt", ios::app); 
			TRANSACTION_LOG <<EjecutivoLibre.at(0)<<endl<<Salida<<endl<<Destino<<endl<<Costo<<endl<<endl;
		  TRANSACTION_LOG.close();
		}
				
			EjecutivoEnUso.push_back(EjecutivoLibre.at(0));
			EjecutivoLibre.erase(EjecutivoLibre.begin());
					
			//////////////////////Actualizar base de datos de Ejecutivos Disponibles///////////////////////
			//////////////////////meter el valor en 0//////////////////////////////
	
						if (Ejecutivos_Disponibles.is_open())
						{
						Ejecutivos_Disponibles.close();	
						Ejecutivos_Disponibles.open("Ejecutivos_Disponibles.txt"); 
						Ejecutivos_Disponibles<<EjecutivoLibre.at(0)<< "\n";
					 	Ejecutivos_Disponibles.close();	
						}
						
						else{
						Ejecutivos_Disponibles.open("Ejecutivos_Disponibles.txt"); 
						Ejecutivos_Disponibles<<EjecutivoLibre.at(0)<< "\n";
					 	Ejecutivos_Disponibles.close();	
				}
					 
			////////////////meter todos los demas valores del vector//////////////				 

					Ejecutivos_Disponibles.open("Ejecutivos_Disponibles.txt", ios::app); 
					 for(int i=1; i <EjecutivoLibre.size(); i++ ){
  					Ejecutivos_Disponibles <<EjecutivoLibre.at(i)<< "\n";
  					}
					  Ejecutivos_Disponibles.close();
					  
					  
			//////////////////Actualizar base de datos de ejecutivos en uso/////////////////////
			//////////////////////meter el valor en 0//////////////////////////////
	
						if (Ejecutivos_En_Uso.is_open())
						{
						Ejecutivos_En_Uso.close();	
						Ejecutivos_En_Uso.open("Ejecutivos_En_Uso.txt"); 
						Ejecutivos_En_Uso<<EjecutivoEnUso.at(0)<< "\n";
					 	Ejecutivos_En_Uso.close();	
						}
						
						else{
						Ejecutivos_En_Uso.open("Ejecutivos_En_Uso.txt"); 
						Ejecutivos_En_Uso<<EjecutivoEnUso.at(0)<< "\n";
					 	Ejecutivos_En_Uso.close();	
				}
					 
			////////////////meter todos los demas valores del vector//////////////				 

					Ejecutivos_En_Uso.open("Ejecutivos_En_Uso.txt", ios::app); 
					 for(int i=1; i <EjecutivoEnUso.size(); i++ ){
  					Ejecutivos_En_Uso <<EjecutivoEnUso.at(i)<< "\n";
  					}
					  Ejecutivos_En_Uso.close();
					
				}
						
				else { 
				cout<<"No hay taxis ejecutivos disponibles \n\n";
				}
	
				break;
				
				
				
				
			case 2:
							system("cls");
		
				
		if (TradicionalLibre.size() >0){
		
					cout<<"\nIngrese datos acerca del viaje \n\n"<<endl;
				
				cout<<"Ingrese punto de salida: ";
				cin>>Salida;
		
				cout<<"Ingrese destino: ";
				cin>>Destino;

				cout<<"Ingrese el costo del viaje: $";
				cin>>Costo;
				cout<<" \n\n";
				{		
					int Di= TradicionalLibre.at(0)-1;
		
		cout<<"El vehiculo asignado es el siguiente: \n\n";		
		cout<<"\n| ID: "<<Taxis.at(Di)<<"\t| Placa: "<<Placas.at(Di)<<"\t| Modelo: "<<Modelo.at(Di)<<"\t|Año: "<<Year.at(Di)<<"\t|\n";
	}
				
					if (TRANSACTION_LOG.is_open())
		{ TRANSACTION_LOG.close();
			TRANSACTION_LOG.open("TRANSACTION_LOG.txt", ios::app); 
			TRANSACTION_LOG <<TradicionalLibre.at(0)<<endl<<Salida<<endl<<Destino<<endl<<Costo<<endl<<endl;
		  TRANSACTION_LOG.close();	  
		}
			
			else {
			TRANSACTION_LOG.open("TRANSACTION_LOG.txt", ios::app); 
			TRANSACTION_LOG <<TradicionalLibre.at(0)<<endl<<Salida<<endl<<Destino<<endl<<Costo<<endl<<endl;
		  TRANSACTION_LOG.close();
		}			
				
		TradicionalEnUso.push_back(TradicionalLibre.at(0));
		TradicionalLibre.erase(TradicionalLibre.begin());
					
					
			//////////////////////meter el valor en 0//////////////////////////////
			//////////////////////meter el valor en 0//////////////////////////////
	
						
						if (Tradicionales_Disponibles.is_open())
						{
						Tradicionales_Disponibles.close();	
						Tradicionales_Disponibles.open("Tradicionales_Disponibles.txt"); 
						Tradicionales_Disponibles<<TradicionalLibre.at(0)<< "\n";
					 	Tradicionales_Disponibles.close();	
						}
						
						else{
						Tradicionales_Disponibles.open("Tradicionales_Disponibles.txt"); 
						Tradicionales_Disponibles<<TradicionalLibre.at(0)<< "\n";
					 	Tradicionales_Disponibles.close();	
				}
					 
			////////////////meter todos los demas valores del vector//////////////				 

					Tradicionales_Disponibles.open("Tradicionales_Disponibles.txt", ios::app); 
					 for(int i=1; i <TradicionalLibre.size(); i++ ){
  					Tradicionales_Disponibles <<TradicionalLibre.at(i)<< "\n";
  					}
					  Tradicionales_Disponibles.close();		
					
					
					
			////////////////////////Actualizar base de datos de Tradicionales en uso		
			//////////////////////meter el valor en 0//////////////////////////////
	
			//////////////////////meter el valor en 0//////////////////////////////
	
						
						if (Tradicionales_En_Uso.is_open())
						{
						Tradicionales_En_Uso.close();	
						Tradicionales_En_Uso.open("Tradicionales_En_Uso.txt"); 
						Tradicionales_En_Uso<<TradicionalEnUso.at(0)<< "\n";
					 	Tradicionales_En_Uso.close();	
						}
						
						else{
						Tradicionales_En_Uso.open("Tradicionales_En_Uso.txt"); 
						Tradicionales_En_Uso<<TradicionalEnUso.at(0)<< "\n";
					 	Tradicionales_En_Uso.close();	
				}
					 
			////////////////meter todos los demas valores del vector//////////////				 

					Tradicionales_En_Uso.open("Tradicionales_En_Uso.txt", ios::app); 
					 for(int i=1; i <TradicionalEnUso.size(); i++ ){
  					Tradicionales_En_Uso <<TradicionalEnUso.at(i)<< "\n";
  					}
					  Tradicionales_En_Uso.close();		
										
				}
												
				else { 
				cout<<"No hay taxis tradicionales disponibles \n\n";
				}	
			break;
				default:
				cout<<"La opcion seleccionada no es correcta. \n\n"<<endl;
					break;
				}
				break;	
}
			break;
			
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 4:
			cout << "Taxis En Ruta:" << endl;
	
		
		system("cls");
		cout<<"\nEscoja la categoria de la cual desea ver la cola de ruta:"<<endl;
		cout<<"1. Ejecutivo"<<endl;
		cout<<"2. Tradicional"<<endl;
				
				cin>>option;
		switch(option){
			case 1:
					system("cls");
					
					if (EjecutivoEnUso.size()>0){
					
			cout<<"Cola de taxis ejecutivos en ruta \n\n"<<endl;
				
				cout<<"|ID\t|Placa\t|Modelo\t|Anio|\n";	
				for(int i=0; i<EjecutivoEnUso.size();i++)
				{
					
					int Di= EjecutivoEnUso.at(i)-1;
				
				for(int au=0; au<Taxis.size();au++)
				{
						if(EjecutivoEnUso.at(i) == Taxis.at(au)){
		cout<<"|"<<Taxis.at(Di)<<"\t|"<<Placas.at(Di)<<"\t|"<<Modelo.at(Di)<<"\t|"
					<<Year.at(Di)<<"\t|\n";
		}
				
				}
					
						}
		}
		
		else{
				cout<<"No hay taxis ejecutivos en ruta \n\n";
		}
			
			
				break;
			case 2:
	
	
					system("cls");
					
					if(TradicionalEnUso.size()>0){
					
					
			cout<<"Cola de taxis tradicionales en ruta \n\n"<<endl;
				
				cout<<"|ID\t|Placa\t|Modelo\t|Año|\n";	
				for(int i=0; i<TradicionalEnUso.size();i++)
				{
					
					int Di= TradicionalEnUso.at(i)-1;
				
				for(int au=0; au<Taxis.size();au++)
				{
						if(TradicionalEnUso.at(i) == Taxis.at(au)){
		cout<<"|"<<Taxis.at(Di)<<"\t|"<<Placas.at(Di)<<"\t|"<<Modelo.at(Di)<<"\t|"
					<<Year.at(Di)<<"\t|\n";
		}
				
				}
					
						}
					}
				else {	
				cout<<"No hay taxis tradicionales en ruta \n\n";
				}
						
	
			
		
			break;
				default:
				cout<<"\n\nLa opción seleccionada no es valida."<<endl;
				
				
			break;
		}
			break;
			
		
			
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
		case 5:
			
			
		cout << "Reinsertar Taxis :" << endl;
	
		
		system("cls");
		cout<<"\nEscoja la categoria de la cual desea ver la cola de ruta:"<<endl;
		cout<<"1. Ejecutivo"<<endl;
		cout<<"2. Tradicional"<<endl;
				
				cin>>option;
		switch(option){
			case 1:
					system("cls");
					
					if (EjecutivoEnUso.size()>0){
					
			cout<<"Cola de taxis ejecutivos en ruta \n\n"<<endl;
				
				cout<<"|ID\t|Placa\t|Modelo\t|Anio|\n";	
				for(int i=0; i<EjecutivoEnUso.size();i++)
				{
					
					int Di= EjecutivoEnUso.at(i)-1;
				
				for(int au=0; au<Taxis.size();au++)
				{
						if(EjecutivoEnUso.at(i) == Taxis.at(au)){
		cout<<"|"<<Taxis.at(Di)<<"\t|"<<Placas.at(Di)<<"\t|"<<Modelo.at(Di)<<"\t|"
					<<Year.at(Di)<<"\t|\n";
		}
				
				}
					
						}
						
						
							{
				int reinsertar;
			int encontrado = -1;
		
			cout<<"\n\ningrese el id del vehiculo que desea reinsertar a la cola de disponibles: ";
			cin>>reinsertar;
			
for (int i = 0; i <EjecutivoEnUso.size() ; i++) {

  if (EjecutivoEnUso.at(i) == reinsertar ) {
    encontrado=  i;
    break;
  } 
}
if (encontrado == -1) {
  cout << "\nEl vehículo con id: " << reinsertar<<" actualmente no está en uso"<<"\n";
} else {
  	EjecutivoLibre.push_back(EjecutivoEnUso.at(encontrado));
	EjecutivoEnUso.erase(EjecutivoEnUso.begin()+ encontrado);

	//////////////////////Actualizar base de datos de Ejecutivos Disponibles///////////////////////
			//////////////////////meter el valor en 0//////////////////////////////
	
						if (Ejecutivos_Disponibles.is_open())
						{
						Ejecutivos_Disponibles.close();	
						Ejecutivos_Disponibles.open("Ejecutivos_Disponibles.txt"); 
						Ejecutivos_Disponibles<<EjecutivoLibre.at(0)<< "\n";
					 	Ejecutivos_Disponibles.close();	
						}
						
						else{
						Ejecutivos_Disponibles.open("Ejecutivos_Disponibles.txt"); 
						Ejecutivos_Disponibles<<EjecutivoLibre.at(0)<< "\n";
					 	Ejecutivos_Disponibles.close();	
				}
					 
			////////////////meter todos los demas valores del vector//////////////				 

					Ejecutivos_Disponibles.open("Ejecutivos_Disponibles.txt", ios::app); 
					 for(int i=1; i <EjecutivoLibre.size(); i++ ){
  					Ejecutivos_Disponibles <<EjecutivoLibre.at(i)<< "\n";
  					}
					  Ejecutivos_Disponibles.close();
					  
					  
			//////////////////Actualizar base de datos de ejecutivos en uso/////////////////////
		//////////////////////meter el valor en 0//////////////////////////////
	
						if (Ejecutivos_En_Uso.is_open())
						{
						Ejecutivos_En_Uso.close();	
						Ejecutivos_En_Uso.open("Ejecutivos_En_Uso.txt"); 
						Ejecutivos_En_Uso<<EjecutivoEnUso.at(0)<< "\n";
					 	Ejecutivos_En_Uso.close();	
						}
						
						else{
						Ejecutivos_En_Uso.open("Ejecutivos_En_Uso.txt"); 
						Ejecutivos_En_Uso<<EjecutivoEnUso.at(0)<< "\n";
					 	Ejecutivos_En_Uso.close();	
				}
					 
			////////////////meter todos los demas valores del vector//////////////				 

					Ejecutivos_En_Uso.open("Ejecutivos_En_Uso.txt", ios::app); 
					 for(int i=1; i <EjecutivoEnUso.size(); i++ ){
  					Ejecutivos_En_Uso <<EjecutivoEnUso.at(i)<< "\n";
  					}
					  Ejecutivos_En_Uso.close();

}


}
													
		}
		
		else{
				cout<<"No hay taxis ejecutivos en ruta \n\n";
		}
			
			
				break;
				
				
				
			case 2:
	
	
					system("cls");
					
					if(TradicionalEnUso.size()>0){
					
					
			cout<<"Cola de taxis tradicionales en ruta \n\n"<<endl;
				
				cout<<"|ID\t|Placa\t|Modelo\t|Año|\n";	
				for(int i=0; i<TradicionalEnUso.size();i++)
				{
					
					int Di= TradicionalEnUso.at(i)-1;
				
				for(int au=0; au<Taxis.size();au++)
				{
						if(TradicionalEnUso.at(i) == Taxis.at(au)){
		cout<<"|"<<Taxis.at(Di)<<"\t|"<<Placas.at(Di)<<"\t|"<<Modelo.at(Di)<<"\t|"
					<<Year.at(Di)<<"\t|\n";
		}
				
				}
					
						}
						
						
							{
				int reinsertar;
			int encontrado = -1;
		
			cout<<"ingrese el id del vehiculo que desea reinsertar a la cola de disponibles: ";
			cin>>reinsertar;
			
for (int i = 0; i <TradicionalEnUso.size() ; i++) {

  if (TradicionalEnUso.at(i) == reinsertar ) {
    encontrado=  i;
    break;
  } 
}
if (encontrado == -1) {
  cout << "\nEl vehículo con id: " << reinsertar<<" actualmente no está en uso"<<"\n";
} else {
	
		TradicionalLibre.push_back(TradicionalEnUso.at(encontrado));
	TradicionalEnUso.erase(TradicionalEnUso.begin()+ encontrado);

  			
			//////////////////////Actualizar base de datos de Tradicionales disponibles//////////////////////////////
			//////////////////////meter el valor en 0//////////////////////////////
	
						
						if (Tradicionales_Disponibles.is_open())
						{
						Tradicionales_Disponibles.close();	
						Tradicionales_Disponibles.open("Tradicionales_Disponibles.txt"); 
						Tradicionales_Disponibles<<TradicionalLibre.at(0)<< "\n";
					 	Tradicionales_Disponibles.close();	
						}
						
						else{
						Tradicionales_Disponibles.open("Tradicionales_Disponibles.txt"); 
						Tradicionales_Disponibles<<TradicionalLibre.at(0)<< "\n";
					 	Tradicionales_Disponibles.close();	
				}
					 
			////////////////meter todos los demas valores del vector//////////////				 

					Tradicionales_Disponibles.open("Tradicionales_Disponibles.txt", ios::app); 
					 for(int i=1; i <TradicionalLibre.size(); i++ ){
  					Tradicionales_Disponibles <<TradicionalLibre.at(i)<< "\n";
  					}
					  Tradicionales_Disponibles.close();		
					
					
					
			////////////////////////Actualizar base de datos de Tradicionales en uso		
			//////////////////////meter el valor en 0//////////////////////////////
	
					//////////////////////meter el valor en 0//////////////////////////////
	
						
						if (Tradicionales_En_Uso.is_open())
						{
						Tradicionales_En_Uso.close();	
						Tradicionales_En_Uso.open("TTradicionales_En_Uso.txt"); 
						Tradicionales_En_Uso<<TradicionalEnUso.at(0)<< "\n";
					 	Tradicionales_En_Uso.close();	
						}
						
						else{
						Tradicionales_En_Uso.open("Tradicionales_En_Uso.txt"); 
						Tradicionales_En_Uso<<TradicionalEnUso.at(0)<< "\n";
					 	Tradicionales_En_Uso.close();	
				}
					 
			////////////////meter todos los demas valores del vector//////////////				 

					Tradicionales_En_Uso.open("Tradicionales_En_Uso.txt", ios::app); 
					 for(int i=1; i <TradicionalEnUso.size(); i++ ){
  					Tradicionales_En_Uso <<TradicionalEnUso.at(i)<< "\n";
  					}
					  Tradicionales_En_Uso.close();		
}
}
		
						
					}
				else {	
				cout<<"No hay taxis tradicionales en ruta \n\n";
				}
						
	
			
		
			break;
				default:
				cout<<"\n\nLa opción seleccionada no es valida."<<endl;
				
				
			break;
		}
			break;
			
			
			
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
		case 6:
			
			
				system("cls");
		cout<<"\nEscoja una opción :"<<endl<<endl;
		cout<<"1. Lista de viajes por cada vehículo."<<endl;
		cout<<"2. Lista de viajes por un vehículo especiico."<<endl;
		cout<<"3. Ingresos totales obtenidos en un mes."<<endl;
		cout<<"4. Ingresos totales obtenidos en un mes por un vehículo específico."<<endl<<endl<<endl;
				
				cin>>option;
		switch(option){
			case 1:{
				system("cls");
			
			cout<<"\n\nLista de viajes por cada vehículo \n\n";	
		cout<<"|ID de taxi\t|Punto de salida\t|Punto de Destino \t|Costo del viaje|\n";	
				for(int i=0; i<IDViajes.size();i++)
				{
		cout<<"|"<<IDViajes.at(i)<<"\t|"<<VSalida.at(i)<<"\t|"<<VDestino.at(i)<<"\t|"
				<<"$:"<<VCosto.at(i)<<"\t|\n";
		}
			cout<<"\n\n";
		}
			break;
			
			
			case 2:

			{
			system("cls");
			int R;
			int encontrado = -1;
		
			cout<<"ingrese el id del vehiculo que desea generar reporte de viajes: ";
			cin>>R;
			cout<<"|ID de taxi\t|Punto de salida\t|Punto de Destino \t|Costo del viaje|\n";	
			for (int i = 0; i <IDViajes.size() ; i++) {
 			if (IDViajes.at(i) == R ) {
    			encontrado=  i;
    		cout<<"|"<<IDViajes.at(i)<<"\t|"<<VSalida.at(i)<<"\t|"<<VDestino.at(i)<<"\t|"
				<<"$:"<<VCosto.at(i)<<"\t|\n";

  				} 
			}
		}
			
			
			break;
			case 3:	
				{
				system("cls");
				float suma = 0;
  			  	for( int i = 0; i <VCosto.size(); i++ ) { 
        		suma += VCosto.at(i);
   			 }
				cout<<"\n\n"<<"Ingresos totales obtenidos: $"<<	suma<<"\n\n";
			
		cout<<"|ID de taxi\t|Punto de salida\t|Punto de Destino \t|Costo del viaje|\n";	
				for(int i=0; i<IDViajes.size();i++)
				{
		cout<<"|"<<IDViajes.at(i)<<"\t|"<<VSalida.at(i)<<"\t|"<<VDestino.at(i)<<"\t|"
				<<"$:"<<VCosto.at(i)<<"\t|\n";
		}	
		
		cout<<"\n\n";			
			}
			
			break;
			case 4:
				{
			system("cls");
			int R;
			int encontrado = -1;
			float suma = 0;
		
			cout<<"ingrese el id del vehiculo que desea generar el reporte de  ingresos obtenidos: ";
			cin>>R;
			
			
			for (int i = 0; i <IDViajes.size() ; i++) {
 			if (IDViajes.at(i) == R ) {
    			suma += VCosto.at(i);
    		}
    	}
			
			cout<<"\n\n"<<"Ingresos totales obtenidos por el vehículo "<<R<<" $:"<<	suma<<"\n\n";
			cout<<"|ID de taxi\t|Punto de salida\t|Punto de Destino \t|Costo del viaje|\n";	
			for (int i = 0; i <IDViajes.size() ; i++) {
 			if (IDViajes.at(i) == R ) {
    			encontrado=  i;
    		cout<<"|"<<IDViajes.at(i)<<"\t|"<<VSalida.at(i)<<"\t|"<<VDestino.at(i)<<"\t|"
				<<"$:"<<VCosto.at(i)<<"\t|\n";

  			} 
		}
		}
			break;
			
		}
			break;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 7:
			system("exit");
			break;
		default:
			cout << "No Ha Seleccionado Una Opcion Correcta." << endl;
			break;
		}
		cout << "Seguro de Continuar? (Y/N)?: ";
		response = getch();
	} while (response == 'Y' || response == 'y');
			Cars_Storage.close(); ////////////////////////////////////////////////////////////////////////////////////
}

bool VerificarItem(vector<int> Arreglo, int Info) {
	for (int i = 0; i < Arreglo.size(); i++)
	{
		if (Arreglo.at(i) == Info)
		{
			cout << "La Informacion Ya Esta Registrada En Esta Position [" << i << "].\nPor Favor Ingresela de Nuevo.\n";
			return true;
		}
		else
		{
			return false;
		}

	}
}

bool VerificarItem(vector<string> Arreglo, string Info) {
	for (int i = 0; i < Arreglo.size(); i++)
	{
		if (Arreglo.at(i) == Info)
		{
			cout << "La Informacion Ya Esta Registrada En Esta Position [" << i << "].\nPor Favor Ingresela de Nuevo.\n";
			return true;
		}
		else
		{
			return false;
		}

	}
}


void printTable(vector<int> Taxis, vector<string> Conductores, vector<string> ConductoresA, 
				vector<string> ConductoresD, vector<string> ConductoresSS, vector<string> ConductoresT, vector<string> 
				Motor, vector<string> Modelo, vector<int> Year, vector<string> Categoria, vector<string> Placas)
{
	TextTable t('-', '/', '-');
	t.add(" ID");
	t.add(" Nombre Del Conductor");
	t.add(" Apellido Del Conductor");
	t.add(" DUI      ");
	t.add(" ISSS Del Conductor");
	t.add(" Tel. Del Conductor");
	t.add(" No. De Motor");
	t.add(" Modelo");
	t.add(" Año ");
	t.add(" Categoria   ");
	t.add(" No. De Placa");
	t.endOfRow();
	for (int i = 0; i < Taxis.size(); i++)
	{
		t.add(to_string(Taxis.at(i)));
		t.add(Conductores.at(i));
		t.add(ConductoresA.at(i));
		t.add(ConductoresD.at(i));
		t.add(ConductoresSS.at(i));
		t.add(ConductoresT.at(i));
		t.add(Motor.at(i));
		t.add(Modelo.at(i));
		t.add(to_string(Year.at(i)));
		t.add(Categoria.at(i));
		t.add(Placas.at(i));
		t.endOfRow();
	}
	t.setAlignment(2, TextTable::Alignment::RIGHT);
	cout << t;
}

void CrearVectorConTodosLosDatos(vector<string>&VectorCTLD) {
    string line;
  ifstream Cars_Storage ("Cars_Storage.txt");
  if (Cars_Storage.is_open())
  {
    while ( getline (Cars_Storage,line) )
    {
      VectorCTLD.push_back(line);
    }
    Cars_Storage.close();
  }
  else cout << "Unable to open file"; 
}

void CrearVectorConTodosLosDatosDeViajes(vector<string>&VectorCTLDDV) {
    string line;
  ifstream TRANSACTION_LOG ("TRANSACTION_LOG.txt");
  if (TRANSACTION_LOG.is_open())
  {
    while ( getline (TRANSACTION_LOG,line) )
    {
      VectorCTLDDV.push_back(line);
    }
    TRANSACTION_LOG.close();
  }
  else cout << "Unable to open file"; 
}

void RecargarDatosIntDeViaje(vector<int> &DatoInt, vector<string>VCTLDDV , int Num) {
   for(int i = Num; i <VCTLDDV.size(); i = i +5)
{
	DatoInt.push_back(atoi(VCTLDDV.at(i).c_str()));
}
}
void RecargarDatosFloatDeViaje(vector<float> &DatoInt, vector<string>VCTLDDV , int Num) {
   for(int i = Num; i <VCTLDDV.size(); i = i +5)
{
	DatoInt.push_back(atof(VCTLDDV.at(i).c_str()));
}
}

void RecargarDatosStringDeViaje(vector<string> &DatoString, vector<string>VCTLDDV , int Num) {
   for(int i = Num; i <VCTLDDV.size(); i = i +5)
{
	DatoString.push_back(VCTLDDV.at(i));
}
}

void RecargarDatosInt(vector<int> &DatoInt, vector<string>VCTLD , int Num) {
   for(int i = Num; i <VCTLD.size(); i = i +12)
{
	DatoInt.push_back(atoi(VCTLD.at(i).c_str()));
}
}

void RecargarDatosString(vector<string> &DatoString, vector<string>VCTLD , int Num) {
   for(int i = Num; i <VCTLD.size(); i = i +12)
{
	DatoString.push_back(VCTLD.at(i));
}
}

void LimpiarVectores(vector<string> &Limpio) {
	Limpio.clear();
	Limpio.shrink_to_fit();
}

void LimpiarVectoresInt(vector<int> &LimpioInt) {
	LimpioInt.clear();
	LimpioInt.shrink_to_fit();
}
void LimpiarVectoresFloat(vector<float> &LimpioFloat) {
	LimpioFloat.clear();
	LimpioFloat.shrink_to_fit();
}

void CargarDatosEjecutivosLibre(vector<string>&EJS) {
 string idEL;
  ifstream Ejecutivos_Disponibles("Ejecutivos_Disponibles.txt");
  if (Ejecutivos_Disponibles.is_open())
  {
    while ( getline(Ejecutivos_Disponibles,idEL) )
    {
      EJS.push_back(idEL);
    }
  }
  else cout << "No se puede abrir el archivo Ejecutivo Libre"; 
}

void CargarDatosEjecutivosEnUso(vector<string>&EEU) {
 string idEEU;
  ifstream Ejecutivos_En_Uso ("Ejecutivos_En_Uso.txt");
  if (Ejecutivos_En_Uso.is_open())
  {
    while ( getline(Ejecutivos_En_Uso,idEEU) )
    {
      EEU.push_back(idEEU);
    }
    Ejecutivos_En_Uso.close();
  }
  else cout << "No se puede abrir el archivo Ejecutivo En Uso "; 
}

void CargarDatosTradicionalesLibre(vector<string>&TLS) {
 string idTL;
  ifstream Tradicionales_Disponibles ("Tradicionales_Disponibles.txt");
  if (Tradicionales_Disponibles.is_open())
  {
    while ( getline(Tradicionales_Disponibles,idTL) )
    {
      TLS.push_back(idTL);
    }
    
    Tradicionales_Disponibles.close();
  }
  else cout << "Unable to open file"; 
}

void CargarDatosTradicionalesEnUso(vector<string>&TEU) {
 string idTEU;
  ifstream Tradicionales_En_Uso ("Tradicionales_En_Uso.txt");
  if (Tradicionales_En_Uso.is_open())
  {
    while ( getline(Tradicionales_En_Uso,idTEU) )
    {
      TEU.push_back(idTEU);
    }
    Tradicionales_En_Uso.close();
  }
  else cout << "Unable to open file"; 
}

void RecargarDatosEnUsoYDisponibles(vector<int> &CargarDato, vector<string>&VS ){

 for(int i=0; i < VS.size(); i++)
    {
       CargarDato.push_back(atoi(VS.at(i).c_str()));
    }


}

void Correlativo(int &Cor){
	Cor+=1;
		cout<<"\nCorrelativo asignado al taxi (id): "<<Cor<<endl<<endl;
		
	
}

