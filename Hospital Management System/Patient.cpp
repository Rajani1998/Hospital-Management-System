#include "Patient.h"

Patient::Patient()
{
	Bill = 0;
}
Patient::Patient(string N,string G,string Ad,string Ph,int Ag,double B):Person(N,G,Ad,Ph,Ag){
	Bill=B;
}
void Patient::setBill(double b){
	Bill = b;
}

double Patient::getBill(){
	return Bill;
}

void Patient::setBloodGroup(string bg){
	int n=8;
	string B[n]={"A+","A-","AB+","AB-","B+","B-","O+","O-"};
	for(int i=0;i<n;i++){
		if(B[i]==bg){
			BloodGroup = B[i];
			return;
		}
	}
	BloodGroup = "--";
}

string Patient::getBloodGroup(){
	return BloodGroup;
}

Patient::~Patient()
{
}
