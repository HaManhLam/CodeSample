/*
 * main.cpp
 *
 *  Created on: Feb 3, 2024
 *      Author: Halam
 */
#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include "Player.h"
#include "ProPlayer.h"

using namespace std;
list<Player> players;
//list<ProPlayer> proPlayers;
bool PlayerImport();
void PlayerExport();
void PlayerAdd();
void PlayerDelete();
void PlayerEdit();
void PlayerListSave();

int main(){
    int menu = 0;
    cout<<"Nhap danh sach Player tu dong----------- "<<endl;
    if( PlayerImport() == true ){
        while (1){
            cout<<"-----MENU-----"<<endl;
            cout<<"\t1.Them player"<<endl;
            cout<<"\t2.Sua player"<<endl;
            cout<<"\t3.Xoa player"<<endl;
            cout<<"\t4.Show player list"<<endl;
            cout<<"\t5.Save player list"<<endl;
            cin>>menu;
            if( menu == 1 ){
                PlayerAdd();
            } else if ( menu == 2 ){
                PlayerEdit();
            } else if( menu == 3 ){
                PlayerDelete();
            } else if(menu == 4 ){
                PlayerExport();
            } else if( menu == 5 ){
                PlayerListSave();
            } else {
                return 0;
            }
        }
    } else {
        return 0;
    }
}


bool PlayerImport(){
    bool importComp = false;
    int id, level;
    Region region;
    string str_region;
    string username;
    string data;
    ifstream myfile;
    myfile.open("Playerlist.txt");
    if( myfile.is_open() ){
        while( myfile ){
            getline( myfile, data );
            istringstream iss(data);
            if( iss >> id >> level >> str_region >> username){
                if( str_region == "NA" ){
                    region = NA;
                } else if( str_region == "SA" ){
                    region = SA;
                } else if( str_region == "SEA" ){
                    region = SEA;
                } else{
                    region = APAC;
                }
                Player player = Player( id, level, region, username );
                players.push_back(player);
            }
        }
        importComp = true;
    } else {
        cerr<< "Error opening file: "<<"Playerlist.txt"<<endl;
    }
    myfile.close();
    return importComp;
}

void PlayerExport(){
    cout<<"\tID\tLevel\tRegion\tUsername"<<endl;
    for( list<Player>::iterator player = players.begin(); player != players.end(); player++ ){
        cout<<"\t"<<player->getId()<<"\t"<<player->getLevel()<<"\t"<<player->getRegionStr()<<"\t"<<player->getUsername()<<endl;
    }
}

void PlayerAdd(){
    int playerNum = 0;
    int id, level;
    string str_region;
    string username;
    string data;
    cout<<" Nhap so luong player dang ki them "<<endl;
    cin>>playerNum;
    Player player = Player(0,0,SA,"sqwerti");

    for( int i = 0; i < playerNum; i++ ){
        cout<<"Add player "<<i<<endl;
        cout<<"\tPlayer ID: Auto generated";
        id = players.size() + 1;
        cout<<"\tPlayer Level: ";
        cin>>level;
        cin.ignore();
        cout<<"\tPlayer Region(NA/SA/SEA/APAC(default)): ";
        getline( cin, str_region );
        cout<<"\tPlayer username: ";
        getline( cin, username );

        player.setId( id );
        player.setLevel( level );
        player.setRegion( player.RegionReg( str_region ) );
        player.setUsername( username );
        players.push_back( player );
    }
}

void PlayerEdit(){
    int id, select;
    int level;
    string str_region;
    string username;
    list<Player>::iterator it;
    cout<<"Nhap id Player can sua, ( maximum ID "<<players.size()<<") :";
    cin>>id;
    for( it = players.begin(); it != players.end(); it++ ){
        if ( it->getId() == id ){
            cout<<"\tChon thong tin muon sua: 1-Level, 2-Region, 3-Username: ";
            cin>>select;
            while (select > 3 || select == 0 ){
                cout<<"Sai lua chon, moi chon lai: ";
                cin>>select;
            }
            if( select == 1 ){
                cout<<"Nhap level moi: ";
                cin>>level;
                it->setLevel( level );
            } else if ( select == 2 ){
                cout<<"Nhap region moi(NA/SA/SEA/APAC(default)): ";
                cin.ignore();
                getline( cin, str_region );
                it->setRegion( it->RegionReg( str_region ) );
            } else if ( select == 3 ){
                cout<<"Nhap usernam moi: ";
                cin.ignore();
                getline( cin, username );
                it->setUsername( username );
            }
            break;
        } else {
        	 cout<<"Ko co id"<<endl;
        }
    }
    //advance( it, id);
}

void PlayerDelete(){
    int id;
    bool find = false;
    cout<<"Nhap ID player muon xoa, ( maximum ID "<<players.size()<<") :";
    cin>>id;
    list<Player>::iterator it;
    for( it = players.begin(); it != players.end(); ){
        if( it->getId() == id ){
        	find = true;
            players.erase(it++);
            cout<<"Chi so la: "<<id<<endl;
//            it = players.begin();
//            advance(it, id);
        } else {
        	++it;
        }
        if( find == true ){
        	it->setId( id++ ); // sap xep lai id cho cac phan tu sau do
        }
    }
}

void PlayerListSave(){
    ofstream myfile;
    string data;
    list<Player>::iterator it;
    myfile.open("Playerlist.txt", ios::out|ios::trunc);
    if( myfile.is_open() ){
        for( it = players.end(); it != players.begin(); it-- ){
            data += to_string(it->getId()) + " " + to_string(it->getLevel()) + " " + it->getRegionStr() + " " + it->getUsername();
            data += "\n";
            myfile<<data;
            data.clear();
        }
    } else {
        cerr<<"Failed to open the file"<<endl;
    }
    myfile.close();
}
