// implement a task scheduler based on the Singleton pattern
#include <set>

class ECScheduler
{
public:
  static ECScheduler& Instance(){
	  static ECScheduler inst;
	  return inst;
  }

  void StartTask(int id){
	setTids.insert(id);
	//More to start tsk in os
  }
  void StopTask(int id) {
	setTids.erase(id);
	//More to stop task in OS
  }

  int GetNumRunTasks() const {
	  return setTids.size();
  }
  
private:
  ECScheduler(){};
  std::set<int> setTids;
};
