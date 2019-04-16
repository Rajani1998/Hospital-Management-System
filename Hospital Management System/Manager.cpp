#include "Manager.h"

Manager::Manager()
{
		setTitle();
}

Manager::Manager(string N,string G,string Ad,string Ph,string Ag,string Pass):Person(N,G,Ad,Ph,Ag){
	 Password=Pass;
}

Manager::~Manager()
{
}

void Manager::setTitle(){
	Title = "Manager";
}

void Manager::resetPassword(string p){
	string p1;
	cout<<"Renter the password ";cin>>p1;
	while (p1 != p){
		cout<<"Enter the same password.\nEnter the password ";cin>>p;
		cout<<"Renter the password ";cin>>p1;
	}
	Password = p;
}

void Manager::setPassword(string p){
	Password = p;
}

string Manager::getPassword(){
	return Password;
}

void Manager::changePassword(){
	string p,p1,p2;
	cout<<"Enter the previous password ";cin>>p;
	while(Password != p){
		cout<<"Password mismatch.\nEnter the previous password ";cin>>p;
	}
	cout<<"Enter the new password ";cin>>p1;
	cout<<"Reneter the new password ";cin>>p2;
	while (p1 != p2){
		cout<<"Enter the same password.\nEnter the password ";cin>>p1;
		cout<<"Renter the password ";cin>>p2;
	}
	Password = p1;
}

template <typename T> void Manager::printBill(T t){
	cout<<t;
}

void Manager::printServices(){
	
	const int n=10;
	string Services[n]={"X-Ray","UltraSound","CT Scan","TC DC HB","Urine Test","Blood Test","Biliribin","Stool Test","Bed Charge","Sugar Test"};
	double Cost[n]={3,5,5,1.5,1.5,1.5,2,1.5,1.5,2};
	cout<<"\nAVAILABLE SERVICES";
	for(int i=0;i<n;i++) cout<<endl<<"Press "<<i+1<<" for "<<Services[i]<<" (Cost = $"<<Cost[i]<<")";
	
}

void Manager::awardService(){
	
	int ch;
	const int n=10;
	string Services[n]={"X-Ray","UltraSound","CT Scan","TC DC HB","Urine Test","Blood Test","Biliribin","Stool Test","Bed Charge","Sugar Test"};
	double Cost[n]={3,5,5,1.5,1.5,1.5,2,1.5,1.5,2};
	cout<<endl<<"Enter your choice "; cin>>ch;
	if(ch>=1&&ch<=n){
		ServicePatient S;
		cin>>S;
		S.setService(Services[ch-1]);
		S.setBill(Cost[ch-1]);
		printBill(S);
	}
	else cout<<"You entered invalid choice.";
}

void Manager::awardDoctor(){
	int choice;
	if(choice>=1&&choice<=26){
		
	}
}

void Manager::printListOfDoctors(){
	const int n=26;
	string DoctorsDept[n]={"General Physician","Diarrhea","Allergy","Depression","Acne","Diabetes","Head Ache","Arthritis","Asthma","Personality Disorder","Rickits","Autism",
	"Back Pain","Bad Breath","Alopecia","Bladder Cancer","Bone Cancer","Breast Cancer","Brain Tumor","Burn","High/Low Blood Pressure","Cholesterol","Heart Problem",
	"High/Low Uric Acid","Dehydration","Severe Flu/Cough"};
	double Cost[n]={10,12,11,12,14,15,17,15,20,25,18,12,8,15,30,25,35,45,10,7,8,25,15,10,10,15};
	string DoctorsName[n]={"James","Shawn","Paul","Andrew","Fadricks","Micheal","Chaplin","John","David","Anthony","Amam","Prakash","Bob","Martin","George","Ramesh","Farooq",
	"Laiba","Lubna","Robert","Harry","Kathrine","Peter","Jack","Mike","Saqib"};
	cout<<"\nAVAILABLE DISEASES (DOCTOR NAME) [COST]";
	for(int i=0;i<n;i++) cout<<endl<<"Press "<<i+1<<" for "<<DoctorsDept[i]<<" (Dr "<<DoctorsName[i]<<" ) [Cost = $"<<Cost[i]<<"]";
}

ostream& operator << (ostream& out,Manager & M){
	out<<"Manager Name = "<<M.getName();
	out<<"\nManager Gender = "<<M.getGender();
	out<<"\nManager Age = "<<M.getAge();
	out<<"\nManager Address = "<<M.getAddress();
	out<<"\nManager Phone Number = "<<M.getPhone();
	return out;
}

istream& operator >> (istream& in, Manager &M){
	string temp;int t;
	cout<<"Enter Manager Name ";in>>temp;M.setName(temp);
	cout<<"\nEnter Manager Password ";in>>temp;M.resetPassword(temp);
	cout<<"\nEnter Manager Age ";in>>t;M.setAge(t);
	cout<<"\nEnter Manager Address ";in>>temp;M.setAddress(temp);
	cout<<"\nEnter Manager Phone Number ";in>>temp;M.setPhone(temp);
	return in;
}
