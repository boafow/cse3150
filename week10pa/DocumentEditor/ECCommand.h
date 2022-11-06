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

// ******************************************************
// Implement command history

class ECCommandHistory
{
public:
    ECCommandHistory() ;
    virtual ~ECCommandHistory();
    bool Undo();
    bool Redo();
    void ExecuteCmd( ECCommand *pCmd );
    
private:
    std::vector<ECCommand *> cmdHistory;
    int cmdIndex;
};


#endif /* ECCommand_h */
