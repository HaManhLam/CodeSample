/*
 * main.cpp
 *
 *  Created on: Jan 12, 2024
 *      Author: Halam
 */

#include <iostream>
#include <string.h>
using namespace std;

struct StdProfile{
	char Name[30];
	int id;
	float score;
};

static StdProfile stdProfile[10];
void Student_import(StdProfile*);
void Student_export(StdProfile*);
void Student_arrangeScore(StdProfile*);

int main(){
	int choice = 0;
	int firstImport = 0;
	StdProfile *stdProf = &stdProfile[0];
	while(1){
		cout<<"\bSelect Menu:"<<endl<<"\t1: Import student lists"<<endl<<"\t2: Export student lists"<<endl<<"\t3: Arrange student lists by score"<<endl<<"\t4: Exit"<<endl<<"Your choice: ";
		cin>>choice;
		if( choice == 4 ){
			cout<<"END PROGRAM------"<<endl;
			exit(0);
		}
		if( choice == 1 && firstImport == 0 )
			firstImport = 1;
		if( choice == 1){
			Student_import( stdProf );
		} else{
			if( firstImport == 0 || choice > 3 || choice == 0){
			// Not input student list yet or invalid choice
				cout<<"\t\t\t---List empty or Invalid selection, choice again---"<<endl;
			} else {
				if( choice == 2 ){
					Student_export( stdProf );
				} else {
					Student_arrangeScore( stdProf );
				}
			}
		}
	}
}

void Student_import(StdProfile* stdProf){
	int idCheck = 0;
	int student_num = 0;

	while(student_num < 10){
		idCheck = 0;
		stdProf = &stdProfile[student_num];
		cout<<"Input Student profile "<<student_num<<endl;
		cout<<"Name: ";
		cin>>stdProf->Name;
		cout<<"ID: ";
		cin>>stdProf->id;
		// Kiem tra id co bi trung voi student khac hay khong
		if( student_num == 0){}
		else{
			while( idCheck < student_num ){
				if( stdProfile[idCheck].id == stdProf->id ){
					cout<<"ID not Valid, input again: ";
					cin>>stdProf->id;
					idCheck = 0;
				} else{
					idCheck++;
				}
			}
		}
		cout<<"Score: ";
		cin>>stdProf->score;
		// Kiem tra score co trong nguong hop le hay khong
		while( (stdProf->score < 0) || (stdProf->score > 10) ){
			cout<<"Invalid Score, input again: ";
			cin>>stdProf->score;
		}
		student_num++;
	}
}

void Student_export(StdProfile* stdProf){
	stdProf = &stdProfile[0];
	cout<<"Student List----------------"<<endl;
	for ( int i = 0; i < 10; i++){
		cout<<"\t\t"<<i<<":"<<stdProf->Name<<"--ID:"<<stdProf->id<<"--Score:"<<stdProf->score<<endl;
		stdProf++;
	}
}

void Student_arrangeScore(StdProfile* stdProf){

	StdProfile temp;
	for ( int i = 0; i < 9; i++){
		stdProf = &stdProfile[i];
		for( int j = i+1; j < 10; j++){
			if (stdProf->score > stdProfile[j].score){
				// Swap values to arrange
				temp = stdProfile[j];
				stdProfile[j] = *stdProf;
				*stdProf = temp;
			}
		}
	}
	Student_export(stdProf);
}
