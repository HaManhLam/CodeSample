/*
 * Player.h
 *
 *  Created on: Feb 3, 2024
 *      Author: Halam
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>
using namespace std;
// Player region type
enum Region {
	NA,		// North America
	SA,		// Sourth America
	SEA,	// South East Asia
	APAC,	// Asia Pacific
};

class Player {
public:
	Player( int id, int level, Region region, string username );
	~Player();
	int getId();
	void setId( int id);
	int getLevel();
	void setLevel(int level);
	Region getRegion();
	string getRegionStr();
	Region RegionReg(string str);
	void setRegion(Region region);
	string getUsername();
	void setUsername(string username);
private:
	int ID;
	string username;
	Region region;
	int level;
};

#endif /* PLAYER_H_ */
