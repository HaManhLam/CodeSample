#include <string>
#include "ProPlayer.h"
using namespace std;

ProPlayer::ProPlayer(int id, int level, Region region, std::string username, ProTeam team, ProPlayPos pos, ProPlayRank rank)
    : Player(id, level, region, username){
	this->proTeam = team;
    this->playPos = pos;
    this->playRank = rank;
}

ProPlayer::~ProPlayer(){
}

ProPlayPos ProPlayer::getPlayPos() {
	return playPos;
}

void ProPlayer::setPlayPos(ProPlayPos playPos) {
	this->playPos = playPos;
}

ProPlayRank ProPlayer::getPlayRank() {
	return playRank;
}

void ProPlayer::setPlayRank(ProPlayRank playRank) {
	this->playRank = playRank;
}

ProTeam ProPlayer::getProTeam() {
	return proTeam;
}

void ProPlayer::setProTeam(ProTeam proTeam) {
	this->proTeam = proTeam;
}
