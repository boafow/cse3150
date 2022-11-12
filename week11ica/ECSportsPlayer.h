#ifndef _EC_SPORTS_PLAYER_H
#define _EC_SPORTS_PLAYER_H

// ********************************************
// Sports Tournament
class ECTournament
{
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
class ECSportsPlayer
{
public:
    virtual bool CanPlay(ECTournament &tr) const
    {
        return false;
    }
    //return true if exits a positivce rule saying can play
    virtual bool isQualified (ECTournament &tr)const
    {
        return false;
    }
    
    //return true if exits a negative rule saying cannot play
    virtual bool notQualified (ECTournament &tr)const
    {
        return false;
    }
};

// ********************************************
// Ranked player
class ECSportsPlayerRanked : public ECSportsPlayer
{
public:
    ECSportsPlayerRanked(int r) : rank(r){}
    
    bool CanPlay(ECTournament &tr) const
    {
        return rank <= tr.GetMinRank();
    }

private:
    int rank;
};

//decorator pattern
class ECSportsPlayerDec : public ECSportsPlayer
{
public:
    ECSportsPlayerDec(ECSportsPlayer &_player): player(_player){}
    virtual bool isQualified (ECTournament &tr)const
    {
        return player.isQualified(tr);
    }
    
    //return true if exits a negative rule saying cannot play
    virtual bool notQualified (ECTournament &tr)const
    {
        return player.notQualified(tr);
    }
private:
    ECSportsPlayer &player;
    
};

// ********************************************
// Wildcard player: qualify for any tournament 
class ECSportsPlayerWildcard : public ECSportsPlayerDec
{
public:
    ECSportsPlayerWildcard(ECSportsPlayer &playerOrig) : ECSportsPlayerDec(playerOrig){}
    virtual bool CanPlay(ECTournament &tr) const
    {
        return true;
    }
    virtual bool isQualified (ECTournament &tr)const
    {
        return true;
    }
};

// ********************************************
// *******************************************
// Displined player: cannot attend any tournament during the period of probation
class ECSportsPlayerDisciplined : public ECSportsPlayerDec
{
public:
    ECSportsPlayerDisciplined(ECSportsPlayer &playerOrig, int mStart, int mEnd):ECSportsPlayerDec(playerOrig), start(mStart), end(mEnd){};
    virtual bool CanPlay(ECTournament &tr) const
    {
        return (tr.GetMonth()<start || tr.GetMonth() >end);
    }

private:
    int start;
    int end;
};

// ********************************************
// Injured player: cannot attend any tournament during the period of injury(injury occurs at a single month) 
class ECSportsPlayerInjured : public ECSportsPlayerDec
{
public:
    ECSportsPlayerInjured(ECSportsPlayer &playerOrig, int m) : ECSportsPlayerDec(playerOrig), month(m){}
    virtual bool CanPlay(ECTournament &tr) const
    {
        return (!(month == tr.GetMonth()));
    }
private:
    int month;
};

#endif