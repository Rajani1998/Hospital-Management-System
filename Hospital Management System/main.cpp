#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<vector>
#include "Manager.h"
#include<string>
#include<cstring>
#include<fstream>
#include<algorithm>
//#include "AdmitPatient.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

void AssignManager(vector<Manager>&);
void AssignCheckUpPatient(vector<CheckUpPatient>&);

int main(int argc, char** argv) {
	
	system("COLOR 70");
	vector<Manager> Man;
	
	int ch1=0,ch2=0;
	r:
	system("cls");
	system("COLOR 70");
	cout<<"\t\t\t\t\t\t================\n";
	cout<<"\t\t\t\t\t\t||ABC HOSPITAL||\n";
	cout<<"\t\t\t\t\t\t================\n";
	cout<<endl<<endl;
	
	AssignManager(Man);
			
	cout<<"Press 1 for Manager\nPress 2 for Patient\nPress 3 for Doctor\nPress 4 for Exit\nEnter your choice ";
	cin>>ch1;
	while (!(ch1>0&&ch1<5)){
		cout<<endl<<"You enter invalid choice.";
		cout<<"\nPress 1 for Manager\nPress 2 for Patient\nPress 3 for Doctor\nPress 4 for Exit\nEnter your choice ";
		cin>>ch1;
	}
	if(ch1==1){
		system("cls");
		string man_name,man_pass;
		x:
		Manager temp;	
		cout<<"\nEnter Name of Manager ";
		cin>>man_name;
		int flag=-1,ch2,i=0;
		for (std::vector<Manager>::iterator it = Man.begin() ; it != Man.end(); ++it){
			cout<<Man[i++];
			if (Man[i++].getName()==man_name) {
				flag = i;
				cout<<"found";
				break;	
			}
		}
		if(flag == -1){
			int ch_t;
			cout<<"\nManager not found.";
			cout<<"\nPress 1 to continue\nPress 2 for BackMenu\nEnter your choice ";
			cin>>ch_t;
			while(!(ch_t>0&&ch_t<3)){
				cout<<"You entered invalid choice.";
				cout<<"\nPress 1 to continue\nPress 2 for BackMenu\nEnter your choice ";
				cin>>ch_t;
			}
			if(ch_t==2) goto r;
			cout<<"\nPress any key to continue ";
			getch();
			goto x;
		}
		cout<<"\nEnter Password of Manager ";
		cin>>man_pass;
		if(Man[flag].getPassword()!=man_pass){
			cout<<"\nYou entered incorrect Password.";
			cout<<endl<<"Press any key to continue ";
			getch();
			goto x;
		}
		y:
		system("cls");
		cout<<"\nPress 1 for Add Patient\nPress 2 for View List of Patients\nPress 3 for Another Manager Login\nPress 4 Add New Manager\nPress 5 Remove Manager\nPress 6 View All Managers\nPress 7 for Back Menu\nEnter your Choice ";
		cin>>ch2;
		while(!(ch2>0&&ch2<8)){
			cout<<"\nYou enter invalid choice.";
			cout<<"\nPress 1 for Add Patient\nPress 2 for View List of Patients\nPress 3 for Another Manager Login\nPress 4 Add New Manager\nPress 5 Remove Manager\nPress 6 View All Managers\nPress 7 for Back Menu\nEnter your Choice ";
			cin>>ch2;
		}
		
		if(ch2==1){
			m:
				system("cls");
				Patient *P;
			int ch3;
			cout<<"\nPress 1 for Checkup Patient\nPress 2 for Emergeny Patient\nPress 3 for Admit Patient\nPress 4 for Service Patient\nPress 5 for Back Menu\nEnter your choice ";
			cin>>ch3;
			while(!(ch3>0&&ch3<6)){
				cout<<"\nYou entered invalid choice.";
				cout<<"\nPress 1 for Checkup Patient\nPress 2 for Emergeny Patient\nPress 3 for Admit Patient\nPress 4 for Service Patient\nPress 5 for Back Menu\nEnter your choice ";
				cin>>ch3;
			}
			if(ch3 == 1){
				P = new CheckUpPatient();
				//cin>>P;
				
			}
			else if(ch3 == 2){
				P = new EmergencyPatient();
			}
			else if(ch3 == 3){
				P = new AdmitPatient();
			}
			else if(ch3 == 4){
				P = new ServicePatient();
			}
			else if(ch3 == 5){
				cout<<"\nPress any key to continue ";
				getch();
				goto y;
			}
			cout<<"Press any key to continue";
			getch();
			goto m;
					
		}
		else if(ch2==2){
			mm:
				system("cls");
			int ch3;
			cout<<"\nPress 1 for Checkup Patient\nPress 2 for Emergeny Patient\nPress 3 for Admit Patient\nPress 4 for Service Patient\nPress 5 for Back Menu\nEnter your choice ";
			cin>>ch3;
			while(!(ch3>0&&ch3<6)){
				cout<<"\nYou entered invalid choice.";
				cout<<"\nPress 1 for Checkup Patient\nPress 2 for Emergeny Patient\nPress 3 for Admit Patient\nPress 4 for Service Patient\nPress 5 for Back Menu\nEnter your choice ";
				cin>>ch3;
			}
			if(ch3 == 1){
				//CheckUpPatient;
			}
			else if(ch3 == 2){
				//EmergencyPatient;
			}
			else if(ch3 == 3){
				//AdmitPatient;
			}
			else if(ch3 == 4){
				//ServicePatient;
			}
			else if(ch3 == 5){
				cout<<"\nPress any key to continue ";
				getch();
				goto y;
			}
			cout<<"Press any key to continue";
			getch();
			goto mm;
		}
		else if(ch2==3){
			string n;
			cout<<man_name<<" enter your password to log off.\n";
			cin>>n;
			if(n==man_pass){
				cout<<man_name<<"You are logged off";
				cout<<"\nPress any key to continue.";
				getch();
				goto x;
			}
			AssignManager(Man);
		}
		else if(ch2==4){
			Manager temp;
			cin>>temp;
			Man.push_back(temp);
			cout<<temp.getName()<<"is added as new manager.";
		}
		else if(ch2==5){
			string temp,pa;
			z:
			cout<<"Enter the Manager you want to remove ";
			cin>>temp;
			int flag1=-1;
	//		for(int k=0;k!=Man.end();k++){
	//			if (Man[k].getname()==temp) {
	//				flag1 = i;
	//				break;	
	//			}
			if(flag1 == -1){
				cout<<"\nManager not found.";
				cout<<"Press any key to continue ";
				getch();
				goto z;
			}
			cout<<"Enter the Password of that Manager ";
			cin>>pa;
		//	if(strcmp(Man[flag1].getPassword,pa)){
		//		Man.erase(iterator<Manager>.begin()+flag1);
		//	}
		//	else cout<<"\nYou entered invalid password.";
		}
		else if(ch2==6){
			int k=1;
			for(vector<Manager>::iterator it = Man.begin() ; it != Man.end(); ++it){
				cout<<"Manager # "<<k++;
				cout<<endl<<*it;
				cout<<endl<<endl;
			}
		}
		else if(ch2==7){
			cout<<endl<<"Press any key to continue ";
			getch();
			goto r;			
		}
		cout<<endl<<"Press any key to continue ";
		getch();
		goto y;
	}
	else if(ch1==2){
		p:
		system("cls");
		cout<<"\nPress 1 for List of Doctor, Disease and Cost\nPress 2 for List of Other Services and Cost\nPress 3 for Back Menu\nEnter your Choice ";
		cin>>ch2;
		while(!(ch2>0&&ch2<4)){
			cout<<endl<<"You enter invalid choice.";
			cout<<"\nPress 1 for List of Doctor, Disease and Cost\nPress 2 for List of Other Services and Cost\nPress 3 for Back Menu\nEnter your Choice ";
			cin>>ch2;
		}
		if(ch2 == 1){
			system("cls");
			const int n=26;
			string DoctorsDept[n]={"General Physician","Diarrhea\t","Allergy\t\t","Depression\t","Acne\t\t","Diabetes\t","Head Ache\t","Arthritis\t","Asthma\t\t","Personality Disorder","Rickits\t\t","Autism\t\t",
			"Back Pain\t","Bad Breath\t","Alopecia\t","Bladder Cancer\t","Bone Cancer\t","Breast Cancer\t","Brain Tumor\t","Burn\t\t","High/Low Blood Pressure","Cholesterol\t","Heart Problem\t",
			"High/Low Uric Acid","Dehydration\t","Severe Flu/Cough"};
			double Cost[n]={10,12,11,12,14,15,17,15,20,25,18,12,8,15,30,25,35,45,10,7,8,25,15,10,10,15};
			string DoctorsName[n]={"James","Shawn","Paul","Andrew","Fadricks","Micheal","Chaplin","John","David","Anthony","Amam","Prakash","Bob","Martin","George","Ramesh","Farooq",
			"Laiba","Lubna","Robert","Harry","Kathrine","Peter","Jack","Mike","Saqib"};
			cout<<"\nAVAILABLE DISEASES, DOCTOR NAMES";
			cout<<"\nSR#\tDISEASES\t\tDOCTOR\tCOST";
			for(int i=0;i<n;i++) cout<<endl<<i+1<<"\t"<<DoctorsDept[i]<<"\t(Dr "<<DoctorsName[i]<<")\t$"<<Cost[i];
		}
		else if(ch2 == 2){
			system("cls");
			const int n=10;
			string Services[n]={"X-Ray\t","UltraSound","CT Scan\t","TC DC HB","Urine Test","Blood Test","Biliribin","Stool Test","Bed Charge","Sugar Test"};
			double Cost[n]={3,5,5,1.5,1.5,1.5,2,1.5,1.5,2};
			cout<<"\nAVAILABLE SERVICES\nSR#\tService\t\tCost";
			for(int i=0;i<n;i++) cout<<endl<<i+1<<"\t"<<Services[i]<<"\t$"<<Cost[i];
		}
		else if(ch2==3){
			cout<<endl<<"Press any key to continue ";
			getch();
			goto r;			
		}
		cout<<endl<<"Press any key to continue ";
		getch();
		goto p;
	}
	else if(ch1==3){
		
	}
	else if(ch1==4){
		cout<<"THANKYOU FOR VISITING ABC HOSPITAL.\nGOOD BYE";
		return 0;	
	}
	cout<<endl<<"Press any key to continue ";
	getch();
	goto r;
}	

void AssignManager(vector<Manager> &M){
	fstream man;
	Manager m_temp;
	string s_temp;
	int i_temp;
	man.open("Manager.csv");
	if(man.bad()){
		cout<<"Manager.csv is unable to open.";
		exit(1);
	}
	cout<<"Start\n";
	while(man.good()){
		getline(man,s_temp,',');m_temp.setName(s_temp);
		getline(man,s_temp,',');m_temp.setGender(s_temp);
		getline(man,s_temp,',');m_temp.setAddress(s_temp);
		getline(man,s_temp,',');m_temp.setPhone(s_temp);
		man>>i_temp;m_temp.setAge(i_temp);
		getline(man,s_temp,',');m_temp.setPassword(s_temp);
		cout<<m_temp;
		M.push_back(m_temp);
		cout<<"Done "<<endl;	
	}
	cout<<"Done "<<endl;
}
void AssignCheckUpPatient(vector<CheckUpPatient> &P){
	ifstream pat;
	CheckUpPatient p_temp;
	string s_temp;
	int i_temp;
	pat.open("CheckUp_Patient.csv");
	if(pat.bad()){
		cout<<"CheckUp_Patient.csv is unable to open.";
		exit(1);
	}
	P.clear();
	while(pat.good()){
		getline(pat,s_temp,',');p_temp.setName(s_temp);
		getline(pat,s_temp,',');p_temp.setGender(s_temp);
		getline(pat,s_temp,',');p_temp.setAddress(s_temp);
		getline(pat,s_temp,',');p_temp.setPhone(s_temp);
		pat>>i_temp;p_temp.setAge(i_temp);
		getline(pat,s_temp,',');p_temp.setBloodGroup(s_temp);
		P.push_back(p_temp);	
	}
}

void AssignServicePatient(vector<ServicePatient> &SP){
	ifstream spat;
	ServicePatient sp_temp;
	string s_temp;
	int i_temp;
	spat.open("Service_Patient.csv");
	if(spat.bad()){
		cout<<"Service_Patient.csv is unable to open";
		exit(1);
	}
	SP.clear();
	while(spat.good()){
		getline(spat,s_temp,',');sp_temp.setName(s_temp);
		getline(spat,s_temp,',');sp_temp.setGender(s_temp);
		getline(spat,s_temp,',');sp_temp.setAddress(s_temp);
		getline(spat,s_temp,',');sp_temp.setPhone(s_temp);
		spat>>i_temp;sp_temp.setAge(i_temp);
		getline(spat,s_temp,',');sp_temp.setBloodGroup(s_temp);
		SP.push_back(sp_temp);	
	}
}

void AssignEmergencyPatient(vector<EmergencyPatient> &E){
	ifstream pat;
	EmergencyPatient p_temp;
	string s_temp;
	int i_temp;
	pat.open("Emergency_Patient.csv");
	if(pat.bad()){
		cout<<"Emergency_Patient.csv is unable to open";
		exit(1);
	}
	E.clear();
	while(pat.good()){
		getline(pat,s_temp,',');p_temp.setName(s_temp);
		getline(pat,s_temp,',');p_temp.setGender(s_temp);
		getline(pat,s_temp,',');p_temp.setAddress(s_temp);
		getline(pat,s_temp,',');p_temp.setPhone(s_temp);
		pat>>i_temp;p_temp.setAge(i_temp);
		getline(pat,s_temp,',');p_temp.setBloodGroup(s_temp);
		E.push_back(p_temp);	

	}
}
	
void AssignAdmitPatient(vector<AdmitPatient> &A){
	ifstream pat;
	AdmitPatient p_temp;
	string s_temp;
	int i_temp;
	pat.open("Admit_Patient.csv");
	if(pat.bad()){
		cout<<"Emergency_Patient.csv is unable to open";
		exit(1);
	}
	A.clear();
	while(pat.good()){
		getline(pat,s_temp,',');p_temp.setName(s_temp);
		getline(pat,s_temp,',');p_temp.setGender(s_temp);
		getline(pat,s_temp,',');p_temp.setAddress(s_temp);
		getline(pat,s_temp,',');p_temp.setPhone(s_temp);
		pat>>i_temp;p_temp.setAge(i_temp);
		getline(pat,s_temp,',');p_temp.setBloodGroup(s_temp);
		A.push_back(p_temp);	
	}
}
