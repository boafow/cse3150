#ifndef _EC_SPORTS_PLAYER_H
#define _EC_SPORTS_PLAYER_H

class ECTournament {
public:
  ECTournament(int mon, int mr) : month(mon), minRank(mr) {}
  int GetMonth() const { return month; }
  int GetMinRank() const { return minRank; }

private:
  int month;
  int minRank;
};

class ECSportsPlayer {
public:
  virtual bool CanPlay(ECTournament &tr) const {
	  if(IsNotQualified()){
		  return false;
	  } else {
		  return isQualified();
	  }
  }

  virtual bool isQualified() const {
  	return false;
  }

  virtual bool isNotQualified(ECTournament &tr) const {
	return false;
  }
};

class ECSportsPlayerRanked : public ECSportsPlayer {
public:
  ECSportsPlayerRanked(int r): rank(r) {};
  virtual bool CanPlay(ECTournament &tr) const { return rank >= tr.GetMinRank(); }
private:
  int rank;
};


//Decorator Pattern
class ECSportsPlayerDec : public ECSportsPlayer {
public:
	ECSportsPlayerDec( ECSportsPlayer &player );
	virtual bool IsQualified() { return player.IsQualified(); }
private:
	ECSportsPlayer & player;

}

class ECSportsPlayerWildcard : public ECSportsPlayerDec {
public:
       	ECSportsPlayerWildcard(ECSportsPlayer &playerOrig): ECSportsPlayer(playerOrig) {};

};

class ECSportsPlayerDisciplined : public ECSportsPlayerDec
{
public:
  ECSportsPlayerDisciplined(ECSportsPlayer &playerOrig, int mStart, int mEnd): ECSportsPlayerDec(playerOrig), mStart(mStart), mEnd(mEnd) {};

private:
  ECSportsPlayer &playerOrig;
  int mStart;
  int mEnd;

};

class ECSportsPlayerInjured : public ECSportsPlayerDec {
public:
  ECSportsPlayerInjured(ECSportsPlayer &playerOrig, int m);

private:
};

#endif
