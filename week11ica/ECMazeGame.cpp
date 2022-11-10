#include <vector>
using namespace std;
// Room
class Room
{
public:
	virtual int GetPrize() const {
		return 1;
  }
};

// Room with a bomb
class RoomWithBomb : public Room {
public:
       virtual int GetPrize(){
           return -10;
   }

};

// Enchanted room 
class EnchantedRoom: public Room
{
public:
  virtual int GetPrize(){ return 20; }
};

// maze game
class MazeGame
{
public:
  MazeGame() {}
  virtual ~MazeGame(){
	for(auto x : listRooms){
		delete x;
	}
  }
  
  // create a maze with two rooms and that is it!
  void CreateMaze()
  {
  	for(int i = 0; i <2; ++i){
		Room *pm = MakeRoom();
		listRooms.push_back(pm);
  }
  }
  // get the total prize amount for the rooms
  int GetTotPrize() const
  {
	  int total = 0;
	  for(auto x : listRooms){
		  total += x->GetPrize();
	  }
	  return total;
  }
  
  virtual Room* MakeRoom(){
	return new Room();
  }
  
private:
	  std::vector<Room* > listRooms;
};

// bombed maze
class BombedMazeGame : public MazeGame {
public:
	virtual Room* MakeRoom(){
		return new RoomWithBomb();
	}
};

// enchanted maze
class EnchantedMazeGame : public MazeGame
{
public:
virtual Room* MakeRoom(){
    return new EnchantedRoom();
         }

};
