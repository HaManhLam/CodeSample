/*
 * main2.cpp
 * By Linked List
 *  Created on: Jan 24, 2024
 *      Author: Halam
 */

#include <iostream>

using namespace std;
#define MAX_STUDENT 10
struct StdList{
	char* name;
	int id;
	int score;
	StdList* prev;
	StdList* next;
};

static StdList st_stdList[MAX_STUDENT];
void std_importList( StdList* );
void std_exportList( StdList* );
void std_arrangeList( StdList* );
void std_linkList( StdList*, int );

int main(){
	int listValid = 0;
	int menu = 0;

	StdList* p_stdList  = &st_stdList[0];
	for( int i=0; i<MAX_STUDENT;i++){
		std_linkList( p_stdList, i );
		p_stdList++;
	}

	// Main function
	while(1){
		if( listValid == 0 ){
		// Import student list
			std_importList( p_stdList );
			listValid = 1;
		} else {
			cout<<endl<<"\t-------MENU----------"<<endl;
			cout<<"\t\t1. Import Student list"<<endl;
			cout<<"\t\t2. Export Student list"<<endl;
			cout<<"\t\t3. Arrange Student list"<<endl;
			cout<<"\t\tOther. Close program"<<endl;
			cout<<"Your select: "<<endl;
			cin>>menu;
			if ( menu == 0 || menu >= 4){
				p_stdList  = &st_stdList[0];
				for( int i=0; i<MAX_STUDENT;i++){
					delete[] p_stdList->name;
					p_stdList++;
				}
				return 0;
			} else if ( menu == 1 ){
				std_importList( p_stdList );
			} else if( menu == 2 ){
				std_exportList( p_stdList );
			} else {
				std_arrangeList( p_stdList );
			}
			
		}
		
	}
}

void std_importList( StdList* p_stdList ){
	p_stdList = &st_stdList[0];
	cout<<"----TAO DANH SACH STUDENT----"<<endl;
	cout<<"Nhap theo thu tu ID, Name, Score, Enter voi moi lan nhap"<<endl;
	for( int i=0; i<MAX_STUDENT;i++){
		cout<<"---Student "<<i+1<<endl;
		cout<<"\tID: ";
		cin>>p_stdList->id;
		cout<<"\tName: ";
		cin.ignore();
		p_stdList->name = new char[50];
		cin.getline(p_stdList->name, 50);
		cout<<"\tScore: ";
		cin>>p_stdList->score;
		p_stdList = p_stdList->next;
	}
}

void std_exportList( StdList* p_stdList ){
	p_stdList = &st_stdList[0];
	cout<<"\t-----XUAT DANH SACH STUDENT-------"<<endl;
	cout<<"\t  -----ID - Name - Score-------"<<endl;
	for( int i=0; i<MAX_STUDENT;i++){
		cout<<p_stdList->id<<" - "<<p_stdList->name<<" - "<<p_stdList->score<<endl;
		p_stdList = p_stdList->next;
	}	
}

void std_arrangeList( StdList* p_stdList ){
	p_stdList = &st_stdList[0];
	int min_id = 0;
	int min_score = 0;
	StdList temp;
	for( int i=0; i<MAX_STUDENT;i++){
		min_id = i;
		min_score = p_stdList->score;
		for( int j=i+1; j<MAX_STUDENT;j++){
			if( st_stdList[j].score < min_score ){
				min_id = j;
				min_score = st_stdList[j].score;
			}
		}
		// Retag value
		if( min_id != i ){
			temp = st_stdList[min_id];
			st_stdList[min_id] = *p_stdList;
			*p_stdList = temp;
		}
		// Swap linked elements
		std_linkList( p_stdList, i );
		p_stdList++;
	}
	std_exportList( p_stdList );
}

void std_linkList( StdList* p_stdList, int i ){
	// Khoi tao linked list
	if( i == 0 ){
		p_stdList->prev = nullptr;
		p_stdList->next = &st_stdList[i+1];
	} else if( i == (MAX_STUDENT - 1) ){
		p_stdList->prev = &st_stdList[i-1];
		p_stdList->next = nullptr;
	} else {
		p_stdList->prev = &st_stdList[i-1];
		p_stdList->next = &st_stdList[i+1];
	}
}
