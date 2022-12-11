#ifndef ECCommand_h
#define ECCommand_h

#include <vector>

// ******************************************************
// Implement command design pattern

class ECCommand
{
public:
    virtual ~ECCommand() {}
    virtual void Execute() = 0;
    virtual void UnExecute() = 0;
};


class ECCommandHistory
{
public:
    ECCommandHistory() : posCurrCmd(-1) {};
    virtual ~ECCommandHistory();
    bool Undo();
    bool Redo();
    void ExecuteCmd( ECCommand *pCmd );
    
private:
    std::vector<ECCommand *> listCommands;
    int posCurrCmd;
};


#endif /* ECCommand_h */
