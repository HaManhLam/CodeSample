/*
 * ProPlayer.h
 *
 *  Created on: Feb 3, 2024
 *      Author: Halam
 */

#ifndef PROPLAYER_H_
#define PROPLAYER_H_

#include "Player.h"
#include "string"

// Player position ingame
enum ProPlayPos {
    TOP,
    MIDDLE,
    JUNGLE,
    AD_CARRY,
    AD_SUPPORT
};

enum ProPlayRank {
    BRONZE,
    SILVER,
    GOLD,
    DIAMOND,
    MASTER,
    CHALLENGE
};

enum ProTeam {
    SKT,
    FNATIC,
    LPL,
    CLOUD9,
    GENG
};

class ProPlayer: public Player {
private:
    ProTeam proTeam;
    ProPlayPos playPos;
    ProPlayRank playRank;
public:
    ProPlayer( int id, int level, Region region, string username, ProTeam proTeam, ProPlayPos playPos, ProPlayRank playRank );
    ~ProPlayer();

	ProPlayPos getPlayPos();

	void setPlayPos(ProPlayPos playPos);

	ProPlayRank getPlayRank();

	void setPlayRank(ProPlayRank playRank);

	ProTeam getProTeam();

	void setProTeam(ProTeam proTeam);
};

#endif	/* PROPLAYER_H_ */
