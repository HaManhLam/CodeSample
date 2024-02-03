/*
 * Player.cpp
 *
 *  Created on: Feb 3, 2024
 *      Author: Halam
 */

#include "Player.h"
#include <string>

//Definition for function
// Player::Player(){
// 	ID = 0;
// 	level = 0;
// 	username = "Unknown";
// 	region = NA;
// }

Player::Player(int id, int level, Region region, string username){
	this->ID = id;
	this->level = level;
	this->region = region;
	this->username = username;
}

Player::~Player(){
}

int Player::getId() {
	return ID;
}

void Player::setId(int id) {
	ID = id;
}

int Player::getLevel() {
	return level;
}

void Player::setLevel(int level) {
	this->level = level;
}

Region Player::getRegion() {
	return region;
}
string Player::getRegionStr() {
	string reg;
	switch (region){
	case NA:
		reg = "NA";
		break;
	case SA:
		reg = "SA";
		break;
	case SEA:
		reg = "SEA";
		break;
	case APAC:
	default:
		reg = "APAC";
		break;
	}
	return reg;
}

Region Player::RegionReg( string str ){
	if( str == "NA"){
		region = NA;
	} else if( str == "SA" ){
		region = SA;
	} else if( str == "SEA" ){
		region = SEA;
	} else {
		region = APAC;
	}
	return region;
}

void Player::setRegion(Region region) {
	this->region = region;
}

std::string Player::getUsername() {
	return username;
}

void Player::setUsername(string username) {
	this->username = username;
}
