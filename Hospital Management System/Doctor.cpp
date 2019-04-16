#include "Doctor.h"

Doctor::Doctor()
{
		setTitle();
}
Doctor::Doctor(string N,string G,string Ad,string Ph,int Ag,string SP,double Sal,double CFee,double SFee):Person(N,G,Ad,Ph,Ag){
	Specialization=SP;
	Salary=Sal;
	CheckUpFees=CFee;
	SurgeryFees=SFee;
}
void Doctor::setTitle(){
	Title = "Doctor";
}

void Doctor::setSpecialization(string s){
	Specialization = s;
}

string Doctor::getSpecialization(){
	return Specialization;
}

void Doctor::setSalary(double s){
	Salary = s;
}

double Doctor::getSalary(){
	return Salary;
}

void Doctor::setCheckUpFees(double c){
	CheckUpFees = c;
}

double Doctor::getCheckUpFees(){
	return CheckUpFees;
}

void Doctor::setSurgeryFees(double s){
	SurgeryFees = s;
}

double Doctor::getSurgeryFees(){
	return SurgeryFees;
}

Doctor::~Doctor()
{
}
