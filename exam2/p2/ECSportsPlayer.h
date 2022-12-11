#ifndef _EC_SPORTS_PLAYER_H
#define _EC_SPORTS_PLAYER_H

#include <iostream>
using namespace std;

// ********************************************
// Sports Tournament (DON'T CHANGE)
class ECTournament {
public:
  ECTournament(int mon, int mr) : month(mon), minRank(mr) {}
  int GetMonth() const { return month; }
  int GetMinRank() const { return minRank; }

private:
  int month;
  int minRank;
};

// ********************************************
// Generic player
class ECSportsPlayer {
public:
  virtual bool CanPlay(ECTournament &tr) const {
    if(IsDisqualified(tr) == true){
	    return false;
    }
    return IsQualified(tr);
  }

  // return true if exists a POSITIVE rule saying that can play
   virtual bool IsQualified(ECTournament &tr) const {
    return false;
   }

  // return true if exists a NEGATIVE rule saying that cannot play
  virtual bool IsDisqualified(ECTournament &tr) const {
    return false;
  }
};

// ********************************************
// Ranked player
class ECSportsPlayerRanked : public ECSportsPlayer {
public:
  ECSportsPlayerRanked(int r): rank(r) {}
  virtual bool IsQualified(ECTournament &tr) const {
    return rank <= tr.GetMinRank();
  }
private:
  int rank;
};

// Decorator Pattern
class ECSportsPlayerDec : public ECSportsPlayer {
  public:
    ECSportsPlayerDec(ECSportsPlayer &player): _player(player) {}
    // takes in a sportsplayer
    virtual bool IsQualified(ECTournament &tr) const {
      return _player.IsQualified(tr);
    }

    virtual bool IsDisqualified(ECTournament &tr) const {
      return _player.IsDisqualified(tr);
    }
  private:
    ECSportsPlayer &_player;
};


// ********************************************
// Wildcard player: qualify for any tournament 
class ECSportsPlayerWildcard : public ECSportsPlayerDec {
public:
  ECSportsPlayerWildcard(ECSportsPlayer &playerOrig): ECSportsPlayerDec(playerOrig) {}
  virtual bool IsQualified(ECTournament &tr) const {
    return true;
  }
};

// YW: THIS IS THE NEW CLASS TO IMPLEMENT

// ********************************************
class ECSportsPlayerQualMatch : public ECSportsPlayerDec  {
public:
  ECSportsPlayerQualMatch(ECSportsPlayer &playerOrig, bool fWinnerQual) : ECSportsPlayerDec(playerOrig), fWinnerQual(fWinnerQual) {}
  // your code
  virtual bool IsQualified(ECTournament &tr) const {
	  return true && fWinnerQual;
  }
private:
	  bool fWinnerQual;
};

// ********************************************
// Displined player: cannot attend any tournament during the period of probation
class ECSportsPlayerDisciplined : public ECSportsPlayerDec {
public:
  ECSportsPlayerDisciplined(ECSportsPlayer &playerOrig, int mS, int mE): ECSportsPlayerDec(playerOrig), mStart(mS), mEnd(mE) {}
  virtual bool IsDisqualified(ECTournament &tr) const override {
    if(ECSportsPlayerDec::IsDisqualified(tr) == true){
	    return true;
    }
    return tr.GetMonth() >= mStart && tr.GetMonth() <= mEnd;
  }
private:
  int mStart;
  int mEnd;
};

// ********************************************
// Injured player: cannot attend any tournament during the period of injury(injury occurs at a single month) 
class ECSportsPlayerInjured : public ECSportsPlayerDec {
public:
  ECSportsPlayerInjured(ECSportsPlayer &playerOrig, int m): ECSportsPlayerDec(playerOrig), month(m) {}
  virtual bool IsDisqualified(ECTournament &tr) const override {
    	if(ECSportsPlayerDec::IsDisqualified(tr) == true){
		return true;
	}
	return tr.GetMonth() == month;
  }
private:
  int month;
};
#endif

